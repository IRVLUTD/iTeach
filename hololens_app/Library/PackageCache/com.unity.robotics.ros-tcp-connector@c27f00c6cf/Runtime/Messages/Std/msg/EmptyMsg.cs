//Do not edit! This file was generated by Unity-ROS MessageGeneration.
using System;
using System.Linq;
using System.Collections.Generic;
using System.Text;
using Unity.Robotics.ROSTCPConnector.MessageGeneration;

namespace RosMessageTypes.Std
{
    [Serializable]
    public class EmptyMsg : Message
    {
        public const string k_RosMessageName = "std_msgs/Empty";
        public override string RosMessageName => k_RosMessageName;


        public EmptyMsg()
        {
        }
        public static EmptyMsg Deserialize(MessageDeserializer deserializer) => new EmptyMsg(deserializer);

        private EmptyMsg(MessageDeserializer deserializer)
        {
        }

        public override void SerializeTo(MessageSerializer serializer)
        {
        }

        public override string ToString()
        {
            return "EmptyMsg: ";
        }

#if UNITY_EDITOR
        [UnityEditor.InitializeOnLoadMethod]
#else
        [UnityEngine.RuntimeInitializeOnLoadMethod]
#endif
        public static void Register()
        {
            MessageRegistry.Register(k_RosMessageName, Deserialize);
        }
    }
}
