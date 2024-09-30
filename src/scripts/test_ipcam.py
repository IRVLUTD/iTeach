import rospy
import cv2
from sensor_msgs.msg import Image
from cv_bridge import CvBridge

def stream_mobile_camera():
    # Initialize ROS node
    rospy.init_node('mobile_camera_stream', anonymous=True)

    # Publisher for the image topic
    pub = rospy.Publisher('/mobile_camera/image_raw', Image, queue_size=10)

    # URL of the IP Webcam stream (update with the actual IP address)
    video_url = 'http://10.42.0.44:8080/video'

    # Open the video stream
    cap = cv2.VideoCapture(video_url)
    bridge = CvBridge()

    rate = rospy.Rate(30)  # 10 Hz

    while not rospy.is_shutdown():
        ret, frame = cap.read()
        if ret:
            # Convert OpenCV image to ROS image message
            image_message = bridge.cv2_to_imgmsg(frame, encoding="bgr8")
            pub.publish(image_message)
        rate.sleep()

    cap.release()

if __name__ == '__main__':
    try:
        stream_mobile_camera()
    except rospy.ROSInterruptException:
        pass
