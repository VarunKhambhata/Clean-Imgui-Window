#pragma once
#define GLEW_STATIC
#include <GL/glew.h>
#include<GLFW/glfw3.h>
#include<imgui.h>
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"



namespace ImGui
{		
	namespace private_vars
	{
		int WIDTH = 800, HEIGHT = 600;
		int glfwPosX = 0, glfwPosY = 0;
		ImVec2 delta;
		ImGuiIO io;
		const char* TitleText;
		int TitleTextLen = 0;
		bool titlebarClicked = false;
		ImGuiWindowFlags usrFlags;
		bool fullScreen = false;
		int revertSize[] = { 0,0 };
		int revertPos[] = { 0,0 };
	}

	GLFWwindow* initGLFW(int w = 800, int h = 600)
	{
		private_vars::WIDTH = w;
		private_vars::HEIGHT = h;
		glfwInit();
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		glfwWindowHint(GLFW_RESIZABLE, 1);
		glfwWindowHint(GLFW_DECORATED, GLFW_FALSE);
		GLFWwindow* window = glfwCreateWindow(private_vars::WIDTH, private_vars::HEIGHT, "ImGUI window", NULL, NULL);

		glfwMakeContextCurrent(window);
		glViewport(0, 0, private_vars::WIDTH, private_vars::HEIGHT);
		glewInit();

		return window;
	}

	void initImGui(GLFWwindow* window, const char* Title = { '\0' },bool resizable = true, bool MenuBar = false)
	{
		IMGUI_CHECKVERSION();
		ImGui::CreateContext();
		ImGui_ImplGlfw_InitForOpenGL(window, true);
		ImGui_ImplOpenGL3_Init("#version 130");
		private_vars::io = ImGui::GetIO();
		
		private_vars::TitleText = Title;
		while (private_vars::TitleText[private_vars::TitleTextLen] != '\0') private_vars::TitleTextLen++;
		if (MenuBar) private_vars::usrFlags |= ImGuiWindowFlags_MenuBar;
		if (!resizable) private_vars::usrFlags |= ImGuiWindowFlags_NoResize;
	}

	void StartCleanWindow(GLFWwindow* window)
	{
		glfwGetWindowPos(window, &private_vars::glfwPosX, &private_vars::glfwPosY);		
		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();
		private_vars::io = ImGui::GetIO();



		



		//TitleBar Buttons		
		ImGui::SetNextWindowPos({ 0,0 });
		ImGui::SetNextWindowSize({ 70,10 });
		ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, { 10,2 });		
		ImGui::Begin("X[]_", NULL, ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoCollapse  | ImGuiWindowFlags_NoTitleBar  | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoBackground );
		ImGui::PushStyleVar(ImGuiStyleVar_FrameRounding, 100);
		ImGui::PushStyleVar(ImGuiStyleVar_FramePadding, { 6.2,4 });
		ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, { 5,4 });
			/*close*/
			ImGui::PushStyleColor(ImGuiCol_Button, { 0.168f, 0.188f,0.188f,1.0f });
			ImGui::PushStyleColor(ImGuiCol_ButtonHovered, { 0.7,0,0,1 });
			ImGui::PushStyleColor(ImGuiCol_ButtonActive, { 1,0,0,1 });
			if (ImGui::Button("##1"))
				glfwSetWindowShouldClose(window, 1);
			ImGui::PopStyleColor(3);


			/*maximize*/
			ImGui::PushStyleColor(ImGuiCol_Button, { 0.168f, 0.188f,0.188f,1.0f });
			ImGui::PushStyleColor(ImGuiCol_ButtonHovered, { 0.17,0.61,0,1 });
			ImGui::PushStyleColor(ImGuiCol_ButtonActive, { 0.027,1,0,1 });
			ImGui::SameLine();
			if (ImGui::Button("##2"))
			{
				if (private_vars::fullScreen)
				{
					private_vars::WIDTH = private_vars::revertSize[0];
					private_vars::HEIGHT = private_vars::revertSize[1];
					private_vars::glfwPosX = private_vars::revertPos[0];
					private_vars::glfwPosY = private_vars::revertPos[1];
					glfwSetWindowSize(window, private_vars::WIDTH, private_vars::HEIGHT);
					glfwSetWindowPos(window, private_vars::glfwPosX, private_vars::glfwPosY);
					glViewport(0, 0, private_vars::WIDTH, private_vars::HEIGHT);
					private_vars::fullScreen = false;
					
				}
				else
				{
					private_vars::revertSize[0] = private_vars::WIDTH;
					private_vars::revertSize[1] = private_vars::HEIGHT;
					private_vars::revertPos[0] = private_vars::glfwPosX;
					private_vars::revertPos[1] = private_vars::glfwPosY;
					glfwMaximizeWindow(window);					
					glfwGetWindowSize(window, &private_vars::WIDTH, &private_vars::HEIGHT);
					private_vars::glfwPosX = private_vars::glfwPosY = 0;
					ImGui::SetWindowSize({ (float)private_vars::WIDTH,(float)private_vars::HEIGHT });
					private_vars::fullScreen = true;
				}
				
			}			
			ImGui::PopStyleColor(3);


			/*minimize*/
			ImGui::PushStyleColor(ImGuiCol_Button, { 0.168f, 0.188f,0.188f,1.0f });
			ImGui::PushStyleColor(ImGuiCol_ButtonHovered, { 0.68,0.623,0,1 });
			ImGui::PushStyleColor(ImGuiCol_ButtonActive, { 0.9,0.85,0,1 });
			ImGui::SameLine();
			if (ImGui::Button("##3"))
				glfwIconifyWindow(window);
			ImGui::PopStyleColor(3);
			ImGui::PopStyleVar(4);			
			ImGui::End();
			
			


		
		
			//MainSpace
			ImGui::SetNextWindowPos({ 0,0 });
			ImGui::SetNextWindowSizeConstraints(ImVec2(private_vars::TitleTextLen * 10 + 142, 50), ImVec2(FLT_MAX, FLT_MAX));
			ImGui::PushStyleVar(ImGuiStyleVar_FramePadding, { 4,6 });
			ImGui::PushStyleVar(ImGuiStyleVar_WindowTitleAlign, { 0.5f,0.5f });
			ImGui::PushStyleColor(ImGuiCol_TitleBg, { 0.14,0.14,0.14,1 });
			ImGui::PushStyleColor(ImGuiCol_TitleBgActive, { 0.14,0.14,0.14,1 });
			ImGui::PushStyleColor(ImGuiCol_Text, { 1,1,1,1 });
			ImGui::Begin(private_vars::TitleText, NULL, ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoBringToFrontOnFocus | private_vars::usrFlags);
			ImGui::PopStyleVar(2);
			ImGui::PopStyleColor(3);
			ImGui::SetWindowSize(ImVec2(private_vars::WIDTH, private_vars::HEIGHT));


		//** MouseEvent on window **
		//move window
		if (private_vars::io.MouseClicked[0] && private_vars::io.MousePos.y < 25 && private_vars::io.MousePos.y >= ImGui::GetWindowPos().y + 4)
			private_vars::titlebarClicked = true;
		if (private_vars::io.MouseReleased[0])
			private_vars::titlebarClicked = false;
		if (private_vars::titlebarClicked)
		{
			private_vars::delta = ImGui::GetMouseDragDelta(0);
			if (private_vars::fullScreen && (private_vars::delta.x > 0 || private_vars::delta.y > 0))
			{
				private_vars::WIDTH = private_vars::revertSize[0]; 
				private_vars::HEIGHT = private_vars::revertSize[1];
				glfwSetWindowSize(window, private_vars::WIDTH, private_vars::HEIGHT);
				glViewport(0, 0, private_vars::WIDTH, private_vars::HEIGHT);
				private_vars::fullScreen = false;
			}

			private_vars::glfwPosX += private_vars::delta.x;
			private_vars::glfwPosY += private_vars::delta.y;
			glfwSetWindowPos(window, private_vars::glfwPosX, private_vars::glfwPosY);
		}

		//resize
		if (private_vars::io.MouseDown[0] &&
			(
				(ImGui::GetIO().MousePos.x <= ImGui::GetWindowPos().x + 6
					|| ImGui::GetIO().MousePos.x >= ImGui::GetWindowSize().x - 6
					|| ImGui::GetIO().MousePos.y <= ImGui::GetWindowPos().y + 6
					|| ImGui::GetIO().MousePos.y >= private_vars::HEIGHT - 6)
				)
			)
		{
			ImVec2 sz = ImGui::GetWindowSize();
			ImVec2 ps = ImGui::GetWindowPos();
			private_vars::WIDTH = sz.x - ps.x; private_vars::HEIGHT = sz.y - ps.y;
			glfwSetWindowSize(window, private_vars::WIDTH, private_vars::HEIGHT);
			glViewport(0, 0, private_vars::WIDTH, private_vars::HEIGHT);
			private_vars::glfwPosX += ps.x;
			private_vars::glfwPosY += ps.y;
			glfwSetWindowPos(window, private_vars::glfwPosX, private_vars::glfwPosY);

		}
	}

	void EndCleanWindow(GLFWwindow* window)
	{
		ImGui::End();
		
		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

		glfwSwapBuffers(window);
		glfwPollEvents();
		glClearColor(0.2f, 0.2f, 0.2f, 0.0f);
		glClear(GL_COLOR_BUFFER_BIT);
	}

	void terminateImGui()
	{		
		ImGui_ImplOpenGL3_Shutdown();
		ImGui_ImplGlfw_Shutdown();
		ImGui::DestroyContext();
	}

	void terminateGLFW(GLFWwindow* window)
	{
		glfwDestroyWindow(window);
		glfwTerminate();
	}
}