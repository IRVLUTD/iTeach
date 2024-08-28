#----------------------------------------------------------------------------------------------------
# Work done while being at the Intelligent Robotics and Vision Lab at the University of Texas, Dallas
# Please check the licenses of the respective works utilized here before using this script.
# 🖋️ Vinaya Bomnale, Jishnu Jaykumar Padalunkal (2024).
#----------------------------------------------------------------------------------------------------


"""
Test this script:
rm -rf fused; rm *.db; rm -rf iTeachModels/; ln -s datasets/train.524 fused  
python iTeach/finetune.py configs/test.yaml
"""

import os
import sys
import glob
import yaml
import json
import time
import torch
import logging
from ultralytics import YOLO
from easydict import EasyDict as edict
from iTeach.train import run as train_run
from sqlite_manager import SQLiteManager

# Import the classes
from test_sampler import (FilenameSampler, SymlinkCreator)


#  Set up logging
logging.basicConfig(level=logging.INFO)
logger = logging.getLogger(__name__)


class DoorHandleModelFinetuner:
    def __init__(self, cfg_path):
        """
        Initialize the DoorHandleModelFinetuner class.

        Args:
            cfg_path (str): config yaml absolute file path.
        """
        logger.info("Initializing DoorHandleModelFinetuner")
        self.model_name = "iTeachModels"
        self.cfg_path = cfg_path
        self.finetune_iter_num = 0
        self.cfg = self.load_yaml(self.cfg_path)
        self.model_ckpt = self.cfg.PRETRAINED_CKPT_PATH
        self.db_manager = SQLiteManager('finetune_val_results.db')

    def set_model_ckpt(self, model_ckpt):
        self.model_ckpt = model_ckpt

    def get_model_ckpt(self):
        return self.model_ckpt

    def select_model_ckpt(self):
        if (self.cfg.RESUME and os.path.exists(self.model_name)) or self.finetune_iter_num > 0:
            best_ckpt_from_ft_iters = self.get_latest_best_model(self.model_name, sort_wrt_mAP50=True)
            self.set_model_ckpt(best_ckpt_from_ft_iters)
        else:
            logger.info(f"Getting pretrained ckpt from: {self.cfg.PRETRAINED_CKPT_PATH}")
            self.set_model_ckpt(self.cfg.PRETRAINED_CKPT_PATH)

    def get_finetune_args(self):
        args = {
            'data': self.cfg_path,
            'epochs': self.cfg.EPOCHS if self.cfg.EPOCHS else 20,
            'batch': self.cfg.BATCH if self.cfg.BATCH else 16,
            'box': self.cfg.BOX_LOSS_WEIGHT if self.cfg.BOX_LOSS_WEIGHT else 7.5,
            'cls': self.cfg.CLS_LOSS_WEIGHT if self.cfg.CLS_LOSS_WEIGHT else 0.5,
            'dropout': self.cfg.DROPOUT if self.cfg.DROPOUT else 0.0,
            'imgsz': 640,
            'weights': self.get_model_ckpt(),
            'nosave': False,
            'noplots': False,
            'noval': False,
            'project': self.model_name,
            'name': 'ft',
            'exist_ok': False,
        }
        return args

    def load_yaml(self, yaml_path):
        """
        Load the cfg.yaml file to get parameters.

        Args:
            yaml_path (str): Absolute path to the yaml file.

        Returns:
            dict: A dictionary containing the parameters from the yaml file.
        """
        logger.info(f"Loading YAML file: {yaml_path}")
        try:
            with open(yaml_path, 'r') as file:
                params = yaml.safe_load(file)
                params = edict(params)
                logger.info("Data YAML file loaded successfully")
                return params
        except FileNotFoundError as fe:
            logger.error(f"YAML file not found: {yaml_path}")
            raise fe
        except yaml.YAMLError as e:
            logger.error(f"Error parsing YAML file: {e}")
            raise e

    def get_latest_best_model(self, directory, sort_wrt_mAP50=False):
        if sort_wrt_mAP50:
            all_results = self.db_manager.get_all_results()
            logger.info("All results: %s", all_results)
            best_model_path = self.db_manager.get_best_model_path()
            logger.info("Best model path: %s", best_model_path)
        else:
            latest_train_path = max(glob.glob(os.path.join(directory, '*/')), key=os.path.getmtime)
            best_model_path = os.path.join(latest_train_path, 'weights', 'best.pt')
            logger.info(f"Best model Path: {best_model_path}")

        if best_model_path:
            logger.info(f"Best model path: {best_model_path}")
            return best_model_path
        else:
            raise FileNotFoundError("Best file could not be found")

    def get_finetune_iter_num(self):
        return self.finetune_iter_num

    def increment_finetune_iter_num(self):
        self.finetune_iter_num += 1

    def update_filenames(self, source_dirs, n):
        """
        Update the list of sampled filenames from the source directories.

        Args:
            source_dirs (list): List of source directories.
            n (int): Number of files to sample from the first source directory.
        """
        sampler = FilenameSampler(source_dirs[0], n)
        sampled_filenames = sampler.get_sampled_filenames()

        # Include filenames from the second source directory
        images_dir = os.path.join(source_dirs[1], 'images')
        filenames = [os.path.splitext(f)[0] for f in os.listdir(images_dir) if os.path.isfile(os.path.join(images_dir, f))]
        sampled_filenames.extend(filenames)

        # Remove duplicates
        self.sampled_filenames = list(set(sampled_filenames))
        logger.info(f"Updated sampled filenames: {self.sampled_filenames}")

    def train_model(self):
        """
        Train the model using the specified parameters.

        Returns:
            dict: Training results in JSON format or an error response.
        """
        logger.info("Training model")
        self.select_model_ckpt()
        args = self.get_finetune_args()
        opt, results = train_run(**args)

        p = os.path.expanduser(os.path.join(opt.project, '*/*/best.pt'))
        latest_train_dir_path = max(glob.glob(p), key=os.path.getmtime)

        self.db_manager.insert_data({
            "finetune_iter_num": self.get_finetune_iter_num(),
            "model_path": latest_train_dir_path,
            "P": results[0],
            "R": results[1],
            "mAP50": results[2],
            "mAP50_95": results[3],
            "val_box_loss": results[4],
            "val_obj_loss": results[5],
            "val_cls_loss": results[6],
        })

        curr_mAP50, overall_best_mAP50_info = results[2], self.db_manager.get_best_mAP50_value()
        self.increment_finetune_iter_num()

        return curr_mAP50, overall_best_mAP50_info

if __name__ == "__main__":
    model = DoorHandleModelFinetuner(sys.argv[1])

    # Parameters
    source_dirs = [
        'test_datasets/hololens.finetuning.data.100',
        'test_datasets/train.524/fetch.on.utd.campus.train.dataset.524'
    ]
    destination_dir = 'fused'
    n = 10  # Number of files to sample

    # Create symlinks
    creator = SymlinkCreator(source_dirs, destination_dir, [])

    # Training loop with dynamic filename updates
    while True:
        model.update_filenames(source_dirs, n)
        if not model.sampled_filenames:
            logger.info("No filenames to process. Exiting.")
            break
        
        creator.filenames = model.sampled_filenames
        creator.create_fused_dataset()
        model.train_model()
