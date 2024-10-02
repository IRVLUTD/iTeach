// Copyright (c) Microsoft Corporation.
// Licensed under the MIT License.

using System;
using UnityEngine.SubsystemsImplementation;

namespace Microsoft.MixedReality.OpenXR.ARSubsystems
{
    public class XRMarkerSubsystemDescriptor :
        SubsystemDescriptorWithProvider<XRMarkerSubsystem, XRMarkerSubsystem.Provider>
    {
        internal struct Cinfo
        {
            /// <summary>
            /// The string identifier for a specific implementation.
            /// </summary>
            internal string id { get; set; }

            /// <summary>
            /// Specifies the provider implementation type to use for instantiation.
            /// </summary>
            /// <value>
            /// The provider implementation type to use for instantiation.
            /// </value>
            internal Type providerType { get; set; }

            /// <summary>
            /// Specifies the <c>XRMarkerSubsystem</c>-derived type that forwards casted calls to its provider.
            /// </summary>
            /// <value>
            /// The type of the subsystem to use for instantiation. If null, <c>XRMarkerSubsystem</c> will be instantiated.
            /// </value>
            internal Type subsystemTypeOverride { get; set; }
        }

        /// <summary>
        /// Creates a new subsystem descriptor and registers it with the <c>SubsystemManager</c>.
        /// </summary>
        /// <param name="cinfo">Construction info for the descriptor.</param>
        internal static void Create(Cinfo cinfo)
        {
            var descriptor = new XRMarkerSubsystemDescriptor(cinfo);
            SubsystemDescriptorStore.RegisterDescriptor(descriptor);
        }

        private XRMarkerSubsystemDescriptor(Cinfo cinfo)
        {
            id = cinfo.id;
            providerType = cinfo.providerType;
            subsystemTypeOverride = cinfo.subsystemTypeOverride;
        }
    }
}