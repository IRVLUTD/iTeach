---
uid: xrhands-implement-a-provider
---
# Implement a provider

To implement a provider for the subsystem in this package (for example, say you are a hardware manufacturer for a new XR device), Unity recommends that your implementation inherit from [XRHandSubsystem](xref:UnityEngine.XR.Hands.XRHandSubsystem) if you have platform-specific data you wish to surface. This subsystem base class has a corresponding abstract class called [XRHandSubsystemProvider](xref:UnityEngine.XR.Hands.ProviderImplementation.XRHandSubsystemProvider), which is the primary interface you must implement to support on your platform.

Subsystem implementations should be independent from each other. For example, your implementation of the [XRHandSubsystem](xref:UnityEngine.XR.Hands.XRHandSubsystem) should have the same behavior whether or not other subsystem implementations are also active in a user's scene.

## Register a subsystem descriptor

Each subsystem type has a corresponding subsystem descriptor type. Your provider should create and register a subsystem descriptor instance with Unity's [SubsystemManager](https://docs.unity3d.com/ScriptReference/SubsystemManager.html) to enable runtime discovery and activation of subsystems. To register your subsystem descriptor, include a static void method with the `[RuntimeInitializeOnLoadMethod(RuntimeInitializeLoadType.SubsystemRegistration)]` attribute as shown in the example below, and in it call `XRHandSubsystemDescriptor.Register` with subsystem descriptor information you are registering.

```csharp
// This class defines a hand subsystem provider
class MyHandProvider : XRHandSubsystemProvider
{
    // ...
}

// This class defines a hand subsystem
class MyHandSubsystem : XRHandSubsystem
{
    public int myPlatformSpecificData => provider.RetrievePlatformSpecificData();

    // This method registers the subsystem descriptor with the SubsystemManager
    [RuntimeInitializeOnLoadMethod(RuntimeInitializeLoadType.SubsystemRegistration)]
    static void RegisterDescriptor()
    {
        var handsSubsystemCinfo = new XRHandSubsystemDescriptor.Cinfo
        {
            id = "My-Hands",
            providerType = typeof(MyHandProvider),
            subsystemTypeOverride = typeof(MyHandSubsystem)
        };
        XRHandSubsystemDescriptor.Register(handsSubsystemCinfo);
    }
}
```

## Implement an XR Loader

An `XRLoader` is responsible for creating and destroying subsystem instances based on the settings found in **Project Settings** > **XR Plug-in Management**. All provider plug-ins must implement an `XRLoader`. For more information on authoring an `XRLoader`, see the [XR Plug-in Management provider documentation](https://docs.unity3d.com/Packages/com.unity.xr.management@latest?subfolder=/manual/Provider.html).
