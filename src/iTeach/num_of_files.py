import os
from collections import Counter

class file_check:

    def check_files(self, images_dir):

        # Getting a list of all files in the folder
        files = os.listdir(images_dir)

        # Defining the image extensions
        image_extensions = ('.jpg', '.png', '.jpeg')

        # Getting all the image files
        image_files = [file for file in files if file.lower().endswith(image_extensions)]

        # Getting the number of images in the folder
        num_of_images = len(image_files)
        print(f"Number of images: {num_of_images}")

        file_counts_dict = Counter(image_files)
        duplicates = [file for file, count in file_counts_dict.items() if count > 1]

        if duplicates:
            print("File has duplicates: ")
            for duplicate in duplicates:
                print(f" {duplicate}")

        else:
            print("No duplicates found")

