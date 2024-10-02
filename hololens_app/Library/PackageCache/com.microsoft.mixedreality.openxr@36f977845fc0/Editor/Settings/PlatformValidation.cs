// Copyright (c) Microsoft Corporation.
// Licensed under the MIT License.

#if UNITY_EDITOR

using Microsoft.MixedReality.OpenXR.Remoting;
using System.Collections.Generic;
using System.Linq;
using Unity.XR.CoreUtils.Editor;
using UnityEditor;
using UnityEditor.SceneManagement;
using UnityEditor.XR.Management.Metadata;
using UnityEditor.XR.OpenXR.Features;
using UnityEngine;
using UnityEngine.SpatialTracking;
using UnityEngine.XR.Management;
using UnityEngine.XR.OpenXR;
using UnityEngine.XR.OpenXR.Features;
using UnityEngine.XR.OpenXR.Features.Interactions;
using static Microsoft.MixedReality.OpenXR.MixedRealityFeaturePlugin;

namespace Microsoft.MixedReality.OpenXR.Editor
{
    /// <summary>
    /// Provides a menu item for configuring settings according to specified OpenXR devices.
    /// </summary>
    internal static class PlatformValidation
    {
        private static readonly IEnumerable<ValidationRuleset> ValidationRulesetsForRuleGeneration = ((ValidationRuleset[]) System.Enum.GetValues(typeof(ValidationRuleset))).Where((ruleset) => ruleset != ValidationRuleset.None);

        private const string OpenXRProjectValidationSettingsPath = "Project/XR Plug-in Management/Project Validation";

        private const string Win32StandaloneRulesetMenuPath = "Mixed Reality/Project Validation Settings/Win32 Application (Standalone)";
        private const string HoloLens2RulesetMenuPath = "Mixed Reality/Project Validation Settings/HoloLens 2 Application (UWP)";
        private const string Win32AppRemotingRulesetMenuPath = "Mixed Reality/Project Validation Settings/Win32 Remoting App for HoloLens 2 (Standalone)";
        private const string UWPAppRemotingRulesetMenuPath = "Mixed Reality/Project Validation Settings/Win32 Remoting App for HoloLens 2 (UWP)";
        private const string DisableValidationRulesetMenuPath = "Mixed Reality/Project Validation Settings/General Validation Rules Only";

        private const string PerformanceHelpLinkText = "Click this icon for more info on recommended performance settings for HoloLens 2.";
        private const string PerformanceHelpLink = "https://aka.ms/HoloLens2PerfSettings";
        private const string SetupHelpLink = "https://aka.ms/HoloLens2OpenXRConfig";
        private static readonly string CannotAutoSetupForHL2 = "Could not automatically apply recommended settings for HoloLens 2. " +
            $"Please see {SetupHelpLink} for manual set up instructions";
        private static readonly string CannotAutoOptimizeForHL2 = "Could not automatically apply recommended settings for HoloLens 2. " +
            $"Please see {PerformanceHelpLink} for manual optimization instructions";

        private const string AboutValidationRulesetsHelpText = "This rule has been enabled because a specific application type has been targeted for this project. \r\n" +
            "To change or disable these additional validation rules, use the top-level menu:\r\n \"Mixed Reality > Project Validation Settings\"";

        [InitializeOnLoadMethod]
        private static void InitializePlatformValidation()
        {
            // These rules are generated for every validation ruleset on every platform - e.g. trying to validate HL2 apps on Standalone will redirect users to UWP.
            BuildValidator.AddRules(BuildTargetGroup.WSA, GenerateBuildTargetRules(BuildTargetGroup.WSA));
            BuildValidator.AddRules(BuildTargetGroup.Standalone, GenerateBuildTargetRules(BuildTargetGroup.Standalone));

            // These rules are generated for every validation ruleset, but only on the platforms where each ruleset is supported.
            // If a project is on the wrong platform, that needs to be fixed before these rules will show.
            BuildValidator.AddRules(BuildTargetGroup.WSA, GenerateOpenXRLoaderRules(BuildTargetGroup.WSA));
            BuildValidator.AddRules(BuildTargetGroup.Standalone, GenerateOpenXRLoaderRules(BuildTargetGroup.Standalone));

            BuildValidator.AddRules(BuildTargetGroup.WSA, GenerateRequiredFeatureSetsRules(BuildTargetGroup.WSA));
            BuildValidator.AddRules(BuildTargetGroup.Standalone, GenerateRequiredFeatureSetsRules(BuildTargetGroup.Standalone));

            BuildValidator.AddRules(BuildTargetGroup.WSA, GenerateInitializeXROnStartRules(BuildTargetGroup.WSA));
            BuildValidator.AddRules(BuildTargetGroup.Standalone, GenerateInitializeXROnStartRules(BuildTargetGroup.Standalone));

            BuildValidator.AddRules(BuildTargetGroup.WSA, GenerateCameraRules());

            // These rules are all HL2 specific, and are only enabled with the HL2 validation ruleset while targeting UWP.
            BuildValidationRule[] wsaValidationRules = new BuildValidationRule[] { GenerateHL2RealtimeGIRule(), GenerateHL2QualityRule(),
                GenerateHL2RenderAndDepthSubmissionModeRule() };
            BuildValidator.AddRules(BuildTargetGroup.WSA, wsaValidationRules);

            // These deprecation warnings are always enabled.
            BuildValidationRule[] androidDeprecationRules = new BuildValidationRule[] { GenerateAndroidHandTrackingRule(), GenerateAndroidMotionControllerRule() };
            BuildValidator.AddRules(BuildTargetGroup.Android, androidDeprecationRules);
        }

        private static void ChangeValidationRuleset(ValidationRuleset validationRuleset)
        {
            BuildTargetGroup buildTargetGroup = validationRuleset.GetBuildTargetGroup();
            BuildTarget buildTarget = validationRuleset.GetBuildTarget();
            string scenarioName = validationRuleset.GetScenarioName();

            if (buildTargetGroup == BuildTargetGroup.WSA && !BuildPipeline.IsBuildTargetSupported(BuildTargetGroup.WSA, BuildTarget.WSAPlayer))
            {
                EditorUtility.DisplayDialog("UWP support not found", "The UWP build support is not currently installed. " +
                    "Please add the Universal Windows Platform Build Support module to your Unity installation.", "OK");
                return;
            }

            BuildTargetGroup previousBuildTargetGroup = EditorUserBuildSettings.selectedBuildTargetGroup;

            // Make sure to select the correct platform, which also select the correct tab in the validation window.
            // NOTE: must do this selected group change before switching build target below
            // otherwise this selection change will not function properly in Unity editor.
            if (EditorUserBuildSettings.selectedBuildTargetGroup != buildTargetGroup)
            {
               EditorUserBuildSettings.selectedBuildTargetGroup = buildTargetGroup;
            }

            if (EditorUserBuildSettings.activeBuildTarget != buildTarget)
            {
                if (EditorUtility.DisplayDialog("Change build target platform?", $"This project is currently targeting a platform which does not support {scenarioName} apps. " +
                    $"To build {scenarioName} applications, the build target platform in Build Settings must be {buildTarget}.\n\n" +
                    $"Click `Continue` to switch the build target platform to {buildTarget} and open the Project Validation window to review other validation messages.",
                    "Continue", "Cancel"))
                {
                    EditorUserBuildSettings.SwitchActiveBuildTarget(buildTargetGroup, buildTarget);
                }
                else
                {
                    EditorUserBuildSettings.selectedBuildTargetGroup = previousBuildTargetGroup;
                    return;
                }
            }

            ValidationSettings.CurrentRuleset = validationRuleset;
            ShowProjectValidationSettings();
        }

        private static void ShowProjectValidationSettings()
        {
            // Need to call OpenProjectSettings twice since the first call may not properly bring up the requested page
            // Possibly due to the generation of XR settings related files on the fly
            SettingsService.OpenProjectSettings(OpenXRProjectValidationSettingsPath);
            EditorApplication.delayCall += () =>
            {
                SettingsService.OpenProjectSettings(OpenXRProjectValidationSettingsPath);
            };
        }

        [MenuItem(Win32StandaloneRulesetMenuPath, isValidateFunction: false, priority: 10)]
        private static void ChangeValidationRulesetWin32Standalone() =>
            ChangeValidationRuleset(ValidationRuleset.Win32Standalone);

        [MenuItem(Win32StandaloneRulesetMenuPath, isValidateFunction: true)]
        private static bool ChangeValidationRulesetWin32StandaloneValidator() =>
            UpdateRulesetMenuItemChecked(Win32StandaloneRulesetMenuPath, ValidationRuleset.Win32Standalone);

        [MenuItem(HoloLens2RulesetMenuPath, isValidateFunction: false, priority: 11)]
        private static void ChangeValidationRulesetHoloLens2() =>
            ChangeValidationRuleset(ValidationRuleset.HoloLens2);

        [MenuItem(HoloLens2RulesetMenuPath, isValidateFunction: true)]
        private static bool ChangeValidationRulesetHoloLens2Validator() =>
            UpdateRulesetMenuItemChecked(HoloLens2RulesetMenuPath, ValidationRuleset.HoloLens2);

        [MenuItem(Win32AppRemotingRulesetMenuPath, isValidateFunction: false, priority: 12)]
        private static void ChangeValidationRulesetWin32AppRemoting() =>
            ChangeValidationRuleset(ValidationRuleset.Win32AppRemoting);

        [MenuItem(Win32AppRemotingRulesetMenuPath, isValidateFunction: true)]
        private static bool ChangeValidationRulesetWin32AppRemotingValidator() =>
            UpdateRulesetMenuItemChecked(Win32AppRemotingRulesetMenuPath, ValidationRuleset.Win32AppRemoting);

        [MenuItem(UWPAppRemotingRulesetMenuPath, isValidateFunction: false, priority: 13)]
        private static void ChangeValidationRulesetUWPAppRemoting() =>
            ChangeValidationRuleset(ValidationRuleset.UWPAppRemoting);

        [MenuItem(UWPAppRemotingRulesetMenuPath, isValidateFunction: true)]
        private static bool ChangeValidationRulesetUWPAppRemotingValidator() =>
            UpdateRulesetMenuItemChecked(UWPAppRemotingRulesetMenuPath, ValidationRuleset.UWPAppRemoting);

        // MenuItems with a difference in priority > 10 will have a horizontal line between them in the menu UI.
        [MenuItem(DisableValidationRulesetMenuPath, isValidateFunction: false, priority: 25)]
        private static void RemoveValidationRulesets() => ValidationSettings.CurrentRuleset = ValidationRuleset.None;

        [MenuItem(DisableValidationRulesetMenuPath, isValidateFunction: true)]
        private static bool RemoveValidationRulesetsValidator() =>
            UpdateRulesetMenuItemChecked(DisableValidationRulesetMenuPath, ValidationRuleset.None);


        #region Validation ruleset rules

        private static BuildValidationRule[] GenerateBuildTargetRules(BuildTargetGroup buildTargetGroup)
        {
            List<BuildValidationRule> validationRules = new List<BuildValidationRule>();

            foreach(ValidationRuleset validationRuleset in ValidationRulesetsForRuleGeneration)
            {
                if(validationRuleset.GetBuildTargetGroup() == buildTargetGroup)
                {
                    // No need for a rule on this build target group, since it must already be correct
                    continue;
                }

                string scenarioName = validationRuleset.GetScenarioName();
                string platformShortName = validationRuleset.GetPlatformShortName();
                validationRules.Add(new BuildValidationRule()
                {
                    // The build target should always be enabled if plugin validation has been enabled.
                    IsRuleEnabled = () => ValidationSettings.CurrentRuleset == validationRuleset,
                    Category = $"Mixed Reality OpenXR - {scenarioName} Ruleset",
                    Message = $"The project needs to target the {platformShortName} platform to build {scenarioName} applications.",
                    CheckPredicate = () => EditorUserBuildSettings.activeBuildTarget == validationRuleset.GetBuildTarget(),
                    FixIt = () => {
                        EditorUserBuildSettings.selectedBuildTargetGroup = validationRuleset.GetBuildTargetGroup();
                        EditorUserBuildSettings.SwitchActiveBuildTarget(validationRuleset.GetBuildTargetGroup(), validationRuleset.GetBuildTarget());
                    },
                    FixItMessage = $"Switch the build target to {platformShortName}",
                    Error = true,
                    FixItAutomatic = true,
                    HelpText = AboutValidationRulesetsHelpText
                });
            }

            return validationRules.ToArray();
        }

        private static BuildValidationRule[] GenerateOpenXRLoaderRules(BuildTargetGroup buildTargetGroup)
        {
            List<BuildValidationRule> validationRules = new List<BuildValidationRule>();

            foreach(ValidationRuleset validationRuleset in ValidationRulesetsForRuleGeneration)
            {
                if(validationRuleset.GetBuildTargetGroup() != buildTargetGroup)
                {
                    continue;
                }

                string scenarioName = validationRuleset.GetScenarioName();
                string platformShortName = validationRuleset.GetPlatformShortName();
                validationRules.Add(new BuildValidationRule()
                    {
                        // The OpenXR loader should always be enabled if a validation ruleset has been enabled.
                        IsRuleEnabled = () => ValidationSettings.CurrentRuleset == validationRuleset,
                        Category = $"Mixed Reality OpenXR - {scenarioName} Ruleset",
                        Message = $"For {scenarioName} applications, the OpenXR loader must be enabled for {platformShortName} in XR plugin management settings.",
                        CheckPredicate = () => XRPackageMetadataStore.IsLoaderAssigned(typeof(OpenXRLoader).FullName, buildTargetGroup),
                        FixIt = () => EnableOpenXRLoader(buildTargetGroup),
                        FixItMessage = $"Assign the OpenXR loader for {platformShortName}",
                        Error = false,
                        HelpText = AboutValidationRulesetsHelpText
                });
            }

            return validationRules.ToArray();
        }

        private static BuildValidationRule[] GenerateRequiredFeatureSetsRules(BuildTargetGroup buildTargetGroup)
        {
            List<BuildValidationRule> validationRules = new List<BuildValidationRule>();

            foreach (ValidationRuleset validationRuleset in ValidationRulesetsForRuleGeneration)
            {
                if (validationRuleset.GetBuildTargetGroup() != buildTargetGroup)
                {
                    continue;
                }

                string scenarioName = validationRuleset.GetScenarioName();
                string platformShortName = validationRuleset.GetPlatformShortName();

                System.Type[] featureSets = validationRuleset.GetRequiredFeatureSets();
                List<string> featureSetUINames = new List<string>();
                List<string> featureSetIds = new List<string>();

                GetIdsAndUserNamesForFeatureSets(featureSets, ref featureSetIds, ref featureSetUINames);

                validationRules.Add(new BuildValidationRule()
                {
                    // The necessary feature set should always be enabled if a validation ruleset has been enabled.
                    IsRuleEnabled = () => ValidationSettings.CurrentRuleset == validationRuleset,
                    Category = $"Mixed Reality OpenXR - {scenarioName} Ruleset",
                    Message = $"For {scenarioName} apps, the following feature sets must be enabled for {platformShortName} in OpenXR settings: {string.Join(", ", featureSetUINames)}",
                    CheckPredicate = () => CheckFeatureSets(buildTargetGroup, featureSetIds),
                    FixIt = () => EnableFeatureSets(buildTargetGroup, featureSetIds),
                    FixItMessage = $"Enable the following feature sets for {platformShortName}: {string.Join(", ", featureSetUINames)}",
                    Error = true,
                    HelpText = AboutValidationRulesetsHelpText
                });

                System.Type[] notRequiredfeatureSets = validationRuleset.GetNotRequiredFeatureSets();
                List<string> notRequiredFeatureSetUINames = new List<string>();
                List<string> notRequiredFeatureSetIds = new List<string>();

                GetIdsAndUserNamesForFeatureSets(notRequiredfeatureSets, ref notRequiredFeatureSetIds, ref notRequiredFeatureSetUINames);

                if (notRequiredFeatureSetIds.Count > 0)
                {
                    validationRules.Add(new BuildValidationRule()
                    {
                        // The necessary feature set should always be enabled if a validation ruleset has been enabled.
                        IsRuleEnabled = () => ValidationSettings.CurrentRuleset == validationRuleset,
                        Category = $"Mixed Reality OpenXR - {scenarioName} Ruleset",
                        Message = $"For {scenarioName} apps, the following feature sets must be disabled for {platformShortName} in OpenXR settings: {string.Join(", ", notRequiredFeatureSetUINames)}",
                        CheckPredicate = () => !CheckFeatureSets(buildTargetGroup, notRequiredFeatureSetIds),
                        FixIt = () => DisableFeatureSets(buildTargetGroup, notRequiredFeatureSetIds),
                        FixItMessage = $"Disable the following feature sets for {platformShortName}: {string.Join(", ", notRequiredFeatureSetUINames)}",
                        Error = true,
                        HelpText = AboutValidationRulesetsHelpText
                    });
                }
            }

            return validationRules.ToArray();
        }

        private static BuildValidationRule[] GenerateInitializeXROnStartRules(BuildTargetGroup buildTargetGroup)
        {
            List<BuildValidationRule> validationRules = new List<BuildValidationRule>();

            foreach (ValidationRuleset validationRuleset in ValidationRulesetsForRuleGeneration)
            {
                if (validationRuleset.GetBuildTargetGroup() != buildTargetGroup)
                {
                    continue;
                }

                string scenarioName = validationRuleset.GetScenarioName();
                string platformShortName = validationRuleset.GetPlatformShortName();
                bool remotingEnabled = validationRuleset.GetRemotingEnabled();

                validationRules.Add(new BuildValidationRule()
                {
                    // This rule will run if a validation ruleset has been enabled. If there is no validation ruleset, we fallback to the validator in AppRemotingValidator.cs
                    IsRuleEnabled = () => ValidationSettings.CurrentRuleset == validationRuleset,
                    Category = $"Mixed Reality OpenXR - {scenarioName} Ruleset",
                    Message = $"For {scenarioName} applications, XR initialization should {(remotingEnabled ? "be delayed until a specific IP address is entered" : "not be delayed")}",
                    CheckPredicate = () =>
                    {
                        XRGeneralSettings settings = XRSettingsHelpers.GetOrCreateXRGeneralSettings(buildTargetGroup);
                        return settings != null && settings.InitManagerOnStart != remotingEnabled;
                    },
                    FixIt = () =>
                    {
                        XRGeneralSettings settings = XRSettingsHelpers.GetOrCreateXRGeneralSettings(buildTargetGroup);
                        if (settings != null)
                        {
                            settings.InitManagerOnStart = !remotingEnabled;
                        }
                    },
                    FixItMessage = $"{ (remotingEnabled ? "Disable" : "Enable") } XR initialization on startup",
                    // If remoting is enabled, this must be enabled. If remoting is not enabled, this should likely be disabled, but it's not required.
                    Error = remotingEnabled,
                    HelpText = AboutValidationRulesetsHelpText
                });
            }

            return validationRules.ToArray();
        }

        #endregion


        #region HoloLens 2 rules

        private static BuildValidationRule GenerateHL2RealtimeGIRule()
        {
            return new BuildValidationRule()
            {
                IsRuleEnabled = IsHL2RulesetEnabled,
                Category = "Mixed Reality OpenXR - HoloLens 2 Ruleset",
                Message = $"Realtime GI has a negative performance impact on HoloLens 2 applications.",
                CheckPredicate = () => !Lightmapping.TryGetLightingSettings(out LightingSettings lightingSettings) || !lightingSettings.realtimeGI,
                FixIt = () =>
                {
                    if (Lightmapping.TryGetLightingSettings(out LightingSettings lightingSettings))
                    {
                        lightingSettings.realtimeGI = false;
                        EditorUtility.SetDirty(lightingSettings);
                    }
                    else
                    {
                        Debug.LogError(CannotAutoOptimizeForHL2);
                    }
                },
                FixItMessage = $"Disable realtime GI in lighting settings",
                Error = false,
                HelpText = PerformanceHelpLinkText + "\r\n\r\n" + AboutValidationRulesetsHelpText,
                HelpLink = PerformanceHelpLink
            };
        }

        private static BuildValidationRule GenerateHL2QualityRule()
        {
            return new BuildValidationRule()
            {
                // Currently this rule doesn't work as Unity use the "default quality" for a platform to determine the quality level to use
                // Setting the "current active quality" does not impact the application running on HoloLens 2
                IsRuleEnabled = () => false,
                Category = "Mixed Reality OpenXR - HoloLens 2 Ruleset",
                Message = $"High quality settings have a negative performance impact on HoloLens 2 applications.",
                CheckPredicate = () => QualitySettings.GetQualityLevel() == 0,
                FixIt = () => QualitySettings.SetQualityLevel(0, true),
                FixItMessage = $"Set quality settings to very low",
                Error = false,
                HelpText = PerformanceHelpLinkText + "\r\n\r\n" + AboutValidationRulesetsHelpText,
                HelpLink = PerformanceHelpLink
            };
        }

        private static BuildValidationRule GenerateHL2GPUSkinningRule()
        {
            return new BuildValidationRule()
            {
                IsRuleEnabled = IsHL2RulesetEnabled,
                Category = "Mixed Reality OpenXR - HoloLens 2 Ruleset",
                Message = $"GPU skinning negatively impacts the performance of HoloLens 2 applications.",
                CheckPredicate = () => !PlayerSettings.gpuSkinning,
                FixIt = () => PlayerSettings.gpuSkinning = false,
                FixItMessage = $"Disable GPU skinning",
                Error = false,
                HelpText = PerformanceHelpLinkText + "\r\n\r\n" + AboutValidationRulesetsHelpText,
                HelpLink = PerformanceHelpLink
            };
        }

        private static BuildValidationRule GenerateHL2RenderAndDepthSubmissionModeRule()
        {
            return new BuildValidationRule()
            {
                IsRuleEnabled = IsHL2RulesetEnabled,
                Category = "Mixed Reality OpenXR - HoloLens 2 Ruleset",
                Message = $"Single pass instanced is recommended for render mode and depth 16 bit is recommended for depth submission mode settings.",
                CheckPredicate = () =>
                {
                    if (TryGetOpenXRSetting(BuildTargetGroup.WSA, out OpenXRSettings settings))
                    {
                        return settings.depthSubmissionMode == OpenXRSettings.DepthSubmissionMode.Depth16Bit && settings.renderMode == OpenXRSettings.RenderMode.SinglePassInstanced;
                    }
                    return true;
                },
                FixIt = () =>
                {
                    if (TryGetOpenXRSetting(BuildTargetGroup.WSA, out OpenXRSettings settings))
                    {
                        settings.depthSubmissionMode = OpenXRSettings.DepthSubmissionMode.Depth16Bit;
                        settings.renderMode = OpenXRSettings.RenderMode.SinglePassInstanced;
                        EditorUtility.SetDirty(settings);
                    }
                    else
                    {
                        Debug.LogError(CannotAutoOptimizeForHL2);
                    }
                },
                FixItMessage = $"Switch the render mode to single pass instanced and depth submission mode to depth 16 bit",
                Error = false,
                HelpText = PerformanceHelpLinkText + "\r\n\r\n" + AboutValidationRulesetsHelpText,
                HelpLink = PerformanceHelpLink
            };
        }

        #endregion HoloLens 2 rules

        #region Camera setup rules

        // Guidelines for using a camera which will render output for a HoloLens 2
        private static BuildValidationRule[] GenerateCameraRules()
        {
            return new BuildValidationRule[] { GenerateCameraFlagsRule(ValidationRuleset.HoloLens2), GenerateCameraFlagsRule(ValidationRuleset.UWPAppRemoting),
                    GenerateCameraBackgroundColorRule(ValidationRuleset.HoloLens2), GenerateCameraBackgroundColorRule(ValidationRuleset.UWPAppRemoting),
                    GenerateCameraPoseDriverRule(ValidationRuleset.HoloLens2), GenerateCameraPoseDriverRule(ValidationRuleset.UWPAppRemoting) };
        } 

        private static BuildValidationRule GenerateCameraFlagsRule(ValidationRuleset targetRuleset)
        {
            return new BuildValidationRule() 
            {
                IsRuleEnabled = () => ValidationSettings.CurrentRuleset == targetRuleset,
                Category = $"Mixed Reality OpenXR - {targetRuleset.GetScenarioName()} Ruleset (Scene specific)",
                Message = $"It is recommended for the main camera to be cleared with a solid color.",
                CheckPredicate = () => Camera.main == null || Camera.main.clearFlags == CameraClearFlags.SolidColor,
                FixIt = () =>
                {
                    Camera.main.clearFlags = CameraClearFlags.SolidColor;
                    EditorSceneManager.MarkSceneDirty(EditorSceneManager.GetActiveScene());
                },
                FixItMessage = $"Set the main camera's clearFlags to CameraClearFlags.SolidColor",
                Error = false,
                FixItAutomatic = false,
                SceneOnlyValidation = true,
                HelpText = AboutValidationRulesetsHelpText
            };
        }
         
        private static BuildValidationRule GenerateCameraBackgroundColorRule(ValidationRuleset targetRuleset)
        {
            return new BuildValidationRule()
            {
                IsRuleEnabled = () => ValidationSettings.CurrentRuleset == targetRuleset,
                Category = $"Mixed Reality OpenXR - {targetRuleset.GetScenarioName()} Ruleset (Scene specific)",
                Message = $"It is recommended for the main camera to have a clear background color.",
                CheckPredicate = () => Camera.main == null || Camera.main.backgroundColor == Color.clear,
                FixIt = () =>
                {
                    Camera.main.backgroundColor = Color.clear;
                    EditorSceneManager.MarkSceneDirty(EditorSceneManager.GetActiveScene());
                },
                FixItMessage = $"Set the main camera background color to clear",
                Error = false,
                FixItAutomatic = false,
                SceneOnlyValidation = true,
                HelpText = AboutValidationRulesetsHelpText
            };
        }

        private static BuildValidationRule GenerateCameraPoseDriverRule(ValidationRuleset targetRuleset)
        {
            return new BuildValidationRule()
            {
                IsRuleEnabled = () => ValidationSettings.CurrentRuleset == targetRuleset,
                Category = $"Mixed Reality OpenXR - {targetRuleset.GetScenarioName()} Ruleset (Scene specific)",
                Message = $"It is recommended for the main camera to have a PoseDriver component.",
                CheckPredicate = () =>
                    Camera.main == null 
                    || Camera.main.gameObject.GetComponent<UnityEngine.SpatialTracking.TrackedPoseDriver>() != null
                    || Camera.main.gameObject.GetComponent<UnityEngine.InputSystem.XR.TrackedPoseDriver>() != null
#if USE_ARFOUNDATION && !USE_ARFOUNDATION_5_OR_NEWER
                    || Camera.main.gameObject.GetComponent<UnityEngine.XR.ARFoundation.ARPoseDriver>() != null
#endif
                    ,
                FixIt = () =>
                {
                    if (Camera.main != null 
                        && !Camera.main.gameObject.GetComponent<UnityEngine.SpatialTracking.TrackedPoseDriver>()
                        && !Camera.main.gameObject.GetComponent<UnityEngine.InputSystem.XR.TrackedPoseDriver>()
#if USE_ARFOUNDATION && !USE_ARFOUNDATION_5_OR_NEWER
                        && !Camera.main.gameObject.GetComponent<UnityEngine.XR.ARFoundation.ARPoseDriver>()
#endif
                        )
                    {
                        Camera.main.gameObject.AddComponent<UnityEngine.SpatialTracking.TrackedPoseDriver>();
                    }
                    EditorSceneManager.MarkSceneDirty(EditorSceneManager.GetActiveScene());
                },
                FixItMessage = $"Ensure the main camera has a PoseDriver component",
                Error = false,
                FixItAutomatic = false,
                SceneOnlyValidation = true,
                HelpText = AboutValidationRulesetsHelpText
            };
        }

        #endregion


        #region Android rules

        private static BuildValidationRule GenerateAndroidHandTrackingRule()
        {
            var handTrackingFeaturePlugins = new System.Type[] { typeof(HandTrackingFeaturePlugin) };
            return new BuildValidationRule()
            {
                IsRuleEnabled = () => true,
                Category = "Mixed Reality OpenXR - Android",
                Message = $"Hand tracking on Android with the Mixed Reality OpenXR Plugin has been deprecated. " +
                "For Android applications using hand tracking, we recommend transitioning to the OpenXR plugins from Unity and Meta.",
                CheckPredicate = () => !CheckFeatures(BuildTargetGroup.Android, handTrackingFeaturePlugins),
                FixIt = () => SettingsService.OpenProjectSettings("Project/XR Plug-in Management/OpenXR"),
                FixItMessage = $"Open Project Settings to disable the Hand Tracking feature for the Android build target.",
                FixItAutomatic = false,
                Error = false,
                HelpText = AboutValidationRulesetsHelpText
            };
        }

        private static BuildValidationRule GenerateAndroidMotionControllerRule()
        {
            var motionControllerFeaturePlugins = new System.Type[] { typeof(MotionControllerFeaturePlugin) };
            return new BuildValidationRule()
            {
                IsRuleEnabled = () => true,
                Category = "Mixed Reality OpenXR - Android",
                Message = $"The Motion Controller Model feature plugin from the Mixed Reality OpenXR Plugin has been deprecated on Android. " +
                "For Android applications using motion controller models, we recommend transitioning to the OpenXR plugins from Unity and Meta.",
                CheckPredicate = () => !CheckFeatures(BuildTargetGroup.Android, motionControllerFeaturePlugins),
                FixIt = () => SettingsService.OpenProjectSettings("Project/XR Plug-in Management/OpenXR"),
                FixItMessage = $"Open Project Settings to disable the Motion Controller feature for the Android build target.",
                FixItAutomatic = false,
                Error = false,
                HelpText = AboutValidationRulesetsHelpText
            };
        }
        #endregion Android rules


        #region Helpers

        private static bool UpdateRulesetMenuItemChecked(string menuPath, ValidationRuleset ruleset)
        {
            Menu.SetChecked(menuPath, ValidationSettings.CurrentRuleset == ruleset);
            return true;
        }

        private static bool IsHL2RulesetEnabled()
        {
            // Ensure the OpenXR loader is enabled on WSA - otherwise this is a flat UWP app on HL2 that shouldn't be validated with XR rules.
            XRGeneralSettings wsaSettings = XRSettingsHelpers.GetOrCreateXRGeneralSettings(BuildTargetGroup.WSA);
            if (!wsaSettings.Manager.activeLoaders.Any(loader => loader is UnityEngine.XR.OpenXR.OpenXRLoader))
            {
                return false;
            }

            // Ensure the HL2 feature plugin is enabled, with ValidationRuleTarget == HL2 - otherwise these specific rules are not necessary.
            MixedRealityFeaturePlugin plugin = BuildProcessorHelpers.GetOpenXRFeature<MixedRealityFeaturePlugin>(BuildTargetGroup.WSA, false);
            return plugin != null && plugin.enabled && (ValidationSettings.CurrentRuleset == ValidationRuleset.HoloLens2);
        }

        private static void EnableOpenXRLoader(BuildTargetGroup targetGroup)
        {
            if (XRSettingsHelpers.GetOrCreateXRManagerSettings(targetGroup) is XRManagerSettings settings && settings != null
            && XRPackageMetadataStore.AssignLoader(settings, nameof(OpenXRLoader), targetGroup))
            {
                EditorUtility.SetDirty(settings);
            }
            else
            {
                Debug.LogError(CannotAutoSetupForHL2);
            }
        }

        private static bool CheckFeatureSets(BuildTargetGroup targetGroup, List<string> featureIds)
        {
            if (XRSettingsHelpers.GetOrCreateXRManagerSettings(targetGroup) is XRManagerSettings settings && settings != null)
            {
                foreach (var featureSet in OpenXRFeatureSetManager.FeatureSetsForBuildTarget(targetGroup))
                {
                    if (featureIds.Contains(featureSet.featureSetId) && !featureSet.isEnabled)
                    {
                        return false;
                    }
                }
            }
            return true;
        }

        private static void EnableFeatureSets(BuildTargetGroup targetGroup, List<string> featureIds)
        {
            foreach (var featureSet in OpenXRFeatureSetManager.FeatureSetsForBuildTarget(targetGroup))
            {
                if (featureIds.Contains(featureSet.featureSetId) && !featureSet.isEnabled)
                {
                    featureSet.isEnabled = true;
                }
            }
            OpenXRFeatureSetManager.SetFeaturesFromEnabledFeatureSets(targetGroup);
        }

        private static void DisableFeatureSets(BuildTargetGroup targetGroup, List<string> featureIds)
        {
            foreach (var featureSet in OpenXRFeatureSetManager.FeatureSetsForBuildTarget(targetGroup))
            {
                if (featureIds.Contains(featureSet.featureSetId) && featureSet.isEnabled)
                {
                    featureSet.isEnabled = false;
                }
            }
            OpenXRFeatureSetManager.SetFeaturesFromEnabledFeatureSets(targetGroup);
        }

        // This extension method must be defined from within the Editor package, as it depends on the feature set types.
        internal static System.Type[] GetRequiredFeatureSets(this ValidationRuleset validationRuleset)
        {
            switch (validationRuleset)
            {
                case ValidationRuleset.Win32Standalone:
                    return new System.Type[] { typeof(WMRFeatureSet) };
                case ValidationRuleset.HoloLens2:
                    return new System.Type[] { typeof(HoloLensFeatureSet) };
                case ValidationRuleset.Win32AppRemoting:
                    return new System.Type[] { typeof(AppRemotingFeatureSet) };
                case ValidationRuleset.UWPAppRemoting:
                    return new System.Type[] { typeof(AppRemotingFeatureSet) };
            }
            Debug.LogError($"RequiredFeatureSets of ValidationRuleset \"{validationRuleset}\" are not defined.");
            return new System.Type[] { };
        }

        internal static System.Type[] GetNotRequiredFeatureSets(this ValidationRuleset validationRuleset)
        {
            switch (validationRuleset)
            {
                case ValidationRuleset.Win32Standalone:
                    return new System.Type[] { typeof(AppRemotingFeatureSet) };
                case ValidationRuleset.HoloLens2:
                    return new System.Type[] { typeof(AppRemotingFeatureSet) };
                case ValidationRuleset.Win32AppRemoting:
                    return new System.Type[] { };
                case ValidationRuleset.UWPAppRemoting:
                    return new System.Type[] { };
            }
            Debug.LogError($"RequiredFeatureSets of ValidationRuleset \"{validationRuleset}\" are not defined.");
            return new System.Type[] { };
        }

        private static bool TryGetOpenXRSetting(BuildTargetGroup targetGroup, out OpenXRSettings openXRSettings)
        {
            if (EditorBuildSettings.TryGetConfigObject(Constants.k_SettingsKey, out Object obj) && obj is IPackageSettings packageSettings
                && packageSettings.GetSettingsForBuildTargetGroup(targetGroup) is OpenXRSettings settings && settings != null)
            {
                openXRSettings = settings;
                return true;
            }
            else
            {
                openXRSettings = null;
                return false;
            }
        }

        private static bool CheckFeatures(BuildTargetGroup targetGroup, IEnumerable<System.Type> featureTypes)
        {
            if (TryGetOpenXRSetting(targetGroup, out OpenXRSettings settings))
            {
                foreach (OpenXRFeature feature in settings.GetFeatures())
                {
                    if (featureTypes.Contains(feature.GetType()) && !feature.enabled)
                    {
                        return false;
                    }
                }
            }
            return true;
        }

        private static void EnableFeatures(BuildTargetGroup targetGroup, IEnumerable<System.Type> featureTypes)
        {
            if (TryGetOpenXRSetting(targetGroup, out OpenXRSettings settings))
            {
                foreach (OpenXRFeature feature in settings.GetFeatures())
                {
                    if (featureTypes.Contains(feature.GetType()) && !feature.enabled)
                    {
                        feature.enabled = true;
                    }
                }
                EditorUtility.SetDirty(settings);
            }
        }

        private static void GetIdsAndUserNamesForFeatureSets(System.Type[] featureSets, ref List<string> featureSetIds, ref List<string> featureSetUINames)
        {
            for(int i = 0; i < featureSets.Length; i++) {
                var attribute = featureSets[i].GetCustomAttributes(typeof(OpenXRFeatureSetAttribute), true).FirstOrDefault() as OpenXRFeatureSetAttribute;
                if (attribute == null)
                {
                    Debug.LogError($"Could not generate Mixed Reality OpenXR feature set validator - feature set attribute not found for {featureSets[i]}");
                    continue;
                }

                featureSetIds.Add(attribute.FeatureSetId);
                featureSetUINames.Add(attribute.UiName);
            }
        }
        #endregion Helpers
    }
}

#endif