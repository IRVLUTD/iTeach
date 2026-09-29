---
name: iteach-repos
description: "iTeach project spans 3 IRVLUTD repos; working clones, conventions, and how the README contents cards are generated"
metadata:
  node_type: memory
  type: project
  originSessionId: 565c7f0a-b409-45f5-b133-3524a16716df
  modified: 2026-09-29T18:27:57.352Z
---

iTeach (paper arXiv 2410.09072, project page irvlutd.github.io/iTeach) is split across IRVLUTD/iTeach (hub + archived DH-YOLO v1), IRVLUTD/iTeachSkillsApp (HoloLens app, Unity project `Unity/iTechDemo`), and IRVLUTD/iTeach-UOIS (SAM2 propagation, MSMFormer training/eval, live ROS node). Working sparse clones live in ~/Projects/iteach-final-code-to-github/.

Conventions agreed with the user (2026-09-29):
- All three repos: MIT license, © Intelligent Robotics and Vision Lab (IRVL), UT Dallas.
- DH-YOLO / iTeach v1 is legacy/archived.
- Grasping uses Contact-GraspNet + GTO from SceneReplica.
- README "Contents" cards are dark-only SVGs, regenerated with `python iTeach/tools/readme_cards/make_toc_cards.py` from the parent dir (edit its CARDS list when sections change).
- Results must match the project page's Results section (UOIS 26.1→80.7, +54.6, 3.1×; grasp 71→74; pick&place 65→72).
- Live setup: robot (<ROBOT_IP>) runs ROS master + `setup_iTeach` alias = ros_tcp_endpoint; laptop is ROS client; HoloLens needs ROSConnectionConfig.json uploaded to LocalAppData/iTechDemo_…/LocalState via Device Portal.

- Verified 2026-09-29: D5 zip lacks gt_masks (masks in each scene's gsam2/masks, link must be recreated); D40/Test include gt_masks. Docker image irvlutd/iteach:uois-peft was made with docker commit (no Dockerfile exists). Live MSMFormer node model is chosen with MODEL/MODEL_CFG env vars.

- Lab-tested envs on this laptop (<lab-laptop>): system ROS Noetic (/opt/ros/noetic) + conda `hololens-pc` (py3.8, terminals 2-4) and `msm39` (py3.9, torch1.10 cu111, detectron2 0.6; MSMFormer node). Pinned in iTeachSkillsApp/Python/requirements-lab.txt and iTeach-UOIS/.../requirements-lab-msm39.txt. RGB-D training OOMs on this 16 GB GPU and needs TOD (mixture_object_train). A software-in-the-loop harness (fake Fetch replaying a recorded scene + scripted HoloLens messages) validated the live laptop pipeline on 2026-09-29.

**Why:** these were decided after several rounds of README rework; don't re-litigate them.
**How to apply:** follow these when editing any iTeach README or docs. The laptop disk is nearly full; use blob:none sparse clones and avoid commands that fetch all blobs (git grep, diff --stat on bulk deletions).
