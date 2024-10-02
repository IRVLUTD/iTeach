using System;

namespace UnityEngine.XR.Hands.ProviderImplementation
{
    public static partial class XRHandProviderUtility
    {
        /// <summary>
        /// Create a fully configurable joint with at least a pose in hand
        /// space, tracking state, and ID.
        /// </summary>
        /// <param name="trackingState">
        /// The tracking state flags associated with this joint, representing
        /// which fields of the <see cref="XRHandJoint"/> are valid.
        /// </param>
        /// <param name="id">
        /// The <see cref="XRHandJointID"/> of the joint. When filling out an
        /// element of an array of <see cref="XRHandJoint"/>, the index must
        /// be converted with <see cref="XRHandJointIDUtility.FromIndex"/>.
        /// </param>
        /// <param name="pose">
        /// The pose of the joint in session space, relative to the
        /// [XROrigin](xref:Unity.XR.CoreUtils.XROrigin).
        /// </param>
        /// <param name="radius">
        /// The radius of the joint. The default value is <c>0f</c>.
        /// </param>
        /// <param name="linearVelocity">
        /// The linear velocity of the joint in hand space (relative to the
        /// [XROrigin](xref:Unity.XR.CoreUtils.XROrigin)). The default value is
        /// <c>Vector3.zero</c>.
        /// </param>
        /// <param name="angularVelocity">
        /// The angular velocity of the joint in hand space (relative to the
        /// [XROrigin](xref:Unity.XR.CoreUtils.XROrigin)). The default value is
        /// <c>Vector3.zero</c>.
        /// </param>
        /// <returns>
        /// An <see cref="XRHandJoint"/> with the given pose and other supplied
        /// data.
        /// </returns>
        [Obsolete("Use the CreateJoint overload that has an additional first argument for handedness. Otherwise, joints will always report as being from the left hand, even if they were from the right hand.")]
        public static XRHandJoint CreateJoint(
            XRHandJointTrackingState trackingState,
            XRHandJointID id,
            Pose pose,
            float radius = 0f,
            Vector3 linearVelocity = new Vector3(),
            Vector3 angularVelocity = new Vector3())
        {
            return new XRHandJoint
            {
                m_TrackingState = trackingState,
                m_IdAndHandedness = (int)id,
                m_Pose = pose,
                m_Radius = radius,
                m_LinearVelocity = linearVelocity,
                m_AngularVelocity = angularVelocity,
            };
        }
    }
}
