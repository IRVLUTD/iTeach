import os
import cv2
import json
import rospy
from cv_bridge import CvBridge
from sensor_msgs.msg import Image
from std_msgs.msg import (String, Bool)
from datetime import datetime


class HololensUserDataSubscriber:
    
    def __init__(self, model, initnode:bool = True):
        if initnode:
            rospy.init_node("HololensOutDataSubscriber")

        self.dh_model = model
        self.cfg = self.dh_model._cfg
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
        self.ft_ckpt_pub = rospy.Publisher("finetune/overall_best_ckpt", String, queue_size=5)
        self.ft_ack_pub = rospy.Publisher("finetune/ack_with_metrics", String, queue_size=5)

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

        
        # todo: implement finetuning logic here
        # perform finetuning
        curr_mAP50, overall_best_mAP50_info = self.dh_model.train_model()        
        print("Current mAP50: %f, Overall best mAP50: %f", curr_mAP50, overall_best_mAP50_info)

        pub_data = {
            'curr_ft_iter_num': self.dh_model.get_finetune_iter_num(),
            'curr_mAP50': curr_mAP50,
            'overall_best_mAP50_ft_iter': overall_best_mAP50_info['mAP50'],
            'overall_best_mAP50': overall_best_mAP50_info['finetune_iter_num'],
        }


        # todo: fetch the overall best model from the database; won't set the dh_model, only retrieves best ckpt
        best_ckpt = self.dh_model.select_model_ckpt()
        self.ft_ckpt_pub.publish(best_ckpt)

        # as soon as the finetuning is complete; send an ack with metrics of curr model and prev best model performance
        self.ft_ack_pub.publish(self.stringify_json(pub_data))

        print(f"PUB_DATA: {pub_data}")
        print("Published ACK")


    def stringify_json(self, data, indent=None):
        try:
            json_string = json.dumps(data, indent=indent)
            return json_string
        except TypeError as e:
            raise ValueError(f"Data provided is not serializable to JSON: {str(e)}")

    def saveResults(self, img, lbl, dep):
        cwd = os.getcwd()
        # train_data_dir = os.path.abspath(os.path.expanduser(os.path.join(self.cfg.path, self.cfg.train, '..'))) # for hololens
        train_data_dir = os.path.abspath(os.path.expanduser(os.path.join(self.cfg.path, self.cfg.train, '..', 'cache')))
        title = datetime.now().strftime("Hololens_%d-%m-%Y_%H-%M-%S")
        
        os.chdir(f"{train_data_dir}/images")
        cv2.imwrite(title+".jpg", img)
        
        os.chdir(f"{train_data_dir}/depth")
        cv2.imwrite(title+".png", dep)
        
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
