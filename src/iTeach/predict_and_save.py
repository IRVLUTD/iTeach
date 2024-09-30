import torch
import os
import shutil
from num_of_files import file_check
#from finetune import DoorHandleModelFinetuner

class predict_and_save:
    def __init__(self, yaml_file_path):
        self.yaml_file_path = yaml_file_path

    def predict_by_checkpoint_file(self, dhyolo_repo_path, checkpoint_path, images_dir, output_dir, prefix):
        repo_path = dhyolo_repo_path
        checkpoint_path = checkpoint_path


        model = torch.hub.load(repo_path, 'custom', path=checkpoint_path, source='local')

        #output_dir = "./inference_results"

        for filename in os.listdir(images_dir):
            image_path = os.path.join(images_dir, filename)
            results = model(image_path)
            results.save(save_dir=output_dir)

        
        self.get_consolidated_results(output_dir, prefix)

    def get_num_files_and_duplicates(self, images_dir):
        get_length_duplicates = file_check()
        get_length_duplicates.check_files(images_dir)

    # def get_checkpoint_path(self, directory):

    #     finetuner = DoorHandleModelFinetuner(self.yaml_file_path)
    #     best_model_path = finetuner.get_overall_best_model(directory, sort_wrt_mAP50=True)
            
    #     return best_model_path

    # def predict(self, dhyolo_repo_path, images_dir, dir):

    #     repo_path = dhyolo_repo_path
    #     checkpoint_path = self.get_checkpoint_path(dir)


    #     model = torch.hub.load(repo_path, 'custom', path=checkpoint_path, source='local')

    #     output_dir = "./inference_results"

    #     for filename in os.listdir(images_dir):
    #         image_path = os.path.join(images_dir, filename)
    #         results = model(image_path)
    #         results.save(save_dir=output_dir)

        
    #     self.get_consolidated_results(output_dir, 'inference_results')


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
    images_dir = "/home/hololens/Projects/hololens/IRVLImageLabellingSupport/datasets/test_dataset.256/images"

    # Path to yolov5 folder in iteach folder
    repo_path = "./yolov5"

    # Checkpoint file path
    checkpoint_path = "/home/hololens/Projects/hololens/IRVLImageLabellingSupport/iTeachModels-cfg/ft6/weights/best.pt"

    # Output directory where output images will be stored
    output_dir = "./ft6_results"

    # Prefix of the extra folders that created for each image prediction
    prefix = "ft6_results"

    # Running the predict functions
    #predict_save.predict(repo_path, images_dir, checkpoints_dir)
    #predict_save.predict_by_checkpoint_file(dhyolo_repo_path=repo_path, checkpoint_path=checkpoint_path, images_dir=images_dir, output_dir=output_dir, prefix=prefix)
    predict_save.get_num_files_and_duplicates("/home/hololens/Projects/hololens/IRVLImageLabellingSupport/iTeach/ft6_results")
