//Do not edit! This file was generated by Unity-ROS MessageGeneration.
using System;
using System.Linq;
using System.Collections.Generic;
using System.Text;
using Unity.Robotics.ROSTCPConnector.MessageGeneration;

namespace RosMessageTypes.Nav
{
    [Serializable]
    public class GetPlanResponse : Message
    {
        public const string k_RosMessageName = "nav_msgs/GetPlan";
        public override string RosMessageName => k_RosMessageName;

        //  Array of poses from start to goal if one was successfully found.
        public PathMsg plan;

        public GetPlanResponse()
        {
            this.plan = new PathMsg();
        }

        public GetPlanResponse(PathMsg plan)
        {
            this.plan = plan;
        }

        public static GetPlanResponse Deserialize(MessageDeserializer deserializer) => new GetPlanResponse(deserializer);

        private GetPlanResponse(MessageDeserializer deserializer)
        {
            this.plan = PathMsg.Deserialize(deserializer);
        }

        public override void SerializeTo(MessageSerializer serializer)
        {
            serializer.Write(this.plan);
        }

        public override string ToString()
        {
            return "GetPlanResponse: " +
            "\nplan: " + plan.ToString();
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
