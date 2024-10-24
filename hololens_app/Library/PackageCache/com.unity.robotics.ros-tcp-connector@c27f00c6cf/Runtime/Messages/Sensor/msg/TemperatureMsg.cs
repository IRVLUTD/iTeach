//Do not edit! This file was generated by Unity-ROS MessageGeneration.
using System;
using System.Linq;
using System.Collections.Generic;
using System.Text;
using Unity.Robotics.ROSTCPConnector.MessageGeneration;

namespace RosMessageTypes.Sensor
{
    [Serializable]
    public class TemperatureMsg : Message
    {
        public const string k_RosMessageName = "sensor_msgs/Temperature";
        public override string RosMessageName => k_RosMessageName;

        //  Single temperature reading.
        public Std.HeaderMsg header;
        //  timestamp is the time the temperature was measured
        //  frame_id is the location of the temperature reading
        public double temperature;
        //  Measurement of the Temperature in Degrees Celsius.
        public double variance;
        //  0 is interpreted as variance unknown.

        public TemperatureMsg()
        {
            this.header = new Std.HeaderMsg();
            this.temperature = 0.0;
            this.variance = 0.0;
        }

        public TemperatureMsg(Std.HeaderMsg header, double temperature, double variance)
        {
            this.header = header;
            this.temperature = temperature;
            this.variance = variance;
        }

        public static TemperatureMsg Deserialize(MessageDeserializer deserializer) => new TemperatureMsg(deserializer);

        private TemperatureMsg(MessageDeserializer deserializer)
        {
            this.header = Std.HeaderMsg.Deserialize(deserializer);
            deserializer.Read(out this.temperature);
            deserializer.Read(out this.variance);
        }

        public override void SerializeTo(MessageSerializer serializer)
        {
            serializer.Write(this.header);
            serializer.Write(this.temperature);
            serializer.Write(this.variance);
        }

        public override string ToString()
        {
            return "TemperatureMsg: " +
            "\nheader: " + header.ToString() +
            "\ntemperature: " + temperature.ToString() +
            "\nvariance: " + variance.ToString();
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
