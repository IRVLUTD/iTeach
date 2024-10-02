using UnityEngine;
using iTeach.Utils;
using Microsoft.MixedReality.Toolkit.UI;
using System.Collections;
using System.Collections.Generic;
using Unity.Robotics.ROSTCPConnector;
using imgMsg = RosMessageTypes.Sensor.ImageMsg;
using strMsg = RosMessageTypes.Std.StringMsg;
using boolMsg = RosMessageTypes.Std.BoolMsg;
using Microsoft.MixedReality.Toolkit.Experimental.UI;

using System.IO;
using System.Net.Sockets;
using System.Net;

// ROSConnection format
[System.Serializable]
public class RosConnectionConfig
{
    public string RosIPAddress;
    public int RosPort;
    public float KeepaliveTime;
    public float NetworkTimeoutSeconds;
    public float SleepTimeSeconds;
    public bool ShowHud;
    public string SubTopic;
    public string PubTopic;

    public static RosConnectionConfig CreateFromJSON(string jsonString)
    {
        return JsonUtility.FromJson<RosConnectionConfig>(jsonString);
    }
} 


public class RosActions : MonoBehaviour
{
    public GameObject progressBar;
    public GameObject DisplayPlane;
    public GameObject finetuneButton;
    public TouchScreenKeyboard keyboard;
    public GameObject sampleTrackerGameObj;
    public string incomingImageTopicName = "hololens/in/robot_pov/detections/bbox_overlayed_rgb";
    public string incoming3DTopicName = "hololens/in/robot_pov/depth"; // Todo: check if this topic gives depth

    // For the unlabeled image
    public string incomingRawImageTopicName = "hololens/in/robot_pov/rgb";
    public string outgoingImageTopicName = "hololens/out/user_labelled/rgb";
    public string outgoing3DTopicName = "hololens/out/user_labelled/depth";
    public string outgoingTextTopicName = "hololens/out/user_labelled/labels";
    public string outgoingRawTopicName = "hololens/out/robot_pov/raw_rgb";
    public string outgoingFinetuneTopicName = "hololens/out/finetune_signal";
    public string incomingFinetuneACKTopicName = "finetune/ack_with_metrics";

    // Materials
    // public Material oldMat;
    // public Material newMat;

    private ProgressIndicatorOrbsRotator indicator;


    private imgMsg recentImg;
    private imgMsg recent3D;
    private imgMsg recentRaw;
    private strMsg finetuneAckWithMetrics;
    private Texture2D recentTexture;

    // ROSConnection ros;

    // ROS Connection related
    public static ROSConnection ros;
    //
    private string rosConfigPath;

    // Start is called before the first frame update
    void Start()
    {
        // = gameObject.GetComponent<MixedRealityKeyboard>();
        //keyboard = TouchScreenKeyboard.Open("192.168.50.220:10000", TouchScreenKeyboardType.Default, false, false, false, false);

        // btnInteractable = finetuneButton.GetComponent<Interactable>();
        indicator = progressBar.GetComponent<ProgressIndicatorOrbsRotator>();

        // ros = ROSConnection.GetOrCreateInstance();
        // Connect to ROS Server
        RosConnect();

        // subscribers
        ros.Subscribe<imgMsg>(incomingImageTopicName, DisplayImage);
        ros.Subscribe<imgMsg>(incoming3DTopicName, Retrieve3D);
        ros.Subscribe<imgMsg>(incomingRawImageTopicName, RetrieveRaw);
        ros.Subscribe<strMsg>(incomingFinetuneACKTopicName, RetrieveFinetuneACKMsg);

        // publishers
        ros.RegisterPublisher<imgMsg>(outgoingImageTopicName);
        ros.RegisterPublisher<imgMsg>(outgoing3DTopicName);
        ros.RegisterPublisher<strMsg>(outgoingTextTopicName);
        ros.RegisterPublisher<imgMsg>(outgoingRawTopicName);
        ros.RegisterPublisher<boolMsg>(outgoingFinetuneTopicName);

        //string ipAddress = GetLocalIPAddress();
        // string ipAddress = hl2ss.GetIPAddress();
        // Debug.Log("HoloLens IP Address: " + ipAddress);

    }

    // Update is called once per frame

    void Update()
    {


    }

    private void OnApplicationQuit()
    {
        // Unsubscribe topics
        // ros.Unsubscribe(incomingImageTopicName);
        // ros.Unsubscribe(incoming3DTopicName);
        // ros.Unsubscribe(incomingRawImageTopicName);
        // ros.Unsubscribe(incomingFinetuneACKTopicName);

        // Disconnect ROS Server
        ros.Disconnect();
    }

    public RosConnectionConfig LoadRosConnectionConfig()
    {
        //if (Application.isEditor)
        //{
        //    rosConfigPath = Path.Combine(Application.streamingAssetsPath, "ROSConnectionConfig.json");
        //}
        //else
        //{
        //    // Path for HoloLens 2 device
        //    rosConfigPath = Path.Combine(Application.persistentDataPath, "ROSConnectionConfig.json");
        //}

        // first try to load config from device
        rosConfigPath = Path.Combine(Application.persistentDataPath, "ROSConnectionConfig.json");
        if (!File.Exists(rosConfigPath))
        {
            rosConfigPath = Path.Combine(Application.streamingAssetsPath, "ROSConnectionConfig.json");
        }

        byte[] bytes = UnityEngine.Windows.File.ReadAllBytes(rosConfigPath);
        string jsonString = System.Text.Encoding.ASCII.GetString(bytes);
        return RosConnectionConfig.CreateFromJSON(jsonString);
    }

    private void RosConnect()
    {
        var config = LoadRosConnectionConfig();
        ros = ROSConnection.GetOrCreateInstance();
        ros.RosIPAddress = config.RosIPAddress;
        ros.RosPort = config.RosPort;
        ros.KeepaliveTime = config.KeepaliveTime;
        ros.NetworkTimeoutSeconds = config.NetworkTimeoutSeconds;
        ros.SleepTimeSeconds = config.SleepTimeSeconds;
        ros.ShowHud = config.ShowHud;
        ros.Connect();

        Debug.Log(config.RosIPAddress);
    }

    private static string GetLocalIPAddress()
    {
        var host = Dns.GetHostEntry(Dns.GetHostName());
        foreach (var ip in host.AddressList)
        {
            if (ip.AddressFamily == AddressFamily.InterNetwork)
            {
                return ip.ToString();
            }
        }
        throw new System.Exception("No network adapters with an IPv4 address in the system!");
    }

    private async void OpenProgressIndicator()
    {
        await indicator.OpenAsync();

        float progress = 0;
        while (progress < 6)
        {
            progress += Time.deltaTime;
            indicator.Message = "Loading...";
            indicator.Progress = progress;
            //await Task.Yield();
        }

        await indicator.CloseAsync();
    }


    private async void ToggleIndicator(IProgressIndicator indicator)
    {
        await indicator.AwaitTransitionAsync();

        switch (indicator.State)
        {
            case ProgressIndicatorState.Closed:
                await indicator.OpenAsync();
                break;

            case ProgressIndicatorState.Open:
                await indicator.CloseAsync();
                break;
        }
    }


    byte[] ConvertBGRToRGBAndFlip(byte[] imagedata, int width, int height)
    {
        byte[] flippedImageData = new byte[imagedata.Length];

        // Convert BGR to RGB and flip horizontally
        for (int y = 0; y < height; y++)
        {
            for (int x = 0; x < width; x++)
            {
                int srcIndex = (y * width + x) * 3;
                int dstIndex = (y * width + (width - x - 1)) * 3;

                // BGR to RGB conversion and horizontal flip
                flippedImageData[dstIndex] = imagedata[srcIndex + 2];     // Red
                flippedImageData[dstIndex + 1] = imagedata[srcIndex + 1]; // Green
                flippedImageData[dstIndex + 2] = imagedata[srcIndex];     // Blue
            }
        }

        return flippedImageData;
    }

    void DisplayImage(imgMsg image)
    {
        //Debug.Log("Image!");
        recentImg = image;

        int width = (int)image.width;
        int height = (int)image.height;
        Texture2D texture = new Texture2D(width, height, TextureFormat.RGB24, false);

        //render.material.mainTexture = texture;
        byte[] imageData = image.data;

        // Convert and flip the image data
        byte[] processedImageData = ConvertBGRToRGBAndFlip(imageData, width, height);

        texture.LoadRawTextureData(processedImageData);

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

    void RetrieveFinetuneACKMsg(strMsg _finetuneAckWithMetrics)
    {
        // 3. wait untill finetune completes and then show the ack with metrics and enable the btn
        finetuneAckWithMetrics = _finetuneAckWithMetrics;
        Debug.Log("Received Finetune ACK with metrics: " + finetuneAckWithMetrics.data);

        string jsonString = finetuneAckWithMetrics.data;

        // Parse JSON
        FinetuneACKMessage ftACK = JsonUtility.FromJson<FinetuneACKMessage>(jsonString);

        // Example: Access data from the parsed JSON
        if (ftACK != null)
        {
            //GameObject.FindGameObjectsWithTag("finetuneHighlightPlate")[0].GetComponent<Renderer>().material = oldMat;
            ToggleIndicator(indicator);
            finetuneButton.GetComponent<ButtonConfigHelper>().IconStyle = ButtonIconStyle.Quad;
            finetuneButton.GetComponent<ButtonConfigHelper>().SetQuadIconByName("IconSettings");

            // Re-enable the finetune button
            EnableFinetuneButton();

            Debug.Log($"Data: {finetuneAckWithMetrics.data}");
            Helpers.ShowNativeToast(GetFormatedFinetuneACKMessage(ftACK));
        }
        else
        {
            Debug.LogError("Failed to parse JSON.");
        }
    }

    public imgMsg getImg()
    {
        return recentImg;
    }

    public imgMsg get3D()
    {
        return recent3D;
    }

    public imgMsg getRaw()
    {
        return recentRaw;
    }

    public Texture2D getTex()
    {
        return recentTexture;
    }


    public void sendResults()
    {

        imgMsg outImg = DisplayPlane.GetComponent<DisplayManager>().GetRecentImg();
        imgMsg out3d = DisplayPlane.GetComponent<DisplayManager>().GetRecent3D();
        imgMsg outRaw = DisplayPlane.GetComponent<DisplayManager>().GetRecentRaw();

        strMsg outStr = new strMsg(DisplayPlane.GetComponent<DrawRectangle>().getLabels());

        if (outImg != null)
        {
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
        
        // Update the sample tracker details
        UpdateSampleTrackerCounts(outStr.data);
        sampleTrackerGameObj.GetComponent<SampleTracker>().AddSample();

    }

    public void sendFinetuneSignal()
    {

        if (finetuneButton.GetComponent<Interactable>().Enabled)
        {
            // send true as a signal for finetuning
            // This will trigger the finetuning function at the yolo-server side
            boolMsg finetuneSignal = new boolMsg(true);
            Debug.Log("Sending Finetune Signal");
            ros.Publish(outgoingFinetuneTopicName, finetuneSignal);
            // Disable the finetune button
            DisableFinetuneButton();

            // Reset sample stats for the current session here
            sampleTrackerGameObj.GetComponent<SampleTracker>().ResetSessionSamples();
            ToggleIndicator(indicator);
        }
        else {
            Debug.Log("Finetuning in progress: " + finetuneButton.GetComponent<Interactable>().Enabled);
            Helpers.ShowNativeToast("Finetuning in progress. Please wait untill completion. Thankyou!!!");
        }

    }


    private void UpdateSampleTrackerCounts(string labelsData)
    {
        // Split the string into lines
        string[] lines = labelsData.Split('\n');

        // Initialize counts
        int doorCount = 0;
        int handleCount = 0;

        // Parse each line
        foreach (string line in lines)
        {
            string[] parts = line.Split(' ');
            Debug.Log(parts);
            // Ensure there is at least one part and try to determine the type
            if (parts.Length > 0)
            {
                // Determine the type from the first part of the line
                BoxIdentifier.RectType rectType;
                try
                {
                    rectType = Helpers.LabelToRectType(parts[0]);
                }
                catch (System.ArgumentException)
                {
                    continue; // Skip invalid labels
                }

                // Increment the respective counter
                if (rectType == BoxIdentifier.RectType.door)
                {
                    doorCount++;
                }
                else if (rectType == BoxIdentifier.RectType.handle)
                {
                    handleCount++;
                }
            }
        }

        Debug.Log("In DC: " + doorCount);
        Debug.Log("In HC: " + handleCount);

        // Update the sample tracker with the counts
        SampleTracker sampleTracker = sampleTrackerGameObj.GetComponent<SampleTracker>();
        sampleTracker.AddDoor(doorCount);  // Update with the door count
        sampleTracker.AddHandle(handleCount);  // Update with the handle count
    }


    public void showSampleDetails() {
        string sampleInfo = sampleTrackerGameObj.GetComponent<SampleTracker>().GetSampleInfoInTableView();
        Debug.Log("In showSampleDetails()" + sampleInfo);
        Helpers.ShowNativeToast(sampleInfo);
    }

    private void DisableFinetuneButton()
    {
        if (finetuneButton != null)
        {
            finetuneButton.GetComponent<Interactable>().Enabled = false;
            finetuneButton.GetComponent<ButtonConfigHelper>().MainLabelText = "<color=\"yellow\">Finetuning...";
            finetuneButton.GetComponent<ButtonConfigHelper>().IconStyle = ButtonIconStyle.None;
            Debug.Log("DisableFinetuneButton: " + finetuneButton.GetComponent<Interactable>().Enabled);
        }
    }


    private void EnableFinetuneButton()
    {
        if (finetuneButton != null)
        {
            //finetuneButton.isEnabled = true;
            finetuneButton.GetComponent<Interactable>().Enabled = true;
            finetuneButton.GetComponent<ButtonConfigHelper>().MainLabelText = "Finetune";
            Debug.Log("EnableFinetuneButton: " + finetuneButton.GetComponent<Interactable>().Enabled);
        }
    }

    private string GetFormatedFinetuneACKMessage(FinetuneACKMessage message)
    {
        if (message == null)
        {
            return "FinetuneACKMessage instance is null.";
        }

        return $"Current mAP50: {message.curr_mAP50}\n" +
               $"Current Fine-Tuning Iteration Number: {message.curr_ft_iter_num}\n" +
               $"Overall Best mAP50: {message.overall_best_mAP50}\n" +
               $"Overall Best mAP50 at Fine-Tuning Iteration: {message.overall_best_mAP50_ft_iter}";
    }

    [System.Serializable]
    public class FinetuneACKMessage
    {
        public int curr_mAP50;
        public int curr_ft_iter_num;
        public float overall_best_mAP50;
        public float overall_best_mAP50_ft_iter;
    }

}


