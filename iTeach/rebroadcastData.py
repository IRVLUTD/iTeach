"""
Makes sure that all of the outputs are in sync
 - Depth and the labelled RGB
 - Depth is not used as of now
"""

import rospy
from sensor_msgs.msg import Image
import cv2

class ImageRebroadcaster:

    onceper = 10
    itemcount = 0

    rgb = None
    dep = None
    lbl = None


    def __init__(self, initnode:bool = True):
        if initnode:
            rospy.init_node("ImageRebroadcaster PC -> Hololens")

        self.imgSub = rospy.Subscriber("head_camera/rgb/image_raw", Image, self.imageSub)
        self.depSub = rospy.Subscriber("head_camera/depth/image", Image, self.depthSub)
        self.lblSub = rospy.Subscriber("pc/detections/bbox_overlayed_rgb", Image, self.labelSub)

        self.imgPub = rospy.Publisher("hololens/in/robot_pov/rgb", Image, queue_size = 2) # continuous Robot RGB POV image
        self.depPub = rospy.Publisher("hololens/in/robot_pov/depth", Image, queue_size = 2) # continuous Robot DEPTH POV image
        self.lblPub = rospy.Publisher("hololens/in/robot_pov/detections/bbox_overlayed_rgb", Image, queue_size=2) # continuous YOLO preds overlayed rgb image
        
        self.onceper *= 3
        
        
    def imageSub(self, rosImage):
        self.rgb = rosImage
        self.itemcount += 1
        if self.itemcount > self.onceper:
            self.pub()

    def depthSub(self, rosImage):
        self.dep = rosImage
        self.itemcount += 1
        if self.itemcount > self.onceper:
            self.pub()

    def labelSub(self, rosImage):
        self.lbl = rosImage
        self.itemcount += 1
        if self.itemcount > self.onceper:
            self.pub()



    def pub(self):
        self.itemcount=0
        if self.rgb == None or self.dep == None or self.lbl == None:
            print("Not sending images, have not received rgb, depth, and labeled images")
            return
        self.imgPub.publish(self.rgb)
        self.depPub.publish(self.dep)
        self.lblPub.publish(self.lbl)

        

if __name__ == "__main__":
    
    reb = ImageRebroadcaster()
    print("Running")
    rospy.spin()
