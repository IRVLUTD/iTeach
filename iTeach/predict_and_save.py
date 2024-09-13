import torch
import os
import shutil
from finetune import DoorHandleModelFinetuner

class predict_and_save:
    def __init__(self, yaml_file_path):
        self.yaml_file_path = yaml_file_path

    def get_checkpoint_path(self, directory):

        finetuner = DoorHandleModelFinetuner(self.yaml_file_path)
        best_model_path = finetuner.get_overall_best_model(directory, sort_wrt_mAP50=True)
            
        return best_model_path

    def predict(self, dhyolo_repo_path, images_dir, dir):

        repo_path = dhyolo_repo_path
        checkpoint_path = self.get_checkpoint_path(dir)


        model = torch.hub.load(repo_path, 'custom', path=checkpoint_path, source='local')

        output_dir = "./inference_results"

        for filename in os.listdir(images_dir):
            image_path = os.path.join(images_dir, filename)
            results = model(image_path)
            results.save(save_dir=output_dir)

        
        self.get_consolidated_results(output_dir, 'inference_results')


    def get_consolidated_results(self, main_folder, temp_folder_prefix):
        # Creating inference_results folder if it doesn't already exist
        if not os.path.exists(main_folder):
            os.makedirs(main_folder)

        # Getting a list of all directories that start with the temp_folders_prefix
        temp_folders = [f for f in os.listdir() if os.path.isdir(f) and f.startswith(temp_folder_prefix) and f != os.path.basename(main_folder)]

        for temp_folder in temp_folders:
            # Iterating through all files in the temporary folder
            for filename in os.listdir(temp_folder):
                temp_file_path = os.path.join(temp_folder, filename)

                if os.path.isfile(temp_file_path):
                    # Copying the file to the main folder
                    shutil.copy(temp_file_path, main_folder)
            
            # Removing the temporary folder after copying its contents
            shutil.rmtree(temp_folder)

        print(f"Results are consolidated into {main_folder}.")



if __name__ == "__main__":

    # Defining an object of predict and save class. Passing the yaml file as parameter during initialization
    predict_save = predict_and_save("../configs/test.yaml")

    # Dummy Directory so that the get_checkpoint_path functions runs
    checkpoints_dir = "./iTeach"

    # Directory where all images to be used for prediction are stored
    images_dir = "./dummy_data2"

    # Path to yolov5 folder in iteach folder
    repo_path = "./yolov5"

    # Running the predict functions
    predict_save.predict(repo_path, images_dir, checkpoints_dir)
