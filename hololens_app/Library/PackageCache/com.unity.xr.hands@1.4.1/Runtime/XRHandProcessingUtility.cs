using System;
using Unity.Collections;

namespace UnityEngine.XR.Hands.Processing
{
    /// <summary>
    /// Utility methods for processing joints from a <see cref="XRHandSubsystem"/>.
    /// </summary>
    public static class XRHandProcessingUtility
    {
        /// <summary>
        /// Sets the subsystem's hand corresponding to hand passed in, which must
        /// have been initially retrieved from the <see cref="XRHandSubsystem"/>'s
        /// <see cref="XRHandSubsystem.leftHand"/> or <see cref="XRHandSubsystem.rightHand"/> 
        /// property.
        /// </summary>
        /// <param name="subsystem">
        /// The invoking subsystem for this extension method. To call this method,
        /// call <c>.SetCorrespondingHand()</c> on an <see cref="XRHandSubsystem"/>.
        /// </param>
        /// <param name="hand">
        /// The hand to update to on the subsystem. Must have originally been
        /// retrieved from that <see cref="XRHandSubsystem"/>
        /// </param>
        public static void SetCorrespondingHand(this XRHandSubsystem subsystem, XRHand hand)
        {
            if (hand.handedness == Handedness.Left)
                subsystem.SetLeftHand(hand);
            else if (hand.handedness == Handedness.Right)
                subsystem.SetRightHand(hand);
            else
                throw new InvalidOperationException("Cannot set hand on subsystem that was not initially retrieved from a subsystem's leftHand or rightHand properties!");
        }

        /// <summary>
        /// Gets the <see cref="NativeArray"/> of <see cref="XRHandJoints"/>
        /// contained in the invoking hand.
        /// </summary>
        /// <param name="hand">
        /// The invoking hand for this extension method. To call this method,
        /// call <c>.GetRawJointArray()</c> on an <see cref="XRHand"/>.
        /// </param>
        /// <returns>
        /// The raw joint array contained in the supplied hand.
        /// </returns>
        /// <remarks>
        /// After manipulating data for a particular joint, be sure to assign it
        /// back to the array you got it from, as you can only manipulate copies
        /// of objects from a <see cref="NativeArray"/>.
        /// </remarks>
        public static NativeArray<XRHandJoint> GetRawJointArray(this XRHand hand)
        {
            if (hand.handedness == Handedness.Invalid)
                throw new ArgumentException("Cannot manipulate joints on an invalid hand. Only use hands retrieved from an XRHandSubsystem's leftHand or rightHand property.");

            return hand.m_Joints;
        }

        /// <summary>
        /// Sets the <see cref="XRHand.rootPose"/> of the invoking <see cref="XRHand"/>.
        /// </summary>
        /// <param name="hand">
        /// The invoking hand for this extension method. To call this method,
        /// call <c>.SetRootPose(modifiedRootPose)</c> on an <see cref="XRHand"/>.
        /// </param>
        /// <param name="rootPose">
        /// The root <see cref="Pose"/> to set for the <paramref name="hand"/>.
        /// </param> 
        /// <remarks>
        /// Be sure to follow this with a call to <c>yourHandSubsystem.SetCorrespondingHand(modifiedHand)</c>,
        /// or you will only update the root pose of a copy of a hand.
        /// </remarks>
        public static void SetRootPose(this ref XRHand hand, Pose rootPose)
        {
            if (hand.handedness == Handedness.Invalid)
                throw new ArgumentException("Cannot set root pose on an invalid hand. Only use hands retrieved from an XRHandSubsystem's leftHand or rightHand property.");

            var offsetRotation = rootPose.rotation * Quaternion.Inverse(hand.m_RootPose.rotation);
            for (int jointIndex = 0; jointIndex < hand.m_Joints.Length; ++jointIndex)
            {
                if (hand.m_Joints[jointIndex].TryGetPose(out var pose))
                {
                    pose.position = offsetRotation * (pose.position - hand.m_RootPose.position) + rootPose.position;
                    pose.rotation = offsetRotation * pose.rotation;
                    var joint = hand.m_Joints[jointIndex];
                    joint.SetPose(pose);
                    hand.m_Joints[jointIndex] = joint;
                }
            }

            hand.m_RootPose = rootPose;
        }

        /// <summary>
        /// Sets the pose that can be retrieved from <see cref="XRHandJoint.TryGetPose"/>
        /// and sets the flag for that pose to be valid.
        /// </summary>
        /// <param name="joint">
        /// The invoking joint for this extension method. To call this method,
        /// call <c>.SetPose(modifiedPose)</c> on an <see cref="XRHandJoint"/>.
        /// </param>
        /// <param name="pose">
        /// The <see cref="Pose"/> to set for the <paramref name="joint"/>.
        /// </param> 
        /// <remarks>
        /// After manipulating data for a particular joint, be sure to assign it
        /// back to the array you got it from, as you can only manipulate copies
        /// of objects from a <see cref="NativeArray"/>.
        /// </remarks>
        public static void SetPose(this ref XRHandJoint joint, Pose pose)
        {
            if (joint.m_TrackingState.HasFlag(XRHandJointTrackingState.WillNeverBeValid))
                throw new ArgumentException("Cannot set pose on a joint that was not registered as being part of the hand layout for this subsystem's provider.", nameof(joint));

            joint.m_TrackingState |= XRHandJointTrackingState.Pose;
            joint.m_Pose = pose;
        }

        /// <summary>
        /// Sets the velocity that can be retrieved from <see cref="XRHandJoint.TryGetLinearVelocity"/>
        /// and sets the flag for that data to be valid.
        /// </summary>
        /// <param name="joint">
        /// The invoking joint for this extension method. To call this method,
        /// call <c>.SetLinearVelocity(modifiedVelocity)</c> on an <see cref="XRHandJoint"/>.
        /// </param>
        /// <param name="linearVelocity">
        /// The linear velocity to set for the <paramref name="joint"/>.
        /// </param>
        /// <remarks>
        /// After manipulating data for a particular joint, be sure to assign it
        /// back to the array you got it from, as you can only manipulate copies
        /// of objects from a <see cref="NativeArray"/>.
        /// </remarks>
        public static void SetLinearVelocity(this ref XRHandJoint joint, Vector3 linearVelocity)
        {
            if (joint.m_TrackingState.HasFlag(XRHandJointTrackingState.WillNeverBeValid))
                throw new ArgumentException("Cannot set linear velocity on a joint that was not registered as being part of the hand layout for this subsystem's provider.", nameof(joint));

            joint.m_TrackingState |= XRHandJointTrackingState.LinearVelocity;
            joint.m_LinearVelocity = linearVelocity;
        }

        /// <summary>
        /// Sets the velocity that can be retrieved from <see cref="XRHandJoint.TryGetAngularVelocity"/>
        /// and sets the flag for that data to be valid.
        /// </summary>
        /// <param name="joint">
        /// The invoking joint for this extension method. To call this method,
        /// call <c>.SetAngularVelocity(modifiedVelocity)</c> on an <see cref="XRHandJoint"/>.
        /// </param>
        /// <param name="angularVelocity">
        /// The angular velocity to set for the <paramref name="joint"/>.
        /// </param>
        /// <remarks>
        /// After manipulating data for a particular joint, be sure to assign it
        /// back to the array you got it from, as you can only manipulate copies
        /// of objects from a <see cref="NativeArray"/>.
        /// </remarks>
        public static void SetAngularVelocity(this ref XRHandJoint joint, Vector3 angularVelocity)
        {
            if (joint.m_TrackingState.HasFlag(XRHandJointTrackingState.WillNeverBeValid))
                throw new ArgumentException("Cannot set angular velocity on a joint that was not registered as being part of the hand layout for this subsystem's provider.", nameof(joint));

            joint.m_TrackingState |= XRHandJointTrackingState.AngularVelocity;
            joint.m_AngularVelocity = angularVelocity;
        }
    }
}
