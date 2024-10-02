using System;
using System.Collections.Generic;
using Unity.Collections;
using Unity.Collections.LowLevel.Unsafe;
using UnityEngine.SubsystemsImplementation;
using UnityEngine.XR.Hands.Gestures;
using UnityEngine.XR.Hands.Processing;
using UnityEngine.XR.Hands.ProviderImplementation;

namespace UnityEngine.XR.Hands
{
    /// <summary>
    /// A subsystem for detecting and tracking hands and their corresponding
    /// joint pose data.
    /// </summary>
    /// <remarks>
    /// The <c>XRHandSubsystem</c> class is the main entry point for accessing hand tracking data
    /// provided by an XR device. A provider implementation that reads tracking data from the
    /// user's device and provides updates to this subsystem must also be available. The XR
    /// Hands package includes a provider implementation for OpenXR.
    ///
    /// Get an instance for this <c>XRHandSubsystem</c> from the active XR
    /// loader, as described in [Get the XRHandSubsystem instance](xref:xrhands-access-data#get-instance).
    /// 
    /// For lowest latency, read the tracking data available from the <see cref="leftHand"/>
    /// and <see cref="rightHand"/> properties in a delegate function assigned to the
    /// <see cref="updatedHands"/> callback. This callback is invoked twice per frame, once near
    /// the <c>MonoBehaviour.Update</c> event and once near the <see cref="Application.onBeforeRender"/>
    /// event. The <see cref="UpdateType.BeforeRender"/> update provides the lowest latency between
    /// hand motion and rendering, but occurs too late to affect physics. In addition, trying to
    /// perform too much work during the <c>BeforeRender</c> callback can negatively impact framerate.
    /// For best results, update game logic affected by hand tracking in a
    /// <see cref="UpdateType.Dynamic"/> update and perform a final update of hand visuals in a
    /// <see cref="UpdateType.BeforeRender"/> update.
    ///
    /// Refer to [Hand tracking data](xref:xrhands-tracking-data) for more information.
    /// </remarks>
    public partial class XRHandSubsystem
        : SubsystemWithProvider<XRHandSubsystem, XRHandSubsystemDescriptor, XRHandSubsystemProvider>
    {
        /// <summary>
        /// Constructs a subsystem. Do not invoke directly.
        /// </summary>
        /// <remarks>
        /// Do not call this constructor if you are an application developer consuming hand tracking data.
        /// Instead, get an instance for this <c>XRHandTrackingSubsystem</c> from the active XR
        /// loader, as described in [Get the XRHandSubsystem instance](xref:xrhands-access-data#get-instance).
        ///
        /// If you are implementing an XR hand data provider, call <c>Create</c>
        /// on the <see cref="XRHandSubsystemDescriptor"/> or call
        /// <see cref="UnityEngine.XR.Management.XRLoaderHelper.CreateSubsystem"/>
        /// instead of invoking this constructor.
        /// </remarks>
        public XRHandSubsystem()
        {
        }

        /// <summary>
        /// Gets the left <see cref="XRHand"/> that is being tracked by this
        /// subsystem.
        /// </summary>
        /// <remarks>
        /// Check the <see cref="updateSuccessFlags"/> property to determine what data
        /// associated with this hand was successfully updated in the last update, if any.
        /// The <see cref="updateSuccessFlags"/> value is also passed to the callback
        /// function assigned to <see cref="updatedHands"/>.
        ///
        /// Refer to [Hand data model](xref:xrhands-data-model) for a description of the
        /// available hand tracking data.
        /// </remarks>
        public XRHand leftHand => m_LeftHand;
        XRHand m_LeftHand;

        internal unsafe void SetLeftHand(XRHand hand)
        {
            if (hand.m_Joints.GetUnsafePtr() != m_LeftHand.m_Joints.GetUnsafePtr())
                throw new InvalidOperationException("Cannot overrwrite the left hand with a hand that was not first retrieved from the subsystem's leftHand property!");
            m_LeftHand = hand;
        }

        /// <summary>
        /// Gets the right <see cref="XRHand"/> that is being tracked by this
        /// subsystem.
        /// </summary>
        /// <remarks>
        /// Check the <see cref="updateSuccessFlags"/> property to determine what data
        /// associated with this hand was successfully updated in the last update, if any.
        /// The <see cref="updateSuccessFlags"/> value is also passed to the callback
        /// function assigned to <see cref="updatedHands"/>.
        ///
        /// Refer to [Hand data model](xref:xrhands-data-model) for a description of the
        /// available hand tracking data.
        /// </remarks>
        public XRHand rightHand => m_RightHand;
        XRHand m_RightHand;

        internal unsafe void SetRightHand(XRHand hand)
        {
            if (hand.m_Joints.GetUnsafePtr() != m_RightHand.m_Joints.GetUnsafePtr())
                throw new InvalidOperationException("Cannot overrwrite the right hand with a hand that was not first retrieved from the subsystem's rightHand property!");
            m_RightHand = hand;
        }

        /// <summary>
        /// Indicates which joints in the <see cref="XRHandJointID"/> list are
        /// supported by the current hand data provider.
        /// </summary>
        /// <remarks>
        /// Hand data providers might not support tracking every joint in the
        /// <see cref="XRHandJointID"/> list. This array contains an element for
        /// each possible joint. A value of true indicates the the current provider
        /// supports tracking the associated joint.
        /// 
        /// To get the correct array index for a joint, call
        /// <see cref="XRHandJointIDUtility.ToIndex(XRHandJointID)"/> on the
        /// <see cref="XRHandJointID"/> in question.
        ///
        /// Refer to [Get supported joints array](xref:xrhands-access-data#joint-layout)
        /// for additional information.
        /// 
        /// This array will already be valid as soon as you have a reference to
        /// a subsystem (in other words, it's filled out before the subsystem is
        /// returned by a call to <c>XRHandSubsystemDescriptor.Create</c>).
        /// </remarks>
        public NativeArray<bool> jointsInLayout => m_JointsInLayout;
        NativeArray<bool> m_JointsInLayout;

        /// <summary>
        /// Describes what data on either hand was updated during the most recent hand update.
        /// </summary>
        /// <remarks>
        /// This property updated every time the hand data is updated, which only occurs while this
        /// XRHandSubsystem is running.
        /// 
        /// The <see cref="updateSuccessFlags"/> value is also passed to the callback
        /// function assigned to <see cref="updatedHands"/>.
        /// </remarks>
        /// <value>The flags for the most recent update. Applies to the <see cref="leftHand"/>
        /// and <see cref="rightHand"/> properties.</value>
        public UpdateSuccessFlags updateSuccessFlags { get; protected set; }

        /// <summary>
        /// Describes what data on either hand was updated during the call.
        /// </summary>
        /// <seealso cref="updateSuccessFlags"/>
        [Flags]
        public enum UpdateSuccessFlags
        {
            /// <summary>
            /// No data was successfully updated for either hand.
            /// </summary>
            None = 0,

            /// <summary>
            /// The root pose of <see cref="XRHandSubsystem.leftHand"/> was updated.
            /// </summary>
            LeftHandRootPose = 1 << 0,

            /// <summary>
            /// The joints in <see cref="XRHandSubsystem.leftHand"/> were updated.
            /// </summary>
            LeftHandJoints = 1 << 1,

            /// <summary>
            /// The root pose of <see cref="XRHandSubsystem.rightHand"/> was updated.
            /// </summary>
            RightHandRootPose = 1 << 2,

            /// <summary>
            /// The joints in <see cref="XRHandSubsystem.rightHand"/> were updated.
            /// </summary>
            RightHandJoints = 1 << 3,

            /// <summary>
            /// All possible valid data retrieved (hand root poses, and joints for both hands).
            /// </summary>
            All = LeftHandRootPose | LeftHandJoints | RightHandRootPose | RightHandJoints
        }

        /// <summary>
        /// The timing of a hand update during a frame.
        /// </summary>
        /// <seealso cref="updatedHands"/>
        /// <seealso cref="TryUpdateHands(UpdateType)"/>
        public enum UpdateType
        {
            /// <summary>
            /// Corresponds to timing similar or close to <c>MonoBehaviour.Update</c>.
            /// </summary>
            Dynamic,

            /// <summary>
            /// Corresponds to timing similar or close to <see cref="Application.onBeforeRender"/>.
            /// </summary>
            BeforeRender
        }

        /// <summary>
        /// A callback invoked for each hand update.
        /// </summary>
        /// <remarks>
        /// This callback is invoked twice per frame, once near
        /// the <c>MonoBehaviour.Update</c> event and once near the <see cref="Application.onBeforeRender"/>
        /// event. The <see cref="UpdateType.BeforeRender"/> update provides the lowest latency between
        /// hand motion and rendering, but occurs too late to affect physics. In addition, trying to
        /// perform too much work during the <c>BeforeRender</c> callback can negatively impact framerate.
        /// For best results, update game logic affected by hand tracking in a
        /// <see cref="UpdateType.Dynamic"/> update and update hand visuals in a
        /// <see cref="UpdateType.BeforeRender"/> update.
        ///
        /// The delegate assigned to this property must take three parameters, which have the
        /// following types and assigned values when the callback is invoked:
        ///
        /// * <see cref="XRHandSubsystem"/>: contains a reference to this subsystem.
        /// * <see cref="UpdateSuccessFlags"/>: the flags indicating which data could be updated.
        /// * <see cref="UpdateType"/>: the update timing.
        /// </remarks>
        public Action<XRHandSubsystem, UpdateSuccessFlags, UpdateType> updatedHands;

        /// <summary>
        /// A callback invoked when the subsystem begins tracking a hand's root pose and joints.
        /// </summary>
        /// <remarks>
        /// This is called before <see cref="updatedHands"/>.
        ///
        /// The delegate assigned to this property must take one parameter of type
        /// <see cref="XRHand"/>, which is assigned a reference to the hand whose tracking was acquired.
        /// </remarks>
        public Action<XRHand> trackingAcquired;

        /// <summary>
        /// A callback invoked when the subsystem stops tracking a hand's root pose and joints.
        /// </summary>
        /// <remarks>
        /// This is called before <see cref="updatedHands"/>.
        /// 
        /// The delegate assigned to this property must take one parameter of type
        /// <see cref="XRHand"/>, which is assigned a reference to the hand whose tracking was lost.
        /// </remarks>
        public Action<XRHand> trackingLost;

        /// <summary>
        /// Request an update from the hand data provider. Application developers
        /// consuming hand tracking data should not call this function. 
        /// </summary>
        /// <param name="updateType">
        /// Informs the provider which kind of timing the update is being
        /// requested under.
        /// </param>
        /// <returns>
        /// Returns <see cref="UpdateSuccessFlags"/> to describe what data was updated successfully.
        /// </returns>
        /// <remarks>
        /// This function must be called by the subsystem implementation to request an update from
        /// the hand data provider.
        ///
        /// When an update is complete, the updated data is available from the <see cref="leftHand"/> and
        /// <see cref="rightHand"/> properties. The <see cref="updatedHands"/> callback is invoked.
        ///
        /// The update is performed immediately. If you request an update timing that occurs in the
        /// future, for example, requesting <see cref="UpdateType.BeforeRender"/> from a
        /// <c>MonoBehaviour.Update</c> function, then the provider predicts what the hand data
        /// will be at the requested time.
        /// 
        /// If overriding this method in a derived type, it is expected that you
        /// call <c>base.TryUpdateHands(updateType)</c> and return what it
        /// returns.
        /// </remarks>
        public virtual unsafe UpdateSuccessFlags TryUpdateHands(UpdateType updateType)
        {
            if (!running)
                return UpdateSuccessFlags.None;

            updateSuccessFlags = provider.TryUpdateHands(
                updateType,
                ref m_LeftHand.m_RootPose,
                m_LeftHand.m_Joints,
                ref m_RightHand.m_RootPose,
                m_RightHand.m_Joints);

            XRFingerShapeMath.ClearFingerStateCache(Handedness.Left);
            XRFingerShapeMath.ClearFingerStateCache(Handedness.Right);

            var wasLeftHandTracked = m_LeftHand.isTracked;
            var success = UpdateSuccessFlags.LeftHandRootPose | UpdateSuccessFlags.LeftHandJoints;
            m_LeftHand.isTracked = (updateSuccessFlags & success) == success;
            if (!wasLeftHandTracked && m_LeftHand.isTracked)
                trackingAcquired?.Invoke(m_LeftHand);
            else if (wasLeftHandTracked && !m_LeftHand.isTracked)
                trackingLost?.Invoke(m_LeftHand);

            var wasRightHandTracked = m_RightHand.isTracked;
            success = UpdateSuccessFlags.RightHandRootPose | UpdateSuccessFlags.RightHandJoints;
            m_RightHand.isTracked = (updateSuccessFlags & success) == success;
            if (!wasRightHandTracked && m_RightHand.isTracked)
                trackingAcquired?.Invoke(m_RightHand);
            else if (wasRightHandTracked && !m_RightHand.isTracked)
                trackingLost?.Invoke(m_RightHand);

            preprocessJoints?.Invoke(this, updateSuccessFlags, updateType);

            for (int processorIndex = 0; processorIndex < m_Processors.Count; ++processorIndex)
                m_Processors[processorIndex].ProcessJoints(this, updateSuccessFlags, updateType);

            if (updatedHands != null)
                updatedHands.Invoke(this, updateSuccessFlags, updateType);

#pragma warning disable 618
            if (handsUpdated != null)
                handsUpdated.Invoke(updateSuccessFlags, updateType);
#pragma warning restore 618

            return updateSuccessFlags;
        }

        /// <summary>
        /// This is called after the subsystem retrieves joint data from the
        /// provider, and before and <see cref="IXRHandProcessor"/>s'
        /// <see cref="IXRHandProcessor.ProcessJoints"/> are called.
        /// </summary>
        public Action<XRHandSubsystem, UpdateSuccessFlags, UpdateType> preprocessJoints;

        /// <summary>
        /// Registers a processor for hand joint data.
        /// </summary>
        /// <param name="processor">
        /// The processor to register for this <see cref="XRHandSubsystem"/>.
        /// </param>
        /// <typeparam name="TProcessor">
        /// The type of the processor to register.
        /// </typeparam>
        public void RegisterProcessor<TProcessor>(TProcessor processor)
            where TProcessor : class, IXRHandProcessor
        {
            if (processor == null)
                throw new ArgumentException("Processor cannot be null.", nameof(processor));

            m_Processors.Add(processor);
            m_Processors.Sort(CompareProcessors);
        }

        /// <summary>
        /// Unregisters a processor for hand joint data.
        /// </summary>
        /// <param name="processor">
        /// The processor to unregister from this <see cref="XRHandSubsystem"/>.
        /// </param>
        /// <typeparam name="TProcessor">
        /// The type of the processor to register.
        /// </typeparam>
        public void UnregisterProcessor<TProcessor>(TProcessor processor)
            where TProcessor : class, IXRHandProcessor
        {
            m_Processors.Remove(processor);
        }

        /// <summary>
        /// Called by Unity before the subsystem is returned from a call to <c>XRHandSubsystemDescriptor.Create</c>.
        /// </summary>
        protected override void OnCreate()
        {
            m_JointsInLayout = new NativeArray<bool>(XRHandJointID.EndMarker.ToIndex(), Allocator.Persistent);
            provider.GetHandLayout(m_JointsInLayout);

            m_LeftHand = new XRHand(Handedness.Left, Allocator.Persistent);
            m_RightHand = new XRHand(Handedness.Right, Allocator.Persistent);

            for (int jointIndex = XRHandJointID.BeginMarker.ToIndex(); jointIndex < XRHandJointID.EndMarker.ToIndex(); ++jointIndex)
            {
                if (!m_JointsInLayout[jointIndex])
                {
                    var id = XRHandJointIDUtility.FromIndex(jointIndex);
                    m_LeftHand.m_Joints[jointIndex] = XRHandProviderUtility.CreateJoint(
                        Handedness.Left,
                        XRHandJointTrackingState.WillNeverBeValid,
                        id,
                        Pose.identity);
                    m_RightHand.m_Joints[jointIndex] = XRHandProviderUtility.CreateJoint(
                        Handedness.Right,
                        XRHandJointTrackingState.WillNeverBeValid,
                        id,
                        Pose.identity);
                }
            }

            for (var fingerID = XRHandFingerID.Thumb; fingerID <= XRHandFingerID.Little; ++fingerID)
                XRFingerShapeMath.SetDefaultFingerShapeConfiguration(fingerID, provider.GetFingerShapeConfiguration(fingerID));
        }

        /// <summary>
        /// Called by Unity before the subsystem is fully destroyed during a call to <c>XRHandSubsystem.Destroy</c>.
        /// </summary>
        protected override void OnDestroy()
        {
            base.OnDestroy();
            m_LeftHand.Dispose();
            m_RightHand.Dispose();
            m_JointsInLayout.Dispose();
        }

        List<IXRHandProcessor> m_Processors = new List<IXRHandProcessor>();

        static int CompareProcessors(IXRHandProcessor a, IXRHandProcessor b)
            => a.callbackOrder.CompareTo(b.callbackOrder);
    }
}
