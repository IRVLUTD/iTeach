# iTeach: Interactive Teaching for Robot Perception using Mixed Reality 🤖🌐

[Project Webpage](https://irvlutd.github.io/iTeach/)

## Abstract 📝

We introduce **iTeach**, a Mixed Reality (MR) framework designed to enhance robot perception through real-time interactive teaching. By enabling human instructors to dynamically label robot RGB data, iTeach improves both the accuracy and adaptability of robot perception to new scenarios. The framework supports on-the-fly data collection and labeling, enhancing model performance and generalization. Applied to door and handle detection for household tasks, iTeach integrates a HoloLens app with an interactive YOLO model. Furthermore, we introduce the **IRVLUTD DoorHandle** dataset. **DH-YOLO**, our efficient detection model, significantly boosts the accuracy and efficiency of door and handle detection, showcasing the potential of MR to make robotic systems more capable and adaptive in real-world environments.

## Directory Structure 📁

* [src](./src): Contains the primary experiment files.
* [toolkit](./toolkit): Source code for the iTeach toolkit.
* [hololens_app](./hololens_app): Source code for the iTeachLabeller application.
* [dataloader](./dataloader): PyTorch dataloader for the IRVLUTD DoorHandle dataset.
* [hf_demo](./hf_demo): Source code for the DHYOLO Hugging Face space.

**NOTE:** For the [toolkit](./toolkit) and [dataloader](./dataloader), execute the following commands with each new build:
```sh
rm -rf build/ dist/ # Also remove the corresponding .egg-info directory
python setup.py sdist bdist_wheel # Make sure to change the version in setup.py before running this
twine upload dist/* # Ensure you have the pypi-token
```

## Getting Started 🚀

To get started with the codebase, navigate to the relevant directory and explore the files and subdirectories. Each directory may have its own README file with more specific information on how to use the code.

## Contributing 🤝

If you're interested in contributing to the iTeach project, please fork this repository and submit a pull request with your changes. Ensure to follow the coding style and conventions used in the existing code.

## Contact 📬

For any clarification, comments, or suggestions, you can choose from the following options:

- Join the [discussion forum](https://github.com/IRVLUTD/iTeach/discussions). 💬
- Report an [issue](https://github.com/IRVLUTD/iTeach/issues). 🛠️
- Contact [Jishnu](https://jishnujayakumar.github.io/). 📧

## Acknowledgements 🙏

This work was supported by the DARPA Perceptually-enabled Task Guidance (PTG) Program under contract number HR00112220005, the Sony Research Award Program, and the National Science Foundation (NSF) under Grant No. 2346528. We thank [Sai Haneesh Allu](https://saihaneeshallu.github.io/) for his assistance with the real-world experiments. 🙌

## BibTex 📚

```bibtex
Coming soon...
```