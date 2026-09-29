# iTeachLabeller Application for HoloLens 2 🦾

> [!WARNING]
> **Archived (legacy):** this is part of **iTeach v1** (door and handle detection with DH-YOLO) and is no longer maintained. It is kept for reference and reproducibility. For the current iTeach system, see [iTeach](https://github.com/IRVLUTD/iTeach), [iTeachSkillsApp](https://github.com/IRVLUTD/iTeachSkillsApp) and [iTeach-UOIS](https://github.com/IRVLUTD/iTeach-UOIS).

This repository contains the code for the **iTeachLabeller** application, developed specifically for **HoloLens 2**.

<img src="https://irvlutd.github.io/iTeach/assets/images/iteach/iteach-app-select-to-main-menu-2x2.webp" alt="iTeachLabeller UI Flow" width="600"/>  <br>
*(i) The user interface flow of the iTeachLabeller app, from startup to the main menu.*

<img src="https://irvlutd.github.io/iTeach/assets/images/iteach/iTeach-main.menu.jpg" alt="iTeachLabeller Main Menu" width="600"/>  <br>
*(ii) Description of the main menu options in the iTeachLabeller app.*


## Setup Instructions ⚙️

To set up the required environment, please follow these steps:

1. **Unity Hub**: Download and install Unity Hub. 📥
2. **Unity Engine**: Obtain and install the Unity Engine. 🔧
3. **Mixed Reality Toolkit (MRTK)**: Integrate the MRTK into your Unity project. 🌐
4. **ROS Connector**: Install the [ROS TCP Connector](https://github.com/Unity-Technologies/ROS-TCP-Connector). Be sure to review this [issue](https://github.com/Unity-Technologies/ROS-TCP-Endpoint/issues/82). ⚠️
5. **Visual Studio**: Ensure Visual Studio is installed with the Universal Windows Platform feature enabled. 💻

For detailed setup instructions, refer to the [how_to_build.md](https://github.com/IRVLUTD/HoloLens2ResearchTools/blob/main/docs/how_to_build.md) file in the [IRVLUTD/HoloLens2ResearchTools](https://github.com/IRVLUTD/HoloLens2ResearchTools/tree/main) repository. 📚

## Building the Application 🏗️

> [!NOTE]
> Unity's `Library/` cache and `UserSettings/` are not tracked in git. Unity rebuilds them the first time you open the project, which can take several minutes.

Assuming the app's root directory is named `iTeachLabellingApp`, you can find guidance for building the app in the following video:

[![Build, Install, and Run the HoloLens Unity App](https://img.youtube.com/vi/kvzMAMyluJU/0.jpg)](https://www.youtube.com/watch?v=kvzMAMyluJU)


### Compilation Steps with Screenshots 📸
- Build the project in Unity. 🔨
- Open the .sln file in Visual Studio. 📂
- Create the package. 📦
- Use the Windows Device Portal to install the .msix file. 🚀
- Record stream or manage the app (Open/Close/Uninstall) using the HoloLens portal. 📱

**NOTE**: Ensure to maintain a standalone system with a working Windows (Dev system + HoloLens), Unity, and Visual Studio to run simulations as well as for app building. We encountered difficulties where the same codebase successfully produced a build on one system but failed on another. To avoid issues, it is recommended to have a system where everything is version-maintained, and updates are done in a controlled manner. 🔒

## Prebuilt Application 📥

The prebuilt `iTeachLabeller.msix` is currently not available for download, so build the app from this folder as described above. The [App Install Video](https://www.youtube.com/watch?v=7xFtCPSMTEk) 🎥 shows how to install the package on the HoloLens.

## ⚠️ Note

- 🚨 It is **recommended** that a **Windows** device is used to compile this part of the project, and it has not been tested on other platforms.
- 💻 A **Unity** version newer or equivalent to a **2022 release** and at least **Microsoft Visual Studio 2022** are required. 
- ⚙️ Due to technical constraints, this project can only run on a **Hololens 2**.
