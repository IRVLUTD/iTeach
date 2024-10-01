# iTeach: Interactive Teaching for Robot Perception using Mixed Reality

[Project Webpage](https://irvlutd.github.io/iTeach/)

## Abstract

We introduce iTeach, a Mixed Reality (MR) framework to improve robot perception through real-time interactive teaching. By allowing human instructors to dynamically label robot RGB data, iTeach improves both the accuracy and adaptability of robot perception to new scenarios. The framework supports on-the-fly data collection and labeling, enhancing model performance, and generalization. Applied to door and handle detection for household tasks, iTeach integrates a HoloLens app with an interactive YOLO model. Furthermore, we introduce the IRVLUTD DoorHandle dataset. DH-YOLO, our efficient detection model, significantly enhances the accuracy and efficiency of door and handle detection, highlighting the potential of MR to make robotic systems more capable and adaptive in real-world environments.

## Directory Structure

* **src**: main experiment files
* **toolkit**: iteach_toolkit src code
* **hololens_app**: contains the code for iteachlabeller app
* **dataloader**: contains the pytorch dataloader for the new IRVLUTD DoorHandle dataset
* **hf_demo**: contains the code for the DHYOLO HuggingFace space


## Getting Started

To get started with the codebase, navigate to the relevant directory and explore the files and subdirectories. Each directory may have its own README file with more specific information on how to use the code.

## Contributing

If you're interested in contributing to the iTeach project, please fork this repository and submit a pull request with your changes. Make sure to follow the coding style and conventions used in the existing code.

## Questions and Issues

If you have any questions or issues with the code, please open an issue in this repository or contact the project maintainers.

Thank you for your interest in the iTeach project!