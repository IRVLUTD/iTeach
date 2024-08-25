import rospy
from cv_bridge import CvBridge, CvBridgeError
from sensor_msgs.msg import Image
import cv2
import os
import argparse
import logging

# Set up logging
logging.basicConfig(level=logging.INFO, format='%(asctime)s - %(levelname)s - %(message)s')

class ImagePublisher:
    """
    A ROS node that publishes RGB and depth images from specified directories.

    The RGB and depth images are assumed to be in subdirectories 'RGB' and 'depth'
    under a provided root directory. The images are published continuously until
    the node is shut down.

    Attributes:
        rgb_folder (str): Path to the folder containing RGB images.
        depth_folder (str): Path to the folder containing depth images.
        pub (rospy.Publisher): ROS publisher for RGB images.
        pub2 (rospy.Publisher): ROS publisher for depth images.
        bridge (CvBridge): Bridge between OpenCV images and ROS image messages.
    """

    def __init__(self, root_dir):
        """
        Initialize the ImagePublisher with the paths to the RGB and depth folders.

        Args:
            root_dir (str): Path to the root directory containing 'RGB' and 'depth' subdirectories.
        """
        rospy.init_node("image_publisher", anonymous=True)

        # Construct the paths to the RGB and depth folders
        self.rgb_folder = os.path.join(root_dir, "RGB")
        self.depth_folder = os.path.join(root_dir, "depth")

        # Initialize ROS publishers for RGB and depth images
        self.pub = rospy.Publisher("head_camera/rgb/image_raw", Image, queue_size=5)
        self.pub2 = rospy.Publisher("head_camera/depth/image", Image, queue_size=5)

        # Initialize the CvBridge for converting OpenCV images to ROS messages
        self.bridge = CvBridge()

        logging.info(f"ImagePublisher initialized with RGB folder: {self.rgb_folder} and Depth folder: {self.depth_folder}")

    def pubImage(self):
        """
        Publish images from the RGB and depth folders.

        This method iterates over all the image files in the RGB folder, assumes
        corresponding depth images exist in the depth folder with the same filenames,
        and publishes them to the respective ROS topics.
        """
        try:
            # List all files in the RGB folder
            image_files = [f for f in os.listdir(self.rgb_folder) if os.path.isfile(os.path.join(self.rgb_folder, f))]

            for img_file in image_files:
                rgb_image_path = os.path.join(self.rgb_folder, img_file)
                depth_image_path = os.path.join(self.depth_folder, img_file)

                # Load the images
                img = cv2.imread(rgb_image_path)
                depimg = cv2.imread(depth_image_path)

                if img is None:
                    rospy.logerr(f"Failed to load RGB image from {rgb_image_path}!")
                    continue
                if depimg is None:
                    rospy.logerr(f"Failed to load Depth image from {depth_image_path}!")
                    continue

                # Publish the images
                self.pub.publish(self.bridge.cv2_to_imgmsg(img[:, :, ::-1], "bgr8"))
                self.pub2.publish(self.bridge.cv2_to_imgmsg(depimg[:, :, ::-1], "bgr8"))

                logging.info(f"Published RGB image: {rgb_image_path} and Depth image: {depth_image_path}")

        except CvBridgeError as e:
            rospy.logerr(f"Failed to publish image: {e}")
            logging.error(f"Failed to publish image due to CvBridgeError: {e}")

if __name__ == "__main__":
    print("Running...")

    # Argument parsing
    parser = argparse.ArgumentParser(description="Publish RGB and Depth images from a root directory containing subfolders.")
    parser.add_argument('--root_dir', type=str, required=True, help="Path to the root directory containing 'RGB' and 'depth' subdirectories.")
    args = parser.parse_args()

    # Create ImagePublisher instance with the provided root directory
    imgpub = ImagePublisher(root_dir=args.root_dir)
    rate = rospy.Rate(1)  # 1 Hz (adjust the rate as needed)

    try:
        while True:  # Infinite loop
            if rospy.is_shutdown():
                break
            imgpub.pubImage()
            rate.sleep()

    except rospy.ROSInterruptException:
        print("ROS Interrupted. Exiting...")
        logging.info("ROS Interrupted. Exiting...")
    except KeyboardInterrupt:
        print("Exiting...")
        logging.info("Process interrupted by user. Exiting...")

    finally:
        print("Image publishing stopped.")
        logging.info("Image publishing stopped.")
