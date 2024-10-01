"""
Usage: python mobile_camera_stream.py <ip_address> <frame_rate> [--save <output_file>]
- If you want to save the video, include the --save option followed by the desired output file name (e.g., output.mp4).
"""
import rospy
import cv2
from sensor_msgs.msg import Image
from cv_bridge import CvBridge
import argparse

def stream_mobile_camera(ip_address, frame_rate, save_video, output_file=None):
    # Initialize ROS node
    rospy.init_node('mobile_camera_stream', anonymous=True)

    # Publisher for the image topic
    pub = rospy.Publisher('/mobile_camera/image_raw', Image, queue_size=10)

    # Construct the video URL from the provided IP address
    video_url = f'http://{ip_address}:8080/video'

    # Open the video stream
    cap = cv2.VideoCapture(video_url)
    bridge = CvBridge()

    rate = rospy.Rate(frame_rate)  # Set rate from command-line argument

    # Get the width and height of the frames
    width = int(cap.get(cv2.CAP_PROP_FRAME_WIDTH))
    height = int(cap.get(cv2.CAP_PROP_FRAME_HEIGHT))

    # Initialize VideoWriter if saving video
    out = None
    if save_video and output_file:
        fourcc = cv2.VideoWriter_fourcc(*'mp4v')  # Codec for MP4
        out = cv2.VideoWriter(output_file, fourcc, frame_rate, (width, height))

    while not rospy.is_shutdown():
        ret, frame = cap.read()
        if ret:
            # Convert OpenCV image to ROS image message
            image_message = bridge.cv2_to_imgmsg(frame, encoding="bgr8")
            pub.publish(image_message)

            # Save the frame to the MP4 file if enabled
            if out is not None:
                out.write(frame)

        rate.sleep()

    cap.release()
    if out is not None:
        out.release()

if __name__ == '__main__':
    parser = argparse.ArgumentParser(description='Stream video from a mobile camera.')
    parser.add_argument('ip_address', type=str, help='IP address of the mobile camera')
    parser.add_argument('frame_rate', type=int, help='Frame rate for the video stream')
    parser.add_argument('--save', type=str, metavar='output_file', help='Output file name to save the video (MP4)')

    args = parser.parse_args()

    try:
        stream_mobile_camera(args.ip_address, args.frame_rate, args.save is not None, args.save)
    except rospy.ROSInterruptException:
        pass

