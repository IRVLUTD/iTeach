//Do not edit! This file was generated by Unity-ROS MessageGeneration.
using System;
using System.Linq;
using System.Collections.Generic;
using System.Text;
using Unity.Robotics.ROSTCPConnector.MessageGeneration;

namespace RosMessageTypes.Sensor
{
    [Serializable]
    public class MultiEchoLaserScanMsg : Message
    {
        public const string k_RosMessageName = "sensor_msgs/MultiEchoLaserScan";
        public override string RosMessageName => k_RosMessageName;

        //  Single scan from a multi-echo planar laser range-finder
        // 
        //  If you have another ranging device with different behavior (e.g. a sonar
        //  array), please find or create a different message, since applications
        //  will make fairly laser-specific assumptions about this data
        public Std.HeaderMsg header;
        //  timestamp in the header is the acquisition time of
        //  the first ray in the scan.
        // 
        //  in frame frame_id, angles are measured around
        //  the positive Z axis (counterclockwise, if Z is up)
        //  with zero angle being forward along the x axis
        public float angle_min;
        //  start angle of the scan [rad]
        public float angle_max;
        //  end angle of the scan [rad]
        public float angle_increment;
        //  angular distance between measurements [rad]
        public float time_increment;
        //  time between measurements [seconds] - if your scanner
        //  is moving, this will be used in interpolating position
        //  of 3d points
        public float scan_time;
        //  time between scans [seconds]
        public float range_min;
        //  minimum range value [m]
        public float range_max;
        //  maximum range value [m]
        public LaserEchoMsg[] ranges;
        //  range data [m]
        //  (Note: NaNs, values < range_min or > range_max should be discarded)
        //  +Inf measurements are out of range
        //  -Inf measurements are too close to determine exact distance.
        public LaserEchoMsg[] intensities;
        //  intensity data [device-specific units].  If your
        //  device does not provide intensities, please leave
        //  the array empty.

        public MultiEchoLaserScanMsg()
        {
            this.header = new Std.HeaderMsg();
            this.angle_min = 0.0f;
            this.angle_max = 0.0f;
            this.angle_increment = 0.0f;
            this.time_increment = 0.0f;
            this.scan_time = 0.0f;
            this.range_min = 0.0f;
            this.range_max = 0.0f;
            this.ranges = new LaserEchoMsg[0];
            this.intensities = new LaserEchoMsg[0];
        }

        public MultiEchoLaserScanMsg(Std.HeaderMsg header, float angle_min, float angle_max, float angle_increment, float time_increment, float scan_time, float range_min, float range_max, LaserEchoMsg[] ranges, LaserEchoMsg[] intensities)
        {
            this.header = header;
            this.angle_min = angle_min;
            this.angle_max = angle_max;
            this.angle_increment = angle_increment;
            this.time_increment = time_increment;
            this.scan_time = scan_time;
            this.range_min = range_min;
            this.range_max = range_max;
            this.ranges = ranges;
            this.intensities = intensities;
        }

        public static MultiEchoLaserScanMsg Deserialize(MessageDeserializer deserializer) => new MultiEchoLaserScanMsg(deserializer);

        private MultiEchoLaserScanMsg(MessageDeserializer deserializer)
        {
            this.header = Std.HeaderMsg.Deserialize(deserializer);
            deserializer.Read(out this.angle_min);
            deserializer.Read(out this.angle_max);
            deserializer.Read(out this.angle_increment);
            deserializer.Read(out this.time_increment);
            deserializer.Read(out this.scan_time);
            deserializer.Read(out this.range_min);
            deserializer.Read(out this.range_max);
            deserializer.Read(out this.ranges, LaserEchoMsg.Deserialize, deserializer.ReadLength());
            deserializer.Read(out this.intensities, LaserEchoMsg.Deserialize, deserializer.ReadLength());
        }

        public override void SerializeTo(MessageSerializer serializer)
        {
            serializer.Write(this.header);
            serializer.Write(this.angle_min);
            serializer.Write(this.angle_max);
            serializer.Write(this.angle_increment);
            serializer.Write(this.time_increment);
            serializer.Write(this.scan_time);
            serializer.Write(this.range_min);
            serializer.Write(this.range_max);
            serializer.WriteLength(this.ranges);
            serializer.Write(this.ranges);
            serializer.WriteLength(this.intensities);
            serializer.Write(this.intensities);
        }

        public override string ToString()
        {
            return "MultiEchoLaserScanMsg: " +
            "\nheader: " + header.ToString() +
            "\nangle_min: " + angle_min.ToString() +
            "\nangle_max: " + angle_max.ToString() +
            "\nangle_increment: " + angle_increment.ToString() +
            "\ntime_increment: " + time_increment.ToString() +
            "\nscan_time: " + scan_time.ToString() +
            "\nrange_min: " + range_min.ToString() +
            "\nrange_max: " + range_max.ToString() +
            "\nranges: " + System.String.Join(", ", ranges.ToList()) +
            "\nintensities: " + System.String.Join(", ", intensities.ToList());
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
