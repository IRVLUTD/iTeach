# IRVL Image Labelling Support

This is a selection of files based around the testing and smooth operation of the IRVL Image Labelling project.

## Subfolders:

### [PublishImages](PublishImages)

This folder contains the images published by [publishimage.py](publishimage.py). It contains two files [3d.jpg](PublishImages/3d.jpg) and [rgb.jpg](PublishImages/rgb.jpg); only files with these names will be registered and sent by [publishimage.py](publishimage.py).

### [Dataset](Dataset)

In this folder one will find the labels, rgb, and 3d images of things labeled through the hololens. [receiveData.py](receiveData.py) publishes to this folder in real time and the images should already be properly formatted for a YOLO machine learning algorithm, this has been tested on [yolov5](https://github.com/ultralytics/yolov5).

## Files

### [execSupport.py](execSupport.py)

This is a container class to run both rebroadcastData and receiveData without needing to open another command window. It requires that rospy be installed and accepts no command line arguments.

### [rebroadcastData.py](rebroadcastData.py)

This class takes output from the head camera of a fetch robot and rebroadcasts the rgb and depth at a lower framerate. The output channels are InfrequentImage and InfrequentDepth, both of ros message type [sensor_msgs/Image](http://docs.ros.org/en/noetic/api/sensor_msgs/html/msg/Image.html). This file can be executed alone with dependencies of ros and rospy, and accepts no arguments.

### [receiveData.py](receiveData.py)

As the name suggests and as is described in the Dataset section, this file recieves data from the hololens and stores it in its appropriate directories. The incoming ros messages are LabeledImage, LabeledDepth, and ImageLabels. It will assume that all messages received at the same time belong to the same set, and assign them the same name as is requested by yolo. This file can also be executed on its own without arguments.

### [publishimage.py](publishimage.py)

This file is a stand-in for a fetch robot for when one is not available. It publishes the files explained in the PublishImages folder section under the same name as the robot would, and is therefore indistinguishable other than the lack of change in images. This can only be executed on its own and takes no arguments.

## Troubleshooting

### OMP: Error #15: Initializing libiomp5md.dll, but found libiomp5md.dll already initialized.

This error might show up in execSupport.py & receiveData.py. In a terminal in the environment that the program is running in run:

```conda install nomkl --channel conda-forge```

After this, check that all package requirements are still installed. This solution courtesy of [postylem](https://stackoverflow.com/questions/20554074/sklearn-omp-error-15-initializing-libiomp5md-dll-but-found-mk2iomp5md-dll-a).