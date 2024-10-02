namespace UnityEngine.XR.Hands.Gestures
{
    /// <summary>
    /// The calculated state of certain relative geometric properties of a
    /// finger from a given hand. Useful for pose detection. All values are
    /// normalized from <c>0</c> to <c>1</c>.
    /// </summary>
    /// <remarks>
    /// Do not construct this yourself. Only retrieve it from
    /// <see cref="XRFingerShapeMath.CalculateFingerShape(XRHand, XRHandFingerID, XRFingerShapeTypes)"/> or
    /// <see cref="XRFingerShapeMath.CalculateFingerShape(XRHand, XRHandFingerID, XRFingerShapeTypes, XRFingerShapeConfiguration)"/>.
    /// </remarks>
    public struct XRFingerShape
    {
        internal XRFingerShapeTypes m_Types;
        internal float m_FullCurl;
        internal float m_BaseCurl;
        internal float m_TipCurl;
        internal float m_Pinch;
        internal float m_Spread;

        /// <summary>
        /// Each enabled flag signifies that the corresponding data was
        /// successfully updated.
        /// </summary>
        /// <remarks>
        /// May not necessarily match the types passed to
        /// <see cref="XRFingerShapeMath.CalculateFingerShape(XRHand, XRHandFingerID, XRFingerShapeTypes)"/> or
        /// <see cref="XRFingerShapeMath.CalculateFingerShape(XRHand, XRHandFingerID, XRFingerShapeTypes, XRFingerShapeConfiguration)"/>,
        /// as data required for the calculations is not guaranteed to be available.
        /// </remarks>
        public readonly XRFingerShapeTypes types => m_Types;

        /// <summary>
        /// Attempts to retrieve the full-curl value.
        /// </summary>
        /// <param name="fullCurl">
        /// If successful, will be set to the calculated full-curl value for the
        /// requested finger.
        /// </param>
        /// <returns>
        /// Returns <see langword="true"/> if successful and <paramref name="fullCurl"/>
        /// is set to a usable value. Otherwise, returns <see langword="false"/>.
        /// </returns>
        /// <remarks>
        /// Full-curl represents how curled the entire finger is. A value of
        /// <c>1</c> denotes a fully curled finger.
        /// </remarks>
        public readonly bool TryGetFullCurl(out float fullCurl)
        {
            var isFullCurlValid = (m_Types & XRFingerShapeTypes.FullCurl) != 0;
            fullCurl = isFullCurlValid ? m_FullCurl : 0f;
            return isFullCurlValid;
        }

        /// <summary>
        /// Attempts to retrieve the base-curl value.
        /// </summary>
        /// <param name="baseCurl">
        /// If successful, will be set to the calculated base-curl value for the
        /// requested finger.
        /// </param>
        /// <returns>
        /// Returns <see langword="true"/> if successful and <paramref name="baseCurl"/>
        /// is set to a usable value. Otherwise, returns <see langword="false"/>.
        /// </returns>
        /// <remarks>
        /// Base-curl represents the extent that the proximal joint is bent.
        /// </remarks>
        public readonly bool TryGetBaseCurl(out float baseCurl)
        {
            var isBaseCurlValid = (m_Types & XRFingerShapeTypes.BaseCurl) != 0;
            baseCurl = isBaseCurlValid ? m_BaseCurl : 0f;
            return isBaseCurlValid;
        }

        /// <summary>
        /// Attempts to retrieve the tip-curl value.
        /// </summary>
        /// <param name="tipCurl">
        /// If successful, will be set to the calculated tip-curl value for the
        /// requested finger.
        /// </param>
        /// <returns>
        /// Returns <see langword="true"/> if successful and <paramref name="tipCurl"/>
        /// is set to a usable value. Otherwise, returns <see langword="false"/>.
        /// </returns>
        /// <remarks>
        /// Tip curl represents how bent the top two joints of the finger or thumb are.
        /// This feature does not take the proximal joint into consideration.
        /// </remarks>
        public readonly bool TryGetTipCurl(out float tipCurl)
        {
            var isTipCurlValid = (m_Types & XRFingerShapeTypes.TipCurl) != 0;
            tipCurl = isTipCurlValid ? m_TipCurl : 0f;
            return isTipCurlValid;
        }

        /// <summary>
        /// Attempts to retrieve the pinch value.
        /// </summary>
        /// <param name="pinch">
        /// If successful, will be set to the calculated pinch value for the
        /// requested finger.
        /// </param>
        /// <returns>
        /// Returns <see langword="true"/> if successful and <paramref name="pinch"/>
        /// is set to a usable value. Otherwise, returns <see langword="false"/>.
        /// </returns>
        /// <remarks>
        /// Pinch represents the strength of the pinch between the requested
        /// finger tip and the thumb tip. Will never be valid for the thumb
        /// (will always have a value of <c>0</c> and this method will always
        /// return <see langword="false"/>).
        /// </remarks>
        public readonly bool TryGetPinch(out float pinch)
        {
            var isPinchValid = (m_Types & XRFingerShapeTypes.Pinch) != 0;
            pinch = isPinchValid ? m_Pinch : 0f;
            return isPinchValid;
        }

        /// <summary>
        /// Attempts to retrieve the spread value.
        /// </summary>
        /// <param name="spread">
        /// If successful, will be set to the calculated spread value for the
        /// requested finger.
        /// </param>
        /// <returns>
        /// Returns <see langword="true"/> if successful and <paramref name="spread"/>
        /// is set to a usable value. Otherwise, returns <see langword="false"/>.
        /// </returns>
        /// <remarks>
        /// Spread represents the normalized angle between two adjacent fingers,
        /// measured at the base of those two fingers. Will never be valid for
        /// the little finger (will always have a value of <c>0</c> and this
        /// method will always return <see langword="false"/>).
        /// </remarks>
        public readonly bool TryGetSpread(out float spread)
        {
            var isSpreadValid = (m_Types & XRFingerShapeTypes.Spread) != 0;
            spread = isSpreadValid ? m_Spread : 0f;
            return isSpreadValid;
        }

        /// <summary>
        /// Clears the state by setting all the types to None.
        /// </summary>
        internal void Clear() => m_Types = XRFingerShapeTypes.None;
    }
}
