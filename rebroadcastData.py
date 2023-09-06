import rospy
from sensor_msgs.msg import Image


class ImageRebradcaster:

    onceper = 10

    itemcount = 0

    rgb = None
    dep = None
    lbl = None


    def __init__(self, initnode:bool = True):
        if initnode:
            rospy.init_node("ImageRebroadcaster")

        self.imgSub = rospy.Subscriber("head_camera/rgb/image_raw", Image, self.imageSub)
        self.depSub = rospy.Subscriber("head_camera/depth/image", Image, self.depthSub)
        self.lblSub = rospy.Subscriber("Cole/AutoLabeledImage", Image, self.labelSub)

        self.imgPub = rospy.Publisher("InfrequentImage", Image, queue_size = 2)
        self.depPub = rospy.Publisher("InfrequentDepth", Image, queue_size = 2)
        self.lblPub = rospy.Publisher("Cole/InfrequentAutoLabeledImage", Image, queue_size=2)

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
    
    reb = ImageRebradcaster()
    print("Running")
    rospy.spin()