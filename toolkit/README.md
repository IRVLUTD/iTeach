# iTeach Toolkit Package 🛠️

## Overview 🔍
The `iTeach_package` is a toolkit designed for running object detection using the **DH-YOLO** model, specifically for identifying doors and handles in images. This package provides easy-to-use command-line tools for performing inference with a pre-trained DH-YOLO model.

## Model Checkpoints 📥
Pretrained model checkpoints can be downloaded from [this link](https://utdallas.box.com/v/DHYOLO-Pretrained-Checkpoints).

## Installation ⚙️
To install the package, use `pip`:

```bash
pip install iteach_toolkit
```

## Usage 🖥️

Below is an example of how to use the package for running inference on an image.

```python
import os
from PIL import Image as PILImg
from iteach_toolkit.DHYOLO import DHYOLODetector

# Set up paths
os.system("wget https://huggingface.co/spaces/IRVLUTD/DH-YOLO/resolve/main/test_imgs/jpad-irvl-test.jpg")
image_path = "./jpad-irvl-test.jpg"

model_path = "/path/to/yolov5_model.pt"

# Initialize the DHYOLODetector class
dhyolo = DHYOLODetector(model_path)

# Perform prediction on the image
orig_image, detections = dhyolo.predict(image_path, conf_thres=0.7, iou_thres=0.7, max_det=1000)

# Plot the bounding boxes on the original image
orig_image, image_with_bboxes = dhyolo.plot_bboxes(attach_watermark=True)

# Convert the image (with bounding boxes) from a NumPy array to a PIL Image for display.
pil_img_with_bboxes = PILImg.fromarray(image_with_bboxes)

# Plot the image
pil_img_with_bboxes.show()
```

## License 📜

This project is licensed under the MIT License.
