#if ENABLE_VR || UNITY_GAMECORE || PACKAGE_DOCS_GENERATION

using System;
using System.Collections.Generic;
using System.Runtime.InteropServices;
using UnityEngine.InputSystem;
using UnityEngine.InputSystem.Controls;
using UnityEngine.InputSystem.Layouts;
using UnityEngine.InputSystem.XR;
using UnityEngine.Scripting;

namespace UnityEngine.XR.Hands
{
    /// <summary>
    /// The flags in the extension for each hand that can be read from
    /// <see cref="MetaAimHand.aimFlags"/> and casting to this type.
    /// </summary>
    [Flags]
    [Preserve]
    public enum MetaAimFlags : ulong
    {
        /// <summary>
        /// No flags are valid.
        /// </summary>
        None = 0,

        /// <summary>
        /// Data for this hand has been computed.
        /// </summary>
        Computed = 1 << 0,

        /// <summary>
        /// The aim pose is generally pointed away from the face and is valid
        /// for use with UI.
        /// </summary>
        Valid = 1 << 1,

        /// <summary>
        /// Indicates whether the index finger is pinching with the thumb.
        /// Only valid when the pinch strength retrieved from
        /// <see cref="MetaAimHand.pinchStrengthIndex"/> is
        /// at a full strength of <c>1.0</c>.
        /// </summary>
        IndexPinching = 1 << 2,

        /// <summary>
        /// Indicates whether the middle finger is pinching with the thumb.
        /// Only valid when the pinch strength retrieved from
        /// <see cref="MetaAimHand.pinchStrengthMiddle"/> is
        /// at a full strength of <c>1.0</c>.
        /// </summary>
        MiddlePinching = 1 << 3,

        /// <summary>
        /// Indicates whether the ring finger is pinching with the thumb.
        /// Only valid when the pinch strength retrieved from
        /// <see cref="MetaAimHand.pinchStrengthRing"/> is
        /// at a full strength of <c>1.0</c>.
        /// </summary>
        RingPinching = 1 << 4,

        /// <summary>
        /// Indicates whether the little finger is pinching with the thumb.
        /// Only valid when the pinch strength retrieved from
        /// <see cref="MetaAimHand.pinchStrengthLittle"/> is
        /// at a full strength of <c>1.0</c>.
        /// </summary>
        LittlePinching = 1 << 5,

        /// <summary>
        /// Indicates whether a system gesture is being performed (when the
        /// palm of the hand is facing the headset).
        /// </summary>
        SystemGesture = 1 << 6,

        /// <summary>
        /// Indicates whether the hand these flags were retrieved from is
        /// the dominant hand.
        /// </summary>
        DominantHand = 1 << 7,

        /// <summary>
        /// Indicates whether the menu gesture button is pressed.
        /// </summary>
        MenuPressed = 1 << 8,
    }

    /// <summary>
    /// A <see cref="TrackedDevice"/> based off the data exposed in the
    /// <see href="https://registry.khronos.org/OpenXR/specs/1.0/html/xrspec.html#XR_FB_hand_tracking_aim">
    /// Meta Hand Tracking Aim extension</see>. Enabled through [Meta Hand Tracking Aim](xref:UnityEngine.XR.Hands.OpenXR.MetaHandTrackingAim)
    /// or by enabling hand-tracking in the Oculus plug-in if the Input System
    /// back-end is enabled.
    /// </summary>
    /// <remarks>
    /// For this type to function, you must enable hand-tracking and be running
    /// with either the OpenXR or Oculus plug-in.
    /// 
    /// The <see cref="TrackedDevice.devicePosition"/> and
    /// <see cref="TrackedDevice.deviceRotation"/> inherited from <see cref="TrackedDevice"/>
    /// represent the aim pose. You can use these values to discover the target for pinch gestures,
    /// when appropriate. 
    /// 
    /// Use the [XROrigin](xref:Unity.XR.CoreUtils.XROrigin) in the scene to position and orient
    /// the device properly. If you are using this data to set the Transform of a GameObject in
    /// the scene hierarchy, you can set the local position and rotation of the Transform and make
    /// it a child of the <c>CameraOffset</c> object below the <c>XROrigin</c>. Otherwise, you can use the
    /// Transform of the <c>CameraOffset</c> to transform the data into world space.
    /// </remarks>
#if UNITY_EDITOR
    [UnityEditor.InitializeOnLoad]
#endif
    [Preserve, InputControlLayout(displayName = "Meta Aim Hand", commonUsages = new[] { "LeftHand", "RightHand" })]
    public partial class MetaAimHand : TrackedDevice
    {
        /// <summary>
        /// The left-hand <see cref="InputDevice"/> that contains
        /// <see cref="InputControl"/>s that surface data in the Meta Hand
        /// Tracking Aim extension.
        /// </summary>
        /// <remarks>
        /// It is recommended that you treat this as read-only, and do not set
        /// it yourself. It will be set for you if hand-tracking has been
        /// enabled and if you are running with either the OpenXR or Oculus
        /// plug-in.
        /// </remarks>
        public static MetaAimHand left { get; set; }

        /// <summary>
        /// The right-hand <see cref="InputDevice"/> that contains
        /// <see cref="InputControl"/>s that surface data in the Meta Hand
        /// Tracking Aim extension.
        /// </summary>
        /// <remarks>
        /// It is recommended that you treat this as read-only, and do not set
        /// it yourself. It will be set for you if hand-tracking has been
        /// enabled and if you are running with either the OpenXR or Oculus
        /// plug-in.
        /// </remarks>
        public static MetaAimHand right { get; set; }

        /// <summary>
        /// The pinch amount required to register as being pressed for the
        /// purposes of <see cref="indexPressed"/>, <see cref="middlePressed"/>,
        /// <see cref="ringPressed"/>, and <see cref="littlePressed"/>.
        /// </summary>
        public const float pressThreshold = 0.8f;

        /// <summary>
        /// A [ButtonControl](xref:UnityEngine.InputSystem.Controls.ButtonControl)
        /// that represents whether the pinch between the index finger and
        /// the thumb is mostly pressed (greater than a threshold of <c>0.8</c>
        /// contained in <see cref="pressThreshold"/>).
        /// </summary>
        [Preserve, InputControl(offset = 0)]
        public ButtonControl indexPressed { get; private set; }

        /// <summary>
        /// A [ButtonControl](xref:UnityEngine.InputSystem.Controls.ButtonControl)
        /// that represents whether the pinch between the middle finger and
        /// the thumb is mostly pressed (greater than a threshold of <c>0.8</c>
        /// contained in <see cref="pressThreshold"/>).
        /// </summary>
        [Preserve, InputControl(offset = 1)]
        public ButtonControl middlePressed { get; private set; }

        /// <summary>
        /// A [ButtonControl](xref:UnityEngine.InputSystem.Controls.ButtonControl)
        /// that represents whether the pinch between the ring finger and
        /// the thumb is mostly pressed (greater than a threshold of <c>0.8</c>
        /// contained in <see cref="pressThreshold"/>).
        /// </summary>
        [Preserve, InputControl(offset = 2)]
        public ButtonControl ringPressed { get; private set; }

        /// <summary>
        /// A [ButtonControl](xref:UnityEngine.InputSystem.Controls.ButtonControl)
        /// that represents whether the pinch between the little finger and
        /// the thumb is mostly pressed (greater than a threshold of <c>0.8</c>
        /// contained in <see cref="pressThreshold"/>).
        /// </summary>
        [Preserve, InputControl(offset = 3)]
        public ButtonControl littlePressed { get; private set; }

        /// <summary>
        /// Cast the result of reading this to <see cref="MetaAimFlags"/> to examine the value.
        /// </summary>
        [Preserve, InputControl]
        public IntegerControl aimFlags { get; private set; }

        /// <summary>
        /// An [AxisControl](xref:UnityEngine.InputSystem.Controls.AxisControl)
        /// that represents the pinch strength between the index finger and
        /// the thumb.
        /// </summary>
        /// <remarks>
        /// A value of <c>0</c> denotes no pinch at all, while a value of
        /// <c>1</c> denotes a full pinch.
        /// </remarks>
        [Preserve, InputControl]
        public AxisControl pinchStrengthIndex { get; private set; }

        /// <summary>
        /// An [AxisControl](xref:UnityEngine.InputSystem.Controls.AxisControl)
        /// that represents the pinch strength between the middle finger and
        /// the thumb.
        /// </summary>
        /// <remarks>
        /// A value of <c>0</c> denotes no pinch at all, while a value of
        /// <c>1</c> denotes a full pinch.
        /// </remarks>
        [Preserve, InputControl]
        public AxisControl pinchStrengthMiddle { get; private set; }

        /// <summary>
        /// An [AxisControl](xref:UnityEngine.InputSystem.Controls.AxisControl)
        /// that represents the pinch strength between the ring finger and
        /// the thumb.
        /// </summary>
        /// <remarks>
        /// A value of <c>0</c> denotes no pinch at all, while a value of
        /// <c>1</c> denotes a full pinch.
        /// </remarks>
        [Preserve, InputControl]
        public AxisControl pinchStrengthRing { get; private set; }

        /// <summary>
        /// An [AxisControl](xref:UnityEngine.InputSystem.Controls.AxisControl)
        /// that represents the pinch strength between the little finger and
        /// the thumb.
        /// </summary>
        /// <remarks>
        /// A value of <c>0</c> denotes no pinch at all, while a value of
        /// <c>1</c> denotes a full pinch.
        /// </remarks>
        [Preserve, InputControl]
        public AxisControl pinchStrengthLittle { get; private set; }

        /// <summary>
        /// Perform final initialization tasks after the control hierarchy has been put into place.
        /// </summary>
        protected override void FinishSetup()
        {
            base.FinishSetup();

            indexPressed = GetChildControl<ButtonControl>(nameof(indexPressed));
            middlePressed = GetChildControl<ButtonControl>(nameof(middlePressed));
            ringPressed = GetChildControl<ButtonControl>(nameof(ringPressed));
            littlePressed = GetChildControl<ButtonControl>(nameof(littlePressed));
            aimFlags = GetChildControl<IntegerControl>(nameof(aimFlags));
            pinchStrengthIndex = GetChildControl<AxisControl>(nameof(pinchStrengthIndex));
            pinchStrengthMiddle = GetChildControl<AxisControl>(nameof(pinchStrengthMiddle));
            pinchStrengthRing = GetChildControl<AxisControl>(nameof(pinchStrengthRing));
            pinchStrengthLittle = GetChildControl<AxisControl>(nameof(pinchStrengthLittle));

            var deviceDescriptor = XRDeviceDescriptor.FromJson(description.capabilities);
            if (deviceDescriptor != null)
            {
                if ((deviceDescriptor.characteristics & InputDeviceCharacteristics.Left) != 0)
                    InputSystem.InputSystem.SetDeviceUsage(this, InputSystem.CommonUsages.LeftHand);
                else if ((deviceDescriptor.characteristics & InputDeviceCharacteristics.Right) != 0)
                    InputSystem.InputSystem.SetDeviceUsage(this, InputSystem.CommonUsages.RightHand);
            }
        }

        /// <summary>
        /// Creates a <see cref="MetaAimHand"/> and adds it to the Input System.
        /// </summary>
        /// <param name="extraCharacteristics">
        /// Additional characteristics to build the hand device with besides
        /// <see cref="InputDeviceCharacteristics.HandTracking"/> and <see cref="InputDeviceCharacteristics.TrackedDevice"/>.
        /// </param>
        /// <returns>
        /// A <see cref="MetaAimHand"/> retrieved from
        /// <see cref="InputSystem.InputSystem.AddDevice(InputDeviceDescription)"/>.
        /// </returns>
        /// <remarks>
        /// It is recommended that you do not call this yourself. It will be
        /// called for you at the appropriate time if hand-tracking has been
        /// enabled and if you are running with either the OpenXR or Oculus
        /// plug-in.
        /// </remarks>
        public static MetaAimHand CreateHand(InputDeviceCharacteristics extraCharacteristics)
        {
            var desc = new InputDeviceDescription
            {
                product = k_MetaAimHandDeviceProductName,
                manufacturer = k_MetaAimHandDeviceManufacturerName,
                capabilities = new XRDeviceDescriptor
                {
                    characteristics = InputDeviceCharacteristics.HandTracking | InputDeviceCharacteristics.TrackedDevice | extraCharacteristics,
                    inputFeatures = new List<XRFeatureDescriptor>
                    {
                        new XRFeatureDescriptor
                        {
                            name = "index_pressed",
                            featureType = FeatureType.Binary
                        },
                        new XRFeatureDescriptor
                        {
                            name = "middle_pressed",
                            featureType = FeatureType.Binary
                        },
                        new XRFeatureDescriptor
                        {
                            name = "ring_pressed",
                            featureType = FeatureType.Binary
                        },
                        new XRFeatureDescriptor
                        {
                            name = "little_pressed",
                            featureType = FeatureType.Binary
                        },
                        new XRFeatureDescriptor
                        {
                            name = "aim_flags",
                            featureType = FeatureType.DiscreteStates
                        },
                        new XRFeatureDescriptor
                        {
                            name = "aim_pose_position",
                            featureType = FeatureType.Axis3D
                        },
                        new XRFeatureDescriptor
                        {
                            name = "aim_pose_rotation",
                            featureType = FeatureType.Rotation
                        },
                        new XRFeatureDescriptor
                        {
                            name = "pinch_strength_index",
                            featureType = FeatureType.Axis1D
                        },
                        new XRFeatureDescriptor
                        {
                            name = "pinch_strength_middle",
                            featureType = FeatureType.Axis1D
                        },
                        new XRFeatureDescriptor
                        {
                            name = "pinch_strength_ring",
                            featureType = FeatureType.Axis1D
                        },
                        new XRFeatureDescriptor
                        {
                            name = "pinch_strength_little",
                            featureType = FeatureType.Axis1D
                        }
                    }
                }.ToJson()
            };
            return InputSystem.InputSystem.AddDevice(desc) as MetaAimHand;
        }

        /// <summary>
        /// Queues update events in the Input System based on the supplied hand.
        /// It is not recommended that you call this directly. This will be called
        /// for you when appropriate.
        /// </summary>
        /// <param name="isHandRootTracked">
        /// Whether the hand root pose is valid.
        /// </param>
        /// <param name="aimFlags">
        /// The aim flags to update in the Input System.
        /// </param>
        /// <param name="aimPose">
        /// The aim pose to update in the Input System. Used if the hand root is tracked.
        /// </param>
        /// <param name="pinchIndex">
        /// The pinch strength for the index finger to update in the Input System.
        /// </param>
        /// <param name="pinchMiddle">
        /// The pinch strength for the middle finger to update in the Input System.
        /// </param>
        /// <param name="pinchRing">
        /// The pinch strength for the ring finger to update in the Input System.
        /// </param>
        /// <param name="pinchLittle">
        /// The pinch strength for the little finger to update in the Input System.
        /// </param>
        public void UpdateHand(
            bool isHandRootTracked,
            MetaAimFlags aimFlags,
            Pose aimPose,
            float pinchIndex,
            float pinchMiddle,
            float pinchRing,
            float pinchLittle)
        {
            if (aimFlags != m_PreviousFlags)
            {
                InputSystem.InputSystem.QueueDeltaStateEvent(this.aimFlags, (int)aimFlags);
                m_PreviousFlags = aimFlags;
            }

            bool isIndexPressed = pinchIndex > pressThreshold;
            if (isIndexPressed != m_WasIndexPressed)
            {
                InputSystem.InputSystem.QueueDeltaStateEvent(indexPressed, isIndexPressed);
                m_WasIndexPressed = isIndexPressed;
            }

            bool isMiddlePressed = pinchMiddle > pressThreshold;
            if (isMiddlePressed != m_WasMiddlePressed)
            {
                InputSystem.InputSystem.QueueDeltaStateEvent(middlePressed, isMiddlePressed);
                m_WasMiddlePressed = isMiddlePressed;
            }

            bool isRingPressed = pinchRing > pressThreshold;
            if (isRingPressed != m_WasRingPressed)
            {
                InputSystem.InputSystem.QueueDeltaStateEvent(ringPressed, isRingPressed);
                m_WasRingPressed = isRingPressed;
            }

            bool isLittlePressed = pinchLittle > pressThreshold;
            if (isLittlePressed != m_WasLittlePressed)
            {
                InputSystem.InputSystem.QueueDeltaStateEvent(littlePressed, isLittlePressed);
                m_WasLittlePressed = isLittlePressed;
            }

            InputSystem.InputSystem.QueueDeltaStateEvent(pinchStrengthIndex, pinchIndex);
            InputSystem.InputSystem.QueueDeltaStateEvent(pinchStrengthMiddle, pinchMiddle);
            InputSystem.InputSystem.QueueDeltaStateEvent(pinchStrengthRing, pinchRing);
            InputSystem.InputSystem.QueueDeltaStateEvent(pinchStrengthLittle, pinchLittle);

            if ((aimFlags & MetaAimFlags.Computed) == MetaAimFlags.None)
            {
                if (m_WasTracked)
                {
                    InputSystem.InputSystem.QueueDeltaStateEvent(isTracked, false);
                    InputSystem.InputSystem.QueueDeltaStateEvent(trackingState, InputTrackingState.None);
                    m_WasTracked = false;
                }

                return;
            }

            if (isHandRootTracked)
            {
                InputSystem.InputSystem.QueueDeltaStateEvent(devicePosition, aimPose.position);
                InputSystem.InputSystem.QueueDeltaStateEvent(deviceRotation, aimPose.rotation);

                if (!m_WasTracked)
                {
                    InputSystem.InputSystem.QueueDeltaStateEvent(trackingState, InputTrackingState.Position | InputTrackingState.Rotation);
                    InputSystem.InputSystem.QueueDeltaStateEvent(isTracked, true);
                }

                m_WasTracked = true;
            }
            else if (m_WasTracked)
            {
                InputSystem.InputSystem.QueueDeltaStateEvent(trackingState, InputTrackingState.None);
                InputSystem.InputSystem.QueueDeltaStateEvent(isTracked, false);
                m_WasTracked = false;
            }
        }

        internal void UpdateHand(bool isLeft, bool isHandRootTracked)
        {
            UnityOpenXRHands_RetrieveMetaAim(
                isLeft,
                out MetaAimFlags aimFlags,
                out Vector3 aimPosePosition,
                out Quaternion aimPoseRotation,
                out float pinchIndex,
                out float pinchMiddle,
                out float pinchRing,
                out float pinchLittle);

            UpdateHand(
                isHandRootTracked,
                aimFlags,
                new Pose(aimPosePosition, aimPoseRotation),
                pinchIndex,
                pinchMiddle,
                pinchRing,
                pinchLittle);
        }

        [DllImport("UnityOpenXRHands")]
        static extern void UnityOpenXRHands_RetrieveMetaAim(
            bool isLeft,
            out MetaAimFlags aimFlags,
            out Vector3 aimPosePosition,
            out Quaternion aimPoseRotation,
            out float pinchStrengthIndex,
            out float pinchStrengthMiddle,
            out float pinchStrengthRing,
            out float pinchStrengthLittle);

#if UNITY_EDITOR
        static MetaAimHand() => RegisterLayout();
#endif
        [RuntimeInitializeOnLoadMethod(RuntimeInitializeLoadType.SubsystemRegistration)]
        static void RegisterLayout()
        {
            InputSystem.InputSystem.RegisterLayout<MetaAimHand>(
                    matches: new InputDeviceMatcher()
                    .WithProduct(k_MetaAimHandDeviceProductName)
                    .WithManufacturer(k_MetaAimHandDeviceManufacturerName));
        }

        const string k_MetaAimHandDeviceProductName = "Meta Aim Hand Tracking";
        const string k_MetaAimHandDeviceManufacturerName = "OpenXR Meta";

        MetaAimFlags m_PreviousFlags;
        bool m_WasTracked;
        bool m_WasIndexPressed;
        bool m_WasMiddlePressed;
        bool m_WasRingPressed;
        bool m_WasLittlePressed;
    }
}

#endif // ENABLE_VR || UNITY_GAMECORE || PACKAGE_DOCS_GENERATION
