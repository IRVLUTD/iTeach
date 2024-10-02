---
uid: xrhands-changelog
---
# Changelog
All notable changes to this package will be documented in this file.

The format is based on [Keep a Changelog](http://keepachangelog.com/en/1.0.0/)
and this project adheres to [Semantic Versioning](http://semver.org/spec/v2.0.0.html).

## [1.4.1] - 2024-04-05

### Changed
- Split hand pose debug UI into hand shape and hand pose to make it simpler to debug in each scenario.
- Updated hand shape debugger with added cross and check mark icon sprites for finger state gesture debug UI

### Fixed
- Fixed performance regression in hand gesture debug UI.
- Fix tolerance range check in `XRFingerShapeCondition` component.

## [1.4.0] - 2024-02-27

### Changed
- Changed gesture detection to allow both upper and lower threshold for more finely-tuned configuration of the finger shapes.
- Added partial-grab gesture detection to the Gestures sample.
- Changed hand and gesture tracking debug UI to support upper threshold, lower threshold, and partial-grab gesture.
- Updated visuals for hand and gesture tracking debug UI in the Gestures sample.

### Fixed
- Fixed compilation errors on tvOS platform where `ENABLE_VR` is not defined.

## [1.4.0-pre.1] - 2023-11-27

### Added
- Added support for custom gestures. For additional information, refer to the [manual documentation](xref:xrhands-custom-gestures).

### Fixed
- OpenXR implementation now correctly responds to feature lifecycle callbacks.

## [1.3.0] - 2023-08-14

### Added
- Added a root pose offset to the `XRHandSkeletonDriver` that allows an additional offset to the root pose (typically the wrist). This is useful for situations where you want the visual hand representation to stop while interacting with objects in a scene.
- Added missing sample script API documentation to make it easier to understand and build from.

### Fixed
- Fixed documentation links for OpenXR features to point at latest documentation version.

## [1.2.1] - 2023-05-30

### Fixed
- Fixed build pipeline that caused `UnityOpenXRHands` assembly to get skipped.

## [1.2.0] - 2023-05-25

### Added

- Added `IXRHandProcessor` interface that intercepts and allows post-processing joint data before being used by other scripts. More information can be found on the [XR Hands Joint Processing](xref:xrhands-process-joints) manual page.
- Added two samples to the Hand Visualizer sample for how to use the new Joint Processing feature to change the visual output of hand tracking.
- `XRHand` and `XRHandJoint` both now implement `IEquatable`, and have `Equals`, `GetHashCode`, and the `==` and `!=` operators overloaded.
- Added `XRHandTrackingEvents` component that subscribes to hand tracking events for a specific hand and surfaces Unity Events when the hand updates or tracking state changes.
- Added `XRHandMeshController` component that subscribes to events from a `XRHandTrackingEvents` and can optionally show or hide a mesh.
- Added `XRHandSkeletonDriver` component that subscribes to events from a `XRHandTrackingEvents` and updates a hierarchy of Transforms for each `XRHandJoint`.

### Changed
- Minimum supported Unity Editor version has changed to 2021.3.

### Fixed

- Fixed Hand Visualizer component so it will use another running `XRHandSubsystem` if the first is stopped.
- Fixed exception in Hand Visualizer component when a joint is invalid.
- Fixed rendering of lines that connect joints in `HandVisualizer` sample when used with the device simulator. Also removed the Origin property from the component since it was no longer used.

## [1.1.0] - 2023-03-16

### Added

- Added `isTracked` to `XRHand`.
- Added `trackingAcquired` and `trackingLost` to `XRHandSubsystem`.
- Added `XRHandDevice` and automatic managing of it if the Input System is enabled and hand-tracking is enabled in the target platform's build settings.
- The `HandVisualizer` sample now opts into using optimized controls in the Input System if you enable the **Use Optimized Controls** option. You must be on at least version 1.5.0 of the Input System package for this to have an effect.
- Added `handedness` getter property to `XRHandJoint`.
- Added `updateSuccessFlags` property to `XRHandSubsystem` to allow the most recent `UpdateSuccessFlags` to be polled. This value matches the argument to the `updatedHands` callback.

The OpenXR package must be installed and enabled for these to work:
- Added OpenXR support through `HandTracking` and `OpenXRHandProvider` types.
- Added support for Meta Hand Tracking Aim extension in OpenXR through `MetaHandTrackingAim`.

### Changed

- `MetaAimHand` and `MetaAimFlags` have been moved outside of the `MetaHandTrackingAim` type and moved from the `UnityEngine.XR.Hands.OpenXR` namespace to `UnityEngine.XR.Hands`. The same input bindings will work the same as before.
- The HandVisualizer sample meshes has been updated.
- Changed Hand Visualizer component so it skips setting the shared material on the instantiated hand mesh prefabs when the Hand Mesh Material property is not set.
- Providers must now create joints with a known `Handedness` during `TryUpdateHands` when calling `XRHandProviderUtility.CreateJoint`.
- Changed Meta Aim Hand input devices that are added to the Input System to continue updating the `devicePosition` and `deviceRotation` controls even when the `MetaAimFlags.Valid` bit flag is not set. Instead it uses whether the hand root is valid. In practice, the `MetaAimFlags.Valid` flag currently does not necessarily indicate whether the pose is valid but instead is based on whether the user is in a natural orientation for distant UI panel selection.
- Changed HandVisualizer sample by adding an Assembly Definition file (`.asmdef`).

### Fixed

- Fixed issue where OpenXR would incorrectly report joints as having updated when they weren't actually tracked that frame. `XRHandSubsystem`'s `trackingAcquired` and `trackingLost`, as well as `XRHand.isTracked`, will now work as expected.
- Fixed issue where `<XRHandDevice>/isTracked` and `<XRHandDevice>/trackingState` controls would never clear.
- Fixed `XRHandDevice` and `MetaAimHand` to also include `InputDeviceCharacteristics.TrackedDevice` in the `XRDeviceDescriptor`.
- Fixed lifetime of GameObjects in `HandVisualizer` sample.
- Fixed `HandVisualizer` so it uses the `XROrigin.Origin` property instead of the Transform of the `XROrigin` itself when transforming joints.
- Reinstated the validation rule that the Meta Touch Interaction Profile is required in the OpenXR Interaction Profiles list.
- OpenXR hand root poses now match the wrist, not the palm.

## [1.0.0-pre.2] - 2022-10-26

### Added

Added subsystem for cross-platform hand-tracking and accompanying types.

Types you might care about as a user:
- `XRHandSubsystemDescriptor`, which you can retrieve a `List` of with `SubsystemManager.GetSubsystemDescriptors`.
- `XRHandSubsystem`, which can be created with a call to `Create` on the above descriptor type.
- `XRHand`, which you can retrieve from `XRHandSubsystem` with its `leftHand` and `rightHand` properties. These contain joints and `rootPose` data, as well as its `Handedness`.
- `XRHandJoint`, which you can retrieve from each `XRHand` using `GetJoint` to query for joint tracking state, pose, radius, and velocity data on a per-joint basis.
- `XRHandJointIDUtility`, which contains extension methods for certain `enum`s listed below and also houses `FromIndex`, which you can use when looping over an array to get the corresponding `XRHandJointID` (useful when calling `XRHand.GetJoint`).

As well as these `enum`s:
- `XRHandJointTrackingState`, a flags-`enum` used to denote which fields are valid and can be retrieved via their `TryGet...` methods on `XRHandJoint`.
- `XRHandJointID`, used to identify each joint, and required when accessing joint data using `XRHand.GetJoint`. If looping over an array of joint data, use `XRHandJointIDUtility.FromIndex` to convert your index to `XRHandJointID`, which is required for `XRHand.GetJoint`.
- `Handedness`, used to identify which hand is referred to by an `XRHand` using its `handedness` property.
- `XRHandFingerID`, not used anywhere else in the API surfaced in this package besides its extension methods in `XRHandJointIDUtility`: `GetFrontJointID` and `GetBackJointID`, which together provider an inclusive range for `XRHandJointID`s spanned by the finger represented by `XRHandFingerID`.

Additional types you may need to interact with if writing a provider (not a common use case):
- `XRHandSubsystemProvider`, which the subsystem asks for data whenever its `TryUpdateHands` is called (built-in Unity setup calls this each frame) and is also queried when the subsystem and provider are created for which common joints are in the provider's layout using `GetHandLayout`.
- `XRHandProviderUtility`, which providers should call into using `CreateJoint` during the `TryUpdateHands` per-frame call to fill out the left- and right-hand joint arrays. This same type also has a nested `SubsystemUpdater` type to be used for automatically updating the subsystem each frame. Users can respond to updates by subscribing to the subsystem's `handsUpdated` callback.

Also added a visualizer sample, which demonstrates drawing using both meshes and per-joint prefabs. You can add this sample to your project through the Samples tab of this package's view in the Package Manager window. This sample has a mesh and script that assume OpenXR layout, so it is recommended you either use that plug-in or another one that conforms to the OpenXR hand joint layout.
