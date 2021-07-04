//
//  WindowsOSWindow.cpp
//  game-engine
//
//  Created by Andy Mina on 6/27/21.
//

#include <pch.h>
#include "WindowsOS/WindowsOSWindow.h"

namespace Hunter {
	bool WindowsOSWindow::CreateWindow(unsigned int width, unsigned int height) {
		glfwInit();
		// Tell GLFW what version we're using
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		// Tell GLFW we're using core profile
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		
		window = glfwCreateWindow(800, 600, "Test Window", nullptr, nullptr);
		
		// Check if window failed to create
		if (!window) return false;
		
		glfwMakeContextCurrent(window);
		gladLoadGL();
		glfwSwapInterval(1);
		return true;
	}
	
	void WindowsOSWindow::DeleteWindow() {
		glfwDestroyWindow(window);
		glfwTerminate();
	}
	
	void WindowsOSWindow::SwapBuffers() {
		glfwSwapBuffers(window);
	}
	
	void WindowsOSWindow::PollForEvent() {
		glfwPollEvents();
	}
	
	int WindowsOSWindow::GetWidth() const {
		int width{ 0 }, height{ 0 };
		glfwGetWindowSize(window, &width, &height);
		return width;
	}
	
	int WindowsOSWindow::GetHeight() const {
		int width{ 0 }, height{ 0 };
		glfwGetWindowSize(window, &width, &height);
		return height;
	}
	
	bool WindowsOSWindow::ShouldClose() const {
		return glfwWindowShouldClose(window);
	}
	
	void WindowsOSWindow::ClearScreen() {
		glClear(GL_COLOR_BUFFER_BIT);
	}
}