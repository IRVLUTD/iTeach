using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class BoxIdentifier : MonoBehaviour
{

    public Color colorHandle;
    public Color colorDoor;
    public enum RectType
    {
        none,
        handle,
        door
    }

    private RectType type;

    public void SetBoxType(RectType intype)
    {
        type = intype;
        switch (type)
        {
            case RectType.none:
                break;
            case RectType.handle:
                gameObject.GetComponent<Renderer>().material.color = colorHandle;
                break;
            case RectType.door:
                gameObject.GetComponent<Renderer>().material.color = colorDoor;
                break;
        }

    }

    public RectType GetBoxType()
    {
        return type;
    }
}
