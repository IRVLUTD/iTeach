// Copyright (c) Microsoft Corporation.
// Licensed under the MIT License.

using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using Unity.Collections;
using Unity.Collections.LowLevel.Unsafe;
using UnityEngine;
using UnityEngine.XR.OpenXR;
using UnityEngine.XR.ARSubsystems;

namespace Microsoft.MixedReality.OpenXR.ARSubsystems
{
    // Mapped to native XrSceneMarkerTypeMSFT
    internal enum XrSceneMarkerTypeMSFT
    {
        XR_SCENE_MARKER_TYPE_QR_CODE_MSFT = 1
    }

    // Mapped to native XrSceneMarkerQRCodeSymbolTypeMSFT
    internal enum XrSceneMarkerQRCodeSymbolTypeMSFT
    {
        XR_SCENE_MARKER_QR_CODE_SYMBOL_TYPE_QR_CODE_MSFT = 1,
        XR_SCENE_MARKER_QR_CODE_SYMBOL_TYPE_MICRO_QR_CODE_MSFT = 2
    }

    [StructLayout(LayoutKind.Sequential, Pack = 8)]
    internal struct NativeMarker
    {
        public Guid id;
        public Vector3 position;
        public Quaternion rotation;
        public TrackingState trackingState;
        public Vector2 center;
        public Vector2 size;
        public Int64 lastSeenTime;
        public XrSceneMarkerTypeMSFT type;
    }

    [StructLayout(LayoutKind.Sequential, Pack = 8)]
    internal struct NativeQRCodeProperties
    {
        public XrSceneMarkerQRCodeSymbolTypeMSFT type;
        public uint version;
    }

    internal struct TimeOffsetInfo
    {
        public float lastOffsetCalculationTime;
        public float offset;
    }

    internal class MarkerSubsystem : XRMarkerSubsystem
    {
        public const string Id = "OpenXR marker tracking";

        private class OpenXRProvider : Provider
        {
            private ARMarkerType[] m_enabledMarkerTypes = { ARMarkerType.QRCode };

            private TransformMode m_defaultTransformMode = TransformMode.MostStable;

            private Dictionary<TrackableId, XRMarker> m_Markers = new Dictionary<TrackableId, XRMarker>();

            private Dictionary<TrackableId, TransformMode> m_PendingTransforms = new Dictionary<TrackableId, TransformMode>();

            private TimeOffsetInfo m_TimeOffsetInfo = new TimeOffsetInfo();

            public OpenXRProvider()
            {
            }

            public override void Destroy()
            {
                NativeLib.DestroyMarkerSubsystem();
            }

            internal override ARMarkerType[] EnabledMarkerTypes
            {
                get => m_enabledMarkerTypes;
                set
                {
                    m_enabledMarkerTypes = value;
                    NativeLib.SetEnabledMarkerTypes(ToXrSceneMarkerTypeMSFT(m_enabledMarkerTypes), m_enabledMarkerTypes.Length);
                }
            }

            internal override TransformMode DefaultTransformMode
            {
                get => m_defaultTransformMode;
                set => m_defaultTransformMode = value;
            }

            public unsafe override TrackableChanges<XRMarker> GetChanges(XRMarker defaultMarker, Allocator allocator)
            {
                float realTimeSinceStartup = Time.realtimeSinceStartup;

                // Fetching current QPC time if over a second has passed since it was fetched last
                if (realTimeSinceStartup - m_TimeOffsetInfo.lastOffsetCalculationTime > 1)
                {
                    m_TimeOffsetInfo.lastOffsetCalculationTime = realTimeSinceStartup;
                    long xrTime = NativeLib.GetCurrentQpcTimeAsXrTime();
                    m_TimeOffsetInfo.offset = realTimeSinceStartup - (xrTime / (float)1e9);
                }

                uint numAddedMarkers = 0;
                uint numUpdatedMarkers = 0;
                uint numRemovedMarkers = 0;
                NativeLib.GetNumMarkerChanges(FrameTime.OnUpdate, ref numAddedMarkers, ref numUpdatedMarkers, ref numRemovedMarkers);

                using (var addedNativeMarkers = new NativeArray<NativeMarker>((int)numAddedMarkers, allocator, NativeArrayOptions.UninitializedMemory))
                using (var updatedNativeMarkers = new NativeArray<NativeMarker>((int)numUpdatedMarkers, allocator, NativeArrayOptions.UninitializedMemory))
                using (var removedNativeMarkers = new NativeArray<Guid>((int)numRemovedMarkers, allocator, NativeArrayOptions.UninitializedMemory))
                {
                    if (numAddedMarkers + numUpdatedMarkers + numRemovedMarkers > 0)
                    {
                        NativeLib.GetMarkerChanges(
                            (uint)(numAddedMarkers * sizeof(NativeMarker)),
                            NativeArrayUnsafeUtility.GetUnsafePtr(addedNativeMarkers),
                            (uint)(numUpdatedMarkers * sizeof(NativeMarker)),
                            NativeArrayUnsafeUtility.GetUnsafePtr(updatedNativeMarkers),
                            (uint)(numRemovedMarkers * sizeof(Guid)),
                            NativeArrayUnsafeUtility.GetUnsafePtr(removedNativeMarkers));
                    }

                    var addedMarkers = HandleAddedMarkers(addedNativeMarkers);
                    var updatedMarkers = HandleUpdatedMarkers(updatedNativeMarkers);
                    var removedMarkers = HandleRemovedMarkers(removedNativeMarkers);

                    // Handling transforms for markers that weren't added, updated or removed
                    if (m_PendingTransforms.Count > 0)
                    {
                        foreach (var trackableId in m_PendingTransforms.Keys.ToList())
                        {
                            XRMarker xrMarker = m_Markers[trackableId];
                            xrMarker.transformMode = m_PendingTransforms[trackableId];
                            xrMarker = ApplyTransform(xrMarker);

                            // Adding the marker to the updated list
                            updatedMarkers.Add(xrMarker);
                            m_Markers[trackableId] = xrMarker;
                        }
                        m_PendingTransforms.Clear();
                    }

                    // Handling tracking state for markers that were updated by the runtime but their last seen time is too old.
                    // These markers are already part of updatedMarkers list and so we need to go through them and change the
                    // tracking state in the list.
                    HashSet<TrackableId> handledMarkers = new HashSet<TrackableId>();
                    for (int i = 0; i < updatedMarkers.Count; ++i)
                    {
                        handledMarkers.Add(updatedMarkers[i].trackableId);
                        if (IsLastSeenTimeTooOld(updatedMarkers[i]))
                        {
                            XRMarker xrMarker = updatedMarkers[i];
                            xrMarker.trackingState = TrackingState.Limited;
                            updatedMarkers[i] = xrMarker;
                            m_Markers[updatedMarkers[i].trackableId] = xrMarker;
                        }
                    }

                    // Handling tracking state for markers that were not updated by the runtime and their last seen time is too old.
                    // We ensure that the markers already part of the updatedMarkers list are not considered again.
                    foreach (var trackableId in m_Markers.Keys.ToList())
                    {
                        if (!handledMarkers.Contains(trackableId))
                        {
                            XRMarker xrMarker = m_Markers[trackableId];
                            if (IsLastSeenTimeTooOld(xrMarker))
                            {
                                xrMarker.trackingState = TrackingState.Limited;
                                updatedMarkers.Add(xrMarker);
                                m_Markers[trackableId] = xrMarker;
                            }
                        }
                    }

                    return TrackableChanges<XRMarker>.CopyFrom(
                        new NativeArray<XRMarker>(addedMarkers.ToArray(), allocator),
                        new NativeArray<XRMarker>(updatedMarkers.ToArray(), allocator),
                        new NativeArray<TrackableId>(removedMarkers, allocator),
                        allocator);
                }
            }

            public override void SetTransformMode(TrackableId trackableId, TransformMode transformMode)
            {
                if (m_Markers.ContainsKey(trackableId) && m_Markers[trackableId].transformMode != transformMode)
                {
                    // Adding transform as pending
                    m_PendingTransforms.Add(trackableId, transformMode);
                }
            }

            public unsafe override NativeArray<byte> GetRawData(TrackableId trackableId, Allocator allocator)
            {
                if (m_Markers.ContainsKey(trackableId))
                {
                    Guid guid = FeatureUtils.ToGuid(trackableId);
                    int rawDataSize = (int)NativeLib.GetMarkerRawDataSize(guid);
                    if (rawDataSize > 0)
                    {
                        NativeArray<byte> rawData = new NativeArray<byte>(rawDataSize, allocator, NativeArrayOptions.UninitializedMemory);
                        NativeLib.GetMarkerRawData(guid, NativeArrayUnsafeUtility.GetUnsafePtr(rawData), (uint)rawDataSize);
                        return rawData;
                    }
                }
                return new NativeArray<byte>(0, allocator, NativeArrayOptions.UninitializedMemory);
            }

            public override string GetDecodedString(TrackableId trackableId)
            {
                if (m_Markers.ContainsKey(trackableId))
                {
                    Guid guid = FeatureUtils.ToGuid(trackableId);
                    int decodedStringLength = (int)NativeLib.GetMarkerDecodedStringLength(guid);
                    if (decodedStringLength > 0)
                    {
                        StringBuilder stringBuilder = new StringBuilder(decodedStringLength);
                        NativeLib.GetMarkerDecodedString(guid, stringBuilder, (uint)stringBuilder.Capacity);
                        return stringBuilder.ToString();
                    }
                }
                return null;
            }

            public override unsafe QRCodeProperties GetQRCodeProperties(TrackableId trackableId)
            {
                Guid guid = FeatureUtils.ToGuid(trackableId);
                NativeQRCodeProperties nativeQRCodeProperties = new NativeQRCodeProperties();
                QRCodeProperties qrCodeProperties = new QRCodeProperties();
                NativeLib.GetMarkerQRCodeProperties(guid, &nativeQRCodeProperties, (uint)sizeof(NativeQRCodeProperties));
                qrCodeProperties.version = nativeQRCodeProperties.version;
                qrCodeProperties.type = (QRCodeType)nativeQRCodeProperties.type;
                return qrCodeProperties;
            }

            public override void Start()
            {
                NativeLib.StartMarkerSubsystem();
            }

            public override void Stop()
            {
                NativeLib.StopMarkerSubsystem();
            }

            private List<XRMarker> HandleAddedMarkers(NativeArray<NativeMarker> addedNativeMarkers)
            {
                var addedMarkers = new List<XRMarker>();
                for (int i = 0; i < addedNativeMarkers.Length; ++i)
                {
                    XRMarker xrMarker = ToXRMarker(addedNativeMarkers[i]);
                    if (xrMarker.transformMode == TransformMode.Center)
                    {
                        // If the default transform mode is center, we apply the transform here
                        xrMarker = ApplyCenterTransform(xrMarker);
                    }
                    m_Markers.Add(xrMarker.trackableId, xrMarker);
                    addedMarkers.Add(xrMarker);
                }
                return addedMarkers;
            }

            private List<XRMarker> HandleUpdatedMarkers(NativeArray<NativeMarker> updatedNativeMarkers)
            {
                var updatedMarkers = new List<XRMarker>();
                for (int i = 0; i < updatedNativeMarkers.Length; ++i)
                {
                    TrackableId updatedId = FeatureUtils.ToTrackableId(updatedNativeMarkers[i].id);
                    if (m_Markers.ContainsKey(updatedId))
                    {
                        XRMarker xrMarker = m_Markers[updatedId];

                        Pose xrMarkerPose = xrMarker.pose;
                        xrMarkerPose.position = updatedNativeMarkers[i].position;
                        xrMarkerPose.rotation = updatedNativeMarkers[i].rotation;
                        xrMarker.pose = xrMarkerPose;

                        xrMarker.center = updatedNativeMarkers[i].center;
                        xrMarker.size = updatedNativeMarkers[i].size;
                        xrMarker.lastSeenTime = GetLastSeenTimeAsRealTimeSinceStartup(updatedNativeMarkers[i].lastSeenTime);
                        xrMarker.trackingState = updatedNativeMarkers[i].trackingState;

                        if (m_PendingTransforms.ContainsKey(updatedId))
                        {
                            // Change transform mode if there is a pending transform
                            xrMarker.transformMode = m_PendingTransforms[updatedId];
                            m_PendingTransforms.Remove(updatedId);
                        }
                        if (xrMarker.transformMode == TransformMode.Center)
                        {
                            // If the marker is supposed to be centered, we apply the transform here
                            xrMarker = ApplyCenterTransform(xrMarker);
                        }

                        m_Markers[updatedId] = xrMarker;
                        updatedMarkers.Add(m_Markers[updatedId]);
                    }
                }
                return updatedMarkers;
            }

            private TrackableId[] HandleRemovedMarkers(NativeArray<Guid> removedNativeMarkers)
            {
                var removedMarkers = new TrackableId[removedNativeMarkers.Length];
                for (int i = 0; i < removedNativeMarkers.Length; ++i)
                {
                    TrackableId removedId = FeatureUtils.ToTrackableId(removedNativeMarkers[i]);
                    if (m_Markers.ContainsKey(removedId))
                    {
                        m_Markers.Remove(removedId);
                    }
                    if (m_PendingTransforms.ContainsKey(removedId))
                    {
                        m_PendingTransforms.Remove(removedId);
                    }
                    removedMarkers[i] = removedId;
                }
                return removedMarkers;
            }

            private XRMarker ApplyTransform(XRMarker xrMarker)
            {
                if (xrMarker.transformMode == TransformMode.Center)
                {
                    return ApplyCenterTransform(xrMarker);
                }

                return ApplyStableTransform(xrMarker);
            }

            private XRMarker ApplyCenterTransform(XRMarker xrMarker)
            {
                if (xrMarker.transformMode == TransformMode.Center)
                {
                    Pose newPose = xrMarker.pose;
                    newPose.position += xrMarker.center.x * newPose.right + xrMarker.center.y * newPose.up;
                    xrMarker.pose = newPose;
                }
                return xrMarker;
            }

            private XRMarker ApplyStableTransform(XRMarker xrMarker)
            {
                if (xrMarker.transformMode == TransformMode.MostStable)
                {
                    Pose newPose = xrMarker.pose;
                    newPose.position -= xrMarker.center.x * newPose.right + xrMarker.center.y * newPose.up;
                    xrMarker.pose = newPose;
                }
                return xrMarker;
            }

            private XRMarker ToXRMarker(NativeMarker nativeMarker)
            {
                return new XRMarker(
                    FeatureUtils.ToTrackableId(nativeMarker.id),
                    new Pose(nativeMarker.position, nativeMarker.rotation),
                    nativeMarker.trackingState,
                    nativeMarker.center,
                    nativeMarker.size,
                    GetLastSeenTimeAsRealTimeSinceStartup(nativeMarker.lastSeenTime),
                    m_defaultTransformMode,
                    (ARMarkerType)nativeMarker.type,
                    IntPtr.Zero);
            }

            private XrSceneMarkerTypeMSFT[] ToXrSceneMarkerTypeMSFT(ARMarkerType[] markerTypes)
            {
                var xrSceneMarkerTypeMSFTs = new XrSceneMarkerTypeMSFT[markerTypes.Length];
                for (int i = 0; i < markerTypes.Length; ++i)
                {
                    xrSceneMarkerTypeMSFTs[i] = (XrSceneMarkerTypeMSFT)markerTypes[i];
                }
                return xrSceneMarkerTypeMSFTs;
            }

            private float GetLastSeenTimeAsRealTimeSinceStartup(long lastSeenTime)
            {
                return lastSeenTime / (float)1e9 + m_TimeOffsetInfo.offset;
            }

            // We consider a marker to be too old if it hasn't been seen for more than 2 seconds.
            // We choose the threshold based on a 99th percentile calculation of last seen times.
            private bool IsLastSeenTimeTooOld(XRMarker xrMarker)
            {
                return (Time.realtimeSinceStartup - xrMarker.lastSeenTime) > 2 && xrMarker.trackingState == TrackingState.Tracking;
            }
        }

        [RuntimeInitializeOnLoadMethod(RuntimeInitializeLoadType.SubsystemRegistration)]
        static void RegisterDescriptor()
        {
            XRMarkerSubsystemDescriptor.Create(new XRMarkerSubsystemDescriptor.Cinfo
            {
                id = Id,
                providerType = typeof(MarkerSubsystem.OpenXRProvider),
                subsystemTypeOverride = typeof(MarkerSubsystem),
            });
        }
    };

    internal class MarkerSubsystemController : SubsystemController
    {
        private static List<XRMarkerSubsystemDescriptor> s_MarkerDescriptors = new List<XRMarkerSubsystemDescriptor>();

        public MarkerSubsystemController(IOpenXRContext context) : base(context)
        {
        }

        public override void OnSubsystemCreate(ISubsystemPlugin plugin)
        {
            if (OpenXRRuntime.IsExtensionEnabled("XR_MSFT_scene_marker"))
            {
                plugin.CreateSubsystem<XRMarkerSubsystemDescriptor, XRMarkerSubsystem>(s_MarkerDescriptors, MarkerSubsystem.Id);
            }
        }

        public override void OnSubsystemDestroy(ISubsystemPlugin plugin)
        {
            plugin.DestroySubsystem<XRMarkerSubsystem>();
        }
    }
}