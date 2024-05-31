import os
import cv2
import rospy
from cv_bridge import CvBridge
from sensor_msgs.msg import Image
from std_msgs.msg import String
from datetime import datetime
from train import run


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

        model_name = "YOLOv5_iTeachModel"
        
        try:
            print(f"case-1: {model_name}/weights/last.pt")
            run(
                data = "doordetect.yaml", 
                imgsz = 640, 
                weights = f"{model_name}/weights/last.pt", 
                epochs=4,
                nosave=True, 
                noplots=False, 
                noval=True,
                project=".",
                name=model_name,
                exist_ok=True
            )
        except:
            print("case-2: yolov5m.pt")
            run(
                data = "doordetect.yaml", 
                imgsz = 640, 
                weights = "pretrained_best.pt", 
                epochs=4,
                nosave=True, 
                noplots=True, 
                noval=True,
                project=".",
                name=model_name,
                exist_ok=True
            )
        
        # train.run(resume = True, epochs = 1)

        """
        Run val.py with the recent checkpoint
        """
        os.system(f'echo Running {model_name}; python val.py --data data/doordetect.yaml --weights {model_name}/weights/last.pt --conf-thres 0.7 --iou-thres 0.7')

        self.imageReceived = False
        self.labelReceived = False
        self.depthReceived = False


if __name__ == "__main__":
    imgsub = ImageSubscriber()
    print("Running")
    rospy.spin()
        
