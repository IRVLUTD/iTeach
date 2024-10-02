using UnityEngine;



public class SampleTracker : MonoBehaviour
{
    private int currentSessionSamples = 0;
    private int overallSamples = 0;

    private int currentSessionDoors = 0;
    private int overallDoors = 0;
    private int currentSessionHandles = 0;
    private int overallHandles = 0;

    public void AddSample()
    {
        currentSessionSamples++;
        overallSamples++;
    }

    public void AddDoor(int count)
    {
        currentSessionDoors += count;
        overallDoors += count;
    }

    public void AddHandle(int count)
    {
        currentSessionHandles += count;
        overallHandles += count;
    }

    public void ResetSessionSamples()
    {
        currentSessionSamples = 0;
        currentSessionDoors = 0;
        currentSessionHandles = 0;
    }

    public int GetCurrentSessionSamples()
    {
        return currentSessionSamples;
    }

    public int GetOverallSamples()
    {
        return overallSamples;
    }

    public int GetCurrentSessionDoors()
    {
        return currentSessionDoors;
    }

    public int GetOverallDoors()
    {
        return overallDoors;
    }

    public int GetCurrentSessionHandles()
    {
        return currentSessionHandles;
    }

    public int GetOverallHandles()
    {
        return overallHandles;
    }

    // Get formatted sample information as a string
    public string GetSampleInfo()
    {
        return $"Samples Collected in Current Session: {currentSessionSamples}\n" +
               $"Overall Samples Collected: {overallSamples}\n" +
               $"Doors Collected in Current Session: {currentSessionDoors}\n" +
               $"Overall Doors Collected: {overallDoors}\n" +
               $"Handles Collected in Current Session: {currentSessionHandles}\n" +
               $"Overall Handles Collected: {overallHandles}";
    }

    // Get formatted sample information as a table
    public string GetSampleInfoInTableView()
    {
        // Fetch the data
        int currentSamples = GetCurrentSessionSamples();
        int overallSamples = GetOverallSamples();
        int currentDoors = GetCurrentSessionDoors();
        int overallDoors = GetOverallDoors();
        int currentHandles = GetCurrentSessionHandles();
        int overallHandles = GetOverallHandles();

        // Create the output string
        string result = "Sample Information:\n";
        result += $"Samples Collected: Current Session = {currentSamples}, Overall = {overallSamples}\n";
        result += $"Doors Collected: Current Session = {currentDoors}, Overall = {overallDoors}\n";
        result += $"Handles Collected: Current Session = {currentHandles}, Overall = {overallHandles}\n";

        return result;
    }

}
