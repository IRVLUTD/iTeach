#!/usr/bin/env python
"""Send the messages iTechDemo sends (record start/stop, gaze prompts) and check the replies."""
import sys, json, time, rospy
from std_msgs.msg import Bool, String
from sensor_msgs.msg import CompressedImage
prompts = json.load(open(sys.argv[1]))["prompts"]
rospy.init_node("fake_hololens")
rec = rospy.Publisher("/hololens/out/record_command", Bool, queue_size=1, latch=False)
pro = rospy.Publisher("/hololens/out/prompts", String, queue_size=1)
got = {"label": 0, "stream": 0, "summary": ""}
rospy.Subscriber("/head_camera/label_frame/image_raw/compressed", CompressedImage, lambda m: got.__setitem__("label", got["label"] + 1))
rospy.Subscriber("/hololens_stream/compressed", CompressedImage, lambda m: got.__setitem__("stream", got["stream"] + 1))
rospy.Subscriber("/hololens/out/summary_info", String, lambda m: got.__setitem__("summary", m.data))
def wait(cond, secs, what):
    t0 = time.time()
    while not cond() and time.time() - t0 < secs and not rospy.is_shutdown(): time.sleep(0.2)
    print(("OK   " if cond() else "FAIL ") + what, flush=True); return cond()
time.sleep(2)
wait(lambda: got["stream"] > 5, 120, "HoloLens video stream (/hololens_stream/compressed) is arriving")
for cap in range(2):
    rec.publish(Bool(True)); time.sleep(4); rec.publish(Bool(False))
    n0 = got["label"]
    wait(lambda: got["label"] > n0, 20, f"capture {cap+1}: last frame came back as label_frame")
    n1 = got["label"]
    pro.publish(String(json.dumps({"prompts": prompts})))
    wait(lambda: got["label"] > n1, 60, f"capture {cap+1}: SAM2 preview came back after Send Label")
    time.sleep(1.5)
print("summary_info:", got["summary"].replace("\n", " | "), flush=True)
