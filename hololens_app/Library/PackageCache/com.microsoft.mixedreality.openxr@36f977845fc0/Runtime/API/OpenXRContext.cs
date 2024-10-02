// Copyright (c) Microsoft Corporation.
// Licensed under the MIT License.

using System;

namespace Microsoft.MixedReality.OpenXR
{
    /// <summary>
    /// Retrieve the current OpenXR instance, session handles and states.
    /// </summary>
    public class OpenXRContext
    {
        /// <summary>
        /// Get the current OpenXR context.
        /// </summary>
        public static OpenXRContext Current { get; } = new OpenXRContext();

        /// <summary>
        /// The XrInstance handle, or 0 when instance is not initialized.
        /// </summary>
        public ulong Instance => OpenXRFeaturePluginManager.ActiveFeature?.Instance ?? 0;

        /// <summary>
        /// The XrSystemId, or 0 when system is not available.
        /// </summary>
        public ulong SystemId => OpenXRFeaturePluginManager.ActiveFeature?.SystemId ?? 0;

        /// <summary>
        /// The XrSession handle, or 0 when session is not created.
        /// </summary>
        public ulong Session => OpenXRFeaturePluginManager.ActiveFeature?.Session ?? 0;

        /// <summary>
        /// Whether the current XrSession is running, i.e. when the frame loop is in progress.
        /// </summary>
        public bool IsSessionRunning => OpenXRFeaturePluginManager.ActiveFeature?.IsSessionRunning ?? false;

        /// <summary>
        /// An XrSpace handle to the reference space of the current Unity scene origin, or 0 when not available.
        /// It's typically a LOCAL, a STAGE or an UNBOUNDED reference space handle when available.
        /// </summary>
        public ulong SceneOriginSpace => OpenXRFeaturePluginManager.ActiveFeature?.SceneOriginSpace ?? 0;

        /// <summary>
        /// Get the function pointer to PFN_xrGetInstanceProcAddr that includes Unity OpenXR plugin and features overrides.
        /// Returns 0 when XR is not loaded in Unity or xrInstance handle above is 0.
        /// </summary>
        public IntPtr PFN_xrGetInstanceProcAddr => OpenXRFeaturePlugin.PFN_xrGetInstanceProcAddr;

        private OpenXRContext() { } // Should use static singleton `Current` property instead.
    }
}
