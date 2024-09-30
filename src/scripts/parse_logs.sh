#!/bin/bash

# Output CSV file
output_csv="parsed_data.csv"

# Write the header to the CSV file
echo "conf,iou,all_P,all_R,all_mAP,all_mAP50-95,door_P,door_R,door_mAP50,door_mAP50-95,handle_P,handle_R,handle_mAP50,handle_mAP50-95" > "$output_csv"

# Loop over conf and iou values in increments of 0.05
for conf in $(seq 0.05 0.05 1.00); do
    for iou in $(seq 0.05 0.05 1.00); do
        # Define the log file name
        logfile="logs/${conf}_${iou}.log"
        
        # Check if the log file exists
        if [[ -f "$logfile" ]]; then
            echo "Processing $logfile"
            
            # Extract lines containing relevant data
            all_line=$(grep ' all ' "$logfile")
            door_line=$(grep ' door ' "$logfile")
            handle_line=$(grep ' handle ' "$logfile")
            
            # Check if all three lines were found
            if [[ -z "$all_line" || -z "$door_line" || -z "$handle_line" ]]; then
                echo "Parsing error: one of the required lines is missing in $logfile"
                echo "All line: $all_line"
                echo "Door line: $door_line"
                echo "Handle line: $handle_line"
                continue
            fi
            
            # Parse the necessary columns (columns 4-7) from the lines
            all=$(echo "$all_line" | awk '{print $4","$5","$6","$7}')
            door=$(echo "$door_line" | awk '{print $4","$5","$6","$7}')
            handle=$(echo "$handle_line" | awk '{print $4","$5","$6","$7}')
            
            # Output the parsed values for debugging
            echo "Parsed all: $all"
            echo "Parsed door: $door"
            echo "Parsed handle: $handle"
            
            # Append the parsed data to the CSV file
            echo "$conf,$iou,$all,$door,$handle" >> "$output_csv"
        else
            echo "Log file $logfile not found!"
        fi
    done
done
