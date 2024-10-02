using NUnit.Framework;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SubsystemsImplementation.Extensions;
using UnityEngine.TestTools;
using UnityEngine.XR.Hands;
using UnityEngine.XR.Hands.ProviderImplementation;

class Tests
{
    [Test]
    public void TestFingerIDsToJointIDs()
    {
        Assert.AreEqual((int)XRHandFingerID.Thumb.GetFrontJointID() + 3, (int)XRHandFingerID.Thumb.GetBackJointID());
        Assert.AreEqual((int)XRHandFingerID.Index.GetFrontJointID() + 4, (int)XRHandFingerID.Index.GetBackJointID());
        Assert.AreEqual((int)XRHandFingerID.Middle.GetFrontJointID() + 4, (int)XRHandFingerID.Middle.GetBackJointID());
        Assert.AreEqual((int)XRHandFingerID.Ring.GetFrontJointID() + 4, (int)XRHandFingerID.Ring.GetBackJointID());
        Assert.AreEqual((int)XRHandFingerID.Little.GetFrontJointID() + 4, (int)XRHandFingerID.Little.GetBackJointID());

        Assert.IsTrue(XRHandFingerID.Thumb.GetBackJointID() < XRHandFingerID.Index.GetFrontJointID());
        Assert.IsTrue(XRHandFingerID.Index.GetBackJointID() < XRHandFingerID.Middle.GetFrontJointID());
        Assert.IsTrue(XRHandFingerID.Middle.GetBackJointID() < XRHandFingerID.Ring.GetFrontJointID());
        Assert.IsTrue(XRHandFingerID.Ring.GetBackJointID() < XRHandFingerID.Little.GetFrontJointID());
    }

    [Test]
    public void CanCreateTestSubsystem()
    {
        var subsystem = CreateTestSubsystem();
        Assert.AreNotEqual(subsystem, null);
        subsystem.Destroy();
    }

    [Test]
    public void SubsystemAsksForHandLayoutDuringCreate()
    {
        var subsystem = CreateTestSubsystem();

        var testProvider = subsystem.GetProvider() as TestHandProvider;
        Assert.IsNotNull(testProvider);
        Assert.AreEqual(1, testProvider.numGetHandLayoutCalls);

        subsystem.Destroy();
    }

    [Test]
    public void SubsystemWontAskProviderForHandDataWithoutStarting()
    {
        var subsystem = CreateTestSubsystem();
        for (var call = 0; call < 10; ++call)
        {
            var flags = subsystem.TryUpdateHands(
                ((call & 1) != 0)
                    ? XRHandSubsystem.UpdateType.Dynamic
                    : XRHandSubsystem.UpdateType.BeforeRender);
            Assert.AreEqual(XRHandSubsystem.UpdateSuccessFlags.None, flags);
        }

        var testProvider = subsystem.GetProvider() as TestHandProvider;
        Assert.IsNotNull(testProvider);
        Assert.AreEqual(0, testProvider.numTryUpdateHandsCalls);

        subsystem.Destroy();
    }

    [Test]
    public void SubsystemAsksForHandsDataIfRunning()
    {
        const int numUpdates = 10;
        var subsystem = CreateTestSubsystem();
        subsystem.Start();

        for (var call = 0; call < numUpdates; ++call)
        {
            var flags = subsystem.TryUpdateHands(
                ((call & 1) != 0)
                    ? XRHandSubsystem.UpdateType.Dynamic
                    : XRHandSubsystem.UpdateType.BeforeRender);
            Assert.AreEqual(XRHandSubsystem.UpdateSuccessFlags.All, flags);
        }

        var testProvider = subsystem.GetProvider() as TestHandProvider;
        Assert.IsNotNull(testProvider);
        Assert.AreEqual(numUpdates, testProvider.numTryUpdateHandsCalls);

        subsystem.Destroy();
    }

    [Test]
    public void HandsMarkedWithCorrectHandedness()
    {
        var subsystem = CreateTestSubsystem();

        Assert.AreEqual(Handedness.Left, subsystem.leftHand.handedness);
        Assert.AreEqual(Handedness.Right, subsystem.rightHand.handedness);

        subsystem.Destroy();
    }

    [Test]
    public void StopIsCalledImplcitlyOnDestroyIfRunning()
    {
        var subsystem = CreateTestSubsystem();
        subsystem.Start();
        subsystem.Destroy();

        var testProvider = subsystem.GetProvider() as TestHandProvider;
        Assert.IsNotNull(testProvider);
        Assert.AreEqual(1, testProvider.numStartCalls);
        Assert.AreEqual(1, testProvider.numStopCalls);
        Assert.AreEqual(1, testProvider.numDestroyCalls);
    }

    [Test]
    public void ProviderGivesValidHandDataWhenRunning()
    {
        var subsystem = CreateTestSubsystem();
        subsystem.Start();

        var updateFlags = subsystem.TryUpdateHands(XRHandSubsystem.UpdateType.Dynamic);
        Assert.AreEqual(XRHandSubsystem.UpdateSuccessFlags.All, updateFlags);

        AssertAreApproximatelyEqual(TestHandData.leftRoot, subsystem.leftHand.rootPose);
        AssertAreApproximatelyEqual(TestHandData.rightRoot, subsystem.rightHand.rootPose);

        int numValidLeftJoints = 0, numValidRightJoints = 0;
        for (int jointIndex = XRHandJointID.BeginMarker.ToIndex();
             jointIndex < XRHandJointID.EndMarker.ToIndex();
             ++jointIndex)
        {
            var id = XRHandJointIDUtility.FromIndex(jointIndex);

            var leftJoint = subsystem.leftHand.GetJoint(id);
            if (leftJoint.TryGetPose(out var leftPose))
            {
                ++numValidLeftJoints;
                AssertAreApproximatelyEqual(TestHandData.leftHand[jointIndex], leftPose);
            }
            else
            {
                Assert.IsFalse(subsystem.jointsInLayout[jointIndex]);
            }

            var rightJoint = subsystem.rightHand.GetJoint(id);
            if (rightJoint.TryGetPose(out var rightPose))
            {
                ++numValidRightJoints;
                AssertAreApproximatelyEqual(TestHandData.rightHand[jointIndex], rightPose);
            }
            else
            {
                Assert.IsFalse(subsystem.jointsInLayout[jointIndex]);
            }
        }

        Assert.AreEqual(26, numValidLeftJoints);
        Assert.AreEqual(26, numValidRightJoints);
        subsystem.Destroy();
    }

    [Test]
    public void MockProviderOnlyGivesHandPosesAndSensibleDefaults()
    {
        var subsystem = CreateTestSubsystem();
        subsystem.Start();

        var updateFlags = subsystem.TryUpdateHands(XRHandSubsystem.UpdateType.Dynamic);
        Assert.AreEqual(XRHandSubsystem.UpdateSuccessFlags.All, updateFlags);

        for (int jointIndex = XRHandJointID.BeginMarker.ToIndex();
             jointIndex < XRHandJointID.EndMarker.ToIndex();
             ++jointIndex)
        {
            var id = XRHandJointIDUtility.FromIndex(jointIndex);

            var leftJoint = subsystem.leftHand.GetJoint(id);
            Assert.AreEqual(XRHandJointTrackingState.Pose, leftJoint.trackingState);
            Assert.IsFalse(leftJoint.TryGetRadius(out var leftRadius));
            Assert.IsFalse(leftJoint.TryGetLinearVelocity(out var leftLinearVelocity));
            Assert.IsFalse(leftJoint.TryGetAngularVelocity(out var leftAngularVelocity));
            Assert.AreEqual(0f, leftRadius);
            Assert.AreEqual(Vector3.zero, leftLinearVelocity);
            Assert.AreEqual(Vector3.zero, leftAngularVelocity);

            var rightJoint = subsystem.rightHand.GetJoint(id);
            Assert.AreEqual(XRHandJointTrackingState.Pose, rightJoint.trackingState);
            Assert.IsFalse(rightJoint.TryGetRadius(out var rightRadius));
            Assert.IsFalse(rightJoint.TryGetLinearVelocity(out var rightLinearVelocity));
            Assert.IsFalse(rightJoint.TryGetAngularVelocity(out var rightAngularVelocity));
            Assert.AreEqual(0f, rightRadius);
            Assert.AreEqual(Vector3.zero, rightLinearVelocity);
            Assert.AreEqual(Vector3.zero, rightAngularVelocity);
        }

        subsystem.Destroy();
    }

    [Test]
    public void XRHandJointToStringNeverNull()
    {
        var subsystem = CreateTestSubsystem();

        for (int jointIndex = XRHandJointID.BeginMarker.ToIndex();
             jointIndex < XRHandJointID.EndMarker.ToIndex();
             ++jointIndex)
        {
            var id = XRHandJointIDUtility.FromIndex(jointIndex);
            var leftJoint = subsystem.leftHand.GetJoint(id);
            var rightJoint = subsystem.rightHand.GetJoint(id);
            Assert.AreNotEqual(null, leftJoint.ToString());
            Assert.AreNotEqual(null, rightJoint.ToString());
        }

        subsystem.Destroy();
    }

    [Test]
    public void ToIndexJustSubtractsOne()
    {
        Assert.AreEqual(XRHandJointID.Invalid.ToIndex(), (int)XRHandJointID.Invalid - 1);
        Assert.AreEqual(XRHandJointID.BeginMarker.ToIndex(), (int)XRHandJointID.BeginMarker - 1);
        Assert.AreEqual(XRHandJointID.Wrist.ToIndex(), (int)XRHandJointID.Wrist - 1);
        Assert.AreEqual(XRHandJointID.Palm.ToIndex(), (int)XRHandJointID.Palm - 1);
        Assert.AreEqual(XRHandJointID.ThumbMetacarpal.ToIndex(), (int)XRHandJointID.ThumbMetacarpal - 1);
        Assert.AreEqual(XRHandJointID.ThumbProximal.ToIndex(), (int)XRHandJointID.ThumbProximal - 1);
        Assert.AreEqual(XRHandJointID.ThumbDistal.ToIndex(), (int)XRHandJointID.ThumbDistal - 1);
        Assert.AreEqual(XRHandJointID.ThumbTip.ToIndex(), (int)XRHandJointID.ThumbTip - 1);
        Assert.AreEqual(XRHandJointID.IndexMetacarpal.ToIndex(), (int)XRHandJointID.IndexMetacarpal - 1);
        Assert.AreEqual(XRHandJointID.IndexProximal.ToIndex(), (int)XRHandJointID.IndexProximal - 1);
        Assert.AreEqual(XRHandJointID.IndexIntermediate.ToIndex(), (int)XRHandJointID.IndexIntermediate - 1);
        Assert.AreEqual(XRHandJointID.IndexDistal.ToIndex(), (int)XRHandJointID.IndexDistal - 1);
        Assert.AreEqual(XRHandJointID.IndexTip.ToIndex(), (int)XRHandJointID.IndexTip - 1);
        Assert.AreEqual(XRHandJointID.MiddleMetacarpal.ToIndex(), (int)XRHandJointID.MiddleMetacarpal - 1);
        Assert.AreEqual(XRHandJointID.MiddleProximal.ToIndex(), (int)XRHandJointID.MiddleProximal - 1);
        Assert.AreEqual(XRHandJointID.MiddleIntermediate.ToIndex(), (int)XRHandJointID.MiddleIntermediate - 1);
        Assert.AreEqual(XRHandJointID.MiddleDistal.ToIndex(), (int)XRHandJointID.MiddleDistal - 1);
        Assert.AreEqual(XRHandJointID.MiddleTip.ToIndex(), (int)XRHandJointID.MiddleTip - 1);
        Assert.AreEqual(XRHandJointID.RingMetacarpal.ToIndex(), (int)XRHandJointID.RingMetacarpal - 1);
        Assert.AreEqual(XRHandJointID.RingProximal.ToIndex(), (int)XRHandJointID.RingProximal - 1);
        Assert.AreEqual(XRHandJointID.RingIntermediate.ToIndex(), (int)XRHandJointID.RingIntermediate - 1);
        Assert.AreEqual(XRHandJointID.RingDistal.ToIndex(), (int)XRHandJointID.RingDistal - 1);
        Assert.AreEqual(XRHandJointID.RingTip.ToIndex(), (int)XRHandJointID.RingTip - 1);
        Assert.AreEqual(XRHandJointID.LittleMetacarpal.ToIndex(), (int)XRHandJointID.LittleMetacarpal - 1);
        Assert.AreEqual(XRHandJointID.LittleProximal.ToIndex(), (int)XRHandJointID.LittleProximal - 1);
        Assert.AreEqual(XRHandJointID.LittleIntermediate.ToIndex(), (int)XRHandJointID.LittleIntermediate - 1);
        Assert.AreEqual(XRHandJointID.LittleDistal.ToIndex(), (int)XRHandJointID.LittleDistal - 1);
        Assert.AreEqual(XRHandJointID.LittleTip.ToIndex(), (int)XRHandJointID.LittleTip - 1);
        Assert.AreEqual(XRHandJointID.EndMarker.ToIndex(), (int)XRHandJointID.EndMarker - 1);
    }

    [Test]
    public void FromIndexJustAddsOne()
    {
        Assert.AreEqual(XRHandJointIDUtility.FromIndex((int)XRHandJointID.Invalid - 1), XRHandJointID.Invalid);
        Assert.AreEqual(XRHandJointIDUtility.FromIndex((int)XRHandJointID.BeginMarker - 1), XRHandJointID.BeginMarker);
        Assert.AreEqual(XRHandJointIDUtility.FromIndex((int)XRHandJointID.Wrist - 1), XRHandJointID.Wrist);
        Assert.AreEqual(XRHandJointIDUtility.FromIndex((int)XRHandJointID.Palm - 1), XRHandJointID.Palm);
        Assert.AreEqual(XRHandJointIDUtility.FromIndex((int)XRHandJointID.ThumbMetacarpal - 1), XRHandJointID.ThumbMetacarpal);
        Assert.AreEqual(XRHandJointIDUtility.FromIndex((int)XRHandJointID.ThumbProximal - 1), XRHandJointID.ThumbProximal);
        Assert.AreEqual(XRHandJointIDUtility.FromIndex((int)XRHandJointID.ThumbDistal - 1), XRHandJointID.ThumbDistal);
        Assert.AreEqual(XRHandJointIDUtility.FromIndex((int)XRHandJointID.ThumbTip - 1), XRHandJointID.ThumbTip);
        Assert.AreEqual(XRHandJointIDUtility.FromIndex((int)XRHandJointID.IndexMetacarpal - 1), XRHandJointID.IndexMetacarpal);
        Assert.AreEqual(XRHandJointIDUtility.FromIndex((int)XRHandJointID.IndexProximal - 1), XRHandJointID.IndexProximal);
        Assert.AreEqual(XRHandJointIDUtility.FromIndex((int)XRHandJointID.IndexIntermediate - 1), XRHandJointID.IndexIntermediate);
        Assert.AreEqual(XRHandJointIDUtility.FromIndex((int)XRHandJointID.IndexDistal - 1), XRHandJointID.IndexDistal);
        Assert.AreEqual(XRHandJointIDUtility.FromIndex((int)XRHandJointID.IndexTip - 1), XRHandJointID.IndexTip);
        Assert.AreEqual(XRHandJointIDUtility.FromIndex((int)XRHandJointID.MiddleMetacarpal - 1), XRHandJointID.MiddleMetacarpal);
        Assert.AreEqual(XRHandJointIDUtility.FromIndex((int)XRHandJointID.MiddleProximal - 1), XRHandJointID.MiddleProximal);
        Assert.AreEqual(XRHandJointIDUtility.FromIndex((int)XRHandJointID.MiddleIntermediate - 1), XRHandJointID.MiddleIntermediate);
        Assert.AreEqual(XRHandJointIDUtility.FromIndex((int)XRHandJointID.MiddleDistal - 1), XRHandJointID.MiddleDistal);
        Assert.AreEqual(XRHandJointIDUtility.FromIndex((int)XRHandJointID.MiddleTip - 1), XRHandJointID.MiddleTip);
        Assert.AreEqual(XRHandJointIDUtility.FromIndex((int)XRHandJointID.RingMetacarpal - 1), XRHandJointID.RingMetacarpal);
        Assert.AreEqual(XRHandJointIDUtility.FromIndex((int)XRHandJointID.RingProximal - 1), XRHandJointID.RingProximal);
        Assert.AreEqual(XRHandJointIDUtility.FromIndex((int)XRHandJointID.RingIntermediate - 1), XRHandJointID.RingIntermediate);
        Assert.AreEqual(XRHandJointIDUtility.FromIndex((int)XRHandJointID.RingDistal - 1), XRHandJointID.RingDistal);
        Assert.AreEqual(XRHandJointIDUtility.FromIndex((int)XRHandJointID.RingTip - 1), XRHandJointID.RingTip);
        Assert.AreEqual(XRHandJointIDUtility.FromIndex((int)XRHandJointID.LittleMetacarpal - 1), XRHandJointID.LittleMetacarpal);
        Assert.AreEqual(XRHandJointIDUtility.FromIndex((int)XRHandJointID.LittleProximal - 1), XRHandJointID.LittleProximal);
        Assert.AreEqual(XRHandJointIDUtility.FromIndex((int)XRHandJointID.LittleIntermediate - 1), XRHandJointID.LittleIntermediate);
        Assert.AreEqual(XRHandJointIDUtility.FromIndex((int)XRHandJointID.LittleDistal - 1), XRHandJointID.LittleDistal);
        Assert.AreEqual(XRHandJointIDUtility.FromIndex((int)XRHandJointID.LittleTip - 1), XRHandJointID.LittleTip);
        Assert.AreEqual(XRHandJointIDUtility.FromIndex((int)XRHandJointID.EndMarker - 1), XRHandJointID.EndMarker);
    }

    [Test]
    public void SubsystemPassesUpdateTypeDirectlyToProvider()
    {
        var subsystem = CreateTestSubsystem();
        var testProvider = subsystem.GetProvider() as TestHandProvider;
        subsystem.Start();

        subsystem.TryUpdateHands(XRHandSubsystem.UpdateType.Dynamic);
        Assert.IsNotNull(testProvider);
        Assert.AreEqual(XRHandSubsystem.UpdateType.Dynamic, testProvider.mostRecentUpdateType);

        subsystem.TryUpdateHands(XRHandSubsystem.UpdateType.BeforeRender);
        Assert.AreEqual(XRHandSubsystem.UpdateType.BeforeRender, testProvider.mostRecentUpdateType);

        subsystem.Destroy();
    }

    [Test]
    public void HandsUpdatedCallbackWorks()
    {
        var flags = XRHandSubsystem.UpdateSuccessFlags.None;
        void OnUpdatedHands(XRHandSubsystem xrHandSubsystem, XRHandSubsystem.UpdateSuccessFlags updateSuccessFlags, XRHandSubsystem.UpdateType updateType) => flags = updateSuccessFlags;

        var subsystem = CreateTestSubsystem();
        subsystem.updatedHands += OnUpdatedHands;
        subsystem.Start();

        subsystem.TryUpdateHands(XRHandSubsystem.UpdateType.Dynamic);
        Assert.AreEqual(XRHandSubsystem.UpdateSuccessFlags.All, flags);

        subsystem.Destroy();
    }

    [Test]
    public void DescriptorCinfoEqualsReturnsTrue()
    {
        var testCinfo = new XRHandSubsystemDescriptor.Cinfo
        {
            id = TestHandProvider.descriptorId,
            providerType = typeof(TestHandProvider)
        };

        var testCinfo2 = new XRHandSubsystemDescriptor.Cinfo
        {
            id = TestHandProvider.descriptorId,
            providerType = typeof(TestHandProvider)
        };

        Assert.IsTrue(testCinfo.Equals(testCinfo2));
        Assert.AreEqual(testCinfo.GetHashCode(), testCinfo2.GetHashCode());
    }

    [Test]
    public void DescriptorCinfoEqualsReturnsFalse()
    {
        var testCinfo = new XRHandSubsystemDescriptor.Cinfo
        {
            id = TestHandProvider.descriptorId,
            providerType = typeof(TestHandProvider)
        };

        var testCinfo2 = new XRHandSubsystemDescriptor.Cinfo
        {
            id = "Dummy-Hands"
        };

        Assert.IsFalse(testCinfo.Equals(testCinfo2));
        Assert.AreNotEqual(testCinfo.GetHashCode(), testCinfo2.GetHashCode());
    }

    [Test]
    public void JointIDsMatch()
    {
        var subsystem = CreateTestSubsystem();
        subsystem.Start();

        var flags = subsystem.TryUpdateHands(XRHandSubsystem.UpdateType.Dynamic);
        Assert.AreEqual(XRHandSubsystem.UpdateSuccessFlags.All, flags);

        for (int jointIndex = XRHandJointID.BeginMarker.ToIndex();
             jointIndex < XRHandJointID.EndMarker.ToIndex();
             ++jointIndex)
        {
            var id = XRHandJointIDUtility.FromIndex(jointIndex);
            var leftJoint = subsystem.leftHand.GetJoint(id);
            var rightJoint = subsystem.rightHand.GetJoint(id);

            Assert.AreEqual(id, leftJoint.id);
            Assert.AreEqual(id, rightJoint.id);
        }

        subsystem.Destroy();
    }

    [Test]
    public void TestJointsAreInSubsystemLayout()
    {
        var subsystem = CreateTestSubsystem();

        for (int jointIndex = XRHandJointID.BeginMarker.ToIndex();
             jointIndex < XRHandJointID.EndMarker.ToIndex();
             ++jointIndex)
        {
            Assert.AreEqual(TestHandData.jointsInLayout[jointIndex], subsystem.jointsInLayout[jointIndex]);
        }

        subsystem.Destroy();
    }

    [UnityTest]
    public IEnumerator SubsystemUpdaterWorks()
    {
        var subsystem = CreateTestSubsystem();
        var updater = new XRHandProviderUtility.SubsystemUpdater(subsystem);
        try
        {
            bool updated = false;
            void OnUpdatedHands(XRHandSubsystem xrHandSubsystem, XRHandSubsystem.UpdateSuccessFlags successFlags, XRHandSubsystem.UpdateType updateType) => updated = true;
            subsystem.updatedHands += OnUpdatedHands;

            subsystem.Start();
            updater.Start();

            yield return null;
            Assert.IsTrue(updated);
        }
        finally
        {
            updater.Stop();
            updater.Destroy();
            subsystem.Destroy();
        }
    }

    [UnityTest]
    public IEnumerator HandTrackingEventCallbacks()
    {
        var subsystem = CreateTestSubsystem();
        var updater = new XRHandProviderUtility.SubsystemUpdater(subsystem);
        var provider = (TestHandProvider)subsystem.GetProvider();
        var go = new GameObject("TestHandTrackingEvents");

        try
        {
            subsystem.Start();
            updater.Start();
            yield return null;

            var rightHandTrackingEvents = go.AddComponent<XRHandTrackingEvents>();
            rightHandTrackingEvents.handedness = Handedness.Right;
            rightHandTrackingEvents.updateType = XRHandTrackingEvents.UpdateTypes.Dynamic;
            bool jointsUpdated = false, poseUpdated = false, trackingAcquired = false, trackingLost = false, trackingStateChanged = false;
            var jointsUpdateCallbackCount = 0;

            rightHandTrackingEvents.trackingAcquired.AddListener(() => trackingAcquired = true);
            rightHandTrackingEvents.trackingLost.AddListener(() => trackingLost = true);
            rightHandTrackingEvents.trackingChanged.AddListener(_ => trackingStateChanged = true);
            rightHandTrackingEvents.jointsUpdated.AddListener(_ =>
            {
                jointsUpdateCallbackCount++;
                jointsUpdated = true;
            });

            rightHandTrackingEvents.poseUpdated.AddListener(_ =>
            {
                poseUpdated = true;
            });

            rightHandTrackingEvents.SetSubsystem(subsystem);
            yield return null;

            // First acquire and first update
            Assert.AreEqual(1, jointsUpdateCallbackCount);
            Assert.IsTrue(rightHandTrackingEvents.handIsTracked);
            Assert.IsTrue(trackingAcquired);
            Assert.IsFalse(trackingLost);
            Assert.IsTrue(trackingStateChanged);
            Assert.IsTrue(jointsUpdated);
            Assert.IsTrue(poseUpdated);

            trackingStateChanged = false;
            yield return null;

            // Second update, no change to tracking state
            Assert.AreEqual(2, jointsUpdateCallbackCount);
            Assert.IsTrue(rightHandTrackingEvents.handIsTracked);
            Assert.IsFalse(trackingStateChanged);

            jointsUpdated = poseUpdated = trackingAcquired = trackingLost = trackingStateChanged = false;

            provider.rightHandIsTracked = false;

            yield return null;

            // Tracking changed (lost) no joints updated
            Assert.AreEqual(2, jointsUpdateCallbackCount);
            Assert.IsFalse(rightHandTrackingEvents.handIsTracked);
            Assert.IsTrue(trackingLost);
            Assert.IsTrue(trackingStateChanged);
            Assert.IsFalse(trackingAcquired);
            Assert.IsFalse(jointsUpdated);
            Assert.IsFalse(poseUpdated);

            jointsUpdated = poseUpdated = trackingAcquired = trackingLost = trackingStateChanged = false;
            provider.rightHandIsTracked = true;
            yield return null;

            // Tracking changed (acquired) and updated again
            Assert.AreEqual(3, jointsUpdateCallbackCount);
            Assert.IsTrue(rightHandTrackingEvents.handIsTracked);
            Assert.IsTrue(trackingAcquired);
            Assert.IsFalse(trackingLost);
            Assert.IsTrue(trackingStateChanged);
            Assert.IsTrue(jointsUpdated);
            Assert.IsTrue(poseUpdated);

            // Stopping tracking on the left hand does not affect the right hand
            jointsUpdated = poseUpdated = trackingAcquired = trackingLost = trackingStateChanged = false;
            provider.leftHandIsTracked = false;
            yield return null;

            Assert.AreEqual(4, jointsUpdateCallbackCount);
            Assert.IsTrue(rightHandTrackingEvents.handIsTracked);
            Assert.IsFalse(trackingAcquired);
            Assert.IsFalse(trackingLost);
            Assert.IsFalse(trackingStateChanged);
            Assert.IsTrue(jointsUpdated);
            Assert.IsTrue(poseUpdated);
        }
        finally
        {
            Object.DestroyImmediate(go);
            updater.Stop();
            updater.Destroy();
            subsystem.Destroy();
        }
    }

    static void EnsureTestSubsystemDescriptorRegistered()
    {
        var descriptors = new List<XRHandSubsystemDescriptor>();
        SubsystemManager.GetSubsystemDescriptors(descriptors);

        foreach (var descriptor in descriptors)
        {
            if (descriptor.id == TestHandProvider.descriptorId)
                return;
        }

        var handsSubsystemCinfo = new XRHandSubsystemDescriptor.Cinfo
        {
            id = TestHandProvider.descriptorId,
            providerType = typeof(TestHandProvider)
        };
        XRHandSubsystemDescriptor.Register(handsSubsystemCinfo);
    }

    static XRHandSubsystem CreateTestSubsystem()
    {
        EnsureTestSubsystemDescriptorRegistered();

        var descriptors = new List<XRHandSubsystemDescriptor>();
        SubsystemManager.GetSubsystemDescriptors(descriptors);

        foreach (var descriptor in descriptors)
        {
            if (descriptor.id == TestHandProvider.descriptorId)
                return descriptor.Create();
        }

        return null;
    }

    static void AssertAreApproximatelyEqual(float expected, float actual)
    {
        Assert.IsTrue(Mathf.Abs(actual - expected) <= k_EpsilonSqrt);
    }

    static void AssertAreApproximatelyEqual(Vector3 expected, Vector3 actual)
    {
        AssertAreApproximatelyEqual(expected.x, actual.x);
        AssertAreApproximatelyEqual(expected.y, actual.y);
        AssertAreApproximatelyEqual(expected.z, actual.z);
    }

    static void AssertAreApproximatelyEqual(Quaternion expected, Quaternion actual)
    {
        AssertAreApproximatelyEqual(expected.x, actual.x);
        AssertAreApproximatelyEqual(expected.y, actual.y);
        AssertAreApproximatelyEqual(expected.z, actual.z);
        AssertAreApproximatelyEqual(expected.w, actual.w);
    }

    static void AssertAreApproximatelyEqual(Pose expected, Pose actual)
    {
        AssertAreApproximatelyEqual(expected.position, actual.position);
        AssertAreApproximatelyEqual(expected.rotation, actual.rotation);
    }

    static readonly float k_EpsilonSqrt = Mathf.Sqrt(Mathf.Epsilon);
}
