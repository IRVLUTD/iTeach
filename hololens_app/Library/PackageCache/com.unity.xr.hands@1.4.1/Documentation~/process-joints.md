---
uid: xrhands-process-joints
---
# Process joints

If you wish to process or filter joint data before it's returned to the subsystem caller, derive a `class` from `IXRHandProcessor` and register it with `XRHandSubsystem.RegisterProcessor` in a static method decorated with `[RuntimeInitializeOnLoadMethod(RuntimeInitializeLoadType.SubsystemRegistration)]`. `IXRHandProcessor`s with a lower `callbackOrder` value will be called sooner than this with higher values for their `callbackOrder`.

If you wish to access the joint data before anyone has had a chance to process the joints, you can use `XRHandSubsystem.preprocessJoints`.

> [!NOTE]
> This is an advanced use case. Typically, you should use the `XRHandSubsystem`'s `updatedHands` callback and just consume the data instead of altering it in any way.

Use extension methods in `UnityEngine.XR.Hands.Processing.XRHandProcessingUtility`. The below sample code demonstrates how to set pose data before it's returned to the subsystem.

```csharp
using UnityEngine.XR.Hands.Processing;

public class MyHandProcessor : MonoBehaviour, IXRHandProcessor
{
    public int callbackOrder => 0;

    public void ProcessJoints(XRHandSubsystem subsystem, XRHandSubsystem.UpdateSuccessFlags successFlags, XRHandSubsystem.UpdateType updateType)
    {
        var leftHand = subsystem.leftHand;
        leftHand.SetRootPose(Pose.identity);
        subsystem.SetCorrespondingHand(leftHand);

        var rightHand = subsystem.rightHand;
        rightHand.SetRootPose(Pose.identity);
        subsystem.SetCorrespondingHand(rightHand);

        var leftJoints = leftHand.GetRawJointArray();
        var rightJoints = rightHand.GetRawJointArray();
        for (int jointIndex = 0; jointIndex < leftJoints.Length; ++jointIndex)
        {
            var leftJoint = leftJoints[jointIndex];
            leftJoint.SetPose(Pose.identity);
            leftJoints[jointIndex] = leftJoint;

            var rightJoint = rightJoints[jointIndex];
            rightJoint.SetPose(Pose.identity);
            rightJoints[jointIndex] = rightJoint;
        }
    }

    void Update()
    {
        if (m_Registered)
            return;

        SubsystemManager.GetSubsystems(s_SubsystemsReuse);
        if (s_SubsystemsReuse.Count == 0)
            return;

        m_Subsystem = s_SubsystemsReuse[0];
        m_Subsystem.RegisterProcessor(this);
        m_Registered = true;
    }

    void OnDisable()
    {
        if (m_Subsystem != null)
        {
            m_Subsystem.UnregisterProcessor(this);
            m_Subsystem = null;
            m_Registered = false;
        }
    }

    bool m_Registered;
    XRHandSubsystem m_Subsystem;

    static List<XRHandSubsystem> s_SubsystemsReuse = new List<XRHandSubsystem>();
}
```

See sample `HandProcessor` script in the `HandVisualizer` sample for a more useful example of how to use this functionality.
