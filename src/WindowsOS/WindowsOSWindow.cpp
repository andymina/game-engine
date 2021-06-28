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
}
