//Do not edit! This file was generated by Unity-ROS MessageGeneration.
using System;
using System.Linq;
using System.Collections.Generic;
using System.Text;
using Unity.Robotics.ROSTCPConnector.MessageGeneration;

namespace RosMessageTypes.Actionlib
{
    [Serializable]
    public class GoalStatusArrayMsg : Message
    {
        public const string k_RosMessageName = "actionlib_msgs/GoalStatusArray";
        public override string RosMessageName => k_RosMessageName;

        //  Stores the statuses for goals that are currently being tracked
        //  by an action server
        public Std.HeaderMsg header;
        public GoalStatusMsg[] status_list;

        public GoalStatusArrayMsg()
        {
            this.header = new Std.HeaderMsg();
            this.status_list = new GoalStatusMsg[0];
        }

        public GoalStatusArrayMsg(Std.HeaderMsg header, GoalStatusMsg[] status_list)
        {
            this.header = header;
            this.status_list = status_list;
        }

        public static GoalStatusArrayMsg Deserialize(MessageDeserializer deserializer) => new GoalStatusArrayMsg(deserializer);

        private GoalStatusArrayMsg(MessageDeserializer deserializer)
        {
            this.header = Std.HeaderMsg.Deserialize(deserializer);
            deserializer.Read(out this.status_list, GoalStatusMsg.Deserialize, deserializer.ReadLength());
        }

        public override void SerializeTo(MessageSerializer serializer)
        {
            serializer.Write(this.header);
            serializer.WriteLength(this.status_list);
            serializer.Write(this.status_list);
        }

        public override string ToString()
        {
            return "GoalStatusArrayMsg: " +
            "\nheader: " + header.ToString() +
            "\nstatus_list: " + System.String.Join(", ", status_list.ToList());
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
