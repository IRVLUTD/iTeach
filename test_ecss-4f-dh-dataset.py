import os
import torch
from torch.utils.data import Dataset, DataLoader
from PIL import Image as PILImg
import numpy as np
import matplotlib.pyplot as plt
from absl import app, logging
from robokit.utils import annotate, overlay_masks
from robokit.perception import GroundingDINOObjectPredictor, SegmentAnythingPredictor
from pycocotools.coco import COCO
from pycocotools.cocoeval import COCOeval
import torchvision.transforms as transforms

class CustomDataset(Dataset):
    def __init__(self, images_dir, labels_dir, transform=None):
        self.images_dir = images_dir
        self.labels_dir = labels_dir
        self.transform = transform
        self.image_files = [f for f in os.listdir(images_dir) if f.endswith('.png')]

    def __len__(self):
        return len(self.image_files)

    def __getitem__(self, idx):
        image_file = self.image_files[idx]
        image_path = os.path.join(self.images_dir, image_file)
        label_file = image_file.replace('.png', '.txt')
        label_path = os.path.join(self.labels_dir, label_file)

        image = PILImg.open(image_path).convert('RGB')
        
        with open(label_path, 'r') as f:
            labels = f.readlines()

        bboxes = []
        for label in labels:
            class_id, cx, cy, w, h = map(float, label.split())
            bboxes.append([class_id, cx, cy, w, h])

        bboxes = np.array(bboxes)

        if self.transform:
            image = self.transform(image)

        return image, bboxes

def custom_collate_fn(batch):
    images, bboxes = zip(*batch)
    images = torch.stack([transforms.ToTensor()(img) for img in images], dim=0)
    bboxes = [torch.tensor(bb) for bb in bboxes]
    return images, bboxes

def plot_image_with_bboxes(image, bboxes, title="Image with Bounding Boxes"):
    fig, ax = plt.subplots(1)
    ax.imshow(image.permute(1, 2, 0))  # Convert CHW to HWC
    
    for bbox in bboxes:
        class_id, cx, cy, w, h = bbox
        x = cx - w / 2
        y = cy - h / 2
        rect = plt.Rectangle((x, y), w, h, edgecolor='r', facecolor='none')
        ax.add_patch(rect)
        ax.text(x, y, str(int(class_id)), color='white', fontsize=12, backgroundcolor='red')
    
    plt.title(title)
    plt.show()

def calculate_metrics(coco_gt, coco_dt):
    coco_eval = COCOeval(coco_gt, coco_dt, 'bbox')
    coco_eval.evaluate()
    coco_eval.accumulate()
    coco_eval.summarize()
    precision = coco_eval.stats[0]
    recall = coco_eval.stats[1]
    mAP50 = coco_eval.stats[2]
    mAP = coco_eval.stats[0]
    mAP50_95 = coco_eval.stats[1]
    return precision, recall, mAP50, mAP50_95, mAP

# Example usage
if __name__ == "__main__":
    DATASET_ROOT_DIR = './Dataset/test_dataset.256'
    images_dir = f'{DATASET_ROOT_DIR}/images'
    labels_dir = f'{DATASET_ROOT_DIR}/labels'

    dataset = CustomDataset(images_dir, labels_dir)
    dataloader = DataLoader(dataset, batch_size=4, shuffle=True, num_workers=4)

    for images, bboxes in dataloader:
        for img, bbox in zip(images, bboxes):
            img_np = np.array(img) # Convert PIL Image to numpy array for plotting
            plot_image_with_bboxes(img_np, bbox)
