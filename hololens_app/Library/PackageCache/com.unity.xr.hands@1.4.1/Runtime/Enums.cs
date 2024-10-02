using System;

namespace UnityEngine.XR.Hands
{
    /// <summary>
    /// Represents the values being tracked for a particular joint.
    /// </summary>
    [Flags]
    public enum XRHandJointTrackingState
    {
        /// <summary>
        /// No data is currently being tracked for a joint.
        /// </summary>
        None = 0,

        /// <summary>
        /// Radius of current joint.
        /// </summary>
        Radius = 1 << 0,

        /// <summary>
        /// Pose of current joint.
        /// </summary>
        Pose = 1 << 1,

        /// <summary>
        /// Linear velocity of current joint.
        /// </summary>
        LinearVelocity = 1 << 2,

        /// <summary>
        /// Angular velocity of current joint.
        /// </summary>
        AngularVelocity = 1 << 3,

        /// <summary>
        /// Joint was marked as not being part of the hand layout for the current provider.
        /// </summary>
        WillNeverBeValid = 1 << 4,
    }

    /// <summary>
    /// Represents the type of a hand joint. If you wish to convert it to an
    /// index, call <c>.ToIndex()</c> on the joint ID.
    /// </summary>
    public enum XRHandJointID
    {
        /// <summary>
        /// Invalid ID.
        /// </summary>
        Invalid,

        /// <summary>
        /// Marks the beginning of joints, or start of an array of data related
        /// to them. Casting this to an integer type will not result in a
        /// correct start. Use <see cref="XRHandJointIDUtility.ToIndex"/> instead.
        /// </summary>
        BeginMarker,

        /// <summary>
        /// Joint for the wrist.
        /// </summary>
        Wrist = BeginMarker,

        /// <summary>
        /// Represents the palm of the hand.
        /// </summary>
        Palm,

        /// <summary>
        /// Metacarpal joint of the thumb.
        /// </summary>
        ThumbMetacarpal,

        /// <summary>
        /// Proximal joint of the thumb.
        /// </summary>
        ThumbProximal,

        /// <summary>
        /// Distal joint of the thumb.
        /// </summary>
        ThumbDistal,

        /// <summary>
        /// Tip of the thumb.
        /// </summary>
        ThumbTip,

        /// <summary>
        /// Metacarpal joint of the index finger.
        /// </summary>
        IndexMetacarpal,

        /// <summary>
        /// Proximal joint of the index finger.
        /// </summary>
        IndexProximal,

        /// <summary>
        /// Intermediate joint of the index finger.
        /// </summary>
        IndexIntermediate,

        /// <summary>
        /// Distal joint of the index finger.
        /// </summary>
        IndexDistal,

        /// <summary>
        /// Tip of the index finger.
        /// </summary>
        IndexTip,

        /// <summary>
        /// Metacarpal joint of the middle finger.
        /// </summary>
        MiddleMetacarpal,

        /// <summary>
        /// Proximal joint of the middle finger.
        /// </summary>
        MiddleProximal,

        /// <summary>
        /// Intermediate joint of the middle finger.
        /// </summary>
        MiddleIntermediate,

        /// <summary>
        /// Distal joint of the middle finger.
        /// </summary>
        MiddleDistal,

        /// <summary>
        /// Tip of the middle finger.
        /// </summary>
        MiddleTip,

        /// <summary>
        /// Metacarpal joint of the ring finger.
        /// </summary>
        RingMetacarpal,

        /// <summary>
        /// Proximal joint of the ring finger.
        /// </summary>
        RingProximal,

        /// <summary>
        /// Intermediate joint of the ring finger.
        /// </summary>
        RingIntermediate,

        /// <summary>
        /// Distal joint of the ring finger.
        /// </summary>
        RingDistal,

        /// <summary>
        /// Tip of the ring finger.
        /// </summary>
        RingTip,

        /// <summary>
        /// Metacarpal joint of the little finger.
        /// </summary>
        LittleMetacarpal,

        /// <summary>
        /// Proximal joint of the little finger.
        /// </summary>
        LittleProximal,

        /// <summary>
        /// Intermediate joint of the little finger.
        /// </summary>
        LittleIntermediate,

        /// <summary>
        /// Distal joint of the little finger.
        /// </summary>
        LittleDistal,

        /// <summary>
        /// Tip of the little finger.
        /// </summary>
        LittleTip,

        /// <summary>
        /// Marks the end of joints, or size of an array of data related to
        /// them. Casting this to an integer type will not result in a correct
        /// count. Use <see cref="XRHandJointIDUtility.ToIndex"/> instead.
        /// </summary>
        EndMarker
    }

    /// <summary>
    /// Represents which hand is being referred to.
    /// </summary>
    public enum Handedness
    {
        /// <summary>
        /// Invalid hand. Will never be usable. Use <see cref="XRHandSubsystem.leftHand"/>
        /// or <see cref="XRHandSubsystem.rightHand"/> to obtain a valid hand.
        /// </summary>
        Invalid,

        /// <summary>
        /// Left hand.
        /// </summary>
        Left,

        /// <summary>
        /// Right hand.
        /// </summary>
        Right
    }

    /// <summary>
    /// Represents a finger on either hand. Useful with the
    /// <see cref="XRHandJointIDUtility.GetFrontJointID"/> and
    /// <see cref="XRHandJointIDUtility.GetBackJointID"/> APIs.
    /// </summary>
    public enum XRHandFingerID
    {
        /// <summary>
        /// Represents the thumb.
        /// </summary>
        Thumb,

        /// <summary>
        /// Represents the index finger.
        /// </summary>
        Index,

        /// <summary>
        /// Represents the middle finger.
        /// </summary>
        Middle,

        /// <summary>
        /// Represents the ring finger.
        /// </summary>
        Ring,

        /// <summary>
        /// Represents the little finger.
        /// </summary>
        Little
    }

    /// <summary>
    /// Houses extension and utility methods for <see cref="XRHandJointID"/>.
    /// </summary>
    public static class XRHandJointIDUtility
    {
        /// <summary>
        /// Call <c>.ToIndex()</c> on a <see cref="XRHandJointID"/> to get its
        /// corresponding index into an array of joint data.
        /// </summary>
        /// <param name="jointId">ID of the joint to convert to an index.</param>
        /// <returns>
        /// The index matching the ID passed in.
        /// </returns>
        public static int ToIndex(this XRHandJointID jointId) => (int)jointId - 1;

        /// <summary>
        /// Call this to get the corresponding <see cref="XRHandJointID"/> from
        /// an index into an array of associated data.
        /// </summary>
        /// <param name="index">Index to convert to an ID.</param>
        /// <returns>
        /// The ID matching the index passed in.
        /// </returns>
        public static XRHandJointID FromIndex(int index) => (XRHandJointID)(index + 1);

        /// <summary>
        /// Gets the metacarpal <see cref="XRHandJointID"/> of a given <see cref="XRHandFingerID"/>.
        /// </summary>
        /// <param name="fingerId">ID of the finger of which you want the first <see cref="XRHandJointID"/>.</param>
        /// <returns>
        /// First <see cref="XRHandJointID"/> for the given finger in an <see cref="XRHand"/>
        /// object's list of joints.
        /// </returns>
        /// <example>
        /// You can use <c>GetFrontJointID</c> and <see cref="GetBackJointID(XRHandFingerID)"/> to iterate
        /// through the joints of a specific finger:
        /// <code>
        /// <![CDATA[
        ///     for(var i = XRHandFingerID.Thumb.GetFrontJointID().ToIndex(); // metacarpal
        ///             i <= XRHandFingerID.Thumb.GetBackJointID().ToIndex();  // tip
        ///             i++)
        ///     {
        ///         // hand is an XRHand object
        ///         XRHandJoint fingerJoint = hand.GetJoint(XRHandJointIDUtility.FromIndex(i));
        ///         // Use data...
        ///     }
        /// ]]>
        /// </code>
        /// </example>
        public static XRHandJointID GetFrontJointID(this XRHandFingerID fingerId)
        {
            switch (fingerId)
            {
                case XRHandFingerID.Thumb:
                    return XRHandJointID.ThumbMetacarpal;

                case XRHandFingerID.Index:
                    return XRHandJointID.IndexMetacarpal;

                case XRHandFingerID.Middle:
                    return XRHandJointID.MiddleMetacarpal;

                case XRHandFingerID.Ring:
                    return XRHandJointID.RingMetacarpal;

                case XRHandFingerID.Little:
                    return XRHandJointID.LittleMetacarpal;
            }

            throw new ArgumentException(nameof(fingerId) + " must be a valid value!");
        }

        /// <summary>
        /// Gets the tip <see cref="XRHandJointID"/> of a given <see cref="XRHandFingerID"/>.
        /// </summary>
        /// <param name="fingerId">ID of the finger you want the last <see cref="XRHandJointID"/> of.</param>
        /// <returns>Last <see cref="XRHandJointID"/> for the given finger in an <see cref="XRHand"/>
        /// object's list of joints.</returns>
        /// <remarks>Use with <see cref="GetFrontJointID(XRHandFingerID)"/> to iterate through the joints
        /// of a finger.</remarks>
        public static XRHandJointID GetBackJointID(this XRHandFingerID fingerId)
        {
            switch (fingerId)
            {
                case XRHandFingerID.Thumb:
                    return XRHandJointID.ThumbTip;

                case XRHandFingerID.Index:
                    return XRHandJointID.IndexTip;

                case XRHandFingerID.Middle:
                    return XRHandJointID.MiddleTip;

                case XRHandFingerID.Ring:
                    return XRHandJointID.RingTip;

                case XRHandFingerID.Little:
                    return XRHandJointID.LittleTip;
            }

            throw new ArgumentException(nameof(fingerId) + " must be a valid value!");
        }
    }
}
