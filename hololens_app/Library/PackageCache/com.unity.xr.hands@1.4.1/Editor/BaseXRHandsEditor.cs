using UnityEngine;

namespace UnityEditor.XR.Hands
{
    /// <summary>
    /// Base class for custom editors in XR Hands
    /// </summary>
    public abstract class BaseXRHandsEditor : Editor
    {
        /// <summary>
        /// Draw the standard read-only Script property.
        /// </summary>
        protected virtual void DrawScript()
        {
            using (new EditorGUI.DisabledScope(true))
            {
                if (target is MonoBehaviour behaviour)
                    EditorGUILayout.ObjectField(EditorGUIUtility.TrTempContent("Script"), MonoScript.FromMonoBehaviour(behaviour), typeof(MonoBehaviour), false);
                else if (target is ScriptableObject scriptableObject)
                    EditorGUILayout.ObjectField(EditorGUIUtility.TrTempContent("Script"), MonoScript.FromScriptableObject(scriptableObject), typeof(ScriptableObject), false);
            }
        }
    }
}
