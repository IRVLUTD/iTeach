---
uid: xrhands-meta-aim-feature
---
# Meta Aim Hand OpenXR feature

Unity OpenXR provides support for the Meta Hand Tracking Aim extension specified by Khronos. For this extension to work, you must also enable the [Hand Tracking feature](handtracking.md).

For this extension to be available, you must install the [OpenXR package](https://docs.unity3d.com/Packages/com.unity.xr.openxr@latest).

For this extension to work when deployed to a Meta Quest device, your OpenXR package must be set to at least version 1.6.0.

You can either use the Unity Input System drop-down menus in the editing UI for Input Action Assets, or directly enter bindings as shown below.

|**Data**|**Generic Binding Path**|
|--------|------------|
|Position|`<TrackedDevice>/devicePosition` or `<MetaAimHand>/devicePosition`|
|Rotation|`<TrackedDevice>/deviceRotation` or `<MetaAimHand>/deviceRotation`|
|Is Tracked|`<TrackedDevice>/isTracked` or `<MetaAimHand>/isTracked`|
|Tracking State|`<TrackedDevice>/trackingState` or `<MetaAimHand>/trackingState`|
|Aim Flags|`<MetaAimHand>/aimFlags`|
|Index Pinch Strength|`<MetaAimHand>/pinchStrengthIndex`|
|Middle Pinch Strength|`<MetaAimHand>/pinchStrengthMiddle`|
|Ring Pinch Strength|`<MetaAimHand>/pinchStrengthRing`|
|Little Pinch Strength|`<MetaAimHand>/pinchStrengthLittle`|
|Is Index Pressed|`<MetaAimHand>/indexPressed`|
|Is Middle Pressed|`<MetaAimHand>/middlePressed`|
|Is Ring Pressed|`<MetaAimHand>/ringPressed`|
|Is Little Pressed|`<MetaAimHand>/littlePressed`|

To specify a particular hand instead of either, you can add `/{leftHand}` or `/{rightHand}` after the `>` in the binding.

For more information about the Meta Hand Tracking Aim extension, see the [OpenXR Specification](https://registry.khronos.org/OpenXR/specs/1.0/html/xrspec.html#XR_FB_hand_tracking_aim).
