# Index

1. [**iTeach Demo: Hardware & Network Setup + App in Action!**](#1-iteach-demo-hardware--network-setup--app-in-action)
2. [📁 **Key Files**](#-2-key-files)
3. [🔧 **Set Environment Variables**](#3--set-environment-variables)
4. [🥽 **HoloLens 2 Setup**](#4--hololens-2-setup)
5. [🤖 **Robot Setup**](#5--robot-setup)
6. [💻 **PC (Laptop) Setup**](#6--pc-laptop-setup)
7. [🔄 **Terminator**](#7--terminator)
8. [🖥️ **Desktop Labelling App**](#8-%EF%B8%8F-desktop-labelling-app)
9. [🛠️ **Troubleshooting Guide**](#9-%EF%B8%8F-troubleshooting-guide)

<br><br>

# 1. **iTeach Demo:** Hardware & Network Setup + App in Action!

![Our experimental setup](./imgs/exp-setup-with-captions.png)

- For a demonstration of the experiment setup, please check out [this video](https://www.youtube.com/watch?v=gJ7Is0SrNgc) 🎦.<br>
- For detailed steps, refer to the video description 📋. Make sure that the respective subnets are configured correctly and devices are connected to each other via WLAN or LAN.
</div>

<br><br>

# 📁 2. Key Files

### 🤖 [fetchdetect.py](./iTeach/fetchdetect.py)

- **Functionality:** This script performs DoorHandle object detection by subscribing to the robot’s input stream from the `/head_camera/rgb/image_raw` topic.
- **Output:** It processes the stream and publishes the bounding box (bbox) overlayed image to the `pc/detections/bbox_overlayed_rgb` topic.

### 📡 [rebroadcastData.py](./iTeach/rebroadcastData.py)

- **Functionality:** This script captures the **Fetch robot's** head camera feed and rebroadcasts both RGB and depth data at a reduced frame rate.
- **Output Topics:** It publishes to `hololens/in/robot_pov/rgb` and `hololens/in/robot_pov/depth`, following the [sensor_msgs/Image](http://docs.ros.org/en/noetic/api/sensor_msgs/html/msg/Image.html) message format.
- **Additional Subscription:** 🔄 The script subscribes to `pc/detections/bbox_overlayed_rgb` and rebroadcasts this to `hololens/in/robot_pov/detections/bbox_overlayed_rgb`. This allows detection overlays to display when the "Robot POV" button is clicked in the HoloLens app.
- **Execution:** 🚀 It runs independently, requiring only ROS and `rospy`, with no additional arguments necessary.

### 📥 [receiveData.py](./iTeach/receiveData.py)

- **Functionality:** This script handles incoming data from the **HoloLens**, organizing it into the correct directories.
- **Incoming Messages:** It processes ROS messages from `hololens/out/robot_pov/raw_rgb`, `hololens/out/user_labelled/depth`, and `hololens/out/user_labelled/labels`. These messages are grouped based on their timestamp to ensure they belong to the same data set.
- **YOLO Integration:** The filenames are formatted to match the requirements of the YOLO algorithm for seamless use.
- **Execution:** The script runs independently, without needing any command line arguments.

### 🏋️‍♂️ [finetune.py](./iTeach/finetune.py)

- **Purpose:** This script fine-tunes the pre-trained model using the human collected dataset from the HoloLens device, adapting it to improve performance.
- **Execution:** Designed to optimize the model for DoorHandle detection task, it plays a key role in enhancing the system's accuracy and robustness.

### 📜 [run_finetuning_node.py](./run_finetuning_node.py)

- **Functionality:** This script serves as a unified container that executes `DoorHandleModelFinetuner`, `rebroadcastData`, and `receiveData` with a single command, simplifying the management of multiple terminal windows.
- **Requirements:** It requires `rospy` to be installed and accepts a YAML file with configuration parameters as a command line argument.

<br><br>

# 3. 🔧 **Set Environment Variables**:

Add the following lines to your `~/.bashrc` file:

```sh
export HOLO_DEVICE_IP="10.42.0.150" # HoloLens IP address when connected to the laptop/PC Wi-Fi hotspot
export HOLO_DEVICE_USERNAME="admin" # HoloLens username
export HOLO_DEVICE_PASSWORD="123456789" # HoloLens password
```

<br><br>

# 4. 🥽 HoloLens 2 Setup

- Ensure the HoloLens is connected to the laptop's Wi-Fi hotspot.
- Take note of the HoloLens device's IP address to access the Windows Device Portal on your laptop for device management.
- Install the **iTeachLabeller** app on the HoloLens device. Check out this [App Install Video 🎦](https://www.youtube.com/watch?v=7xFtCPSMTEk) for guidance!
- To change the IP of the ROS server, use the [script](./hololens_utils/HoloDevicePortal.py) to upload the [ROSConnectionConfig.json](ROSConnectionConfig.json) file to the HoloLens device. **Make sure both the laptop and HoloLens are connected to the same network!** 🌐

```json
{
  "RosIPAddress": "192.168.1.3", // change here
  "RosPort": 10000,
  "KeepaliveTime": 1,
  "NetworkTimeoutSeconds": 2,
  "SleepTimeSeconds": 0.033,
  "ShowHud": false
}
```
<br>

```bash
python hololens_utils/HoloDevicePortal.py --file_path path/to/ROSConnectionConfig.json
```

<br><br>

# 5. 🤖 Robot Setup

- Ensure the robot is connected to the PC via **Ethernet** and also connected to the laptop's **Wi-Fi hotspot** for communication with the **HoloLens** device.
- Launch the **ROS TCP connector**.
  - Make sure the server is running the [ROS-TCP-Endpoint](https://github.com/Unity-Technologies/ROS-TCP-Endpoint) to establish a connection with the HoloLens. Check the link for installation instructions.
- [Optional: FYI] A sample Conda environment 📦 with the necessary dependencies for the robot system can be found in [robot-env.txt](conda-env/robot-env.txt).
- Once everything is set up, follow these steps:

```bash
export ROS_HOSTNAME=10.42.0.233 # Replace with the robot's WLAN IP when connected to the laptop hotspot
export ROS_MASTER_URI=http://$ROS_HOSTNAME:11311 # IP when connected to the IRVL laptop hotspot

# To check the connected network SSID
echo "Connected to SSID: $(iw dev wlan0 info | grep ssid | awk '{print $2}')"
echo "ROS_IP: " $ROS_IP
echo "ROS_HOSTNAME: " $ROS_HOSTNAME
echo "ROS_MASTER_URI: " $ROS_MASTER_URI

# To run the ROS TCP connector
source /opt/ros/$ROS_DISTRO/setup.bash
source devel/setup.bash

# server_ip is the WLAN IP of the robot when connected to the laptop hotspot, port should be 10000
rosrun ROS-TCP-Endpoint endpoint.launch tcp_ip:=$ROS_HOSTNAME tcp_port:=10000
```

<br><br>

# 6. 💻 PC (Laptop) Setup

- Ensure that the PC has an active Wi-Fi hotspot to which both the **HoloLens** and the **Robot** are connected.
- On a Linux computer, set the `ROS_IP` and `ROS_MASTER_URI` (but not `ROS_HOSTNAME`).
- In [`configs/cfg.yml`](configs/cfg.yml), specify the folder for datasets and update the path accordingly. Make sure to adjust any necessary values before starting the experiment.

<br>

### 6.1 Create a Conda Environment on the PC/Laptop

- A sample Conda environment 📦 with the necessary dependencies for the laptop system is available in [pc-env.txt](conda-env/pc-env.txt).

```shell
conda create -n iTeachPC python=3.9
conda activate iTeachPC
pip install -r conda-env/pc-env.txt
```

<br>

### 6.2 Download Pretrained Checkpoints

```shell
wget -v -O pretrained_ckpt.pt https://utdallas.box.com/shared/static/hj1mncmm85bswn4uvbm9ytaydi7d3ws0.pt
```

<br>

### 6.3 📜 Scripts to Run

To set up and run the necessary scripts for fine-tuning and streaming, follow the instructions below:

<br>

### 6.3.1 Execute the Fine-Tuning Node

Run the following commands to activate the fine-tuning ROS node:

```shell
export ROS_IP=10.42.0.233 # Use the ROS server WLAN IP for HL2SS
export ROS_MASTER_URI=http://$ROS_IP:11311
export ROS_HOSTNAME=192.168.1.4 # Use the ROS server LAN IP for HL2SS
conda activate iTeachPC

# Ensure cfg.yaml is configured correctly; assuming you are in the src/ directory
python run_finetuning_node.py --config configs/cfg.yaml # Start fine-tuning node
```

<br>

### 6.3.2 Set Up Streaming

You have the option to stream either the PC webcam feed or the HoloLens POV to the ROS server. Choose one of the following methods:

<br>

#### 6.3.2.a Stream PC Webcam to ROS Server

1. **Install `usb_cam`**:
   You can find more details on the [wiki](https://wiki.ros.org/usb_cam) or [GitHub](https://github.com/ros-drivers/usb_cam).

2. **Publish to the `/usb_cam/image_raw` ROS topic**:
   Use the following commands:

```sh
# For ROS1
sudo apt install ros-<ROS-DISTRO>-usb-cam
v4l2-ctl --list-devices # List available devices to identify the webcam
rosrun usb_cam usb_cam_node _video_device:=/dev/video0 _camera_name:='usb_cam' _camera_frame_id:='usb_cam' # Adjust /dev/video0 if needed
```

<br>

#### 6.3.2.b Stream HoloLens POV to ROS Server

```sh
python publish_hlpov2ros.py
# If the IP address is read correctly, the output should indicate that the script is running fine, given the HoloLens device is ON:
# Read HoloLens IP: 10.42.0.150 from ENV
```

<br>

### 6.3.3 Visualize Published Data with **RViz**

Run the following command to open RViz and visualize all your published data:

```sh
# Requires setup from sections 5.3.2.a (PC webcam) and 5.3.2.b (HoloLens POV) 📸🔧
# Feel free to adjust the RViz panels as needed for your visualization 🔍
rosrun rviz rviz -d rviz/iteach.rviz
```

<br><br>

# 7. 🔄 Terminator

We recommend using the [Terminator](https://github.com/gnome-terminator/terminator) tool for managing multiple terminal windows efficiently.

Below is an example of the Terminator layout used to run all necessary modules. Ensure that the PC is connected to both the **HoloLens** and the **robot** to handle the sub-networking aspect.

![iTeach-RViz-Setup](./imgs/terminator-iteach.webp)

<br><br>

# 8. 🖥️ Desktop Labelling App

https://github.com/user-attachments/assets/dc82bf66-c9a2-4b24-a514-289abd44e499

<div>
We’ve developed a simple desktop labelling app 🎨, designed for tagging incoming image samples from the HoloLens in batches 📸. Below is a demo showcasing its functionality. We utilized this app to report results in the main paper 📝.
</div>

<br><br>

# 9. 🛠️ Troubleshooting Guide

We’re sharing potential solutions 🛠️ for the issues we faced during development. While other challenges may arise, we believe the ones we encountered will address most common scenarios 🌐.

### 9.1. 👓 Rviz

To effectively follow the troubleshooting steps, it is essential to view the images being transmitted through ROS. **Rviz** is the recommended tool for this purpose. 👀

### 9.2. 🖥️ PC Not Receiving Images from the Server

Ensure that the `ROS_IP` and `ROS_MASTER_URI` environment variables are correctly set on both the server and the PC. 🌐

### 9.3. 🤖 HoloLens Not Receiving Images

1. Confirm that **execsupport** is active.
2. If the server is receiving processed images, verify that the endpoint has launched correctly. ✅
3. Ensure that the IP address is set correctly on the **HoloLens**. 💡

### 9.4. 🖼️ PC Not Receiving Relabeled Images & Labels

If this occurs, it's likely that the `ROS_HOSTNAME` on the PC or server is set to a non-null value. Change these settings to `0.0.0.0`. 🔧

### 9.5. ⚠️ OMP: Error #15 - Initializing libiomp5md.dll

You may encounter this error in `run_finetuning_node.py` and `receiveData.py`. To resolve it, open a terminal in the environment where the program is running and execute the following command:

```bash
conda install nomkl --channel conda-forge
```

After this, check that all package requirements are still installed. This solution is courtesy of [postylem](https://stackoverflow.com/questions/20554074/sklearn-omp-error-15-initializing-libiomp5md-dll-but-found-mk2iomp5md-dll). 💡
