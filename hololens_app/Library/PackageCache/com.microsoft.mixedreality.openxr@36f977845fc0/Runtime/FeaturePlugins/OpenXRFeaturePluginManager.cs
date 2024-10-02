// Copyright (c) Microsoft Corporation.
// Licensed under the MIT License.

using System;
using System.Collections.Generic;
using UnityEngine.XR.OpenXR;

namespace Microsoft.MixedReality.OpenXR
{
    [AttributeUsage(AttributeTargets.Class)]
    public class RequiresNativePluginDLLsAttribute : Attribute { }

    // A utility for managing connections between Mixed Reality OpenXR feature plugins and the native plugin DLL.
    internal static class OpenXRFeaturePluginManager
    {
        // If this is true, the NativeLib is guaranteed to be available.
        // If this is false, the NativeLib may or may not be available.
        internal static bool NativeLibAvailable { get => m_nativeLibAvailable; }
        private static bool m_nativeLibAvailable = false;

        // Cache the result of all enabled OpenXRSettings.Instance.GetFeatures() in our package.
        // The first element in the list will serve as the active feature for routing states to native library.
        // This list is updated at query for PFN_xrGetInstanceProcAddr, which is openxr_loader first load the runtime.
        private static List<OpenXRFeaturePlugin> m_enabledPluginFeatures = new List<OpenXRFeaturePlugin>();

        // ActiveFeature is one of the enabled OpenXRFeature, when not null, it's in sync with OpenXR runtime status.
        internal static OpenXRFeaturePlugin ActiveFeature => m_enabledPluginFeatures.Count > 0 ? m_enabledPluginFeatures[0] : null;

        // Because Unity's OpenXRFeature notifies child classes about OpenXR state changes 
        // always in a loop. reference: OpenXRFeature.cs, ReceiveNativeEvent() function.
        // To update our nativeLib, only one of such sync function is enough.
        // Choose the 1st enabled feature related to nativeLib as the responsible child class.
        internal static bool IsResponsibleForNativeLib(OpenXRFeaturePlugin plugin)
        {
            return m_enabledPluginFeatures.Count > 0 ? m_enabledPluginFeatures[0] == plugin : false;
        }

        internal static void OnFeaturePluginInitializing(OpenXRFeaturePlugin feature)
        {
            if (!m_nativeLibAvailable)
            {
                TryInitializeNativeLibAvailable(feature.GetType());
            }
        }

        internal static void TryInitializeNativeLibAvailable(Type featureType)
        {
            if (!m_nativeLibAvailable)
            {
                var feature = OpenXRSettings.Instance.GetFeature(featureType);
                if (feature != null && feature.enabled && Attribute.IsDefined(featureType, typeof(RequiresNativePluginDLLsAttribute)))
                {
                    m_nativeLibAvailable = true;
                }
            }
        }

        internal static void InitializeOpenXRFeatureList()
        {
            m_enabledPluginFeatures.Clear();
            var features = OpenXRSettings.Instance.GetFeatures(typeof(OpenXRFeaturePlugin));
            foreach (var pluginFeature in features)
            {
                if (pluginFeature != null && pluginFeature.enabled)
                {
                    m_enabledPluginFeatures.Add((OpenXRFeaturePlugin)pluginFeature);
                    NativeLib.InitializePluginProviders(pluginFeature.GetType().Name);
                }
            }
        }
    }
}