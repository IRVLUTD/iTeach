// Copyright (c) Microsoft Corporation.
// Licensed under the MIT License.

using System.Collections.Generic;

namespace Microsoft.MixedReality.OpenXR
{
    /// <summary>
    /// Event arguments for the <see cref="ARMarkerManager.markersChanged"/> event.
    /// Following design pattern set by <see cref="UnityEngine.XR.ARFoundation.ARPlanesChangedEventArgs"/>
    /// </summary>
    public struct ARMarkersChangedEventArgs
    {
        /// <summary>
        /// The list of <see cref="ARMarker"/>s added since the last event.
        /// </summary>
        public IReadOnlyList<ARMarker> added { get; }

        /// <summary>
        /// The list of <see cref="ARMarker"/>s udpated since the last event.
        /// </summary>
        public IReadOnlyList<ARMarker> updated { get; }

        /// <summary>
        /// The list of <see cref="ARMarker"/>s removed since the last event.
        /// </summary>
        public IReadOnlyList<ARMarker> removed { get; }

        /// <summary>
        /// Default empty list of <see cref="ARMarker"/>s.
        /// </summary>
        private static IReadOnlyList<ARMarker> empty { get; } = new ARMarker[0];

        /// <summary>
        /// Constructs an <see cref="ARMarkersChangedEventArgs"/>.
        /// </summary>
        /// <param name="added">The list of <see cref="ARMarker"/>s added since the last event.</param>
        /// <param name="updated">The list of <see cref="ARMarker"/>s updated since the last event.</param>
        /// <param name="removed">The list of <see cref="ARMarker"/>s removed since the last event.</param>
        internal ARMarkersChangedEventArgs(
            IReadOnlyList<ARMarker> added,
            IReadOnlyList<ARMarker> updated,
            IReadOnlyList<ARMarker> removed)
        {
            this.added = (added != null) ? added : empty;
            this.updated = (updated != null) ? updated : empty;
            this.removed = (removed != null) ? removed : empty;
        }

        /// <summary>
        /// Generates a string representation of this <see cref="ARMarkersChangedEventArgs"/>.
        /// </summary>
        /// <returns>A string representation of this <see cref="ARMarkersChangedEventArgs"/>.</returns>
        public override string ToString()
        {
            return string.Format("Added: {0}, Updated: {1}, Removed: {2}", added.Count, updated.Count, removed.Count);
        }
    }
}
