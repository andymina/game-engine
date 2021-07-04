//
//  macOSWindow.cpp
//  game-engine
//
//  Created by Andy Mina on 6/27/21.
//

#include <pch.h>
#include "macOS/macOSWindow.h"

namespace Hunter {
	bool macOSWindow::CreateWindow(unsigned int width, unsigned int height) {
		glfwInit();
		// Tell GLFW what version we're using
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		// Tell GLFW we're using core profile
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		// macOS specific
		glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
		
		window = glfwCreateWindow(800, 600, "Test Window", nullptr, nullptr);
		
		// Check if window failed to create
		if (!window) return false;
		
		glfwMakeContextCurrent(window);
		gladLoadGL();
		glfwSwapInterval(1);
		return true;
	}
	
	void macOSWindow::DeleteWindow() {
		glfwDestroyWindow(window);
		glfwTerminate();
	}
	
	void macOSWindow::SwapBuffers() {
		glfwSwapBuffers(window);
	}
	
	void macOSWindow::PollForEvent() {
		glfwPollEvents();
	}
	
	void macOSWindow::ClearScreen() {
		glClear(GL_COLOR_BUFFER_BIT);
	}
	
	int macOSWindow::GetWidth() const {
		int width{ 0 }, height{ 0 };
		glfwGetWindowSize(window, &width, &height);
		return width;
	}
	
	int macOSWindow::GetHeight() const {
		int width{ 0 }, height{ 0 };
		glfwGetWindowSize(window, &width, &height);
		return height;
	}
	
	bool macOSWindow::ShouldClose() const {
		return glfwWindowShouldClose(window);
	}
}
