
// Copyright (c) Microsoft Corporation.
// Licensed under the MIT License.

#if UNITY_EDITOR

using Microsoft.MixedReality.OpenXR.Editor;
using Microsoft.MixedReality.OpenXR.Remoting;
using System;
using System.IO;
using UnityEditor;
using UnityEditor.XR.OpenXR.Features;
using UnityEngine;
using UnityEngine.XR.OpenXR.Features.Interactions;

namespace Microsoft.MixedReality.OpenXR
{
    internal enum ValidationRuleset {
        None,
        Win32Standalone,
        HoloLens2,
        Win32AppRemoting,
        UWPAppRemoting
    }

    internal static class ValidationRulesetExtensions
    {
        // Example usage: $"This validation is for building {scenario name} apps"
        internal static string GetScenarioName(this ValidationRuleset validationRuleset)
        {
            switch(validationRuleset)
            {
                case ValidationRuleset.Win32Standalone:   return "Standalone Win32 XR";
                case ValidationRuleset.HoloLens2:         return "HoloLens 2";
                case ValidationRuleset.Win32AppRemoting:  return "Holographic Remoting Win32 Remote";
                case ValidationRuleset.UWPAppRemoting:    return "Holographic Remoting UWP Remote";
            }
            Debug.LogError($"ScenarioName of ValidationRuleset \"{validationRuleset}\" is not defined.");
            return "";
        }

        // Example usage: $"loader must be enabled for {platformShortName}"
        internal static string GetPlatformShortName(this ValidationRuleset validationRuleset)
        {
            switch(validationRuleset)
            {
                case ValidationRuleset.Win32Standalone:   return "Standalone";
                case ValidationRuleset.HoloLens2:         return "UWP";
                case ValidationRuleset.Win32AppRemoting:  return "Standalone";
                case ValidationRuleset.UWPAppRemoting:    return "UWP";
            }
            Debug.LogError($"PlatformShortName of ValidationRuleset \"{validationRuleset}\" is not defined.");
            return "";
        }

        internal static BuildTargetGroup GetBuildTargetGroup(this ValidationRuleset validationRuleset)
        {
            switch(validationRuleset)
            {
                case ValidationRuleset.Win32Standalone:   return BuildTargetGroup.Standalone;
                case ValidationRuleset.HoloLens2:         return BuildTargetGroup.WSA;
                case ValidationRuleset.Win32AppRemoting:  return BuildTargetGroup.Standalone;
                case ValidationRuleset.UWPAppRemoting:    return BuildTargetGroup.WSA;
            }
            Debug.LogError($"BuildTargetGroup of ValidationRuleset \"{validationRuleset}\" is not defined.");
            return BuildTargetGroup.Unknown;
        }

        internal static BuildTarget GetBuildTarget(this ValidationRuleset validationRuleset)
        {
            switch(validationRuleset)
            {
                case ValidationRuleset.Win32Standalone:   return BuildTarget.StandaloneWindows64;
                case ValidationRuleset.HoloLens2:         return BuildTarget.WSAPlayer;
                case ValidationRuleset.Win32AppRemoting:  return BuildTarget.StandaloneWindows64;
                case ValidationRuleset.UWPAppRemoting:    return BuildTarget.WSAPlayer;
            }
            Debug.LogError($"BuildTarget of ValidationRuleset \"{validationRuleset}\" is not defined.");
            return BuildTarget.StandaloneWindows64;
        }

        internal static bool GetRemotingEnabled(this ValidationRuleset validationRuleset)
        {
            switch (validationRuleset)
            {
                case ValidationRuleset.Win32Standalone:  return false;
                case ValidationRuleset.HoloLens2:        return false;
                case ValidationRuleset.Win32AppRemoting: return true;
                case ValidationRuleset.UWPAppRemoting:   return true;
            }
            Debug.LogError($"RemotingEnabled of ValidationRuleset \"{validationRuleset}\" is not defined.");
            return false;
        }
    }

    internal static class ValidationSettings
    {
        private const string SettingsFileName = "MixedRealityOpenXRValidationSettings.asset";
        private static string XRSettingsFolder => Path.Combine(Application.dataPath, "..", "ProjectSettings");
        private static string SettingsAssetPath => Path.Combine(XRSettingsFolder, SettingsFileName);

        private class SerializableSettings : ScriptableObject {
            [field: SerializeField]
            internal ValidationRuleset Ruleset { get; set; } = ValidationRuleset.None;
        }

        private static SerializableSettings settingsInstance;

        private static SerializableSettings CurrentSettings
        {
            get
            {
                if (settingsInstance == null)
                {
                    LoadSettings();
                }
                return settingsInstance;
            }
        }

        internal static ValidationRuleset CurrentRuleset
        {
            get => CurrentSettings.Ruleset;
            set
            {
                if(CurrentSettings.Ruleset != value)
                {
                    CurrentSettings.Ruleset = value;
                    SaveSettings();
                }
            }
        }

        private static void LoadSettings()
        {
            settingsInstance = ScriptableObject.CreateInstance<SerializableSettings>();

            if (File.Exists(SettingsAssetPath))
            {
                using (StreamReader settingsReader = new StreamReader(SettingsAssetPath))
                {
                    JsonUtility.FromJsonOverwrite(settingsReader.ReadToEnd(), settingsInstance);
                }
            }

            // If this file doesn't yet exist, port the old value from MixedRealityFeaturePlugin.
            else
            {
                MixedRealityFeaturePlugin plugin = BuildProcessorHelpers.GetOpenXRFeature<MixedRealityFeaturePlugin>(BuildTargetGroup.WSA, false);
                if (plugin == null)
                {
                    FeatureHelpers.RefreshFeatures(BuildTargetGroup.WSA);
                    plugin = BuildProcessorHelpers.GetOpenXRFeature<MixedRealityFeaturePlugin>(BuildTargetGroup.WSA, false);
                }

                if (plugin != null && plugin.validationRuleTarget == MixedRealityFeaturePlugin.ValidationRuleTargetPlatform.HoloLens2)
                {
                    settingsInstance.Ruleset = ValidationRuleset.HoloLens2;
                }
                else
                {
                    settingsInstance.Ruleset = ValidationRuleset.None;
                }
                SaveSettings();
            }
        }

        private static void SaveSettings()
        {
            if (settingsInstance == null)
            {
                return;
            }

            if (!Directory.Exists(XRSettingsFolder))
            {
                Directory.CreateDirectory(XRSettingsFolder);
            }

            using (StreamWriter settingsWriter = new StreamWriter(SettingsAssetPath))
            {
                settingsWriter.Write(JsonUtility.ToJson(settingsInstance, true));
            }
        }
    }
}

#endif // UNITY_EDITOR