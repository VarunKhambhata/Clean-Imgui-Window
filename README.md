# Clean-Imgui-Window
This header file works as an extension of ImGui namespace.
It provides integration of GLFW, GLEW, ImGui and custom procedures to create a clean independent GUI window quickly.



To use this wrapper, GLFW, GLEW and ImGui must be setup first.
After ImGui is functionally working with GLFW and GLEW, add CleanImGuiWin.h to the project files

Below is the sample code to create a clean window using this header file
```c++
#include<CleanImGuiWin.h>
int main()
{	
	GLFWwindow* window = ImGui::initGLFW();
	ImGui::initImGui(window, "Title");

        //Edit ImGui Theme
	ImGui::GetStyle().Colors[ImGuiCol_WindowBg].w = 1.0f;
	ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 15);

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
![image](https://user-images.githubusercontent.com/52032582/146166145-a9b84b23-d58e-4a3b-a4f3-3cd955c347ff.png)


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
