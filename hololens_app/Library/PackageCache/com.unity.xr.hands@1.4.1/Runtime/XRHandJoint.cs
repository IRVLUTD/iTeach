using System;
using System.Runtime.InteropServices;
using UnityEngine.XR.Hands.ProviderImplementation;

namespace UnityEngine.XR.Hands
{
    /// <summary>
    /// Represents a joint of an <see cref="XRHand"/>.
    /// </summary>
    /// <remarks>
    /// The term "joint" should be taken loosely in this context. In addition to the
    /// anatomical finger joints, the list of joints includes the fingertips, a point on the palm
    /// and a point on the wrist. See <see cref="XRHandJointID"/> for the full list of
    /// joints.
    ///
    /// Refer to [Hand data model](xref:xrhands-data-model) for a description of the joint locations
    /// and the data they contain.
    /// </remarks>
    [StructLayout(LayoutKind.Sequential)]
    public struct XRHandJoint : IEquatable<XRHandJoint>
    {
        /// <summary>
        /// The ID of this joint.
        /// </summary>
        /// <value>The joint ID.</value>
        public XRHandJointID id => (XRHandJointID)(m_IdAndHandedness & ~k_IsRightHandBit);

        /// <summary>
        /// Denotes which hand this joint is on.
        /// </summary>
        /// <value>Right or left.</value>
        public Handedness handedness => (m_IdAndHandedness & k_IsRightHandBit) != 0 ? Handedness.Right : Handedness.Left;

        /// <summary>
        /// Represents which tracking data is valid.
        /// </summary>
        /// <value>A flag is set for each valid type of data. If the
        /// The <see cref="XRHandJointTrackingState.WillNeverBeValid"/> flag is set
        /// when this joint ID isn't supported by the hand data provider.</value>
        public XRHandJointTrackingState trackingState => m_TrackingState;

        /// <summary>
        /// Retrieves the joint's radius, if available.
        /// </summary>
        /// <param name="radius">
        /// Assigned the tracked radius of this joint, if successful.
        /// Set to zero, if unsuccessful.
        /// </param>
        /// <returns>
        /// Returns <see langword="true"/> if successful and the radius was
        /// filled out with valid tracking data, returns <see langword="false"/>
        /// otherwise.
        /// </returns>
        public bool TryGetRadius(out float radius)
        {
            if ((m_TrackingState & XRHandJointTrackingState.Radius) == XRHandJointTrackingState.None)
            {
                radius = 0.0f;
                return false;
            }

            radius = m_Radius;
            return true;
        }

        /// <summary>
        /// Retrieves the joint's pose, if available.
        /// </summary>
        /// <param name="pose">
        /// Assigned the tracked pose of this joint, if successful.
        /// Set to <see cref="Pose.identity"/>, if unsuccessful.
        /// </param>
        /// <returns>
        /// Returns <see langword="true"/> if successful and the joint pose was
        /// filled out with valid tracking data, returns <see langword="false"/>
        /// otherwise.
        /// </returns>
        /// <remarks>
        /// Joint poses are relative to the real-world point chosen by the user's device.
        /// 
        /// To transform to world space so that the joint appears in the correct location
        /// relative to the user, transform the pose based on the
        /// [XROrigin](xref:Unity.XR.CoreUtils.XROrigin).
        /// </remarks>
        /// <example>
        /// The following example illustrates how to transform a pose into world space using the
        /// transform from the XROrigin object in a scene.
        /// <code>
        /// public Pose ToWorldPose(XRHandJoint joint, Transform origin)
        /// {
        ///     Pose xrOriginPose = new Pose(origin.position, origin.rotation);
        ///     if (joint.TryGetPose(out Pose jointPose))
        ///     {
        ///         return jointPose.GetTransformedBy(xrOriginPose);
        ///     }
        ///     else
        ///     {
        ///         return Pose.identity;
        ///     }
        /// }
        /// </code>
        /// </example>
        public bool TryGetPose(out Pose pose)
        {
            if ((m_TrackingState & XRHandJointTrackingState.Pose) == XRHandJointTrackingState.None)
            {
                pose = Pose.identity;
                return false;
            }

            pose = m_Pose;
            return true;
        }

        /// <summary>
        /// Retrieves the joint's linear velocity vector, if available.
        /// </summary>
        /// <param name="linearVelocity">
        /// Assigned the tracked linear velocity of this joint, if successful.
        /// Set to <see cref="Vector3.zero"/>, if unsuccessful.
        /// </param>
        /// <returns>
        /// Returns <see langword="true"/> if successful and the velocity was
        /// filled out with valid tracking data, returns <see langword="false"/>
        /// otherwise.
        /// </returns>
        /// <remarks>
        /// To transform to world space so that the vector has the correct direction
        /// relative to the user, rotate this by the rotation of the
        /// [XROrigin](xref:Unity.XR.CoreUtils.XROrigin).
        /// </remarks>
        public bool TryGetLinearVelocity(out Vector3 linearVelocity)
        {
            if ((m_TrackingState & XRHandJointTrackingState.LinearVelocity) == XRHandJointTrackingState.None)
            {
                linearVelocity = Vector3.zero;
                return false;
            }

            linearVelocity = m_LinearVelocity;
            return true;
        }

        /// <summary>
        /// Retrieves the joint's angular velocity vector, if available
        /// </summary>
        /// <param name="angularVelocity">
        /// Assigned the tracked angular velocity of this joint, if successful.
        /// Set to <see cref="Vector3.zero"/>, if unsuccessful.
        /// </param>
        /// <returns>
        /// Returns <see langword="true"/> if successful and the angular
        /// velocity filled out with valid tracking data, returns
        /// <see langword="false"/> otherwise.
        /// </returns>
        /// <remarks>
        /// To transform to world space so that the vector has the correct direction
        /// relative to the user, rotate this by the rotation of the
        /// [XROrigin](xref:Unity.XR.CoreUtils.XROrigin).
        /// </remarks>
        public bool TryGetAngularVelocity(out Vector3 angularVelocity)
        {
            if ((m_TrackingState & XRHandJointTrackingState.AngularVelocity) == XRHandJointTrackingState.None)
            {
                angularVelocity = Vector3.zero;
                return false;
            }

            angularVelocity = m_AngularVelocity;
            return true;
        }

        /// <summary>
        /// Returns a string representation of the XRHandJoint.
        /// </summary>
        /// <returns>
        /// String representation of the value.
        /// </returns>
        public override string ToString()
        {
            return string.Format(
                "[{0} {1}] Pose: {2} | Radius: {3} | Linear Velocity: {4} | Angular Velocity: {5} | Tracking State: {6}",
                handedness, id, m_Pose.ToString("F4"), m_Radius.ToString("F4"), m_LinearVelocity.ToString("F4"), m_AngularVelocity.ToString("F4"), m_TrackingState);
        }

        /// <summary>
        /// Tests for equality.
        /// </summary>
        /// <param name="other">The <see cref="XRHandJoint"/> to compare against.</param>
        /// <returns>
        /// Returns <see langword="true"/> if the underlying native pointers are
        /// the same. Returns <see langword="false"/> otherwise.
        /// </returns>
        public bool Equals(XRHandJoint other)
        {
            return m_IdAndHandedness == other.m_IdAndHandedness &&
                m_Pose == other.m_Pose &&
                m_Radius == other.m_Radius &&
                m_LinearVelocity == other.m_LinearVelocity &&
                m_AngularVelocity == other.m_AngularVelocity &&
                m_TrackingState == other.m_TrackingState;
        }

        /// <summary>
        /// Tests for equality.
        /// </summary>
        /// <param name="obj">An <see cref="object"/> to compare against.</param>
        /// <returns>
        /// Returns <see langword="true"/> if <paramref name="obj"/> is an
        /// <see cref="XRHandJoint"/> and it compares equal to this one using
        /// <see cref="Equals(UnityEngine.XR.Hands.XRHandJoint)"/>.
        /// </returns>
        public override bool Equals(object obj) => obj is XRHandJoint other && Equals(other);

        /// <summary>
        /// Computes a hash code from all fields of XRHandJoint.
        /// </summary>
        /// <returns>Returns a hash code of this object.</returns>
        public override int GetHashCode()
        {
            unchecked
            {
                int hash = m_IdAndHandedness.GetHashCode();
                hash = hash * 486187739 + m_Pose.GetHashCode();
                hash = hash * 486187739 + m_Radius.GetHashCode();
                hash = hash * 486187739 + m_LinearVelocity.GetHashCode();
                hash = hash * 486187739 + m_AngularVelocity.GetHashCode();
                hash = hash * 486187739 + m_TrackingState.GetHashCode();
                return hash;
            }
        }

        /// <summary>
        /// Tests for equality. Same as <see cref="Equals(UnityEngine.XR.Hands.XRHandJoint)"/>.
        /// </summary>
        /// <param name="lhs">The left-hand side of the comparison.</param>
        /// <param name="rhs">The right-hand side of the comparison.</param>
        /// <returns>Returns the same value as <see cref="Equals(UnityEngine.XR.Hands.XRHandJoint)"/>.</returns>
        public static bool operator ==(XRHandJoint lhs, XRHandJoint rhs) => lhs.Equals(rhs);

        /// <summary>
        /// Tests for inequality. Same as !<see cref="Equals(UnityEngine.XR.Hands.XRHandJoint)"/>
        /// </summary>
        /// <param name="lhs">The left-hand side of the comparison.</param>
        /// <param name="rhs">The right-hand side of the comparison.</param>
        /// <returns>Returns the negation of <see cref="Equals(UnityEngine.XR.Hands.XRHandJoint)"/>.</returns>
        public static bool operator !=(XRHandJoint lhs, XRHandJoint rhs) => !lhs.Equals(rhs);

        internal int m_IdAndHandedness;
        internal Pose m_Pose;
        internal float m_Radius;
        internal Vector3 m_LinearVelocity;
        internal Vector3 m_AngularVelocity;
        internal XRHandJointTrackingState m_TrackingState;

        internal const int k_IsRightHandBit = 1 << 31;
    }
}
