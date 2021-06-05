# Clean-Imgui-Window
This header file works as an extension of ImGui namespace.
It provides integration of GLFW, GLEW, ImGui and custom procedures to create a clean independent GUI window quickly.


> ### *It began with the forging of the Great GUIs library. ImGui were given to the Open Source-Developers, immortal, wisest and fairest of all beings. Qt to the Industry-Developers, great miners and craftsmen of the user softwares. And .Net, .Net Framework were gifted to the race of Men, who above all else desire Window's power. For within these library was bound the strength and the will to govern each application UI. But they were all of them deceived, for another header file was made. Deep in the land of CyberSpace, in the Fires of Visual Studio, the Dark Lord forged a master header file, and into this header he poured his openGL, his GLFW, GLEW and his will to extend ImGui.*
> 
> 
> ## *One Header to rule them all, One Header to find them, One Header to bring them all and in the GUI bind them.*



To use this wrapper, GLFW, GLEW and ImGui must be setup first.
After ImGui is functionally working with GLFW and GLEW, add CleanImGuiWin.h to the project files

Below is the sample code to create a clean window using this header file
```c++
#include<CleanImGuiWin.h>
int main()
{	
	GLFWwindow* window = ImGui::initGLFW();
	ImGui::initImGui(window, "Title");
  
	while(!glfwWindowShouldClose(window))
	{
	   ImGui::StartCleanWindow(window);
	   // Add ImGui UI elemnts here--------------------
	   	ImGui::Text("Add ImGui UI elements here");
		ImGui::Button("Like This");
	   // ---------------------------------------------
	   ImGui::EndCleanWindow(window);
	}
  
	ImGui::terminateImGui();
	ImGui::terminateGLFW(window);
	return 0;
}
```
Result:
![image](https://user-images.githubusercontent.com/52032582/120906921-027dad80-c67b-11eb-9fc0-27bc067352c1.png)


This header file will add following functions to ImGui namespace:
```c++ 
GLFWwindow* initGLFW(int width, int height)
```
```c++ 
void initImGui(GLFWwindow* window, const char* Title)
```
```c++ 
void StartCleanWindow(GLFWwindow* window)
```
```c++ 
void EndCleanWindow(GLFWwindow* window)
```
```c++ 
void terminateImGui()
```
```c++ 
void terminateGLFW(GLFWwindow* window)
```




<br><br><br>
---
**ImGui:** https://github.com/ocornut/imgui

**GLFW:**  https://www.glfw.org/

**GLEW:**  http://glew.sourceforge.net/
