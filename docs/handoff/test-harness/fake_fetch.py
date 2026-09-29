#!/usr/bin/env python
"""Replay a recorded scene as the Fetch head-camera topics (for a laptop-only test)."""
import sys, os, glob, cv2, numpy as np, rospy, ros_numpy, tf2_ros
from sensor_msgs.msg import Image, CameraInfo
from geometry_msgs.msg import TransformStamped
scene = sys.argv[1]
rgbs = sorted(glob.glob(os.path.join(scene, "rgb", "*.png")))
rospy.init_node("fake_fetch")
p_rgb = rospy.Publisher("/head_camera/rgb/image_raw", Image, queue_size=2)
p_dep = rospy.Publisher("/head_camera/depth_registered/image_raw", Image, queue_size=2)
p_info = rospy.Publisher("/head_camera/rgb/camera_info", CameraInfo, queue_size=2, latch=True)
br = tf2_ros.StaticTransformBroadcaster(); tfs = []
for child in ["head_camera_rgb_optical_frame", "laser_link"]:
    t = TransformStamped(); t.header.stamp = rospy.Time.now(); t.header.frame_id = "base_link"; t.child_frame_id = child
    t.transform.translation.z = 1.0; t.transform.rotation.w = 1.0; tfs.append(t)
br.sendTransform(tfs)
info = CameraInfo(); info.height, info.width = 480, 640
info.K = [554.25, 0, 320.5, 0, 554.25, 240.5, 0, 0, 1]; info.header.frame_id = "head_camera_rgb_optical_frame"
rate = rospy.Rate(15); i = 0
rospy.loginfo(f"fake_fetch: replaying {len(rgbs)} frames from {scene}")
while not rospy.is_shutdown():
    f = rgbs[i % len(rgbs)]; i += 1
    bgr = cv2.imread(f); dep = cv2.imread(f.replace("/rgb/", "/depth/"), cv2.IMREAD_ANYDEPTH)
    now = rospy.Time.now()
    m1 = ros_numpy.msgify(Image, np.ascontiguousarray(bgr[:, :, ::-1]), "rgb8")
    m2 = ros_numpy.msgify(Image, (dep.astype(np.float32) / 1000.0), "32FC1")   # Fetch publishes metres
    for m in (m1, m2): m.header.stamp = now; m.header.frame_id = "head_camera_rgb_optical_frame"
    info.header.stamp = now
    p_info.publish(info); p_rgb.publish(m1); p_dep.publish(m2)
    rate.sleep()
