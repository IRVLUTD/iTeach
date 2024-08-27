#----------------------------------------------------------------------------------------------------
# Work done while being at the Intelligent Robotics and Vision Lab at the University of Texas, Dallas
# Please check the licenses of the respective works utilized here before using this script.
# 🖋️ using OpenAI ChatGPT (2024).
#----------------------------------------------------------------------------------------------------


import sqlite3
import csv
import json
from typing import Dict, Optional


class SQLiteManager:
    def __init__(self, db_path: str):
        self.db_path = db_path
        self.conn = sqlite3.connect(self.db_path, check_same_thread=False)
        self.cursor = self.conn.cursor()
        self._create_table()

    def _create_table(self):
        """Create the results table if it doesn't exist."""
        self.cursor.execute('''
        CREATE TABLE IF NOT EXISTS results (
            model_path TEXT PRIMARY KEY,
            P REAL,
            R REAL,
            mAP50 REAL,
            mAP50_95 REAL,
            val_box_loss REAL,
            val_obj_loss REAL,
            val_cls_loss REAL,
            finetune_iter_num INTEGER
        )
        ''')
        self.conn.commit()

    def insert_data(self, data: Dict):
        """Insert a new record into the results table."""
        self.cursor.execute('''
        INSERT OR REPLACE INTO results 
        (model_path, P, R, mAP50, mAP50_95, val_box_loss, val_obj_loss, val_cls_loss, finetune_iter_num)
        VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?)
        ''', (
            data['model_path'],
            data['P'],
            data['R'],
            data['mAP50'],
            data['mAP50_95'],
            data['val_box_loss'],
            data['val_obj_loss'],
            data['val_cls_loss'],
            data['finetune_iter_num']
        ))
        self.conn.commit()

    def get_best_model_path(self) -> Optional[str]:
        """Retrieve the model path with the highest mAP50."""
        self.cursor.execute('''
        SELECT model_path FROM results 
        ORDER BY mAP50 DESC 
        LIMIT 1
        ''')
        result = self.cursor.fetchone()
        return result[0] if result else None

    def get_best_mAP50_value(self):
        """Retrieve the highest mAP50 value along with the corresponding model path and finetune_iter_num."""
        self.cursor.execute('''
        SELECT model_path, mAP50, finetune_iter_num FROM results 
        ORDER BY mAP50 DESC 
        LIMIT 1
        ''')
        result = self.cursor.fetchone()
        if result:
            return {
                'model_path': result[0],
                'mAP50': result[1],
                'finetune_iter_num': result[2]
            }
        return None

    def get_best_and_second_best_model_paths(self):
        """Retrieve the best and second-best model paths based on mAP50."""
        self.cursor.execute('''
        SELECT model_path, mAP50 FROM results 
        ORDER BY mAP50 DESC 
        LIMIT 2
        ''')
        results = self.cursor.fetchall()
        return results

    def get_all_results(self):
        """Retrieve and pretty-print all records from the results table."""
        self.cursor.execute('SELECT * FROM results')
        rows = self.cursor.fetchall()
        column_names = [description[0] for description in self.cursor.description]

        results = [dict(zip(column_names, row)) for row in rows]
        return results
    
    def export_to_csv(self, csv_file_path: str):
        """Export the results table to a CSV file."""
        self.cursor.execute('SELECT * FROM results')
        rows = self.cursor.fetchall()
        column_names = [description[0] for description in self.cursor.description]

        with open(csv_file_path, 'w', newline='') as csv_file:
            writer = csv.writer(csv_file)
            writer.writerow(column_names)  # Write header
            writer.writerows(rows)  # Write data rows

    def export_to_json(self, json_file_path: str):
        """Export the results table to a JSON file."""
        self.cursor.execute('SELECT * FROM results')
        rows = self.cursor.fetchall()
        column_names = [description[0] for description in self.cursor.description]

        data_list = [dict(zip(column_names, row)) for row in rows]

        with open(json_file_path, 'w') as json_file:
            json.dump(data_list, json_file, indent=4)

    def close(self):
        """Close the database connection."""
        self.conn.close()

# Example usage:
if __name__ == '__main__':
    # Create an instance of the SQLiteManager
    db_manager = SQLiteManager('dummy_results.db')

    # Insert data into the database
    db_manager.insert_data({
        "model_path": "/path/to/model1",
        "P": 0.85,
        "R": 0.80,
        "mAP50": 0.75,
        "mAP50_95": 0.60,
        "val_box_loss": 0.02,
        "val_obj_loss": 0.01,
        "val_cls_loss": 0.03,
        "finetune_iter_num": 100
    })

    db_manager.insert_data({
        "model_path": "/path/to/model2",
        "P": 0.90,
        "R": 0.85,
        "mAP50": 0.78,
        "mAP50_95": 0.65,
        "val_box_loss": 0.01,
        "val_obj_loss": 0.02,
        "val_cls_loss": 0.02,
        "finetune_iter_num": 200
    })

    # Get the best mAP50 value along with the model path and finetune_iter_num
    best_mAP50_info = db_manager.get_best_mAP50_value()
    print("Best mAP50 value, model path, and finetune iteration number:", best_mAP50_info)

    # Close the database connection
    db_manager.close()
