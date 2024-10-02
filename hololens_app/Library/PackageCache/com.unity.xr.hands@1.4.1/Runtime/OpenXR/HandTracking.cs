#if UNITY_OPENXR_PACKAGE || PACKAGE_DOCS_GENERATION

using System;
using System.Collections.Generic;
using System.Runtime.InteropServices;
using UnityEngine.XR.Hands;
using UnityEngine.XR.Hands.ProviderImplementation;
using UnityEngine.XR.Management;
using UnityEngine.XR.OpenXR;
using UnityEngine.XR.OpenXR.Features;

#if UNITY_EDITOR
using UnityEditor;
using UnityEditor.XR.Management;
#endif

#if UNITY_OPENXR_PACKAGE_1_2 && !UNITY_OPENXR_PACKAGE_1_6
using UnityEngine.XR.OpenXR.Features.OculusQuestSupport;
#endif

namespace UnityEngine.XR.Hands.OpenXR
{
    /// <summary>
    /// This <see cref="OpenXRInteractionFeature"/> enables the use of
    /// hand-tracking data in OpenXR through the <see cref="XRHandSubsystem"/>.
    /// It enables <see href="https://registry.khronos.org/OpenXR/specs/1.0/html/xrspec.html#XR_EXT_hand_tracking">
    /// XR_EXT_hand_tracking</see> in the underlying runtime. To retrieve hand
    /// data, use the <see cref="XRHandSubsystem"/> retrieved from
    /// <see cref="HandTracking.subsystem"/>.
    /// </summary>
    /// <remarks>
    /// For this extension to be available, you must install the
    /// <see href="https://docs.unity3d.com/Packages/com.unity.xr.hands@latest/manual/index.html">
    /// XR Hands package</see>.
    /// </remarks>
#if UNITY_EDITOR
    [UnityEditor.XR.OpenXR.Features.OpenXRFeature(UiName = "Hand Tracking Subsystem",
        BuildTargetGroups = new[] { BuildTargetGroup.Standalone, BuildTargetGroup.WSA, BuildTargetGroup.Android },
        Company = "Unity",
        Desc = "Creates and manages an XRHandSubsystem.",
        DocumentationLink = XRHelpURLConstants.k_CurrentManualDocsBaseUrl + "features/handtracking.html",
        Version = "0.0.1",
        OpenxrExtensionStrings = extensionString,
        Category = UnityEditor.XR.OpenXR.Features.FeatureCategory.Feature,
        FeatureId = featureId,
        Priority = -100)]
#endif
    public class HandTracking : OpenXRFeature
    {
        /// <summary>
        /// The feature ID string. This is used to give the feature a well known
        /// ID for reference.
        /// </summary>
        public const string featureId = "com.unity.openxr.feature.input.handtracking";

        /// <summary>
        /// The OpenXR Extension string. OpenXR uses this to check if this
        /// extension is available or enabled. See
        /// <see href="https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#XR_EXT_hand_tracking">hand interaction extension</see>
        /// documentation for more information on this OpenXR extension.
        /// </summary>
        public const string extensionString = "XR_EXT_hand_tracking";

        /// <summary>
        /// The <see cref="XRHandSubsystem"/> that retrieves hand data from its
        /// provider. Will only be valid when this feature is enabled and
        /// running. To subscribe to updates, use <see cref="XRHandSubsystem.handsUpdated"/>.
        /// </summary>
        public static XRHandSubsystem subsystem => s_Subsystem;

        /// <summary>See <see cref="OpenXRFeature.OnSystemChange(ulong)"/>.</summary>
        protected override void OnSystemChange(ulong xrSystem)
        {
            base.OnSystemChange(xrSystem);
            NativeApi.OnSystemChange(xrSystem);
        }

        /// <summary>See <see cref="OpenXRFeature.OnInstanceCreate(ulong)"/>.</summary>
        protected override bool OnInstanceCreate(ulong xrInstance)
        {
            if (!base.OnInstanceCreate(xrInstance))
                return false;

            return NativeApi.OnInstanceCreate(xrInstance, xrGetInstanceProcAddr);
        }

        /// <summary>See <see cref="OpenXRFeature.OnAppSpaceChange(ulong)"/>.</summary>
        protected override void OnAppSpaceChange(ulong xrSpace)
        {
            base.OnAppSpaceChange(xrSpace);
            NativeApi.OnAppSpaceChange(xrSpace);
        }

        /// <summary>
        /// Called after xrCreateSession.
        /// </summary>
        /// <remarks>
        /// Creates an <see cref="XRHandSubsystem"/> with the OpenXR provider.
        /// </remarks>
        protected override void OnSessionCreate(ulong xrSession)
        {
            base.OnSessionCreate(xrSession);
            NativeApi.OnSessionCreate(xrSession);

            var descriptors = new List<XRHandSubsystemDescriptor>();
            SubsystemManager.GetSubsystemDescriptors(descriptors);
            if (descriptors.Count < 1)
                return;

            CreateSubsystem<XRHandSubsystemDescriptor, XRHandSubsystem>(descriptors, OpenXRHandProvider.id);
            s_Subsystem = XRGeneralSettings.Instance?.Manager?.activeLoader?.GetLoadedSubsystem<XRHandSubsystem>();

            if (s_Subsystem == null)
            {
                Debug.LogError($"Failed to find descriptor '{OpenXRHandProvider.id}' - HandTracking OpenXR feature will not do anything!");
                return;
            }

            m_Updater = new XRHandProviderUtility.SubsystemUpdater(s_Subsystem);
        }

        /// <summary>See <see cref="OpenXRFeature.OnAppSpaceChange(ulong)"/>.</summary>
        protected override void OnSessionDestroy(ulong xrSpace)
        {
            base.OnSessionDestroy(xrSpace);
            NativeApi.OnSessionDestroy(xrSpace);
        }

        /// <summary>See <see cref="OpenXRFeature.OnInstanceDestroy(ulong)"/>.</summary>
        protected override void OnInstanceDestroy(ulong xrInstance)
        {
            base.OnInstanceDestroy(xrInstance);
            NativeApi.OnInstanceDestroy(xrInstance);
        }

        /// <summary>See <see cref="OpenXRFeature.OnInstanceLossPending(ulong)"/>.</summary>
        protected override void OnInstanceLossPending(ulong xrInstance)
        {
            base.OnInstanceLossPending(xrInstance);
            NativeApi.OnInstanceLossPending(xrInstance);
        }

        /// <summary>
        /// Called after the OpenXR loader has started its subsystems.
        /// </summary>
        /// <remarks>
        /// Starts the <see cref="XRHandSubsystem"/> and automatic updating for
        /// it. To subscribe to updates, use <see cref="XRHandSubsystem.handsUpdated"/>.
        /// </remarks>
        protected override void OnSubsystemStart()
        {
            if (s_Subsystem == null)
                return;

            s_Subsystem.Start();
            m_Updater.Start();
        }

        /// <summary>
        /// Called before the OpenXR loader stops its subsystems.
        /// </summary>
        /// <remarks>
        /// Stops the <see cref="XRHandSubsystem"/> and automatic updating for it.
        /// </remarks>
        protected override void OnSubsystemStop()
        {
            m_Updater?.Stop();
            s_Subsystem?.Stop();
        }

        /// <summary>
        /// Called before the OpenXR loader destroys its subsystems.
        /// </summary>
        /// <remarks>
        /// Destroys the <see cref="XRHandSubsystem"/>.
        /// </remarks>
        protected override void OnSubsystemDestroy()
        {
            m_Updater?.Destroy();
            m_Updater = null;

            s_Subsystem?.Destroy();
            s_Subsystem = null;
        }

        /// <see cref="OpenXRFeature.HookGetInstanceProcAddr(IntPtr)"/>
        protected override IntPtr HookGetInstanceProcAddr(IntPtr func)
            => NativeApi.Intercept_xrGetInstanceProcAddr(func);

#if UNITY_EDITOR
        protected override void GetValidationChecks(List<ValidationRule> results, BuildTargetGroup targetGroup)
        {
#if UNITY_OPENXR_PACKAGE_1_2 && !UNITY_OPENXR_PACKAGE_1_6
            results.Add(new ValidationRule(this)
            {
                message = "Hand-tracking does not work on a Quest device at runtime without a version of the OpenXR package at version 1.6.0 or newer.",
                checkPredicate = () =>
                {
                    var settings = OpenXRSettings.GetSettingsForBuildTargetGroup(targetGroup);
                    if (null == settings)
                        return false;

                    var questFeature = settings.GetFeature<OculusQuestFeature>();
                    return questFeature == null || !questFeature.enabled;
                },
                error = true
            });
#endif // UNITY_OPENXR_PACKAGE_1_6
        }
#endif // UNITY_EDITOR

        internal const string k_LibraryName = "UnityOpenXRHands";

        static class NativeApi
        {
            [DllImport(k_LibraryName, EntryPoint = "UnityOpenXRHands_OnSystemChange")]
            static internal extern void OnSystemChange(ulong xrSystem);

            [DllImport(k_LibraryName, EntryPoint = "UnityOpenXRHands_OnInstanceCreate")]
            static internal extern bool OnInstanceCreate(ulong xrInstance, IntPtr xrGetInstanceProcAddr);

            [DllImport(k_LibraryName, EntryPoint = "UnityOpenXRHands_OnAppSpaceChange")]
            static internal extern void OnAppSpaceChange(ulong xrSpace);

            [DllImport(k_LibraryName, EntryPoint = "UnityOpenXRHands_OnSessionCreate")]
            static internal extern void OnSessionCreate(ulong xrSession);

            [DllImport(k_LibraryName, EntryPoint = "UnityOpenXRHands_OnSessionDestroy")]
            static internal extern void OnSessionDestroy(ulong xrSession);

            [DllImport(k_LibraryName, EntryPoint = "UnityOpenXRHands_OnInstanceDestroy")]
            static internal extern void OnInstanceDestroy(ulong xrInstance);

            [DllImport(k_LibraryName, EntryPoint = "UnityOpenXRHands_OnInstanceLossPending")]
            static internal extern void OnInstanceLossPending(ulong xrInstance);

            [DllImport(k_LibraryName, EntryPoint = "UnityOpenXRHands_intercept_xrGetInstanceProcAddr")]
            static internal extern IntPtr Intercept_xrGetInstanceProcAddr(IntPtr func);
        }

#if UNITY_EDITOR
        internal static bool OpenXRLoaderEnabledForEditorPlayMode()
        {
            var settings = XRGeneralSettings.Instance?.AssignedSettings ?? (XRGeneralSettingsPerBuildTarget.XRGeneralSettingsForBuildTarget(BuildTargetGroup.Standalone)?.AssignedSettings);
            if (!settings)
                return false;

            foreach (var activeLoader in settings.activeLoaders)
            {
                if (activeLoader is OpenXRLoader)
                    return true;
            }

            return false;
        }
#endif

        XRHandProviderUtility.SubsystemUpdater m_Updater;
        static XRHandSubsystem s_Subsystem;
    }
}

#endif // UNITY_OPENXR_PACKAGE || PACKAGE_DOCS_GENERATION
