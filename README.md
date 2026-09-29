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
[![Video](https://img.shields.io/badge/▶%20Video-Overview-FF0000?style=for-the-badge&logo=youtube&logoColor=white)](https://www.youtube.com/watch?v=J380k96szSM)
[![DH-YOLO Demo](https://img.shields.io/badge/🤗%20Demo-DH--YOLO-ffcc4d?style=for-the-badge)](https://huggingface.co/spaces/IRVLUTD/DH-YOLO)

<br>

<img src="media/intro.webp" width="95%" alt="iTeach overview">
<br>
<sub><i>A pretrained perception model fails in the wild. A co-located human performs a short HumanPlay, annotates a single frame with eye-gaze + voice, and the label is propagated across the RGB-D clip. Failure-driven samples feed an iterative fine-tuning loop, and the best checkpoint is redeployed.</i></sub>

</div>

<br>

**iTeach** adapts robot perception **while the robot is deployed**, triggered by its failures, instead of through offline retraining.

When the perception model fails, a human spends a few seconds rearranging the objects (**HumanPlay**, 5–10 s) while the robot records RGB-D. The human then labels the final frame **hands-free with eye-gaze and voice** on a HoloLens 2. **SAM2** turns those point prompts into masks and propagates them backwards through the clip, producing dense supervision. That data is used to iteratively fine-tune an **MSMFormer** unseen-object instance segmentation (UOIS) model, which in turn improves grasping and pick-and-place.

<br>

<div align="center">

| 🎯 UOIS combined score | 🦾 Grasping success | 📦 Pick & place success | 👥 User study |
|:-:|:-:|:-:|:-:|
| **26.1 → 80.7**<br><sub>+54.6 · 3.1× lift</sub> | **71 → 74** / 100<br><sub>+3 on SceneReplica</sub> | **65 → 72** / 100<br><sub>+7 on SceneReplica</sub> | **94.9%** mean box IoU<br><sub>NASA-TLX 21/100 · 12 participants</sub> |

</div>

<br>

## 📑 Contents

<table>
<tr>
<td width="33%" valign="top"><kbd>01</kbd> <small>🔎 Understand</small><br><br><b>🎬 <a href="#-how-it-works">How It Works</a></b><br><small>The overview video and the three FS3 labelling steps</small></td>
<td width="33%" valign="top"><kbd>02</kbd> <small>🔎 Understand</small><br><br><b>📈 <a href="#-results">Results</a></b><br><small>Perception improves, manipulation follows, anyone can teach</small><br><small>↳ <a href="#-perception-adaptation">Perception</a> · <a href="#-manipulation-follows">Manipulation</a> · <a href="#-who-can-teach--12-participant-user-study">User study</a></small></td>
<td width="33%" valign="top"><kbd>03</kbd> <small>🧰 Set up</small><br><br><b>🧩 <a href="#-code">Code</a></b><br><small>Which repository does what, and in which order</small><br><small>↳ <a href="#-data--checkpoints">Data & checkpoints</a> · <a href="#️-hardware">Hardware</a></small></td>
</tr>
<tr>
<td width="33%" valign="top"><kbd>04</kbd> <small>📖 Reference</small><br><br><b>🚪 <a href="#-iteach-v1-door--handle-detection-dh-yolo">iTeach v1 · DH-YOLO</a></b><br><small>The earlier door and handle detection system</small><br><small>↳ <a href="#-getting-started-in-3-steps">Getting started</a> · <a href="#-directory-structure">Directory structure</a></small></td>
<td width="33%" valign="top"><kbd>✦</kbd> <small>📚 MORE</small><br><br><b>📚 <a href="#-citation">Citation</a> · 📬 <a href="#-contact">Contact</a> · 🙏 <a href="#-acknowledgements">Acknowledgements</a></b><br><small>How to cite iTeach, and how to reach us</small></td>
<td width="33%"></td>
</tr>
</table>

<br>

---

<br>

## 🎬 How It Works

<p align="center">
  <a href="https://www.youtube.com/watch?v=J380k96szSM">
    <img src="media/overview-video.jpg" width="70%" alt="iTeach overview video">
  </a>
  <br>
  <sub>▶ <b><a href="https://www.youtube.com/watch?v=J380k96szSM">Watch the overview video</a></b></sub>
</p>

<br>

Labelling uses **FS3 (Few-Shot Semi-Supervised)**: one human-labelled frame becomes dense supervision for the whole clip.

<br>

**① HumanPlay: clean up the scene**

<p align="center">
  <img src="media/humanplay.gif" width="55%" alt="HumanPlay interaction">
  <br>
  <sub><i>The human rearranges objects to reduce occlusion and produce a clean final frame while a short 5–10 s RGB-D sequence is recorded.</i></sub>
</p>

<br>

**② Annotate hands-free: eye-gaze + voice**

<p align="center">
  <img src="media/iteach-uois-annotation.webp" width="90%" alt="FS3 annotation via eye-gaze and voice">
  <br>
  <sub><i>Eye-gaze places point prompts on the final frame; a voice command triggers SAM2 to convert them into bounding-box object labels.</i></sub>
</p>

<br>

**③ Propagate: SAM2 video mode**

<p align="center">
  <img src="media/sam2-mask-prop.webp" width="80%" alt="SAM2 label propagation">
  <br>
  <sub><i>SAM2 propagates masks backwards from the final annotated frame to all earlier frames, producing dense per-frame supervision.</i></sub>
</p>

<br>

<div align="right"><sub><a href="#-contents">⬆ back to contents</a></sub></div>

---

<br>

## 📈 Results

<p align="center"><b>Perception improves · Manipulation follows · Anyone can teach</b></p>

<br>

### 🎯 Perception adaptation

<div align="center">

| UOIS combined score | Before | After | Gain |
|:--|:-:|:-:|:-:|
| MSMFormer → iTeach fine-tuned | 26.1 | **80.7** | **+54.6** · **3.1×** |

</div>

<p align="center">
  <img src="media/iteach-uois-qual.webp" width="90%" alt="Qualitative UOIS across iTeach fine-tuning rounds">
  <br>
  <sub><i>Qualitative UOIS. Left → right: ground truth, pretrained MSMFormer, and iTeach fine-tuning rounds FT1, FT3, FT5. iTeach recovers missed instances and cleans up over-segmentation across tabletops, shelves, sofas, stairs and floor-level scenes.</i></sub>
</p>

<br>

### 🦾 Manipulation follows

<div align="center">

| Success / 100 (SceneReplica) | Prior best (MSMFormer) | iTeach-UOIS | Gain |
|:--|:-:|:-:|:-:|
| 🦾 Grasping | 71 | **74** | **+3** |
| 📦 Pick & place | 65 | **72** | **+7** |

</div>

<p align="center">
  <img src="media/realworld-with-gto.webp" width="100%" alt="Real-world pick-and-place with GTO">
  <br>
  <sub><i>Only the segmentation stage changes across comparisons; everything else is held fixed. Swap in iTeach-UOIS and the same real-robot pipeline (UOIS → GTO motion planning → grasp) starts handling clutter and unseen objects the pretrained baseline fails on.</i></sub>
</p>

<br>

### 👥 Who can teach? · 12-participant user study

<div align="center">

| 👥 Participants | ✍️ Annotations | 🎯 Mean box IoU | 🧠 NASA-TLX |
|:-:|:-:|:-:|:-:|
| **12**<br><sub>6 expert · 6 non-expert</sub> | **240**<br><sub>12 people × 20 objects</sub> | **94.9%**<br><sub>SD 0.49 · gaze + voice prompts</sub> | **21 / 100**<br><sub>low task load</sub> |

</div>

<sub>Each participant ran one full teaching interaction unassisted: spot the failure in the headset, perform HumanPlay, then label the final frame with gaze and voice. <b>Expertise made no difference on any measure.</b></sub>

<br>

<div align="right"><sub><a href="#-contents">⬆ back to contents</a></sub></div>

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

<p align="center">
  <img src="media/system-setup.webp" width="85%" alt="Deployment setup: Fetch robot with an RTX 4090 laptop and a human wearing a HoloLens 2">
  <br>
  <sub><i>Everything the system needs is in this frame: a Fetch carrying an RGB-D camera and an RTX 4090 laptop that runs inference, SAM2 and fine-tuning onboard, and a human wearing a HoloLens 2 for the live overlay and gaze + voice annotation.</i></sub>
</p>

<br>

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

<p align="center">
  <img src="https://irvlutd.github.io/iTeach/assets/images/iteach/iteach-overview.webp" width="80%" alt="iTeach v1 overview">
  <br>
  <sub><i>iTeach v1: Mixed Reality labelling loop for door and handle detection.</i></sub>
</p>

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
