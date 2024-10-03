#------------------------------------------------------------------------------
# This script receives video from the HoloLens front RGB camera and publishes
# it to a ROS topic.
# The camera supports various resolutions and framerates. See
# https://github.com/jdibenes/hl2ss/blob/main/etc/pv_configurations.txt
# for a list of supported formats. The default configuration is 1080p 30 FPS. 
# The stream supports three operating modes: 0) video, 1) video + camera pose, 
# 2) query calibration (single transfer).
# Press esc to stop.
#------------------------------------------------------------------------------

from pynput import keyboard
import cv2
import rospy
from sensor_msgs.msg import Image
from cv_bridge import CvBridge
import hl2ss
from .hl2ss import hl2ss_lnm

# Settings --------------------------------------------------------------------

# HoloLens address
host = "10.42.0.150"

# Operating mode
# 0: video
# 1: video + camera pose
# 2: query calibration (single transfer)
mode = hl2ss.StreamMode.MODE_1

# Enable Mixed Reality Capture (Holograms)
enable_mrc = True

# Enable Shared Capture
shared = False

# Camera parameters
width     = 1920
height    = 1080
framerate = 30
divisor = 1 
profile = hl2ss.VideoProfile.H265_MAIN
bitrate = None
decoded_format = 'bgr24'

# ROS setup ------------------------------------------------------------------

rospy.init_node('hololens_video_publisher', anonymous=True)
image_pub = rospy.Publisher('/hololens/pv_camera/image_raw', Image, queue_size=10)
bridge = CvBridge()

# Start HoloLens subsystem --------------------------------------------------

hl2ss_lnm.start_subsystem_pv(host, hl2ss.StreamPort.PERSONAL_VIDEO, enable_mrc=enable_mrc, shared=shared)

if mode == hl2ss.StreamMode.MODE_2:
    # Query calibration data
    data = hl2ss_lnm.download_calibration_pv(host, hl2ss.StreamPort.PERSONAL_VIDEO, width, height, framerate)
    print('Calibration')
    print(f'Focal length: {data.focal_length}')
    print(f'Principal point: {data.principal_point}')
    print(f'Radial distortion: {data.radial_distortion}')
    print(f'Tangential distortion: {data.tangential_distortion}')
    print('Projection')
    print(data.projection)
    print('Intrinsics')
    print(data.intrinsics)
    print('RigNode Extrinsics')
    print(data.extrinsics)
    print(f'Intrinsics MF: {data.intrinsics_mf}')
    print(f'Extrinsics MF: {data.extrinsics_mf}')
else:
    enable = True

    def on_press(key):
        global enable
        enable = key != keyboard.Key.esc
        return enable

    listener = keyboard.Listener(on_press=on_press)
    listener.start()

    client = hl2ss_lnm.rx_pv(host, hl2ss.StreamPort.PERSONAL_VIDEO, mode=mode, width=width, height=height, framerate=framerate, divisor=divisor, profile=profile, bitrate=bitrate, decoded_format=decoded_format)
    client.open()

    while enable:
        data = client.get_next_packet()

        # Convert image from OpenCV format to ROS Image message
        ros_image = bridge.cv2_to_imgmsg(data.payload.image, encoding=decoded_format)
        ros_image.header.stamp = rospy.Time.now()
        ros_image.header.frame_id = 'hololens_rgb_camera'

        # Publish image to ROS topic
        image_pub.publish(ros_image)

        # Debug print statements
        print(f'Frame captured at {data.timestamp}')
        print(f'Focal length: {data.payload.focal_length}')
        print(f'Principal point: {data.payload.principal_point}')
        print(f'Exposure Time: {data.payload.exposure_time}')
        print(f'Exposure Compensation: {data.payload.exposure_compensation}')
        print(f'Lens Position (Focus): {data.payload.lens_position}')
        print(f'Focus State: {data.payload.focus_state}')
        print(f'ISO Speed: {data.payload.iso_speed}')
        print(f'White Balance: {data.payload.white_balance}')
        print(f'ISO Gains: {data.payload.iso_gains}')
        print(f'White Balance Gains: {data.payload.white_balance_gains}')
        print(f'Pose')
        print(data.pose)

    client.close()
    listener.join()

hl2ss_lnm.stop_subsystem_pv(host, hl2ss.StreamPort.PERSONAL_VIDEO)

