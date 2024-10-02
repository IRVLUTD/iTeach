---
uid: xrhands-openxr-hands-feature
---

# Hand tracking OpenXR feature

Unity OpenXR provides support for the Hand Tracking extension specified by Khronos. Use this feature to have Unity manage and update an `XRHandSubsystem`. To subscribe to updates, use `XRHandSubsystem.updatedHands`.

For this extension to be available, you must install the [OpenXR package](https://docs.unity3d.com/Packages/com.unity.xr.openxr@latest).

For this extension to work when deployed to a Meta Quest device, your OpenXR package must be set to at least version 1.6.0.

For background information about the Hand Tracking extension, refer to the [OpenXR Specification](https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#XR_EXT_hand_tracking).
