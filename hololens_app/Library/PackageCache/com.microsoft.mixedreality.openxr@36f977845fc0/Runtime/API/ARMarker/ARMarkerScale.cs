// Copyright (c) Microsoft Corporation.
// Licensed under the MIT License.

using System;
using UnityEngine;

namespace Microsoft.MixedReality.OpenXR
{
    /// <summary>
    /// Monobehavior to help scale detected markers.
    /// </summary>
    [RequireComponent(typeof(ARMarker))]
    public class ARMarkerScale : MonoBehaviour
    {
        private ARMarker m_arMarker;

        /// <summary>
        /// Transform containing marker contents that needs to be scaled.
        /// </summary>
        [Tooltip("Transform containing marker contents that needs to be scaled.")]
        public Transform markerScaleTransform;

        private void OnEnable()
        {
            m_arMarker = GetComponent<ARMarker>();
            if (markerScaleTransform == null)
            {
                markerScaleTransform = gameObject.transform;
            }
        }

        private void Update()
        {
            // Scale the marker contents based on the computed scale factor.
            float scaleFactor = (float)Math.Sqrt(m_arMarker.size.x * m_arMarker.size.y);
            markerScaleTransform.transform.localScale = new Vector3(scaleFactor, scaleFactor, scaleFactor);
        }
    }
}