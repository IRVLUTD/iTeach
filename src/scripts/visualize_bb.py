import os
import matplotlib.pyplot as plt
from PIL import Image, ImageOps
import matplotlib.patches as patches

# Define directories
# images_dir = '/Users/vinayabomnale/Desktop/CV Lab/Data_aug/Dummy_Data/augmented_images'
# labels_dir = '/Users/vinayabomnale/Desktop/CV Lab/Data_aug/Dummy_Data/augmented_labels'

images_dir = '/home/vinaya/Desktop/yolov8/test_dataset.256/images'
labels_dir = '/home/vinaya/Desktop/yolov8/test_dataset.256/labels'


# Function to parse label file
def parse_label_file(label_path):
    with open(label_path, 'r') as file:
        lines = file.readlines()
    bboxes = []
    for line in lines:
        parts = line.strip().split()
        cls = int(parts[0])
        cx = float(parts[1])
        cy = float(parts[2])
        w = float(parts[3])
        h = float(parts[4])
        bboxes.append((cls, cx, cy, w, h))
    return bboxes

# Function to denormalize and flip bbox coordinates horizontally
def denormalize_and_flip_bbox(bbox, img_width, img_height):
    cls, cx, cy, w, h = bbox
    # Flip horizontally: new cx = 1 - old cx
    #cx = 1 - cx
    x = int((cx - w / 2) * img_width)
    y = int((cy - h / 2) * img_height)
    width = int(w * img_width)
    height = int(h * img_height)
    return cls, x, y, width, height

# Loop through all images
for image_file in os.listdir(images_dir):
    if image_file.endswith(('.png', '.jpg', '.jpeg')):
        image_path = os.path.join(images_dir, image_file)
        label_path = os.path.join(labels_dir, os.path.splitext(image_file)[0] + '.txt')

        # Load image
        image = Image.open(image_path)
        img_width, img_height = image.size

        # Parse labels
        bboxes = parse_label_file(label_path)

        # Plot image and bboxes
        fig, ax = plt.subplots(1)
        ax.imshow(image)

        # Set the title as the file name
        ax.set_title(image_file)

        for bbox in bboxes:
            cls, x, y, width, height = denormalize_and_flip_bbox(bbox, img_width, img_height)
            rect = patches.Rectangle((x, y), width, height, linewidth=1, edgecolor='r', facecolor='none')
            ax.add_patch(rect)
            # if cls == 0:
            #     plt.text(x, y, 'door', color='white', fontsize=8, bbox=dict(facecolor='red'), alpha=0.5)
            # elif cls == 1:
            #     plt.text(x, y, 'handle', color='black', fontsize=8, bbox=dict(facecolor='yellow'), alpha=0.5)
            # else:
            plt.text(x, y, f'Class: {cls}', color='white', fontsize=8, bbox=dict(facecolor='red', alpha=0.5))

        plt.show()
        plt.close(fig)  # Close the figure to free up memory