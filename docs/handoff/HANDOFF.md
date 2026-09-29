# iTeach handoff: resume on another machine

> **Sanitised copy.** Usernames, the machine name and the lab's private IPs have been
> replaced with placeholders: `/home/<user>`, `<lab-laptop>`, `<ROBOT_IP>` (robot),
> `<LAPTOP_IP>` (laptop, wired), `<HOLOLENS_IP>` / `<HOTSPOT_GW>` / `<HOTSPOT_CLIENT>`
> (hotspot). Substitute your own values before running anything.

Snapshot taken on the lab laptop `<lab-laptop>` on 2026-09-29, at the end of a working session that finalised the three iTeach repositories.

## 1. Where the work lives (all pushed)

| Repo | Commit | Role |
|:--|:--|:--|
| [IRVLUTD/iTeach](https://github.com/IRVLUTD/iTeach) | `79bf0a4` | Project hub, archived DH-YOLO v1, `src/hololens_utils` (Device Portal upload), README card generator |
| [IRVLUTD/iTeachSkillsApp](https://github.com/IRVLUTD/iTeachSkillsApp) | `e3f25d3` | HoloLens 2 app (Unity `Unity/iTechDemo`) + live laptop scripts |
| [IRVLUTD/iTeach-UOIS](https://github.com/IRVLUTD/iTeach-UOIS) | `355d0e9` | SAM2 propagation, MSMFormer training/eval, live MSMFormer ROS node |

Resume by cloning. iTeach's history contains ~1.2 GB of old Unity cache, so use a partial clone:

```bash
git clone https://github.com/IRVLUTD/iTeachSkillsApp.git
git clone https://github.com/IRVLUTD/iTeach-UOIS.git
git clone --filter=blob:none https://github.com/IRVLUTD/iTeach.git
```

Pushing from a new machine needs its own GitHub login (SSH key or `gh auth login`). The personal access token used during this session was revoked.

## 2. Conventions agreed in this session (don't re-litigate)

- **License:** MIT, © Intelligent Robotics and Vision Lab (IRVL), UT Dallas, identical in all three repos. Bundled third-party code keeps its own license (YOLOv5 AGPL-3.0; UCN NVIDIA non-commercial; MSMFormer MIT; robokit MIT).
- **DH-YOLO / iTeach v1 is legacy/archived.** `iTeach/src/hololens_utils` is still used by the current system.
- **Grasping / pick-and-place** use Contact-GraspNet + GTO from SceneReplica.
- **Results** must match the project page's Results section: UOIS combined score 26.1 → 80.7 (+54.6, 3.1×); SceneReplica grasping 71 → 74, pick & place 65 → 72; user study 12 participants, 240 annotations, 94.9 % box IoU, NASA-TLX 21/100.
- **README contents cards** are dark-only SVGs. Regenerate with `python iTeach/tools/readme_cards/make_toc_cards.py`, run from a folder containing the three clones; edit its `CARDS` list when sections change.
- `setup_iTeach` on the Fetch is an alias that starts the ROS TCP server (`ros_tcp_endpoint`); the robot's ROS master is already running.

## 3. The lab's working setup (from this laptop)

- **Network** (`lab-config/`): the robot `<ROBOT_IP>` is wired to the laptop `<LAPTOP_IP>/24`. The laptop's Wi-Fi hotspot is in NetworkManager *Shared* mode, and the HoloLens joins it (e.g. `<HOLOLENS_IP>`). The HoloLens config points at the robot: `ROSConnectionConfig.json`, uploaded to `LocalAppData/iTechDemo_…/LocalState` via the Device Portal.
- **Environments** (`environments/`): system ROS Noetic (`/opt/ros/noetic`) plus conda envs:
  - `hololens-pc` (Python 3.8): live terminals 2–4. Pinned in `iTeachSkillsApp/Python/requirements-lab.txt`.
  - `msm39` (Python 3.9, torch 1.10 + cu111, detectron2 0.6): live MSMFormer node. Pinned in `iTeach-UOIS/uois-models/UnseenObjectsWithMeanShift/requirements-lab-msm39.txt`, with `setuptools==59.5.0` added for training.
  - `iteachskills` (Python 3.11): RoboStack-style. Kept for reference only; `cv_bridge` raw conversion fails in it.
  - `*.pip-freeze.txt` / `*.conda.yml` here are full exports; the requirement files in the repos are the curated, index-checked versions.

## 4. What was verified, and how

A laptop-side software-in-the-loop run (`test-harness/`) replayed a recorded Fetch scene as the camera topics and scripted the HoloLens messages.

| Verified ✅ | Not verified ⚠️ |
|:--|:--|
| Live MSMFormer node from repo code with README-built checkpoints (~0.7 Hz) | Training to completion: RGB-D fine-tuning OOMs on a 16 GB GPU and needs TOD (34 GB) |
| Predictions → `sub_compress_pub.py` → `/hololens_stream/compressed` → HoloLens | SAM2 mask propagation (robokit/SAM2 not installed; disk too small) |
| Record start/stop → one scene folder per capture (60 frames each), SAM2 previews back | Robot + HoloLens hardware: network route, Unity build, the real app |
| GPU peak 13.7 / 16.4 GB (MSMFormer + SAM2) | |
| `test_data.py` data check; evaluation → `results.json` → `combined_score.py` | |
| Serving a run's `model_final.pth` + `config.yaml` via `MODEL` / `MODEL_CFG` | |

Fixed along the way (all pushed): 94 missing MSMFormer/UCN source files restored; `set_env.sh` on fresh clones; a stray `/home/<user>` `WEIGHTS` in `humanplay_RGBD.yaml`; `sub_compress_pub.py` for non-3.8 Python; the recorder overwriting captures; `combined_score.py` input format; D5 `gt_masks` symlink note; 72 tracked `.pyc` files.

The harness scripts hard-code this laptop's paths (`/home/<user>/...`, the scratchpad). Adjust the variables at the top of `run_sil.sh` / `run_offline.sh` before re-running elsewhere.

## 5. Still open

1. Full RGB-D training run: needs a GPU with more than 16 GB and TOD in `DATA/tabletop_dataset_v5_public/`.
2. SAM2 mask propagation on a machine with robokit + SAM2.
3. One robot + HoloLens session following the README and its first-run checklist.
4. 27 GitHub security (Dependabot) alerts on IRVLUTD/iTeach, mostly from the archived YOLOv5 code.
5. **Security:** a stale GitHub credential was found on the origin laptop and handled there; nothing sensitive is present in this handoff or in any pushed repo.
6. the `rclone` remote used for dataset transfer has an expired login (`rclone config reconnect <remote>:`).

## 6. Laptop-only files NOT in this handoff

| What | Path on the laptop | Size | Status |
|:--|:--|:-:|:--|
| Per-round fine-tuned checkpoints f1/f2 | `~/Projects/iTeach-UOIS/uois-models/UnseenObjectsWithMeanShift/new_ckpts/` | 402 MB | In the separate `iteach-new_ckpts-f1-f2.zip` |
| Raw MSMFormer predictions | `…/UnseenObjectsWithMeanShift/raw-msm-preds/` | 5.0 GB | Not copied (likely regenerable) |
| Recorded D5 captures | `~/Projects/iteachSkillsApp/Python/_data_captured.og.iteach-uois/` | 1.8 GB | Same scenes as the released D5 on Box; their `prompts.json` are included here |
| Other captures (`task_*`) | `~/Projects/iteachSkillsApp/Python/_dc*` | 0.2 GB | Not copied |
| v1 / other projects | `~/Projects/hololens` | 31 GB | Outside this handoff |
| Public weights (SAM2, pretrained MSMFormer/UCN) | various | ~1.3 GB | Re-downloadable (SAM2 via ultralytics; checkpoints via the Box links in the READMEs) |

## 7. Contents of this handoff

```
HANDOFF.md                     this file
lab-config/                    ROSConnectionConfig.json, ROS/HoloLens lines from ~/.bashrc (password redacted),
                               NetworkManager wired + hotspot profile settings
environments/                  pip freeze + conda export of hololens-pc, msm39, iteachskills (tokens redacted);
                               installed system ROS Noetic packages
old-repo-changes/              uncommitted diffs of the laptop's older clones (already ported into the repos,
                               kept as the exact lab versions) + small untracked sources, D5 prompts.json and
                               f1/f2 training configs
test-harness/                  fake_fetch.py, fake_hololens.py, run_sil.sh, run_offline.sh
claude-memory/                 Claude Code project memory; copy into ~/.claude/projects/<project>/memory/
                               on the new machine so a Claude session resumes with these conventions
```
