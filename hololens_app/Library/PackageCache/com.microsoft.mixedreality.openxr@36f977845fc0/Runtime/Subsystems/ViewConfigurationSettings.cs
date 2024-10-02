// Copyright (c) Microsoft Corporation.
// Licensed under the MIT License.

using System;
using System.Collections.Generic;
using System.Runtime.InteropServices;
using UnityEngine;

namespace Microsoft.MixedReality.OpenXR
{
    // Used to report reprojection settings for a view configuration to the native layer
    [StructLayout(LayoutKind.Sequential, Pack = 8)]
    internal struct NativeReprojectionSettings
    {
        public ReprojectionMode reprojectionMode;

        public Vector3 reprojectionPlaneOverridePosition;
        public byte reprojectionPlaneOverridePositionHasValue;

        public Vector3 reprojectionPlaneOverrideNormal;
        public byte reprojectionPlaneOverrideNormalHasValue;

        public Vector3 reprojectionPlaneOverrideVelocity;
        public byte reprojectionPlaneOverrideVelocityHasValue;

        internal NativeReprojectionSettings(ReprojectionSettings settings) : this()
        {
            reprojectionMode = settings.ReprojectionMode;

            if (settings.ReprojectionPlaneOverridePosition.HasValue)
            {
                reprojectionPlaneOverridePosition = settings.ReprojectionPlaneOverridePosition.Value;
                reprojectionPlaneOverridePositionHasValue = 1;
            }

            if (settings.ReprojectionPlaneOverrideNormal.HasValue)
            {
                reprojectionPlaneOverrideNormal = settings.ReprojectionPlaneOverrideNormal.Value;
                reprojectionPlaneOverrideNormalHasValue = 1;
            }

            if (settings.ReprojectionPlaneOverrideVelocity.HasValue)
            {
                reprojectionPlaneOverrideVelocity = settings.ReprojectionPlaneOverrideVelocity.Value;
                reprojectionPlaneOverrideVelocityHasValue = 1;
            }
        }
    }

    // Used to provide view configuration information from the native layer
    internal class OpenXRViewConfiguration
    {
        private ViewConfigurationType m_viewConfigurationType;
        private ReprojectionMode[] m_supportedReprojectionModes;

        public ViewConfigurationType ViewConfigurationType { get => m_viewConfigurationType; }

        internal bool HasTrackingFlags(NativeSpaceLocationFlags nativeSpaceLocationFlags)
        {
            NativeSpaceLocationFlags flags = NativeLib.GetViewTrackingFlags(m_viewConfigurationType);
            return (flags & nativeSpaceLocationFlags) == nativeSpaceLocationFlags;
        }

        public bool IsActive { get => NativeLib.GetViewConfigurationIsActive(m_viewConfigurationType); }

        public bool IsPrimary { get => NativeLib.GetViewConfigurationIsPrimary(m_viewConfigurationType); }

        public IReadOnlyList<ReprojectionMode> SupportedReprojectionModes { get => m_supportedReprojectionModes; }

        public float StereoSeparationAdjustment { get => NativeLib.GetStereoSeparationAdjustment(); }

        public OpenXRViewConfiguration(ViewConfigurationType viewConfigurationType)
        {
            m_viewConfigurationType = viewConfigurationType;

            uint numSupportedModes = NativeLib.GetSupportedReprojectionModesCount(m_viewConfigurationType);
            m_supportedReprojectionModes = new ReprojectionMode[numSupportedModes];
            NativeLib.GetSupportedReprojectionModes(m_viewConfigurationType, m_supportedReprojectionModes, numSupportedModes);
        }

        public void SetReprojectionSettings(ReprojectionSettings reprojectionSettings)
        {
            NativeLib.SetReprojectionSettings(m_viewConfigurationType, new NativeReprojectionSettings(reprojectionSettings));
        }

        public void SetStereoSeparationAdjustment(float stereoSeparationAdjustment)
        {
            NativeLib.SetStereoSeparationAdjustment(stereoSeparationAdjustment);
        }
    }

    internal class OpenXRViewConfigurationSettings : SubsystemController
    {
        private List<ViewConfiguration> m_enabledViewConfigurations = new List<ViewConfiguration>();
        private ViewConfiguration m_primaryViewConfiguration = null;

        public IReadOnlyList<ViewConfiguration> EnabledViewConfigurations => m_enabledViewConfigurations;
        public ViewConfiguration PrimaryViewConfiguration => m_primaryViewConfiguration;

        public OpenXRViewConfigurationSettings(IOpenXRContext context) : base(context)
        {
            context.SessionBegun += Context_SessionBegun;
            context.SessionEnding += Context_SessionEnding;
        }

        private void Context_SessionBegun(IOpenXRContext sender, EventArgs args)
        {
            // Enabled view configurations are changed when session begin/end
            uint viewConfigurationTypesCount = NativeLib.GetEnabledViewConfigurationTypesCount();
            ViewConfigurationType[] viewConfigurationTypes = new ViewConfigurationType[viewConfigurationTypesCount];
            NativeLib.GetEnabledViewConfigurationTypes(viewConfigurationTypes, viewConfigurationTypesCount);

            foreach (ViewConfigurationType viewConfigurationType in viewConfigurationTypes)
            {
                OpenXRViewConfiguration openxrViewConfiguration = new OpenXRViewConfiguration(viewConfigurationType);
                ViewConfiguration viewConfiguration = new ViewConfiguration(openxrViewConfiguration);
                m_enabledViewConfigurations.Add(viewConfiguration);
                if (openxrViewConfiguration.IsPrimary)
                {
                    m_primaryViewConfiguration = viewConfiguration;
                }
            }
        }

        private void Context_SessionEnding(IOpenXRContext sender, EventArgs args)
        {
            m_enabledViewConfigurations.Clear();
            m_primaryViewConfiguration = null;
        }
    }
}
