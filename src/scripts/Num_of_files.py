# Code to check the number of files in a given folder

from pathlib import Path

# Checking if the agmented images and augmented folder has 436 x 12 images and labels has all the 436 files
image_directory = Path('/home/vinaya/Desktop/yolov8/test_dataset.256/images')
label_directory = Path('/home/vinaya/Desktop/yolov8/test_dataset.256/labels')

img_files_list = list(image_directory.glob('*'))
lb_files_list = list(label_directory.glob('*'))

print(f'Number of files in images folder: {len(img_files_list)}')
print(f'Number of files in labels folder: {len(lb_files_list)}')
