//Do not edit! This file was generated by Unity-ROS MessageGeneration.
using System;
using System.Linq;
using System.Collections.Generic;
using System.Text;
using Unity.Robotics.ROSTCPConnector.MessageGeneration;

namespace RosMessageTypes.Std
{
    [Serializable]
    public class BoolMsg : Message
    {
        public const string k_RosMessageName = "std_msgs/Bool";
        public override string RosMessageName => k_RosMessageName;

        //  This was originally provided as an example message.
        //  It is deprecated as of Foxy
        //  It is recommended to create your own semantically meaningful message.
        //  However if you would like to continue using this please use the equivalent in example_msgs.
        public bool data;

        public BoolMsg()
        {
            this.data = false;
        }

        public BoolMsg(bool data)
        {
            this.data = data;
        }

        public static BoolMsg Deserialize(MessageDeserializer deserializer) => new BoolMsg(deserializer);

        private BoolMsg(MessageDeserializer deserializer)
        {
            deserializer.Read(out this.data);
        }

        public override void SerializeTo(MessageSerializer serializer)
        {
            serializer.Write(this.data);
        }

        public override string ToString()
        {
            return "BoolMsg: " +
            "\ndata: " + data.ToString();
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
