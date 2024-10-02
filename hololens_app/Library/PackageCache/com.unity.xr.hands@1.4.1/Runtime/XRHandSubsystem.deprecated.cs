using System;

namespace UnityEngine.XR.Hands
{
    /// <summary>
    /// A subsystem for detecting and tracking hands and their corresponding
    /// joint pose data.
    /// </summary>
    public partial class XRHandSubsystem
    {
        /// <summary>
        /// Obsolete. Use <see cref="updatedHands"/> instead.
        /// </summary>
        [Obsolete("Use updatedHands instead.")]
        public Action<UpdateSuccessFlags, UpdateType> handsUpdated;
    }
}
