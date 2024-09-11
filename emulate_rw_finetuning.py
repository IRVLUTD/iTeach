import os
import shutil
import random

def trigger_logic(files_copied):
    print(f"\n{files_copied} files copied so far.")
    input("Press Enter to proceed with the next batch...")

def copy_files_with_trigger(src_dirs, target_dir, seed=None, trigger_interval=5):
    # Set random seed for replicable randomness
    if seed is not None:
        random.seed(seed)

    # Dictionary to store filenames and their paths
    file_dict = {}

    # Traverse through all source directories
    for src_dir in src_dirs:
        for root, dirs, files in os.walk(src_dir):
            for file in files:
                # Extract filename without extension
                filename, ext = os.path.splitext(file)
                file_path = os.path.join(root, file)
                
                if filename not in file_dict:
                    file_dict[filename] = []
                file_dict[filename].append(file_path)

    # Collect all filenames
    all_filenames = list(file_dict.keys())

    # Shuffle filenames to ensure random sampling
    random.shuffle(all_filenames)
    
    # Counter for copied files
    files_copied = 0
    
    # Copy files to the target directory
    for filename in all_filenames:
        for file_path in file_dict[filename]:
            # Determine the subdirectory structure
            sub_dir = os.path.relpath(os.path.dirname(file_path), src_dirs[0])
            target_sub_dir = os.path.join(target_dir, sub_dir)
            
            # Create target subdirectory if it doesn't exist
            if not os.path.exists(target_sub_dir):
                os.makedirs(target_sub_dir)
            
            # Copy file
            shutil.copy(file_path, target_sub_dir)
            files_copied += 1

            # Trigger logic every time 5 files are copied
            if files_copied % trigger_interval == 0:
                trigger_logic(files_copied)

    # After all files are copied, you can also call the logic one final time
    if files_copied % trigger_interval != 0:
        trigger_logic(files_copied)

# Define your source directories and target directory
source_dirs = ['images', 'depth', 'labels']
target_directory = 'target_dir'

# Seed for replicable randomness
random_seed = 42

# Execute the function
copy_files_with_trigger(source_dirs, target_directory, seed=random_seed)
