import os
import cv2
import json
import rospy
from cv_bridge import CvBridge
from sensor_msgs.msg import Image
from std_msgs.msg import (String, Bool)
from datetime import datetime
import iTeach.fetchdetect as fetchdetect


class HololensUserDataSubscriber:
    
    def __init__(self, model, ros_image_reader, initnode:bool = True):
        if initnode:
            rospy.init_node("HololensOutDataSubscriber")

        self.dh_model = model
        self.cfg = self.dh_model._cfg
        self.ros_image_reader = ros_image_reader
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

            # Perform finetuning
            curr_mAP50, overall_best_mAP50_info = self.dh_model.train_model()        
            print("Current mAP50: %f, Overall best mAP50: %f", curr_mAP50, overall_best_mAP50_info)

            pub_data = {
                'curr_ft_iter_num': self.dh_model.get_finetune_iter_num(),
                'curr_mAP50': curr_mAP50,
                'overall_best_mAP50_ft_iter': overall_best_mAP50_info['mAP50'],
                'overall_best_mAP50': overall_best_mAP50_info['finetune_iter_num'],
            }

            # Send ACK with metrics
            self.ft_ack_pub.publish(self.stringify_json(pub_data))
            print(f"PUB_DATA: {pub_data}")
            print("Published ACK")

            # Select overall best checkpoint after finetuning
            self.dh_model.select_model_ckpt()
            overall_best_ckpt_path = self.dh_model.get_model_ckpt()

            # Stop and restart the ros_image_reader node
            self.restart_ros_image_reader(overall_best_ckpt_path)

    def restart_ros_image_reader(self, ckpt_path):
        # Stop the existing ros_image_reader node
        self.ros_image_reader.shutdown()  # Assuming ros_image_reader has a shutdown method
        rospy.sleep(2)  # Optional: sleep for a moment to ensure shutdown

        # Restart with the new checkpoint
        conf_thres = self.dh_model._cfg.CONF_THRES if self.dh_model._cfg.CONF_THRES else 0.7
        iou_thres = self.dh_model._cfg.IOU_THRES if self.dh_model._cfg.IOU_THRES else 0.7

        self.ros_image_reader = fetchdetect.ros_image_reader(
            data=self.dh_model.cfg_path,
            weights=ckpt_path,
            nosave=True,
            send_ros=True,
            conf_thres=conf_thres,
            iou_thres=iou_thres
        )
        print("ros_image_reader node restarted with updated weights.")

    def stringify_json(self, data, indent=None):
        try:
            json_string = json.dumps(data, indent=indent)
            return json_string
        except TypeError as e:
            raise ValueError(f"Data provided is not serializable to JSON: {str(e)}")

    def saveResults(self, img, lbl, dep):
        cwd = os.getcwd()
        train_data_dir = os.path.abspath(os.path.expanduser(os.path.join(self.cfg.path, self.cfg.train, '..')))
        title = datetime.now().strftime("Hololens_%d-%m-%Y_%H-%M-%S")
        
        os.chdir(f"{train_data_dir}/images")
        cv2.imwrite(title+".jpg", img)
        
        os.chdir(f"{train_data_dir}/depth")
        cv2.imwrite(title+".jpg", dep)
        
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
