#----------------------------------------------------------------------------------------------------
# Work done while being at the Intelligent Robotics and Vision Lab at the University of Texas, Dallas
# Please check the licenses of the respective works utilized here before using this script.
# 🖋️ Assisted by OpenAI ChatGPT (2024).
#----------------------------------------------------------------------------------------------------


"""
Filename Sampling and Symbolic Link Creation Script.

This script performs two main functions:
1. Sampling filenames from a specified subdirectory ('images' by default) in a given source directory.
2. Creating symbolic links for these sampled filenames in a new directory structure.

Classes:
- FilenameSampler: Handles the sampling of filenames from a given directory.
- SymlinkCreator: Manages the creation of symbolic links for the sampled filenames across multiple source directories.

Usage:
1. Initialize the `FilenameSampler` with a source directory and the number of filenames to sample.
2. Use the sampled filenames to initialize the `SymlinkCreator` with a list of source directories and a destination directory.
3. Call the `create_fused_dataset` method of `SymlinkCreator` to create symbolic links in the destination directory.
"""

import os
import random


class FilenameSampler:
    def __init__(self, source_dir, n):
        self.source_dir = source_dir
        self.n = n
        self.subdirs = ['images']  # Assuming you only want to sample from the 'images' subdirectory

    def get_sampled_filenames(self):
        """Sample filenames from the images directory."""
        images_dir = os.path.join(self.source_dir, 'images')
        filenames = [os.path.splitext(f)[0] for f in os.listdir(images_dir) if os.path.isfile(os.path.join(images_dir, f))]
        return random.sample(filenames, self.n)


class SymlinkCreator:
    def __init__(self, source_dirs, destination_dir, filenames):
        self.source_dirs = source_dirs
        self.destination_dir = destination_dir
        self.filenames = filenames
        self.subdirs = {
            'images': 'png',
            'depth': 'png',
            'labels': 'txt',
        }

    def create_symlink(self, src_file, dst_file):
        """Create a symbolic link for the file if it does not already exist."""
        if not os.path.exists(dst_file):
            try:
                os.symlink(src_file, dst_file)
            except:
                pass
        else:
            print(f"Symlink already exists: {dst_file}")

    def process_source_directory(self, source_dir):
        """Process files from the source directory and create symlinks in the destination directory."""
        while self.filenames:
            filename = self.filenames.pop()
            for subdir, ext in self.subdirs.items():
                src_file = os.path.join(source_dir, subdir, f"{filename}.{ext}")
                dst_file = os.path.join(self.destination_dir, subdir, f"{filename}.{ext}")

                if os.path.exists(src_file):
                    self.create_symlink(src_file, dst_file)
                else:
                    print(f"Warning: {src_file} does not exist and will be skipped.")

    def create_fused_dataset(self):
        # Ensure the destination subdirectories exist
        for subdir in self.subdirs.keys():
            os.makedirs(os.path.join(self.destination_dir, subdir), exist_ok=True)

        # Process each source directory until all symlinks are created
        while self.filenames:
            for source_dir in self.source_dirs:
                self.process_source_directory(source_dir)
                if not self.filenames:
                    break
