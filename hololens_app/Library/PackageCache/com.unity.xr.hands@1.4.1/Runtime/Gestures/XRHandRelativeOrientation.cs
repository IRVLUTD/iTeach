using System;
using Unity.Burst;
using Unity.Mathematics;

namespace UnityEngine.XR.Hands.Gestures
{
    /// <summary>
    /// Defines hand orientation relative to the user and a target <c>Transform</c>.
    /// </summary>
    [Serializable]
    public class XRHandRelativeOrientation
    {
        /// <summary>
        /// A condition that can be used to check the orientation of a hand relative to the user's head
        /// or the tracking origin.
        /// </summary>
#if BURST_PRESENT
        [BurstCompile]
#endif
        [Serializable]
        public class UserCondition
        {
            /// <summary>
            /// The <see cref="XRHandAxis"/> that is used to compare to the direction relative to the target.
            /// </summary>
            public XRHandAxis handAxis
            {
                get => m_HandAxis;
                set => m_HandAxis = value;
            }

            /// <summary>
            /// The <see cref="AlignmentCondition"/> used to evaluate the condition.
            /// </summary>
            public XRHandAlignmentCondition alignmentCondition
            {
                get => m_AlignmentCondition;
                set => m_AlignmentCondition = value;
            }

            /// <summary>
            /// The <see cref="XRHandUserRelativeDirection"/> to compare to the <see cref="handAxis"/> for this condition.
            /// </summary>
            public XRHandUserRelativeDirection referenceDirection
            {
                get => m_ReferenceDirection;
                set => m_ReferenceDirection = value;
            }

            /// <summary>
            /// If the <see cref="alignmentCondition"/> is <see cref="AlignmentCondition.AlignsWith"/>, 
            /// this is the maximum angle between the <see cref="handAxis"/> and the reference direction for the condition to be met.
            ///
            /// If the <see cref="alignmentCondition"/> is <see cref="AlignmentCondition.OppositeTo"/>,
            /// this is the maximum angle between the <see cref="handAxis"/> and the opposite of the reference direction for the condition to be met.
            /// 
            /// If the <see cref="alignmentCondition"/> is <see cref="AlignmentCondition.PerpendicularTo"/>,
            /// this is the maximum angle difference from 90 degrees (perpendicular) between the <see cref="handAxis"/> and the reference direction for the condition to be met.
            /// </summary>
            public float angleTolerance
            {
                get => m_AngleTolerance;
                set => m_AngleTolerance = value;
            }

            /// <summary>
            /// If enabled, the y position will be ignored when referencing a direction relative to another position.
            /// </summary>
            public bool ignorePositionY
            {
                get => m_IgnorePositionY;
                set => m_IgnorePositionY = value;
            }

            internal bool CheckCondition(
                in float3 rootPosition, in quaternion rootRotation,
                in RigidTransform originTransform, in RigidTransform headTransform,
                float handednessMultiplier)
            {
                return CheckConditionBursted(
                    m_HandAxis, m_AlignmentCondition, m_ReferenceDirection,
                    m_AngleTolerance,
                    rootPosition, rootRotation,
                    originTransform, headTransform,
                    m_IgnorePositionY,
                    handednessMultiplier);
            }

#if BURST_PRESENT
            [BurstCompile]
#endif
            static bool CheckConditionBursted(
                XRHandAxis handAxis,
                XRHandAlignmentCondition alignmentCondition,
                XRHandUserRelativeDirection referenceDirection,
                float tolerance,
                in float3 rootPosition, in quaternion rootRotation,
                in RigidTransform originTransform,
                in RigidTransform headTransform,
                bool ignorePositionY, float handednessMultiplier)
            {
                XRHandOrientationUtility.GetHandAxisDirection(
                    out var calculatedHandAxisDirection,
                    handAxis,
                    rootRotation,
                    handednessMultiplier);

                GetReferenceDirection(
                    out var calculatedReferenceDirection,
                    rootPosition,
                    referenceDirection,
                    originTransform,
                    headTransform,
                    handednessMultiplier);

                return XRHandOrientationUtility.CheckDirectionAlignment(
                    alignmentCondition,
                    tolerance,
                    ignorePositionY,
                    calculatedHandAxisDirection,
                    calculatedReferenceDirection);
            }

#if BURST_PRESENT
            [BurstCompile]
#endif
            static void GetReferenceDirection(
                out float3 result,
                in float3 handPosition,
                XRHandUserRelativeDirection direction,
                in RigidTransform handTrackingOrigin,
                in RigidTransform headTransform,
                float handednessMultiplier)
            {
                float3 worldDirection;
                switch (direction)
                {
                    case XRHandUserRelativeDirection.OriginUp:
                        worldDirection = math.rotate(handTrackingOrigin, new float3(0f, 1f, 0f));
                        break;

                    case XRHandUserRelativeDirection.HandToHead:
                        worldDirection = headTransform.pos - math.transform(handTrackingOrigin, handPosition);
                        break;

                    case XRHandUserRelativeDirection.NoseDirection:
                        worldDirection = math.rotate(headTransform, new float3(1f, 0f, 1f));
                        break;

                    case XRHandUserRelativeDirection.ChinDirection:
                        worldDirection = math.rotate(headTransform, new float3(0f, -1f, 0f));
                        break;

                    case XRHandUserRelativeDirection.EarDirection:
                        worldDirection = math.rotate(headTransform, new float3(-handednessMultiplier, 0f, 0f));
                        break;

                    default:
                        worldDirection = new float3(0f, 1f, 0f);
                        break;
                }

                result = math.mul(math.inverse(handTrackingOrigin).rot, worldDirection);
            }

            [SerializeField]
            [Tooltip("The axis of the hand using the OpenXR spec axis mapping for hands.")]
            XRHandAxis m_HandAxis = XRHandAxis.PalmDirection;

            [SerializeField]
            [Tooltip("The method used to compare two directions.")]
            XRHandAlignmentCondition m_AlignmentCondition = XRHandAlignmentCondition.AlignsWith;

            [SerializeField]
            [Tooltip("The axis to compare the hand's axis to.")]
            XRHandUserRelativeDirection m_ReferenceDirection = XRHandUserRelativeDirection.OriginUp;

            [SerializeField]
            [Tooltip("The condition will be true if the angle difference between the hand axis and the reference direction (in degrees) is less than this value.")]
            [Range(XRHandOrientationUtility.k_MinimumAngleTolerance, XRHandOrientationUtility.k_MaximumAngleTolerance)]
            float m_AngleTolerance;

            [SerializeField]
            [Tooltip("If enabled, the y position will be ignored when comparing to a direction relative to another position.")]
            bool m_IgnorePositionY;
        }

        /// <summary>
        /// A condition that can be used to check the orientation of a hand
        /// relative to some other target. The target is another transform
        /// referenced by the <see cref="target"/> property.
        /// </summary>
        /// <remarks>
        /// To check the orientation relative to the user's head or origin, use
        /// <see cref="UserOrientation"/> to avoid the need to set a specific
        /// target transform per condition.
        /// </remarks>
#if BURST_PRESENT
        [BurstCompile]
#endif
        [Serializable]
        public class TargetCondition
        {
            /// <summary>
            /// The <see cref="XRHandAxis"/> that is used to compare to the direction relative to the target.
            /// </summary>
            public XRHandAxis handAxis
            {
                get => m_HandAxis;
                set => m_HandAxis = value;
            }

            /// <summary>
            /// The <see cref="XRHandAlignmentCondition"/> used to evaluate the condition.
            /// </summary>
            public XRHandAlignmentCondition alignmentCondition
            {
                get => m_AlignmentCondition;
                set => m_AlignmentCondition = value;
            }

            /// <summary>
            /// The <see cref="XRHandTargetRelativeDirection"/> to compare to the <see cref="handAxis"/> for this condition.
            /// </summary>
            public XRHandTargetRelativeDirection referenceDirection
            {
                get => m_ReferenceDirection;
                set => m_ReferenceDirection = value;
            }

            /// <summary>
            /// If the <see cref="alignmentCondition"/> is <see cref="XRHandAlignmentCondition.AlignsWith"/>, 
            /// this is the maximum angle between the <see cref="handAxis"/> and the reference direction for the condition to be met.
            ///
            /// If the <see cref="alignmentCondition"/> is <see cref="XRHandAlignmentCondition.OppositeTo"/>,
            /// this is the maximum angle between the <see cref="handAxis"/> and the opposite of the reference direction for the condition to be met.
            /// 
            /// If the <see cref="alignmentCondition"/> is <see cref="XRHandAlignmentCondition.PerpendicularTo"/>,
            /// this is the maximum angle difference from 90 degrees (perpendicular) between the <see cref="handAxis"/> and the reference direction for the condition to be met.
            /// </summary>
            public float angleTolerance
            {
                get => m_AngleTolerance;
                set => m_AngleTolerance = value;
            }

            /// <summary>
            /// If enabled, the Y position will be ignored when referencing a direction relative to another position.
            /// </summary>
            public bool ignorePositionY
            {
                get => m_IgnorePositionY;
                set => m_IgnorePositionY = value;
            }

            internal bool CheckCondition(
                in float3 rootPosition, in quaternion rootRotation,
                in RigidTransform originTransform,
                in RigidTransform targetTransform,
                float handednessMultiplier)
            {
                return CheckConditionBursted(
                    m_HandAxis, m_AlignmentCondition, m_ReferenceDirection,
                    m_AngleTolerance, m_IgnorePositionY,
                    rootPosition, rootRotation,
                    originTransform, targetTransform,
                    handednessMultiplier);
            }

#if BURST_PRESENT
            [BurstCompile]
#endif
            static bool CheckConditionBursted(
                XRHandAxis xrHandAxis,
                XRHandAlignmentCondition condition,
                XRHandTargetRelativeDirection direction,
                float threshold, bool ignorePositionY,
                in float3 rootPosition, in quaternion rootRotation,
                in RigidTransform originTransform, in RigidTransform targetTransform,
                float handednessMultiplier)
            {
                XRHandOrientationUtility.GetHandAxisDirection(
                    out var currentHandAxisDirection,
                    xrHandAxis,
                    rootRotation,
                    handednessMultiplier);

                GetReferenceDirection(
                    out var currentReferenceDirection,
                    rootPosition,
                    direction,
                    originTransform,
                    targetTransform);

                return XRHandOrientationUtility.CheckDirectionAlignment(
                    condition,
                    threshold,
                    ignorePositionY,
                    currentHandAxisDirection,
                    currentReferenceDirection);
            }

#if BURST_PRESENT
            [BurstCompile]
#endif
            static void GetReferenceDirection(
                out float3 result,
                in float3 rootPosition,
                in XRHandTargetRelativeDirection direction,
                in RigidTransform handTrackingOrigin,
                in RigidTransform targetTransform)
            {
                float3 worldDirection;
                switch (direction)
                {
                    case XRHandTargetRelativeDirection.HandToTarget:
                        worldDirection = targetTransform.pos - math.transform(handTrackingOrigin, rootPosition);
                        break;

                    case XRHandTargetRelativeDirection.TargetForward:
                        worldDirection = math.rotate(targetTransform, new float3(0f, 0f, 1f));
                        break;

                    case XRHandTargetRelativeDirection.TargetRight:
                        worldDirection = math.rotate(targetTransform, new float3(1f, 0f, 0f));
                        break;

                    case XRHandTargetRelativeDirection.TargetUp:
                        worldDirection = math.rotate(targetTransform, new float3(0f, 1f, 0f));
                        break;

                    default:
                        worldDirection = new float3(0f, 1f, 0f);
                        break;
                }

                result = math.mul(math.inverse(handTrackingOrigin).rot, worldDirection);
            }

            [SerializeField]
            [Tooltip("The axis of the hand using the OpenXR spec axis mapping for hands.")]
            XRHandAxis m_HandAxis = XRHandAxis.PalmDirection;

            [SerializeField]
            [Tooltip("The method used to compare two directions.")]
            XRHandAlignmentCondition m_AlignmentCondition = XRHandAlignmentCondition.AlignsWith;

            [SerializeField]
            [Tooltip("The axis to compare the hand's axis to.")]
            XRHandTargetRelativeDirection m_ReferenceDirection = XRHandTargetRelativeDirection.HandToTarget;

            [SerializeField]
            [Tooltip("The condition will be true if the angle difference between the hand axis and the reference direction (in degrees) is less than this value.")]
            [Range(XRHandOrientationUtility.k_MinimumAngleTolerance, XRHandOrientationUtility.k_MaximumAngleTolerance)]
            float m_AngleTolerance;

            [SerializeField]
            [Tooltip("If enabled, the y position will be ignored when comparing to a direction relative to another position.")]
            bool m_IgnorePositionY;
        }

        /// <summary>
        /// The list of conditions to check for the hand's orientation, relative to the user.
        /// </summary>
        public UserCondition[] userConditions
        {
            get => m_UserConditions;
            set => m_UserConditions = value;
        }

        [SerializeField]
        [Tooltip("A list of conditions to user to check a hand's orientation, relative to the user.")]
        UserCondition[] m_UserConditions;

        /// <summary>
        /// The list of conditions to check for the hand's orientation, relative to a target <c>Transform</c>.
        /// </summary>
        /// <remarks>
        /// All of these conditions use <see cref="targetTransform"/>.
        /// </remarks>
        public TargetCondition[] targetConditions
        {
            get => m_TargetConditions;
            set => m_TargetConditions = value;
        }

        [SerializeField]
        [Tooltip("A list of the conditions to use to check a hand's orientation, relative to a target Transform.")]
        TargetCondition[] m_TargetConditions;

        /// <summary>
        /// The target transform that the <see cref="targetConditions"/> are relative to.
        /// </summary>
        /// <remarks>
        /// This is not used for <see cref="userConditions"/>.
        /// </remarks>
        public Transform targetTransform
        {
            get => m_TargetTransform;
            set => m_TargetTransform = value;
        }

        Transform m_TargetTransform;

        /// <summary>
        /// Checks the hand orientation conditions to determine whether the hand is in the correct orientation.
        /// </summary>
        /// <param name="rootPose">The root pose of the hand.</param>
        /// <param name="handedness">The handedness of the hand.</param>
        /// <returns>Whether all the conditions are met.</returns>
        public bool CheckConditions(Pose rootPose, Handedness handedness)
        {
            if (!XRHandOrientationUtility.TryGetOriginTransform(out var originTransform) ||
                !XRHandOrientationUtility.TryGetHeadTransform(out var headTransform))
                return false;

            var rootPosePosition = (float3)rootPose.position;
            var rootPoseRotation = (quaternion)rootPose.rotation;
            var originRigidTransform = new RigidTransform(originTransform.rotation, originTransform.position);
            var handednessMultiplier = handedness == Handedness.Right ? -1f : 1f;
            for (var conditionIndex = 0; conditionIndex < m_UserConditions.Length; ++conditionIndex)
            {
                if (!m_UserConditions[conditionIndex].CheckCondition(
                    rootPosePosition, rootPoseRotation,
                    originRigidTransform,
                    new RigidTransform(headTransform.rotation, headTransform.position),
                    handednessMultiplier))
                    return false;
            }

            if (m_TargetTransform == null)
                return true;

            var targetRigidTransform = new RigidTransform(m_TargetTransform.rotation, m_TargetTransform.position);
            for (var conditionIndex = 0; conditionIndex < m_TargetConditions.Length; ++conditionIndex)
            {
                if (!m_TargetConditions[conditionIndex].CheckCondition(
                    rootPosePosition, rootPoseRotation,
                    originRigidTransform, targetRigidTransform,
                    handednessMultiplier))
                    return false;
            }

            return true;
        }
    }
}
