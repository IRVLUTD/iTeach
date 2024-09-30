
# iTeach Toolkit Package

## Overview
The `iTeach_package` is a toolkit designed for running object detection using the YOLOv5 model, specifically for identifying doors and handles in images. This package provides easy-to-use command-line tools for performing inference with a pre-trained YOLOv5 model.

## Model Checkpoints
Pretrained model checkpoints can be downloaded from [this link](https://utdallas.box.com/v/DHYOLO-Pretrained-Checkpoints).

## Installation
To install the package, use `pip`:

```bash
pip install iteach_toolkit
```

## Usage

Below is an example of how to use the package for running inference on an image.

```python
from PIL import Image as PILImg
from iteach_toolkit.DHYOLO import DHYOLODetector  # or from dhyolo if using the original name

# Set up paths
image_path = "./test_imgs/irvl-test.jpg"
model_path = "/path/to/yolov5_model.pt"

# Initialize the DHYOLODetector class
dhyolo = DHYOLODetector(model_path)

# Run inference
bbox_img = dhyolo.predict(image_path)

# Display the result
bbox_img = bbox_img[:, :, ::-1] # BGR to RGB
im = PILImg.fromarray(bbox_img)
im.show()
```

### Example

In the above code, replace `"path/to/yolov5_model.pt"` with the actual path to your model checkpoint and `"./test_imgs/irvl-test.jpg"` with the path to your input image.

For example:

```python
m = '/home/hololens/Projects/hololens/IRVLImageLabellingSupport/pretrained_ckpt.pt'
res = dhyolo.predict("./test_imgs/irvl-test.jpg")
im = PILImg.fromarray(res[:, :, ::-1])
im.show()
```

## License

This project is licensed under the MIT License. See the LICENSE file for more details.