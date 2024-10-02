---
uid: xrhands-platform-gestures
---

# Platform gestures

Some XR platforms can detect hand and finger gestures using their native hardware and software capabilities. Where available, such gesture data is made available to a Unity app through a provider plugin or the platform's own, separate SDK.

The XR platforms with native gesture detection include:

| Platform | Provider plugin | Supported platform gestures |
| :------- | :-------------- | :-------------------------- |
| [OpenXR] | [OpenXR], [XR Hands]      | Pinch, aim, system gesture, system menu gesture through the Meta AIM hand OpenXR extension. Grip, aim, pinch, and poke through the Hand Interaction Poses OpenXR extension.|
| [HoloLens 2] |  [Mixed Reality OpenXR plugin] | |
| [Magic Leap 2] | Magic Leap XR plugin] | |

Platform gestures might require their own set of components or platform-specific extensions. As such they often aren't suitable for cross-platform projects.