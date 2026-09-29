#!/bin/bash
# Offline half of the README flow on the two live captures (box masks stand in for SAM2 propagation).
SC=/tmp/claude-1001/-home-hololens/565c7f0a-b409-45f5-b133-3524a16716df/scratchpad
SIL=$SC/sil; HP=$SC/hp; LOG=$SIL/logs_offline; rm -rf $HP $LOG; mkdir -p $LOG
UOIS=/home/<user>/Projects/iteach-final-code-to-github/iTeach-UOIS; MSM=$UOIS/uois-models/UnseenObjectsWithMeanShift
CAP=/home/<user>/Projects/iteach-final-code-to-github/iTeachSkillsApp/Python/data_captured
ROSENV='source /opt/ros/noetic/setup.bash; export ROS_MASTER_URI=http://localhost:11311 ROS_IP=127.0.0.1; unset ROS_HOSTNAME'
source ~/miniconda3/etc/profile.d/conda.sh; conda activate msm39
export PYTHONPATH=/tmp/claude-1001/-home-hololens/565c7f0a-b409-45f5-b133-3524a16716df/scratchpad/st59:$PYTHONPATH   # setuptools==59.5.0 (README known fix), temp only
PIDS=(); cleanup(){ for p in "${PIDS[@]}"; do kill -TERM -- -$p 2>/dev/null; done; sleep 2; for p in "${PIDS[@]}"; do kill -KILL -- -$p 2>/dev/null; done
  rm -f $UOIS/DATA/iTeach-HumanPlay; rmdir $UOIS/DATA 2>/dev/null; rm -f $MSM/MSMFormer/configs/_sil_tmp.yaml; rm -rf $MSM/MSMFormer/sil_run; }
trap cleanup EXIT
# 1. dataset in the README layout: training_set/scene*, test_set/scene*
i=0; for s in $(ls -d $CAP/scene_* | sort); do
  split=$([ $i -eq 0 ] && echo training_set || echo test_set); d=$HP/$split/scene_sil_$i; mkdir -p $d/gt_masks
  ln -s $s/rgb $d/rgb; ln -s $s/depth $d/depth
  python - "$s" "$d" <<'PYEOF'
import sys, json, os, numpy as np, cv2
s, d = sys.argv[1:]; boxes = json.load(open(f"{s}/prompts.json"))["bboxes_xyxy"]
lab = np.zeros((480, 640), np.uint8)
for k, (x1, y1, x2, y2) in enumerate(boxes, 1): lab[y1:y2, x1:x2] = k
for f in os.listdir(f"{s}/rgb"): cv2.imwrite(f"{d}/gt_masks/{f}", lab)
PYEOF
  i=$((i+1)); done
mkdir -p $UOIS/DATA && ln -sfn $HP $UOIS/DATA/iTeach-HumanPlay
echo "== 1. README data check: cd lib && python test_data.py"
(cd $MSM/lib && python test_data.py) > $LOG/test_data.log 2>&1 && tail -2 $LOG/test_data.log || { echo "FAIL"; tail -5 $LOG/test_data.log; }
# 2. training (README command, 30-iteration copy of the config)
sed -e 's/^  MAX_ITER: .*/  MAX_ITER: 30/' -e 's/^  CHECKPOINT_PERIOD: .*/  CHECKPOINT_PERIOD: 100000/' -e 's/TRAIN: ("mixture_object_train",)/TRAIN: ("humanplay_object_train",)/' $MSM/MSMFormer/configs/humanplay_RGBD.yaml > $MSM/MSMFormer/configs/_sil_tmp.yaml
echo "== 2. training: python iteach_train_net_pretrained.py --num-gpus 1 ... --out_dir sil_run"
(cd $MSM/MSMFormer && timeout 900 python iteach_train_net_pretrained.py --num-gpus 1 --dist-url tcp://127.0.0.1:12345 --cfg $MSM/MSMFormer/configs/_sil_tmp.yaml --out_dir sil_run) > $LOG/train.log 2>&1
grep -q "CUDA out of memory" $LOG/train.log && echo "  training: CUDA out of memory on this 16 GB GPU (expected here); config.yaml written: $([ -f $MSM/MSMFormer/sil_run/config.yaml ] && echo yes || echo no)"
[ -f $MSM/MSMFormer/sil_run/model_final.pth ] || ln -s $MSM/data/checkpoints/rgbd_pretrain/norm_RGBD_pretrained.pth $MSM/MSMFormer/sil_run/model_final.pth
echo "  stand-in: MSMFormer/sil_run/model_final.pth -> pretrained norm_RGBD_pretrained.pth"
ls $MSM/MSMFormer/sil_run/model_final.pth $MSM/MSMFormer/sil_run/config.yaml 2>&1 | sed 's#.*/MSMFormer/#  MSMFormer/#'; grep -m1 -E "Loading from|Checkpoint .* not found|weights" $LOG/train.log | cut -c1-150; grep -E "^[A-Za-z]*Error" $LOG/train.log | tail -2
# 3. evaluation (README command)
echo "== 3. evaluation: cd lib/fcn && python iteach_test_dataset.py sil_run"
(cd $MSM/lib/fcn && timeout 900 python iteach_test_dataset.py sil_run) > $LOG/eval.log 2>&1; ls $MSM/MSMFormer/sil_run/model_results/results.json 2>&1 | sed 's#.*/MSMFormer/#  MSMFormer/#'; grep -E "^[A-Za-z]*Error" $LOG/eval.log | tail -2
echo "== 4. combined score"
(cd $MSM/lib/fcn && python combined_score.py ../../MSMFormer/sil_run/model_results/results.json) 2>&1 | grep -A2 "ITEACH-UOIS"
# 5. serve the fine-tuned model with MODEL/MODEL_CFG and wait for a prediction
echo "== 5. live node with MODEL=MSMFormer/sil_run/model_final.pth MODEL_CFG=MSMFormer/sil_run/config.yaml"
setsid bash -c "conda activate hololens-pc; $ROSENV; roscore" > $LOG/roscore.log 2>&1 & PIDS+=($!); sleep 6
setsid bash -c "source ~/miniconda3/etc/profile.d/conda.sh; conda activate hololens-pc; $ROSENV; python $SIL/fake_fetch.py $CAP/$(ls $CAP | head -1)" > $LOG/fake_fetch.log 2>&1 & PIDS+=($!)
setsid bash -c "source ~/miniconda3/etc/profile.d/conda.sh; conda activate msm39; $ROSENV; export PYTHONPATH=/tmp/claude-1001/-home-hololens/565c7f0a-b409-45f5-b133-3524a16716df/scratchpad/st59:$PYTHONPATH; cd $MSM; MODEL=MSMFormer/sil_run/model_final.pth MODEL_CFG=MSMFormer/sil_run/config.yaml ./experiments/scripts/ros_seg_transformer_test_segmentation_fetch.sh 0 sil_ft" > $LOG/node_ft.log 2>&1 & PIDS+=($!)
bash -c "$ROSENV; timeout 240 rostopic echo -n 1 /seg_image_refined/header" > $LOG/pred_ft.log 2>&1 && echo "OK   fine-tuned model is serving predictions" || { echo "FAIL no prediction"; grep -E "^[A-Za-z]*Error" $LOG/node_ft.log | tail -2; }
grep -m1 -oE "\-\-pretrained [^ ]+" $LOG/node_ft.log
