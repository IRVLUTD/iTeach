print("Compiling")
import rospy
from cv_bridge import CvBridge
from sensor_msgs.msg import Image
import cv2
import time

class ImagePublisher:
    def __init__(self):
        rospy.init_node("ImagePublisher")



        self.pub = rospy.Publisher("head_camera/rgb/image_raw", Image, queue_size=5)
        self.pub2 = rospy.Publisher("head_camera/depth/image", Image, queue_size=5)
        self.bridge = CvBridge()
        self.img = cv2.imread("PublishImages/rgb.jpg")
        self.depimg = cv2.imread("PublishImages/3d.jpg")

        


    def pubImage(self):
        self.pub.publish(self.bridge.cv2_to_imgmsg(self.img[:,:,::-1]))
        self.pub2.publish(self.bridge.cv2_to_imgmsg(self.depimg[:,:,::-1]))


if __name__ == "__main__":
    print("Running")
    imgpub = ImagePublisher()
    try:
        for _ in range(5000):
            imgpub.pubImage()
            time.sleep(0.05)

    except KeyboardInterrupt:
        print("Exiting")
