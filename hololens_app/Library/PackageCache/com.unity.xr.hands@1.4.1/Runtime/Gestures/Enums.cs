using System;

namespace UnityEngine.XR.Hands.Gestures
{
    /// <summary>
    /// The different states to describe a finger
    /// </summary>
    public enum XRFingerShapeType
    {
        /// <summary>
        /// The amount that all joints in a finger are curled.  
        /// </summary>
        FullCurl,

        /// <summary>
        /// The amount that the proximal (knuckle) joint is curled.
        /// </summary>
        BaseCurl,

        /// <summary>
        /// The amount of bend in the top two joints of the finger.
        /// </summary>
        /// <remarks>
        /// This state does not take the Proximal (knuckle) joint into consideration.
        /// </remarks>
        TipCurl,

        /// <summary>
        /// How close a given fingertip of the four fingers is to the <see cref="XRHandJointID.ThumbTip"/>.
        /// </summary>
        /// <remarks>
        /// This state does not exist for the <see cref="XRHandFingerID.Thumb"/>.
        /// </remarks>
        Pinch,

        /// <summary>
        /// The amount that the finger is separated from the adjacent finger towards the <see cref="XRHandFingerID.Little"/> finger.
        /// </summary>
        /// <remarks>
        /// This state does not exist for the <see cref="XRHandFingerID.Little"/> finger.
        /// </remarks>
        Spread,
    }

    /// <summary>
    /// Set which types you want to calculate for the the corresponding fields calculated when
    /// calling <see cref="XRFingerShapeMath.Calculate(XRHand, XRHandFingerID, XRFingerShapeTypes)"/>.
    /// Any cleared types will result in a value of <c>0</c> for its corresponding field in the
    /// returned <see cref="XRFingerShape"/>.
    /// </summary>
    [Flags]
    public enum XRFingerShapeTypes
    {
        /// <summary>
        /// Don't calculate any fields of <see cref="XRFingerShape"/> during a
        /// call to <see cref="XRFingerShapeMath.Calculate(XRHand, XRHandFingerID, XRFingerShapeTypes)"/> or
        /// <see cref="XRFingerShapeMath.Calculate(XRHand, XRHandFingerID, XRFingerShapeTypes, XRFingerShapeConfiguration)"/>.
        /// </summary>
        None = 0,

        /// <summary>
        /// Whether to calculate the <see cref="XRFingerShapeType.FullCurl"/> value
        /// during a call to <see cref="XRFingerShapeMath.Calculate(XRHand, XRHandFingerID, XRFingerShapeTypes)"/> or
        /// <see cref="XRFingerShapeMath.Calculate(XRHand, XRHandFingerID, XRFingerShapeTypes, XRFingerShapeConfiguration)"/>.
        /// </summary>
        FullCurl = 1 << XRFingerShapeType.FullCurl,

        /// <summary>
        /// Whether to calculate the <see cref="XRFingerShapeType.BaseCurl"/> value
        /// during a call to <see cref="XRFingerShapeMath.Calculate(XRHand, XRHandFingerID, XRFingerShapeTypes)"/> or
        /// <see cref="XRFingerShapeMath.Calculate(XRHand, XRHandFingerID, XRFingerShapeTypes, XRFingerShapeConfiguration)"/>.
        /// </summary>
        BaseCurl = 1 << XRFingerShapeType.BaseCurl,

        /// <summary>
        /// Whether to calculate the <see cref="XRFingerShapeType.TipCurl"/> value
        /// during a call to <see cref="XRFingerShapeMath.Calculate(XRHand, XRHandFingerID, XRFingerShapeTypes)"/> or
        /// <see cref="XRFingerShapeMath.Calculate(XRHand, XRHandFingerID, XRFingerShapeTypes, XRFingerShapeConfiguration)"/>.
        /// </summary>
        TipCurl = 1 << XRFingerShapeType.TipCurl,

        /// <summary>
        /// Whether to calculate the <see cref="XRFingerShapeType.Pinch"/> value
        /// during a call to <see cref="XRFingerShapeMath.Calculate(XRHand, XRHandFingerID, XRFingerShapeTypes)"/> or
        /// <see cref="XRFingerShapeMath.Calculate(XRHand, XRHandFingerID, XRFingerShapeTypes, XRFingerShapeConfiguration)"/>.
        /// </summary>
        Pinch = 1 << XRFingerShapeType.Pinch,

        /// <summary>
        /// Whether to calculate the <see cref="XRFingerShapeType.Splay"/> value
        /// during a call to <see cref="XRFingerShapeMath.Calculate(XRHand, XRHandFingerID, XRFingerShapeTypes)"/> or
        /// <see cref="XRFingerShapeMath.Calculate(XRHand, XRHandFingerID, XRFingerShapeTypes, XRFingerShapeConfiguration)"/>.
        /// </summary>
        Spread = 1 << XRFingerShapeType.Spread,

        /// <summary>
        /// Calculate all fields of <see cref="XRFingerShapeType"/> during a call to
        /// <see cref="XRFingerShapeMath.Calculate(XRHand, XRHandFingerID, XRFingerShapeTypes)"/> or
        /// <see cref="XRFingerShapeMath.Calculate(XRHand, XRHandFingerID, XRFingerShapeTypes, XRFingerShapeConfiguration)"/>.
        /// </summary>
        All = (1 << 5) - 1
    }

    /// <summary>
    /// The axis of a hand that is independent of the handedness.
    /// </summary>
    public enum XRHandAxis
    {
        /// <summary>
        /// The direction pointing out from the hand's palm.
        /// This direction is perpendicular to the hand's <see cref="XRHandAxis.FingersExtendedDirection"/> and
        /// <see cref="XRHandAxis.ThumbExtendedDirection"/>
        /// </summary>
        PalmDirection,

        /// <summary>
        /// The direction pointing from the center of the hand towards the thumb.
        /// Left and right hands are symmetrically mirrored so when palms are facing up in front of the body, this
        /// direction is right on the right hand, and left on the left hand, relative to the body.
        /// This direction is perpendicular to the hand's <see cref="XRHandAxis.PalmDirection"/> and
        /// <see cref="XRHandAxis.FingersExtendedDirection"/>
        /// </summary>
        ThumbExtendedDirection,

        /// <summary>
        /// The direction that the index, middle, ring, and little finger point when they are extended.
        /// This direction is perpendicular to the hand's <see cref="XRHandAxis.PalmDirection"/> and
        /// <see cref="XRHandAxis.ThumbExtendedDirection"/>
        /// </summary>
        FingersExtendedDirection,
    }

    /// <summary>
    /// The method used to compare two directions.
    /// </summary>
    public enum XRHandAlignmentCondition
    {
        /// <summary>
        /// The angle between the directions is less than the threshold.
        /// </summary>
        AlignsWith,

        /// <summary>
        /// The angle between the directions is 90 degrees plus or minus the threshold.
        /// </summary>
        PerpendicularTo,

        /// <summary>
        /// The angle between the direction and the opposite of the reference direction is less than the threshold.
        /// </summary>
        OppositeTo,
    }

    /// <summary>
    /// The direction to compare the hand's axis direction to relative to the user.
    /// </summary>
    public enum XRHandUserRelativeDirection
    {
        /// <summary>
        /// Up direction of the user's tracking space.
        /// The direction uses the <see cref="Unity.XR.CoreUtils.XROrigin.Origin"/> in the scene.
        /// </summary>
        OriginUp,

        /// <summary>
        /// Direction from the root pose of the hand to the user's head.
        /// The head position is the position of the <see cref="Unity.XR.CoreUtils.XROrigin.Camera"/> in the scene.
        /// </summary>
        HandToHead,

        /// <summary>
        /// The nose direction of the user's head.
        /// The direction uses the forward direction of the <see cref="Unity.XR.CoreUtils.XROrigin.Camera"/> in the scene.
        /// </summary>
        NoseDirection,

        /// <summary>
        /// The chin direction of the user's head.
        /// The direction uses the down direction of the <see cref="Unity.XR.CoreUtils.XROrigin.Camera"/> in the scene.
        /// </summary>
        ChinDirection,

        /// <summary>
        /// The ear direction of the user's head, or the lateral direction of the user's head.
        /// The ear chosen is the one on the same side of the body as the hand's connected shoulder.
        /// This direction is perpendicular to the <see cref="NoseDirection"/> and <see cref="ChinDirection"/> directions.
        /// The direction uses the right/left direction of the <see cref="Unity.XR.CoreUtils.XROrigin.Camera"/> in the scene.
        /// </summary>
        EarDirection,
    }

    /// <summary>
    /// The direction to compare the hand's axis direction to relative to an arbitrary target transform in the scene.
    /// </summary>
    public enum XRHandTargetRelativeDirection
    {
        /// <summary>
        /// Direction pointing towards the target from the hand.
        /// </summary>
        HandToTarget,

        /// <summary>
        /// The forward direction of the target.
        /// </summary>
        TargetForward,

        /// <summary>
        /// The up direction of the target.
        /// </summary>
        TargetUp,

        /// <summary>
        /// The right direction of the target.
        /// </summary>
        TargetRight,
    }
}
