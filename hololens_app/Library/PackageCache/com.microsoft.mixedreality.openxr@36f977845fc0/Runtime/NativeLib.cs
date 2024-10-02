// Copyright (c) Microsoft Corporation.
// Licensed under the MIT License.

using System;
using System.Runtime.InteropServices;
using System.Text;
using Microsoft.MixedReality.OpenXR.ARSubsystems;
using UnityEngine;
using UnityEngine.XR.ARSubsystems;

namespace Microsoft.MixedReality.OpenXR
{
    [Flags]
    internal enum NativeSpaceLocationFlags : uint
    {
        OrientationValid = 1,
        PositionValid = 2,
        OrientationTracked = 4,
        PositionTracked = 8,
        All = 15
    }

    [Serializable, StructLayout(LayoutKind.Sequential, Pack = 8)]
    internal struct MixedRealityPluginOptions
    {
        private byte m_disableFirstPersonObserver;
        private byte m_enablePoseUpdateOnBeforeRender;

        public bool DisableFirstPersonObserver
        {
            get { return m_disableFirstPersonObserver != 0; }
            set { m_disableFirstPersonObserver = (byte)(value ? 1 : 0); }
        }
        public bool EnablePoseUpdateOnBeforeRender
        {
            get { return m_enablePoseUpdateOnBeforeRender != 0; }
            set { m_enablePoseUpdateOnBeforeRender = (byte)(value ? 1 : 0); }
        }
    }

    [Serializable, StructLayout(LayoutKind.Sequential, Pack = 8)]
    internal struct HandTrackingOptions
    {
        [SerializeField, Tooltip("The requested motion range for this hand.")]
        private HandJointsMotionRange motionRange;

        public HandJointsMotionRange MotionRange
        {
            get => motionRange;
            set => motionRange = value;
        }
    }

    // IL2CPP does not support marshaling delegates that do not have this attribute.
    internal class MonoPInvokeCallbackAttribute : Attribute { public MonoPInvokeCallbackAttribute() { } }

    internal class NativeLib
    {
        internal const string DllName = "MicrosoftOpenXRPlugin";

        // Configure Unity's IL2CPP compiler to process C# string (always UTF16) interop to C++ "const char*".
        // Unity by default is converting to UTF8 when compiling IL2CPP code for pinvoke.
        // Using the [MarshalAs(UnmanagedUTF8Type)] string to make this conversion more explicitly.
        // UnmanagedType.LPUTF8Str is only defined in Net40, so for compatibility on NET20, use 48 instead.
        internal const short UnmanagedUTF8Type = 48; // UnmanagedType.LPUTF8Str

        [DllImport(DllName, EntryPoint = "openxr_plugin_InitializePlugin")]
        internal static extern void InitializePlugin();

        [DllImport(DllName, EntryPoint = "openxr_plugin_InitializePluginProviders")]
        internal static extern void InitializePluginProviders([MarshalAs(UnmanagedUTF8Type)] string featureName);

        [DllImport(DllName, EntryPoint = "openxr_plugin_SetPluginEnvironment")]
        internal static extern void SetPluginEnvironment(PluginEnvironment pluginEnvironment, [MarshalAs(UnmanagedUTF8Type)] string pluginInfo);

        [DllImport(DllName, EntryPoint = "openxr_plugin_OnSubsystemsStarting")]
        internal static extern void OnSubsystemsStarting();

        [DllImport(DllName, EntryPoint = "openxr_plugin_OnSubsystemsStopped")]
        internal static extern void OnSubsystemsStopped();

        [DllImport(DllName, EntryPoint = "openxr_plugin_HookGetInstanceProcAddr")]
        internal static extern IntPtr HookGetInstanceProcAddr(IntPtr func);

        [DllImport(DllName, EntryPoint = "openxr_plugin_OnInstanceCreated")]
        internal static extern void OnInstanceCreated(ulong instance, IntPtr xrGetInstanceProcAddr, string[] enabledExtensionNames, int enabledExtensionNamesCount);

        [DllImport(DllName, EntryPoint = "openxr_plugin_OnInstanceDestroyed")]
        internal static extern void OnInstanceDestroyed();

        [DllImport(DllName, EntryPoint = "openxr_plugin_SetXrSystemId")]
        internal static extern void SetXrSystemId(ulong systemId);

        [DllImport(DllName, EntryPoint = "openxr_plugin_SetXrSession")]
        internal static extern void SetXrSession(ulong session);

        [DllImport(DllName, EntryPoint = "openxr_plugin_SetXrSessionRunning")]
        internal static extern void SetXrSessionRunning([MarshalAs(UnmanagedType.U1)] bool running);

        [DllImport(DllName, EntryPoint = "openxr_plugin_SetXrSessionState")]
        internal static extern void SetSessionState(uint sessionState);

        [DllImport(DllName, EntryPoint = "openxr_plugin_GetViewTrackingFlags")]
        internal static extern NativeSpaceLocationFlags GetViewTrackingFlags(ViewConfigurationType viewConfigurationType);

        [DllImport(DllName, EntryPoint = "openxr_plugin_SetMixedRealityPluginOptions")]
        internal static extern void SetMixedRealityPluginOptions(MixedRealityPluginOptions mixedRealityPluginOptions);

        [DllImport(DllName, EntryPoint = "openxr_plugin_SetSceneOriginSpace")]
        internal static extern void SetSceneOriginSpace(ulong sceneOriginSpace);

        [DllImport(DllName, EntryPoint = "openxr_plugin_IsSelectKeywordFiltered")]
        [return: MarshalAs(UnmanagedType.U1)] 
        internal static extern bool IsSelectKeywordFiltered();

        [DllImport(DllName, EntryPoint = "openxr_plugin_GetEnabledViewConfigurationTypesCount")]
        internal static extern uint GetEnabledViewConfigurationTypesCount();

        [DllImport(DllName, EntryPoint = "openxr_plugin_GetEnabledViewConfigurationTypes")]
        internal static extern void GetEnabledViewConfigurationTypes(ViewConfigurationType[] viewConfigurationTypes, uint viewConfigurationTypesCapacity);

        [DllImport(DllName, EntryPoint = "openxr_plugin_GetViewConfigurationIsActive")]
        [return: MarshalAs(UnmanagedType.U1)] 
        internal static extern bool GetViewConfigurationIsActive(ViewConfigurationType viewConfigurationType);

        [DllImport(DllName, EntryPoint = "openxr_plugin_GetViewConfigurationIsPrimary")]
        [return: MarshalAs(UnmanagedType.U1)] 
        internal static extern bool GetViewConfigurationIsPrimary(ViewConfigurationType viewConfigurationType);

        [DllImport(DllName, EntryPoint = "openxr_plugin_SetStereoSeparationAdjustment")]
        internal static extern void SetStereoSeparationAdjustment(float stereoSeparationAdjustment);

        [DllImport(DllName, EntryPoint = "openxr_plugin_GetStereoSeparationAdjustment")]
        internal static extern float GetStereoSeparationAdjustment();

        [DllImport(DllName, EntryPoint = "openxr_plugin_GetSupportedReprojectionModesCount")]
        internal static extern uint GetSupportedReprojectionModesCount(ViewConfigurationType viewConfigurationType);

        [DllImport(DllName, EntryPoint = "openxr_plugin_GetSupportedReprojectionModes")]
        internal static extern void GetSupportedReprojectionModes(ViewConfigurationType viewConfigurationType, ReprojectionMode[] reprojectionModes, uint reprojectionModesCapacity);

        [DllImport(DllName, EntryPoint = "openxr_plugin_SetReprojectionSettings")]
        internal static extern void SetReprojectionSettings(ViewConfigurationType viewConfigurationType, NativeReprojectionSettings nativeReprojectionSettings);

        [DllImport(DllName, EntryPoint = "openxr_plugin_GetPrimaryViewTrackingState")]
        internal static extern NativeSpaceLocationFlags GetPrimaryViewTrackingState();

        [DllImport(DllName, EntryPoint = "openxr_plugin_CreatePlaneProvider")]
        internal static extern void CreatePlaneProvider();

        [DllImport(DllName, EntryPoint = "openxr_plugin_StartPlaneSubsystem")]
        internal static extern void StartPlaneSubsystem();

        [DllImport(DllName, EntryPoint = "openxr_plugin_StopPlaneSubsystem")]
        internal static extern void StopPlaneSubsystem();

        [DllImport(DllName, EntryPoint = "openxr_plugin_DestroyPlaneSubsystem")]
        internal static extern void DestroyPlaneSubsystem();

        [DllImport(DllName, EntryPoint = "openxr_plugin_SetPlaneDetectionMode")]
        internal static extern void SetPlaneDetectionMode(PlaneDetectionMode planeDetectionMode);

        [DllImport(DllName, EntryPoint = "openxr_plugin_GetNumPlaneChanges")]
        internal static extern void GetNumPlaneChanges(FrameTime frameTime, ref uint numAddedPlanes, ref uint numUpdatedPlanes, ref uint numRemovedPlanes);

        [DllImport(DllName, EntryPoint = "openxr_plugin_GetPlaneChanges")]
        unsafe internal static extern void GetPlaneChanges(uint addedPlanesSize, void* addedPlanes, uint updatedPlanesSize, void* updatedPlanes, uint removedPlanesSize, void* removedPlanes);

        [DllImport(DllName, EntryPoint = "openxr_plugin_StartAnchorSubsystem")]
        internal static extern void StartAnchorSubsystem();

        [DllImport(DllName, EntryPoint = "openxr_plugin_StopAnchorSubsystem")]
        internal static extern void StopAnchorSubsystem();

        [DllImport(DllName, EntryPoint = "openxr_plugin_DestroyAnchorSubsystemPending")]
        internal static extern void DestroyAnchorSubsystemPending();

        [DllImport(DllName, EntryPoint = "openxr_plugin_DestroyAnchorSubsystem")]
        internal static extern void DestroyAnchorSubsystem();

        [DllImport(DllName, EntryPoint = "openxr_plugin_RemoveAllAnchors")]
        internal static extern void RemoveAllAnchors();

        [DllImport(DllName, EntryPoint = "openxr_plugin_TryAddAnchor")]
        [return: MarshalAs(UnmanagedType.U1)] 
        unsafe internal static extern bool TryAddAnchor(FrameTime frameTime, Quaternion rotation, Vector3 position, void* anchorPtr);

        [DllImport(DllName, EntryPoint = "openxr_plugin_TryRemoveAnchor")]
        [return: MarshalAs(UnmanagedType.U1)] 
        internal static extern bool TryRemoveAnchor(Guid anchorId);

        [DllImport(DllName, EntryPoint = "openxr_plugin_GetNumAnchorChanges")]
        internal static extern void GetNumAnchorChanges(FrameTime frameTime, ref uint numAddedAnchors, ref uint numUpdatedAnchors, ref uint numRemovedAnchors);

        [DllImport(DllName, EntryPoint = "openxr_plugin_GetAnchorChanges")]
        unsafe internal static extern void GetAnchorChanges(uint addedAnchorsSize, void* addedAnchors, uint updatedAnchorsSize, void* updatedAnchors, uint removedAnchorsSize, void* removedAnchors);

        [DllImport(DllName, EntryPoint = "openxr_plugin_LoadAnchorStore")]
        [return: MarshalAs(UnmanagedType.U1)] 
        internal static extern bool LoadAnchorStore();

        [DllImport(DllName, EntryPoint = "openxr_plugin_GetNumPersistedAnchorNames")]
        internal static extern uint GetNumPersistedAnchorNames();

        [DllImport(DllName, EntryPoint = "openxr_plugin_GetPersistedAnchorName")]
        internal static extern void GetPersistedAnchorName(uint idx, [MarshalAs(UnmanagedUTF8Type)] StringBuilder nameOut, uint capacity);

        [DllImport(DllName, EntryPoint = "openxr_plugin_LoadPersistedAnchor")]
        internal static extern Guid LoadPersistedAnchor([MarshalAs(UnmanagedUTF8Type)] string name);

        [DllImport(DllName, EntryPoint = "openxr_plugin_TryPersistAnchor")]
        [return: MarshalAs(UnmanagedType.U1)] 
        internal static extern bool TryPersistAnchor([MarshalAs(UnmanagedUTF8Type)] string name, Guid anchorId);

        [DllImport(DllName, EntryPoint = "openxr_plugin_UnpersistAnchor")]
        internal static extern void UnpersistAnchor([MarshalAs(UnmanagedUTF8Type)] string name);

        [DllImport(DllName, EntryPoint = "openxr_plugin_ClearPersistedAnchors")]
        internal static extern void ClearPersistedAnchors();

        [DllImport(DllName, EntryPoint = "openxr_plugin_GetHandJointsMotionRange")]
        internal static extern HandJointsMotionRange GetHandJointsMotionRange(Handedness handedness);

        [DllImport(DllName, EntryPoint = "openxr_plugin_SetHandJointsMotionRange")]
        internal static extern void SetHandJointsMotionRange(Handedness handedness, HandJointsMotionRange handTrackingOptions);

#pragma warning disable CS0618
        [DllImport(DllName, EntryPoint = "openxr_plugin_TryGetHandJointData")]
        [return: MarshalAs(UnmanagedType.U1)] 
        internal static extern bool TryGetHandJointData(Handedness handedness, FrameTime frameTime,
            [MarshalAs(UnmanagedType.LPArray, SizeConst = HandTracker.JointCount)] HandJointLocation[] handJoints);
#pragma warning restore CS0618

        [DllImport(DllName, EntryPoint = "openxr_plugin_TryLocateHandMesh")]
        [return: MarshalAs(UnmanagedType.U1)] 
        internal static extern bool TryLocateHandMesh(Handedness handedness, FrameTime frameTime, HandPoseType handPoseType, out Pose pose);

        [DllImport(DllName, EntryPoint = "openxr_plugin_TryGetHandMesh")]
        [return: MarshalAs(UnmanagedType.U1)] 
        internal static extern bool TryGetHandMesh(Handedness handedness, FrameTime frameTime, HandPoseType handPoseType,
            ref ulong vertexBufferKey, out uint vertexCount, Vector3[] vertexPositions, Vector3[] vertexNormals,
            ref uint indexBufferKey, out uint indexCount, int[] indices);

        [DllImport(DllName, EntryPoint = "openxr_plugin_TryGetHandMeshBufferSizes")]
        [return: MarshalAs(UnmanagedType.U1)] 
        internal static extern bool TryGetHandMeshBufferSizes(out uint maxVertexCount, out uint maxIndexCount);

        [DllImport(DllName, EntryPoint = "openxr_plugin_IsControllerModelSupported")]
        [return: MarshalAs(UnmanagedType.U1)] 
        internal static extern bool IsControllerModelSupported();

        [DllImport(DllName, EntryPoint = "openxr_plugin_TryGetControllerModelKey")]
        [return: MarshalAs(UnmanagedType.U1)] 
        internal static extern bool TryGetControllerModelKey(Handedness handedness, out ulong modelKey);

        [DllImport(DllName, EntryPoint = "openxr_plugin_TryGetControllerModel")]
        [return: MarshalAs(UnmanagedType.U1)] 
        internal static extern bool TryGetControllerModel(ulong modelKey, uint bufferCapacityInput, out uint bufferCountOutput, byte[] modelBuffer = null);

#pragma warning disable CS0618
        [DllImport(DllName, EntryPoint = "openxr_plugin_TryGetControllerModelProperties")]
        [return: MarshalAs(UnmanagedType.U1)] 
        internal static extern bool TryGetControllerModelProperties(ulong key, uint nodeCapacityInput, out uint nodeCountOutput, [Out] ControllerModel.ControllerModelNodeProperties[] properties = null);
#pragma warning restore CS0618

        [DllImport(DllName, EntryPoint = "openxr_plugin_TryGetControllerModelState")]
        [return: MarshalAs(UnmanagedType.U1)] 
        internal static extern bool TryGetControllerModelState(ulong key, uint nodeCapacityInput, out uint nodeCountOutput, Pose[] poses = null);

        [DllImport(DllName, EntryPoint = "openxr_plugin_TryEnableRemotingOverride")]
        [return: MarshalAs(UnmanagedType.U1)] 
        internal static extern bool TryEnableRemotingOverride();

        [DllImport(DllName, EntryPoint = "openxr_plugin_ResetRemotingOverride")]
        internal static extern void ResetRemotingOverride();

        [DllImport(DllName, EntryPoint = "openxr_plugin_ConnectRemoting")]
        internal static extern void ConnectRemoting(Remoting.InternalRemotingConnectConfiguration configuration, [MarshalAs(UnmanagedType.U1)] bool secureConnect,
            [MarshalAs(UnmanagedUTF8Type)] string authenticationToken, [MarshalAs(UnmanagedType.U1)] bool performSystemValidation,
            [MarshalAs(UnmanagedType.FunctionPtr)] Remoting.InternalValidateServerCertificateDelegate validateServerCertificateCallback);

        [DllImport(DllName, EntryPoint = "openxr_plugin_GetNumCertificates")]
        internal static extern uint GetNumCertificates();

        [DllImport(DllName, EntryPoint = "openxr_plugin_GetCertificate")]
        internal static extern IntPtr GetCertificate(uint certIndex, out int size);

        [DllImport(DllName, EntryPoint = "openxr_plugin_ListenRemoting")]
        unsafe internal static extern void ListenRemoting(
            Remoting.InternalRemotingListenConfiguration listenConfiguration,
            [MarshalAs(UnmanagedType.U1)] bool secureListen,
            void* certificate,
            uint certificateByteCount,
            [MarshalAs(UnmanagedUTF8Type)] string subjectName,
            [MarshalAs(UnmanagedUTF8Type)] string keyPassPhrase,
            [MarshalAs(UnmanagedType.FunctionPtr)] Remoting.SecureRemotingValidateAuthenticationTokenDelegate validateAuthenticationTokenCallback);

        [DllImport(DllName, EntryPoint = "openxr_plugin_DisconnectRemoting")]
        internal static extern void DisconnectRemoting();

        [DllImport(DllName, EntryPoint = "openxr_plugin_TryGetRemotingConnectionState")]
        [return: MarshalAs(UnmanagedType.U1)] 
        internal static extern bool TryGetRemotingConnectionState(out Remoting.ConnectionState connectionState, out Remoting.DisconnectReason disconnectReason);

        [DllImport(DllName, EntryPoint = "openxr_plugin_SetRemoteSpeechCulture")]
        [return: MarshalAs(UnmanagedType.U1)] 
        internal static extern bool SetRemoteSpeechCulture([MarshalAs(UnmanagedUTF8Type)] string cultureName);

        [DllImport(DllName, EntryPoint = "openxr_plugin_TryLocateUserReferenceSpace")]
        [return: MarshalAs(UnmanagedType.U1)] 
        internal static extern bool TryLocateUserReferenceSpace(FrameTime frameTime, out Pose pose);

        [DllImport(DllName, EntryPoint = "openxr_plugin_TryConvertToRemoteTime")]
        [return: MarshalAs(UnmanagedType.U1)] 
        internal static extern bool TryConvertToRemoteTime(long playerPerformanceCount, out long remotePerformanceCount);

        [DllImport(DllName, EntryPoint = "openxr_plugin_TryConvertToPlayerTime")]
        [return: MarshalAs(UnmanagedType.U1)] 
        internal static extern bool TryConvertToPlayerTime(long remotePerformanceCount, out long playerPerformanceCount);

        [DllImport(DllName, EntryPoint = "openxr_plugin_TryCreateSpaceFromStaticNodeId")]
        [return: MarshalAs(UnmanagedType.U1)] 
        internal static extern bool TryCreateSpaceFromStaticNodeId(Guid id, out ulong spaceId);

        [DllImport(DllName, EntryPoint = "openxr_plugin_TryCreateSpaceFromDynamicNodeId")]
        [return: MarshalAs(UnmanagedType.U1)] 
        internal static extern bool TryCreateSpaceFromDynamicNodeId(Guid id, out ulong spaceId);

        [DllImport(DllName, EntryPoint = "openxr_plugin_TryLocateSpatialGraphNodeSpace")]
        [return: MarshalAs(UnmanagedType.U1)] 
        internal static extern bool TryLocateSpatialGraphNodeSpace(ulong spaceId, FrameTime frameTime, out Pose pose);

        [DllImport(DllName, EntryPoint = "openxr_plugin_TryLocateSpatialGraphNodeSpaceWithQpcTime")]
        [return: MarshalAs(UnmanagedType.U1)] 
        internal static extern bool TryLocateSpatialGraphNodeSpace(ulong spaceId, long qpcTime, out Pose pose);

        [DllImport(DllName, EntryPoint = "openxr_plugin_TryLocateViewSpace")]
        [return: MarshalAs(UnmanagedType.U1)] 
        internal static extern bool TryLocateViewSpace(FrameTime frameTime, out Pose pose, out long time);

        [DllImport(DllName, EntryPoint = "openxr_plugin_TryAcquireSceneCoordinateSystem")]
        internal static extern IntPtr TryAcquireSceneCoordinateSystem(Pose poseInScene);

        [DllImport(DllName, EntryPoint = "openxr_plugin_TryAcquirePerceptionSpatialAnchorByHandle")]
        internal static extern IntPtr TryAcquirePerceptionSpatialAnchor(ulong anchorHandle);

        [DllImport(DllName, EntryPoint = "openxr_plugin_TryAcquirePerceptionSpatialAnchorById")]
        internal static extern IntPtr TryAcquirePerceptionSpatialAnchor(Guid trackableId);

        [DllImport(DllName, EntryPoint = "openxr_plugin_TryCreateARAnchorFromOpenXRHandle")]
        internal static extern Guid TryCreateARAnchorFromOpenXRHandle(ulong openxrAnchor);

        [DllImport(DllName, EntryPoint = "openxr_plugin_TryCreateARAnchorFromPerceptionAnchor")]
        internal static extern Guid TryCreateARAnchorFromPerceptionAnchor([MarshalAs(UnmanagedType.IUnknown)] object perceptionAnchor);

        [DllImport(DllName, EntryPoint = "openxr_plugin_TryAcquireAndReplaceXrSpatialAnchor")]
        internal static extern Guid TryAcquireAndReplaceXrSpatialAnchor([MarshalAs(UnmanagedType.IUnknown)] object perceptionAnchor, Guid id);

        [DllImport(DllName, EntryPoint = "openxr_plugin_TryGetPerceptionDeviceFactory")]
        internal static extern IntPtr TryGetPerceptionDeviceFactory(IntPtr pfnGetInstanceProcAddr);

        [DllImport(DllName, EntryPoint = "openxr_plugin_SetMeshComputeSettings")]
        [return: MarshalAs(UnmanagedType.U1)] 
        internal static extern bool SetMeshComputeSettings(MeshComputeSettings settings);

        [DllImport(DllName, EntryPoint = "openxr_plugin_TryCreateGestureRecognizer")]
        internal static extern ulong TryCreateGestureRecognizer(GestureSettings settings);

        [DllImport(DllName, EntryPoint = "openxr_plugin_DestroyGestureRecognizer")]
        internal static extern void DestroyGestureRecognizer(ulong gestureRecognizer);

        [DllImport(DllName, EntryPoint = "openxr_plugin_TrySetGestureSettings")]
        [return: MarshalAs(UnmanagedType.U1)] 
        internal static extern bool TrySetGestureSettings(ulong gestureRecognizer, GestureSettings settings);

        [DllImport(DllName, EntryPoint = "openxr_plugin_CancelPendingGesture")]
        internal static extern void CancelPendingGesture(ulong gestureRecognizer);

        [DllImport(DllName, EntryPoint = "openxr_plugin_TryGetNextEventData")]
        [return: MarshalAs(UnmanagedType.U1)] 
        internal static extern bool TryGetNextEventData(ulong gestureRecognizer, ref GestureEventData eventData);

        [DllImport(DllName, EntryPoint = "openxr_plugin_StartGestureRecognizer")]
        internal static extern void StartGestureRecognizer(ulong gestureRecognizer);

        [DllImport(DllName, EntryPoint = "openxr_plugin_StopGestureRecognizer")]
        internal static extern void StopGestureRecognizer(ulong gestureRecognizer);

        [DllImport(DllName, EntryPoint = "openxr_plugin_StartMarkerSubsystem")]
        internal static extern void StartMarkerSubsystem();

        [DllImport(DllName, EntryPoint = "openxr_plugin_StopMarkerSubsystem")]
        internal static extern void StopMarkerSubsystem();

        [DllImport(DllName, EntryPoint = "openxr_plugin_DestroyMarkerSubsystem")]
        internal static extern void DestroyMarkerSubsystem();

        [DllImport(DllName, EntryPoint = "openxr_plugin_SetEnabledMarkerTypes")]
        internal static extern void SetEnabledMarkerTypes(XrSceneMarkerTypeMSFT[] enabledMarkerTypes, int numMarkerTypes);

        [DllImport(DllName, EntryPoint = "openxr_plugin_GetNumMarkerChanges")]
        internal static extern void GetNumMarkerChanges(FrameTime frameTime, ref uint numAddedMarkers, ref uint numUpdatedMarkers, ref uint numRemovedMarkers);

        [DllImport(DllName, EntryPoint = "openxr_plugin_GetMarkerChanges")]
        unsafe internal static extern void GetMarkerChanges(uint addedMarkersSize, void* addedMarkers, uint updatedMarkersSize, void* updatedMarkers, uint removedMarkersSize, void* removedMarkers);

        [DllImport(DllName, EntryPoint = "openxr_plugin_GetMarkerRawDataSize")]
        internal static extern uint GetMarkerRawDataSize(Guid markerId);

        [DllImport(DllName, EntryPoint = "openxr_plugin_GetMarkerRawData")]
        unsafe internal static extern void GetMarkerRawData(Guid markerId, void* rawDataOut, uint capacity);

        [DllImport(DllName, EntryPoint = "openxr_plugin_GetMarkerDecodedStringLength")]
        internal static extern uint GetMarkerDecodedStringLength(Guid markerId);

        [DllImport(DllName, EntryPoint = "openxr_plugin_GetMarkerDecodedString")]
        internal static extern void GetMarkerDecodedString(Guid markerId, [MarshalAs(UnmanagedUTF8Type)] StringBuilder decodedStringOut, uint capacity);

        [DllImport(DllName, EntryPoint = "openxr_plugin_GetMarkerQRCodeProperties")]
        unsafe internal static extern void GetMarkerQRCodeProperties(Guid markerId, NativeQRCodeProperties* qrCodePropertiesOut, uint capacity);

        [DllImport(DllName, EntryPoint = "openxr_plugin_GetCurrentQpcTimeAsXrTime")]
        unsafe internal static extern long GetCurrentQpcTimeAsXrTime();

        [DllImport(DllName, EntryPoint = "openxr_plugin_StartMapTrackingSubsystem")]
        internal static extern void StartMapTrackingSubsystem();

        [DllImport(DllName, EntryPoint = "openxr_plugin_StopMapTrackingSubsystem")]
        internal static extern void StopMapTrackingSubsystem();

        [DllImport(DllName, EntryPoint = "openxr_plugin_DestroyMapTrackingSubsystem")]
        internal static extern void DestroyMapTrackingSubsystem();

        [DllImport(DllName, EntryPoint = "openxr_plugin_MapTrackingManagerSupportsApplicationExclusiveMaps")]
        internal static extern bool MapTrackingManagerSupportsApplicationExclusiveMaps();

        [DllImport(DllName, EntryPoint = "openxr_plugin_MapTrackingManagerGetActiveTrackingMapType")]
        internal static extern int MapTrackingManagerGetActiveTrackingMapType();

        [DllImport(DllName, EntryPoint = "openxr_plugin_MapTrackingManagerActivateExclusiveMap")]
        internal static extern bool MapTrackingManagerActivateExclusiveMap(ref Guid mapId);

        [DllImport(DllName, EntryPoint = "openxr_plugin_MapTrackingManagerActivateSharedMap")]
        internal static extern bool MapTrackingManagerActivateSharedMap();
    }
}
