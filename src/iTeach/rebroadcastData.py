import rospy
from sensor_msgs.msg import Image
import cv2
import cv_bridge
import os
from datetime import datetime

class ImageRebroadcaster:
    
    rgb = None
    dep = None
    lbl = None

    def __init__(self, initnode: bool = True):
        if initnode:
            rospy.init_node("ImageRebroadcaster PC -> Hololens")

        self.imgSub = rospy.Subscriber("head_camera/rgb/image_raw", Image, self.imageSub)
        self.depSub = rospy.Subscriber("head_camera/depth/image", Image, self.depthSub)
        self.lblSub = rospy.Subscriber("pc/detections/bbox_overlayed_rgb", Image, self.labelSub)

        self.imgPub = rospy.Publisher("hololens/in/robot_pov/rgb", Image, queue_size=1)
        self.depPub = rospy.Publisher("hololens/in/robot_pov/depth", Image, queue_size=1)
        self.lblPub = rospy.Publisher("hololens/in/robot_pov/detections/bbox_overlayed_rgb", Image, queue_size=1)

        self.bridge = cv_bridge.CvBridge()
        
        self.onceper = 30
        self.itemcount = 0
        self.onceper *= 5
        
        # Ensure the directory exists
        self.save_directory = "RGB"
        os.makedirs(self.save_directory, exist_ok=True)

        self.frame_counter = 0  # Counter to track frames

    # def imageSub(self, rosImage):
    #     self.rgb = rosImage
    #     # Save the RGB image with a timestamp including microseconds
    #     timestamp = datetime.now().strftime("%Y%m%d_%H%M%S_%f")
    #     image_filename = f"robot_rgb_{timestamp}.jpg"
    #     self.save_image(self.rgb, image_filename, dir_suffix='robot_realtime_pov')
        
    #     self.itemcount += 1
        
    #     # Publish if the itemcount exceeds the defined limit
    #     if self.itemcount >= self.onceper:
    #         self.pub()

    def imageSub(self, rosImage):
        self.frame_counter += 1  # Increment the frame counter

        # Capture every second frame to achieve 15 fps
        if self.frame_counter % 6 == 0:
            self.rgb = rosImage
            # Save the RGB image with a timestamp including microseconds
            timestamp = datetime.now().strftime("%Y%m%d_%H%M%S_%f")
            image_filename = f"robot_pov_rgb_{timestamp}.jpg"
            # self.save_image(self.rgb, image_filename, dir_suffix='robot_realtime_pov')
            self.itemcount += 1
            
            # Publish if the itemcount exceeds the defined limit
            if self.itemcount >= self.onceper:
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
        self.itemcount = 0
        if self.rgb is None or self.dep is None or self.lbl is None:
            print("Not sending images, have not received rgb, depth, and labeled images")
            return
        
        # Publish the images
        self.imgPub.publish(self.rgb)
        self.depPub.publish(self.dep)
        self.lblPub.publish(self.lbl)

        # Save the RGB image with a timestamp
        timestamp = datetime.now().strftime("%Y%m%d_%H%M%S")
        # self.save_image(self.rgb, f"rob   ot_pov_rebroadcasted_rgb_{timestamp}.jpg", dir_suffix='rebroadcast_pov')
        # self.save_image(self.dep, f"depth_{timestamp}.jpg")
        # self.save_image(self.lbl, f"label_{timestamp}.jpg")

    def save_image(self, ros_image, filename, dir_suffix=""):
        try:
            cv_image = self.bridge.imgmsg_to_cv2(ros_image, desired_encoding="bgr8")
            out_dir = f"{self.save_directory}/{dir_suffix}"
            os.makedirs(out_dir, exist_ok=True)
            save_path = os.path.join(out_dir, filename)
            cv2.imwrite(save_path, cv_image)
            print(f"Saved image to {save_path}")
        except Exception as e:
            print(f"Failed to save image: {e}")

if __name__ == "__main__":
    reb = ImageRebroadcaster()
    print("Running")
    rospy.spin()
