import os
from pathlib import Path
from urllib import request, parse
import base64
import mimetypes
import json
from time import sleep
import logging

# REST API:
#   - https://learn.microsoft.com/en-us/windows/mixed-reality/develop/advanced-concepts/device-portal-api-reference
#   - https://learn.microsoft.com/en-us/windows/uwp/debug-test-perf/device-portal-api-core


class HoloDevicePortal:
    def __init__(self, host, username, password, debug=False) -> None:
        self._logger = self._init_logger(debug)
        self._basic_url = f"http://{host}"

        self._logger.info(
            f"Connecting to HoloLens Device Portal at {self._basic_url} ..."
        )
        self._pwd_mgr = request.HTTPPasswordMgrWithDefaultRealm()
        self._pwd_mgr.add_password(None, self._basic_url, username, password)
        self._auth_handler = request.HTTPBasicAuthHandler(self._pwd_mgr)
        self._opener = request.build_opener(self._auth_handler)
        self._opener.open(self._basic_url)
        request.install_opener(self._opener)
        self._logger.info(f"Connected to HoloLens Device Portal.")

    def _init_logger(self, debug):
        logger = logging.getLogger(__name__)
        logger.setLevel(logging.DEBUG if debug else logging.INFO)
        ch = logging.StreamHandler()
        ch.setLevel(logging.DEBUG if debug else logging.INFO)
        formatter = logging.Formatter(
            "%(asctime)s - %(name)s - %(levelname)s - %(message)s"
        )
        ch.setFormatter(formatter)
        logger.addHandler(ch)
        return logger

    def _get(self, url):
        r = request.urlopen(url)
        data = json.loads(r.read().decode("utf-8"))
        return data

    def _post(self, url):
        r = request.urlopen(request.Request(url, method="POST"))
        code = r.getcode()
        return code

    def _put(self, url, data):
        r = request.Request(url, data=data)
        r.get_method = lambda: "PUT"
        data = json.loads(r.read().decode("utf-8"))
        return data

    def _delete(self, url):
        r = request.urlopen(request.Request(url, method="DELETE"))
        code = r.getcode()
        return code

    def _download_file(self, url, save_path):
        save_path = str(save_path)
        request.urlretrieve(url, save_path)

    def _delete_file(self, url):
        self._delete(url)

    def _upload_file(self, url, file_path):
        body, headers = self._encode_multipart_formdata(file_path)
        r = request.urlopen(
            request.Request(url, data=body, headers=headers, method="POST")
        )
        return r.getcode()

    def _encode_multipart_formdata(self, file_path):
        boundary = "----WebKitFormBoundary7MA4YWxkTrZu0gW"
        crlf = "\r\n"
        data = []
        data.append("--" + boundary)
        data.append(
            f'Content-Disposition: form-data; name="file"; filename="{file_path}"'
        )
        data.append(
            "Content-Type: {}".format(
                mimetypes.guess_type(file_path)[0] or "application/octet-stream"
            )
        )
        data.append("")
        with open(file_path, "rb") as f:
            data.append(f.read().decode("utf-8"))
        data.append("--" + boundary + "--")
        data.append("")
        body = crlf.join(data)
        headers = {
            "Content-Type": f"multipart/form-data; boundary={boundary}",
            "Content-Length": str(len(body)),
        }
        body = body.encode("utf-8")
        return body, headers

    def _string_to_base64(self, string):
        encoded_name = base64.b64encode(string.encode()).decode()
        url_name = parse.quote(encoded_name)
        return url_name

    def get_os_info(self):
        url = f"{self._basic_url}/api/os/info"
        return self._get(url)

    def get_package_list(self):
        url = f"{self._basic_url}/api/app/packagemanager/packages"
        return self._get(url)["InstalledPackages"]

    def get_process_list(self):
        url = f"{self._basic_url}/api/resourcemanager/processes"
        return self._get(url)["Processes"]

    def get_package_fullname(self, package_name):
        packages = self.get_package_list()
        for package in packages:
            if package["PackageFamilyName"] == package_name:
                return package["PackageFullName"]
        return None

    def get_package_id(self, package_name):
        packages = self.get_package_list()
        for package in packages:
            if package["PackageFamilyName"] == package_name:
                return package["PackageRelativeId"]
        return None

    def get_battery_info(self):
        url = f"{self._basic_url}/api/power/battery"
        r = self._get(url)
        battery = r["RemainingCapacity"] / r["MaximumCapacity"] * 100
        return battery

    def get_machine_name(self):
        url = f"{self._basic_url}/api/os/machinename"
        r = self._get(url)
        return r["ComputerName"]

    def set_machine_name(self, name):
        data = self._string_to_base64(name)
        url = f"{self._basic_url}/api/os/machinename?name={data}"
        return self._post(url)

    def get_app_running_status(self, app_name):
        processes = self.get_process_list()
        for process in processes:
            if process.get("AppName") == app_name:
                return process.get("IsRunning")
        return False

    def start_app(self, app_name):
        if self.get_app_running_status(app_name):
            self._logger.warning(f"App {app_name} is already running.")
            return

        app_id = self.get_package_id(app_name)
        encoded_name = self._string_to_base64(app_id)
        url = f"{self._basic_url}/api/taskmanager/app?appid={encoded_name}"
        code = self._post(url)
        if code == 200 and self.get_app_running_status(app_name):
            self._logger.info(f"App {app_name} started successfully.")
        else:
            self._logger.warning(f"App {app_name} started failed.")

    def stop_app(self, app_name):
        if not self.get_app_running_status(app_name):
            self._logger.warning(f"App {app_name} is not running.")
            return

        full_name = self.get_package_fullname(app_name)
        encoded_name = self._string_to_base64(full_name)
        url = f"{self._basic_url}/api/taskmanager/app?package={encoded_name}"
        code = self._delete(url)
        if code == 200 and not self.get_app_running_status(app_name):
            self._logger.info(f"App {app_name} stopped successfully.")
        else:
            self._logger.warning(f"App {app_name} stopped failed.")

    def shutdown(self):
        self._logger.warning("Shutting down HoloLens in 3 secs ...")
        sleep(3)
        url = f"{self._basic_url}/api/control/shutdown"
        return self._post(url)

    def reboot(self):
        self._logger.warning("Rebooting HoloLens in 3 secs ...")
        sleep(3)
        url = f"{self._basic_url}/api/control/restart"
        return self._post(url)

    def download_file_from_app(self, app_name, file_path, save_path):
        self._logger.debug(
            f"Downloading file {file_path} from {app_name} to {save_path} ..."
        )
        full_name = self.get_package_fullname(app_name)
        url = (
            f"{self._basic_url}/api/filesystem/apps/file"
            + f"?knownfolderid=LocalAppData"
            + f"&packagefullname={full_name}"
            + f"&filename={file_path}"
        )
        self._download_file(url, save_path)

    def delete_file_from_app(self, app_name, file_path):
        self._logger.debug(f"Deleting file {file_path} from {app_name} ...")
        full_name = self.get_package_fullname(app_name)
        url = (
            f"{self._basic_url}/api/filesystem/apps/file"
            + f"?knownfolderid=LocalAppData"
            + f"&packagefullname={full_name}"
            + f"&filename={file_path}"
        )
        return self._delete_file(url)

    def upload_file_to_app(self, app_name, sub_directory, file_path):
        self._logger.debug(
            f"Uploading file {file_path} to {app_name}/{sub_directory} ..."
        )
        full_name = self.get_package_fullname(app_name)
        url = (
            f"{self._basic_url}/api/filesystem/apps/file"
            + f"?knownfolderid=LocalAppData"
            + f"&packagefullname={full_name}"
            + f"&path={sub_directory}"
            + f"&extract=false"
        )
        return self._upload_file(url, file_path)


if __name__ == "__main__":
    PROJ_ROOT = Path(__file__).resolve().parents[2]

    # Read environment variables
    host = os.getenv("HOLO_DEVICE_IP")
    user = os.getenv("HOLO_DEVICE_USERNAME")
    pwd = os.getenv("HOLO_DEVICE_PASSWORD")


    portal = HoloDevicePortal(host, user, pwd, debug=True)

    device_name = portal.get_machine_name()
    print(f"Device Name: {device_name}")

    battery = portal.get_battery_info()
    print(f"Battery: {battery:.1f}%")

    # app_name = "PTGDemo"
    # print(f"App Name: {app_name}")
    # app_fullname = portal.get_package_fullname(app_name)
    # print(f"App Full Name: {app_fullname}")
    # app_id = portal.get_package_id(app_name)
    # print(f"App ID: {app_id}")
    # is_running = portal.get_process_running(app_name)
    # print(f"App Running: {is_running}")

    # Old Name: HOLOLENS-KV5H72
    # new_name = "HOLOLENS-KV5H72"
    # print(f"Set New Device Name: {new_name}")
    # code = portal.set_machine_name("HOLOLENS-KV5H72")
    # if code == 200:
    #     print("Set Machine Name Successfully.")
    #     portal.reboot()
    # else:
    #     print("Set Machine Name Failed.")

    # # start APP
    # app_name = "PTGDemo"
    # print(f"Launch App: {app_name}")
    # portal.start_app(app_name)

    # print("Wait for 15 secs ...")
    # sleep(15)

    # # stop APP
    # app_name = "PTGDemo"
    # print(f"Stop App: {app_name}")
    # portal.stop_app(app_name)

    # get known folders
    # api: /api/filesystem/apps/knownfolders
    # {'KnownFolders': ['Documents', 'LocalAppData', 'PublicDocuments', 'Videos', 'Music', 'Pictures', '3D Objects', 'DevelopmentFiles', 'Downloads']}

    # get files in known folder
    app_name = "PTGDemo"
    sub_directory = "/LocalState"
    file_path = PROJ_ROOT / "file_upload_test.json"
    download_file_path = f"{sub_directory}/file_upload_test.json"
    save_path = PROJ_ROOT / "file_download_test.json"

    #portal.upload_file_to_app(app_name, sub_directory, file_path)
    #portal.download_file_from_app(app_name, download_file_path, save_path)
    #portal.delete_file_from_app(app_name, download_file_path)
