//Do not edit! This file was generated by Unity-ROS MessageGeneration.
using System;
using System.Linq;
using System.Collections.Generic;
using System.Text;
using Unity.Robotics.ROSTCPConnector.MessageGeneration;

namespace RosMessageTypes.Std
{
    [Serializable]
    public class Float64Msg : Message
    {
        public const string k_RosMessageName = "std_msgs/Float64";
        public override string RosMessageName => k_RosMessageName;

        //  This was originally provided as an example message.
        //  It is deprecated as of Foxy
        //  It is recommended to create your own semantically meaningful message.
        //  However if you would like to continue using this please use the equivalent in example_msgs.
        public double data;

        public Float64Msg()
        {
            this.data = 0.0;
        }

        public Float64Msg(double data)
        {
            this.data = data;
        }

        public static Float64Msg Deserialize(MessageDeserializer deserializer) => new Float64Msg(deserializer);

        private Float64Msg(MessageDeserializer deserializer)
        {
            deserializer.Read(out this.data);
        }

        public override void SerializeTo(MessageSerializer serializer)
        {
            serializer.Write(this.data);
        }

        public override string ToString()
        {
            return "Float64Msg: " +
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
