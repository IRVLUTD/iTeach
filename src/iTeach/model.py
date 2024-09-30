from ultralytics import YOLO
import os, glob
import yaml
import json
import os
import time

class Finetune():

    flag = 0
    
    #Loading the data.yaml file to get parameters
    def load_yaml(self, yaml_file):
        with open(yaml_file, 'r') as file:
            return yaml.safe_load(file)



    def get_latest_best_model(self, directory):

        # Getting the last created train folder
        latest_train_path = max(glob.glob(os.path.join(directory, '*/')), key=os.path.getmtime)


        # Constructing path for the latest best.pt file
        best_file_path = os.path.join(latest_train_path, 'weights', 'best.pt')

        print(f"Best File Path: {best_file_path}")

        if best_file_path:
            print(best_file_path)
            return best_file_path
        
        else:
            raise FileNotFoundError("Best file could not be found")

    def train_model(self):

        data_yaml_rel_path = './test.yaml'
        data_yaml_abs_path = os.path.abspath(data_yaml_rel_path)

        # Loading the yaml file
        parameters = self.load_yaml(data_yaml_rel_path)

        args = {
            'data': data_yaml_abs_path,
            'epochs': parameters['epochs'] if parameters['epochs'] else 20,
            'batch': parameters['batch'] if parameters['batch'] else 16,
            'box': parameters['box'] if parameters['box'] else 7.5,
            'cls': parameters['cls'] if parameters['cls'] else 0.5,
            'dropout': parameters['dropout'] if parameters['dropout'] else 0.0,
        }

        directory = parameters['train_directory']


        # Getting the best.pt file path
        best_file_path = self.get_latest_best_model(directory)

        # if best_file_path == None:
        #     print("Best file could not be found")
        #     return

        # Loading the best.pt file
        model = YOLO(best_file_path)


        # Train the model
        results = model.train(**args)

        # Waiting for 5 seconds till model is fully trained
        # print("Training complete. Waiting for 2 seconds before saving results...")
        # time.sleep(2)

        # Getting path of the latest train folder created in runs/detect
        latest_train_dir_path = max(glob.glob(os.path.join(directory, '*/')), key=os.path.getmtime)

        if results: 
            results_data = {
                "ap_class_index": results.ap_class_index.tolist(),
                "precision": results.box.p.tolist(),
                "recall": results.box.r.tolist(),
                "f1": results.box.f1.tolist(),
                "map50": float(results.box.map50),
                "map75": float(results.box.map75),
                "map": float(results.box.map)
            }
            #print(f'AP Class Index: {type(results.ap_class_index)} \n Box Precision: {type(results.box.p)} \n Box Recall: {type(results.box.r)} \n F1: {type(results.box.f1)} \n MAP50: {type(results.box.map50)} \n MAP75: {type(results.box.map75)} MAP: {type(results.box.map)}')
            print(f'Box Precision: {results.box.p} \n Box Recall: {results.box.r} \n F1: {results.box.f1} \n MAP50: {results.box.map50} \n MAP75: {results.box.map75} MAP: {results.box.map} Mean Result: {results.box.mean_results}')
            results_saved = self.store_results(results_data, latest_train_dir_path)
        else:
            print("Could not retrieve results from training!")
            return

        if results_saved:
            print(f"Results saved to {latest_train_dir_path} in results.json file!")    

        else:
            print("Results could not be saved to Json file!")
            return


    def store_results(self, results, train_path):
        # Creating a Json file to save the results
        json = SaveResults()
        json_file_path = json.create_json_file(results, train_path)

        if json_file_path:
            #json.read_json_file(json_file_path)
            return True
        
        else:
            print("Json file could not be created!")
            return False
    

        #print(f'AP_Class_Index: {results.ap_class_index} \n Box: {results.box} \n Class Result: {results.class_result} \n Confusion Matrix: {results.confusion_matrix} \n Maps: {results.maps} \n Mean Results" {results.mean_results}')
        #print(f'Box Precision: {results.box.p} \n Box Recall: {results.box.r} \n F1: {results.box.f1} \n MAP50: {results.box.map50} \n MAP75: {results.box.map75} MAP: {results.box.map} Mean Result: {results.box.mean_results}')

class SaveResults():
    def create_json_file(self, results, train_path):
        json_file_path = os.path.join(train_path, 'results.json')

        # Save results to the json file
        with open(json_file_path, 'w') as json_file:
            json.dump(results, json_file, indent=4)

        return json_file_path
    
    def read_json_file(self, json_file_path):
        # Read and print the json file
        with open(json_file_path, 'r') as json_file:
            loaded_file = json.load(json_file)
            print(json.dumps(loaded_file, indent=4))

if __name__ == "__main__":

    model = Finetune()
    model.train_model()

    


