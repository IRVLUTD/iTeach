using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using imgMsg = RosMessageTypes.Sensor.ImageMsg;

public class DisplayManager : MonoBehaviour
{

    public GameObject DisplayPlane;
    public GameObject HeadCam;
    public Renderer DisplayRender;

    //The image/message pair that is to be labelled
    public RosSubscriberOnly RosInterface;

    //The image that is currently being labelled
    private imgMsg recentImg = null;
    private imgMsg recent3D = null;
    private imgMsg recentRaw = null;
    private Texture2D recentTexture;

    private float spawnDist = 0.6f;
    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        
    }

    // OnEnable is called when the object is no longer disabled
    // Use to retrieve the most recent image
    void OnEnable()
    {
        //get the next textures
        recentImg = RosInterface.getImg();
        recentTexture = RosInterface.getTex();
        recent3D = RosInterface.get3D();
        recentRaw = RosInterface.getRaw();

        //apply the next textures
        DisplayRender.material.mainTexture = recentTexture;
        try{
            recentTexture.Apply();
        } catch (System.Exception) {
            Debug.Log("Image requested, no image received");
        }
    }

    // OnDisable is called when the object is no longer enabled
    // Use to clear the most recent image
    void OnDisable()
    {

    }

    // FaceUser is called when the Summon button is pressed
    public void FaceUser()
    {
        // Calculate the target position in front of the camera
        Vector3 targetPosition = HeadCam.transform.position + (HeadCam.transform.forward * spawnDist);

        // Move the plane to the target position
        DisplayPlane.transform.position = targetPosition;

        // Rotate the plane to face the camera
        Vector3 direction = HeadCam.transform.position - DisplayPlane.transform.position;
        Quaternion rotation = Quaternion.LookRotation(new Vector3(direction.x, -90f, direction.z));
        DisplayPlane.transform.rotation = rotation;
    }

    public imgMsg GetRecentImg(){
        if(recentImg == null){
            Debug.Log("Recent image is null");
        }
        return recentImg;
    }

    public imgMsg GetRecent3D(){
        if(recentImg == null){
            Debug.Log("Recent depth image is null");
        }
        return recent3D;
    }

    public imgMsg GetRecentRaw(){
        if(recentRaw == null){
            Debug.Log("Recent raw image is null");
        }
        return recentRaw;
    }


}
