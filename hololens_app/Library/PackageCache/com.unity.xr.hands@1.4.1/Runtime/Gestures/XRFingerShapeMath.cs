using System;
using Unity.Mathematics;
using UnityObject = UnityEngine.Object;
#if BURST_PRESENT
using Unity.Burst;
#endif

namespace UnityEngine.XR.Hands.Gestures
{
    /// <summary>
    /// Extension methods for <see cref="XRHand"/> to calculate the
    /// <see cref="XRFingerShape"/> for each finger. Also provides static access
    /// to the Finger State Processor that is used to clear the cache of
    /// calculated values.
    /// </summary>
#if BURST_PRESENT
    [BurstCompile]
#endif
    public static class XRFingerShapeMath
    {
        /// <summary>
        /// Calculate values useful for pose detection for a single finger. Will
        /// only calculate fields of <see cref="XRFingerShape"/> for
        /// corresponding flags that are set in <paramref name="shapeTypes"/>.
        /// </summary>
        /// <param name="xrHand">
        /// The <see cref="XRHand"/> from which to get  finger joint data.
        /// </param>
        /// <param name="fingerID">
        /// Denotes which finger to calculate <see cref="XRFingerState"/> values
        /// for.
        /// </param>
        /// <param name="shapeTypes">
        /// Denotes which fields to calculate in the returned
        /// <see cref="XRFingerShape"/>.
        /// </param>
        /// <returns>
        /// Returns an <see cref="XRFingerShape"/> with values calculated if
        /// their corresponding flags were set in <paramref name="shapeTypes"/>.
        /// </returns>
        /// <remarks>
        /// Calling this overload will use a <see cref="XRFingerShapeConfiguration"/>
        /// with the current configuration. The configuration is set to a sensible
        /// default provided by the platform.
        /// </remarks>
        public static XRFingerShape CalculateFingerShape(
            this XRHand xrHand,
            XRHandFingerID fingerID,
            XRFingerShapeTypes shapeTypes)
        {
            return CalculateFingerShape(
                xrHand,
                fingerID,
                shapeTypes,
                s_CurrentConfigurations[(int)fingerID]);
        }

        /// <summary>
        /// Calculate values useful for pose detection for a single finger. Will
        /// only calculate fields of <see cref="XRFingerShape"/> for
        /// corresponding flags that are set in <paramref name="shapeTypes"/>.
        /// </summary>
        /// <param name="xrHand">
        /// The <see cref="XRHand"/> from which to get  finger joint data.
        /// </param>
        /// <param name="fingerID">
        /// Denotes which finger to calculate <see cref="XRFingerShape"/> values
        /// for.
        /// </param>
        /// <param name="shapeTypes">
        /// Denotes which fields to calculate in the returned <see cref="XRFingerShape"/>.
        /// </param>
        /// <param name="configuration">
        /// The configuration used to convert joint data to finger state values.
        /// </param>
        /// <returns>
        /// Returns an <see cref="XRFingerShape"/> with values calculated if
        /// their corresponding flags were set in <paramref name="shapeTypes"/>.
        /// </returns>
        public static XRFingerShape CalculateFingerShape(
            this XRHand xrHand,
            XRHandFingerID fingerID,
            XRFingerShapeTypes shapeTypes,
            XRFingerShapeConfiguration configuration)
        {
            ref var fingerShape = ref k_CachedFingerShapes[(int)xrHand.handedness, (int)fingerID];

            // if all the requested values are already calculated, return the
            // cached value - otherwise, try to calculate missing fields before
            // returning
            if ((fingerShape.m_Types & shapeTypes) == shapeTypes)
                return fingerShape;

            if ((shapeTypes & XRFingerShapeTypes.FullCurl) != 0 &&
                (fingerShape.m_Types & XRFingerShapeTypes.FullCurl) == 0 &&
                xrHand.TryCalculateFullCurl(fingerID, ref fingerShape.m_FullCurl, configuration))
                fingerShape.m_Types |= XRFingerShapeTypes.FullCurl;

            if ((shapeTypes & XRFingerShapeTypes.BaseCurl) != 0 &&
                (fingerShape.m_Types & XRFingerShapeTypes.BaseCurl) == 0 &&
                xrHand.TryCalculateBaseCurl(fingerID, ref fingerShape.m_BaseCurl, configuration))
                fingerShape.m_Types |= XRFingerShapeTypes.BaseCurl;

            if ((shapeTypes & XRFingerShapeTypes.TipCurl) != 0 &&
                (fingerShape.m_Types & XRFingerShapeTypes.TipCurl) == 0 &&
                xrHand.TryCalculateTipCurl(fingerID, ref fingerShape.m_TipCurl, configuration))
                fingerShape.m_Types |= XRFingerShapeTypes.TipCurl;

            if ((shapeTypes & XRFingerShapeTypes.Pinch) != 0 &&
                (fingerShape.m_Types & XRFingerShapeTypes.Pinch) == 0 &&
                xrHand.TryCalculatePinch(fingerID, ref fingerShape.m_Pinch, configuration))
                fingerShape.m_Types |= XRFingerShapeTypes.Pinch;

            if ((shapeTypes & XRFingerShapeTypes.Spread) != 0 &&
                (fingerShape.m_Types & XRFingerShapeTypes.Spread) == 0 &&
                xrHand.TryCalculateSpread(fingerID, ref fingerShape.m_Spread, configuration))
                fingerShape.m_Types |= XRFingerShapeTypes.Spread;

            return fingerShape;
        }

        /// <summary>
        /// Set the finger state configuration to use for all future calls to
        /// <see cref="XRFingerStateMathUtilities.CalculateFingerStates"/> for
        /// the given finger.
        /// </summary>
        /// <param name="fingerID">
        /// Which finger to set the <see cref="XRFingerShapeConfiguration"/> for.
        /// </param>
        /// <param name="configuration">
        /// The configurations for the given finger. If <see langword="null"/>,
        /// that finger's configuration will revert to an appropriate default.
        /// </param>
        /// <exception cref="System.ArgumentNullException">
        /// Thrown if <paramref name="fileName"/> is <see langword="null"/>.
        /// </exception>
        /// <remarks>
        /// If you wish to restore the default, call <see cref="ResetFingerShapeConfiguration"/>.
        /// </remarks>
        public static void SetFingerShapeConfiguration(XRHandFingerID fingerID, XRFingerShapeConfiguration configuration)
        {
            if (configuration == null)
                throw new ArgumentNullException("{nameof(configuration)} must not be null", nameof(configuration));

            s_CurrentConfigurations[(int)fingerID] = configuration;
        }

        /// <summary>
        /// Resets the finger state configuration to default for all future calls to
        /// <see cref="XRFingerStateMathUtilities.CalculateFingerStates"/> for
        /// the given finger.
        /// </summary>
        /// <param name="fingerID">
        /// Which finger to reset the <see cref="XRFingerShapeConfiguration"/> for.
        /// </param>
        /// <remarks>
        /// If you wish to override the default, call <see cref="SetFingerShapeConfiguration"/>.
        /// </remarks>
        public static void ResetFingerShapeConfiguration(XRHandFingerID fingerID)
        {
            s_CurrentConfigurations[(int)fingerID] = k_DefaultConfigurations[(int)fingerID];
        }

        internal static void SetDefaultFingerShapeConfiguration(XRHandFingerID fingerID, XRFingerShapeConfiguration configuration)
        {
            k_DefaultConfigurations[(int)fingerID] = configuration;
            s_CurrentConfigurations[(int)fingerID] = configuration;
        }

        internal static void ClearFingerStateCache(Handedness handedness)
        {
            for (var fingerShapeIndex = 0; fingerShapeIndex < k_FingerCacheSize; ++fingerShapeIndex)
                k_CachedFingerShapes[(int)handedness, fingerShapeIndex].Clear();
        }

        static bool TryCalculateFullCurl(
            this XRHand xrHand,
            XRHandFingerID fingerID,
            ref float fullCurl,
            XRFingerShapeConfiguration configuration)
        {
            var frontJointID = fingerID.GetFrontJointID();
            if (!xrHand.GetJoint(frontJointID).TryGetPose(out var pose0) ||
                !xrHand.GetJoint(frontJointID + 1).TryGetPose(out var pose1) ||
                !xrHand.GetJoint(frontJointID + 2).TryGetPose(out var pose2) ||
                !xrHand.GetJoint(frontJointID + 3).TryGetPose(out var pose3) ||
                !xrHand.GetJoint(frontJointID + 4).TryGetPose(out var pose4) && fingerID != XRHandFingerID.Thumb)
                return false;

            fullCurl = CalculateFullCurl(
                fingerID,
                pose0.position,
                pose1.position, pose1.rotation,
                pose2.position, pose2.rotation,
                pose3.position, pose3.rotation,
                pose4.position,
                configuration.minimumFullCurlDegrees1, configuration.maximumFullCurlDegrees1,
                configuration.minimumFullCurlDegrees2, configuration.maximumFullCurlDegrees2,
                configuration.minimumFullCurlDegrees3, configuration.maximumFullCurlDegrees3);
            return true;
        }

        static bool TryCalculateBaseCurl(
            this XRHand xrHand,
            XRHandFingerID fingerID,
            ref float baseCurl,
            XRFingerShapeConfiguration configuration)
        {
            // the base curl for the thumb has a completely different calculation
            // from the rest of the fingers, but is very similar to how spread is
            // calculated (requested by design)
            if (fingerID == XRHandFingerID.Thumb)
            {
                if (!xrHand.GetJoint(XRHandJointID.Wrist).TryGetPose(out var wristPose) ||
                    !xrHand.GetJoint(XRHandJointID.ThumbMetacarpal).TryGetPose(out var thisPose1) ||
                    !xrHand.GetJoint(XRHandJointID.ThumbProximal).TryGetPose(out var thisPose2) ||
                    !xrHand.GetJoint(XRHandJointID.IndexMetacarpal).TryGetPose(out var nextPose1) ||
                    !xrHand.GetJoint(XRHandJointID.IndexProximal).TryGetPose(out var nextPose2))
                    return false;

                baseCurl = CalculateBaseCurlThumb(
                    wristPose.position, wristPose.rotation,
                    thisPose1.position, thisPose2.position,
                    nextPose1.position, nextPose2.position,
                    configuration.minimumBaseCurlDegrees, configuration.maximumBaseCurlDegrees);
                return true;
            }

            var frontJointID = fingerID.GetFrontJointID();
            var middleJointID = frontJointID + 1;
            var lastJointID = middleJointID + 1;
            if (!xrHand.GetJoint(frontJointID).TryGetPose(out var frontPose) ||
                !xrHand.GetJoint(middleJointID).TryGetPose(out var middlePose) ||
                !xrHand.GetJoint(lastJointID).TryGetPose(out var lastPose))
                return false;

            baseCurl = CalculateBaseCurl(
                frontPose.position,
                middlePose.position, middlePose.rotation,
                lastPose.position,
                configuration.minimumBaseCurlDegrees, configuration.maximumBaseCurlDegrees);
            return true;
        }

        static bool TryCalculateTipCurl(
            this XRHand xrHand,
            XRHandFingerID fingerID,
            ref float tipCurl,
            XRFingerShapeConfiguration configuration)
        {
            var jointID3 = fingerID.GetBackJointID();
            var jointID2 = jointID3 - 1;
            var jointID1 = jointID2 - 1;
            var jointID0 = jointID1 - 1;

            if (!xrHand.GetJoint(jointID0).TryGetPose(out var pose0) ||
                !xrHand.GetJoint(jointID1).TryGetPose(out var pose1) ||
                !xrHand.GetJoint(jointID2).TryGetPose(out var pose2) ||
                !xrHand.GetJoint(jointID3).TryGetPose(out var pose3))
                return false;

            tipCurl = CalculateTipCurl(
                pose0.position,
                pose1.position, pose1.rotation,
                pose2.position, pose2.rotation,
                pose3.position,
                configuration.minimumTipCurlDegrees1, configuration.maximumTipCurlDegrees1,
                configuration.minimumTipCurlDegrees2, configuration.maximumTipCurlDegrees2);
            return true;
        }

        static bool TryCalculatePinch(
            this XRHand xrHand,
            XRHandFingerID fingerID,
            ref float pinch,
            XRFingerShapeConfiguration configuration)
        {
            if (fingerID == XRHandFingerID.Thumb)
                return false;

            if (!xrHand.GetJoint(fingerID.GetBackJointID()).TryGetPose(out var fingerTipPose) ||
                !xrHand.GetJoint(XRHandJointID.ThumbTip).TryGetPose(out var thumbTipPose))
                return false;

            pinch = CalculatePinch(
                fingerTipPose.position,
                thumbTipPose.position,
                configuration.minimumPinchDistance, configuration.maximumPinchDistance);
            return true;
        }

        static bool TryCalculateSpread(
            this XRHand xrHand,
            XRHandFingerID fingerID,
            ref float spread,
            XRFingerShapeConfiguration configuration)
        {
            if (fingerID == XRHandFingerID.Little || !xrHand.GetJoint(XRHandJointID.Wrist).TryGetPose(out var wristPose))
                return false;

            // we want proximal and intermediate for the four fingers...
            var thisID1 = fingerID.GetFrontJointID() + 1;
            var thisID2 = thisID1 + 1;
            var nextID1 = (fingerID + 1).GetFrontJointID() + 1;
            var nextID2 = nextID1 + 1;

            // ...but in practice, these specific joints work best for the the thumb instead
            if (fingerID == XRHandFingerID.Thumb)
            {
                thisID1 = XRHandJointID.ThumbMetacarpal;
                thisID2 = XRHandJointID.ThumbTip;
                nextID1 = XRHandJointID.IndexMetacarpal;
                nextID2 = XRHandJointID.IndexProximal;
            }

            if (!xrHand.GetJoint(thisID1).TryGetPose(out var thisPose1) ||
                !xrHand.GetJoint(thisID2).TryGetPose(out var thisPose2) ||
                !xrHand.GetJoint(nextID1).TryGetPose(out var nextPose1) ||
                !xrHand.GetJoint(nextID2).TryGetPose(out var nextPose2))
                return false;

            spread = CalculateSpread(
                xrHand.handedness,
                fingerID,
                wristPose.position, wristPose.rotation,
                thisPose1.position,
                thisPose2.position,
                nextPose1.position,
                nextPose2.position,
                configuration.minimumSpreadDegrees, configuration.maximumSpreadDegrees);
            return true;
        }

#if BURST_PRESENT
        [BurstCompile]
#endif
        static float CalculateFullCurl(
            XRHandFingerID fingerID,
            in float3 position0,
            in float3 position1, in quaternion rotation1,
            in float3 position2, in quaternion rotation2,
            in float3 position3, in quaternion rotation3,
            in float3 position4,
            float minimumDegrees1, float maximumDegrees1,
            float minimumDegrees2, float maximumDegrees2,
            float minimumDegrees3, float maximumDegrees3)
        {
            var divisor = 2f;
            var totalNormalizedDegrees =
                (DegreesBetween(position0, position1, rotation1, position2) - minimumDegrees1) / (maximumDegrees1 - minimumDegrees1) +
                (DegreesBetween(position1, position2, rotation2, position3) - minimumDegrees2) / (maximumDegrees2 - minimumDegrees2);

            if (fingerID != XRHandFingerID.Thumb)
            {
                divisor = 3f;
                totalNormalizedDegrees +=
                    (DegreesBetween(position2, position3, rotation3, position4) - minimumDegrees3) / (maximumDegrees3 - minimumDegrees3);
            }

            return 1f - math.clamp(totalNormalizedDegrees / divisor, 0f, 1f);
        }

#if BURST_PRESENT
        [BurstCompile]
#endif
        static float CalculateBaseCurlThumb(
            in float3 wristPosition, in quaternion wristRotation,
            in float3 thisPosition1, in float3 thisPosition2,
            in float3 nextPosition1, in float3 nextPosition2,
            float minimumDegrees, float maximumDegrees)
        {
            var wristRotationInverse = math.inverse(wristRotation);
            LocalizeTo(out var thisPosition1Localized, wristPosition, wristRotationInverse, thisPosition1);
            LocalizeTo(out var thisPosition2Localized, wristPosition, wristRotationInverse, thisPosition2);
            LocalizeTo(out var nextPosition1Localized, wristPosition, wristRotationInverse, nextPosition1);
            LocalizeTo(out var nextPosition2Localized, wristPosition, wristRotationInverse, nextPosition2);

            var toThis2 = thisPosition2Localized - thisPosition1Localized;
            var toNext2 = nextPosition2Localized - nextPosition1Localized;

            toThis2.x = 0f;
            toNext2.x = 0f;
            toThis2.z = math.abs(toThis2.z);
            toNext2.z = math.abs(toNext2.z);

            if (toThis2.y > toNext2.y)
                return 0f;

            var degrees = math.degrees(math.acos(math.dot(toThis2, toNext2) / (math.length(toThis2) * math.length(toNext2))));
            var range = maximumDegrees - minimumDegrees;
            return math.clamp((degrees - minimumDegrees) / range, 0f, 1f);
        }

#if BURST_PRESENT
        [BurstCompile]
#endif
        static float CalculateBaseCurl(
            in float3 position0,
            in float3 position1, in quaternion rotation1,
            in float3 position2,
            float minimumDegrees, float maximumDegrees)
        {
            var degrees = DegreesBetween(position0, position1, rotation1, position2);
            var range = maximumDegrees - minimumDegrees;
            return 1f - math.clamp((degrees - minimumDegrees) / range, 0f, 1f);
        }

#if BURST_PRESENT
        [BurstCompile]
#endif
        static float CalculateTipCurl(
            in float3 position0,
            in float3 pose1Position, in quaternion pose1Rotation,
            in float3 pose2Position, in quaternion pose2Rotation,
            in float3 pose3Position,
            float minimumDegrees1, float maximumDegrees1,
            float minimumDegrees2, float maximumDegrees2)
        {
            var degrees1 = DegreesBetween(position0, pose1Position, pose1Rotation, pose2Position);
            var normalized1 = 1f - math.clamp((degrees1 - minimumDegrees1) / (maximumDegrees1 - minimumDegrees1), 0f, 1f);

            var degrees2 = DegreesBetween(pose1Position, pose2Position, pose2Rotation, pose3Position);
            var normalized2 = 1f - math.clamp((degrees2 - minimumDegrees2) / (maximumDegrees2 - minimumDegrees2), 0f, 1f);

            return 0.5f * (normalized1 + normalized2);
        }

#if BURST_PRESENT
        [BurstCompile]
#endif
        static float CalculatePinch(
            in float3 fingerTipPosition,
            in float3 thumbTipPosition,
            float minimumDistance, float maximumDistance)
        {
            var distanceSquared = math.distancesq(fingerTipPosition, thumbTipPosition);
            if (distanceSquared > maximumDistance * maximumDistance)
                return 0f;

            if (distanceSquared < minimumDistance * minimumDistance)
                return 1f;

            var distance = math.sqrt(distanceSquared);
            var range = maximumDistance - minimumDistance;
            return 1f - (distance - minimumDistance) / range;
        }

#if BURST_PRESENT
        [BurstCompile]
#endif
        static float CalculateSpread(
            Handedness handedness,
            XRHandFingerID fingerID,
            in float3 wristPosition, in quaternion wristRotation,
            in float3 thisPosition1, in float3 thisPosition2,
            in float3 nextPosition1, in float3 nextPosition2,
            float minimumDegrees, float maximumDegrees)
        {
            var wristRotationInverse = math.inverse(wristRotation);
            LocalizeTo(out var thisPosition1Localized, wristPosition, wristRotationInverse, thisPosition1);
            LocalizeTo(out var thisPosition2Localized, wristPosition, wristRotationInverse, thisPosition2);
            LocalizeTo(out var nextPosition1Localized, wristPosition, wristRotationInverse, nextPosition1);
            LocalizeTo(out var nextPosition2Localized, wristPosition, wristRotationInverse, nextPosition2);

            var toThis2 = thisPosition2Localized - thisPosition1Localized;
            var toNext2 = nextPosition2Localized - nextPosition1Localized;

            if (handedness == Handedness.Left)
            {
                if (toNext2.x > toThis2.x)
                    return 0f;
            }
            else if (toNext2.x < toThis2.x)
            {
                return 0f;
            }

            toThis2.y = 0f;
            toNext2.y = 0f;
            toThis2.z = math.abs(toThis2.z);
            toNext2.z = math.abs(toNext2.z);

            var degrees = math.degrees(math.acos(math.dot(toThis2, toNext2) / (math.length(toThis2) * math.length(toNext2))));
            var range = maximumDegrees - minimumDegrees;
            return math.clamp((degrees - minimumDegrees) / range, 0f, 1f);
        }

#if BURST_PRESENT
        [BurstCompile]
#endif
        static void LocalizeTo(
            out float3 localized,
            in float3 poseDefinitingSpacePosition,
            in quaternion poseDefinitingSpaceRotationInverse,
            in float3 positionToConvert)
            => localized = math.mul(poseDefinitingSpaceRotationInverse, positionToConvert - poseDefinitingSpacePosition);

#if BURST_PRESENT
        [BurstCompile]
#endif
        static float DegreesBetween(
            in float3 position0,
            in float3 position1, in quaternion rotation1,
            in float3 position2)
        {
            var to0 = math.normalize(position0 - position1);
            var to2 = math.normalize(position2 - position1);
            var right = new float3(1f, 0f, 0f);

            // If the cross product is negative, then the joints are bending "backwards" and the angle is greater than 180 degrees
            if (math.dot(math.mul(rotation1, right), math.cross(-to0, to2)) < 0f)
                return 180f;

            return math.degrees(math.acos(math.dot(to0, to2)));
        }

        const int k_FingerCacheSize = 5;
        const int k_HandednessCacheSize = 3;
        static readonly XRFingerShape[,] k_CachedFingerShapes = new XRFingerShape[k_HandednessCacheSize, k_FingerCacheSize];
        static readonly XRFingerShapeConfiguration[] k_DefaultConfigurations = new XRFingerShapeConfiguration[k_FingerCacheSize];
        static XRFingerShapeConfiguration[] s_CurrentConfigurations = new XRFingerShapeConfiguration[k_FingerCacheSize];
    }
}
