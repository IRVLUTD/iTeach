#!/bin/bash
# Laptop-side software-in-the-loop run of the README's live system.
SIL=/tmp/claude-1001/-home-hololens/565c7f0a-b409-45f5-b133-3524a16716df/scratchpad/sil
REPO=/home/<user>/Projects/iteach-final-code-to-github
MSM=$REPO/iTeach-UOIS/uois-models/UnseenObjectsWithMeanShift
APP=$REPO/iTeachSkillsApp
SCENE=/home/<user>/Projects/iteachSkillsApp/Python/_data_captured.og.iteach-uois/scene_0423T124209
LOG=$SIL/logs; rm -rf $LOG; mkdir -p $LOG
ROSENV='source /opt/ros/noetic/setup.bash; export ROS_MASTER_URI=http://localhost:11311 ROS_IP=127.0.0.1; unset ROS_HOSTNAME'
CONDA='source ~/miniconda3/etc/profile.d/conda.sh'
PIDS=()
start() { setsid bash -c "$CONDA; conda activate $2; $ROSENV; cd $3; $4" > $LOG/$1.log 2>&1 & PIDS+=($!); }
cleanup() {
  for p in "${PIDS[@]}"; do kill -TERM -- -$p 2>/dev/null; done; sleep 2
  for p in "${PIDS[@]}"; do kill -KILL -- -$p 2>/dev/null; done
  rm -f $APP/sam2_l.pt   # temporary link only
}
trap cleanup EXIT
# temporary links to existing weights (no copies, no downloads)
# model checkpoints: links created by the real set_env.sh
ln -sfn /home/<user>/Projects/iteachSkillsApp/sam2_l.pt $APP/sam2_l.pt
rm -rf $APP/Python/data_captured

start roscore      hololens-pc $SIL "roscore"
sleep 6
start fake_fetch   hololens-pc $SIL "python fake_fetch.py $SCENE"
start t1_msmformer msm39       $MSM "./experiments/scripts/ros_seg_transformer_test_segmentation_fetch.sh 0 siltest"
start t2_compress  hololens-pc $APP/Python "python sub_compress_pub.py"
start t3_recorder  hololens-pc $APP "python Python/image_publisher_fetch.py"

# wait for the model to come up (first /seg_image_refined)
bash -c "$ROSENV; timeout 240 rostopic echo -n 1 /seg_image_refined/header" > $LOG/first_pred.log 2>&1 && echo "OK   first prediction received" || echo "FAIL no prediction within 240 s (see t1_msmformer.log)"
bash -c "$ROSENV; for t in /head_camera/rgb/image_raw /head_camera/depth_registered/image_raw /seg_image_refined /hololens_stream/compressed; do echo \$t; timeout 12 rostopic hz \$t 2>&1 | grep -m1 'average rate' || echo '  no messages'; done" > $LOG/rates.log 2>&1
cat $LOG/rates.log
nvidia-smi --query-gpu=memory.used,memory.total --format=csv,noheader | sed 's/^/GPU memory used\/total (MSMFormer + SAM2 loaded): /'
bash -c "$CONDA; conda activate hololens-pc; $ROSENV; cd $SIL; timeout 240 python fake_hololens.py $SCENE/prompts.json" 2>&1 | grep -E "OK|FAIL|summary_info"
nvidia-smi --query-gpu=memory.used --format=csv,noheader | sed 's/^/GPU memory used after SAM2 labelling: /'
echo "== captured scenes"; for s in $APP/Python/data_captured/scene_*; do [ -d "$s" ] && echo "$(basename $s): rgb=$(ls $s/rgb 2>/dev/null | wc -l) depth=$(ls $s/depth 2>/dev/null | wc -l) prompts.json=$([ -f $s/prompts.json ] && echo yes || echo no) previews=$(ls $s/usr_annotation_viz 2>/dev/null | wc -l)"; done
