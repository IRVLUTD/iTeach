using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using Unity.Robotics.ROSTCPConnector;
using imgMsg = RosMessageTypes.Sensor.ImageMsg;
using strMsg = RosMessageTypes.Std.StringMsg;
using Microsoft.MixedReality.Toolkit.Experimental.UI;

public class RosSubscriberOnly : MonoBehaviour
{


    public TouchScreenKeyboard keyboard;
    public GameObject DisplayPlane;

    public string incomingImageTopicName = "camImg";

    public string incoming3DTopicName = "3dmap";

    // For the unlabeled image
    public string incomingRawImageTopicName = "InfrequentImage";

    public string outgoingImageTopicName = "LabeledImage";
    public string outgoing3DTopicName = "LabeledDepth";
    public string outgoingTextTopicName = "ImageLabels";
    public string outgoingRawTopicName = "Cole/RawLabeledImage";
    private imgMsg recentImg;
    private imgMsg recent3D;
    private imgMsg recentRaw;
    private Texture2D recentTexture;

    ROSConnection ros;

    

    // Start is called before the first frame update
    void Start()
    {
        // = gameObject.GetComponent<MixedRealityKeyboard>();
        //keyboard = TouchScreenKeyboard.Open("192.168.50.220:10000", TouchScreenKeyboardType.Default, false, false, false, false);
        
        ros = ROSConnection.GetOrCreateInstance();
        ros.Subscribe<imgMsg>(incomingImageTopicName, DisplayImage); 
        ros.Subscribe<imgMsg>(incoming3DTopicName, Retrieve3D);
        ros.Subscribe<imgMsg>(incomingRawImageTopicName, RetrieveRaw);
        ros.RegisterPublisher<imgMsg>(outgoingImageTopicName);
        ros.RegisterPublisher<imgMsg>(outgoing3DTopicName);
        ros.RegisterPublisher<strMsg>(outgoingTextTopicName);
        ros.RegisterPublisher<strMsg>(outgoingRawTopicName);
        
    }

    // Update is called once per frame
    
    void Update()
    {
    
        
    }

    void DisplayImage(imgMsg image)
    {   
        //Debug.Log("Image!");
        recentImg = image;
        Texture2D texture = new Texture2D((int)image.width, (int)image.height, TextureFormat.RGB24, false);
        //render.material.mainTexture = texture;
        byte[] imagedata = image.data;
        texture.LoadRawTextureData(imagedata);
        recentTexture = texture;
        //texture.Apply();
    }
        
        
    


    void Retrieve3D(imgMsg img3D)
    {
        recent3D = img3D; 
    }

    void RetrieveRaw(imgMsg imgRaw)
    {
        recentRaw = imgRaw;
    }


    public imgMsg getImg(){
        return recentImg;
    }

    public imgMsg get3D(){
        return recent3D;
    }
    public imgMsg getRaw(){
        return recentRaw;
    }

    public Texture2D getTex(){
        return recentTexture;
    }


    public void sendResults(){
        
        imgMsg outImg = DisplayPlane.GetComponent<DisplayManager>().GetRecentImg();
        imgMsg out3d = DisplayPlane.GetComponent<DisplayManager>().GetRecent3D();
        imgMsg outRaw = DisplayPlane.GetComponent<DisplayManager>().GetRecentRaw();
        
        strMsg outStr = new strMsg(DisplayPlane.GetComponent<DrawRectangle>().getLabels());

        if(outImg != null){
            Debug.Log("Sending Image");
            ros.Publish(outgoingImageTopicName, outImg);

            Debug.Log("Sending 3d");
            ros.Publish(outgoing3DTopicName, out3d);

            Debug.Log("Sending Raw");
            ros.Publish(outgoingRawTopicName, outRaw);

            Debug.Log("Sending Labels");
            Debug.Log(outStr.data);
            ros.Publish(outgoingTextTopicName, outStr);
        

            DisplayPlane.GetComponent<DrawRectangle>().ClearRectangles();
            DisplayPlane.SetActive(false);
        }
    }

}
