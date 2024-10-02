---
uid: xrhands-custom-gestures
---

# Custom gestures

The XR Hands package provides a custom gesture recognizer that can detect when the user performs a gesture that you define as a hand shape and orientation. 

> [!IMPORTANT]
> The recognizer can detect static poses only. Gestures involving motion, such as a swipe or a throw, are not supported.

To add a custom gesture to a scene, you create and configure a [Static Hand Gesture](xref:xrhands-static-gesture-component) component. This component references a [Hand Shape](xref:xrhands-hand-shapes) or [Hand Pose](xref:xrhands-hand-poses) asset and an [XR Hand Tracking Events](xref:UnityEngine.XR.Hands.XRHandTrackingEvents) object. It dispatches [UnityEvents](xref:UnityEngine.Events.UnityEvent) when it detects that the user's hand matches the configured hand shape and orientation and when a gesture is no longer detected.

For more information about designing and configuring custom gestures with the XR Hands package, refer to the following topics:

| Topic | Description |
| :---- | :---------- |
| [Gesture design](xref:xrhands-gesture-design) | Discusses the possibilities and challenges to consider when designing your own gestures. |
| [Gesture building blocks](xref:xrhands-gesture-building-blocks) | Outlines the concepts, assets, and components involved in defining a gesture. |
| [Finger shape](xref:xrhands-finger-shapes) | Describes the aspects of a finger shape that you can specify as part of the required hand shape of a gesture. |
| [Orientation](xref:xrhands-hand-orientation) | Provides an overview and visual examples of how you can specified a required orientation for a gesture. |
| [Hand Shape](xref:xrhands-hand-shapes) | How to create and edit Hand Shape assets. |
| [Hand Pose](xref:xrhands-hand-poses) | How to create and edit Hand Pose assets. |
| [Static Hand Gesture component](xref:xrhands-static-gesture-component) | Describes the properties of the **Static Hand Gesture** component. |
| [Add a custom gesture](xref:xrhands-define-custom-gesture) | Covers the mechanics of adding a recognizer for a custom gesture to a scene. |

> [!IMPORTANT]
> You must import the **Gestures** sample provided by the XR Hands package to use the **Static Hand Gesture** component. Refer to [Samples](xref:xrhands-manual#samples) for instructions.
