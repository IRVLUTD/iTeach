# iTeachLabeller Application for HoloLens 2 🦾

This repository contains the code for the **iTeachLabeller** application, specifically designed for the **HoloLens 2**. 

## Setup Instructions ⚙️

To set up the required environment, please follow these steps:

1. **Unity Hub**: Download and install Unity Hub. 📥
2. **Unity Engine**: Obtain and install the Unity Engine. 🔧
3. **Mixed Reality Toolkit (MRTK)**: Integrate the MRTK into your Unity project. 🌐
4. **ROS Connector**: Install the [ROS TCP Connector](https://github.com/Unity-Technologies/ROS-TCP-Connector). Be sure to review this [issue](https://github.com/Unity-Technologies/ROS-TCP-Endpoint/issues/82). ⚠️
5. **Visual Studio**: Ensure Visual Studio is installed with the Universal Windows Platform feature enabled. 💻

For detailed setup instructions, refer to the [how_to_build.md](https://github.com/IRVLUTD/HoloLens2ResearchTools/blob/main/docs/how_to_build.md) file in the [IRVLUTD/HoloLens2ResearchTools](https://github.com/IRVLUTD/HoloLens2ResearchTools/tree/main) repository. 📚

## Building the Application 🏗️

Assuming the app's root directory is named `iTeachLabellingApp`, you can find guidance for building the app in the following video:

[![Build, Install, and Run the HoloLens Unity App](https://i9.ytimg.com/vi_webp/kvzMAMyluJU/mqdefault.webp?v=66fdaee4&sqp=CPTc9rcG&rs=AOn4CLDHb2Tr4BQtK3-Vvpk748-E2yBF2w)](https://www.youtube.com/watch?v=kvzMAMyluJU)

### Compilation Steps with Screenshots 📸
- Build the project in Unity. 🔨
- Open the .sln file in Visual Studio. 📂
- Create the package. 📦
- Use the Windows Device Portal to install the .msix file. 🚀
- Record stream or manage the app (Open/Close/Uninstall) using the HoloLens portal. 🎤📱

**NOTE**: Ensure to maintain a standalone system with a working Windows (Dev system + HoloLens), Unity, and Visual Studio to run simulations as well as for app building. We encountered difficulties where the same codebase successfully produced a build on one system but failed on another. To avoid issues, it is recommended to have a system where everything is version-maintained, and updates are done in a controlled manner. 🔒

## Download Prebuilt Application 📥

If you prefer to use the application without any modifications, you can download the prebuilt version from the following link:

- [Download iTeachLabeller Prebuilt Application](https://utdallas.box.com/v/iTeachLabellerApp) 📦
