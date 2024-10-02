using System;
using System.Collections.Generic;
using Unity.Collections;
using Unity.XR.CoreUtils;

#if BURST_PRESENT
using Unity.Burst;
#endif

namespace UnityEngine.XR.Hands
{
    /// <summary>
    /// A struct that contains an XR Hand Joint Identifier (<see cref="XRHandJointID"/>) and a reference to the Transform to drive with that joint.
    /// </summary>
    [Serializable]
    public struct JointToTransformReference
    {
        [SerializeField]
        [Tooltip("The XR Hand Joint Identifier that will drive the Transform.")]
        XRHandJointID m_XRHandJointID;

        [SerializeField]
        [Tooltip("The Transform that will be driven by the specified XR Joint.")]
        Transform m_JointTransform;

        /// <summary>
        /// The <see cref="XRHandJointID"/> that will drive the Transform.
        /// </summary>
        public XRHandJointID xrHandJointID
        {
            get => m_XRHandJointID;
            set => m_XRHandJointID = value;
        }

        /// <summary>
        /// The Transform that will be driven by the specified joint's tracking data.
        /// </summary>
        public Transform jointTransform
        {
            get => m_JointTransform;
            set => m_JointTransform = value;
        }
    }

    /// <summary>
    /// Controls a hierarchy of Transforms driven by joints in an <see cref="XRHand"/>.
    /// This component subscribes to events from an <see cref="XRHandTrackingEvents"/> component to move and rotate the joints when the hand is updated.
    /// </summary>
    [HelpURL(XRHelpURLConstants.k_XRHandSkeletonDriver)]
#if BURST_PRESENT
    [BurstCompile]
#endif
    public class XRHandSkeletonDriver : MonoBehaviour, ISerializationCallbackReceiver
    {
        [SerializeField]
        [Tooltip("The XR Hand Tracking Events component that will be used to subscribe to hand tracking events.")]
        XRHandTrackingEvents m_XRHandTrackingEvents;

        [SerializeField]
        [Tooltip("The Transform that will be driven by the hand's root position and rotation.")]
        Transform m_RootTransform;

        /// <summary>
        /// The list of joint to transform references
        /// </summary>
        [SerializeField]
        [Tooltip("List of XR Hand Joints with a reference to a transform to drive.")]
        protected List<JointToTransformReference> m_JointTransformReferences;

        /// <summary>
        /// The array of joint data indexed by the <see cref="XRHandJointID"/> which is accessible via
        /// <see cref="XRHandJointIDUtility.ToIndex"/>.
        /// </summary>
        protected Transform[] m_JointTransforms;

        /// <summary>
        /// An array of booleans tracking which joint indexes have a valid transform to drive. This is calculated once
        /// when the references change to avoid a null check every time the joint is updated.
        /// </summary>
        protected bool[] m_HasJointTransformMask;

        /// <summary>
        /// A boolean tracking whether the root transform is valid. This is calculated once when the root transform
        /// changes to avoid a null check every time the root is updated.
        /// </summary>
        protected bool m_HasRootTransform;

        /// <summary>
        /// The array of joint local poses indexed by the <see cref="XRHandJointID"/> which is updated by the method
        /// <see cref="UpdateJointLocalPoses"/> and then applied to the joint transforms by the
        /// method <see cref="ApplyUpdatedTransformPoses"/>.
        /// </summary>
        protected NativeArray<Pose> m_JointLocalPoses;

        /// <summary>
        /// Offset translation applied to hand root position.
        /// </summary>
        protected virtual Vector3 rootOffset => m_RootOffset;
        
        Vector3 m_RootOffset = Vector3.zero;

        /// <summary>
        /// Bool tracking whether the root requires an offset to be applied to it.
        /// </summary>
        protected virtual bool hasRootOffset => m_HasRootOffset;
        
        bool m_HasRootOffset;

        /// <summary>
        /// The serialized list of <see cref="XRHandJointID"/> with a reference to a transform to drive.
        /// After this list is finished being assigned or modified, use the method
        /// <see cref="InitializeFromSerializedReferences"/> to update the runtime
        /// mapping of transforms to drive.
        /// </summary>
        public List<JointToTransformReference> jointTransformReferences
        {
            get => m_JointTransformReferences;
            set
            {
                m_JointTransformReferences = value;
                InitializeFromSerializedReferences();
            }
        }

        /// <summary>
        /// The Transform that will be driven by the hand's root position and rotation.
        /// </summary>
        public Transform rootTransform
        {
            get => m_RootTransform;
            set
            {
                m_RootTransform = value;
                m_HasRootTransform = m_RootTransform != null;
            }
        }

        /// <summary>
        /// The <see cref="XRHandTrackingEvents"/> component that will be the source of hand tracking events for this driver.
        /// </summary>
        public XRHandTrackingEvents handTrackingEvents
        {
            get => m_XRHandTrackingEvents;
            set
            {
                if (Application.isPlaying)
                    UnsubscribeFromHandTrackingEvents();

                m_XRHandTrackingEvents = value;

                if (Application.isPlaying && isActiveAndEnabled)
                    SubscribeToHandTrackingEvents();
            }
        }

        /// <summary>
        /// See <see cref="MonoBehaviour"/>.
        /// </summary>
        protected virtual void Reset()
        {
            TryGetComponent(out m_XRHandTrackingEvents);
        }

        /// <summary>
        /// See <see cref="MonoBehaviour"/>.
        /// MonoBehaviour OnEnable method that subscribes to hand tracking events and allocates the joint local poses array.
        /// </summary>
        protected virtual void OnEnable()
        {
            m_JointLocalPoses = new NativeArray<Pose>(XRHandJointID.EndMarker.ToIndex(), Allocator.Persistent);

            if (m_XRHandTrackingEvents == null)
                TryGetComponent(out m_XRHandTrackingEvents);

            if (m_XRHandTrackingEvents == null)
            {
                Debug.LogError($"The {nameof(XRHandSkeletonDriver)} requires an {nameof(XRHandTrackingEvents)} component to subscribe to hand tracking events.", this);
                return;
            }

            foreach (var joint in m_JointTransformReferences)
            {
                var jointIndex = joint.xrHandJointID.ToIndex();
                if (jointIndex < 0 || jointIndex >= m_JointTransforms.Length)
                {
                    Debug.LogWarning($"{nameof(XRHandSkeletonDriver)} has an invalid joint reference set: {joint.xrHandJointID}", this);
                }
            }

            SubscribeToHandTrackingEvents();
        }

        /// <summary>
        /// See <see cref="MonoBehaviour"/>.
        /// MonoBehaviour OnDisable method that unsubscribes from hand tracking events and disposes the joint local poses array.
        /// </summary>
        protected virtual void OnDisable()
        {
            if (m_JointLocalPoses.IsCreated)
                m_JointLocalPoses.Dispose();

            UnsubscribeFromHandTrackingEvents();
            ResetRootPoseOffset();
        }

        void UnsubscribeFromHandTrackingEvents()
        {
            if (m_XRHandTrackingEvents != null)
            {
                m_XRHandTrackingEvents.jointsUpdated.RemoveListener(OnJointsUpdated);
                m_XRHandTrackingEvents.poseUpdated.RemoveListener(OnRootPoseUpdated);
            }
        }

        void SubscribeToHandTrackingEvents()
        {
            if (m_XRHandTrackingEvents != null)
            {
                m_XRHandTrackingEvents.jointsUpdated.AddListener(OnJointsUpdated);
                m_XRHandTrackingEvents.poseUpdated.AddListener(OnRootPoseUpdated);
            }
        }

        /// <summary>
        /// Applies an offset to the root pose of the hand skeleton.
        /// This can be used to adjust the position of the hand in situations where you want the hand visual to stop moving when interacting with an object. 
        /// The offset is applied in the local space of the hand's root transform.
        /// </summary>
        /// <param name="rootPoseOffset">A Vector3 representing the offset to apply to the root pose of the hand skeleton.</param>
        public void ApplyRootPoseOffset(Vector3 rootPoseOffset)
        {
            m_RootOffset = m_RootTransform.parent.InverseTransformDirection(rootPoseOffset);
            m_HasRootOffset = true;
        }

        /// <summary>
        /// Resets the offset of the root pose of the hand skeleton back to zero.
        /// This can be used to remove any previously applied offset, restoring the hand's root pose to its original position.
        /// </summary>
        public void ResetRootPoseOffset()
        {
            m_RootOffset = Vector3.zero;
            m_HasRootOffset = false;
        }

        /// <summary>
        /// Update the <see cref="rootTransform"/>'s local position and rotation with the hand's root pose.
        /// </summary>
        /// <param name="rootPose">The root pose of the hand.</param>
        /// <remarks>
        /// Override this method to change how to the root pose is applied to the skeleton.
        /// </remarks>
        protected virtual void OnRootPoseUpdated(Pose rootPose)
        {
            if (!m_HasRootTransform)
                return;

            if (hasRootOffset)
                m_RootTransform.localPosition = rootPose.position + rootOffset;
            else
                m_RootTransform.localPosition = rootPose.position;

            m_RootTransform.localRotation = rootPose.rotation;
        }

        /// <summary>
        /// Updates all the joints of the hand. This method calls <see cref="UpdateJointLocalPoses"/> to
        /// calculate the local poses of the joints and then immediately calls <see cref="ApplyUpdatedTransformPoses"/>
        /// to apply the changes to the joint Transforms.
        /// </summary>
        /// <param name="args">The event arguments for the XRHand joints updated.</param>
        /// <remarks>
        /// Override this method to change either how or when the <see cref="m_JointLocalPoses"/> array is updated and
        /// applied to the transforms.
        /// </remarks>
        protected virtual void OnJointsUpdated(XRHandJointsUpdatedEventArgs args)
        {
            UpdateJointLocalPoses(args);

            ApplyUpdatedTransformPoses();
        }

        /// <summary>
        /// Applies the values in the <see cref="m_JointLocalPoses"/> array to the <see cref="m_JointTransforms"/> array.
        /// </summary>
        /// <remarks>
        /// Override this method to change how the local hand joint poses affect the transforms, such as ignoring position,
        /// or converting to a different coordinate space.
        /// </remarks>
        protected virtual void ApplyUpdatedTransformPoses()
        {
            // Apply the local poses to the joint transforms
            for (var i = 0; i < m_JointTransforms.Length; i++)
            {
                if (m_HasJointTransformMask[i])
                {
#if UNITY_EDITOR || DEVELOPMENT_BUILD
                    if (m_JointTransforms[i] == null)
                    {
                        Debug.LogError("XR Hand Skeleton has detected that a joint transform has been destroyed after it was initialized." +
                            " After removing or modifying transform joint references at runtime it is required to call InitializeFromSerializedReferences to update the joint transform references.", this);

                        continue;
                    }
#endif
                    m_JointTransforms[i].SetLocalPose(m_JointLocalPoses[i]);
                }
            }
        }

        /// <summary>
        /// Calculates the local poses for all the joints in the hand using the standard parent hierarchy.
        /// Call this method to update the <see cref="m_JointLocalPoses"/> array with the latest joint data.
        /// </summary>
        /// <param name="args">The event arguments for the XRHand joints updated.</param>
        protected void UpdateJointLocalPoses(XRHandJointsUpdatedEventArgs args)
        {
            // Calculate the local poses for all the joints, accessing the internal joints array to enable burst compilation when available
            CalculateJointTransformLocalPoses(ref args.hand.m_Joints, ref m_JointLocalPoses);
        }

#if BURST_PRESENT && UNITY_2022_1_OR_NEWER
        [BurstCompile]
#endif
        static void CalculateJointTransformLocalPoses(ref NativeArray<XRHandJoint> joints, ref NativeArray<Pose> jointLocalPoses)
        {
            var wristIndex = XRHandJointID.Wrist.ToIndex();
            if (joints[wristIndex].TryGetPose(out var wristJointPose))
            {
                jointLocalPoses[wristIndex] = wristJointPose;
                var palmIndex = XRHandJointID.Palm.ToIndex();

                if (joints[palmIndex].TryGetPose(out var palmJointPose))
                {
                    CalculateLocalTransformPose(wristJointPose, palmJointPose, out var palmPose);
                    jointLocalPoses[palmIndex] = palmPose;
                }

                for (var fingerIndex = (int)XRHandFingerID.Thumb;
                     fingerIndex <= (int)XRHandFingerID.Little;
                     ++fingerIndex)
                {
                    var parentPose = wristJointPose;
                    var fingerId = (XRHandFingerID)fingerIndex;

                    var jointIndexBack = fingerId.GetBackJointID().ToIndex();
                    var jointIndexFront = fingerId.GetFrontJointID().ToIndex();
                    for (var jointIndex = jointIndexFront;
                         jointIndex <= jointIndexBack;
                         ++jointIndex)
                    {
                        if (joints[jointIndex].TryGetPose(out var fingerJointPose))
                        {
                            CalculateLocalTransformPose(parentPose, fingerJointPose, out var jointLocalPose);
                            parentPose = fingerJointPose;
                            jointLocalPoses[jointIndex] = jointLocalPose;
                        }
                    }
                }
            }
        }

#if BURST_PRESENT
        [BurstCompile]
#endif
        static void CalculateLocalTransformPose(in Pose parentPose, in Pose jointPose, out Pose jointLocalPose)
        {
            var inverseParentRotation = Quaternion.Inverse(parentPose.rotation);
            jointLocalPose.position = inverseParentRotation * (jointPose.position - parentPose.position);
            jointLocalPose.rotation = inverseParentRotation * jointPose.rotation;
        }

        /// <summary>
        /// Converts the serialized list <see cref="jointTransformReferences"/> to a mapping of Transforms to drive.
        /// This method is called automatically via <see cref="ISerializationCallbackReceiver.OnAfterDeserialize"/>.
        /// It can be called manually after the list of Transform references is modified at runtime to apply the changes.
        /// </summary>
        public void InitializeFromSerializedReferences()
        {
            if (m_RootTransform != null)
                m_HasRootTransform = true;

            m_HasJointTransformMask = new bool[XRHandJointID.EndMarker.ToIndex()];
            m_JointTransforms = new Transform[XRHandJointID.EndMarker.ToIndex()];
            foreach (var joint in m_JointTransformReferences)
            {
                var jointIndex = joint.xrHandJointID.ToIndex();
                if (jointIndex >= 0 && jointIndex < m_JointTransforms.Length)
                {
                    m_JointTransforms[jointIndex] = joint.jointTransform;
                    m_HasJointTransformMask[jointIndex] = joint.jointTransform != null;
                }
            }
        }

        /// <summary>
        /// Finds the joint transform references from the root.
        /// </summary>
        /// <remarks>
        /// Override this method to change how the joint transform references are found from the root and setup in the
        /// <see cref="m_JointTransformReferences"/>. This method is called from the default inspector editor UI when
        /// the Find Joints button is clicked.
        /// </remarks>
        /// <param name="missingJointNames">A list of strings to list the joints that were not found.</param>
        public virtual void FindJointsFromRoot(List<string> missingJointNames)
        {
            XRHandSkeletonDriverUtility.FindJointsFromRoot(this, missingJointNames);
        }

        /// <inheritdoc />
        void ISerializationCallbackReceiver.OnBeforeSerialize()
        {
        }

        /// <inheritdoc />
        void ISerializationCallbackReceiver.OnAfterDeserialize()
        {
            InitializeFromSerializedReferences();
        }
    }
}
