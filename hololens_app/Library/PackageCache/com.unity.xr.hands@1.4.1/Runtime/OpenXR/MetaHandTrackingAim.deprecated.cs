#if UNITY_OPENXR_PACKAGE || PACKAGE_DOCS_GENERATION

using System;
using System.Collections.Generic;
using System.Runtime.InteropServices;
using UnityEngine.InputSystem;
using UnityEngine.InputSystem.Controls;
using UnityEngine.InputSystem.Layouts;
using UnityEngine.InputSystem.XR;
using UnityEngine.Scripting;
using UnityEngine.XR.Hands;
using UnityEngine.XR.Management;
using UnityEngine.XR.OpenXR;
using UnityEngine.XR.OpenXR.Input;
using UnityEngine.XR.OpenXR.Features;

#if UNITY_EDITOR
using UnityEditor;
#endif

namespace UnityEngine.XR.Hands.OpenXR
{
    public partial class MetaHandTrackingAim
    {
        /// <summary>
        /// (Deprecated) The left-hand <see cref="InputDevice"/> that contains
        /// <see cref="InputControl"/>s that surface data in the Meta Hand
        /// Tracking Aim extension.
        /// </summary>
        [Obsolete("Use MetaAimHand.left instead. (UnityUpgradable) -> UnityEngine.XR.Hands.MetaAimHand.left", true)]
        public static MetaAimHand leftHand => null;

        /// <summary>
        /// (Deprecated) The right-hand <see cref="InputDevice"/> that contains
        /// <see cref="InputControl"/>s that surface data in the Meta Hand
        /// Tracking Aim extension.
        /// </summary>
        [Obsolete("Use MetaAimHand.right instead. (UnityUpgradable) -> UnityEngine.XR.Hands.MetaAimHand.right", true)]
        public static MetaAimHand rightHand => null;

        /// <summary>
        /// (Deprecated) Use <see cref="MetaAimFlags"/> instead.
        /// </summary>
        [Obsolete("Use UnityEngine.XR.Hands.MetaAimFlags instead.")]
        [Flags]
        public enum AimFlags : ulong
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
            /// The aim pose is valid. Retrieve this data from
            /// <see cref="TrackedDevice.devicePosition"/> and
            /// <see cref="TrackedDevice.deviceRotation"/> that
            /// <see cref="MetaAimHand"/> inherits.
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
        /// (Deprecated) A <see cref="TrackedDevice"/> based off the data exposed in the <see href="https://registry.khronos.org/OpenXR/specs/1.0/html/xrspec.html#XR_FB_hand_tracking_aim">Meta Hand Tracking Aim extension</see>.
        /// Use <see cref="MetaAimHand"/> instead of <see cref="MetaHandTrackingAim.MetaAimHand"/>.
        /// </summary>
        [Preserve, InputControlLayout(displayName = "Meta Aim Hand (OpenXR)", commonUsages = new[] { "LeftHand", "RightHand" })]
        [Obsolete("Use the UnityEngine.XR.Hands.MetaAimHand instead. (UnityUpgradable) -> UnityEngine.XR.Hands.MetaAimHand", true)]
        public class MetaAimHand : TrackedDevice
        {
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
            /// (Deprecated) Cast the result of reading this to <see cref="MetaAimFlags"/> to examine the value.
            /// Use <see cref="MetaAimHand"/> instead of <see cref="MetaHandTrackingAim.MetaAimHand"/>.
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
            protected override void FinishSetup() => base.FinishSetup();
        }
    }
}

#endif // UNITY_OPENXR_PACKAGE || PACKAGE_DOCS_GENERATION
