#if ENABLE_VR || UNITY_GAMECORE || PACKAGE_DOCS_GENERATION

using System.Collections.Generic;
using UnityEngine.InputSystem;
using UnityEngine.InputSystem.Controls;
using UnityEngine.InputSystem.Layouts;
using UnityEngine.InputSystem.XR;
using UnityEngine.Scripting;

#if UNITY_EDITOR
using UnityEditor;
#endif

namespace UnityEngine.XR.Hands
{
    /// <summary>
    /// An <see cref="InputDevice"/> that surfaces common controller data
    /// populated by hand joint poses. Devices will only be created if
    /// hand-tracking is enabled in the build settings for the target platform.
    /// </summary>
    /// <remarks>
    /// The <see cref="TrackedDevice.devicePosition"/> and
    /// <see cref="TrackedDevice.deviceRotation"/> inherited from <see cref="TrackedDevice"/>
    /// represent the wrist pose.
    ///
    /// Use the [XROrigin](xref:Unity.XR.CoreUtils.XROrigin) in the scene to position and orient the device
    /// and gesture poses properly. If you are using this data to set the Transform of a GameObject in
    /// the scene hierarchy, you can set the local position and rotation of the Transform and make
    /// it a child of the <c>CameraOffset</c> object below the <c>XROrigin</c>. Otherwise, you can use the
    /// Transform of the <c>CameraOffset</c> to transform the data into world space.
    /// </remarks>
    #if UNITY_EDITOR
    [InitializeOnLoad]
    #endif
    [Preserve, InputControlLayout(displayName = "XR Hand Device", commonUsages = new[] { "LeftHand", "RightHand" })]
    public class XRHandDevice : TrackedDevice
    {
        /// <summary>
        /// The left-hand <see cref="InputDevice"/> that contains
        /// <see cref="InputControl"/>s that surface common controller data
        /// populated by hand joint poses.
        /// </summary>
        public static XRHandDevice leftHand { get; internal set; }

        /// <summary>
        /// The right-hand <see cref="InputDevice"/> that contains
        /// <see cref="InputControl"/>s that surface common controller data
        /// populated by hand joint poses.
        /// </summary>
        public static XRHandDevice rightHand { get; internal set; }

        /// <summary>
        /// Position of the grip pose, representing the palm.
        /// When transformed relative to the [XROrigin](xref:Unity.XR.CoreUtils.XROrigin),
        /// the position will be in the correct position in the scene relative to the user.
        /// </summary>
        [Preserve, InputControl]
        public Vector3Control gripPosition { get; private set; }

        /// <summary>
        /// Rotation of the grip pose, representing the palm.
        /// When transformed relative to the [XROrigin](xref:Unity.XR.CoreUtils.XROrigin),
        /// the rotation will be in the correct orientation in the scene relative to the user.
        /// </summary>
        [Preserve, InputControl]
        public QuaternionControl gripRotation { get; private set; }

        /// <summary>
        /// Position of the poke pose, representing the index finger's tip. 
        /// When transformed relative to the [XROrigin](xref:Unity.XR.CoreUtils.XROrigin),
        /// the position will be in the correct position in the scene relative to the user.
        /// </summary>
        [Preserve, InputControl]
        public Vector3Control pokePosition { get; private set; }

        /// <summary>
        /// Rotation of the poke pose, representing the index finger's tip.
        /// When transformed relative to the [XROrigin](xref:Unity.XR.CoreUtils.XROrigin),
        /// the rotation will be in the correct orientation in the scene relative to the user.
        /// </summary>
        [Preserve, InputControl]
        public QuaternionControl pokeRotation { get; private set; }

        /// <summary>
        /// Position of the pinch pose, representing the thumb's tip.
        /// When transformed relative to the [XROrigin](xref:Unity.XR.CoreUtils.XROrigin),
        /// the position will be in the correct position in the scene relative to the user.
        /// </summary>
        [Preserve, InputControl]
        public Vector3Control pinchPosition { get; private set; }

        /// <summary>
        /// Rotation of the pinch pose, representing the thumb's tip.
        /// When transformed relative to the [XROrigin](xref:Unity.XR.CoreUtils.XROrigin),
        /// the rotation will be in the correct orientation in the scene relative to the user.
        /// </summary>
        [Preserve, InputControl]
        public QuaternionControl pinchRotation { get; private set; }

        /// <summary>
        /// Perform final initialization tasks after the control hierarchy has been put into place.
        /// </summary>
        protected override void FinishSetup()
        {
            base.FinishSetup();

            gripPosition = GetChildControl<Vector3Control>("gripPosition");
            gripRotation = GetChildControl<QuaternionControl>("gripRotation");
            pokePosition = GetChildControl<Vector3Control>("pokePosition");
            pokeRotation = GetChildControl<QuaternionControl>("pokeRotation");
            pinchPosition = GetChildControl<Vector3Control>("pinchPosition");
            pinchRotation = GetChildControl<QuaternionControl>("pinchRotation");

            var deviceDescriptor = XRDeviceDescriptor.FromJson(description.capabilities);
            if (deviceDescriptor != null)
            {
                if ((deviceDescriptor.characteristics & InputDeviceCharacteristics.Left) != 0)
                    InputSystem.InputSystem.SetDeviceUsage(this, InputSystem.CommonUsages.LeftHand);
                else if ((deviceDescriptor.characteristics & InputDeviceCharacteristics.Right) != 0)
                    InputSystem.InputSystem.SetDeviceUsage(this, InputSystem.CommonUsages.RightHand);
            }
        }

        internal static XRHandDevice Create(
            XRHandSubsystem subsystem,
            Handedness handedness,
            XRHandSubsystem.UpdateSuccessFlags updateSuccessFlags,
            XRHandSubsystem.UpdateType updateType)
        {
            var extraCharacteristics = handedness == Handedness.Left ? InputDeviceCharacteristics.Left : InputDeviceCharacteristics.Right;

            var desc = new InputDeviceDescription
            {
                product = k_DeviceProductName,
                capabilities = new XRDeviceDescriptor
                {
                    characteristics = InputDeviceCharacteristics.HandTracking | InputDeviceCharacteristics.TrackedDevice | extraCharacteristics,
                    inputFeatures = new List<XRFeatureDescriptor>
                    {
                        new XRFeatureDescriptor
                        {
                            name = "grip_position",
                            featureType = FeatureType.Axis3D
                        },
                        new XRFeatureDescriptor
                        {
                            name = "grip_rotation",
                            featureType = FeatureType.Rotation
                        },
                        new XRFeatureDescriptor
                        {
                            name = "poke_position",
                            featureType = FeatureType.Axis3D
                        },
                        new XRFeatureDescriptor
                        {
                            name = "poke_rotation",
                            featureType = FeatureType.Rotation
                        },
                        new XRFeatureDescriptor
                        {
                            name = "pinch_position",
                            featureType = FeatureType.Axis3D
                        },
                        new XRFeatureDescriptor
                        {
                            name = "pinch_rotation",
                            featureType = FeatureType.Rotation
                        }
                    }
                }.ToJson()
            };
            var handDevice = InputSystem.InputSystem.AddDevice(desc) as XRHandDevice;
            if (handDevice != null)
            {
                subsystem.updatedHands += handDevice.OnUpdatedHands;
                handDevice.m_Handedness = handedness;

                handDevice.OnUpdatedHands(subsystem, updateSuccessFlags, updateType);
            }

            return handDevice;
        }

        void OnUpdatedHands(XRHandSubsystem subsystem, XRHandSubsystem.UpdateSuccessFlags updateSuccessFlags, XRHandSubsystem.UpdateType updateType)
        {
            XRHand hand;
            bool isValid;
            if (m_Handedness == Handedness.Left)
            {
                hand = subsystem.leftHand;
                var success = XRHandSubsystem.UpdateSuccessFlags.LeftHandRootPose | XRHandSubsystem.UpdateSuccessFlags.LeftHandJoints;
                isValid = (updateSuccessFlags & success) == success;
            }
            else
            {
                hand = subsystem.rightHand;
                var success = XRHandSubsystem.UpdateSuccessFlags.RightHandRootPose | XRHandSubsystem.UpdateSuccessFlags.RightHandJoints;
                isValid = (updateSuccessFlags & success) == success;
            }

            if (!m_WasValid && !isValid)
                return;

            if (m_WasValid && !isValid)
            {
                InputSystem.InputSystem.QueueDeltaStateEvent(isTracked, false);
                InputSystem.InputSystem.QueueDeltaStateEvent(trackingState, InputTrackingState.None);
                m_WasValid = false;
                return;
            }

            if (!m_WasValid && isValid)
            {
                InputSystem.InputSystem.QueueDeltaStateEvent(isTracked, true);
                InputSystem.InputSystem.QueueDeltaStateEvent(trackingState, InputTrackingState.Position | InputTrackingState.Rotation);
                m_WasValid = true;
            }

            if (hand.GetJoint(XRHandJointID.Wrist).TryGetPose(out var wristPose))
            {
                InputSystem.InputSystem.QueueDeltaStateEvent(devicePosition, wristPose.position);
                InputSystem.InputSystem.QueueDeltaStateEvent(deviceRotation, wristPose.rotation);
            }

            if (hand.GetJoint(XRHandJointID.Palm).TryGetPose(out var palmPose))
            {
                InputSystem.InputSystem.QueueDeltaStateEvent(gripPosition, palmPose.position);
                InputSystem.InputSystem.QueueDeltaStateEvent(gripRotation, palmPose.rotation);
            }

            if (hand.GetJoint(XRHandJointID.IndexTip).TryGetPose(out var indexTipPose))
            {
                InputSystem.InputSystem.QueueDeltaStateEvent(pokePosition, indexTipPose.position);
                InputSystem.InputSystem.QueueDeltaStateEvent(pokeRotation, indexTipPose.rotation);
            }

            if (hand.GetJoint(XRHandJointID.ThumbTip).TryGetPose(out var thumbTipPose))
            {
                InputSystem.InputSystem.QueueDeltaStateEvent(pinchPosition, thumbTipPose.position);
                InputSystem.InputSystem.QueueDeltaStateEvent(pinchRotation, thumbTipPose.rotation);
            }
        }

        static XRHandDevice() => Initialize();

        [RuntimeInitializeOnLoadMethod(RuntimeInitializeLoadType.SubsystemRegistration)]
        static void Initialize()
        {
#if ENABLE_INPUT_SYSTEM
            InputSystem.InputSystem.RegisterLayout<XRHandDevice>(
                matches: new InputDeviceMatcher()
                .WithProduct(k_DeviceProductName));
#endif // ENABLE_INPUT_SYSTEM
        }

        const string k_DeviceProductName = "XRHandDevice";

        Handedness m_Handedness;
        bool m_WasValid;
    }
}

#endif // ENABLE_VR || UNITY_GAMECORE || PACKAGE_DOCS_GENERATION
