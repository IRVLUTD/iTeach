using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class BoxIdentifier : MonoBehaviour
{
    
    public Color colorHandle;
    public Color colorCabinet;
    public enum RectType
    {
        none,
        handle,
        cabinet
    }

    private RectType type;

    public void SetBoxType(RectType intype){
        type = intype;
        switch(type){
            case RectType.none:
                break;
            case RectType.handle:
                gameObject.GetComponent<Renderer>().material.color = colorHandle;
                break;
            case RectType.cabinet:
                gameObject.GetComponent<Renderer>().material.color = colorCabinet;
                break;
        }
        
    }

    public RectType GetBoxType(){
        return type;
    }
}
