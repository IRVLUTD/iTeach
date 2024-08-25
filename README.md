# Setup
#### iTeach Labelling app
- Install UnityHub and select a Unity version
	- Install mrtk
	- Install ros connector
- Install Visual Studio


#### Show how to compile using screenshots
- Build in Unity
- Open .sln file in Visual Studio
- Create Package
- Use Windows device portal to install the msix file
- Stream record using hololens portal


#### To stream webcam to ROS Server
- Install `usb_cam` [[wiki](https://wiki.ros.org/usb_cam) | [github](https://github.com/ros-drivers/usb_cam)]
- Following will publish to `/usb_cam/image_raw`
```sh
# For ros1
sudo apt install ros-<ROS-DISTRO>-usb-cam
v4l2-ctl --list-devices # list available devices; check which one is webcam
rosrun usb_cam usb_cam_node  _video_device:=/dev/video0 _camera_name:='usb_cam' _camera_frame_id:='usb_cam' # assuming /dev/video0 as the webcam
```




# IRVL Image Labelling Support

This is a selection of files based around the testing and smooth operation of the IRVL Image Labelling project.

## Subfolders:

### [PublishImages](PublishImages)

This folder contains the images published by [publishimage.py](publishimage.py). It contains two files [3d.jpg](PublishImages/3d.jpg) and [rgb.jpg](PublishImages/rgb.jpg); only files with these names will be registered and sent by [publishimage.py](publishimage.py).

### [Dataset](Dataset)

In this folder one will find the labels, rgb, and 3d images of things labeled through the hololens. [receiveData.py](receiveData.py) publishes to this folder in real time and the images should already be properly formatted for a YOLO machine learning algorithm, this has been tested on [yolov5](https://github.com/ultralytics/yolov5).

### [HoloLensImageLabellingApp](HoloLensImageLabellingApp)

This is the subproject for the Unity/Hololens component of the pipeline. This folder is what should be opened when attempting to rebuild the project, not the root folder of this project. Further explanation is given in its own section.


## Files

### [run_finetuning_node.py](run_finetuning_node.py)

This is a container class to run both rebroadcastData and receiveData without needing to open another command window. It requires that rospy be installed and accepts no command line arguments.

### [rebroadcastData.py](rebroadcastData.py)

This class takes output from the head camera of a fetch robot and rebroadcasts the rgb and depth at a lower framerate. The output channels are InfrequentImage and InfrequentDepth, both of ros message type [sensor_msgs/Image](http://docs.ros.org/en/noetic/api/sensor_msgs/html/msg/Image.html). This file can be executed alone with dependencies of ros and rospy, and accepts no arguments.

### [receiveData.py](receiveData.py)

As the name suggests and as is described in the Dataset section, this file recieves data from the hololens and stores it in its appropriate directories. The incoming ros messages are LabeledImage, LabeledDepth, and ImageLabels. It will assume that all messages received at the same time belong to the same set, and assign them the same name as is requested by yolo. This file can also be executed on its own without arguments.

### [publishimage.py](publishimage.py)

This file is a stand-in for a fetch robot for when one is not available. It publishes the files explained in the PublishImages folder section under the same name as the robot would, and is therefore indistinguishable other than the lack of change in images. This can only be executed on its own and takes no arguments.

## Hololens Component

### Overview

In order for the user to label images on the move, there must be an application to facilitate it. The Root folder of the project to open is [HoloLensImageLabellingApp](HoloLensImageLabellingApp).

* **Robot POV:** Bring up the most recent image taken in front of the user. drag the spheres on the edges of the frame to rotate it and drag the cubes on the corners to resize it. If the button is pressed again, the frame will be brought to the user's position without clearing existing labels.

* **Discard Sample:** Dismiss the window and clear all labels present.

* **Save Sample:** Send all images and detections back to the Yolo component and dismiss the frame.

* **Label Door:**

* **Label Handle:**

* **Undo:** If an unwanted bounding box is drawn or is drawn wrong, this will remove the most recently placed box.

### Installation

It is recommended that a Windows device is used to compile this part of the project, and has not been tested on other platforms. A Unity version newer or equivalent to a 2022 release and at least Microsoft Visual Studio 2022 are required. Due to technical constraints, this project can only run on a Hololens 2. To deploy the project after building to your local machine, follow the optional steps of [the Hololens 2 tutorial](https://learn.microsoft.com/en-us/training/modules/learn-mrtk-tutorials/1-7-exercise-hand-interaction-with-objectmanipulator) and build the project with the release version; it will lose considerable amounts of FPS when built with a debug target.

## Execution

### PC
On a linux computer, set the ROS_IP and ROS_MASTER_URI (and not ROS_HOSTNAME), then run [execsupport.py](execsupport.py). See [execsupport](#execsupportpy) for individual usage and expectations.

### Server
The server needs to be running [ROS-TCP-Endpoint](https://github.com/Unity-Technologies/ROS-TCP-Endpoint) to connect to the Hololens. See the link for installation instructions.

Once it has been setup, the commands should look approximately as follows:

```
source devel/setup.bash

rosrun ROS-TCP-Endppoint endpoint.launch tcp_ip:=<The server's ip> tcp_port:=10000
```

### Hololens
After setting the IP of the server in Unity, the project needs to be built and deployed to the hololens. Further details are provided in [Hololens Installation](#installation). Once it's deployed, just open the app from the start menu.

## Troubleshooting

### Rviz

For many of these troubleshooting steps, it is required to be able to see the images being passed through ROS. Rviz is recommended for this.

### PC is not receiving images from the server

Check the ROS_IP and ROS_MASTER_URI environment variables on both the server and the PC.

### Hololens is not receiving images

Firstly, check that execsupport is running. If the server is receiving processed images then check that the endpoint launched properly. If both of these are true, check that the ip is set correctly in the Hololens.

### PC is not receiving relabeled images & labels

In this case, it's likely that the PC or server's ROS_HOSTNAME is set to a non-null value. Set these to ```0.0.0.0```.

### OMP: Error #15: Initializing libiomp5md.dll, but found libiomp5md.dll already initialized.

This error might show up in run_finetuning_node.py & receiveData.py. In a terminal in the environment that the program is running in run:

```conda install nomkl --channel conda-forge```

After this, check that all package requirements are still installed. This solution courtesy of [postylem](https://stackoverflow.com/questions/20554074/sklearn-omp-error-15-initializing-libiomp5md-dll-but-found-mk2iomp5md-dll-a).
