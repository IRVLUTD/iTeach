import os
import shutil
import logging
import argparse
from tqdm import tqdm
from time import sleep
import iTeach.finetune as finetune

# Set up logging
logging.basicConfig(level=logging.INFO)
logger = logging.getLogger(__name__)

def parse_opt():
    parser = argparse.ArgumentParser()
    parser.add_argument('--config', type=str, default='cfg.yml', help='config file path', required=True)
    return parser.parse_args()

def trigger_logic(dh_model, files_copied):
    print(f"\n{files_copied} files copied.")
    input("Press Enter to proceed with finetuning...")
    sleep(1)
    dh_model.train_model()
    input("Finetuning complete. Press Enter to exit...")
    sleep(6)

def copy_files_and_trigger(dh_model, src_root_dir, target_dir):
    # Dictionary to store filenames as keys and their corresponding file paths as values (tuple for images, labels)
    file_dict = {}

    # Traverse through all source subdirectories (images, labels)
    src_dirs = ['images', 'labels']
    for src_subdir in src_dirs:
        full_src_dir = os.path.join(src_root_dir, src_subdir)
        for root, dirs, files in os.walk(full_src_dir):
            for file in files:
                # Extract filename without extension
                filename, ext = os.path.splitext(file)
                file_path = os.path.join(root, file)
                # Store the file path in the dictionary
                if filename not in file_dict.keys():
                    file_dict[filename] = [None, None]  # Initialize a list to hold (image, label)

                # Assign the file path to the appropriate index based on the subdirectory
                if src_subdir == 'images':
                    file_dict[filename][0] = file_path
                elif src_subdir == 'labels':
                    file_dict[filename][1] = file_path

    all_filenames = list(file_dict.keys())

    # Counter for copied files
    files_copied = 0
    
    # Initialize tqdm progress bar
    total_files = len(all_filenames) * len(src_dirs)  # Each filename corresponds to 2 files (image, label)
    with tqdm(total=total_files, desc="Copying files", unit="file") as pbar:
        # Copy files to the target directory
        for filename in all_filenames:
            for i, sub_dir in enumerate(src_dirs):
                # Get the file path from the file_dict tuple
                file_path = file_dict[filename][i]
                
                if file_path:  # Check if file path is not None
                    # Determine the target subdirectory path
                    target_sub_dir = os.path.join(target_dir, sub_dir)
                    
                    # Create the target subdirectory if it doesn't exist
                    if not os.path.exists(target_sub_dir):
                        os.makedirs(target_sub_dir)
                    
                    # Copy the file
                    shutil.copy(file_path, target_sub_dir)
                    files_copied += 1
                    pbar.update(1)  # Update the tqdm progress bar

    # Trigger the action after all files are copied
    trigger_logic(dh_model, files_copied)

if __name__ == "__main__":
    # Define your source root directory and target directory
    # source_root_dir = '/home/hololens/Projects/hololens/IRVLImageLabellingSupport/datasets/hololens.finetuning.data.100'
    source_root_dir = '/home/hololens/Projects/hololens/IRVLImageLabellingSupport/datasets/hololens.exp'
    target_directory = '/home/hololens/Projects/hololens/IRVLImageLabellingSupport/datasets/524'

    args = parse_opt()
    dh_model = finetune.DoorHandleModelFinetuner(args.config)
    logging.info(f"Resume option is {'ON' if dh_model._cfg.RESUME else 'OFF'}")

    conf_thres = dh_model._cfg.CONF_THRES if dh_model._cfg.CONF_THRES else 0.7
    iou_thres = dh_model._cfg.IOU_THRES if dh_model._cfg.IOU_THRES else 0.7   

    # Execute the function
    copy_files_and_trigger(dh_model, source_root_dir, target_directory)
