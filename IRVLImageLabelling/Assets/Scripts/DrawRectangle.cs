using Microsoft.MixedReality.Toolkit.Input;
using Microsoft.MixedReality.Toolkit.UI;
using System.Collections;
using UnityEngine;

public class DrawRectangle : MonoBehaviour, IMixedRealityPointerHandler
{

    public GameObject DrawPlane; // the plane to be drawn on
    public GameObject rectanglePrefab; // the rectangle prefab to be instantiated



    //Handler for drawing either a cabinet or a handle
    enum Drawmode
    {
        none,
        handle,
        cabinet
    }
    private Drawmode mode = Drawmode.none;
    public void ToggleHandleMode(){ 
        if(mode != Drawmode.handle){
            mode = Drawmode.handle;
            Debug.Log("Handle Mode");
        } else {    // If the program is already in the mode, leave all modes
            mode = Drawmode.none;
            Debug.Log("None Mode");
        }
    }
    public void ToggleCabinetMode(){
        if(mode != Drawmode.cabinet){
            mode = Drawmode.cabinet;
            Debug.Log("Cabinet Mode");
        } else {
            mode = Drawmode.none;
            Debug.Log("None Mode");
        }
    }




    private ArrayList rects = new ArrayList(); // stores all currently active rectangles
    private GameObject currentRectangle; // the current rectangle being drawn
    private Vector3 startCorner; // the starting corner of the rectangle
    private Vector3 endCorner; // the ending corner of the rectangle

    private Vector3 rectCorner; //the world space corner of the rectangle
    private bool isDrawing; // whether or not the user is currently drawing a rectangle

    private float drawMultiplier = 5f;

    private void Start()
    {
        isDrawing = false;
    }

    public void OnPointerDown(MixedRealityPointerEventData eventData)
    {
        if (!isDrawing)
        {
            isDrawing = true;
            rectCorner = eventData.Pointer.Result.Details.Point + (DrawPlane.transform.up*0.001f); // get the starting corner of the rectangle
            startCorner = DrawPlane.transform.InverseTransformPoint(eventData.Pointer.Position);
            currentRectangle = Instantiate(rectanglePrefab); // instantiate a new rectangle
            currentRectangle.transform.position = rectCorner; // set the position of the rectangle to the starting corner
            currentRectangle.transform.parent = DrawPlane.transform;
            rectCorner = currentRectangle.transform.localPosition;
            currentRectangle.transform.rotation = DrawPlane.transform.rotation; // set the rotation of the rectangle to match the plane

        }
    }

    public void OnPointerDragged(MixedRealityPointerEventData eventData)
    {
        if (isDrawing)
        {
            endCorner = DrawPlane.transform.InverseTransformPoint(eventData.Pointer.Position); // get the ending corner of the rectangle
            float width = (endCorner.x - startCorner.x)*DrawPlane.transform.localScale.x * drawMultiplier; // calculate the width of the rectangle
            float height = (endCorner.z - startCorner.z)*DrawPlane.transform.localScale.z * drawMultiplier; // calculate the height of the rectangle
            // * extra is so the drag scaling is at a reasonable speed
            currentRectangle.transform.localScale = new Vector3(Mathf.Abs(width), 1f, Mathf.Abs(height)); // set the scale of the rectangle
            currentRectangle.transform.localPosition = rectCorner+(new Vector3(width, 0f, height)*5f); //set the initial point to the corner of the rectangle
        }
    }

    public void OnPointerUp(MixedRealityPointerEventData eventData)
    {
        if (isDrawing)
        {
            isDrawing = false;
            // calculate the relative position of the rectangle with respect to the plane's position and size
            //Vector3 relativePosition = currentRectangle.transform.position - transform.position;
            Vector3 relativePosition = (currentRectangle.transform.localPosition/10f)+new Vector3(0.5f,0,0.5f);
            float relativeWidth = currentRectangle.transform.localScale.x;// / transform.localScale.x;
            float relativeHeight = currentRectangle.transform.localScale.z;// / transform.localScale.z;
            Debug.Log("Relative Position: " + relativePosition);
            Debug.Log("Relative Width: " + relativeWidth);
            Debug.Log("Relative Height: " + relativeHeight);


            switch(mode){
                case Drawmode.cabinet:
                    currentRectangle.GetComponent<BoxIdentifier>().SetBoxType(BoxIdentifier.RectType.cabinet);
                    rects.Add(currentRectangle);
                    break;
                case Drawmode.handle:
                    currentRectangle.GetComponent<BoxIdentifier>().SetBoxType(BoxIdentifier.RectType.handle);
                    rects.Add(currentRectangle);
                    break;
                case Drawmode.none:
                    Destroy(currentRectangle);
                    break;
            }
            
        }
    }

    public void ClearRectangles(){
        while(rects.Count>0){
            Destroy((GameObject)rects[rects.Count-1]);
            rects.RemoveAt(rects.Count-1);
        }
    }
    
    public void UndoRectangle(){
        Destroy((GameObject)rects[rects.Count-1]);
        rects.RemoveAt(rects.Count-1);
    }

    public string getLabels(){
        string output = "";
        for(int i=0; i<rects.Count; i++){
            // TODO: confirm that these are the correct labels
            string type = (((GameObject)rects[i]).GetComponent<BoxIdentifier>().GetBoxType() == BoxIdentifier.RectType.cabinet ? "0" : "1");
            Vector3 relativePosition = (((GameObject)rects[i]).transform.localPosition/10f)+new Vector3(0.5f,0,0.5f);
            float relativeWidth = ((GameObject)rects[i]).transform.localScale.x;// / transform.localScale.x;
            float relativeHeight = ((GameObject)rects[i]).transform.localScale.z;// / transform.localScale.z;
            output = output+type+" "+relativePosition.x+" "+relativePosition.z+" "+relativeWidth+" "+relativeHeight+"\n";

        }
        if(output.Length>0){
            output.Substring(0,output.Length-1);
        }
        return output;
    }

    // Implement the remaining methods of the IMixedRealityPointerHandler interface
    //required to have a functioning program

    public void OnPointerClicked(MixedRealityPointerEventData eventData) { }

    public void OnPointerUpAsButton(MixedRealityPointerEventData eventData) { }

    public void OnPointerEnter(GameObject obj) { }

    public void OnPointerExit(GameObject obj) { }
}
