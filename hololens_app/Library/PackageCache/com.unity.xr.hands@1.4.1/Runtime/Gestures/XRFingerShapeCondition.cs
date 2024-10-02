using System;

namespace UnityEngine.XR.Hands.Gestures
{
    /// <summary>
    /// A set of targets for the <see cref="XRFingerShape"/> values of a single
    /// <see cref="XRHandFingerID"/>.
    /// </summary>
    [Serializable]
    public class XRFingerShapeCondition
    {
        /// <summary>
        /// A configuration for a <see cref="XRFingerShapeType"/> and its
        /// desired value in a condition.
        /// </summary>
        [Serializable]
        public struct Target
        {
            [SerializeField]
            [Tooltip("The finger shape type that is being checked in this condition.")]
            XRFingerShapeType m_ShapeType;

            /// <summary>
            /// The <see cref="XRFingerShapeType"/> that is being checked in
            /// this condition.
            /// </summary>
            public XRFingerShapeType shapeType
            {
                get => m_ShapeType;
                set => m_ShapeType = value;
            }

            /// <summary>
            /// The desired value to compare the specified
            /// <see cref="XRFingerShapeType"/> to in this condition.
            /// </summary>
            public float desired
            {
                get => m_Desired;
                set => m_Desired = Mathf.Clamp01(value);
            }

            [SerializeField]
            [Range(0f, 1f)]
            [Tooltip("The maximum allowable increase in range from the Desired value that will allow for a condition to be met.")]
            float m_UpperTolerance;

            /// <summary>
            /// The maximum allowable increase in range from the <see cref="desired"/> value that will allow for a condition to be met.
            /// </summary>
            public float upperTolerance
            {
                get => m_UpperTolerance;
                set => m_UpperTolerance = Mathf.Clamp01(value);
            }

            [Range(0f, 1f)]
            [SerializeField]
            [Tooltip("The minimum allowable decrease in range from the Desired value that will allow for a condition to be met.")]
            float m_LowerTolerance;

            /// <summary>
            /// The minimum allowable decrease in range from the <see cref="desired"/> value that will allow for a condition to be met.
            /// for the condition to be met.
            /// </summary>
            public float lowerTolerance
            {
                get => m_LowerTolerance;
                set => m_LowerTolerance = Mathf.Clamp01(value);
            }

            [HideInInspector, SerializeField, Obsolete("Deprecated. Use upperTolerance and lowerTolerance instead.")]
            float m_Tolerance;

            /// <summary>
            /// The deprecated minimum and maximum the value can differ from the <see cref="desired"/>
            /// for the condition to be met.
            /// </summary>
            [Obsolete("Deprecated. Use upperTolerance and lowerTolerance instead.")]
            public float tolerance
            {
                get => m_Tolerance;
                set
                {
                    Debug.LogWarning("Deprecated. Use upperTolerance and lowerTolerance instead. Both of those properties will be set via the deprecated tolerance value.");
                    m_Tolerance = Mathf.Clamp01(value);
                    upperTolerance = m_Tolerance;
                    lowerTolerance = m_Tolerance;

                    // Reset tolerance value to zero in order to prevent further deprecated upgrade functionality
                    m_Tolerance = 0f;
                }
            }

            [Range(0f, 1f)]
            [SerializeField]
            [Tooltip("The desired value for the finger shape.")]
            float m_Desired;
        }

        [SerializeField]
        [Tooltip("The finger to check for this condition.")]
        XRHandFingerID m_FingerID = XRHandFingerID.Index;

        [SerializeField]
        [Tooltip("The targets to check for this condition.")]
        Target[] m_Targets;

        /// <summary>
        /// Finger shape targets to check for this finger. Setting this value
        /// will update the <see cref="XRFingerShapeTypes"/> needed for this
        /// condition.
        /// </summary>
        public Target[] targets
        {
            get => m_Targets;
            set
            {
                m_Targets = value;
                m_TypesNeededDirty = true;
            }
        }

        /// <summary>
        /// The finger ID that this condition applies to.
        /// </summary>
        public XRHandFingerID fingerID
        {
            get => m_FingerID;
            set => m_FingerID = value;
        }

        XRFingerShapeTypes m_TypesNeeded;
        bool m_TypesNeededDirty = true;

        /// <summary>
        /// Checks if the <see cref="XRFingerShape"/> matches the targets in
        /// this condition.
        /// </summary>
        /// <remarks>
        /// The target values are checked in the order listed.
        /// The method will return <see langword="false"/> as soon as it finds
        /// one value that is different from the target by more than the tolerance.
        /// </remarks>
        /// <param name="eventArgs">
        /// The hand joint updated event argument that contains the latest hand data.
        /// </param>
        /// <returns>
        /// Returns <see langword="true"/> if all the finger shape conditions
        /// are met. Otherwise, returns <see langword="false"/>.
        /// </returns>
        public bool CheckCondition(XRHandJointsUpdatedEventArgs eventArgs)
        {
            UpdateTypesNeededIfDirty();
            if (m_TypesNeeded == XRFingerShapeTypes.None)
                return true;

            var fingerShape = eventArgs.hand.CalculateFingerShape(m_FingerID, m_TypesNeeded);
            for (var index = 0; index < m_Targets.Length; ++index)
            {
                float value;
                bool hasValue;
                var target = targets[index];

                switch (target.shapeType)
                {
                    case XRFingerShapeType.FullCurl:
                        hasValue = fingerShape.TryGetFullCurl(out value);
                        break;

                    case XRFingerShapeType.BaseCurl:
                        hasValue = fingerShape.TryGetBaseCurl(out value);
                        break;

                    case XRFingerShapeType.TipCurl:
                        hasValue = fingerShape.TryGetTipCurl(out value);
                        break;

                    case XRFingerShapeType.Pinch:
                        hasValue = fingerShape.TryGetPinch(out value);
                        break;

                    case XRFingerShapeType.Spread:
                        hasValue = fingerShape.TryGetSpread(out value);
                        break;

                    default:
                        throw new ArgumentOutOfRangeException($"Finger shape type {target.shapeType} is invalid for finger shape target condition.");
                }

                // Test for the current tracked value being within the allowed range
                if (!hasValue ||
                    value < (target.desired - target.lowerTolerance) ||
                    value > (target.desired + target.upperTolerance))
                {
                    return false;
                }
            }

            return true;
        }

        internal void UpdateTypesNeededIfDirty()
        {
            if (!m_TypesNeededDirty)
                return;

            m_TypesNeeded = XRFingerShapeTypes.None;
            for (var index = 0; index < m_Targets.Length; index++)
                m_TypesNeeded |= (XRFingerShapeTypes)(1 << (int)m_Targets[index].shapeType);

            m_TypesNeededDirty = false;
        }
    }
}
