// Copyright (c) Microsoft Corporation.
// Licensed under the MIT License.

using System;
using Unity.Collections;
using UnityEngine.SubsystemsImplementation;
using UnityEngine.XR.ARSubsystems;

namespace Microsoft.MixedReality.OpenXR.ARSubsystems
{
    /// <summary>
    /// Base class for marker subsystems.
    /// </summary>
    /// <remarks>
    /// This subsystem surfaces information regarding the detection of markers such as QRCodes in the physical environment.
    /// </remarks>
    public class XRMarkerSubsystem
        : TrackingSubsystem<XRMarker, XRMarkerSubsystem, XRMarkerSubsystemDescriptor, XRMarkerSubsystem.Provider>
    {
        public XRMarkerSubsystem() { }

        /// <summary>
        /// Get or set the list of marker types <see cref="ARMarkerType"/> that will be detected.
        /// </summary>
        internal ARMarkerType[] EnabledMarkerTypes
        {
            get => provider.EnabledMarkerTypes;
            set => provider.EnabledMarkerTypes = value;
        }

        /// <summary>
        /// Default <see cref="TransformMode"/> for newly detected markers.
        /// </summary>
        public TransformMode DefaultTransformMode
        {
            get => provider.DefaultTransformMode;
            set => provider.DefaultTransformMode = value;
        }

        /// <summary>
        /// Get the changes to markers (added, updated, and removed) since the last call to <see cref="GetChanges(Allocator)"/>.
        /// </summary>
        /// <param name="allocator">An <c>Allocator</c> to use when allocating the returned <c>NativeArray</c>s.</param>
        /// <returns>
        /// <see cref="TrackableChanges{T}"/> that describes the markers that have been added, updated, and removed
        /// since the last call to <see cref="GetChanges(Allocator)"/>. The caller owns the memory allocated with <c>Allocator</c>.
        /// </returns>
        public override TrackableChanges<XRMarker> GetChanges(Allocator allocator)
        {
            var changes = provider.GetChanges(XRMarker.defaultValue, allocator);
#if DEVELOPMENT_BUILD || UNITY_EDITOR
            m_ValidationUtility.ValidateAndDisposeIfThrown(changes);
#endif
            return changes;
        }

        /// <summary>
        /// Set transform mode of an existing <see cref="XRMarker"/>.
        /// </summary>
        /// <param name="trackableId">The <see cref="TrackableId"/> of the marker to be transformed.</param>
        /// <param name="transformMode">The <see cref="TransformMode"/> to be applied.</param>
        public void SetTransformMode(TrackableId trackableId, TransformMode transformMode)
        {
            provider.SetTransformMode(trackableId, transformMode);
        }

        /// <summary>
        /// Get raw data for an existing <see cref="XRMarker"/>.
        /// </summary>
        /// <param name="trackableId">The <see cref="TrackableId"/> of the marker.</param>
        public NativeArray<byte> GetRawData(TrackableId trackableId, Allocator allocator)
        {
            return provider.GetRawData(trackableId, allocator);
        }

        /// <summary>
        /// Get decoded string for an existing <see cref="XRMarker"/>.
        /// </summary>
        /// <param name="trackableId">The <see cref="TrackableId"/> of the marker to be transformed.</param>
        public string GetDecodedString(TrackableId trackableId)
        {
            return provider.GetDecodedString(trackableId);
        }

        /// <summary>
        /// Get QR code properties for an existing <see cref="XRMarker"/> of type <see cref="ARMarkerType.QRCode"/>.
        /// </summary>
        /// <param name="trackableId">The <see cref="TrackableId"/> of the QRCode marker.</param>
        public QRCodeProperties GetQRCodeProperties(TrackableId trackableId)
        {
            return provider.GetQRCodeProperties(trackableId);
        }

        /// <summary>
        /// The API that derived classes must implement.
        /// </summary>
        public abstract class Provider : SubsystemProvider<XRMarkerSubsystem>
        {
            /// <summary>
            /// Get the changes to markers (added, updated, and removed) since the last call to
            /// <see cref="GetChanges(XRMarker,Allocator)"/>.
            /// </summary>
            /// <param name="defaultMarker">
            /// The default marker. This should be used to initialize the returned <c>NativeArray</c>s for backwards compatibility.
            /// See <see cref="TrackableChanges{T}.TrackableChanges(void*, int, void*, int, void*, int, T, int, Allocator)"/>.
            /// </param>
            /// <param name="allocator">An <c>Allocator</c> to use when allocating the returned <c>NativeArray</c>s.</param>
            /// <returns>
            /// <see cref="TrackableChanges{T}"/> describing the markers that have been added, updated, and removed
            /// since the last call to <see cref="GetChanges(XRMarker,Allocator)"/>. The changes should be allocated using
            /// <paramref name="allocator"/>.
            /// </returns>
            public abstract TrackableChanges<XRMarker> GetChanges(XRMarker defaultMarker, Allocator allocator);

            /// <summary>
            /// Set transform mode of an existing <see cref="XRMarker"/>.
            /// </summary>
            /// <param name="trackableId">The <see cref="TrackableId"/> of the marker to be transformed.</param>
            /// <param name="transformMode">The <see cref="TransformMode"/> to be applied.</param>
            public abstract void SetTransformMode(TrackableId trackableId, TransformMode transformMode);

            /// <summary>
            /// Get raw data for an existing <see cref="XRMarker"/>.
            /// </summary>
            /// <param name="trackableId">The <see cref="TrackableId"/> of the marker.</param>
            public abstract NativeArray<byte> GetRawData(TrackableId trackableId, Allocator allocator);

            /// <summary>
            /// Get decoded string for an existing <see cref="XRMarker"/>.
            /// </summary>
            /// <param name="trackableId">The <see cref="TrackableId"/> of the marker.</param>
            public abstract string GetDecodedString(TrackableId trackableId);

            /// <summary>
            /// Get QR code properties for an existing <see cref="XRMarker"/> of type <see cref="ARMarkerType.QRCode"/>.
            /// </summary>
            /// <param name="trackableId">The <see cref="TrackableId"/> of the QRCode marker.</param>
            public abstract QRCodeProperties GetQRCodeProperties(TrackableId trackableId);

            /// <summary>
            /// Get or set the list of marker types <see cref="ARMarkerType"/> that will be detected.
            /// </summary>
            internal abstract ARMarkerType[] EnabledMarkerTypes { get; set; }

            /// <summary>
            /// Default <see cref="TransformMode"/> for newly detected markers.
            /// </summary>
            internal abstract TransformMode DefaultTransformMode { get; set; }
        }

#if DEVELOPMENT_BUILD || UNITY_EDITOR
        private ValidationUtility<XRMarker> m_ValidationUtility =
            new ValidationUtility<XRMarker>();
#endif
    }
}