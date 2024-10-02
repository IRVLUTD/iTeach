---
uid: xrhands-access-data
---

# Access hand data from Unity components in the scene

Access hand-tracking data from Unity components in the scene. 

The [XRHandTrackingEvents](xref:UnityEngine.XR.Hands.XRHandTrackingEvents) component can be added to a GameObject in the scene to subscribe to hand-tracking events for a particular hand chosen by the Handedness property.
This component subscribes to the [XRHandSubsystem](xref:UnityEngine.XR.Hands.XRHandSubsystem) and dispatches events when the hand data is updated.
Callbacks to these events can either be added via script, or from the Inspector window.

There are also standard components to drive a Skinned Mesh Renderer component and its skeleton from these events which is outlined in the [Hand Visuals](xref:xrhands-visuals) section.

# Access hand data from the XR Hand Subsystem

Access hand tracking data from the [XRHandSubsystem](xref:UnityEngine.XR.Hands.XRHandSubsystem). 

The [XRHandSubsystem](xref:UnityEngine.XR.Hands.XRHandSubsystem) updates hands twice per frame. The first update occurs as close as possible to the frame [Update](xref:ExecutionOrder) event. Use the data in this update to perform game logic, such as interactions, that depend on the hand data. The second update occurs just before rendering, as close as possible to the [Application.onBeforeRender](https://docs.unity3d.com/ScriptReference/Application-onBeforeRender.html) event. Use the data in this event to position game objects or other visual representations of the hands. This second update provides the lowest latency between hand motion and rendering.

The best way to access the data is through the [updatedHands](xref:UnityEngine.XR.Hands.XRHandSubsystem.updatedHands) callback, which is dispatched twice a frame when the hand data is updated. Getting the data in response to the callback provides the lowest latency and guarantees that you are using the latest data. Refer to [Subscribe to hand update events](#subscribe) for more information.

You can also access [XRHand](xref:UnityEngine.XR.Hands.XRHand) objects directly from the [XRHandSubsystem](xref:UnityEngine.XR.Hands.XRHandSubsystem) without waiting for the [updatedHands](xref:UnityEngine.XR.Hands.XRHandSubsystem.updatedHands) callback to be invoked. The [XRHand](xref:UnityEngine.XR.Hands.XRHand) objects reflect the data as of the latest successful update event. This might be from a previous frame.

> [!NOTE]
> The `XRHandSubsystem` does not supply data to the UnityEngine [XR.Hand](https://docs.unity3d.com/ScriptReference/XR.Hand.html) or [XR.Bone](https://docs.unity3d.com/ScriptReference/XR.Bone.html) structs.

<a id="get-instance"></a>
## Get the XRHandSubsystem instance

Get the hand subsystem from the active XR loader using [`SubsystemManager.GetSubsystems`](https://docs.unity3d.com/ScriptReference/SubsystemManager.GetSubsystems.html):

``` csharp
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.XR.Hands;

// ...

var handSubsystems = new List<XRHandSubsystem>();
SubsystemManager.GetSubsystems(handSubsystems);
```

You can get the subsystem after the XR system has finished initialization. By default, initialization occurs before any MonoBehaviour [Start](xref:ExecutionOrder) methods are called. However, if your project initializes XR manually, you must wait for your code to finish loading the subsystem.

<a id="subscribe"></a>
## Subscribe to hand update events

To subscribe to the hand update event, assign an [Action](xref:System.Action) delegate function to the [XRHandSubsystem.updatedHands](xref:UnityEngine.XR.Hands.XRHandSubsystem.updatedHands) property. When a hand update occurs, the `XRHandSubsystem` calls your delegate function.

Use the [updateType](xref:UnityEngine.XR.Hands.XRHandSubsystem.updatedHands) parameter to determine whether the update event is "Dynamic" which occurs near the MonoBehaviour `Update` event, or "BeforeRender" which occurs just before rendering begins.

``` csharp
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.XR.Hands;

public class HandsExample : MonoBehaviour
{
    XRHandSubsystem m_HandSubsystem;

    void Start()
    {
        var handSubsystems = new List<XRHandSubsystem>();
        SubsystemManager.GetSubsystems(handSubsystems);

        for (var i = 0; i < handSubsystems.Count; ++i)
        {
            var handSubsystem = handSubsystems[i];
            if (handSubsystem.running)
            {
                m_HandSubsystem = handSubsystem;
                break;
            }
        }

        if (m_HandSubsystem != null)
            m_HandSubsystem.updatedHands += OnUpdatedHands;
    }

    void OnUpdatedHands(XRHandSubsystem subsystem,
        XRHandSubsystem.UpdateSuccessFlags updateSuccessFlags,
        XRHandSubsystem.UpdateType updateType)
    {
        switch (updateType)
        {
            case XRHandSubsystem.UpdateType.Dynamic:
                // Update game logic that uses hand data
                break;
            case XRHandSubsystem.UpdateType.BeforeRender:
                // Update visual objects that use hand data
                break;
        }
    }
}
```

For a complete code example including how to handle late initialization, refer to the `HandVisualizer` component in the [HandVisualizer sample](xref:xrhands-manual#samples).

## Get joint data

Get the data for individual joints with the [XRHand.GetJoint](xref:UnityEngine.XR.Hands.XRHand.GetJoint*) method, passing in the index of the joint. This method returns an [XRHandJoint](xref:UnityEngine.XR.Hands.XRHandJoint) object that contains the latest data for a joint.

The joints of the hand are indexed by the [XRHandJointID](xref:UnityEngine.XR.Hands.XRHandJointID) enum. You can iterate through the list of joints in a for loop:

``` csharp
for(var i = XRHandJointID.BeginMarker.ToIndex();
        i < XRHandJointID.EndMarker.ToIndex(); 
        i++)
{
    var trackingData = hand.GetJoint(XRHandJointIDUtility.FromIndex(i));

    if (trackingData.TryGetPose(out Pose pose))
    {
        // displayTransform is some GameObject's Transform component
        displayTransform.localPosition = pose.position;
        displayTransform.localRotation = pose.rotation;
    }
}
```

Note that some or all of the data for a joint might not be successfully tracked in a given update.  The TryGet functions of the [XRHandJoint](xref:UnityEngine.XR.Hands.XRHandJoint) object return false if the data they access is unavailable. You can also use the [XRHandJoint.trackingState](xref:UnityEngine.XR.Hands.XRHandJoint.trackingState) flags to determine whether the data is valid or not. Refer to [Check data validity](#check-data-validity) for more information.

In addition, the hand data plug-in providing the hand data might not support every joint in the [XRHandJointID](xref:UnityEngine.XR.Hands.XRHandJointID) list. The TryGet functions of an unsupported joint always return false and the [trackingState](xref:UnityEngine.XR.Hands.XRHandJoint.trackingState) has the [WillNeverBeValid](xref:UnityEngine.XR.Hands.XRHandJointTrackingState.WillNeverBeValid) flag set. Refer to [Get provider data support](#joint-layout) for more information.

> [!NOTE]
> The XRHandSubsystem stores the data associated with each joint in an internal native array and updates the elements in place when new hand data becomes available. If you make a copy of an [XRHand](xref:UnityEngine.XR.Hands.XRHand)  object, the copy still points to the original native array. To take a snapshot of the joint data, you must copy the individual XRHandJoint objects at the desired point in time.

<a id="check-data-validity"></a>
## Check data validity

Hand data can be unreliable for a variety of reasons. A hand or part of a hand might be occluded or out of sensor range. The provider plug-in supplying the data might not support every tracked point or might not calculate certain aspects of the data, such as velocity. Before you use the hand data, you should make sure that it is valid.

The XR Hands API provides several APIs that you can use to check data validity.

| API | Purpose |
|:---|:---| 
| [XRHandSubsystem.jointsInLayout](xref:UnityEngine.XR.Hands.XRHandSubsystem.jointsInLayout)| Indicates which joints are supported by the current hand data provider. You can use this property before the [XRHandSystem](xref:UnityEngine.XR.Hands.XRHandSubsystem) is loaded or initialized. |
| [XRHandSubsystem.trackingAcquired](xref:UnityEngine.XR.Hands.XRHandSubsystem.trackingAcquired)| A callback function invoked when the system starts tracking a hand. |
| [XRHandSubsystem.trackingLost](xref:UnityEngine.XR.Hands.XRHandSubsystem.trackingLost)| A callback function invoked when tracking of a hand is lost. |
| [XRHandSubsystem.updateSuccessFlags](xref:UnityEngine.XR.Hands.XRHandSubsystem.updateSuccessFlags)| Flags describing which types of data are available in the most recent update. These flags apply to the [XRHandSubsystem.rightHand](xref:UnityEngine.XR.Hands.XRHandSubsystem.rightHand) and [XRHandSubsystem.leftHand](xref:UnityEngine.XR.Hands.XRHandSubsystem.leftHand) properties. |
| [XRHand.isTracked](xref:UnityEngine.XR.Hands.XRHand.isTracked)| Indicates whether the user's corresponding hand is currently being tracked by the system. |
| [XRHandJoint.trackingState](xref:UnityEngine.XR.Hands.XRHandJoint.trackingState)| Indicates which types of data in the joint are valid. A specific type of data might be invalid because the system could not determine the value in the current update or because the hand data provider does not support that type of data.|
| [XRHandJoint TryGet functions](xref:UnityEngine.XR.Hands.XRHandJoint#methods)| The [XRHandJoint](xref:UnityEngine.XR.Hands.XRHandJoint) object uses the "TryGet" pattern to provide access to a specific type of data for a joint, such as the pose or a velocity. These functions return false if the corresponding type of data is invalid for the joint. |


<a id="joint-layout"></a>
## Get supported joints array

The [XRHandSubsystem.jointsInLayout](xref:UnityEngine.XR.Hands.XRHandSubsystem.jointsInLayout) is an array of boolean values that indicate which joints the current hand data provider supports. The array contains a value for each joint defined by the [XRHandJointID](xref:UnityEngine.XR.Hands.XRHandJointID) enumeration.

The following example uses the `jointsInLayout` array to instantiate a prefab for each supported joint, which are stored in a dictionary keyed by the joint ID so that they can be updated when new hand data is available:

``` csharp
Dictionary<XRHandJointID, Transform> CreateHandDisplay(
            GameObject jointPrefab, 
            Transform sceneParent, 
            XRHandSubsystem handSubsystem)
{
    var displayObjects = new Dictionary<XRHandJointID, Transform>();
    
    for(var i = XRHandJointID.BeginMarker.ToIndex(); 
            i < XRHandJointID.EndMarker.ToIndex(); 
            i++)
    {
        if (handSubsystem.jointsInLayout[i])
        {
            XRHandJointID jointID = XRHandJointIDUtility.FromIndex(i); 
            var go = Instantiate(jointPrefab, sceneParent);
            go.name = jointID.ToString();
            displayObjects.Add(jointID, go.transform);
        }
    }
    return displayObjects;
}
```

With this dictionary, you could update the transforms of these game objects when a hand update is available:

``` csharp
void UpdateJointTransforms(XRHand hand, 
         Dictionary<XRHandJointID, Transform> displayObjects)
{
    foreach (var joint in displayObjects)
    {
        var trackingData = hand.GetJoint(joint.Key);
        var displayTransform = joint.Value;
        if (trackingData.TryGetPose(out Pose pose))
        {
            displayTransform.localPosition = pose.position;
            displayTransform.localRotation = pose.rotation;
        }
    }
}
```
