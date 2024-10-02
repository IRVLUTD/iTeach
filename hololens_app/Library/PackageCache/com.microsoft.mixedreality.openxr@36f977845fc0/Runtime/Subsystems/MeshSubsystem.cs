// Copyright (c) Microsoft Corporation.
// Licensed under the MIT License.

using System.Collections.Generic;
using UnityEngine.XR;

namespace Microsoft.MixedReality.OpenXR
{
    internal class MeshSubsystemController : SubsystemController
    {
        // Must be the same as meshings.id in UnitySubsystemsManifest.json
        // and the same for RegisterLifecycleProvider in InputProvider.cpp
        public const string Id = "OpenXR Mesh Extension";

        private static List<XRMeshSubsystemDescriptor> s_MeshDescriptors = new List<XRMeshSubsystemDescriptor>();

        public MeshSubsystemController(IOpenXRContext context) : base(context)
        {
        }

        public override void OnSubsystemCreate(ISubsystemPlugin plugin)
        {
            plugin.CreateSubsystem<XRMeshSubsystemDescriptor, XRMeshSubsystem>(s_MeshDescriptors, Id);
        }

        public override void OnSubsystemDestroy(ISubsystemPlugin plugin)
        {
            plugin.DestroySubsystem<XRMeshSubsystem>();
        }
    }
}
