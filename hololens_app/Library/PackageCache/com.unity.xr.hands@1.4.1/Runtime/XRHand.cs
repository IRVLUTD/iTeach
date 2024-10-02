using System;
using Unity.Collections;

namespace UnityEngine.XR.Hands
{
    /// <summary>
    /// Represents a hand from an <see cref="XRHandSubsystem"/>. Do not create
    /// this yourself - get hand objects from the <see cref="XRHandSubsystem.leftHand"/>
    /// and <see cref="XRHandSubsystem.rightHand"/> properties of the <see cref="XRHandSubsystem"/>.
    /// </summary>
    /// <remarks>
    /// See [Hand tracking](xref:xrhands-tracking-data) for a description of the hand data model
    /// and how to access the tracking data.
    /// </remarks>
    public struct XRHand : IEquatable<XRHand>
    {
        /// <summary>
        /// Retrieves an <see cref="XRHandJoint"/> by its ID.
        /// </summary>
        /// <remarks>
        /// The joint data is stored in an internal native array that isn't copied if you
        /// make a shallow copy of an <c>XRHand</c> object. This native array is modified each time
        /// A hand update occurs. Calling this function from a
        /// copied <c>XRHand</c> retrieves the latest hand data, not the data from when the
        /// hand object was copied. To take a snapshot of the joint data for use later, you must
        /// copy each individual <see cref="XRHandJoint"/> object.
        /// </remarks>
        /// <param name="id">ID of the required joint.</param>
        /// <returns>The <see cref="XRHandJoint"/> corresponding the ID passed in.</returns>
        public XRHandJoint GetJoint(XRHandJointID id) => m_Joints[id.ToIndex()];
        internal NativeArray<XRHandJoint> m_Joints;

        /// <summary>
        /// Root pose for the hand.
        /// </summary>
        /// <value>Located at the wrist joint, the forward vector of the hand points in the direction
        /// of the fingers.</value>
        public Pose rootPose => m_RootPose;
        internal Pose m_RootPose;

        /// <summary>
        /// Represents which hand this is.
        /// </summary>
        /// <value>Right, left, or invalid.</value>
        public Handedness handedness => m_Handedness;
        Handedness m_Handedness;

        /// <summary>
        /// Whether the subsystem is currently tracking this hand's root pose and joints.
        /// </summary>
        /// <value>Indicates the tracking status as of the last hand data update.</value>
        public bool isTracked { get; internal set; }

        /// <summary>
        /// Returns a string representation of the XRHand.
        /// </summary>
        /// <returns>
        /// String representation of the value.
        /// </returns>
        public override string ToString()
        {
            return m_Handedness + " XRHand";
        }

        /// <summary>
        /// Tests for equality.
        /// </summary>
        /// <param name="other">The <see cref="XRHand"/> to compare against.</param>
        /// <returns>
        /// Returns <see langword="true"/> if the underlying native pointers are
        /// the same. Returns <see langword="false"/> otherwise.
        /// </returns>
        public bool Equals(XRHand other)
        {
            return m_Joints == other.m_Joints &&
                m_RootPose == other.m_RootPose &&
                m_Handedness == other.m_Handedness &&
                isTracked == other.isTracked;
        }

        /// <summary>
        /// Tests for equality.
        /// </summary>
        /// <param name="obj">An <see cref="object"/> to compare against.</param>
        /// <returns>
        /// Returns <see langword="true"/> if <paramref name="obj"/> is an
        /// <see cref="XRHand"/> and it compares equal to this one using
        /// <see cref="Equals(UnityEngine.XR.Hands.XRHand)"/>.
        /// </returns>
        public override bool Equals(object obj) => obj is XRHand other && Equals(other);

        /// <summary>
        /// Computes a hash code from all fields of XRHand.
        /// </summary>
        /// <returns>Returns a hash code of this object.</returns>
        public override int GetHashCode()
        {
            unchecked
            {
                int hash = m_Joints.GetHashCode();
                hash = hash * 486187739 + m_RootPose.GetHashCode();
                hash = hash * 486187739 + m_Handedness.GetHashCode();
                hash = hash * 486187739 + isTracked.GetHashCode();
                return hash;
            }
        }

        /// <summary>
        /// Tests for equality. Same as <see cref="Equals(UnityEngine.XR.Hands.XRHand)"/>.
        /// </summary>
        /// <param name="lhs">The left-hand side of the comparison.</param>
        /// <param name="rhs">The right-hand side of the comparison.</param>
        /// <returns>Returns the same value as <see cref="Equals(UnityEngine.XR.Hands.XRHand)"/>.</returns>
        public static bool operator ==(XRHand lhs, XRHand rhs) => lhs.Equals(rhs);

        /// <summary>
        /// Tests for inequality. Same as !<see cref="Equals(UnityEngine.XR.Hands.XRHand)"/>
        /// </summary>
        /// <param name="lhs">The left-hand side of the comparison.</param>
        /// <param name="rhs">The right-hand side of the comparison.</param>
        /// <returns>Returns the negation of <see cref="Equals(UnityEngine.XR.Hands.XRHand)"/>.</returns>
        public static bool operator !=(XRHand lhs, XRHand rhs) => !lhs.Equals(rhs);

        internal XRHand(Handedness handedness, Allocator allocator)
        {
            m_RootPose = Pose.identity;
            m_Handedness = handedness;
            m_Joints = new NativeArray<XRHandJoint>(XRHandJointID.EndMarker.ToIndex(), allocator);
            isTracked = false;
        }

        internal void Dispose()
        {
            if (m_Joints.IsCreated)
                m_Joints.Dispose();
        }
    }
}
