import os
import cv2
import json
import rospy
from cv_bridge import CvBridge
from sensor_msgs.msg import Image
from std_msgs.msg import String, Bool
from datetime import datetime

class HololensUserDataSubscriber:
    
    def __init__(self, model, initnode: bool = True):
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
        self.faultyRGBsub = rospy.Subscriber("/hololens/out/user_labelled/rgb", Image, self.faultyRGBSub)
        
        self.ft_ckpt_pub = rospy.Publisher("finetune/overall_best_ckpt", String, queue_size=5)
        self.ft_ack_pub = rospy.Publisher("finetune/ack_with_metrics", String, queue_size=5)

    def imageSub(self, rosImage):
        img = self.bridge.imgmsg_to_cv2(rosImage, desired_encoding='passthrough')
        self.image = img[:, :, ::-1]
        self.imageReceived = True
        print("Received image")
        if self.imageReceived and self.labelReceived and self.depthReceived:
            self.saveResults(self.image, self.label, self.depth)

    def labelSub(self, Text):
        self.label = Text.data
        self.labelReceived = True
        print("Received label")
        if self.imageReceived and self.labelReceived and self.depthReceived:
            self.saveResults(self.image, self.label, self.depth)

    def depthSub(self, dep):
        dep = self.bridge.imgmsg_to_cv2(dep, desired_encoding='passthrough')
        self.depth = dep[:, :]
        self.depthReceived = True
        print("Received depth")
        if self.imageReceived and self.labelReceived and self.depthReceived:
            self.saveResults(self.image, self.label, self.depth)

    def faultyRGBSub(self, faulty_rgb_sample_msg):
        img = self.bridge.imgmsg_to_cv2(faulty_rgb_sample_msg, desired_encoding='passthrough')
        self.image = img[:, :, ::-1]
        print("Received faulty RGB sample")
        self.save_faulty_sample(self.image)

    def finetuneSigSub(self, ft_sig_msg):
        self.finetuneSignalReceived = ft_sig_msg.data
        if self.finetuneSignalReceived:
            print(f"Received finetune cmd...: {ft_sig_msg.data}")

        # Implement finetuning logic here
        curr_mAP50, overall_best_mAP50_info = self.dh_model.train_model()        
        print("Current mAP50: %f, Overall best mAP50: %f" % (curr_mAP50, overall_best_mAP50_info))

        pub_data = {
            'curr_ft_iter_num': self.dh_model.get_finetune_iter_num(),
            'curr_mAP50': curr_mAP50,
            'overall_best_mAP50_ft_iter': overall_best_mAP50_info['mAP50'],
            'overall_best_mAP50': overall_best_mAP50_info['finetune_iter_num'],
        }

        best_ckpt = self.dh_model.select_model_ckpt()
        self.ft_ckpt_pub.publish(best_ckpt)

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
        train_data_dir = os.path.abspath(os.path.expanduser(os.path.join(self.cfg.path, self.cfg.train, '..'))) # for hololens
        title = datetime.now().strftime("Hololens_%d-%m-%Y_%H-%M-%S")
        
        os.chdir(f"{train_data_dir}/images")
        cv2.imwrite(title + ".png", img)
        
        os.chdir(f"{train_data_dir}/depth")
        cv2.imwrite(title + ".png", dep)
        
        os.chdir(f"{train_data_dir}/labels")
        os.chdir("./../labels")
        with open(title + ".txt", 'w') as file:
            # Flip YOLO labels horizontally as this comes flipped from hololens app
            print("Flipping incoming labels horizontally due to Unity convention. ⚠️  (todo): change later in the hololens app source code")
            flipped_labels = ""
            lines = str(lbl).strip().split('\n')
            for line in lines:
                parts = line.strip().split()
                class_idx, cx, cy, w, h = map(float, parts)
                new_cx = 1.0 - cx
                flipped_labels += f"{int(class_idx)} {new_cx} {cy} {w} {h}\n"

            file.write(flipped_labels)
        
        os.chdir(cwd)
        
        self.imageReceived = False
        self.depthReceived = False
        self.labelReceived = False
        self.finetuneSignalReceived = False

    def save_faulty_sample(self, img):
        cwd = os.getcwd()
        train_data_dir = os.path.abspath(os.path.expanduser(os.path.join(self.cfg.path, self.cfg.train, '..')))  # for hololens
        title = datetime.now().strftime("faulty_sample_collected_%d-%m-%Y_%H-%M-%S")
        out_dir = f"{train_data_dir}/from_hololens_faulty_samples_with_pretrained_bboxes"
        os.makedirs(out_dir)
        os.chdir(out_dir)  # Make sure this directory exists
        cv2.imwrite(title + ".jpg", img)
        print(f"Saved faulty sample to {train_data_dir}/faulty_samples/{title}.jpg")
        os.chdir(cwd)
