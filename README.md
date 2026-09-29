<div align="center">

# 🤖 iTeach

### In the Wild Interactive Teaching for Failure-Driven Adaptation of Robot Perception

<br>

<a href="https://jishnujayakumar.github.io">Jishnu Jaykumar P</a> &nbsp;·&nbsp;
<a href="https://labs.utdallas.edu/irvl/people/">Cole Salvato</a> &nbsp;·&nbsp;
<a href="https://labs.utdallas.edu/irvl/people/">Vinaya Bomnale</a> &nbsp;·&nbsp;
<a href="https://jwroboticsvision.github.io/">Jikai Wang</a> &nbsp;·&nbsp;
<a href="https://ayush-bhardwaj.vercel.app/">Ayush Bhardwaj</a> &nbsp;·&nbsp;
<a href="https://jessekim.com/">Jin-Ryong Kim</a> &nbsp;·&nbsp;
<a href="https://yuxng.github.io/">Yu Xiang</a>

<sub>Intelligent Robotics and Vision Lab · The University of Texas at Dallas</sub>

<br><br>

[![Project Page](https://img.shields.io/badge/Project-Page-2ea44f?style=for-the-badge)](https://irvlutd.github.io/iTeach/)
[![arXiv](https://img.shields.io/badge/arXiv-2410.09072-b31b1b?style=for-the-badge)](https://arxiv.org/abs/2410.09072)
[![DH-YOLO Demo](https://img.shields.io/badge/🤗%20Demo-DH--YOLO-ffcc4d?style=for-the-badge)](https://huggingface.co/spaces/IRVLUTD/DH-YOLO)

<br>

<img src="https://irvlutd.github.io/iTeach/assets/images/iteach/iteach-overview.webp" width="80%" alt="iTeach Overview">

</div>

<br>

**iTeach** adapts robot perception **while the robot is deployed**, triggered by its failures, instead of through offline retraining.

When the perception model fails, a human spends a few seconds rearranging the objects (**HumanPlay**, 5–10 s) while the robot records RGB-D. The human then labels the final frame **hands-free with eye-gaze and voice** on a HoloLens 2. **SAM2** turns those point prompts into masks and propagates them backwards through the clip, producing dense supervision. That data is used to iteratively fine-tune an **MSMFormer** unseen-object instance segmentation (UOIS) model, which in turn improves grasping and pick-and-place.

<br>

<div align="center">

| 🎯 UOIS combined score | 🦾 Grasping | 📦 Pick-and-place | 👥 User study (12 participants) |
|:-:|:-:|:-:|:-:|
| **26.1 → 80.7** | **71 → 74** / 100 | **65 → 72** / 100 | 94.9% box IoU · NASA-TLX 21/100 |

</div>

<br>

## 📑 Contents

<table>
  <tr><th width="4%">#</th><th width="34%">Section</th><th>Go here to…</th></tr>
  <tr><td align="center">1</td><td><a href="#-code"><b>🧩 Code</b></a></td><td>Find which repository does what, and in which order to use them<br><small>↳ <a href="#-data--checkpoints">Data & checkpoints</a> · <a href="#️-hardware">Hardware</a></small></td></tr>
  <tr><td align="center">2</td><td><a href="#-iteach-v1-door--handle-detection-dh-yolo"><b>🚪 iTeach v1: Door & Handle Detection (DH-YOLO)</b></a></td><td>The earlier DH-YOLO system in this repo<br><small>↳ <a href="#-getting-started-in-3-steps">Getting started</a> · <a href="#-directory-structure">Directory structure</a></small></td></tr>
  <tr><td align="center">·</td><td colspan="2"><a href="#-citation">📚 Citation</a> · <a href="#-contact">📬 Contact</a> · <a href="#-acknowledgements">🙏 Acknowledgements</a></td></tr>
</table>

<br>

---

<br>

## 🧩 Code

The current iTeach system is split into **three repositories**, one per module. Follow them in this order:

<br>

<table>
  <tr>
    <th width="8%">Step</th>
    <th width="30%">Repository</th>
    <th>What it does</th>
  </tr>
  <tr>
    <td align="center"><b>1</b></td>
    <td>🥽 <a href="https://github.com/IRVLUTD/iTeachSkillsApp"><b>iTeachSkillsApp</b></a></td>
    <td>HoloLens 2 app + ROS bridge. Watch live predictions, record a HumanPlay clip, place point prompts with gaze + voice, get SAM2 boxes.</td>
  </tr>
  <tr>
    <td align="center"><b>2</b></td>
    <td>🧠 <a href="https://github.com/IRVLUTD/iTeach-UOIS"><b>iTeach-UOIS</b></a></td>
    <td>Propagate SAM2 masks backwards through the clip, fine-tune MSMFormer, evaluate on iTeach-HumanPlay, and run MSMFormer as a live ROS node.</td>
  </tr>
  <tr>
    <td align="center">🔧</td>
    <td>📍 <b>iTeach</b> <sub>(this repo)</sub> · <a href="./src/hololens_utils">src/hololens_utils</a></td>
    <td>HoloLens Device Portal / hl2ss helpers and the robot ↔ laptop ↔ HoloLens network setup (<a href="./src/README.md">src/README.md</a>, sections 3–5).</td>
  </tr>
</table>

<br>

> [!TIP]
> **Setting up the whole system?** Start with the [system diagram and five-terminal setup](https://github.com/IRVLUTD/iTeachSkillsApp#-system-overview) in iTeachSkillsApp. It covers the ROS topics, the voice commands, and how to point the HoloLens at your robot with `ROSConnectionConfig.json`.

<br>

### 📦 Data & Checkpoints

<sub>All hosted on UTD Box.</sub>

| | D5 · 5 controlled scenes | D40 · 40 scenes | Test · 902 samples |
|:--|:-:|:-:|:-:|
| **iTeach-HumanPlay dataset** | [Download](https://utdallas.box.com/v/iTeach-HumanPlay-D5) | [Download](https://utdallas.box.com/v/iTeach-HumanPlay-D40) | [Download](https://utdallas.box.com/v/iTeach-HumanPlay-Test) |
| **Fine-tuned MSMFormer** | [Download](https://utdallas.box.com/v/iTeach-UOIS-D5-ckpts) | [Download](https://utdallas.box.com/v/iTeach-UOIS-D40-ckpts) | – |

<br>

### 🛠️ Hardware

| | |
|:--|:--|
| 🤖 **Robot** | Fetch mobile manipulator with a head RGB-D camera |
| 💻 **Compute** | Laptop with an RTX 4090 for onboard inference and fine-tuning |
| 🥽 **Mixed reality** | Microsoft HoloLens 2 |
| 🎮 **Teleoperation** | PS4 controller |
| 🌐 **Network** | Wired Ethernet + Wi-Fi hotspot |

<br>

<div align="right"><sub><a href="#-contents">⬆ back to contents</a></sub></div>

---

<br>

## 🚪 iTeach v1: Door & Handle Detection (DH-YOLO)

> [!NOTE]
> Everything below, and the `src/`, `toolkit/`, `dataloader/`, `hololens_app/` and `hf_demo/` folders, covers the **earlier version** of iTeach. That version is a Mixed Reality labelling loop for door and handle detection with a YOLOv5-based model (**DH-YOLO**), the **IRVLUTD DoorHandle** dataset and the **iTeachLabeller** HoloLens app. It is kept for reference and reproducibility.

<br>

### 🚀 Getting started in 3 steps

**1 · Install the iTeachLabeller app on the HoloLens 2**
&nbsp;&nbsp;📱 Build it from [`hololens_app/`](./hololens_app) &nbsp;·&nbsp; 🛠️ [Install video](https://www.youtube.com/watch?v=7xFtCPSMTEk)

**2 · Set up the laptop and robot**
&nbsp;&nbsp;📚 Follow [src/README.md](./src/README.md)

**3 · Teach**
&nbsp;&nbsp;🤖 Drive the robot, collect failure samples, label them and fine-tune. &nbsp;·&nbsp; 🎬 [Real-world demo](https://www.youtube.com/watch?v=fusb4CkM_IE)

<br>

🎦 A walkthrough of the hardware, network and scripts is in [this video](https://www.youtube.com/watch?v=gJ7Is0SrNgc). Detailed steps are in its description.

<br>

### 📁 Directory structure

Each directory has its own README.

| Folder | Contents |
|:--|:--|
| 🧪 [`src/`](./src) | Main experiment files |
| 🛠️ [`toolkit/`](./toolkit) | iTeach toolkit (DH-YOLO inference) |
| 📱 [`hololens_app/`](./hololens_app) | iTeachLabeller HoloLens app source |
| 🗃️ [`dataloader/`](./dataloader) | PyTorch dataloader for the IRVLUTD DoorHandle dataset |
| 🤗 [`hf_demo/`](https://huggingface.co/spaces/IRVLUTD/DH-YOLO/tree/main) | DH-YOLO Hugging Face space (git submodule: `git submodule update --init hf_demo`, needs [git-lfs](https://git-lfs.com/)) |

<br>

<details>
<summary><b>📦 Publishing <code>toolkit</code> / <code>dataloader</code> to PyPI</b></summary>
<br>

Run these with each new build:

```bash
rm -rf build/ dist/               # also remove the corresponding .egg-info directory
python setup.py sdist bdist_wheel # bump the version in setup.py first
twine upload dist/*               # needs your PyPI token
```

</details>

<br>

<div align="right"><sub><a href="#-contents">⬆ back to contents</a></sub></div>

---

<br>

## 📚 Citation

If ***iTeach*** helps your research, please cite:

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

<br>

## 📬 Contact

| | |
|:--|:--|
| 💬 Questions & ideas | [Discussion forum](https://github.com/IRVLUTD/iTeach/discussions) |
| 🛠️ Bugs | [Open an issue](https://github.com/IRVLUTD/iTeach/issues) |
| 📧 Direct | [Jishnu](https://jishnujayakumar.github.io/) |

<br>

## 🙏 Acknowledgements

This work was supported by the DARPA Perceptually-enabled Task Guidance (PTG) Program under contract number HR00112220005, the Sony Research Award Program, and the National Science Foundation (NSF) under Grant No. 2346528. We thank [Sai Haneesh Allu](https://saihaneeshallu.github.io/) for his assistance with the real-world experiments.

<br>

<div align="center">
<sub>Built at the <a href="https://labs.utdallas.edu/irvl/">Intelligent Robotics and Vision Lab</a>, The University of Texas at Dallas</sub>
</div>
