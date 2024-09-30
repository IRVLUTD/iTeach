import os
import cv2
import matplotlib.pyplot as plt
from tqdm import tqdm

class YoloVisualizer:
    def __init__(self, image_dir, label_dir, output_dir):
        self.image_dir = image_dir
        self.label_dir = label_dir
        self.output_dir = output_dir
        os.makedirs(output_dir, exist_ok=True)

    def draw_bounding_boxes(self, image_path, label_path):
        """Draw bounding boxes on an image based on YOLO labels."""
        # Load image
        image = cv2.imread(image_path)
        img_height, img_width = image.shape[:2]

        # Read YOLO label file
        with open(label_path, 'r') as f:
            labels = f.readlines()

        for label in labels:
            parts = label.strip().split()
            class_id = int(parts[0])
            x_center, y_center, width, height = map(float, parts[1:])
            
            # Convert YOLO normalized coordinates to pixel values
            x_min = int((x_center - width / 2) * img_width)
            x_max = int((x_center + width / 2) * img_width)
            y_min = int((y_center - height / 2) * img_height)
            y_max = int((y_center + height / 2) * img_height)
            
            # Assign color based on class
            color = (0, 0, 255) if class_id == 0 else (0, 255, 255)  # Green for class 0, Yellow for class 1
            
            # Draw bounding box
            cv2.rectangle(image, (x_min, y_min), (x_max, y_max), color, 2)
            
            # Add class label with background
            label_text = 'Door' if class_id == 0 else 'Handle'
            
            # Font settings for HERSHEY_COMPLEX
            font = cv2.FONT_HERSHEY_DUPLEX
            font_scale = 0.6
            font_thickness = 1

            # Get text size
            (text_width, text_height), baseline = cv2.getTextSize(label_text, font, font_scale, font_thickness)
            
            # Set the label box to the top-left corner of the bounding box
            text_x = x_min
            text_y = y_min - 5  # Slight padding above the box
            
            # Adjust if the text box goes outside the image (above the top edge)
            if text_y - text_height < 0:
                text_y = y_min + text_height + 5  # Move it inside the box if outside
                
            # Adjust the text box if it extends beyond the image width
            if text_x + text_width > img_width:
                text_x = x_max - text_width

            # Draw text background (filled rectangle)
            cv2.rectangle(image, (text_x, text_y - text_height - baseline), 
                          (text_x + text_width, text_y), color, cv2.FILLED)
            
            # Add the label text on top of the background
            cv2.putText(image, label_text, (text_x, text_y - baseline), font, font_scale, 
                        (0, 0, 0), font_thickness, lineType=cv2.LINE_AA)

        return image

    def process_images(self):
        """Process all images and labels, draw bounding boxes, and save the results."""
        image_files = [file for file in os.listdir(self.image_dir) if file.endswith('.png')]
        
        for file_name in tqdm(image_files, desc="Processing Images", unit="file"):
            # Image and label file paths
            image_path = os.path.join(self.image_dir, file_name)
            label_path = os.path.join(self.label_dir, file_name.replace('.png', '.txt'))
            
            if os.path.exists(label_path):
                # Draw bounding boxes
                image_with_boxes = self.draw_bounding_boxes(image_path, label_path)
                
                # Save the result
                output_path = os.path.join(self.output_dir, file_name)
                cv2.imwrite(output_path, image_with_boxes)
            else:
                print(f'No label file found for: {file_name}')

    def plot_image_with_boxes(self, image_path):
        """Plot a single image with bounding boxes for visualization."""
        # Read image with bounding boxes
        image = cv2.imread(image_path)
        
        # Convert BGR (OpenCV format) to RGB (for matplotlib)
        image_rgb = cv2.cvtColor(image, cv2.COLOR_BGR2RGB)
        
        # Plot the image
        plt.imshow(image_rgb)
        plt.axis('off')  # Turn off axis
        plt.show()

def main():
    # Directories
    image_dir = '/home/hololens/Projects/hololens/IRVLImageLabellingSupport/datasets/test_dataset.256/images/'
    label_dir = '/home/hololens/Projects/hololens/IRVLImageLabellingSupport/datasets/test_dataset.256/labels/'
    output_dir = './output/'

    visualizer = YoloVisualizer(image_dir, label_dir, output_dir)
    
    # Process all images and save results with bounding boxes
    visualizer.process_images()

if __name__ == "__main__":
    main()
