//Do not edit! This file was generated by Unity-ROS MessageGeneration.
using System;
using System.Linq;
using System.Collections.Generic;
using System.Text;
using Unity.Robotics.ROSTCPConnector.MessageGeneration;

namespace RosMessageTypes.Std
{
    [Serializable]
    public class ColorRGBAMsg : Message
    {
        public const string k_RosMessageName = "std_msgs/ColorRGBA";
        public override string RosMessageName => k_RosMessageName;

        public float r;
        public float g;
        public float b;
        public float a;

        public ColorRGBAMsg()
        {
            this.r = 0.0f;
            this.g = 0.0f;
            this.b = 0.0f;
            this.a = 0.0f;
        }

        public ColorRGBAMsg(float r, float g, float b, float a)
        {
            this.r = r;
            this.g = g;
            this.b = b;
            this.a = a;
        }

        public static ColorRGBAMsg Deserialize(MessageDeserializer deserializer) => new ColorRGBAMsg(deserializer);

        private ColorRGBAMsg(MessageDeserializer deserializer)
        {
            deserializer.Read(out this.r);
            deserializer.Read(out this.g);
            deserializer.Read(out this.b);
            deserializer.Read(out this.a);
        }

        public override void SerializeTo(MessageSerializer serializer)
        {
            serializer.Write(this.r);
            serializer.Write(this.g);
            serializer.Write(this.b);
            serializer.Write(this.a);
        }

        public override string ToString()
        {
            return "ColorRGBAMsg: " +
            "\nr: " + r.ToString() +
            "\ng: " + g.ToString() +
            "\nb: " + b.ToString() +
            "\na: " + a.ToString();
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
