using System;
using Unity.Collections;
using UnityEngine.SubsystemsImplementation;
using UnityEngine.XR.Hands.Gestures;

namespace UnityEngine.XR.Hands.ProviderImplementation
{
    /// <summary>
    /// Methods to implement by the implementing provider for an <see cref="XRHandSubsystem"/>.
    /// </summary>
    public abstract class XRHandSubsystemProvider
        : SubsystemProvider<XRHandSubsystem>
    {
        /// <summary>
        /// Gets the layout of hand joints for this provider, by having the
        /// provider mark each index corresponding to a <see cref="XRHandJointID"/>
        /// get marked as <see langword="true"/> if the provider attempts to track
        /// that joint.
        /// </summary>
        /// <remarks>
        /// Called once on creation so that before the subsystem is even started,
        /// the user can immediately create a valid hierarchical structure as
        /// soon as they get a reference to the subsystem without even needing to
        /// start it. This is called before any call to
        /// <see cref="GetFingerShapeConfiguration"/>.
        /// </remarks>
        /// <param name="handJointsInLayout">
        /// Each index corresponds to a <see cref="XRHandJointID"/>. For each
        /// joint that the provider will attempt to track, mark that spot as
        /// <see langword="true"/> by calling <c>.ToIndex()</c> on that ID.
        /// </param>
        public abstract void GetHandLayout(NativeArray<bool> handJointsInLayout);

        /// <summary>
        /// Gets the <see cref="XRFingerShapeConfiguration"/> on the current
        /// device for the given <see cref="XRHandFingerID"/>.
        /// </summary>
        /// <remarks>
        /// Called once for each finger on creation so that the subsystem will
        /// always have valid configurations to base detection math off of. If
        /// the provider does not override this, defaults will be reported -
        /// this means that if the device is more constrained in reporting joint
        /// data than the defaults, gestures and poses may not be detected correctly.
        /// Called after <see cref="GetHandLayout"/> for each finger, but before
        /// the subsystem is returned during a call to
        /// <see cref="XRHandSubsystemDescriptor.Create"/>.
        /// </remarks>
        /// <param name="fingerID">
        /// Which finger to get the <see cref="XRFingerShapeConfiguration"/> for.
        /// </param>
        /// <returns>
        /// A populated <see cref="XRFingerShapeConfiguration"/> representing
        /// range of motion for the given <see cref="XRHandFingerID"/>.
        /// </returns>
        /// <exception>
        /// Will throw an exception if <paramref name="fingerID"/> is not a named
        /// value of <see cref="XRHandFingerID"/>.
        /// </exception>
        public virtual XRFingerShapeConfiguration GetFingerShapeConfiguration(XRHandFingerID fingerID)
        {
            switch (fingerID)
            {
                case XRHandFingerID.Thumb:
                    return FingerConfigDefaults.k_Thumb;

                case XRHandFingerID.Index:
                    return FingerConfigDefaults.k_Index;

                case XRHandFingerID.Middle:
                    return FingerConfigDefaults.k_Middle;

                case XRHandFingerID.Ring:
                    return FingerConfigDefaults.k_Ring;

                case XRHandFingerID.Little:
                    return FingerConfigDefaults.k_Little;

                default:
                    throw new ArgumentException("Invalid XRHandFingerID!");
            }
        }

        /// <summary>
        /// Attempts to retrieve current hand-tracking data from the provider.
        /// </summary>
        /// <param name="updateType">
        /// Informs the provider which kind of timing the update is being
        /// requested under.
        /// </param>
        /// <param name="leftHandRootPose">
        /// Update this and include <c>XRHandSubsystem.UpdateSuccessFlags.LeftHandRootPose</c>
        /// in the return value to update the left hand's root pose.
        /// </param>
        /// <param name="leftHandJoints">
        /// Array of hand joints to fill out for the left hand. These are
        /// initialized with a copy of the current joint data for the left hand,
        /// so if the last known tracking data for a particular joint is still
        /// fine, you don't need to fill out that data again. If you update
        /// these, include <c>XRHandSubsystem.UpdateSuccessFlags.LeftHandJoints</c>
        /// in the return value to have the changes reflected in the subsystem.
        /// </param>
        /// <param name="rightHandRootPose">
        /// Update this and include <c>XRHandSubsystem.UpdateSuccessFlags.RightHandRootPose</c>
        /// in the return value to update the right hand's root pose.
        /// </param>
        /// <param name="rightHandJoints">
        /// Array of hand joints to fill out for the right hand. These are
        /// initialized with a copy of the current joint data for the right hand,
        /// so if the last known tracking data for a particular joint is still
        /// fine, you don't need to fill out that data again. If you update
        /// these, include <c>XRHandSubsystem.UpdateSuccessFlags.RightHandJoints</c>
        /// in the return value to have the changes reflected in the subsystem.
        /// </param>
        /// <returns>
        /// Returns <see cref="XRHandSubsystem.UpdateSuccessFlags"/> to describe which tracking
        /// data was successfully updated.
        /// </returns>
        public abstract XRHandSubsystem.UpdateSuccessFlags TryUpdateHands(
            XRHandSubsystem.UpdateType updateType,
            ref Pose leftHandRootPose,
            NativeArray<XRHandJoint> leftHandJoints,
            ref Pose rightHandRootPose,
            NativeArray<XRHandJoint> rightHandJoints);

        // these defaults were captured using a Meta Quest 2
        static class FingerConfigDefaults
        {
            static internal readonly XRFingerShapeConfiguration k_Thumb = new XRFingerShapeConfiguration
            {
                minimumFullCurlDegrees1 = 132f,
                maximumFullCurlDegrees1 = 162f,
                minimumFullCurlDegrees2 = 129f,
                maximumFullCurlDegrees2 = 180f,
                minimumFullCurlDegrees3 = -1f,
                maximumFullCurlDegrees3 = -1f,

                minimumBaseCurlDegrees = 2f,
                maximumBaseCurlDegrees = 60f,

                minimumTipCurlDegrees1 = 119f,
                maximumTipCurlDegrees1 = 169f,
                minimumTipCurlDegrees2 = 129f,
                maximumTipCurlDegrees2 = 180f,

                minimumPinchDistance = -1f,
                maximumPinchDistance = -1f,

                minimumSpreadDegrees = 3f,
                maximumSpreadDegrees = 57f,
            };

            static internal readonly XRFingerShapeConfiguration k_Index = new XRFingerShapeConfiguration
            {
                minimumFullCurlDegrees1 = 102f,
                maximumFullCurlDegrees1 = 180f,
                minimumFullCurlDegrees2 = 90f,
                maximumFullCurlDegrees2 = 174f,
                minimumFullCurlDegrees3 = 120f,
                maximumFullCurlDegrees3 = 180f,

                minimumBaseCurlDegrees = 102f,
                maximumBaseCurlDegrees = 180f,

                minimumTipCurlDegrees1 = 90f,
                maximumTipCurlDegrees1 = 174f,
                minimumTipCurlDegrees2 = 120f,
                maximumTipCurlDegrees2 = 180f,

                minimumPinchDistance = 0.01f,
                maximumPinchDistance = 0.045f,

                minimumSpreadDegrees = 3f,
                maximumSpreadDegrees = 18f,
            };

            static internal readonly XRFingerShapeConfiguration k_Middle = new XRFingerShapeConfiguration
            {
                minimumFullCurlDegrees1 = 92f,
                maximumFullCurlDegrees1 = 180f,
                minimumFullCurlDegrees2 = 90f,
                maximumFullCurlDegrees2 = 174f,
                minimumFullCurlDegrees3 = 116f,
                maximumFullCurlDegrees3 = 180f,

                minimumBaseCurlDegrees = 92f,
                maximumBaseCurlDegrees = 180f,

                minimumTipCurlDegrees1 = 90f,
                maximumTipCurlDegrees1 = 174f,
                minimumTipCurlDegrees2 = 116f,
                maximumTipCurlDegrees2 = 180f,

                minimumPinchDistance = 0.01f,
                maximumPinchDistance = 0.045f,

                minimumSpreadDegrees = 3f,
                maximumSpreadDegrees = 20f,
            };

            static internal readonly XRFingerShapeConfiguration k_Ring = new XRFingerShapeConfiguration
            {
                minimumFullCurlDegrees1 = 90f,
                maximumFullCurlDegrees1 = 180f,
                minimumFullCurlDegrees2 = 90f,
                maximumFullCurlDegrees2 = 174f,
                minimumFullCurlDegrees3 = 112f,
                maximumFullCurlDegrees3 = 180f,

                minimumBaseCurlDegrees = 95f,
                maximumBaseCurlDegrees = 180f,

                minimumTipCurlDegrees1 = 90f,
                maximumTipCurlDegrees1 = 174f,
                minimumTipCurlDegrees2 = 112f,
                maximumTipCurlDegrees2 = 180f,

                minimumPinchDistance = 0.01f,
                maximumPinchDistance = 0.045f,

                minimumSpreadDegrees = 3f,
                maximumSpreadDegrees = 20f,
            };

            static internal readonly XRFingerShapeConfiguration k_Little = new XRFingerShapeConfiguration
            {
                minimumFullCurlDegrees1 = 90f,
                maximumFullCurlDegrees1 = 180f,
                minimumFullCurlDegrees2 = 90f,
                maximumFullCurlDegrees2 = 164f,
                minimumFullCurlDegrees3 = 116f,
                maximumFullCurlDegrees3 = 180f,

                minimumBaseCurlDegrees = 95f,
                maximumBaseCurlDegrees = 180f,

                minimumTipCurlDegrees1 = 90f,
                maximumTipCurlDegrees1 = 164f,
                minimumTipCurlDegrees2 = 116f,
                maximumTipCurlDegrees2 = 180f,

                minimumPinchDistance = 0.01f,
                maximumPinchDistance = 0.045f,

                minimumSpreadDegrees = -1f,
                maximumSpreadDegrees = -1f,
            };
        }
    }
}
