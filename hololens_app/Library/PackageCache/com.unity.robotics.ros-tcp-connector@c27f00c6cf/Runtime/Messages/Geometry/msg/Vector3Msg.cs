//Do not edit! This file was generated by Unity-ROS MessageGeneration.
using System;
using System.Linq;
using System.Collections.Generic;
using System.Text;
using Unity.Robotics.ROSTCPConnector.MessageGeneration;

namespace RosMessageTypes.Geometry
{
    [Serializable]
    public class Vector3Msg : Message
    {
        public const string k_RosMessageName = "geometry_msgs/Vector3";
        public override string RosMessageName => k_RosMessageName;

        //  This represents a vector in free space.
        //  This is semantically different than a point.
        //  A vector is always anchored at the origin.
        //  When a transform is applied to a vector, only the rotational component is applied.
        public double x;
        public double y;
        public double z;

        public Vector3Msg()
        {
            this.x = 0.0;
            this.y = 0.0;
            this.z = 0.0;
        }

        public Vector3Msg(double x, double y, double z)
        {
            this.x = x;
            this.y = y;
            this.z = z;
        }

        public static Vector3Msg Deserialize(MessageDeserializer deserializer) => new Vector3Msg(deserializer);

        private Vector3Msg(MessageDeserializer deserializer)
        {
            deserializer.Read(out this.x);
            deserializer.Read(out this.y);
            deserializer.Read(out this.z);
        }

        public override void SerializeTo(MessageSerializer serializer)
        {
            serializer.Write(this.x);
            serializer.Write(this.y);
            serializer.Write(this.z);
        }

        public override string ToString()
        {
            return "Vector3Msg: " +
            "\nx: " + x.ToString() +
            "\ny: " + y.ToString() +
            "\nz: " + z.ToString();
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
