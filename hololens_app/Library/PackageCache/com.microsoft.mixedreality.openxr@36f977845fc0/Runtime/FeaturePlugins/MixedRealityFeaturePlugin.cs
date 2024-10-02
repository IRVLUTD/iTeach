// Copyright (c) Microsoft Corporation.
// Licensed under the MIT License.

using System;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.XR.OpenXR.Features;
using Microsoft.MixedReality.OpenXR.ARSubsystems;

#if UNITY_EDITOR
using UnityEditor;
using UnityEditor.XR.OpenXR.Features;
#endif

namespace Microsoft.MixedReality.OpenXR
{

#if UNITY_EDITOR
    [OpenXRFeature(UiName = featureName,
        BuildTargetGroups = new[] { BuildTargetGroup.Standalone, BuildTargetGroup.WSA },
        Company = "Microsoft",
        Desc = "Supports features on HoloLens 2 and Mixed Reality headsets.",
        DocumentationLink = "https://aka.ms/openxr-unity",
        CustomRuntimeLoaderBuildTargets = null,
        OpenxrExtensionStrings = requestedExtensions,
        Required = true,
        Category = FeatureCategory.Feature,
        FeatureId = featureId,
        Version = "1.10.1")]
#endif
    [RequiresNativePluginDLLs]
    internal class MixedRealityFeaturePlugin : OpenXRFeaturePlugin<MixedRealityFeaturePlugin>
    {
        internal enum ValidationRuleTargetPlatform
        {
            None = 0,
            [InspectorName("HoloLens 2")]
            HoloLens2 = 1
        }

        internal const string featureId = "com.microsoft.openxr.feature.hololens";
        internal const string featureName = "Mixed Reality Features";
        internal const string mixedRealityExtensions = ""
            + "XR_MSFT_unbounded_reference_space "
            + "XR_MSFT_spatial_anchor "
            + "XR_MSFT_secondary_view_configuration "
            + "XR_MSFT_first_person_observer "
            + "XR_MSFT_spatial_graph_bridge "
            + "XR_MSFT_perception_anchor_interop "
            + "XR_MSFT_spatial_anchor_persistence "
            + "XR_MSFT_scene_understanding "
            + "XR_MSFT_scene_understanding_serialization "
            + "XR_MSFT_scene_marker "
            + "XR_MSFT_spatial_anchor_export_preview "
            + "XR_MSFT_composition_layer_reprojection"; // Do not add space at the end

        internal const string requestedExtensions = ""
            + "XR_MSFT_holographic_window_attachment "
            + "XR_KHR_win32_convert_performance_counter_time "
            + mixedRealityExtensions;

        [Header("Mixed Reality Plugin Settings")]

        [SerializeField, LabelWidth(250f),
            Tooltip("Using first person observer, Mixed Reality Capture (MRC) will render from the perspective of the PV camera with an extra rendering pass. " +
            "This provides better hologram quality and alignment to the physical world but may use more rendering resources. " +
            "When this flag is set, MRC will render from one of the eyes without an extra rendering pass, reducing the " +
            "rendering cost for MRC but potentially introducing visual disparity, especially on hand tracking visuals.")]
        private bool disableFirstPersonObserver = false;

        [SerializeField, LabelWidth(250f),
            Tooltip("Using the before-render pose update allows the app to use lower latency action poses in the render scripts." +
                "However, this pose update adds cost in the pre-render phase. The before-render pose update is disabled by default " +
                "so that action poses are updated once a frame in the update phase which has 2 frames of latency.")]
        private bool enablePoseUpdateOnBeforeRender = false;


#if UNITY_EDITOR
        [EditorDrawerVisibleToBuildTarget(BuildTargetGroup.WSA)]
#endif
        [SerializeField, HideInInspector]
        internal ValidationRuleTargetPlatform validationRuleTarget;

        private OpenXRViewConfigurationSettings m_viewConfigurationSettings;

        internal MixedRealityFeaturePlugin()
        {
            AddSubsystemController(new SessionSubsystemController(this));
            AddSubsystemController(new AnchorSubsystemController(this));
            AddSubsystemController(new PlaneSubsystemController(this));
            AddSubsystemController(new RaycastSubsystemController(this));
            AddSubsystemController(new MeshSubsystemController(this));
            AddSubsystemController(m_viewConfigurationSettings = new OpenXRViewConfigurationSettings(this));
            AddSubsystemController(new MarkerSubsystemController(this));
        }

#if UNITY_EDITOR
        // UnityEditor.SessionState will store these across assembly reloading, but will be cleared when the Unity editor is closed.
        internal static string VersionInstalledOnLaunch
        {
            get => UnityEditor.SessionState.GetString(versionInstalledOnLaunchKey, defaultValue: string.Empty);
            set => UnityEditor.SessionState.SetString(versionInstalledOnLaunchKey, value);
        }
        private const string versionInstalledOnLaunchKey = "MixedRealityFeaturePlugin_VersionInstalledOnLaunch";

        protected override void OnEnable()
        {
            base.OnEnable();

            // Only cache the version here on first load.
            if (string.IsNullOrWhiteSpace(VersionInstalledOnLaunch))
            {
                VersionInstalledOnLaunch = UnityEditor.PackageManager.PackageInfo.FindForAssembly(typeof(MixedRealityFeaturePlugin).Assembly)?.version;
            }
        }
#endif // UNITY_EDITOR

        protected override bool OnInstanceCreate(ulong instance)
        {
            bool returnValue = base.OnInstanceCreate(instance);

            NativeLib.SetMixedRealityPluginOptions(new MixedRealityPluginOptions()
            {
                DisableFirstPersonObserver = disableFirstPersonObserver,
                EnablePoseUpdateOnBeforeRender = enablePoseUpdateOnBeforeRender,
            });

            return returnValue;
        }

        internal IReadOnlyList<ViewConfiguration> EnabledViewConfigurations
            => m_viewConfigurationSettings.EnabledViewConfigurations;

        internal ViewConfiguration PrimaryViewConfiguration => m_viewConfigurationSettings.PrimaryViewConfiguration;


#if UNITY_EDITOR
        protected override void GetValidationChecks(List<ValidationRule> results, BuildTargetGroup targetGroup)
        {
            MixedRealityFeatureValidator.GetValidationChecks(this, results, targetGroup);
        }
#endif
    }
}
