using System;
using Unity.Burst;
using Unity.Mathematics;
using Unity.XR.CoreUtils;

namespace UnityEngine.XR.Hands.Gestures
{
    /// <summary>
    /// Utility class for calculating hand orientation.
    /// </summary>
#if BURST_PRESENT
    [BurstCompile]
#endif
    static class XRHandOrientationUtility
    {
        internal const float k_MinimumAngleTolerance = 0.1f;
        internal const float k_MaximumAngleTolerance = 180f;

        internal static bool TryGetOriginTransform(out Transform originTransform)
        {
            bool found = TryEnsureOriginAndHead() && s_OriginTransform != null;
            originTransform = s_OriginTransform;
            return found;
        }

        internal static bool TryGetHeadTransform(out Transform headTransform)
        {
            bool found = TryEnsureOriginAndHead() && s_HeadTransform != null;
            headTransform = s_HeadTransform;
            return found;
        }

        static bool TryEnsureOriginAndHead()
        {
            if (s_Origin != null)
                return true;

#if UNITY_2023_2_OR_NEWER
            s_Origin = Object.FindAnyObjectByType<XROrigin>(FindObjectsInactive.Exclude);
#else
            s_Origin = Object.FindObjectOfType<XROrigin>();
#endif // !UNITY_2023_2_OR_NEWER

            if (s_Origin == null)
                return false;

            s_OriginTransform = s_Origin.Origin.transform;
            s_HeadTransform = s_Origin.Camera.transform;
            return true;
        }

#if BURST_PRESENT
        [BurstCompile]
#endif
        internal static void GetHandAxisDirection(
            out float3 result,
            XRHandAxis handAxis,
            in quaternion rootRotation,
            float handednessMultiplier)
        {
            switch (handAxis)
            {
                case XRHandAxis.PalmDirection:
                    result = math.mul(rootRotation, new float3(0f, -1f, 0f));
                    break;

                case XRHandAxis.ThumbExtendedDirection:
                    result = math.mul(rootRotation, new float3(handednessMultiplier, 0f, 0f));
                    break;

                case XRHandAxis.FingersExtendedDirection:
                    result = math.mul(rootRotation, new float3(0f, 0f, 1f));
                    break;

                default:
                    result = new float3(0f, 0f, 1f);
                    break;
            }
        }

#if BURST_PRESENT
        [BurstCompile]
#endif
        internal static bool CheckDirectionAlignment(
            XRHandAlignmentCondition condition,
            float threshold,
            bool ignorePositionY,
            in float3 handAxisDirection,
            in float3 referenceDirection)
        {
            var handComparisonDirection = handAxisDirection;
            var referenceComparisonDirection = referenceDirection;
            if (ignorePositionY)
            {
                handComparisonDirection.y = 0f;
                referenceComparisonDirection.y = 0f;
            }

            referenceComparisonDirection = math.normalize(referenceComparisonDirection);
            handComparisonDirection = math.normalize(handComparisonDirection);

            var dot = math.dot(handComparisonDirection, referenceComparisonDirection);
            switch (condition)
            {
                case XRHandAlignmentCondition.AlignsWith:
                    return dot > math.cos(math.radians(threshold));

                case XRHandAlignmentCondition.PerpendicularTo:
                    return math.abs(dot) < math.cos(math.radians(math.clamp(90f - threshold, 0f, 90f)));

                case XRHandAlignmentCondition.OppositeTo:
                    return dot < -math.cos(math.radians(threshold));

                default:
                    return false;
            }
        }

        static XROrigin s_Origin;
        static Transform s_OriginTransform;
        static Transform s_HeadTransform;
    }
}
