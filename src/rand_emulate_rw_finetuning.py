import os
import shutil
import random
import iTeach.finetune as finetune
import logging
import argparse
from tqdm import tqdm
from time import sleep


# Set up logging
logging.basicConfig(level=logging.INFO)
logger = logging.getLogger(__name__)

def parse_opt():
    parser = argparse.ArgumentParser()
    parser.add_argument('--config', type=str, default='cfg.yml', help='config file path', required=True)
    return parser.parse_args()

def trigger_logic(dh_model, files_copied):
    print(f"\n{files_copied} files copied so far.")
    input("Press Enter to proceed with finetuning...")
    # print("Proceed with finetuning...")
    sleep(1)
    dh_model.train_model()
    input("Finetuning complete. Press Enter to proceed with the next batch...")
    # print("Finetuning complete. Proceeding with the next batch...")
    sleep(6)

def copy_files_with_trigger(dh_model, src_root_dir, target_dir, seed=None, trigger_interval=10):
    # Set random seed for replicable randomness
    if seed is not None:
        random.seed(seed)

    # Dictionary to store filenames as keys and their corresponding file paths as values
    file_dict = {}

    # Traverse through all source subdirectories (images, depth, labels)
    src_dirs = ['images', 'labels']
    for src_subdir in src_dirs:
        full_src_dir = os.path.join(src_root_dir, src_subdir)
        for root, dirs, files in os.walk(full_src_dir):
            for file in files:
                filename, ext = os.path.splitext(file)
                file_path = os.path.join(root, file)
                if filename not in file_dict.keys():
                    file_dict[filename] = [None, None]  # Initialize a list to hold (image, depth, label)
                
                if src_subdir == 'images':
                    file_dict[filename][0] = file_path
                if src_subdir == 'labels':
                    file_dict[filename][1] = file_path

    all_filenames = list(file_dict.keys())

    # Shuffle filenames to ensure random sampling
    random.shuffle(all_filenames)
    
    files_copied = 0
    files_in_current_batch = 0  # To count files in the current trigger interval
    
    total_files = len(all_filenames) * 2  # Each filename corresponds to 2 files (image, label)
    with tqdm(total=total_files, desc="Copying files", unit="file") as pbar:
        for filename in all_filenames:
            for i, sub_dir in enumerate(src_dirs):
                file_path = file_dict[filename][i]
                if file_path is None:
                    logger.warning(f"Missing file for {filename} in {sub_dir}. Skipping.")
                    continue
                
                target_sub_dir = os.path.join(target_dir, sub_dir)
                if not os.path.exists(target_sub_dir):
                    os.makedirs(target_sub_dir)
                
                try:
                    shutil.copy(file_path, target_sub_dir)
                except Exception as e:
                    logger.error(f"Error copying {file_path} to {target_sub_dir}: {e}")
                    continue
                
                files_copied += 1
                files_in_current_batch += 1
                pbar.update(1)  # Update the tqdm progress bar

            if files_in_current_batch >= trigger_interval:
                trigger_logic(dh_model, files_copied//2)
                files_in_current_batch = 0  # Reset the batch counter

    if files_in_current_batch != 0:
        trigger_logic(dh_model, files_copied)


if __name__ == "__main__":
    # Define your source root directory and target directory
    source_root_dir = '/home/hololens/Projects/hololens/IRVLImageLabellingSupport/datasets/hololens.finetuning.data.100'
    target_directory = '/home/hololens/Projects/hololens/IRVLImageLabellingSupport/datasets/524'

    # Seed for replicable randomness
    random_seed = 1

    args = parse_opt()
    dh_model = finetune.DoorHandleModelFinetuner(args.config)
    logging.info(f"Resume option is {'ON' if dh_model._cfg.RESUME else 'OFF'}")

    conf_thres = dh_model._cfg.CONF_THRES if dh_model._cfg.CONF_THRES else 0.7
    iou_thres = dh_model._cfg.IOU_THRES if dh_model._cfg.IOU_THRES else 0.7   

    # Execute the function
    copy_files_with_trigger(dh_model, source_root_dir, target_directory, seed=random_seed, trigger_interval=20)
