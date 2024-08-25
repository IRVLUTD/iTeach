#!/bin/bash

out_dir='logs'
mkdir -p $out_dir

# Loop over conf and iou values in increments of 0.05
for conf in $(seq 0.05 0.05 1.00); do
    for iou in $(seq 0.05 0.05 1.00); do
        # Define the log file name
        logfile="${out_dir}/${conf}_${iou}.log"
        
        # Run your command and save the output to the log file
        echo "Running command with conf=$conf and iou=$iou, outputting to $logfile"
        python val.py --data data/doordetect.yaml --weights pretrained_best.pt --conf-thres $conf --iou-thres $iou > "$logfile" 2>&1
    done
done
