// Copyright (c) Microsoft Corporation.
// Licensed under the MIT License.

using System;
using System.Runtime.InteropServices;
using UnityEngine;
using UnityEngine.XR.ARSubsystems;
using Pose = UnityEngine.Pose;

namespace Microsoft.MixedReality.OpenXR.ARSubsystems
{
    /// <summary>
    /// The session-relative data associated with a marker.
    /// Following design pattern set by <see cref="UnityEngine.XR.ARSubsystems.BoundedPlane"/>
    /// </summary>
    /// <seealso cref="XRMarkerSubsystem"/>
    [StructLayout(LayoutKind.Sequential)]
    public struct XRMarker : ITrackable
    {
        private static readonly XRMarker s_Default = new XRMarker(
                TrackableId.invalidId,
                Pose.identity,
                TrackingState.None,
                Vector2.zero,
                Vector2.zero,
                0.0f,
                TransformMode.MostStable,
                ARMarkerType.QRCode,
                IntPtr.Zero);

        /// <summary>
        /// Gets a default-initialized <see cref="XRMarker"/>. This can be
        /// different from the zero-initialized version, e.g., the <see cref="pose"/>
        /// is <c>Pose.identity</c> instead of zero-initialized.
        /// </summary>
        internal static XRMarker defaultValue => s_Default;

        /// <summary>
        /// Constructs a new <see cref="XRMarker"/>. This is just a data container
        /// for a marker's session relative data. These are typically created by
        /// <see cref="XRMarkerSubsystem.GetChanges(Unity.Collections.Allocator)"/>.
        /// </summary>
        /// <param name="trackableId">The <see cref="TrackableId"/> associated with the marker.</param>
        /// <param name="pose">The <c>Pose</c> associated with the marker.</param>
        /// <param name="trackingState">The <see cref="TrackingState"/> associated with the marker.</param>
        /// <param name="center">The center of the marker, in marker space (relative to <paramref name="pose"/>).</param>
        /// <param name="size">The dimensions associated with the marker.</param>
        /// <param name="lastSeenTime">The time when the marker was last seen.</param>
        /// <param name="markerType">The type of the marker. Currently only markers of type QRCode are supported.</param>
        /// <param name="nativePtr">The native pointer associated with the marker.</param>
        internal XRMarker(
            TrackableId trackableId,
            Pose pose,
            TrackingState trackingState,
            Vector2 center,
            Vector2 size,
            float lastSeenTime,
            TransformMode transformMode,
            ARMarkerType markerType,
            IntPtr nativePtr)
        {
            this.trackableId = trackableId;
            this.pose = pose;
            this.trackingState = trackingState;
            this.center = center;
            this.size = size;
            this.lastSeenTime = lastSeenTime;
            this.transformMode = transformMode;
            this.markerType = markerType;
            this.nativePtr = nativePtr;
        }

        /// <summary>
        /// The <see cref="TrackableId"/> associated with this marker.
        /// </summary>
        public TrackableId trackableId { get; }

        /// <summary>
        /// The <c>Pose</c>, in session space, of the marker.
        /// </summary>
        public Pose pose { get; internal set; }

        /// <summary>
        /// The <see cref="TrackingState"/> of the marker.
        /// </summary>
        public TrackingState trackingState { get; internal set; }

        /// <summary>
        /// The center of the marker in marker space (relative to its <see cref="pose"/>).
        /// </summary>
        public Vector2 center { get; internal set; }

        /// <summary>
        /// The size (dimensions) of the marker in meters.
        /// </summary>
        public Vector2 size { get; internal set; }

        /// <summary>
        /// The time the marker was last seen.
        /// </summary>
        public float lastSeenTime { get; internal set; }

        /// <summary>
        /// The type of transform on the marker.
        /// </summary>
        public TransformMode transformMode { get; internal set; }

        /// <summary>
        /// The type of the marker. Currently we only support markers of type QRCode.
        /// </summary>
        public ARMarkerType markerType { get; }

        /// <summary>
        /// A native pointer associated with this marker.
        /// The data pointer to by this pointer is implementation defined.
        /// </summary>
        public IntPtr nativePtr { get; }
    }
}