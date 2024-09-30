# Code to find the number of samples in each class by reading the first column of each txt file
# in labels folder
import os
from collections import defaultdict

# Function to count the number of occurrences of each label throughout the dataset
def count_classes_in_files(directory):
    # Initialize a dictionary to store the count of each class
    class_counts = defaultdict(int)
    # Loop through all the files in the directory
    for filename in os.listdir(directory):
        if filename.endswith(".txt"):
            filepath = os.path.join(directory, filename)
            with open(filepath, 'r') as file:
                for line in file:
                    class_id = int(line.split()[0])
                    class_counts[class_id] += 1
    return class_counts

# Function to count how many images contain only door and handle labels
def count_class_door_handle(directory):
    # Initialize a dictionary to store the count of each class
    img_count = 0
    # Loop through all the files in the directory
    for filename in os.listdir(directory):
        if filename.endswith(".txt"):
            filepath = os.path.join(directory, filename)
            flag = 0 # TO keep trak of whether there was a class id of 2 or 3 in the file and accordingly
            # update the image count variable
            with open(filepath, 'r') as file:
                for line in file:
                    class_id = int(line.split()[0])
                    if class_id == 2 or class_id == 3:
                        flag = 1
                        break
                if flag == 0:
                    img_count += 1
    return img_count

# Specify the directory containing the .txt files
#directory = '/home/vinaya/Desktop/yolov8/FullReal/labels'
directory = '/home/vinaya/Desktop/yolov8/test_dataset.256/labels'

# Get the count of each class
class_counts = count_classes_in_files(directory)
# Print the counts
for class_id, count in class_counts.items():
    print(f"Class {class_id}: {count} labels")

# Get count of images which contain only door or handle label
img_count = count_class_door_handle(directory)
print(f"The number of images containing only door or handle labels: {img_count}")