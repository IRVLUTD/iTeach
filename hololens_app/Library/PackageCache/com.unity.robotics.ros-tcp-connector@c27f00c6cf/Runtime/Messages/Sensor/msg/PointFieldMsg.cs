//Do not edit! This file was generated by Unity-ROS MessageGeneration.
using System;
using System.Linq;
using System.Collections.Generic;
using System.Text;
using Unity.Robotics.ROSTCPConnector.MessageGeneration;

namespace RosMessageTypes.Sensor
{
    [Serializable]
    public class PointFieldMsg : Message
    {
        public const string k_RosMessageName = "sensor_msgs/PointField";
        public override string RosMessageName => k_RosMessageName;

        //  This message holds the description of one point entry in the
        //  PointCloud2 message format.
        public const byte INT8 = 1;
        public const byte UINT8 = 2;
        public const byte INT16 = 3;
        public const byte UINT16 = 4;
        public const byte INT32 = 5;
        public const byte UINT32 = 6;
        public const byte FLOAT32 = 7;
        public const byte FLOAT64 = 8;
        //  Common PointField names are x, y, z, intensity, rgb, rgba
        public string name;
        //  Name of field
        public uint offset;
        //  Offset from start of point struct
        public byte datatype;
        //  Datatype enumeration, see above
        public uint count;
        //  How many elements in the field

        public PointFieldMsg()
        {
            this.name = "";
            this.offset = 0;
            this.datatype = 0;
            this.count = 0;
        }

        public PointFieldMsg(string name, uint offset, byte datatype, uint count)
        {
            this.name = name;
            this.offset = offset;
            this.datatype = datatype;
            this.count = count;
        }

        public static PointFieldMsg Deserialize(MessageDeserializer deserializer) => new PointFieldMsg(deserializer);

        private PointFieldMsg(MessageDeserializer deserializer)
        {
            deserializer.Read(out this.name);
            deserializer.Read(out this.offset);
            deserializer.Read(out this.datatype);
            deserializer.Read(out this.count);
        }

        public override void SerializeTo(MessageSerializer serializer)
        {
            serializer.Write(this.name);
            serializer.Write(this.offset);
            serializer.Write(this.datatype);
            serializer.Write(this.count);
        }

        public override string ToString()
        {
            return "PointFieldMsg: " +
            "\nname: " + name.ToString() +
            "\noffset: " + offset.ToString() +
            "\ndatatype: " + datatype.ToString() +
            "\ncount: " + count.ToString();
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
