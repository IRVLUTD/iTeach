import logging
from iteach_toolkit.DHYOLO import DHYOLODetector
from PIL import Image as PILImg

# Configure logging
logging.basicConfig(level=logging.INFO)
logger = logging.getLogger(__name__)

def main(model_path, image_path):
    """
    Main function to perform object detection using the DHYOLODetector.

    Args:
        model_path (str): Path to the YOLO model weights.
        image_path (str): Path to the image file to be processed.

    Returns:
        None
    """
    try:
        # Initialize the DHYOLODetector with the provided model path
        dhyolo = DHYOLODetector(model_path)

        # Perform prediction on the image
        orig_image, detections = dhyolo.predict(image_path)

        # Log the detections
        logger.info("Detections: %s", detections)

        # Plot the bounding boxes on the original image
        orig_image, image_with_bboxes = dhyolo.plot_bboxes(attach_watermark=True)

        # Convert the image (with bounding boxes) from a NumPy array to a PIL Image for display.
        pil_img_with_bboxes = PILImg.fromarray(image_with_bboxes)

        # Display the image with bounding boxes
        pil_img_with_bboxes.show()

    except FileNotFoundError as e:
        logger.error("File not found: %s", e)
    except Exception as e:
        logger.error("An error occurred: %s", e)

if __name__ == "__main__":
    # Define the model path and image path
    model_path = '/home/hololens/Projects/hololens/IRVLImageLabellingSupport/src/pretrained_ckpt.pt'  # Replace with the actual path to your model
    image_path = "./test_imgs/irvl-test.jpg"  # Replace with the actual path to the image you want to test

    # Call the main function
    main(model_path, image_path)
