# IRVLUTD Door Handle Dataset Loader 📦

This Python package provides a PyTorch dataset loader for the **IRVLUTD Door Handle dataset**, which includes:

- 🖼️ Images
- 🌐 Depth maps
- 🏷️ YOLO-style labels

This package simplifies loading and using the dataset in machine learning workflows. It is a part of the [iTeach](https://irvlutd.github.io/iTeach) project.

<img src='https://irvlutd.github.io/iTeach/assets/images/iteach/iTeach-IRVLUTD-DoorHandle-Dataset-Banner.webp'>

<summary><center><h1>Area Covered 🌍</h1></center></summary>
<img src='https://raw.githubusercontent.com/IRVLUTD/IRVLUTDDoorHandleDataset/refs/heads/main/imgs/area-covered-for-irvlutd-doorhandle-dataset-creation.png'>

## Installation ⚙️
```shell
pip install IRVLUTDDoorHandleDataset

```

## Usage 📖

Once installed, you can use the `IRVLUTDDoorHandleDataset` class to load dataset in a PyTorch-compatible format:

```python
from IRVLUTDDoorHandleDataset import IRVLUTDDoorHandleDataset

# Path to the dataset root directory
root_dir = '/path/to/the/data'

# Initialize the dataset
dataset = IRVLUTDDoorHandleDataset(root_dir=root_dir) # by default, only images and label dir are read
dataset = IRVLUTDDoorHandleDataset(root_dir=root_dir, use_depth=True) # to use depth dir as well

# Access the first sample in the dataset
sample = dataset[0]

# Access different components of the sample
image = sample['image']
depth = sample['depth']
labels = sample['labels']  # Bounding boxes in YOLO format (cx, cy, w, h)
class_labels = sample['class_labels']  # Class ID and name for each object

print(f"Image Shape: {image.size}")
print(f"Depth Shape: {depth.size}")
print(f"Labels: {labels}")
print(f"Class Labels: {class_labels}")
```


## Dataset Structure 📂
Download dataset from [here](https://utdallas.box.com/v/IRVLUTD-DoorHandle-Dataset).

The dataset should follow this structure:
```
data/
├── images/ (filename.png)
├── labels/ (filename.txt)
├── depth/ (filename_with_depth.png)
└── obj.names  # Contains class names (e.g., Door, Handle)
```

Each sample in the dataset shares the same filename (excluding the extension) in both the images and labels directories. The iTeach system assumes that all messages received simultaneously belong to the same set and will assign them the same name as required by YOLO. Due to this assumption, please be aware that there may be inconsistencies when using depth data alongside the color samples.

- **Images**: RGB images (e.g., `image.png`)
- **Depth**: Depth images (e.g., `depth.png`)
- **Labels**: YOLO format labels (e.g., `label.txt`) (Dataloader normalized the coordinates in [0-1] range)
- **obj.names**: Class names (e.g., `Door`, `Handle`)

Note: This dataloader will work with any detection dataset following the above mentioned file structure and having normalized YOLO bbox labels stored in txt files.

## License 📜

This project is licensed under the MIT License.
