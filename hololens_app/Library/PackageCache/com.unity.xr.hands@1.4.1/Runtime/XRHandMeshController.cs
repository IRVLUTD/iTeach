using System;

namespace UnityEngine.XR.Hands
{
    /// <summary>
    /// A component that controls the visual representation for an <see cref="XRHand"/> in the scene.
    /// This component subscribes to events from an <see cref="XRHandTrackingEvents"/> component to enable and disable a mesh renderer when tracking is acquired or lost.
    /// </summary>
    [HelpURL(XRHelpURLConstants.k_XRHandMeshController)]
    public class XRHandMeshController : MonoBehaviour
    {
        [SerializeField]
        [Tooltip("The XR Hand Tracking Events component that will be used to subscribe to hand tracking events.")]
        XRHandTrackingEvents m_XRHandTrackingEvents;
        
        [SerializeField]
        [Tooltip("The renderer that is rendering the hand mesh.")]
        Renderer m_HandMeshRenderer;

        [SerializeField]
        [Tooltip("If enabled, the hand mesh renderer will be enabled when the hand tracking is acquired.")]
        bool m_ShowMeshWhenTrackingIsAcquired = true;
        
        [SerializeField]
        [Tooltip("If enabled, the hand mesh renderer will be disabled when the hand tracking is lost.")]
        bool m_HideMeshWhenTrackingIsLost = true;

        bool m_HandIsTracked;

        /// <summary>
        /// Whether the hand for this visual is currently being tracked
        /// </summary>
        public bool handIsTracked => m_HandIsTracked;

        /// <summary>
        /// If enabled, the hand mesh renderer will be enabled when the hand tracking is acquired.
        /// </summary>
        public bool showMeshWhenTrackingIsAcquired
        {
            get => m_ShowMeshWhenTrackingIsAcquired;
            set
            {
                m_ShowMeshWhenTrackingIsAcquired = value;

                if (Application.isPlaying)
                    UpdateRendererVisibility();
            }
        }

        /// <summary>
        /// If enabled, the hand mesh renderer will be disabled when the hand tracking is lost.
        /// </summary>
        public bool hideMeshWhenTrackingIsLost
        {
            get => m_HideMeshWhenTrackingIsLost;
            set
            {
                m_HideMeshWhenTrackingIsLost = value;

                if (Application.isPlaying)
                    UpdateRendererVisibility();
            }
        }

        /// <summary>
        /// The renderer used to draw the hand mesh.
        /// </summary>
        public Renderer handMeshRenderer
        {
            get => m_HandMeshRenderer;
            set
            {
                m_HandMeshRenderer = value;

                if (Application.isPlaying)
                    UpdateRendererVisibility();
            }
        }

        /// <summary>
        /// The <see cref="XRHandTrackingEvents"/> component that will be the source of hand tracking events for this mesh controller.
        /// </summary>
        public XRHandTrackingEvents handTrackingEvents
        {
            get => m_XRHandTrackingEvents;
            set
            {
                if (Application.isPlaying)
                    UnsubscribeFromHandTrackingEvents();

                m_XRHandTrackingEvents = value;

                if (Application.isPlaying && isActiveAndEnabled)
                    SubscribeToHandTrackingEvents();
            }
        }

        /// <summary>
        /// See <see cref="MonoBehaviour"/>.
        /// </summary>
        protected virtual void Reset()
        {
            TryGetComponent(out m_XRHandTrackingEvents);
        }

        /// <summary>
        /// See <see cref="MonoBehaviour"/>.
        /// </summary>
        protected virtual void OnEnable()
        {
            if (m_XRHandTrackingEvents == null)
                TryGetComponent(out m_XRHandTrackingEvents);

            if (m_XRHandTrackingEvents == null)
            {
                Debug.LogError("The XR Hand Mesh Controller requires an XR Hand Tracking Events component to subscribe to hand tracking events.", this);
                return;
            }

            SubscribeToHandTrackingEvents();
        }

        /// <summary>
        /// See <see cref="MonoBehaviour"/>.
        /// </summary>
        protected virtual void OnDisable()
        {
            UnsubscribeFromHandTrackingEvents();
        }

        void SubscribeToHandTrackingEvents()
        {
            if (m_XRHandTrackingEvents != null)
            {
                m_XRHandTrackingEvents.bindableHandIsTracked.SubscribeAndUpdate(OnTrackingChanged);
            }
        }

        void UnsubscribeFromHandTrackingEvents()
        {
            if (m_XRHandTrackingEvents != null)
            {
                m_XRHandTrackingEvents.bindableHandIsTracked.Unsubscribe(OnTrackingChanged);
            }
        }

        void OnTrackingChanged(bool isTracked)
        {
            m_HandIsTracked = isTracked;
            UpdateRendererVisibility();
        }

        void UpdateRendererVisibility()
        {
            if (m_HandIsTracked && m_ShowMeshWhenTrackingIsAcquired)
            {
                m_HandMeshRenderer.enabled = true;
            }
            else if (!m_HandIsTracked && m_HideMeshWhenTrackingIsLost)
            {
                m_HandMeshRenderer.enabled = false;
            }
        }
    }
}
