using System.Collections.Generic;
#if UNITY_EDITOR
using UnityEditor;
#endif

namespace UnityEngine.XR.Hands.Gestures
{
    /// <summary>
    /// Description of a hand shape, which is a set of constraints on some or all of the fingers' shapes.
    /// </summary>
    [CreateAssetMenu(fileName = "New Hand Shape", menuName = "XR/Hand Interactions/Hand Shape")]
    public class XRHandShape : ScriptableObject
    {
        const float k_DefaultShapeTolerance = 0.3f;

        [SerializeField]
        [Tooltip("The finger shape conditions that must be met for this hand shape to be considered detected. " +
                 "The conditions are checked in order, ending at the first false condition. " +
                 "Usually the thumb and index should be first to rule out many other hand shapes.")]
        List<XRFingerShapeCondition> m_FingerShapeConditions = new List<XRFingerShapeCondition>();

        /// <summary>
        /// The list of finger state conditions for this hand shape.
        /// </summary>
        public List<XRFingerShapeCondition> fingerShapeConditions
        {
            get => m_FingerShapeConditions;
            set => m_FingerShapeConditions = value;
        }

        /// <summary>
        /// Check the hand shape against the given updated hand joint data.
        /// </summary>
        /// <remarks>
        /// The check will end early if the hand is not tracked or after the
        /// first finger state condition is found to be <see langword="false"/>.
        /// The order of the conditions will determine the order they are checked.
        /// </remarks>
        /// <param name="eventArgs">
        /// The hand joints updated event arguments to reference for the latest hand.
        /// </param>
        /// <returns>
        /// Returns <see langword="true"/> if all the finger state conditions are met.
        /// Otherwise, returns <see langword="false"/>.
        /// </returns>
        public bool CheckConditions(XRHandJointsUpdatedEventArgs eventArgs)
        {
            if (!eventArgs.hand.isTracked)
                return false;

            for (var index = 0; index < m_FingerShapeConditions.Count; ++index)
            {
                if (!m_FingerShapeConditions[index].CheckCondition(eventArgs))
                    return false;
            }

            return true;
        }

#if UNITY_EDITOR
        // In Editor only, allow modifications to the hand shape to update the finger state types needed for this condition
        void OnValidate()
        {
            for (var index = 0; index < m_FingerShapeConditions.Count; ++index)
            {
                var condition = m_FingerShapeConditions[index];
                for (int i = 0; i < condition.targets.Length; ++i)
                {
                    // Upgrade any deprecated single tolerance range values to support separate upper and lower tolerances
                    var target = condition.targets[i];
#pragma warning disable 618
                    if (target.tolerance != 0f)
                    {
                        var targetCopy = target;
                        targetCopy.tolerance = target.tolerance;
                        condition.targets[i] = targetCopy;
                        EditorUtility.SetDirty(this);
                        AssetDatabase.SaveAssets();
                    }
#pragma warning restore 618
                }

                condition.UpdateTypesNeededIfDirty();
            }
        }

        [ContextMenu("Reset All Tolerances")]
        void ResetAllTolerances()
        {
            for (var index = 0; index < m_FingerShapeConditions.Count; ++index)
            {
                var condition = m_FingerShapeConditions[index];
                for (var i = 0; i < condition.targets.Length; i++)
                {
                    condition.targets[i].upperTolerance = k_DefaultShapeTolerance;
                    condition.targets[i].lowerTolerance = k_DefaultShapeTolerance;
                }
            }
        }
#endif
    }
}
