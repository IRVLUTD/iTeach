import rospy
import cv2
import numpy as np
from sensor_msgs.msg import Image
from cv_bridge import CvBridge
import hl2ss
import hl2ss_lnm

# Settings --------------------------------------------------------------------

# HoloLens address
host = "10.42.0.150"

# Operating mode
mode = hl2ss.StreamMode.MODE_0

# Enable Mixed Reality Capture (Holograms)
enable_mrc = True

# Enable Shared Capture
shared = False

# Camera parameters
width = 1280
height = 720
framerate = 30
divisor = 2 
profile = hl2ss.VideoProfile.H265_MAIN
bitrate = None
decoded_format = 'bgr24'

# ROS setup ------------------------------------------------------------------

rospy.init_node('hololens_video_publisher', anonymous=True)
image_pub = rospy.Publisher('/hololens/pv_camera/image_raw', Image, queue_size=10)
bridge = CvBridge()

# Initialize HoloLens client ------------------------------------------------

hl2ss_lnm.start_subsystem_pv(host, hl2ss.StreamPort.PERSONAL_VIDEO, enable_mrc=enable_mrc, shared=shared)
client = hl2ss_lnm.rx_pv(host, hl2ss.StreamPort.PERSONAL_VIDEO, mode=mode, width=width, height=height, framerate=framerate, divisor=divisor, profile=profile, bitrate=bitrate, decoded_format=decoded_format)
client.open()

def image_callback(event):
    """Callback function for timer to publish image."""
    try:
        data = client.get_next_packet()
        
        if data:
            np_image = np.frombuffer(data.payload.image, dtype=np.uint8).reshape((height, width, 3))  # Adjust shape based on decoded format

            print(np_image, np_image.shape)

            # Convert OpenCV image to ROS Image message
            ros_image = bridge.cv2_to_imgmsg(np_image, encoding='passthrough')  # Adjust encoding based on format

            # Publish image to ROS topic
            image_pub.publish(ros_image)

            # Debug print statements
            rospy.loginfo(f'Frame captured at {data.timestamp}')
            rospy.loginfo(f'Focal length: {data.payload.focal_length}')
            rospy.loginfo(f'Principal point: {data.payload.principal_point}')
            rospy.loginfo(f'Exposure Time: {data.payload.exposure_time}')
            rospy.loginfo(f'Exposure Compensation: {data.payload.exposure_compensation}')
            rospy.loginfo(f'Lens Position (Focus): {data.payload.lens_position}')
            rospy.loginfo(f'Focus State: {data.payload.focus_state}')
            rospy.loginfo(f'ISO Speed: {data.payload.iso_speed}')
            rospy.loginfo(f'White Balance: {data.payload.white_balance}')
            rospy.loginfo(f'ISO Gains: {data.payload.iso_gains}')
            rospy.loginfo(f'White Balance Gains: {data.payload.white_balance_gains}')
            rospy.loginfo(f'Pose: {data.pose}')
    except Exception as e:
        rospy.logerr(f"Error during image capture or publishing: {e}")

# Set up a timer to call image_callback periodically
timer = rospy.Timer(rospy.Duration(1.0 / framerate), image_callback)

# Keep the node running
rospy.spin()

# Cleanup
client.close()
hl2ss_lnm.stop_subsystem_pv(host, hl2ss.StreamPort.PERSONAL_VIDEO)

