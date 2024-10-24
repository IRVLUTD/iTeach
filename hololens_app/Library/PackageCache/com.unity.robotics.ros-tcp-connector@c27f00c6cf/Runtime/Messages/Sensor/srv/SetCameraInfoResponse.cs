//Do not edit! This file was generated by Unity-ROS MessageGeneration.
using System;
using System.Linq;
using System.Collections.Generic;
using System.Text;
using Unity.Robotics.ROSTCPConnector.MessageGeneration;

namespace RosMessageTypes.Sensor
{
    [Serializable]
    public class SetCameraInfoResponse : Message
    {
        public const string k_RosMessageName = "sensor_msgs/SetCameraInfo";
        public override string RosMessageName => k_RosMessageName;

        public bool success;
        //  True if the call succeeded
        public string status_message;
        //  Used to give details about success

        public SetCameraInfoResponse()
        {
            this.success = false;
            this.status_message = "";
        }

        public SetCameraInfoResponse(bool success, string status_message)
        {
            this.success = success;
            this.status_message = status_message;
        }

        public static SetCameraInfoResponse Deserialize(MessageDeserializer deserializer) => new SetCameraInfoResponse(deserializer);

        private SetCameraInfoResponse(MessageDeserializer deserializer)
        {
            deserializer.Read(out this.success);
            deserializer.Read(out this.status_message);
        }

        public override void SerializeTo(MessageSerializer serializer)
        {
            serializer.Write(this.success);
            serializer.Write(this.status_message);
        }

        public override string ToString()
        {
            return "SetCameraInfoResponse: " +
            "\nsuccess: " + success.ToString() +
            "\nstatus_message: " + status_message.ToString();
        }

#if UNITY_EDITOR
        [UnityEditor.InitializeOnLoadMethod]
#else
        [UnityEngine.RuntimeInitializeOnLoadMethod]
#endif
        public static void Register()
        {
            MessageRegistry.Register(k_RosMessageName, Deserialize, MessageSubtopic.Response);
        }
    }
}
