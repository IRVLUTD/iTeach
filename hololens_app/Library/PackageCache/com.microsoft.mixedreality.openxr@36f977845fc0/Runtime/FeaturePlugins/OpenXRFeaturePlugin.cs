// Copyright (c) Microsoft Corporation.
// Licensed under the MIT License.

using System;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.XR.OpenXR;
using UnityEngine.XR.OpenXR.Features;
using UnityEngine.XR.OpenXR.NativeTypes;

namespace Microsoft.MixedReality.OpenXR
{
    internal abstract class OpenXRFeaturePlugin<TPlugin>
        : OpenXRFeaturePlugin where TPlugin : OpenXRFeaturePlugin<TPlugin>
    {
        private static OpenXRFeature m_feature;

        internal static TPlugin Feature => (TPlugin)m_feature;

        protected override void OnEnable()
        {
            // Important notes about this Feature reference initialization:
            // - Awake and OnEnable are called sequentially when this ScriptableObject is created, far earlier than when values such as the Feature singleton should be used.
            // - ScriptableObject::OnEnable always runs when the feature is supported, independent of whether or not the enabled value defined in OpenXRFeature is true.
            // - The reference must be refreshed in OnEnable, as Awake is not called on domain refresh (e.g. editing scripts while the editor is open).
            // - References to OpenXR Project Settings are avoided, as they may not be available (e.g. while regenerating the project settings asset).

            var featureInCurrentPlatform = OpenXRSettings.Instance.GetFeature<TPlugin>();
            if (featureInCurrentPlatform == this)
            {
                // C# scriptable object might be enabled for project settings in editor
                // that's meant for other platforms, and won't be used when running the app.
                // Only initialize those scriptable objects in the current platform.
                // This field will be refreshed upon app domain refresh.
                m_feature = this;
            }

            base.OnEnable();
        }
    }

    internal abstract class OpenXRFeaturePlugin
        : OpenXRFeature, IOpenXRContext, ISubsystemPlugin
    {
        private List<SubsystemController> m_subsystemControllers = new List<SubsystemController>();

        public ulong Instance { get; private set; } = 0;
        public ulong SystemId { get; private set; } = 0;
        public ulong Session { get; private set; } = 0;
        public bool IsSessionRunning { get; private set; } = false;
        public XrSessionState SessionState { get; private set; } = XrSessionState.Unknown;
        public ulong SceneOriginSpace { get; private set; } = 0;

        public event OpenXRContextEvent InstanceCreated;       // after instance is created
        public event OpenXRContextEvent InstanceDestroying;    // before instance is destroyed
        public event OpenXRContextEvent SessionCreated;        // after session is created
        public event OpenXRContextEvent SessionDestroying;     // before session is destroyed
        public event OpenXRContextEvent SessionBegun;          // after session is begun
        public event OpenXRContextEvent SessionEnding;         // before session is ended

        // Convert protected OpenXRFeature.xrGetInstanceProcAddr to internal visibility
        internal static IntPtr PFN_xrGetInstanceProcAddr => OpenXRFeature.xrGetInstanceProcAddr;

        protected override void OnEnable()
        {
            base.OnEnable();
            OpenXRFeaturePluginManager.OnFeaturePluginInitializing(this);

            if (OpenXRFeaturePluginManager.NativeLibAvailable)
            {
                PluginEnvironmentSubsystem.InitializePlugin();
            }
        }

        protected override IntPtr HookGetInstanceProcAddr(IntPtr func)
        {
            OpenXRFeaturePluginManager.InitializeOpenXRFeatureList();

            if (OpenXRFeaturePluginManager.IsResponsibleForNativeLib(this))
            {
                func = NativeLib.HookGetInstanceProcAddr(func);
            }
            return func;
        }

        protected void AddSubsystemController(SubsystemController subsystemController)
        {
            m_subsystemControllers.Add(subsystemController);
        }

        protected override void OnSubsystemCreate()
        {
            m_subsystemControllers.ForEach(controller => controller.OnSubsystemCreate(this));
        }

        protected override void OnSubsystemStart()
        {
            if (OpenXRFeaturePluginManager.IsResponsibleForNativeLib(this))
            {
                NativeLib.OnSubsystemsStarting();
            }
            m_subsystemControllers.ForEach(controller => controller.OnSubsystemStart(this));
        }

        protected override void OnSubsystemStop()
        {
            m_subsystemControllers.ForEach(controller => controller.OnSubsystemStop(this));
            if (OpenXRFeaturePluginManager.IsResponsibleForNativeLib(this))
            {
                NativeLib.OnSubsystemsStopped();
            }
        }

        protected override void OnSubsystemDestroy()
        {
            m_subsystemControllers.ForEach(controller => controller.OnSubsystemDestroy(this));
        }

        protected override bool OnInstanceCreate(ulong instance)
        {
            if (Instance != 0)
            {
                Debug.LogWarning("New instance was created without properly destroying the previous one.");
            }

            Instance = instance;

            string[] enabledExtensionNames = OpenXRRuntime.GetEnabledExtensions();
            if (OpenXRFeaturePluginManager.IsResponsibleForNativeLib(this))
            {
                NativeLib.OnInstanceCreated(instance, PFN_xrGetInstanceProcAddr, enabledExtensionNames, enabledExtensionNames.Length);
            }

            InstanceCreated?.Invoke(this, EventArgs.Empty);
            return true;
        }

        protected override void OnInstanceDestroy(ulong instance)
        {
            if (Instance == 0)
            {
                // Unity might call destroy when instance handle was not successfully created
                // Ignore such cases since there's no resources associated with instance of 0.
                return;
            }

            if (SystemId != 0)
            {
                // Unity's OnSystemChange event won't trigger when destroying instance.
                // Reset resources associated with system before destroying the instance.
                SystemId = 0;
                if (OpenXRFeaturePluginManager.IsResponsibleForNativeLib(this))
                {
                    NativeLib.SetXrSystemId(0);
                }
            }

            InstanceDestroying?.Invoke(this, EventArgs.Empty);
            Instance = 0;
            if (OpenXRFeaturePluginManager.IsResponsibleForNativeLib(this))
            {
                NativeLib.OnInstanceDestroyed();
            }
        }

        protected override void OnSystemChange(ulong systemId)
        {
            SystemId = systemId;
            if (OpenXRFeaturePluginManager.IsResponsibleForNativeLib(this))
            {
                NativeLib.SetXrSystemId(systemId);
            }
        }

        protected override void OnSessionCreate(ulong session)
        {
            Session = session;
            PluginEnvironmentSubsystem.OnSessionCreated();

            if (OpenXRFeaturePluginManager.IsResponsibleForNativeLib(this))
            {
                NativeLib.SetXrSession(session);
            }
            SessionCreated?.Invoke(this, EventArgs.Empty);
        }

        protected override void OnSessionBegin(ulong session)
        {
            // This virtual function is called right after xrSessionBegin returns, 
            // All C# scripts should observe that the session is running.
            IsSessionRunning = true;

            if (OpenXRFeaturePluginManager.IsResponsibleForNativeLib(this))
            {
                NativeLib.SetXrSessionRunning(true);
            }
            SessionBegun?.Invoke(this, EventArgs.Empty);
        }

        protected override void OnSessionStateChange(int oldState, int newState)
        {
            SessionState = (XrSessionState)newState;
            if (OpenXRFeaturePluginManager.IsResponsibleForNativeLib(this))
            {
                NativeLib.SetSessionState((uint)newState);
            }
        }

        protected override void OnSessionEnd(ulong session)
        {
            SessionEnding?.Invoke(this, EventArgs.Empty);
            if (OpenXRFeaturePluginManager.IsResponsibleForNativeLib(this))
            {
                NativeLib.SetXrSessionRunning(false);
            }

            // This virtual function is called right before xrSessionEnd is called.
            // All C# scripts should still observe that the session is running until this point.
            IsSessionRunning = false;
        }

        protected override void OnSessionDestroy(ulong session)
        {
            SessionDestroying?.Invoke(this, EventArgs.Empty);
            Session = 0;
            if (OpenXRFeaturePluginManager.IsResponsibleForNativeLib(this))
            {
                NativeLib.SetXrSession(0);
            }
        }

        protected override void OnAppSpaceChange(ulong sceneOriginSpace)
        {
            SceneOriginSpace = sceneOriginSpace;
            if (OpenXRFeaturePluginManager.IsResponsibleForNativeLib(this))
            {
                NativeLib.SetSceneOriginSpace(sceneOriginSpace);
            }
        }

        // Convert protected function to internal
        internal static new void SetEnvironmentBlendMode(XrEnvironmentBlendMode environmentBlendMode)
        {
            OpenXRFeature.SetEnvironmentBlendMode(environmentBlendMode);
        }

        // Convert protected function to internal
        internal static new XrEnvironmentBlendMode GetEnvironmentBlendMode()
        {
            return OpenXRFeature.GetEnvironmentBlendMode();
        }

        void ISubsystemPlugin.CreateSubsystem<TDescriptor, TSubsystem>(List<TDescriptor> descriptors, string id) =>
            base.CreateSubsystem<TDescriptor, TSubsystem>(descriptors, id);

        void ISubsystemPlugin.StartSubsystem<T>() => base.StartSubsystem<T>();

        void ISubsystemPlugin.StopSubsystem<T>() => base.StopSubsystem<T>();

        void ISubsystemPlugin.DestroySubsystem<T>() => base.DestroySubsystem<T>();
    }
}