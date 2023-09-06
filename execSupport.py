import rospy
import receiveData
import rebroadcastData

if __name__ == "__main__":
    rospy.init_node("HololensImageSupport")
    imgsub = receiveData.ImageSubscriber(False)
    print("Subscriber online")
    imgreb = rebroadcastData.ImageRebradcaster(False)
    print("Rebroadcaster online")
    try:
        rospy.spin()
    except KeyboardInterrupt:
        print("Exiting")
