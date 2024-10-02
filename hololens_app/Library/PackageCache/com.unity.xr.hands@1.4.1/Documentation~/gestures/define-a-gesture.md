---
uid: xrhands-define-custom-gesture
---

# Add a custom gesture to a scene

To define a custom gesture and add it to a scene:

1. Start by creating a [Hand Shape](xref:xrhands-hand-shapes) asset.
2. For each finger that must be held in a specific way, add the necessary [finger shapes](xref:xrhands-finger-shapes) to the conditions in the **Hand Shape** asset.
3. If the gesture design requires that the hand be oriented in a specific way relative to either the world Up vector or relative to the user, then create a [Hand Pose](xref:xrhands-hand-poses) asset.
4. In the **Hand Pose**, reference the **Hand Shape** and add the necessary **Hand Orientation Conditions**.
5. In the scene that should contain the gesture recognizer, create a GameObject and add a [Static Hand Gesture](xref:xrhands-static-gesture-component) component to it.

   > [!NOTE]
   > Any XR scene should already be configured with an XR Origin. The gesture component also needs a reference to an [XRHandTrackingEvents](xref:UnityEngine.XR.Hands.XRHandTrackingEvents) component in the scene to get hand tracking data. One of these components is needed for each hand. Refer to [Access hand data from Unity components in the scene](xref:xrhands-access-data) for more information. 
   
6. In the **Static Hand Gesture** component Inspector:

   1. Add a reference to the [XRHandTrackingEvents](xref:UnityEngine.XR.Hands.XRHandTrackingEvents) component for the hand that you want to perform the gesture. (If you want both hands to be able to perform a gesture, you need to add two **Static Hand Gesture** components. They can share **Hand Shape** or **Hand Pose** assets.)
   2. Add a reference to the **Hand Shape** or **Hand Pose** asset.
   3. If the gesture design requires that the hand be oriented in a specific way relative to a target GameObject in the scene, add the necessary **Hand Orientation Conditions** to identify the orientation and the target object.
   4. Adjust the recognition time properties, **Minimum Hold Time** and **Gesture Detection Interval** for reliable gesture detection.
   5. Hook up the **Gesture Performed** and **Gesture Ended** events to the appropriate event handlers in the scene.
   6. Assign your HandShape and HandPose assets to the right side missing references in the two **Gesture Performed** events.
  
A [Static Hand Gesture](xref:xrhands-static-gesture-component) component can recognize a single gesture for either the right or the left hand. Add a component for each different gesture that you want recognized. 

> [!TIP]
> You can use the [Gesture debugger](xref:xrhands-gesture-debugger) scene to help develop and test gestures. 