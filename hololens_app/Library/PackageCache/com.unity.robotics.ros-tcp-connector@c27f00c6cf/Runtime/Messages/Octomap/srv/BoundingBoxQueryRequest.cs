//Do not edit! This file was generated by Unity-ROS MessageGeneration.
using System;
using System.Linq;
using System.Collections.Generic;
using System.Text;
using Unity.Robotics.ROSTCPConnector.MessageGeneration;

namespace RosMessageTypes.Octomap
{
    [Serializable]
    public class BoundingBoxQueryRequest : Message
    {
        public const string k_RosMessageName = "octomap_msgs-melodic-devel/BoundingBoxQuery";
        public override string RosMessageName => k_RosMessageName;

        //  Clear a region specified by a global axis-aligned bounding box in stored OctoMap
        //  minimum corner point of axis-aligned bounding box in global frame
        public Geometry.PointMsg min;
        //  maximum corner point of axis-aligned bounding box in global frame
        public Geometry.PointMsg max;

        public BoundingBoxQueryRequest()
        {
            this.min = new Geometry.PointMsg();
            this.max = new Geometry.PointMsg();
        }

        public BoundingBoxQueryRequest(Geometry.PointMsg min, Geometry.PointMsg max)
        {
            this.min = min;
            this.max = max;
        }

        public static BoundingBoxQueryRequest Deserialize(MessageDeserializer deserializer) => new BoundingBoxQueryRequest(deserializer);

        private BoundingBoxQueryRequest(MessageDeserializer deserializer)
        {
            this.min = Geometry.PointMsg.Deserialize(deserializer);
            this.max = Geometry.PointMsg.Deserialize(deserializer);
        }

        public override void SerializeTo(MessageSerializer serializer)
        {
            serializer.Write(this.min);
            serializer.Write(this.max);
        }

        public override string ToString()
        {
            return "BoundingBoxQueryRequest: " +
            "\nmin: " + min.ToString() +
            "\nmax: " + max.ToString();
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
