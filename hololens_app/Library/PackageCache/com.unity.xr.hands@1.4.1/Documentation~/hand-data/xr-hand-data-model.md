---
uid: xrhands-data-model
---

## Hand data model

Hand tracking provides data such as position, orientation, and velocity for several points on a user's hand. The following diagram illustrates the tracked points:

![Tracked points of a hand](../images/xrhands-data-model.png)<br />*Left hand showing tracked hand points*

The 26 tracked points of the hand include the finger joints, fingertips, the wrist and the palm. 

> [!NOTE]
> The thumb has one fewer joint than the other fingers because thumbs do not have an intermediate phalanx.

The hand API reports tracking data relative to the real-world location chosen by the user's device as its tracking origin. Distances are provided in meters. The [XR Origin](https://docs.unity3d.com/Packages/com.unity.xr.core-utils@2.2/manual/xr-origin.html) in a properly configured XR scene is positioned relative to the device's tracking origin. To position model hands in the correct place in a virtual scene relative to the user's real hands, you can set the local poses of a hand model in your scene directly from the tracking data as long as the model is a child of the XR Origin's [Camera Offset](https://docs.unity3d.com/Packages/com.unity.xr.core-utils@2.2/manual/xr-origin-reference.html) object in the scene hierarchy. In other situations, you can transform the hand data into Unity world space with the XR Origin's pose.

> [!Note]
> Unity uses a left hand coordinate system, with the positive Z axis facing forward. This is different from the right-handed coordinate system used by OpenXR. Provider plug-in implementations are required to transform the data they provide into the Unity coordinate system. 

## Tracking data

The tracking data supplied by the hand API includes:

| Name| API | Description |
|:---|:---|:---| 
| Hand pose| [XRHand.rootPose](xref:UnityEngine.XR.Hands.XRHand.rootPose*) | The position and rotation of a hand. Positions are in meters and the rotation is expressed as a quaternion. |
| Joint pose| [XRHandJoint.TryGetPose](xref:UnityEngine.XR.Hands.XRHandJoint.TryGetPose(UnityEngine.Pose@)) | The position and rotation of a joint.<br /><br/>Note that the term "joint" should be interpreted loosely in this context. The list of joints provided by the XRHand includes the fingertips and the palm. |
| Joint radius| [XRHandJoint.TryGetRadius](xref:UnityEngine.XR.Hands.XRHandJoint.TryGetRadius*) | The distance from the center of the joint to the skin surface. |
| Joint linear velocity| [XRHandJoint.TryGetLinearVelocity](xref:UnityEngine.XR.Hands.XRHandJoint.TryGetLinearVelocity*) | A vector expressing the speed and direction of the joint in meters per second. |
| Joint angular velocity| [XRHandJoint.TryGetAngularVelocity](xref:UnityEngine.XR.Hands.XRHandJoint.TryGetAngularVelocity*) | A vector expressing a joint's rotational velocity. The direction of this vector is the axis of rotation and its magnitude is the angular velocity in meters per second. |
| Grip| [XRHandDevice.gripPosition](xref:UnityEngine.XR.Hands.XRHandDevice.gripPosition*)<br />[XRHandDevice.gripRotation](xref:UnityEngine.XR.Hands.XRHandDevice.gripRotation*) | The position and orientation of the center of mass of a hand in a grip pose. |
| Pinch| [XRHandDevice.pinchPosition](xref:UnityEngine.XR.Hands.XRHandDevice.pinchPosition)<br />[XRHandDevice.pinchRotation](xref:UnityEngine.XR.Hands.XRHandDevice.pinchRotation) | The position and orientation of the point between the thumb and the index finger when the hand is in a pinching pose. |
| Poke| [XRHandDevice.pokePosition](xref:UnityEngine.XR.Hands.XRHandDevice.pokePosition)<br />[XRHandDevice.pokeRotation](xref:UnityEngine.XR.Hands.XRHandDevice.pokeRotation) | The position and orientation of the index fingertip when the hand is in a poking pose. |
| Device gestures, including pinch, menu pressed, and system.| [MetaAimHand.aimFlags](xref:UnityEngine.XR.Hands.OpenXR.MetaHandTrackingAim.MetaAimHand.aimFlags*) | Hand gestures reported through the Meta Aim Hand extension to OpenXR. |
| Aim direction and position| [MetaAimHand.devicePosition](xref:UnityEngine.InputSystem.TrackedDevice.devicePosition)<br />[MetaAimHand.deviceRotation](xref:UnityEngine.InputSystem.TrackedDevice.deviceRotation) | A pose indicating where a device gesture is pointing, which can be used for UI and other interactions in a scene. |


The [XRHand](xref:UnityEngine.XR.Hands.XRHand), [XRHandJoint](xref:UnityEngine.XR.Hands.XRHandJoint), and [XRHandDevice](xref:UnityEngine.XR.Hands.XRHandDevice) objects are always available from a provider plug-in that supports the [XRHandSubsystem](xref:UnityEngine.XR.Hands.XRHandSubsystem). However, a provider might not support every possible joint on the hand. You can determine which joints the current device supports with the [XRHandSubsystem.jointsInLayout](xref:UnityEngine.XR.Hands.XRHandSubsystem.jointsInLayout) property. Refer to [Get provider data layout](xref:xrhands-access-data#joint-layout) for more information. 

A provider might not support every type of data for a hand or joint, or might not be able to provide it with every hand update event. In both cases, you can determine which data are valid in an update with the  [XRHandJoint.trackingState](xref:UnityEngine.XR.Hands.XRHandJoint.trackingState) property. Refer to [Check data validity](xref:xrhands-access-data#check-data-validity) for more information.

The data for the [MetaAimHand](xref:UnityEngine.XR.Hands.MetaAimHand) is supplied by an optional OpenXR extension. Provider plug-ins are not required to support it. Use the [MetaAimHand.aimFlags](xref:UnityEngine.XR.Hands.MetaAimHand.aimFlags) at runtime to determine if the data in a `MetaAimHand` object is valid. 

## Joint nomenclature

The term "joint" should be interpreted fairly loosely. In this context, a joint is really a point on the hand that is independently tracked. It might not correspond to an anatomical joint. For example, the fingertips, palm, and wrist are not anatomical joints, but they do appear in the list of joints provided by the API.

The Unity API follows the OpenXR joint nomenclature. In addition to including points that aren't joints, the OpenXR API names a joint by its adjacent bone rather than by its anatomical name. For example, the OpenXR API metacarpal "joint" is the end of the metacarpal bone that is closest to the wrist.

The following table provides the API names along with the anatomical joint names for the tracked hand points:

<table>
  <tr>
   <td>Tracked point
   </td>
   <td>Nomenclature
   </td>
  </tr>
  <tr>
   <td rowspan="10" ><strong>Tip</strong><br>
<img src="../images/gestures/tip.png" width="" alt="Fingertips" title="Fingertips">

   </td>
   <td><strong>Thumb</strong>
   </td>
  </tr>
  <tr>
   <td><strong>Unity API</strong>: ThumbTip<br><strong>OpenXR</strong>: XR_HAND_JOINT_THUMB_TIP_EXT
   </td>
  </tr>
  <tr>
   <td><strong>Index Finger</strong>
   </td>
  </tr>
  <tr>
   <td><strong>Unity API</strong>: IndexTip<br><strong>OpenXR</strong>: XR_HAND_JOINT_INDEX_TIP_EXT
   </td>
  </tr>
  <tr>
   <td><strong>Middle Finger</strong>
   </td>
  </tr>
  <tr>
   <td><strong>Unity API</strong>: MiddleTip<br><strong>OpenXR</strong>: XR_HAND_JOINT_MIDDLE_TIP_EXT
   </td>
  </tr>
  <tr>
   <td><strong>Ring Finger</strong>
   </td>
  </tr>
  <tr>
   <td><strong>Unity API</strong>: RingTip<br><strong>OpenXR</strong>: XR_HAND_JOINT_RING_TIP_EXT
   </td>
  </tr>
  <tr>
   <td><strong>Little Finger</strong>
   </td>
  </tr>
  <tr>
   <td><strong>Unity API</strong>: LittleTip<br><strong>OpenXR</strong>: XR_HAND_JOINT_LITTLE_TIP_EXT
   </td>
  </tr>
  <tr>
   <td rowspan="10" ><strong>Distal point</strong><br>
<img src="../images/gestures/distal.png" width="" alt="Distal Interphalangeal joints" title="Distal Interphalangeal joints">

   </td>
   <td><strong>Thumb</strong>
   </td>
  </tr>
  <tr>
   <td><strong>Unity API</strong>: ThumbDistal<br><strong>OpenXR</strong>: XR_HAND_JOINT_THUMB_DISTAL_EXT
<p>
<strong>Anatomic</strong>: Interphalangeal (IP)
   </td>
  </tr>
  <tr>
   <td><strong>Index Finger</strong>
   </td>
  </tr>
  <tr>
   <td><strong>Unity API</strong>: IndexDistal<br><strong>OpenXR</strong>: XR_HAND_JOINT_INDEX_DISTAL_EXT
<p>
<strong>Anatomic</strong>: Distal Interphalangeal (DIP)
   </td>
  </tr>
  <tr>
   <td><strong>Middle Finger</strong>
   </td>
  </tr>
  <tr>
   <td><strong>Unity API</strong>: MiddleDistal<br><strong>OpenXR</strong>: XR_HAND_JOINT_MIDDLE_DISTAL_EXT
<p>
<strong>Anatomic</strong>: Distal Interphalangeal (DIP)
   </td>
  </tr>
  <tr>
   <td><strong>Ring Finger</strong>
   </td>
  </tr>
  <tr>
   <td><strong>Unity API</strong>: RingDistal<br><strong>OpenXR</strong>: XR_HAND_JOINT_RING_DISTAL_EXT<br><strong>Anatomic</strong>: Distal Interphalangeal (DIP)
   </td>
  </tr>
  <tr>
   <td><strong>Little Finger</strong>
   </td>
  </tr>
  <tr>
   <td><strong>Unity API</strong>: LittleDistal<br><strong>OpenXR</strong>: XR_HAND_JOINT_LITTLE_DISTAL_EXT<br><strong>Anatomic</strong>: Distal Interphalangeal (DIP)
   </td>
  </tr>
  <tr>
   <td rowspan="10" ><strong>Intermediate point</strong><br>
<img src="../images/gestures/intermediate.png" width="" alt="Proximal Interphalangeal joints" title="Proximal Interphalangeal joints">

   </td>
   <td><strong>Thumb</strong>
   </td>
  </tr>
  <tr>
   <td>Not defined (the thumb has one less phalange bone than the other fingers).
   </td>
  </tr>
  <tr>
   <td><strong>Index Finger</strong>
   </td>
  </tr>
  <tr>
   <td><strong>Unity API</strong>: IndexIntermediate<br>OpenXR: XR_HAND_JOINT_INDEX_INTERMEDIATE_EXT
<p>
Anatomic: Proximal Interphalangeal (PIP)
   </td>
  </tr>
  <tr>
   <td><strong>Middle Finger</strong>
   </td>
  </tr>
  <tr>
   <td><strong>Unity API</strong>: MiddleIntermediate<br><strong>OpenXR</strong>: XR_HAND_JOINT_MIDDLE_INTERMEDIATE_EXT
<p>
<strong>Anatomic</strong>: Proximal Interphalangeal (PIP)
   </td>
  </tr>
  <tr>
   <td><strong>Ring Finger</strong>
   </td>
  </tr>
  <tr>
   <td><strong>Unity API</strong>: RingIntermediate<br><strong>OpenXR</strong>: XR_HAND_JOINT_RING_INTERMEDIATE_EXT<br><strong>Anatomic</strong>: Proximal Interphalangeal (PIP)
   </td>
  </tr>
  <tr>
   <td><strong>Little Finger</strong>
   </td>
  </tr>
  <tr>
   <td><strong>Unity API</strong>: LittleIntermediate<br><strong>OpenXR</strong>: XR_HAND_JOINT_LITTLE_INTERMEDIATE_EXT<br><strong>Anatomic</strong>: Proximal Interphalangeal (PIP)
   </td>
  </tr>
  <tr>
   <td rowspan="10" ><strong>Proximal point</strong><br>
<img src="../images/gestures/proximal.png" width="" alt="Metacarpophalangeal joints" title="MetacarpoPhalangeal joints">

   </td>
   <td><strong>Thumb</strong>
   </td>
  </tr>
  <tr>
   <td><strong>Unity API</strong>: ThumbProximal<br><strong>OpenXR</strong>: XR_HAND_JOINT_THUMB_PROXIMAL_EXT
<p>
<strong>Anatomic</strong>: Metacarpophalangeal (MCP)
   </td>
  </tr>
  <tr>
   <td><strong>Index Finger</strong>
   </td>
  </tr>
  <tr>
   <td><strong>Unity API</strong>: IndexProximal<br><strong>OpenXR</strong>: XR_HAND_JOINT_INDEX_PROXIMAL_EXT
<p>
<strong>Anatomic</strong>: Metacarpophalangeal (MCP)
   </td>
  </tr>
  <tr>
   <td><strong>Middle Finger</strong>
   </td>
  </tr>
  <tr>
   <td><strong>Unity API</strong>: MiddleProximal<br><strong>OpenXR</strong>: XR_HAND_JOINT_MIDDLE_PROXIMAL_EXT
<p>
<strong>Anatomic</strong>: Metacarpophalangeal (MCP)
   </td>
  </tr>
  <tr>
   <td><strong>Ring Finger</strong>
   </td>
  </tr>
  <tr>
   <td><strong>Unity API</strong>: RingProximal<br><strong>OpenXR</strong>: XR_HAND_JOINT_RING_PROXIMAL_EXT<br><strong>Anatomic</strong>: Metacarpophalangeal (MCP)
   </td>
  </tr>
  <tr>
   <td><strong>Little Finger</strong>
   </td>
  </tr>
  <tr>
   <td><strong>Unity API</strong>: LittleProximal<br><strong>OpenXR</strong>: XR_HAND_JOINT_LITTLE_PROXIMAL_EXT<br><strong>Anatomic</strong>: Metacarpophalangeal (MCP)
   </td>
  </tr>
  <tr>
   <td rowspan="10" ><strong>Metacarpal point</strong><br>
<img src="../images/gestures/metacarpal.png" width="" alt="Carpometacarpal joints" title="Carpometacarpal joints">

   </td>
   <td><strong>Thumb</strong>
   </td>
  </tr>
  <tr>
   <td><strong>Unity API</strong>: ThumbMetacarpal<br><strong>OpenXR</strong>: XR_HAND_JOINT_THUMB_DISTAL_EXT
<p>
<strong>Anatomic</strong>: Carpometacarpal (CMC)
   </td>
  </tr>
  <tr>
   <td><strong>Index Finger</strong>
   </td>
  </tr>
  <tr>
   <td><strong>Unity API</strong>: IndexMetacarpal<br>OpenXR: XR_HAND_JOINT_INDEX_METACARPAL_EXT
<p>
Anatomic: Carpometacarpal (CMC)
   </td>
  </tr>
  <tr>
   <td><strong>Middle Finger</strong>
   </td>
  </tr>
  <tr>
   <td><strong>Unity API</strong>: MiddleMetacarpal<br><strong>OpenXR</strong>: XR_HAND_JOINT_MIDDLE_METACARPAL_EXT
<p>
<strong>Anatomic</strong>: Carpometacarpal (CMC)
   </td>
  </tr>
  <tr>
   <td><strong>Ring Finger</strong>
   </td>
  </tr>
  <tr>
   <td><strong>Unity API</strong>: RingMetacarpal<br><strong>OpenXR</strong>: XR_HAND_JOINT_RING_METACARPAL_EXT<br><strong>Anatomic</strong>: Carpometacarpal (CMC)
   </td>
  </tr>
  <tr>
   <td><strong>Little Finger</strong>
   </td>
  </tr>
  <tr>
   <td><strong>Unity API</strong>: LittleMetacarpal<br><strong>OpenXR</strong>: XR_HAND_JOINT_LITTLE_METACARPAL_EXT<br><strong>Anatomic</strong>: Carpometacarpal (CMC)
   </td>
  </tr>
  <tr>
   <td><strong>Palm point</strong><br>
<img src="../images/gestures/palm.png" width="" alt="Palm point" title="Palm point">

   </td>
   <td><strong>Unity API</strong>: Palm
<p>
<strong>OpenXR</strong>: XR_HAND_JOINT_PALM_EXT
   </td>
  </tr>
  <tr>
   <td><strong>Wrist point</strong><br>
<img src="../images/gestures/wrist.png" width="" alt="Wrist point" title="Wrist point">

   </td>
   <td><strong>Unity API</strong>: Wrist
<p>
<strong>OpenXR</strong>: XR_HAND_JOINT_WRIST_EXT
   </td>
  </tr>
</table>

For the API declarations of the tracked points, refer to the Enum [XRHandJointID](xref:UnityEngine.XR.Hands.XRHandJointID) in the Unity API and [XrHandJointEXT](https://registry.khronos.org/OpenXR/specs/1.0/man/html/XrHandJointEXT.html) in the OpenXR specification.

