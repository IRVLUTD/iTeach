import rospy
import receiveData
import rebroadcastData
import fetchdetect

if __name__ == "__main__":
    rospy.init_node("HololensImageSupport")
    imgbro = fetchdetect.ros_image_reader(
        data="doordetect.yaml",
        weights = "Model/weights/last.pt",
        nosave = True,
        send_ros = True,
        conf_thres=0.25,
        iou_thres=0.45
    )

    imgpro = fetchdetect.ros_image_reader(weights="Model/weights/last.pt", source="data/doordetect.yaml")
    print("Publisher online")
    imgsub = receiveData.ImageSubscriber(False)
    print("Subscriber online")
    imgreb = rebroadcastData.ImageRebradcaster(False)
    print("Rebroadcaster online")
    try:
        rospy.spin()
    except KeyboardInterrupt:
        print("Exiting")
