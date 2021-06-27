//
//  WindowsOSWindow.h
//  game-engine
//
//  Created by Andy Mina on 6/27/21.
//

#ifndef WindowsOSWindow_h
#define WindowsOSWindow_h
#define GLFW_INCLUDE_NONE

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "Window.h"

namespace Hunter {
	class WindowsOSWindow final: public Hunter::Window {
	public:
		virtual bool CreateWindow(unsigned int width, unsigned int height) override;
		virtual void DeleteWindow() override;
		virtual void SwapBuffers() override;
		virtual void PollForEvent() override;
	private:
		GLFWwindow* window;
	};
}

#endif /* WindowsOSWindow_h */
