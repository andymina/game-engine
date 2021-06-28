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
}
