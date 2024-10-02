using UnityEngine;
using UnityEngine.XR.Hands;

static class TestHandData
{
    public static readonly bool[] jointsInLayout;

    public static readonly Pose leftRoot;
    public static readonly Pose[] leftHand;

    public static readonly Pose rightRoot;
    public static readonly Pose[] rightHand;

    static TestHandData()
    {
        // this uses data captured from a run on OpenXR, so the data layout matches that
        jointsInLayout = new bool[XRHandJointID.EndMarker.ToIndex()];
        jointsInLayout[XRHandJointID.Palm.ToIndex()] = true;
        jointsInLayout[XRHandJointID.Wrist.ToIndex()] = true;
        jointsInLayout[XRHandJointID.ThumbMetacarpal.ToIndex()] = true;
        jointsInLayout[XRHandJointID.ThumbProximal.ToIndex()] = true;
        jointsInLayout[XRHandJointID.ThumbDistal.ToIndex()] = true;
        jointsInLayout[XRHandJointID.ThumbTip.ToIndex()] = true;
        jointsInLayout[XRHandJointID.IndexMetacarpal.ToIndex()] = true;
        jointsInLayout[XRHandJointID.IndexProximal.ToIndex()] = true;
        jointsInLayout[XRHandJointID.IndexIntermediate.ToIndex()] = true;
        jointsInLayout[XRHandJointID.IndexDistal.ToIndex()] = true;
        jointsInLayout[XRHandJointID.IndexTip.ToIndex()] = true;
        jointsInLayout[XRHandJointID.MiddleMetacarpal.ToIndex()] = true;
        jointsInLayout[XRHandJointID.MiddleProximal.ToIndex()] = true;
        jointsInLayout[XRHandJointID.MiddleIntermediate.ToIndex()] = true;
        jointsInLayout[XRHandJointID.MiddleDistal.ToIndex()] = true;
        jointsInLayout[XRHandJointID.MiddleTip.ToIndex()] = true;
        jointsInLayout[XRHandJointID.RingMetacarpal.ToIndex()] = true;
        jointsInLayout[XRHandJointID.RingProximal.ToIndex()] = true;
        jointsInLayout[XRHandJointID.RingIntermediate.ToIndex()] = true;
        jointsInLayout[XRHandJointID.RingDistal.ToIndex()] = true;
        jointsInLayout[XRHandJointID.RingTip.ToIndex()] = true;
        jointsInLayout[XRHandJointID.LittleMetacarpal.ToIndex()] = true;
        jointsInLayout[XRHandJointID.LittleProximal.ToIndex()] = true;
        jointsInLayout[XRHandJointID.LittleIntermediate.ToIndex()] = true;
        jointsInLayout[XRHandJointID.LittleDistal.ToIndex()] = true;
        jointsInLayout[XRHandJointID.LittleTip.ToIndex()] = true;

        leftRoot = new Pose(
            new Vector3(-0.05319f, 1.14112f, 0.08206f),
            new Quaternion(0.37018f, -0.42667f, -0.23629f, -0.79063f));

        leftHand = new Pose[XRHandJointID.EndMarker.ToIndex()];
        leftHand[XRHandJointID.Wrist.ToIndex()] = new Pose(
            new Vector3(-0.08227f, 1.09858f, 0.06240f),
            new Quaternion(0.37018f, -0.42667f, -0.23629f, -0.79063f));
        leftHand[XRHandJointID.Palm.ToIndex()] = new Pose(
            new Vector3(-0.05319f, 1.14112f, 0.08206f),
            new Quaternion(0.37018f, -0.42667f, -0.23629f, -0.79063f));
        leftHand[XRHandJointID.ThumbMetacarpal.ToIndex()] = new Pose(
            new Vector3(-0.03098f, 1.12033f, 0.05497f),
            new Quaternion(0.62813f, -0.40647f, 0.45152f, -0.48617f));
        leftHand[XRHandJointID.ThumbProximal.ToIndex()] = new Pose(
            new Vector3(0.00508f, 1.12946f, 0.05049f),
            new Quaternion(0.56658f, -0.37898f, 0.40879f, -0.60683f));
        leftHand[XRHandJointID.ThumbDistal.ToIndex()] = new Pose(
            new Vector3(0.04104f, 1.14418f, 0.05325f),
            new Quaternion(0.50136f, -0.31467f, 0.52384f, -0.61255f));
        leftHand[XRHandJointID.ThumbTip.ToIndex()] = new Pose(
            new Vector3(0.06704f, 1.15292f, 0.06050f),
            new Quaternion(0.50136f, -0.31467f, 0.52384f, -0.61255f));
        leftHand[XRHandJointID.IndexMetacarpal.ToIndex()] = new Pose(
            new Vector3(-0.04156f, 1.12615f, 0.06273f),
            new Quaternion(0.37018f, -0.42667f, -0.23629f, -0.79063f));
        leftHand[XRHandJointID.IndexProximal.ToIndex()] = new Pose(
            new Vector3(-0.00694f, 1.18204f, 0.08261f),
            new Quaternion(0.33862f, -0.46716f, -0.16301f, -0.80033f));
        leftHand[XRHandJointID.IndexIntermediate.ToIndex()] = new Pose(
            new Vector3(0.02092f, 1.21239f, 0.09721f),
            new Quaternion(0.20645f, -0.49184f, -0.11594f, -0.83787f));
        leftHand[XRHandJointID.IndexDistal.ToIndex()] = new Pose(
            new Vector3(0.04267f, 1.22527f, 0.10928f),
            new Quaternion(0.19916f, -0.47258f, -0.13734f, -0.84743f));
        leftHand[XRHandJointID.IndexTip.ToIndex()] = new Pose(
            new Vector3(0.06123f, 1.23835f, 0.12155f),
            new Quaternion(0.19916f, -0.47258f, -0.13734f, -0.84743f));
        leftHand[XRHandJointID.MiddleMetacarpal.ToIndex()] = new Pose(
            new Vector3(-0.05418f, 1.12452f, 0.07682f),
            new Quaternion(0.37018f, -0.42667f, -0.23629f, -0.79063f));
        leftHand[XRHandJointID.MiddleProximal.ToIndex()] = new Pose(
            new Vector3(-0.02412f, 1.18365f, 0.10172f),
            new Quaternion(0.29654f, -0.42389f, -0.22072f, -0.82684f));
        leftHand[XRHandJointID.MiddleIntermediate.ToIndex()] = new Pose(
            new Vector3(0.00409f, 1.21717f, 0.12471f),
            new Quaternion(0.07485f, -0.46811f, -0.11850f, -0.87249f));
        leftHand[XRHandJointID.MiddleDistal.ToIndex()] = new Pose(
            new Vector3(0.02946f, 1.22484f, 0.14219f),
            new Quaternion(0.01800f, -0.47650f, -0.14103f, -0.86761f));
        leftHand[XRHandJointID.MiddleTip.ToIndex()] = new Pose(
            new Vector3(0.05258f, 1.23078f, 0.15831f),
            new Quaternion(0.01800f, -0.47650f, -0.14103f, -0.86761f));
        leftHand[XRHandJointID.RingMetacarpal.ToIndex()] = new Pose(
            new Vector3(-0.06652f, 1.12487f, 0.09424f),
            new Quaternion(0.37018f, -0.42667f, -0.23629f, -0.79063f));
        leftHand[XRHandJointID.RingProximal.ToIndex()] = new Pose(
            new Vector3(-0.03655f, 1.17324f, 0.11937f),
            new Quaternion(0.28613f, -0.37813f, -0.29259f, -0.83039f));
        leftHand[XRHandJointID.RingIntermediate.ToIndex()] = new Pose(
            new Vector3(-0.01585f, 1.20454f, 0.14410f),
            new Quaternion(0.05979f, -0.45370f, -0.22094f, -0.86126f));
        leftHand[XRHandJointID.RingDistal.ToIndex()] = new Pose(
            new Vector3(0.00728f, 1.21384f, 0.16190f),
            new Quaternion(-0.02753f, -0.50001f, -0.17905f, -0.84686f));
        leftHand[XRHandJointID.RingTip.ToIndex()] = new Pose(
            new Vector3(0.03065f, 1.21918f, 0.17654f),
            new Quaternion(-0.02753f, -0.50001f, -0.17905f, -0.84686f));
        leftHand[XRHandJointID.LittleMetacarpal.ToIndex()] = new Pose(
            new Vector3(-0.06905f, 1.12129f, 0.10329f),
            new Quaternion(0.22237f, -0.38305f, -0.43656f, -0.78310f));
        leftHand[XRHandJointID.LittleProximal.ToIndex()] = new Pose(
            new Vector3(-0.04770f, 1.15721f, 0.13526f),
            new Quaternion(0.23079f, -0.30136f, -0.37872f, -0.84409f));
        leftHand[XRHandJointID.LittleIntermediate.ToIndex()] = new Pose(
            new Vector3(-0.03588f, 1.17908f, 0.16046f),
            new Quaternion(-0.02823f, -0.37711f, -0.34394f, -0.85947f));
        leftHand[XRHandJointID.LittleDistal.ToIndex()] = new Pose(
            new Vector3(-0.02025f, 1.18402f, 0.17718f),
            new Quaternion(-0.08543f, -0.44714f, -0.31003f, -0.83466f));
        leftHand[XRHandJointID.LittleTip.ToIndex()] = new Pose(
            new Vector3(-0.00056f, 1.18870f, 0.19236f),
            new Quaternion(-0.08543f, -0.44714f, -0.31003f, -0.83466f));

        rightRoot = new Pose(
            new Vector3(0.26061f, 1.04213f, -0.12217f),
            new Quaternion(-0.36011f, 0.06995f, -0.10860f, 0.92392f));

        rightHand = new Pose[XRHandJointID.EndMarker.ToIndex()];
        rightHand[XRHandJointID.Wrist.ToIndex()] = new Pose(
            new Vector3(0.25036f, 1.00710f, -0.16350f),
            new Quaternion(-0.36011f, 0.06995f, -0.10860f, 0.92392f));
        rightHand[XRHandJointID.Palm.ToIndex()] = new Pose(
            new Vector3(0.26061f, 1.04213f, -0.12217f),
            new Quaternion(-0.36011f, 0.06995f, -0.10860f, 0.92392f));
        rightHand[XRHandJointID.ThumbMetacarpal.ToIndex()] = new Pose(
            new Vector3(0.22277f, 1.02779f, -0.11895f),
            new Quaternion(-0.29443f, -0.09961f, 0.61688f, 0.72309f));
        rightHand[XRHandJointID.ThumbProximal.ToIndex()] = new Pose(
            new Vector3(0.20376f, 1.03914f, -0.08872f),
            new Quaternion(-0.17373f, 0.03486f, 0.54658f, 0.81844f));
        rightHand[XRHandJointID.ThumbDistal.ToIndex()] = new Pose(
            new Vector3(0.19858f, 1.05170f, -0.05222f),
            new Quaternion(-0.08241f, 0.04251f, 0.61551f, 0.78265f));
        rightHand[XRHandJointID.ThumbTip.ToIndex()] = new Pose(
            new Vector3(0.19663f, 1.05785f, -0.02459f),
            new Quaternion(-0.08241f, 0.04251f, 0.61551f, 0.78265f));
        rightHand[XRHandJointID.IndexMetacarpal.ToIndex()] = new Pose(
            new Vector3(0.23565f, 1.03198f, -0.12363f),
            new Quaternion(-0.36011f, 0.06995f, -0.10860f, 0.92392f));
        rightHand[XRHandJointID.IndexProximal.ToIndex()] = new Pose(
            new Vector3(0.24581f, 1.07980f, -0.07552f),
            new Quaternion(-0.26745f, -0.00230f, -0.05316f, 0.96210f));
        rightHand[XRHandJointID.IndexIntermediate.ToIndex()] = new Pose(
            new Vector3(0.24686f, 1.10231f, -0.03806f),
            new Quaternion(-0.08818f, -0.01665f, -0.07783f, 0.99292f));
        rightHand[XRHandJointID.IndexDistal.ToIndex()] = new Pose(
            new Vector3(0.24632f, 1.10729f, -0.01050f),
            new Quaternion(-0.08070f, 0.00726f, -0.09635f, 0.99204f));
        rightHand[XRHandJointID.IndexTip.ToIndex()] = new Pose(
            new Vector3(0.24765f, 1.11246f, 0.01474f),
            new Quaternion(-0.08070f, 0.00726f, -0.09635f, 0.99204f));
        rightHand[XRHandJointID.MiddleMetacarpal.ToIndex()] = new Pose(
            new Vector3(0.25356f, 1.02741f, -0.12805f),
            new Quaternion(-0.36011f, 0.06995f, -0.10860f, 0.92392f));
        rightHand[XRHandJointID.MiddleProximal.ToIndex()] = new Pose(
            new Vector3(0.27087f, 1.07717f, -0.08084f),
            new Quaternion(-0.25376f, 0.06876f, -0.13017f, 0.95600f));
        rightHand[XRHandJointID.MiddleIntermediate.ToIndex()] = new Pose(
            new Vector3(0.28064f, 1.10029f, -0.03821f),
            new Quaternion(0.00277f, 0.03060f, -0.15586f, 0.98730f));
        rightHand[XRHandJointID.MiddleDistal.ToIndex()] = new Pose(
            new Vector3(0.28253f, 1.09981f, -0.00652f),
            new Quaternion(0.03529f, 0.02435f, -0.20304f, 0.97823f));
        rightHand[XRHandJointID.MiddleTip.ToIndex()] = new Pose(
            new Vector3(0.28434f, 1.09860f, 0.02220f),
            new Quaternion(0.03529f, 0.02435f, -0.20304f, 0.97823f));
        rightHand[XRHandJointID.RingMetacarpal.ToIndex()] = new Pose(
            new Vector3(0.27434f, 1.02385f, -0.13037f),
            new Quaternion(-0.36011f, 0.06995f, -0.10860f, 0.92392f));
        rightHand[XRHandJointID.RingProximal.ToIndex()] = new Pose(
            new Vector3(0.28989f, 1.06311f, -0.08470f),
            new Quaternion(-0.30300f, 0.12805f, -0.19366f, 0.92428f));
        rightHand[XRHandJointID.RingIntermediate.ToIndex()] = new Pose(
            new Vector3(0.30581f, 1.08606f, -0.04948f),
            new Quaternion(-0.02105f, 0.04613f, -0.25712f, 0.96505f));
        rightHand[XRHandJointID.RingDistal.ToIndex()] = new Pose(
            new Vector3(0.30886f, 1.08658f, -0.01902f),
            new Quaternion(0.09422f, -0.01594f, -0.27039f, 0.95800f));
        rightHand[XRHandJointID.RingTip.ToIndex()] = new Pose(
            new Vector3(0.30779f, 1.08315f, 0.00885f),
            new Quaternion(0.09422f, -0.01594f, -0.27039f, 0.95800f));
        rightHand[XRHandJointID.LittleMetacarpal.ToIndex()] = new Pose(
            new Vector3(0.28250f, 1.01819f, -0.12876f),
            new Quaternion(-0.33093f, 0.12084f, -0.34823f, 0.86869f));
        rightHand[XRHandJointID.LittleProximal.ToIndex()] = new Pose(
            new Vector3(0.30567f, 1.04402f, -0.08921f),
            new Quaternion(-0.31247f, 0.21947f, -0.28321f, 0.87977f));
        rightHand[XRHandJointID.LittleIntermediate.ToIndex()] = new Pose(
            new Vector3(0.32560f, 1.05908f, -0.06413f),
            new Quaternion(-0.02639f, 0.12369f, -0.40234f, 0.90671f));
        rightHand[XRHandJointID.LittleDistal.ToIndex()] = new Pose(
            new Vector3(0.33135f, 1.05787f, -0.04147f),
            new Quaternion(0.06308f, 0.03026f, -0.41147f, 0.90874f));
        rightHand[XRHandJointID.LittleTip.ToIndex()] = new Pose(
            new Vector3(0.33230f, 1.05547f, -0.01630f),
            new Quaternion(0.06308f, 0.03026f, -0.41147f, 0.90874f));
    }
}
