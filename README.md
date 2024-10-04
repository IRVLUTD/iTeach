# iTeach: Interactive Teaching for Robot Perception using Mixed Reality 🤖🌐

[Project Webpage](https://irvlutd.github.io/iTeach/) | [🤗 DH-YOLO Demo](https://huggingface.co/spaces/IRVLUTD/DH-YOLO)

![](https://irvlutd.github.io/iTeach/assets/images/iteach/iteach-overview.webp)

## Abstract 📝

We introduce **iTeach**, a Mixed Reality (MR) framework designed to enhance robot perception through real-time interactive teaching. By enabling human instructors to dynamically label robot RGB data, iTeach improves both the accuracy and adaptability of robot perception to new scenarios. The framework supports on-the-fly data collection and labeling, enhancing model performance and generalization. Applied to door and handle detection for household tasks, iTeach integrates a HoloLens app with an interactive YOLO model. Furthermore, we introduce the **IRVLUTD DoorHandle** dataset. **DH-YOLO**, our efficient detection model, significantly boosts the accuracy and efficiency of door and handle detection, showcasing the potential of MR to make robotic systems more capable and adaptive in real-world environments.


## Getting Started 🚀

To begin working with the codebase, first navigate to the relevant directory and explore the files and subdirectories. Each directory includes its own README file with specific instructions on how to use the code.

For a demonstration of the experiment setup, please check out [this video](https://www.youtube.com/watch?v=gJ7Is0SrNgc) 🎥. For detailed steps, refer to the video description 📋.

**Step 1**: Build and install the **iTeachLabeller** app on the HoloLens 2. [App Install Video](https://www.youtube.com/watch?v=7xFtCPSMTEk) 🛠️  
**Step 2**: Navigate to the [src](./src) directory and follow the setup instructions in its [README](./src/README.md) file 📚.  
**Step 3**: Start interacting with the app—navigate the robot, collect faulty samples, label them, and fine-tune the model. [Real World Demo](https://www.youtube.com/watch?v=fusb4CkM_IE) 🤖



## Directory Structure 📁

* [src](./src): Contains the primary experiment files.
* [toolkit](./toolkit): Source code for the iTeach toolkit.
* [hololens_app](./hololens_app): Source code for the iTeachLabeller application.
* [dataloader](./dataloader): PyTorch dataloader for the IRVLUTD DoorHandle dataset.
* [hf_demo](https://huggingface.co/spaces/IRVLUTD/DH-YOLO/tree/main): Source code for the DHYOLO Hugging Face space.

**NOTE:** For the [toolkit](./toolkit) and [dataloader](./dataloader), execute the following commands with each new build:
```sh
rm -rf build/ dist/ # Also remove the corresponding .egg-info directory
python setup.py sdist bdist_wheel # Make sure to change the version in setup.py before running this
twine upload dist/* # Ensure you have the pypi-token
```


## Contributing 🤝

If you're interested in contributing to the iTeach project, please fork this repository and submit a pull request with your changes. Ensure to follow the coding style and conventions used in the existing code.

## Contact 📬

For any clarification, comments, or suggestions, you can choose from the following options:

- Join the [discussion forum](https://github.com/IRVLUTD/iTeach/discussions). 💬
- Report an [issue](https://github.com/IRVLUTD/iTeach/issues). 🛠️
- Contact [Jishnu](https://jishnujayakumar.github.io/). 📧

## Acknowledgements 🙏
This work was supported by the 
- Sony Research Award Program
- National Science Foundation (NSF) under Grant No. `2346528`
- DARPA Perceptually-enabled Task Guidance (PTG) Program under contract number `HR00112220005`

We thank [Sai Haneesh Allu](https://saihaneeshallu.github.io/) for his assistance with the real-world experiments. 🙌

## BibTex 📚
Please cite ***iTeach*** if it helps your research 🙌:
```bibtex
Coming soon...
```