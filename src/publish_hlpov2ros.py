import os
from hololens_utils import HoloRosPublisher


if __name__ == "__main__":
    # Read the IP address from environment variable
    host_ip = os.getenv("HOLO_DEVICE_IP")

    if not host_ip:
        raise ValueError("The environment variable 'HOLO_DEVICE_IP' is not set. Please set the environment variable and try again.")

    print(f"Read HoloLens IP: {host_ip} from ENV")

    # Define configuration options
    enable_pv = True
    pv_res = "720P"
    enable_depth = False
    debug = True

    # Initialize and run the publisher
    publisher = HoloRosPublisher(
        host=host_ip,
        enable_pv=enable_pv,
        pv_res=pv_res,
        enable_depth=enable_depth,
        debug=debug
    )
    
    publisher.run()
