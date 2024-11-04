<div align="center">
<h1>iTeach: Interactive Teaching for Robot Perception using Mixed Reality 🤖🌐</h1>
<a href="https://jishnujayakumar.github.io/">Jishnu Jaykumar P</a>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
<a href="https://labs.utdallas.edu/irvl/people/">Cole Salvato</a>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
<a href="https://labs.utdallas.edu/irvl/people/">Vinaya Bomnale</a>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
<a href="https://labs.utdallas.edu/irvl/people/">Jikai Wang</a>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
<a href="https://yuxng.github.io/">Yu Xiang</a><br><br>
<a href="https://irvlutd.github.io/iTeach/">Project Webpage</a> | <a href="https://huggingface.co/spaces/IRVLUTD/DH-YOLO">🤗 DH-YOLO Demo</a><br><br>
</div>
<p>We introduce <strong>iTeach</strong>, a Mixed Reality (MR) framework designed to enhance robot perception through real-time interactive teaching. By enabling human instructors to dynamically label robot RGB data, iTeach improves both the accuracy and adaptability of robot perception to new scenarios. The framework supports on-the-fly data collection and labeling, enhancing model performance and generalization. Applied to door and handle detection for household tasks, iTeach integrates a HoloLens app with an interactive YOLO model. Furthermore, we introduce the <strong>IRVLUTD DoorHandle</strong> dataset. <strong>DH-YOLO</strong>, our efficient detection model, significantly boosts the accuracy and efficiency of door and handle detection, showcasing the potential of MR to make robotic systems more capable and adaptive in real-world environments.</p> 

<div align="center">
  <img src="https://irvlutd.github.io/iTeach/assets/images/iteach/iteach-overview.webp" style="width:70%" alt="iTeach Overview"> 
</div>


## Getting Started in only 3 steps 🚀 !!!

The iTeach system can be started in just 3 simple steps:

**Step-1**: Build and install the **iTeachLabeller** app on the HoloLens 2.
  - [App Download Link](https://utdallas.app.box.com/v/iTeachLabellerApp) 📱
  - [App Install Video](https://www.youtube.com/watch?v=7xFtCPSMTEk) 🛠️

**Step-2**: Navigate to the [src](./src) directory and follow the setup instructions in its [README](./src/README.md) file 📚.  
**Step-3**: Start interacting with the app—navigate the robot, collect faulty samples, label them, and fine-tune the model. [Real World Demo](https://www.youtube.com/watch?v=fusb4CkM_IE) 🤖

✨ We show a demo of setting up the experiment hardware, network, and scripts to be run in [this video](https://www.youtube.com/watch?v=gJ7Is0SrNgc) 🎦. For detailed steps, refer to the video description 📋.

## Directory Structure 📁
To begin working with the codebase, first navigate to the relevant directory and explore the files and subdirectories. Each directory includes its own README file with specific instructions on how to use the code.
- [src](./src): Contains the primary experiment files. 🧪  
- [toolkit](./toolkit): Source code for the iTeach toolkit. 🛠️  
- [hololens_app](./hololens_app): Source code for the iTeachLabeller application. 📱  
- [dataloader](./dataloader): PyTorch dataloader for the IRVLUTD DoorHandle dataset. 🗃️  
- [hf_demo](https://huggingface.co/spaces/IRVLUTD/DH-YOLO/tree/main): Source code for the DHYOLO Hugging Face space. 🤗  

<details>
  <summary><strong>Note:</strong> Click to show more 💡 (For PyPI)</summary>
  
  For the [toolkit](./toolkit) and [dataloader](./dataloader), execute the following commands with each new PyPI build:
  
  ```bash
  rm -rf build/ dist/ # Also remove the corresponding .egg-info directory
  python setup.py sdist bdist_wheel # Make sure to change the version in setup.py before running this
  twine upload dist/* # Ensure you have the pypi-token
```
</details>


## BibTex 📚
Please cite ***iTeach*** if it helps your research 🙌:
```bibtex
@misc{padalunkal2024iteach,
    title={iTeach: Interactive Teaching for Robot Perception using Mixed Reality},
    author={Jishnu Jaykumar P and Cole Salvato and Vinaya Bomnale and Jikai Wang and Yu Xiang},
    year={2024},
    eprint={2410.09072},
    archivePrefix={arXiv},
    primaryClass={cs.RO}
}
```

## Contact 📬

For any clarification, comments, or suggestions, you can choose from the following options:

- Join the [discussion forum](https://github.com/IRVLUTD/iTeach/discussions). 💬
- Report an [issue](https://github.com/IRVLUTD/iTeach/issues). 🛠️
- Contact [Jishnu](https://jishnujayakumar.github.io/). 📧

## Acknowledgements 🙏
This work was supported by the DARPA Perceptually-enabled Task Guidance (PTG) Program under contract number HR00112220005, the Sony Research Award Program, and the National Science Foundation (NSF) under Grant No.2346528. We thank [Sai Haneesh Allu](https://saihaneeshallu.github.io/) for his assistance with the real-world experiments. 🙌
