import rospy
import logging
import argparse
import iTeach.finetune as finetune
import iTeach.fetchdetect as fetchdetect
import iTeach.receiveData as receiveData
import iTeach.rebroadcastData as rebroadcastData


#  Set up logging
logging.basicConfig(level=logging.INFO)
logger = logging.getLogger(__name__)

def parse_opt():
    parser = argparse.ArgumentParser()
    parser.add_argument('--config', type=str, default='cfg.yml', help='config file path', required=True)
    return parser.parse_args()


if __name__ == "__main__":
    logging.info("Init setup...")
    rospy.init_node("YOLOFinetuningNode")

    args = parse_opt()
    dh_model = finetune.DoorHandleModelFinetuner(args.config)
    logging.info(f"Resume option is {'ON' if dh_model._cfg.RESUME else 'OFF'}")

    conf_thres = dh_model._cfg.CONF_THRES if dh_model._cfg.CONF_THRES else 0.7
    iou_thres = dh_model._cfg.IOU_THRES if dh_model._cfg.IOU_THRES else 0.7        

    # do yolo predictions on the incoming fetch pov image
    img_broadcaster = fetchdetect.ros_image_reader(
        data=dh_model.cfg_path,
        weights = dh_model.model_ckpt,
        nosave = True,
        send_ros = True,
        conf_thres = conf_thres,
        iou_thres = iou_thres
    )

    logging.info("DoorHandle detector online...")

    # reboradcast with a lower frequency
    img_rebroadcaster = rebroadcastData.ImageRebroadcaster(False)
    logging.info("Rebroadcaster online...")

    # here only do subscription from hololens
    # get the labelled samples and save
    # trigger finetuning when received true from /hololens/out/finetune_signal
    imgsub = receiveData.HololensUserDataSubscriber(dh_model, False)
    logging.info("Hololens user data subscriber online...")


    try:
        rospy.spin()
    except KeyboardInterrupt:
        logging.error("Exiting...")
