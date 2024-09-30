#----------------------------------------------------------------------------------------------------
# Work done while being at the Intelligent Robotics and Vision Lab at the University of Texas, Dallas
# Please check the licenses of the respective works utilized here before using this script.
# 🖋️ Jishnu Jaykumar Padalunkal (2024) (Thanks to OpenAI ChatGPT for a bit of assistance! 😜)
#----------------------------------------------------------------------------------------------------

import os
import torch
from torch.utils.data import Dataset
from PIL import Image
import numpy as np

class IRVLUTDDoorHandleDataset(Dataset):
    def __init__(self, root_dir, transform=None, use_depth=False):
        """
        Args:
            root_dir (string): Directory with all the images, labels, and depth files.
            transform (callable, optional): Optional transform to be applied on an image sample.
            use_depth (bool, optional): If True, depth data will be loaded. Default is False.
        """
        self.root_dir = root_dir
        self.images_dir = os.path.join(root_dir, 'images')
        self.labels_dir = os.path.join(root_dir, 'labels')
        self.depth_dir = os.path.join(root_dir, 'depth') if use_depth else None
        self.transform = transform
        self.use_depth = use_depth
        self.image_filenames = [f for f in os.listdir(self.images_dir) if f.endswith('.png')]

        # Load class names from obj.names file
        obj_names_path = os.path.join(root_dir, 'obj.names')
        with open(obj_names_path, 'r') as f:
            self.class_names = [line.strip() for line in f.readlines()]

    def __len__(self):
        return len(self.image_filenames)

    def __getitem__(self, idx):
        # Get the image filename (without extension)
        image_filename = self.image_filenames[idx]
        base_filename = os.path.splitext(image_filename)[0]

        # Load image
        image_path = os.path.join(self.images_dir, image_filename)
        image = Image.open(image_path).convert('RGB')

        # Load depth image (only if use_depth is True)
        if self.use_depth:
            depth_path = os.path.join(self.depth_dir, f'{base_filename.replace("color", "depth")}.png')
            depth = Image.open(depth_path).convert('L')  # Assuming depth image is single-channel (grayscale)
        else:
            depth = None  # No depth data if use_depth is False

        # Load labels
        label_path = os.path.join(self.labels_dir, f'{base_filename}.txt')
        boxes = []
        class_labels = []  # This will store both class IDs and names

        with open(label_path, 'r') as f:
            for line in f:
                label_data = line.strip().split()
                class_id = int(label_data[0])
                bbox = [float(x) for x in label_data[1:]]

                # Clamp the bounding box values
                bbox = self.clamp_bbox_values(bbox)

                boxes.append([class_id] + bbox)  # class_id, cx, cy, w, h

                # Get the class name using class_id
                class_name = self.class_names[class_id]
                class_labels.append({'id': class_id, 'name': class_name})

        # Convert boxes to torch tensors
        boxes = torch.tensor(boxes, dtype=torch.float32)

        # Apply any transformations (for image, depth if applicable, and possibly boxes)
        if self.transform:
            # Apply transformations depending on whether depth is present
            if self.use_depth:
                transformed = self.transform(image=np.array(image), depth=np.array(depth), boxes=boxes)
                image = transformed['image']
                depth = transformed['depth']
                boxes = transformed['boxes']
            else:
                transformed = self.transform(image=np.array(image), boxes=boxes)
                image = transformed['image']
                boxes = transformed['boxes']

        # Return the image, depth (if applicable), labels, and class names
        return {
            'image': image,
            'depth': depth if self.use_depth else None,  # Include depth only if it was used
            'labels': boxes,
            'class_labels': class_labels  # Returns both class ID and name
        }

    def clamp_bbox_values(self, bbox):
        """Clamp bounding box values to be within [0, 1]."""
        return [max(0, min(1, value)) for value in bbox]
