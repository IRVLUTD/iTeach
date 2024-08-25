import os
import cv2
import rospy
from cv_bridge import CvBridge
from sensor_msgs.msg import Image
from std_msgs.msg import (String, Bool)
from datetime import datetime
from iTeach.train import run


class HololensUserDataSubscriber:
    
    def __init__(self, model, initnode:bool = True):
        if initnode:
            rospy.init_node("HololensOutDataSubscriber")

        self.dh_model = model
        self.cfg = self.dh_model.cfg
        self.bridge = CvBridge()
        
        self.image = None
        self.depth = None
        self.label = None
        self.ft_signal = False
        self.imageReceived = False
        self.depthReceived = False
        self.labelReceived = False
        self.finetuneSignalReceived = False

        self.imgsub = rospy.Subscriber("hololens/out/robot_pov/raw_rgb", Image, self.imageSub)
        self.depsub = rospy.Subscriber("hololens/out/user_labelled/depth", Image, self.depthSub)
        self.texsub = rospy.Subscriber("hololens/out/user_labelled/labels", String, self.labelSub)
        self.ftsub = rospy.Subscriber("hololens/out/finetune_signal", Bool, self.finetuneSigSub)
        self.ft_ack_pub = rospy.Publisher("/finetune/ack_with_metrics", String, queue_size=5)
        
        # todo: create a publisher to send the finetuning details    

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
        
    
    def finetuneSigSub(self, ft_sig_msg):
        self.finetuneSignalReceived = ft_sig_msg.data
        if self.finetuneSignalReceived:
            print(f"Received finetune cmd...: {ft_sig_msg.data}")

        # perform finetuning
        results = self.dh_model.train_model()
        
        print()

        # todo: implement finetuning logic here
        # metrics
        # as soon as the finetuning is complete; send an ack with metrics of curr model and prev best model performance
        self.ft_ack_pub.publish(f"Finished finetune iter: {self.dh_model.} with <num> samples.\nfinetuning complete. Metrics")

        # thorough a topic


    def saveResults(self, img, lbl, dep):
        cwd = os.getcwd()
        train_data_dir = os.path.abspath(os.path.expanduser(os.path.join(self.cfg.path, self.cfg.train, '..')))
        title = datetime.now().strftime("Hololens_%d-%m-%Y_%H-%M-%S")
        
        # save rgb
        os.chdir(f"{train_data_dir}/images")
        cv2.imwrite(title+".jpg", img)
        
        # save depth
        os.chdir(f"{train_data_dir}/depth")
        cv2.imwrite(title+".jpg", dep)
        
        # save labels
        os.chdir(f"{train_data_dir}/labels")
        os.chdir("./../labels")
        file = open(title+".txt", r'w')
        file.write(str(lbl))
        file.close()
        
        os.chdir(cwd)
        
        self.imageReceived = False
        self.depthReceived = False
        self.labelReceived = False
        self.finetuneSignalReceived = False


if __name__ == "__main__":
    imgsub = HololensUserDataSubscriber()
    print("Running")
    rospy.spin()
