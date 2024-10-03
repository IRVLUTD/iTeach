import cv2
import threading
import numpy as np
import rospy, cv_bridge, tf2_ros
from sensor_msgs.msg import Image, CameraInfo
from geometry_msgs.msg import TransformStamped
from .hl2ss import hl2ss, hl2ss_lnm




class HoloRosPublisher:
    """
    HoloRosPublisher Class: This class is responsible for setting up and managing the ROS publishers for the HoloLens device.
    Args:
        host: IP address of the HoloLens device.
        enable_pv: Enable publishing of personal video (PV) data (default: True).
        pv_res: Resolution of the PV data ("720P" or "1080P").
        enable_depth: Enable publishing of depth camera data (default: False).
        debug: Enable debug output (default: False).
    
    Main Function:
        Reads the HoloLens IP from the environment variable.
        Initializes the HoloRosPublisher class with configuration options.
        Starts publishing data from the HoloLens device.
    """

    def __init__(
        self, host, enable_pv=True, pv_res="720P", enable_depth=False, debug=False
    ):
        self._host = host
        self._enable_pv = enable_pv
        self._enable_depth = enable_depth
        self._debug = debug

        self._pv_client = None
        self._depth_client = None

        self._pv_fps = 30

        if pv_res == "720P":
            self._pv_width = 1280
            self._pv_height = 720
        elif pv_res == "1080P":
            self._pv_width = 1920
            self._pv_height = 1080
        else:
            rospy.logerr_once(f"Unsupported PV resolution: {pv_res}")

        self._bridge = cv_bridge.CvBridge()

        self._node_id = "hololens2_publisher"

        self._pv_frame_id = f"holo_pv_optical_frame"
        self._pv_imageTopic = "/hololens/pv_camera/image_raw"
        self._pv_camInfoTopic = "/hololens/pv_camera/camera_info"

        self._depth_frame_id = f"holo_depth_optical_frame"
        self._depth_imageTopic = "/hololens/depth_camera/image_raw"

    def _pv_publisher(self, enable_mrc=True):
        prev_timestamp = 0

        if self._enable_pv:
            hl2ss_lnm.start_subsystem_pv(
                self._host,
                hl2ss.StreamPort.PERSONAL_VIDEO,
                enable_mrc=enable_mrc,
            )

            self._pv_client = hl2ss_lnm.rx_pv(
                self._host,
                hl2ss.StreamPort.PERSONAL_VIDEO,
                mode=hl2ss.StreamMode.MODE_1,
                width=self._pv_width,
                height=self._pv_height,
                framerate=self._pv_fps,
                divisor=1,
                profile=hl2ss.VideoProfile.RAW,
                decoded_format="bgr24",
            )
            self._pv_client.open()

            rospy.loginfo_once("Start publishing messages from PV camera...")

            imagePub = rospy.Publisher(self._pv_imageTopic, Image, queue_size=10)
            camInfoPub = rospy.Publisher(
                self._pv_camInfoTopic, CameraInfo, queue_size=10
            )

            while not rospy.is_shutdown():
                data = self._pv_client.get_next_packet()
                timestamp = data.timestamp

                if timestamp == prev_timestamp:
                    continue

                prev_timestamp = timestamp

                msgTimestamp = rospy.Time.from_sec(timestamp / 1e7)
                pose = data.pose.T
                focal_length = data.payload.focal_length
                principal_point = data.payload.principal_point
                image = data.payload.image

                if self._debug:
                    print("-" * 60)
                    print(f"Timestamp: {timestamp}, msgTimestamp={msgTimestamp}")
                    print(f"PV_Pose: {pose.tolist()}")
                    print(f"Focal length: {focal_length}")
                    print(f"Principal point: {principal_point}")
                    print(f"Image info: {image.shape, image.dtype}")
                    print("-" * 60)

                # Publish image
                msgImage = self._create_msgImage(image, msgTimestamp, self._pv_frame_id)
                imagePub.publish(msgImage)

                # Publish camera info
                msgCamInfo = self._create_msgCamInfo(
                    msgTimestamp,
                    P=[
                        focal_length[0],
                        0.0,
                        principal_point[0],
                        0.0,
                        0.0,
                        focal_length[1],
                        principal_point[1],
                        0.0,
                        0.0,
                        0.0,
                        1.0,
                        0.0,
                    ],
                )
                camInfoPub.publish(msgCamInfo)

    def _depth_publisher(self):
        prev_timestamp = 0

        if self._enable_depth:
            imagePub = rospy.Publisher(self._depth_imageTopic, Image, queue_size=10)

            self._depth_client = hl2ss_lnm.rx_rm_depth_ahat(
                self._host,
                hl2ss.StreamPort.RM_DEPTH_AHAT,
                mode=hl2ss.StreamMode.MODE_1,
                divisor=1,
                profile_z=hl2ss.DepthProfile.SAME,
            )
            self._depth_client.open()

            rospy.loginfo_once("Start publishing messages from Depth camera...")

            while not rospy.is_shutdown():
                data = self._depth_client.get_next_packet()

                timestamp = data.timestamp

                if timestamp == prev_timestamp:
                    continue

                prev_timestamp = timestamp

                msgTimestamp = rospy.Time.from_sec(timestamp / 1e7)
                pose = data.pose.T
                image = data.payload.depth

                if self._debug:
                    print("-" * 60)
                    print(f"Timestamp: {timestamp}, msgTimestamp={msgTimestamp}")
                    print(f"Depth_Pose: {pose.tolist()}")
                    print(f"Image shape: {image.shape, image.dtype}")
                    print("-" * 60)

                # Publish image
                msgImage = self._create_msgImage(
                    image, msgTimestamp, self._depth_frame_id
                )
                imagePub.publish(msgImage)

    def _create_msgImage(
        self, image_array, timestamp, frame_id, encoding="passthrough"
    ):
        """
        ref: http://docs.ros.org/en/noetic/api/sensor_msgs/html/msg/Image.html
        ref: http://wiki.ros.org/cv_bridge/Tutorials/ConvertingBetweenROSImagesAndOpenCVImagesPython
        :param image_array
            numpy array of the image
        :param encoding
            encoding type of the image ()

        :returns msgImage
        """
        msg = self._bridge.cv2_to_imgmsg(image_array, encoding=encoding)
        msg.header.stamp = timestamp
        msg.header.frame_id = frame_id
        return msg

    def _create_msgCamInfo(self, timestamp, D=None, K=None, R=None, P=None):
        """
        ref: http://docs.ros.org/en/noetic/api/sensor_msgs/html/msg/CameraInfo.html
        :param D: float64[5]
            distortion parameters, For "plumb_bob", the 5 parameters are: (k1, k2, t1, t2, k3)
        :param K: float64[9]
            Intrinsic camera matrix for the raw (distorted) images
                [fx  0 cx]
            K = [ 0 fy cy]
                [ 0  0  1]
        :param R: float[9]
            Rectification matrix (stereo cameras only)
            # default: [1, 0, 0, 0, 1, 0, 0, 0, 1]
        :param P: float64[12]
            Intrinsic camera matrix of the processed (rectified) image
                [fx'  0  cx' Tx]
            P = [ 0  fy' cy' Ty]
                [ 0   0   1   0]
        """

        msg = CameraInfo()
        msg.header.stamp = timestamp
        msg.header.frame_id = self._pv_frame_id
        msg.width = self._pv_width
        msg.height = self._pv_height
        msg.distortion_model = "plumb_bob"
        if D is not None:
            msg.D = D
        if K is not None:
            msg.K = K
        if R is not None:
            msg.R = R
        if P is not None:
            msg.P = P
        return msg

    def run(self):
        # Initialize node
        try:
            rospy.init_node(
                name=self._node_id,
                anonymous=False,
                log_level=rospy.DEBUG if self._debug else rospy.INFO,
            )
            rospy.loginfo_once("Node '{}' initialized success...".format(self._node_id))
        except:
            rospy.loginfo_once("Node '{}' initialized failed!!!".format(self._node_id))
            exit()

        threads = []
        if self._enable_pv:
            pv_thread = threading.Thread(target=self._pv_publisher)
            threads.append(pv_thread)
            pv_thread.start()

        if self._enable_depth:
            depth_thread = threading.Thread(target=self._depth_publisher)
            threads.append(depth_thread)
            depth_thread.start()

        rospy.spin()

        # Wait for all threads to complete
        for thread in threads:
            thread.join()

        self.stop()

    def stop(self):
        if self._enable_pv:
            self._pv_client.close()
            hl2ss_lnm.stop_subsystem_pv(self._host, hl2ss.StreamPort.PERSONAL_VIDEO)
            rospy.loginfo_once("Stop publishing messages from PV camera...")
        if self._enable_depth:
            self._depth_client.close()
            rospy.loginfo_once("Stop publishing messages from Depth camera...")
