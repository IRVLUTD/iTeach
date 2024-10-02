// Copyright (c) Microsoft Corporation.
// Licensed under the MIT License.

using System;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;
using UnityEngine;
using UnityEngine.XR.OpenXR;

namespace Microsoft.MixedReality.OpenXR
{
    internal class TrackingMapSubsystem : Disposable
    {
        private static MixedRealityFeaturePlugin Feature => OpenXRFeaturePlugin<MixedRealityFeaturePlugin>.Feature;

        internal static TrackingMapSubsystem TryCreateTrackingMapSubsystem()
        {
            if (!Feature.IsValidAndEnabled())
            {
                Debug.LogWarning($"{MixedRealityFeaturePlugin.featureName} is not enabled.");
                return null;
            }

            return new TrackingMapSubsystem();
        }

        private TrackingMapSubsystem()
        {
            NativeLib.StartMapTrackingSubsystem();
        }

        internal bool SupportsApplicationExclusiveMaps()
        {
            return NativeLib.MapTrackingManagerSupportsApplicationExclusiveMaps();
        }

        internal TrackingMapType ActiveTrackingMapType
        {
            get => (TrackingMapType)NativeLib.MapTrackingManagerGetActiveTrackingMapType();
        }

        internal Guid ActivateApplicationExclusiveMap(Guid? existingMapId)
        {
            Guid mapId = existingMapId.HasValue ? existingMapId.Value : Guid.Empty;
            if (NativeLib.MapTrackingManagerActivateExclusiveMap(ref mapId))
            {
                return mapId;
            }
            else
            {
                // Known error cases:
                // 1. Application-exclusive maps are not supported
                // 2. Map transition already in progress
                throw new InvalidOperationException();
            }
        }

        internal void ActivateSharedMapAsync()
        {
            if (!NativeLib.MapTrackingManagerActivateSharedMap())
            {
                // Known error cases:
                // 1. Map transition already in progress
                throw new InvalidOperationException();
            }
        }
    }
}