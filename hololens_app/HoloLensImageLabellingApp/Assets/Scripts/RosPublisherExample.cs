using UnityEngine;
using Unity.Robotics.ROSTCPConnector;
using StrMsg = RosMessageTypes.Std.StringMsg;
using ImgMsg = RosMessageTypes.Sensor.ImageMsg;
using Header = RosMessageTypes.Std.HeaderMsg;
using TimeMsg = RosMessageTypes.BuiltinInterfaces.TimeMsg;

/// <summary>
/// 
/// </summary>
public class RosPublisherExample : MonoBehaviour
{
    ROSConnection ros;
    public string topicName = "pos_rot";

    // Publish the cube's position and rotation every N seconds
    public float publishMessageFrequency = 0.5f;
    //private uint seqnum = 0; // Sequence number for images

    // Used to determine how much time has elapsed since the last message was published
    private float timeElapsed;

    void Start()
    {
        // start the ROS connection
        ros = ROSConnection.GetOrCreateInstance();
        ros.RegisterPublisher<StrMsg>(topicName);
    }

    private void Update()
    {
        timeElapsed += Time.deltaTime;

        if (timeElapsed > publishMessageFrequency)
        {
            

            string msg = "Haha";
            StrMsg cubePos = new StrMsg(msg);


            // Finally send the message to server_endpoint.py running in ROS
            ros.Publish(topicName, cubePos);
            

            timeElapsed = 0;
        }
    }
}