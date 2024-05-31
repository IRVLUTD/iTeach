using UnityEngine;
using Unity.Robotics.ROSTCPConnector;
using inmsg = RosMessageTypes.Std.StringMsg;
using imgMsg = RosMessageTypes.Sensor.ImageMsg;
using System.IO;



public class RosSubscriberExample : MonoBehaviour
{
    public GameObject plane;
    public Renderer render;
    
    private Texture2D texture;
    
    void Start()
    {
        
        ROSConnection.GetOrCreateInstance().Subscribe<imgMsg>("camImg", DisplayImage);
        
    }

    void ColorChange(inmsg stringMessage)
    {
        print(stringMessage);
    }


    void DisplayImage(imgMsg image)
    {
        print("Image!");
        texture = new Texture2D((int)image.width, (int)image.height, TextureFormat.RGB24, false);
        render.material.mainTexture = texture;
        byte[] imagedata = image.data;
        texture.LoadRawTextureData(imagedata);
        texture.Apply();
        
        
    }
}