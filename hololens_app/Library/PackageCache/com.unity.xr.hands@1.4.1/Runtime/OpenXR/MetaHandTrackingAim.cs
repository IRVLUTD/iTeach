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
    /// <summary>
    /// This <see cref="OpenXRInteractionFeature"/> enables the use of Meta's
    /// hand-tracking aim data in OpenXR. It will not work without also enabling
    /// the <see cref="HandTracking"/> feature. It enables
    /// <see href="https://registry.khronos.org/OpenXR/specs/1.0/html/xrspec.html#XR_FB_hand_tracking_aim">
    /// XR_FB_hand_tracking_aim</see> in the underlying runtime. This creates
    /// new <see cref="InputDevice"/>s with the <see cref="InputDeviceCharacteristics.HandTracking"/>
    /// characteristic where the <see cref="TrackedDevice.devicePosition"/>
    /// and <see cref="TrackedDevice.deviceRotation"/> represent the aim pose
    /// exposed by this extension.
    /// </summary>
    /// <remarks>
    /// For this extension to be available, you must install the
    /// <see href="https://docs.unity3d.com/Packages/com.unity.xr.hands@latest/manual/index.html">
    /// XR Hands package</see>.
    /// </remarks>
#if UNITY_EDITOR
    [UnityEditor.XR.OpenXR.Features.OpenXRFeature(UiName = "Meta Hand Tracking Aim",
        BuildTargetGroups = new[] { BuildTargetGroup.Standalone, BuildTargetGroup.Android },
        Company = "Unity",
        Desc = "Allows for mapping input to the aim pose extension data. Will create an InputDevice for each hand if this and HandTracking are enabled.",
        DocumentationLink = XRHelpURLConstants.k_CurrentManualDocsBaseUrl + "features/metahandtrackingaim.html",
        Version = "0.0.1",
        OpenxrExtensionStrings = extensionString,
        Category = UnityEditor.XR.OpenXR.Features.FeatureCategory.Feature,
        FeatureId = featureId)]
#endif
    public partial class MetaHandTrackingAim : OpenXRFeature
    {
        /// <summary>
        /// The feature ID string. This is used to give the feature a well known
        /// ID for reference.
        /// </summary>
        public const string featureId = "com.unity.openxr.feature.input.metahandtrackingaim";

        /// <summary>
        /// The OpenXR Extension string. OpenXR uses this to check if this
        /// extension is available or enabled. See
        /// <see href="https://registry.khronos.org/OpenXR/specs/1.0/html/xrspec.html#XR_FB_hand_tracking_aim">Meta hand-tracking aim</see>
        /// documentation for more information on this OpenXR extension.
        /// </summary>
        public const string extensionString = "XR_FB_hand_tracking_aim";

        /// <summary>
        /// The device product name used when creating the <see cref="InputDevice"/>s
        /// that represent each hand in the extension.
        /// </summary>
        const string deviceProductName = "Meta Aim Hand Tracking";

        /// <summary>
        /// The device manufacturer name used when creating the <see cref="InputDevice"/>s
        /// that represent each hand in the extension.
        /// </summary>
        const string deviceManufacturerName = "OpenXR Meta";

        /// <summary>See <see cref="OpenXRFeature.OnSubsystemStart"/>.</summary>
        protected override void OnSubsystemStart()
        {
            if (NativeApi.ToggleMetaAim(true))
            {
                CreateHands();
                var subsystem = XRGeneralSettings.Instance?.Manager?.activeLoader?.GetLoadedSubsystem<XRHandSubsystem>();
                if (subsystem != null)
                    subsystem.updatedHands += OnUpdatedHands;
            }
            else
            {
                Debug.LogError("Couldn't enable Meta aim retrieval in plugin - please ensure you enabled the Hand Tracking Subsystem feature in the OpenXR project settings.");
            }
        }

        /// <summary>See <see cref="OpenXRFeature.OnSubsystemStop"/>.</summary>
        protected override void OnSubsystemStop()
        {
            NativeApi.ToggleMetaAim(false);

            var subsystem = XRGeneralSettings.Instance?.Manager?.activeLoader?.GetLoadedSubsystem<XRHandSubsystem>();
            if (subsystem != null)
                subsystem.updatedHands -= OnUpdatedHands;

            DestroyHands();
        }

        void CreateHands()
        {
            if (Hands.MetaAimHand.left == null)
                Hands.MetaAimHand.left = Hands.MetaAimHand.CreateHand(InputDeviceCharacteristics.Left);

            if (Hands.MetaAimHand.right == null)
                Hands.MetaAimHand.right = Hands.MetaAimHand.CreateHand(InputDeviceCharacteristics.Right);
        }

        void DestroyHands()
        {
            if (Hands.MetaAimHand.left != null)
            {
                InputSystem.InputSystem.RemoveDevice(Hands.MetaAimHand.left);
                Hands.MetaAimHand.left = null;
            }

            if (Hands.MetaAimHand.right != null)
            {
                InputSystem.InputSystem.RemoveDevice(Hands.MetaAimHand.right);
                Hands.MetaAimHand.right = null;
            }
        }

        void OnUpdatedHands(XRHandSubsystem subsystem, XRHandSubsystem.UpdateSuccessFlags successFlags, XRHandSubsystem.UpdateType updateType)
        {
            if ((successFlags & (XRHandSubsystem.UpdateSuccessFlags.LeftHandRootPose | XRHandSubsystem.UpdateSuccessFlags.LeftHandJoints)) != 0)
                Hands.MetaAimHand.left.UpdateHand(true, (successFlags & XRHandSubsystem.UpdateSuccessFlags.LeftHandRootPose) != 0);
            if ((successFlags & (XRHandSubsystem.UpdateSuccessFlags.RightHandRootPose | XRHandSubsystem.UpdateSuccessFlags.RightHandJoints)) != 0)
                Hands.MetaAimHand.right.UpdateHand(false, (successFlags & XRHandSubsystem.UpdateSuccessFlags.RightHandRootPose) != 0);
        }

        static class NativeApi
        {
            [DllImport(HandTracking.k_LibraryName, EntryPoint = "UnityOpenXRHands_ToggleMetaAim")]
            static internal extern bool ToggleMetaAim(bool enable);
        }
    }
}

#endif // UNITY_OPENXR_PACKAGE || PACKAGE_DOCS_GENERATION
