//Do not edit! This file was generated by Unity-ROS MessageGeneration.
using System;
using System.Linq;
using System.Collections.Generic;
using System.Text;
using Unity.Robotics.ROSTCPConnector.MessageGeneration;

namespace RosMessageTypes.Visualization
{
    [Serializable]
    public class MarkerMsg : Message
    {
        public const string k_RosMessageName = "visualization_msgs/Marker";
        public override string RosMessageName => k_RosMessageName;

        //  See:
        //   - http://www.ros.org/wiki/rviz/DisplayTypes/Marker
        //   - http://www.ros.org/wiki/rviz/Tutorials/Markers%3A%20Basic%20Shapes
        // 
        //  for more information on using this message with rviz.
        public const int ARROW = 0;
        public const int CUBE = 1;
        public const int SPHERE = 2;
        public const int CYLINDER = 3;
        public const int LINE_STRIP = 4;
        public const int LINE_LIST = 5;
        public const int CUBE_LIST = 6;
        public const int SPHERE_LIST = 7;
        public const int POINTS = 8;
        public const int TEXT_VIEW_FACING = 9;
        public const int MESH_RESOURCE = 10;
        public const int TRIANGLE_LIST = 11;
        public const int ADD = 0;
        public const int MODIFY = 0;
        public const int DELETE = 2;
        public const int DELETEALL = 3;
        //  Header for timestamp and frame id.
        public Std.HeaderMsg header;
        //  Namespace in which to place the object.
        //  Used in conjunction with id to create a unique name for the object.
        public string ns;
        //  Object ID used in conjunction with the namespace for manipulating and deleting the object later.
        public int id;
        //  Type of object.
        public int type;
        //  Action to take; one of:
        //   - 0 add/modify an object
        //   - 1 (deprecated)
        //   - 2 deletes an object
        //   - 3 deletes all objects
        public int action;
        //  Pose of the object with respect the frame_id specified in the header.
        public Geometry.PoseMsg pose;
        //  Scale of the object; 1,1,1 means default (usually 1 meter square).
        public Geometry.Vector3Msg scale;
        //  Color of the object; in the range: [0.0-1.0]
        public Std.ColorRGBAMsg color;
        //  How long the object should last before being automatically deleted.
        //  0 indicates forever.
        public BuiltinInterfaces.DurationMsg lifetime;
        //  If this marker should be frame-locked, i.e. retransformed into its frame every timestep.
        public bool frame_locked;
        //  Only used if the type specified has some use for them (eg. POINTS, LINE_STRIP, etc.)
        public Geometry.PointMsg[] points;
        //  Only used if the type specified has some use for them (eg. POINTS, LINE_STRIP, etc.)
        //  The number of colors provided must either be 0 or equal to the number of points provided.
        //  NOTE: alpha is not yet used
        public Std.ColorRGBAMsg[] colors;
        //  Only used for text markers
        public string text;
        //  Only used for MESH_RESOURCE markers.
        public string mesh_resource;
        public bool mesh_use_embedded_materials;

        public MarkerMsg()
        {
            this.header = new Std.HeaderMsg();
            this.ns = "";
            this.id = 0;
            this.type = 0;
            this.action = 0;
            this.pose = new Geometry.PoseMsg();
            this.scale = new Geometry.Vector3Msg();
            this.color = new Std.ColorRGBAMsg();
            this.lifetime = new BuiltinInterfaces.DurationMsg();
            this.frame_locked = false;
            this.points = new Geometry.PointMsg[0];
            this.colors = new Std.ColorRGBAMsg[0];
            this.text = "";
            this.mesh_resource = "";
            this.mesh_use_embedded_materials = false;
        }

        public MarkerMsg(Std.HeaderMsg header, string ns, int id, int type, int action, Geometry.PoseMsg pose, Geometry.Vector3Msg scale, Std.ColorRGBAMsg color, BuiltinInterfaces.DurationMsg lifetime, bool frame_locked, Geometry.PointMsg[] points, Std.ColorRGBAMsg[] colors, string text, string mesh_resource, bool mesh_use_embedded_materials)
        {
            this.header = header;
            this.ns = ns;
            this.id = id;
            this.type = type;
            this.action = action;
            this.pose = pose;
            this.scale = scale;
            this.color = color;
            this.lifetime = lifetime;
            this.frame_locked = frame_locked;
            this.points = points;
            this.colors = colors;
            this.text = text;
            this.mesh_resource = mesh_resource;
            this.mesh_use_embedded_materials = mesh_use_embedded_materials;
        }

        public static MarkerMsg Deserialize(MessageDeserializer deserializer) => new MarkerMsg(deserializer);

        private MarkerMsg(MessageDeserializer deserializer)
        {
            this.header = Std.HeaderMsg.Deserialize(deserializer);
            deserializer.Read(out this.ns);
            deserializer.Read(out this.id);
            deserializer.Read(out this.type);
            deserializer.Read(out this.action);
            this.pose = Geometry.PoseMsg.Deserialize(deserializer);
            this.scale = Geometry.Vector3Msg.Deserialize(deserializer);
            this.color = Std.ColorRGBAMsg.Deserialize(deserializer);
            this.lifetime = BuiltinInterfaces.DurationMsg.Deserialize(deserializer);
            deserializer.Read(out this.frame_locked);
            deserializer.Read(out this.points, Geometry.PointMsg.Deserialize, deserializer.ReadLength());
            deserializer.Read(out this.colors, Std.ColorRGBAMsg.Deserialize, deserializer.ReadLength());
            deserializer.Read(out this.text);
            deserializer.Read(out this.mesh_resource);
            deserializer.Read(out this.mesh_use_embedded_materials);
        }

        public override void SerializeTo(MessageSerializer serializer)
        {
            serializer.Write(this.header);
            serializer.Write(this.ns);
            serializer.Write(this.id);
            serializer.Write(this.type);
            serializer.Write(this.action);
            serializer.Write(this.pose);
            serializer.Write(this.scale);
            serializer.Write(this.color);
            serializer.Write(this.lifetime);
            serializer.Write(this.frame_locked);
            serializer.WriteLength(this.points);
            serializer.Write(this.points);
            serializer.WriteLength(this.colors);
            serializer.Write(this.colors);
            serializer.Write(this.text);
            serializer.Write(this.mesh_resource);
            serializer.Write(this.mesh_use_embedded_materials);
        }

        public override string ToString()
        {
            return "MarkerMsg: " +
            "\nheader: " + header.ToString() +
            "\nns: " + ns.ToString() +
            "\nid: " + id.ToString() +
            "\ntype: " + type.ToString() +
            "\naction: " + action.ToString() +
            "\npose: " + pose.ToString() +
            "\nscale: " + scale.ToString() +
            "\ncolor: " + color.ToString() +
            "\nlifetime: " + lifetime.ToString() +
            "\nframe_locked: " + frame_locked.ToString() +
            "\npoints: " + System.String.Join(", ", points.ToList()) +
            "\ncolors: " + System.String.Join(", ", colors.ToList()) +
            "\ntext: " + text.ToString() +
            "\nmesh_resource: " + mesh_resource.ToString() +
            "\nmesh_use_embedded_materials: " + mesh_use_embedded_materials.ToString();
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
