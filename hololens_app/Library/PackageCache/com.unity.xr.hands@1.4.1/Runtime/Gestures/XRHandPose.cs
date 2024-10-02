namespace UnityEngine.XR.Hands.Gestures
{
    /// <summary>
    /// Description of a hand pose, which is <see cref="XRHandShape"/> and
    /// <see cref="XRHandRelativeOrientation"/>.
    /// </summary>
    [CreateAssetMenu(fileName = "New Hand Pose", menuName = "XR/Hand Interactions/Hand Pose")]
    public class XRHandPose : ScriptableObject
    {
        [SerializeField]
        [Tooltip("Hand shape to check for this pose.")]
        XRHandShape m_HandShape;

        [SerializeField]
        [Tooltip("User- and target-relative hand orientation conditions to check for this pose.")]
        XRHandRelativeOrientation m_RelativeOrientation;

        /// <summary>
        /// The <see cref="XRHandShape"/> required for this hand pose.
        /// </summary>
        public XRHandShape handShape
        {
            get => m_HandShape;
            set => m_HandShape = value;
        }

        /// <summary>
        /// The <see cref="XRHandRelativeOrientation"/> required for this hand pose.
        /// </summary>
        public XRHandRelativeOrientation relativeOrientation
        {
            get => m_RelativeOrientation;
            set => m_RelativeOrientation = value;
        }

        /// <summary>
        /// Check the hand shape against the given updated hand joint data.
        /// </summary>
        /// <remarks>
        /// The check will end early if the hand is not tracked or after the
        /// first finger shape condition is found to be <see langword="false"/>.
        /// The order of the conditions will determine the order they are
        /// checked.
        /// </remarks>
        /// <param name="eventArgs">
        /// The hand joints updated event arguments to reference for the
        /// latest hand.
        /// </param>
        /// <returns>
        /// Returns <see langword="true"/> if all the finger shape conditions
        /// are met. Otherwise, returns <see langword="false"/> if any condition
        /// is not met.
        /// </returns>
        public bool CheckConditions(XRHandJointsUpdatedEventArgs eventArgs)
        {
            var hand = eventArgs.hand;
            return hand.isTracked &&
                m_HandShape != null && m_HandShape.CheckConditions(eventArgs) &&
                m_RelativeOrientation.CheckConditions(hand.rootPose, hand.handedness);
        }
    }
}
