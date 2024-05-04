import rospy
from cv_bridge import CvBridge
from sensor_msgs.msg import Image
from std_msgs.msg import String
import cv2
from datetime import datetime
import os
from train import run



from train import train
import numpy as np

class ImageSubscriber:
    imageReceived = False
    depthReceived = False
    labelReceived = False
    image = None
    depth = None
    label = None

    def __init__(self, initnode:bool = True):
        if initnode:
            rospy.init_node("ImageSubscriber")



        self.imgsub = rospy.Subscriber("Cole/RawLabeledImage", Image, self.imageSub)
        self.depSub = rospy.Subscriber("LabeledDepth", Image, self.depthSub)
        self.texsub = rospy.Subscriber("ImageLabels", String, self.labelSub)
        self.bridge = CvBridge()
        
    

    def imageSub(self, rosImage):
        img = self.bridge.imgmsg_to_cv2(rosImage, desired_encoding='passthrough')
        self.image = img[:,:,::-1]
        self.imageReceived = True
        print("Received image")
        if(self.imageReceived and self.labelReceived and self.depthReceived):
            self.saveResults(self.image, self.label, self.depth)


    def labelSub(self, Text):
        self.label = Text.data
        self.labelReceived = True
        print("Received label")
        if(self.imageReceived and self.labelReceived and self.depthReceived):
            self.saveResults(self.image, self.label, self.depth)
            

    def depthSub(self, dep):
        dep = self.bridge.imgmsg_to_cv2(dep, desired_encoding='passthrough')
        self.depth = dep[:,:]
        self.depthReceived = True
        print("Received depth")
        if(self.imageReceived and self.labelReceived and self.depthReceived):
            self.saveResults(self.image, self.label, self.depth)
        
            

    def saveResults(self, img, lbl, dep):

        
        os.chdir("./Dataset/images")
        title = datetime.now().strftime("Holo_%d-%m-%Y_%H-%M-%S")
        cv2.imwrite(title+".jpg", img)
        os.chdir("./../depth")
        cv2.imwrite(title+".jpg", dep)
        os.chdir("./../labels")
        file = open(title+".txt", r'w')
        file.write(str(lbl))
        file.close()
        os.chdir("./../..")
        
        try:
            run(
                data = "doordetect.yaml", 
                imgsz = 640, 
                weights = "Model/weights/last.pt", 
                epochs=1, 
                nosave=True, 
                noplots=False, 
                noval=True,
                project=".",
                name="Model",
                exist_ok=True
            )
        except:
            run(
                data = "doordetect.yaml", 
                imgsz = 640, 
                weights = "yolov5m.pt", 
                epochs=1, 
                nosave=True, 
                noplots=True, 
                noval=True,
                project=".",
                name="Model",
                exist_ok=True
            )
        
        # train.run(resume = True, epochs = 1)

        self.imageReceived = False
        self.labelReceived = False
        self.depthReceived = False

        



    


if __name__ == "__main__":
    imgsub = ImageSubscriber()
    print("Running")
    rospy.spin()
        
