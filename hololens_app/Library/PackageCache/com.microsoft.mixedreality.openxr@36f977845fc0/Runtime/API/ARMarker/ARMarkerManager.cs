// Copyright (c) Microsoft Corporation.
// Licensed under the MIT License.

using Microsoft.MixedReality.OpenXR.ARSubsystems;
using System;
using System.Collections.Generic;
using System.Linq;
using Unity.Collections;
using Unity.XR.CoreUtils;
using UnityEngine;
using UnityEngine.XR.ARFoundation;
using UnityEngine.XR.ARSubsystems;

namespace Microsoft.MixedReality.OpenXR
{
    /// <summary>
    /// A manager for <see cref="ARMarker"/>s. Creates, updates, and removes
    /// <c>GameObject</c>s in response to detected surfaces in the physical
    /// environment.
    /// </summary>
    [DefaultExecutionOrder(ARUpdateOrder.k_PlaneManager)]
    [DisallowMultipleComponent]
#if USE_ARFOUNDATION_5_OR_NEWER
    [RequireComponent(typeof(XROrigin))]
#else
    [RequireComponent(typeof(ARSessionOrigin))]
#endif
    public sealed class ARMarkerManager : ARTrackableManager<
        XRMarkerSubsystem,
        XRMarkerSubsystemDescriptor,
        XRMarkerSubsystem.Provider,
        XRMarker,
        ARMarker>
    {
        private static ARMarkerManager m_instance = null;

        /// <summary>
        /// Singleton instance for ARMarkerManager
        /// </summary>
        public static ARMarkerManager Instance => m_instance;

        /// <summary>
        /// Getter or setter for the Marker Prefab.
        /// </summary>
        [Tooltip("If not null, instantiates this prefab for each created marker. Else, a default empty GameObject is created with the new ARMarker attached.")]
        public GameObject markerPrefab;

        /// <summary>
        /// The list of <see cref="ARMarkerType"/>s that will be detected.
        /// </summary>
        [Tooltip("The list of ARMarker types that will be detected.")]
        public ARMarkerType[] enabledMarkerTypes = { ARMarkerType.QRCode };

        /// <summary>
        /// Default <see cref="TransformMode"/> for newly detected markers.
        /// </summary>
        [Tooltip("Default transform mode for newly detected markers.")]
        public TransformMode defaultTransformMode = TransformMode.MostStable;

        /// <summary>
        /// Invoked when markers have changed (been added, updated, or removed).
        /// </summary>
        public event Action<ARMarkersChangedEventArgs> markersChanged;

        /// <summary>
        /// Attempt to retrieve an existing <see cref="ARMarker"/> by <paramref name="trackableId"/>.
        /// </summary>
        /// <param name="trackableId">The <see cref="TrackableId"/> of the marker to retrieve.</param>
        /// <returns>The <see cref="ARMarker"/> with <paramref name="trackableId"/>, or <c>null</c> if it does not exist.</returns>
        public ARMarker GetMarker(TrackableId trackableId) => m_Trackables.TryGetValue(trackableId, out ARMarker marker) ? marker : null;

        /// <summary>
        /// Set transform mode of an existing <see cref="ARMarker"/>.
        /// </summary>
        /// <param name="trackableId">The <see cref="TrackableId"/> of the marker to be transformed.</param>
        /// <param name="transformMode">The <see cref="TransformMode"/> to be applied.</param>
        public void SetTransformMode(TrackableId trackableId, TransformMode transformMode)
        {
            if (enabled && subsystem != null)
            {
                subsystem.SetTransformMode(trackableId, transformMode);
            }
        }

        /// <summary>
        /// Get raw data for an existing <see cref="ARMarker"/>.
        /// </summary>
        /// <param name="trackableId">The <see cref="TrackableId"/> of the marker.</param>
        public NativeArray<byte> GetRawData(TrackableId trackableId, Allocator allocator)
        {
            if (enabled && subsystem != null)
            {
                return subsystem.GetRawData(trackableId, allocator);
            }
            return new NativeArray<byte>();
        }

        /// <summary>
        /// Get decoded string for an existing <see cref="ARMarker"/>.
        /// </summary>
        /// <param name="trackableId">The <see cref="TrackableId"/> of the marker.</param>
        public string GetDecodedString(TrackableId trackableId)
        {
            if (enabled && subsystem != null)
            {
                return subsystem.GetDecodedString(trackableId);
            }
            return null;
        }

        /// <summary>
        /// Get QR code properties for an existing <see cref="XRMarker"/> of type <see cref="ARMarkerType.QRCode"/>.
        /// </summary>
        /// <param name="trackableId">The <see cref="TrackableId"/> of the QRCode marker.</param>
        public QRCodeProperties GetQRCodeProperties(TrackableId trackableId)
        {
            if (enabled && subsystem != null)
            {
                return subsystem.GetQRCodeProperties(trackableId);
            }
            return new QRCodeProperties();
        }

        /// <summary>
        /// Get the Prefab which will be instantiated for each <see cref="ARMarker"/>. Can be `null`.
        /// </summary>
        /// <returns>The Prefab which will be instantiated for each <see cref="ARMarker"/>.</returns>
        protected override GameObject GetPrefab() => markerPrefab;

        /// <summary>
        /// Invoked when the base class detects trackable changes.
        /// </summary>
        /// <param name="added">The list of added <see cref="ARMarker"/>s.</param>
        /// <param name="updated">The list of updated <see cref="ARMarker"/>s.</param>
        /// <param name="removed">The list of removed <see cref="ARMarker"/>s.</param>
        protected override void OnTrackablesChanged(
            List<ARMarker> added,
            List<ARMarker> updated,
            List<ARMarker> removed)
        {
            if (markersChanged != null)
            {
                using (new ScopedProfiler("OnMarkersChanged"))
                    markersChanged(
                        new ARMarkersChangedEventArgs(
                            added,
                            updated,
                            removed));
            }
        }

        protected override void Update()
        {
            base.Update();
            if (enabled && subsystem != null)
            {
                Array.Sort(enabledMarkerTypes);
                if (!enabledMarkerTypes.SequenceEqual(subsystem.EnabledMarkerTypes))
                {
                    subsystem.EnabledMarkerTypes = enabledMarkerTypes;
                }

                if (defaultTransformMode != subsystem.DefaultTransformMode)
                {
                    subsystem.DefaultTransformMode = defaultTransformMode;
                }
            }
        }

        protected override void OnEnable()
        {
            base.OnEnable();

            // Replicating behavior in ARFoundation to initialize singleton instance
            m_instance = this;
        }

        /// <summary>
        /// The name to be used for the <c>GameObject</c> whenever a new marker object is created from <see cref="markerPrefab"/>.
        /// </summary>
        protected override string gameObjectName => "ARMarker";
    }
}
