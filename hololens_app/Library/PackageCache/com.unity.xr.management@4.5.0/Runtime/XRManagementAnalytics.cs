using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.CompilerServices;
using System.Diagnostics.CodeAnalysis;

#if UNITY_EDITOR
using UnityEditor;
#endif

#if UNITY_ANALYTICS && ENABLE_CLOUD_SERVICES_ANALYTICS
using UnityEngine.Analytics;
#endif //UNITY_ANALYTICS && ENABLE_CLOUD_SERVICES_ANALYTICS

[assembly:InternalsVisibleTo("Unity.XR.Management.Editor")]
namespace UnityEngine.XR.Management
{
    internal static class XRManagementAnalytics
    {
        private const int kMaxEventsPerHour = 1000;
        private const int kMaxNumberOfElements = 1000;
        private const string kVendorKey = "unity.xrmanagement";
        private const string kEventBuild = "xrmanagment_build";

#if ENABLE_CLOUD_SERVICES_ANALYTICS && UNITY_ANALYTICS
        private static bool s_Initialized = false;
#endif //ENABLE_CLOUD_SERVICES_ANALYTICS && UNITY_ANALYTICS

        [Serializable]
        private struct BuildEvent
#if UNITY_2023_2_OR_NEWER && ENABLE_CLOUD_SERVICES_ANALYTICS && UNITY_ANALYTICS
            : IAnalytic.IData
#endif //UNITY_2023_2_OR_NEWER && ENABLE_CLOUD_SERVICES_ANALYTICS && UNITY_ANALYTICS
        {
            public string buildGuid;
            public string buildTarget;
            public string buildTargetGroup;
            public string[] assigned_loaders;
        }

#if UNITY_2023_2_OR_NEWER && ENABLE_CLOUD_SERVICES_ANALYTICS && UNITY_ANALYTICS
        [AnalyticInfo(eventName: kEventBuild, vendorKey: kVendorKey, maxEventsPerHour: kMaxEventsPerHour, maxNumberOfElements: kMaxNumberOfElements)]
        private class XrInitializeAnalytic : IAnalytic
        {
            private BuildEvent? data = null;

            public XrInitializeAnalytic(BuildEvent data)
            {
                this.data = data;
            }

            public bool TryGatherData(out IAnalytic.IData data, [NotNullWhen(false)] out Exception error)
            {
                error = null;
                data = this.data;
                return data != null;
            }
        }
#endif //UNITY_2023_2_OR_NEWER && ENABLE_CLOUD_SERVICES_ANALYTICS && UNITY_ANALYTICS

        private static bool Initialize()
        {
#if ENABLE_TEST_SUPPORT || !ENABLE_CLOUD_SERVICES_ANALYTICS || !UNITY_ANALYTICS
            return false;
#elif UNITY_EDITOR && UNITY_2023_2_OR_NEWER
            return EditorAnalytics.enabled;
#else

#if UNITY_EDITOR
            if (!EditorAnalytics.enabled)
                return false;

            if(AnalyticsResult.Ok != EditorAnalytics.RegisterEventWithLimit(kEventBuild, kMaxEventsPerHour, kMaxNumberOfElements, kVendorKey))
                return false;
            s_Initialized = true;
#endif //UNITY_EDITOR
            return s_Initialized;
#endif //ENABLE_TEST_SUPPORT || !ENABLE_CLOUD_SERVICES_ANALYTICS || !UNITY_ANALYTICS

        }

#if UNITY_EDITOR
        public static void SendBuildEvent(GUID guid, BuildTarget buildTarget, BuildTargetGroup buildTargetGroup, IEnumerable<XRLoader> loaders)
        {

#if UNITY_ANALYTICS && ENABLE_CLOUD_SERVICES_ANALYTICS

            if (!s_Initialized && !Initialize())
            {
                return;
            }

            List<string> loaderTypeNames = new List<string>();
            foreach (var loader in loaders)
            {
                loaderTypeNames.Add(loader.GetType().Name);
            }

            var data = new BuildEvent
            {
                buildGuid = guid.ToString(),
                buildTarget = buildTarget.ToString(),
                buildTargetGroup = buildTargetGroup.ToString(),
                assigned_loaders = loaderTypeNames.ToArray(),
            };
#if UNITY_2023_2_OR_NEWER
            EditorAnalytics.SendAnalytic(new XrInitializeAnalytic(data));
#else
            EditorAnalytics.SendEventWithLimit(kEventBuild, data);
#endif //UNITY_2023_2_OR_NEWER
#endif //UNITY_ANALYTICS && ENABLE_CLOUD_SERVICES_ANALYTICS

        }
#endif //UNITY_EDITOR
    }
}
