using System;

namespace UnityEngine.XR.Hands.Gestures
{
    /// <summary>
    /// Configuration values for how to calculate <see cref="XRFingerShape"/>.
    /// Defines minimum and maximum angles or distances between joints to normalize finger joints into each
    /// <see cref="XRFingerStateType"/>'s' <c>0</c> to <c>1</c> value.
    /// </summary>
    [Serializable]
    public class XRFingerShapeConfiguration
    {
        /// <summary>
        /// The minimum degrees between vectors from the first extension
        /// joint to its closest neighbors.
        /// </summary>
        public float minimumFullCurlDegrees1 { get; set; }

        /// <summary>
        /// The maximum degrees between vectors from the first extension
        /// joint to its closest neighbors.
        /// </summary>
        public float maximumFullCurlDegrees1 { get; set; }

        /// <summary>
        /// The minimum degrees between vectors from the second extension
        /// joint to its closest neighbors.
        /// </summary>
        public float minimumFullCurlDegrees2 { get; set; }

        /// <summary>
        /// The maximum degrees between vectors from the second extension
        /// joint to its closest neighbors.
        /// </summary>
        public float maximumFullCurlDegrees2 { get; set; }

        /// <summary>
        /// The minimum degrees between vectors from the third extension
        /// joint to its closest neighbors. Ignored on the thumb.
        /// </summary>
        public float minimumFullCurlDegrees3 { get; set; }

        /// <summary>
        /// The maximum degrees between vectors from the third extension
        /// joint to its closest neighbors. Ignored on the thumb.
        /// </summary>
        public float maximumFullCurlDegrees3 { get; set; }

        /// <summary>
        /// The minimum degrees between vectors from the central flex joint to
        /// its closest neighbors. When the angle between those two vectors is
        /// less than or equal to this value, the flex value will be <c>1</c>.
        /// </summary>
        public float minimumBaseCurlDegrees { get; set; }

        /// <summary>
        /// The maximum degrees between vectors from the central flex joint to
        /// its closest neighbors. When the angle between those two vectors is
        /// greater than or equal to this value, the flex value will be <c>0</c>.
        /// </summary>
        public float maximumBaseCurlDegrees { get; set; }

        /// <summary>
        /// The minimum degrees between vectors from the first curl
        /// joint to its closest neighbors.
        /// </summary>
        public float minimumTipCurlDegrees1 { get; set; }

        /// <summary>
        /// The maximum degrees between vectors from the first curl
        /// joint to its closest neighbors.
        /// </summary>
        public float maximumTipCurlDegrees1 { get; set; }

        /// <summary>
        /// The minimum degrees between vectors from the second curl
        /// joint to its closest neighbors.
        /// </summary>
        public float minimumTipCurlDegrees2 { get; set; }

        /// <summary>
        /// The maximum degrees between vectors from the second curl
        /// joint to its closest neighbors.
        /// </summary>
        public float maximumTipCurlDegrees2 { get; set; }

        /// <summary>
        /// The minimum distance between each finger tip and the thumb tip
        /// to calculate pinch values for. Values below or equal to this will
        /// result in a pinch value of <c>1</c>.
        /// </summary>
        public float minimumPinchDistance { get; set; }

        /// <summary>
        /// The maximum distance between each finger tip and the thumb tip
        /// which allows for non-zero pinch values.
        /// </summary>
        public float maximumPinchDistance { get; set; }

        /// <summary>
        /// The minimum degrees for splay between this finger and the next.
        /// Not used for the little finger.
        /// </summary>
        public float minimumSpreadDegrees { get; set; }

        /// <summary>
        /// The maximum degrees for splay between this finger and the next.
        /// Not used for the little finger.
        /// </summary>
        public float maximumSpreadDegrees { get; set; }
    }
}
