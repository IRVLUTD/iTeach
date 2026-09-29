<div align="center">
<h1>iTeach: In the Wild Interactive Teaching for Failure-Driven Adaptation of Robot Perception 🤖🌐</h1>
<a href="https://jishnujayakumar.github.io/">Jishnu Jaykumar P</a>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
<a href="https://labs.utdallas.edu/irvl/people/">Cole Salvato</a>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
<a href="https://labs.utdallas.edu/irvl/people/">Vinaya Bomnale</a>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
<a href="https://labs.utdallas.edu/irvl/people/">Jikai Wang</a>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
Ayush Bhardwaj&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
Jin-Ryong Kim&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
<a href="https://yuxng.github.io/">Yu Xiang</a><br><br>
<a href="https://irvlutd.github.io/iTeach/">Project Webpage</a> | <a href="https://arxiv.org/abs/2410.09072">arXiv</a> | <a href="https://huggingface.co/spaces/IRVLUTD/DH-YOLO">🤗 DH-YOLO Demo</a><br><br>
</div>
<p><strong>iTeach</strong> adapts robot perception while the robot is deployed, driven by its failures, instead of through offline retraining. When a perception model fails, a human briefly rearranges the objects (<strong>HumanPlay</strong>, 5–10 s) while the robot records RGB-D. The human then labels the final frame hands-free with <strong>eye-gaze and voice</strong> on a HoloLens 2. <strong>SAM2</strong> turns the point prompts into masks and propagates them backwards through the clip, giving dense supervision. That data is used to iteratively fine-tune an <strong>MSMFormer</strong> unseen-object instance segmentation (UOIS) model, which improves downstream grasping and pick-and-place.</p>

<div align="center">
  <img src="https://irvlutd.github.io/iTeach/assets/images/iteach/iteach-overview.webp" style="width:70%" alt="iTeach Overview"> 
</div>

## Code 🧩

The current iTeach system (UOIS with HumanPlay) is split across three repositories. Follow them in this order:

| Step | Repo | What it does |
|---|---|---|
| 1. Capture + label | [IRVLUTD/iTeachSkillsApp](https://github.com/IRVLUTD/iTeachSkillsApp) | HoloLens 2 app + ROS bridge: record a HumanPlay clip, place point prompts on the last frame with gaze + voice, get SAM2 boxes |
| 2. Propagate + train + evaluate | [IRVLUTD/iTeach-UOIS](https://github.com/IRVLUTD/iTeach-UOIS) | Propagate SAM2 masks backwards through the clip, fine-tune MSMFormer, evaluate on the iTeach-HumanPlay test set |
| Networking utilities | this repo, [src/hololens_utils](./src/hololens_utils) | HoloLens Device Portal / hl2ss helpers and the robot ↔ laptop ↔ HoloLens network setup ([src/README.md](./src/README.md), sections 3–5) |

**System setup:** the diagram of the robot ↔ ROS laptop ↔ HoloLens setup (ROS topics, voice commands, and how to point the app at your laptop with `ROSConnectionConfig.json`) is in the [iTeachSkillsApp README](https://github.com/IRVLUTD/iTeachSkillsApp#system-overview).

**Data and checkpoints** (all hosted on UTD Box):
- iTeach-HumanPlay: [D5](https://utdallas.box.com/v/iTeach-HumanPlay-D5) · [D40](https://utdallas.box.com/v/iTeach-HumanPlay-D40) · [Test](https://utdallas.box.com/v/iTeach-HumanPlay-Test)
- Fine-tuned MSMFormer: [D5 ckpts](https://utdallas.box.com/v/iTeach-UOIS-D5-ckpts) · [D40 ckpts](https://utdallas.box.com/v/iTeach-UOIS-D40-ckpts)

**Hardware used:** Fetch mobile manipulator (head RGB-D camera), a laptop with an RTX 4090 for onboard inference and fine-tuning, a Microsoft HoloLens 2, a PS4 controller for teleoperation, and wired Ethernet plus a Wi-Fi hotspot for connectivity.

---

## iTeach v1: Door & Handle Detection (DH-YOLO) 🚪

The rest of this README and the `src/`, `toolkit/`, `dataloader/`, `hololens_app/` and `hf_demo/` folders cover the **earlier version** of iTeach. That version is a Mixed Reality labelling loop for door and handle detection with a YOLOv5-based model (DH-YOLO) and the **IRVLUTD DoorHandle** dataset, using the iTeachLabeller HoloLens app. It is kept for reference and reproducibility of that work.

### Getting Started in only 3 steps 🚀 !!!

The iTeach v1 system can be started in just 3 simple steps:

**Step-1**: Build and install the **iTeachLabeller** app on the HoloLens 2.
  - [App Download Link](https://utdallas.app.box.com/v/iTeachLabellerApp) 📱
  - [App Install Video](https://www.youtube.com/watch?v=7xFtCPSMTEk) 🛠️

**Step-2**: Navigate to the [src](./src) directory and follow the setup instructions in its [README](./src/README.md) file 📚.  
**Step-3**: Start interacting with the app—navigate the robot, collect faulty samples, label them, and fine-tune the model. [Real World Demo](https://www.youtube.com/watch?v=fusb4CkM_IE) 🤖

✨ We show a demo of setting up the experiment hardware, network, and scripts to be run in [this video](https://www.youtube.com/watch?v=gJ7Is0SrNgc) 🎦. For detailed steps, refer to the video description 📋.

### Directory Structure 📁
To begin working with the codebase, first navigate to the relevant directory and explore the files and subdirectories. Each directory includes its own README file with specific instructions on how to use the code.
- [src](./src): Contains the primary experiment files. 🧪  
- [toolkit](./toolkit): Source code for the iTeach toolkit. 🛠️  
- [hololens_app](./hololens_app): Source code for the iTeachLabeller application. 📱  
- [dataloader](./dataloader): PyTorch dataloader for the IRVLUTD DoorHandle dataset. 🗃️  
- [hf_demo](https://huggingface.co/spaces/IRVLUTD/DH-YOLO/tree/main): Source code for the DHYOLO Hugging Face space. 🤗 This is a git submodule; fetch it with `git submodule update --init hf_demo` (requires [git-lfs](https://git-lfs.com/)).  

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
      title={iTeach: In the Wild Interactive Teaching for Failure-Driven Adaptation of Robot Perception}, 
      author={Jishnu Jaykumar P and Cole Salvato and Vinaya Bomnale and Jikai Wang and Ayush Bhardwaj and Jin-Ryong Kim and Yu Xiang},
      year={2026},
      eprint={2410.09072},
      archivePrefix={arXiv},
      primaryClass={cs.RO},
      url={https://arxiv.org/abs/2410.09072}, 
}
```

## Contact 📬

For any clarification, comments, or suggestions, you can choose from the following options:

- Join the [discussion forum](https://github.com/IRVLUTD/iTeach/discussions). 💬
- Report an [issue](https://github.com/IRVLUTD/iTeach/issues). 🛠️
- Contact [Jishnu](https://jishnujayakumar.github.io/). 📧

## Acknowledgements 🙏
This work was supported by the DARPA Perceptually-enabled Task Guidance (PTG) Program under contract number HR00112220005, the Sony Research Award Program, and the National Science Foundation (NSF) under Grant No.2346528. We thank [Sai Haneesh Allu](https://saihaneeshallu.github.io/) for his assistance with the real-world experiments. 🙌
