//Do not edit! This file was generated by Unity-ROS MessageGeneration.
using System;
using System.Linq;
using System.Collections.Generic;
using System.Text;
using Unity.Robotics.ROSTCPConnector.MessageGeneration;

namespace RosMessageTypes.Nav
{
    [Serializable]
    public class GetMapFeedback : Message
    {
        public const string k_RosMessageName = "nav_msgs/GetMap";
        public override string RosMessageName => k_RosMessageName;

        //  no feedback

        public GetMapFeedback()
        {
        }
        public static GetMapFeedback Deserialize(MessageDeserializer deserializer) => new GetMapFeedback(deserializer);

        private GetMapFeedback(MessageDeserializer deserializer)
        {
        }

        public override void SerializeTo(MessageSerializer serializer)
        {
        }

        public override string ToString()
        {
            return "GetMapFeedback: ";
        }

#if UNITY_EDITOR
        [UnityEditor.InitializeOnLoadMethod]
#else
        [UnityEngine.RuntimeInitializeOnLoadMethod]
#endif
        public static void Register()
        {
            MessageRegistry.Register(k_RosMessageName, Deserialize, MessageSubtopic.Feedback);
        }
    }
}
