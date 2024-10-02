using System;
using System.Collections.Generic;
using Unity.XR.CoreUtils.Bindings.Variables;
using UnityEngine.Events;

namespace UnityEngine.XR.Hands
{
    /// <summary>
    /// Event type that contains a reference to an XR Hand that was updated.
    /// </summary>
    [Serializable]
    public sealed class HandUpdatedEvent : UnityEvent<XRHandJointsUpdatedEventArgs>
    {
    }

    /// <summary>
    /// Extension methods to check if a flag is set in the <see cref="XRHandTrackingEvents.UpdateTypes"/> enum.
    /// </summary>
    public static class UpdateTypesExtensions
    {
        /// <summary>
        /// Checks if the specific flag is set in this flags enum.
        /// </summary>
        /// <param name="self">The flags.</param>
        /// <param name="flag">The flag to check for.</param>
        /// <returns>Returns <see langword="true"/> if the flag is set in this flags enum.</returns>
        public static bool IsSet(this XRHandTrackingEvents.UpdateTypes self, XRHandTrackingEvents.UpdateTypes flag)
        {
            return (self & flag) == flag;
        }
    }

    /// <summary>
    /// Component that subscribes to hand tracking events from the <see cref="XRHandSubsystem"/> for a particular
    /// <see cref="Handedness"/> and sends UnityEvents for tracking updates.
    /// </summary>
    [HelpURL(XRHelpURLConstants.k_XRHandTrackingEvents)]
    public class XRHandTrackingEvents : MonoBehaviour
    {
        /// <summary>
        /// Flags enum that specifies which update type or types to send events for.
        /// </summary>
        /// <seealso cref="updateType"/>
        /// <seealso cref="XRHandSubsystem.UpdateType"/>
        [Flags]
        public enum UpdateTypes
        {
            /// <summary>
            /// No update type. Will not send events.
            /// </summary>
            None = 0,

            /// <summary>
            /// See <see cref="XRHandSubsystem.UpdateType.Dynamic"/>
            /// </summary>
            Dynamic = 1 << 0,

            /// <summary>
            /// See <see cref="XRHandSubsystem.UpdateType.BeforeRender"/>
            /// </summary>
            BeforeRender = 1 << 1,
        }

        [SerializeField]
        [Tooltip("The hand to track and send events for.")]
        Handedness m_Handedness = Handedness.Right;

        [SerializeField]
        [Tooltip("The update type to send events for when the pose and joints are updated.")]
        UpdateTypes m_UpdateType = UpdateTypes.Dynamic;

        [SerializeField]
        UnityEvent<Pose> m_PoseUpdated = new UnityEvent<Pose>();
        
        [SerializeField]
        HandUpdatedEvent m_JointsUpdated = new HandUpdatedEvent();

        [SerializeField]
        UnityEvent m_TrackingAcquired = new UnityEvent();

        [SerializeField]
        UnityEvent m_TrackingLost = new UnityEvent();

        [SerializeField]
        UnityEvent<bool> m_TrackingChanged = new UnityEvent<bool>();

        /// <summary>
        /// The hand to track and send events for.
        /// </summary>
        public Handedness handedness
        {
            get => m_Handedness;
            set => m_Handedness = value;
        }

        /// <summary>
        /// Which update type to send events for when the pose and joints are updated.
        /// This can be one or multiple options from <see cref="XRHandSubsystem.UpdateType"/>.
        /// </summary>
        /// <seealso cref="UpdateTypes"/>
        public UpdateTypes updateType
        {
            get => m_UpdateType;
            set => m_UpdateType = value;
        }

        /// <summary>
        /// Whether the hand is currently being tracked, stored as a bindable variable that can be subscribed to for value changes. 
        /// </summary>
        public IReadOnlyBindableVariable<bool> bindableHandIsTracked => m_HandIsTracked;

        /// <summary>
        /// Whether the hand is currently being tracked
        /// </summary>
        public bool handIsTracked => m_Subsystem != null && m_Subsystem.running && m_HandIsTracked.Value;

        /// <summary>
        /// The root pose of the hand.
        /// </summary>
        public Pose rootPose => m_HandJointsUpdatedEventArgs.hand.rootPose;
        
        /// <summary>
        /// Event that occurs when the joints of the hands have updated.
        /// </summary>
        /// <remarks>
        /// The <see cref="XRHandJointsUpdatedEventArgs"/> passed to each listener is only valid while the event is invoked,
        /// do not hold a reference to it.
        /// </remarks>
        public HandUpdatedEvent jointsUpdated => m_JointsUpdated;
        
        /// <summary>
        /// Event that occurs when the pose of the hands has updated.
        /// </summary>
        public UnityEvent<Pose> poseUpdated => m_PoseUpdated;

        /// <summary>
        /// Event that occurs when the hand tracking is acquired.
        /// </summary>
        public UnityEvent trackingAcquired => m_TrackingAcquired;

        /// <summary>
        /// Event that occurs when the hand tracking is lost.
        /// </summary>
        public UnityEvent trackingLost => m_TrackingLost;

        /// <summary>
        /// Event that occurs when the hand tracking is acquired (true) or lost (false).
        /// </summary>
        public UnityEvent<bool> trackingChanged => m_TrackingChanged;

        static readonly List<XRHandSubsystem> k_SubsystemsReuse = new List<XRHandSubsystem>();
        readonly BindableVariable<bool> m_HandIsTracked = new BindableVariable<bool>();

        XRHandSubsystem m_Subsystem;
        readonly XRHandJointsUpdatedEventArgs m_HandJointsUpdatedEventArgs = new XRHandJointsUpdatedEventArgs();

        /// <summary>
        /// See <see cref="MonoBehaviour"/>.
        /// </summary>
        protected virtual void Update()
        {
            if (m_Subsystem != null && m_Subsystem.running)
                return;

            SubsystemManager.GetSubsystems(k_SubsystemsReuse);
            for (var i = 0; i < k_SubsystemsReuse.Count; ++i)
            {
                var handSubsystem = k_SubsystemsReuse[i];
                if (handSubsystem.running)
                {
                    SetSubsystem(handSubsystem);
                    break;
                }
            }
        }

        /// <summary>
        /// See <see cref="MonoBehaviour"/>.
        /// </summary>
        protected virtual void OnDisable()
        {
            UnsubscribeFromSubsystem();
        }

        void UnsubscribeFromSubsystem()
        {
            if (m_Subsystem != null)
            {
                m_Subsystem.trackingAcquired -= OnTrackingAcquired;
                m_Subsystem.trackingLost -= OnTrackingLost;
                m_Subsystem.updatedHands -= OnUpdatedHands;
                m_Subsystem = null;
            }
        }

        internal void SetSubsystem(XRHandSubsystem handSubsystem)
        {
            UnsubscribeFromSubsystem();
            
            m_Subsystem = handSubsystem;

            XRHand hand;
            if (m_Handedness == Handedness.Left)
                hand = m_Subsystem.leftHand;
            else if (m_Handedness == Handedness.Right)
                hand = m_Subsystem.rightHand;
            else
                hand = default;

            m_HandJointsUpdatedEventArgs.hand = hand;

            m_Subsystem.trackingAcquired += OnTrackingAcquired;
            m_Subsystem.trackingLost += OnTrackingLost;
            m_Subsystem.updatedHands += OnUpdatedHands;

            TrackingAcquiredOrLost(hand.isTracked);
        }

        void OnTrackingAcquired(XRHand hand)
        {
            if (hand.handedness == m_Handedness)
                TrackingAcquiredOrLost(true);
        }

        void OnTrackingLost(XRHand hand)
        {
            if (hand.handedness == m_Handedness)
                TrackingAcquiredOrLost(false);
        }

        void TrackingAcquiredOrLost(bool isTracked)
        {
            m_HandIsTracked.Value = isTracked;
            if (m_HandIsTracked.Value)
                m_TrackingAcquired?.Invoke();
            else
                m_TrackingLost?.Invoke();
            
            m_TrackingChanged?.Invoke(isTracked);
        }

        void OnUpdatedHands(XRHandSubsystem subsystem, XRHandSubsystem.UpdateSuccessFlags updateSuccessFlags, XRHandSubsystem.UpdateType updateEventType)
        {
            if (updateEventType == XRHandSubsystem.UpdateType.Dynamic && !m_UpdateType.IsSet(UpdateTypes.Dynamic)
                || updateEventType == XRHandSubsystem.UpdateType.BeforeRender && !m_UpdateType.IsSet(UpdateTypes.BeforeRender))
                return;

            if (m_Handedness == Handedness.Left)
            {
                var leftJointsUpdated = (updateSuccessFlags & XRHandSubsystem.UpdateSuccessFlags.LeftHandJoints) != XRHandSubsystem.UpdateSuccessFlags.None;
                var leftRootPoseUpdated = (updateSuccessFlags & XRHandSubsystem.UpdateSuccessFlags.LeftHandRootPose) != XRHandSubsystem.UpdateSuccessFlags.None;

                if (leftJointsUpdated || leftRootPoseUpdated)
                    m_HandJointsUpdatedEventArgs.hand = m_Subsystem.leftHand;

                if (leftJointsUpdated)
                    m_JointsUpdated?.Invoke(m_HandJointsUpdatedEventArgs);

                if (leftRootPoseUpdated)
                    m_PoseUpdated?.Invoke(m_HandJointsUpdatedEventArgs.hand.rootPose);
            }
            else if (m_Handedness == Handedness.Right)
            {
                var rightJointsUpdated = (updateSuccessFlags & XRHandSubsystem.UpdateSuccessFlags.RightHandJoints) != XRHandSubsystem.UpdateSuccessFlags.None;
                var rightRootPoseUpdated = (updateSuccessFlags & XRHandSubsystem.UpdateSuccessFlags.RightHandRootPose) != XRHandSubsystem.UpdateSuccessFlags.None;

                if (rightJointsUpdated || rightRootPoseUpdated)
                    m_HandJointsUpdatedEventArgs.hand = m_Subsystem.rightHand;

                if (rightJointsUpdated)
                    m_JointsUpdated?.Invoke(m_HandJointsUpdatedEventArgs);

                if (rightRootPoseUpdated)
                    m_PoseUpdated?.Invoke(m_HandJointsUpdatedEventArgs.hand.rootPose);
            }
        }
    }
}
