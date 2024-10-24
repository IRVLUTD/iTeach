//Do not edit! This file was generated by Unity-ROS MessageGeneration.
using System;
using System.Linq;
using System.Collections.Generic;
using System.Text;
using Unity.Robotics.ROSTCPConnector.MessageGeneration;

namespace RosMessageTypes.Sensor
{
    [Serializable]
    public class MultiDOFJointStateMsg : Message
    {
        public const string k_RosMessageName = "sensor_msgs/MultiDOFJointState";
        public override string RosMessageName => k_RosMessageName;

        //  Representation of state for joints with multiple degrees of freedom,
        //  following the structure of JointState which can only represent a single degree of freedom.
        // 
        //  It is assumed that a joint in a system corresponds to a transform that gets applied
        //  along the kinematic chain. For example, a planar joint (as in URDF) is 3DOF (x, y, yaw)
        //  and those 3DOF can be expressed as a transformation matrix, and that transformation
        //  matrix can be converted back to (x, y, yaw)
        // 
        //  Each joint is uniquely identified by its name
        //  The header specifies the time at which the joint states were recorded. All the joint states
        //  in one message have to be recorded at the same time.
        // 
        //  This message consists of a multiple arrays, one for each part of the joint state.
        //  The goal is to make each of the fields optional. When e.g. your joints have no
        //  wrench associated with them, you can leave the wrench array empty.
        // 
        //  All arrays in this message should have the same size, or be empty.
        //  This is the only way to uniquely associate the joint name with the correct
        //  states.
        public Std.HeaderMsg header;
        public string[] joint_names;
        public Geometry.TransformMsg[] transforms;
        public Geometry.TwistMsg[] twist;
        public Geometry.WrenchMsg[] wrench;

        public MultiDOFJointStateMsg()
        {
            this.header = new Std.HeaderMsg();
            this.joint_names = new string[0];
            this.transforms = new Geometry.TransformMsg[0];
            this.twist = new Geometry.TwistMsg[0];
            this.wrench = new Geometry.WrenchMsg[0];
        }

        public MultiDOFJointStateMsg(Std.HeaderMsg header, string[] joint_names, Geometry.TransformMsg[] transforms, Geometry.TwistMsg[] twist, Geometry.WrenchMsg[] wrench)
        {
            this.header = header;
            this.joint_names = joint_names;
            this.transforms = transforms;
            this.twist = twist;
            this.wrench = wrench;
        }

        public static MultiDOFJointStateMsg Deserialize(MessageDeserializer deserializer) => new MultiDOFJointStateMsg(deserializer);

        private MultiDOFJointStateMsg(MessageDeserializer deserializer)
        {
            this.header = Std.HeaderMsg.Deserialize(deserializer);
            deserializer.Read(out this.joint_names, deserializer.ReadLength());
            deserializer.Read(out this.transforms, Geometry.TransformMsg.Deserialize, deserializer.ReadLength());
            deserializer.Read(out this.twist, Geometry.TwistMsg.Deserialize, deserializer.ReadLength());
            deserializer.Read(out this.wrench, Geometry.WrenchMsg.Deserialize, deserializer.ReadLength());
        }

        public override void SerializeTo(MessageSerializer serializer)
        {
            serializer.Write(this.header);
            serializer.WriteLength(this.joint_names);
            serializer.Write(this.joint_names);
            serializer.WriteLength(this.transforms);
            serializer.Write(this.transforms);
            serializer.WriteLength(this.twist);
            serializer.Write(this.twist);
            serializer.WriteLength(this.wrench);
            serializer.Write(this.wrench);
        }

        public override string ToString()
        {
            return "MultiDOFJointStateMsg: " +
            "\nheader: " + header.ToString() +
            "\njoint_names: " + System.String.Join(", ", joint_names.ToList()) +
            "\ntransforms: " + System.String.Join(", ", transforms.ToList()) +
            "\ntwist: " + System.String.Join(", ", twist.ToList()) +
            "\nwrench: " + System.String.Join(", ", wrench.ToList());
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
