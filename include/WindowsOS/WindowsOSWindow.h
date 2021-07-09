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
		virtual void ClearFrame() override;
		
		// key callbacks
		virtual void SetKeyPressedCallback(std::function<void(KeyPressedEvent&)> newCallback) override;
		virtual void SetKeyHeldCallback(std::function<void(KeyHeldEvent&)> newCallback) override;
		virtual void SetKeyReleasedCallback(std::function<void(KeyReleasedEvent&)> newCallback) override;
		
		virtual int GetWidth() const override;
		virtual int GetHeight() const override;
		virtual bool ShouldClose() const override;
		
	private:
		struct Callbacks {
			std::function<void(KeyPressedEvent &event)> keyPressedCallback;
			std::function<void(KeyHeldEvent &event)> keyHeldCallback;
			std::function<void(KeyReleasedEvent &event)> keyReleasedCallback;
		} callbacks;
		GLFWwindow* window;
	};
}

#endif /* WindowsOSWindow_h */
