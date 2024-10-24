//Do not edit! This file was generated by Unity-ROS MessageGeneration.
using System;
using System.Linq;
using System.Collections.Generic;
using System.Text;
using Unity.Robotics.ROSTCPConnector.MessageGeneration;

namespace RosMessageTypes.Nav
{
    [Serializable]
    public class SetMapResponse : Message
    {
        public const string k_RosMessageName = "nav_msgs/SetMap";
        public override string RosMessageName => k_RosMessageName;

        //  True if the map was successfully set, false otherwise.
        public bool success;

        public SetMapResponse()
        {
            this.success = false;
        }

        public SetMapResponse(bool success)
        {
            this.success = success;
        }

        public static SetMapResponse Deserialize(MessageDeserializer deserializer) => new SetMapResponse(deserializer);

        private SetMapResponse(MessageDeserializer deserializer)
        {
            deserializer.Read(out this.success);
        }

        public override void SerializeTo(MessageSerializer serializer)
        {
            serializer.Write(this.success);
        }

        public override string ToString()
        {
            return "SetMapResponse: " +
            "\nsuccess: " + success.ToString();
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
