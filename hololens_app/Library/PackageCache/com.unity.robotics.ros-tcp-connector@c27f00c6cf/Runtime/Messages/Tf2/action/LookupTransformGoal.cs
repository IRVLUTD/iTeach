//Do not edit! This file was generated by Unity-ROS MessageGeneration.
using System;
using System.Linq;
using System.Collections.Generic;
using System.Text;
using Unity.Robotics.ROSTCPConnector.MessageGeneration;
using RosMessageTypes.BuiltinInterfaces;

namespace RosMessageTypes.Tf2
{
    [Serializable]
    public class LookupTransformGoal : Message
    {
        public const string k_RosMessageName = "tf2_msgs/LookupTransform";
        public override string RosMessageName => k_RosMessageName;

        // Simple API
        public string target_frame;
        public string source_frame;
        public TimeMsg source_time;
        public DurationMsg timeout;
        // Advanced API
        public TimeMsg target_time;
        public string fixed_frame;
        // Whether or not to use the advanced API
        public bool advanced;

        public LookupTransformGoal()
        {
            this.target_frame = "";
            this.source_frame = "";
            this.source_time = new TimeMsg();
            this.timeout = new DurationMsg();
            this.target_time = new TimeMsg();
            this.fixed_frame = "";
            this.advanced = false;
        }

        public LookupTransformGoal(string target_frame, string source_frame, TimeMsg source_time, DurationMsg timeout, TimeMsg target_time, string fixed_frame, bool advanced)
        {
            this.target_frame = target_frame;
            this.source_frame = source_frame;
            this.source_time = source_time;
            this.timeout = timeout;
            this.target_time = target_time;
            this.fixed_frame = fixed_frame;
            this.advanced = advanced;
        }

        public static LookupTransformGoal Deserialize(MessageDeserializer deserializer) => new LookupTransformGoal(deserializer);

        private LookupTransformGoal(MessageDeserializer deserializer)
        {
            deserializer.Read(out this.target_frame);
            deserializer.Read(out this.source_frame);
            this.source_time = TimeMsg.Deserialize(deserializer);
            this.timeout = DurationMsg.Deserialize(deserializer);
            this.target_time = TimeMsg.Deserialize(deserializer);
            deserializer.Read(out this.fixed_frame);
            deserializer.Read(out this.advanced);
        }

        public override void SerializeTo(MessageSerializer serializer)
        {
            serializer.Write(this.target_frame);
            serializer.Write(this.source_frame);
            serializer.Write(this.source_time);
            serializer.Write(this.timeout);
            serializer.Write(this.target_time);
            serializer.Write(this.fixed_frame);
            serializer.Write(this.advanced);
        }

        public override string ToString()
        {
            return "LookupTransformGoal: " +
            "\ntarget_frame: " + target_frame.ToString() +
            "\nsource_frame: " + source_frame.ToString() +
            "\nsource_time: " + source_time.ToString() +
            "\ntimeout: " + timeout.ToString() +
            "\ntarget_time: " + target_time.ToString() +
            "\nfixed_frame: " + fixed_frame.ToString() +
            "\nadvanced: " + advanced.ToString();
        }

#if UNITY_EDITOR
        [UnityEditor.InitializeOnLoadMethod]
#else
        [UnityEngine.RuntimeInitializeOnLoadMethod]
#endif
        public static void Register()
        {
            MessageRegistry.Register(k_RosMessageName, Deserialize, MessageSubtopic.Goal);
        }
    }
}
