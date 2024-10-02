#if ENABLE_VR || UNITY_GAMECORE || PACKAGE_DOCS_GENERATION

using System;
using UnityEngine.InputSystem;

namespace UnityEngine.XR.Hands
{
    public partial class MetaAimHand
    {
        /// <summary>
        /// Queues update events in the Input System based on the supplied hand.
        /// It is not recommended that you call this directly. This will be called
        /// for you when appropriate.
        /// </summary>
        /// <param name="aimFlags">
        /// The aim flags to update in the Input System.
        /// </param>
        /// <param name="aimPose">
        /// The aim pose to update in the Input System.
        /// </param>
        /// <param name="pinchIndex">
        /// The pinch strength for the index finger to update in the Input System.
        /// </param>
        /// <param name="pinchMiddle">
        /// The pinch strength for the middle finger to update in the Input System.
        /// </param>
        /// <param name="pinchRing">
        /// The pinch strength for the ring finger to update in the Input System.
        /// </param>
        /// <param name="pinchLittle">
        /// The pinch strength for the little finger to update in the Input System.
        /// </param>
        [Obsolete("Use the UpdateHand that has an additional first bool parameter for whether the hand is tracked, or the device pose won't update correctly.")]
        public void UpdateHand(
            MetaAimFlags aimFlags,
            Pose aimPose,
            float pinchIndex,
            float pinchMiddle,
            float pinchRing,
            float pinchLittle)
        {
            UpdateHand(
                (aimFlags & MetaAimFlags.Valid) != MetaAimFlags.None,
                aimFlags,
                aimPose,
                pinchIndex,
                pinchMiddle,
                pinchRing,
                pinchLittle);
        }
    }
}

#endif // ENABLE_VR || UNITY_GAMECORE || PACKAGE_DOCS_GENERATION
