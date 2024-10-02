namespace UnityEngine.XR.Hands
{
    /// <summary>
    /// Constants for <see cref="HelpURLAttribute"/> for XR Hands.
    /// </summary>
    internal class XRHelpURLConstants
    {
        const string k_ApiFolder = "api";
        const string k_ManualFolder = "manual";
        const string k_CurrentDocsVersion = "1.4";
        const string k_CurrentDocsBaseUrl = "https://docs.unity3d.com/Packages/com.unity.xr.hands@" + k_CurrentDocsVersion + "/";
        const string k_NamespaceRoot = "UnityEngine.XR.Hands.";

        const string k_CurrentApiDocsBaseUrl = k_CurrentDocsBaseUrl + k_ApiFolder + "/";

        /// <summary>
        /// Base documentation version for the current package version of XR Hands.
        /// </summary>
        internal static string currentDocsVersion => k_CurrentDocsVersion;

        /// <summary>
        /// Base URL for the current version of the XR Hands manual page.
        /// </summary>
        internal const string k_CurrentManualDocsBaseUrl = k_CurrentDocsBaseUrl + k_ManualFolder + "/";                

        /// <summary>
        /// Scripting API URL for <see cref="XRHandSkeletonDriver"/>.
        /// </summary>
        internal const string k_XRHandSkeletonDriver = k_CurrentApiDocsBaseUrl + k_NamespaceRoot + nameof(XRHandSkeletonDriver) + ".html";

        /// <summary>
        /// Scripting API URL for <see cref="XRHandTrackingEvents"/>.
        /// </summary>
        internal const string k_XRHandTrackingEvents = k_CurrentApiDocsBaseUrl + k_NamespaceRoot + nameof(XRHandTrackingEvents) + ".html";
        
        /// <summary>
        /// Scripting API URL for <see cref="XRHandMeshController"/>.
        /// </summary>
        internal const string k_XRHandMeshController = k_CurrentApiDocsBaseUrl + k_NamespaceRoot + nameof(XRHandMeshController) + ".html";
    }
}
