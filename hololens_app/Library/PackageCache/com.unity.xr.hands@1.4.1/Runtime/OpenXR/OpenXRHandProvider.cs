#if UNITY_OPENXR_PACKAGE || PACKAGE_DOCS_GENERATION

using System;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;
using Unity.Collections;
using Unity.Collections.LowLevel.Unsafe;
using UnityEngine.XR.Hands;
using UnityEngine.XR.Hands.ProviderImplementation;
using UnityEngine.XR.OpenXR;
using UnityEngine.XR.OpenXR.Features;

namespace UnityEngine.XR.Hands.OpenXR
{
    /// <summary>
    /// Hand tracking provider for the OpenXR platform.
    /// </summary>
    public unsafe class OpenXRHandProvider : XRHandSubsystemProvider
    {
        /// <summary>
        /// See <see cref="UnityEngine.SubsystemsImplementation.SubsystemProvider{T}.Start"/>.
        /// </summary>
        public override void Start() {}

        /// <summary>
        /// See <see cref="UnityEngine.SubsystemsImplementation.SubsystemProvider{T}.Stop"/>.
        /// </summary>
        public override void Stop() {}

        /// <summary>
        /// See <see cref="UnityEngine.SubsystemsImplementation.SubsystemProvider{T}.Destroy"/>.
        /// </summary>
        public override void Destroy() => NativeApi.Destroy();

        /// <inheritdoc/>
        public override void GetHandLayout(NativeArray<bool> handJointsInLayout)
        {
            if (!NativeApi.TryInitialize())
            {
                Debug.LogError("OpenXR hand provider failed to initialize - no data will be tracked or surfaced!");
                return;
            }

            handJointsInLayout[XRHandJointID.Palm.ToIndex()] = true;
            handJointsInLayout[XRHandJointID.Wrist.ToIndex()] = true;

            handJointsInLayout[XRHandJointID.ThumbMetacarpal.ToIndex()] = true;
            handJointsInLayout[XRHandJointID.ThumbProximal.ToIndex()] = true;
            handJointsInLayout[XRHandJointID.ThumbDistal.ToIndex()] = true;
            handJointsInLayout[XRHandJointID.ThumbTip.ToIndex()] = true;

            handJointsInLayout[XRHandJointID.IndexMetacarpal.ToIndex()] = true;
            handJointsInLayout[XRHandJointID.IndexProximal.ToIndex()] = true;
            handJointsInLayout[XRHandJointID.IndexIntermediate.ToIndex()] = true;
            handJointsInLayout[XRHandJointID.IndexDistal.ToIndex()] = true;
            handJointsInLayout[XRHandJointID.IndexTip.ToIndex()] = true;

            handJointsInLayout[XRHandJointID.MiddleMetacarpal.ToIndex()] = true;
            handJointsInLayout[XRHandJointID.MiddleProximal.ToIndex()] = true;
            handJointsInLayout[XRHandJointID.MiddleIntermediate.ToIndex()] = true;
            handJointsInLayout[XRHandJointID.MiddleDistal.ToIndex()] = true;
            handJointsInLayout[XRHandJointID.MiddleTip.ToIndex()] = true;

            handJointsInLayout[XRHandJointID.RingMetacarpal.ToIndex()] = true;
            handJointsInLayout[XRHandJointID.RingProximal.ToIndex()] = true;
            handJointsInLayout[XRHandJointID.RingIntermediate.ToIndex()] = true;
            handJointsInLayout[XRHandJointID.RingDistal.ToIndex()] = true;
            handJointsInLayout[XRHandJointID.RingTip.ToIndex()] = true;

            handJointsInLayout[XRHandJointID.LittleMetacarpal.ToIndex()] = true;
            handJointsInLayout[XRHandJointID.LittleProximal.ToIndex()] = true;
            handJointsInLayout[XRHandJointID.LittleIntermediate.ToIndex()] = true;
            handJointsInLayout[XRHandJointID.LittleDistal.ToIndex()] = true;
            handJointsInLayout[XRHandJointID.LittleTip.ToIndex()] = true;

            m_IsValid = true;
        }

        /// <inheritdoc/>
        public override XRHandSubsystem.UpdateSuccessFlags TryUpdateHands(
            XRHandSubsystem.UpdateType updateType,
            ref Pose leftHandRootPose,
            NativeArray<XRHandJoint> leftHandJoints,
            ref Pose rightHandRootPose,
            NativeArray<XRHandJoint> rightHandJoints)
        {
            if (!m_IsValid)
                return XRHandSubsystem.UpdateSuccessFlags.None;

            return NativeApi.TryUpdateHands(
                updateType,
                ref leftHandRootPose,
                leftHandJoints.GetUnsafePtr(),
                ref rightHandRootPose,
                rightHandJoints.GetUnsafePtr());
        }

        bool m_IsValid;

        static internal string id { get; private set; }

        static OpenXRHandProvider() => id = "OpenXR Hands";

        [RuntimeInitializeOnLoadMethod(RuntimeInitializeLoadType.SubsystemRegistration)]
        static void Register()
        {
            var settings = OpenXRSettings.Instance;
            if (settings == null)
                return;

            var feature = settings.GetFeature<HandTracking>();
            if (feature != null && feature.enabled)
            {
                var handsSubsystemCinfo = new XRHandSubsystemDescriptor.Cinfo
                {
                    id = id,
                    providerType = typeof(OpenXRHandProvider)
                };
                XRHandSubsystemDescriptor.Register(handsSubsystemCinfo);
            }
        }

        static class NativeApi
        {
            [DllImport(HandTracking.k_LibraryName, EntryPoint = "UnityOpenXRHands_TryInitialize")]
            internal static extern bool TryInitialize();

            [DllImport(HandTracking.k_LibraryName, EntryPoint = "UnityOpenXRHands_Destroy")]
            internal static extern void Destroy();

            [DllImport(HandTracking.k_LibraryName, EntryPoint = "UnityOpenXRHands_TryUpdateHands")]
            internal static unsafe extern XRHandSubsystem.UpdateSuccessFlags TryUpdateHands(
                XRHandSubsystem.UpdateType updateType,
                ref Pose leftRootPose,
                void* leftHandJoints,
                ref Pose rightRootPose,
                void* rightHandJoints);
        }
    }
}

#endif // UNITY_OPENXR_PACKAGE || PACKAGE_DOCS_GENERATION
