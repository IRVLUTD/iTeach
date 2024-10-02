// Copyright (c) Microsoft Corporation.
// Licensed under the MIT License.
using System;
using System.Collections.Generic;
using System.Threading.Tasks;

namespace Microsoft.MixedReality.OpenXR
{
    /// <summary>
    /// Type of tracking maps
    /// </summary>
    public enum TrackingMapType : uint
    {
        /// <summary>
        /// Default tracking map on HoloLens 2, shared between all applications.
        /// </summary>
        Shared = 0,
        /// <summary>
        /// New tracking environment private to application, which can be persisted
        /// and restored with some limitations.
        /// </summary>
        ApplicationExclusive = 0x00000001
    }

    /// <summary>
    /// TrackingMapManager class allows an application to opt into running in an Application-Exclusive tracking mode instead of default shared environment.
    /// </summary>
    /// <remarks>
    /// <para>
    /// Activating an Application-Exclusive tracking map creates a brand-new environment for the application, unencumbered by any Device Space
    /// tracking inaccuracies as the result of degradation over time.
    /// This is equivalent to using the "Remove All Holograms" command from Settings, but only applicable to the running application.
    /// Holograms for all other applications (including the HoloLens Shell) remain intact and available as before.
    /// Returning to the Shell or activating another application will return the HoloLens to the Device Shared tracking mode automatically.
    /// </para>
    /// <para>
    /// When first entering the Application-Exclusive tracking mode, the calling application will be issued a unique identifier
    /// that can be used to resume tracking the app-specific map in future sessions of the application
    /// (like if the user switches away from the application and it is terminated in the background due to system resource constraints).
    /// However, if the device simply goes to sleep or the user briefly interacts with the Shell,
    /// the application will automatically resume in the Application-Exclusive tracking mode once it is reactivated (and all application state will remain available).
    /// </para>
    /// <para>
    /// There are two limitations to be aware of when using the Application-Exclusive tracking mode:
    /// </para>
    /// <list type="number">
    /// <item>
    /// <description>Only a single Application-Exclusive tracking map can exist on the HoloLens at one time. If an application requests a new Application-Exclusive tracking mode,
    /// then any previous Application-Exclusive tracking data would be erased and all SpatialAnchor objects (and attached holograms) would be lost,
    /// even if the data was created by a completely different application using its own Application-Exclusive tracking mode.
    /// Therefore, attempting to return to a previous Application-Exclusive map (by specifying the identifier received when this map was created)
    /// may result in a return value indicating that the previous map was not found.
    /// Applications must be prepared to handle the scenario where a previous Application-Exclusive tracking map is not available. </description>
    /// </item>
    /// <item>
    /// <description> The disk storage available to the Application-Exclusive tracking mode is limited to one third of what is available for the Device Shared tracking mode,
    /// although this is unlikely to be an issue for most users. When this limit is reached, HoloLens will begin erasing its least valuable tracking data,
    /// which will eventually result in poorer tracking accuracy.
    /// The smaller limit is still large enough to maintain good accuracy for house-sized environments and is unlikely to be a concern for most application scenarios.</description>
    /// </item>
    /// </list>
    /// <para>Given these limitations, the target scenario for the Application-Exclusive tracking mode is for applications with high accuracy requirements that are task oriented,
    /// where a task may be interrupted by the user returning the HoloLens Shell or the device going to sleep.
    /// However, once the user's task is complete, nothing about the task (with respect to the 3D environment) needs to be saved and so can be erased.
    /// </para>
    /// <para>Examples:</para>
    /// <list type="number">
    /// <item>
    /// <description> High-accuracy alignment of holograms to a real-world object, using QR codes to bootstrap the scenario. </description>
    /// </item>
    /// <item>
    /// <description> Editing a 3D model with high-accuracy requirements when no 3D spatial persistence of the model needs to occur after the session ends. </description>
    /// </item>
    /// <item>
    /// <description> Tracking in places that have a lot of environmental churn (like people moving around), which sometimes results in poorer tracking quality than more static environments. </description>
    /// </item>
    /// </list>
    /// </remarks>
    public class TrackingMapManager
    {
        private TrackingMapSubsystem m_trackingMapSubsystem;
        private TrackingMapManager(TrackingMapSubsystem trackingMapSubsystem) {
            m_trackingMapSubsystem = trackingMapSubsystem;
        }

        /// <summary>
        /// Gets an instance of TrackingMapManager.
        /// </summary>
        /// <returns><c>Task&lt;TrackingMapManager&gt;</c> which is completed when the Tracking Map Manager is fully initialized.
        /// The <c>Result</c> property of the task is a <c>TrackingMapManager</c> instance.</returns>
        /// <remarks>Use <see cref="IsSupported(TrackingMapType)"><c>IsSupported</c></see> to check if the HoloLens 2
        /// on which the application is currently executing supports Application-Exclusive maps.</remarks>
        public static Task<TrackingMapManager> GetAsync()
        {
            Task<TrackingMapManager> result = Task.Run(() =>
            {
                TrackingMapSubsystem trackingMapSubsystem = TrackingMapSubsystem.TryCreateTrackingMapSubsystem();
                return new TrackingMapManager(trackingMapSubsystem);
            });
            return result;
        }

        /// <summary>
        /// Indicates if a tracking map type is supported
        /// </summary>
        /// <param name="trackingMapType">Tracking map type to check for support</param>
        /// <returns>True if the tracking map type is supported.</returns>
        /// <remarks>
        /// TrackingMapType.Shared is always supported.
        /// </remarks>
        public bool IsSupported(TrackingMapType trackingMapType)
        {
            switch (trackingMapType)
            {
                case TrackingMapType.Shared:
                    return true;
                case TrackingMapType.ApplicationExclusive:
                    return (m_trackingMapSubsystem != null) && m_trackingMapSubsystem.SupportsApplicationExclusiveMaps();
                default:
                    return false;
            }
        }

        /// <summary>
        /// Indicates the active tracking map type.
        /// </summary>
        public TrackingMapType ActiveTrackingMapType
        {
            get => (m_trackingMapSubsystem != null) ? m_trackingMapSubsystem.ActiveTrackingMapType : TrackingMapType.Shared;
        }

        /// <summary>
        /// Creates and activates a new application-exclusive map.
        /// </summary>
        /// <param name="existingMapId">Optional identifier to try reactivating a previously created map. If null is passed, a new map is created.
        /// If a non empty guid map is passed, the tracking manager tries to load the corresponding map.
        /// If the map cannot be found or loaded, a new map is created.</param>
        /// <returns><c>Task&lt;Guid&gt;</c> which is completed when the system has created and activated an application-exclusive map.
        /// The <c>Result</c> property contains the guid of the activated map. If it is equal to <c>existingMapId</c>, it means that the existing map has been reloaded.
        /// If not, it means that a new map has been created.</returns>
        /// <exception cref="System.InvalidOperationException">Thrown when the TrackingMapManager does not support application-exclusive Maps
        /// or if a map change is already in progress.</exception>
        /// <remarks>In order to take effect, the application must be the active, immersive 3D application.
        /// <c>ActivateApplicationExclusiveMapAsync</c> should only be called once the application has started rendering its 3D user interface (and not, for example, when the application first starts).
        /// </remarks>
        public Task<Guid> ActivateApplicationExclusiveMapAsync(Guid? existingMapId = null)
        {
            if (m_trackingMapSubsystem == null) throw new InvalidOperationException("Feature not supported.");
            Task<Guid> result = Task.Run(() =>
            {
                return m_trackingMapSubsystem.ActivateApplicationExclusiveMap(existingMapId);
            });
            return result;
        }

        /// <summary>
        /// Leaves the current application-exclusive map and returns to the default shared map.
        /// If the device was already in the default shared map, this method does nothing.
        /// </summary>
        /// <returns><c>Task</c> which is completed when the system has returned to the default map.</returns>
        /// <exception cref="System.InvalidOperationException">Thrown when a map change is already in progress.</exception>
        public Task ActivateSharedMapAsync()
        {
            if (m_trackingMapSubsystem == null) throw new InvalidOperationException("Feature not supported.");
            Task result = Task.Run(() =>
            {
                m_trackingMapSubsystem.ActivateSharedMapAsync();
            });
            return result;
        }
    }
}
