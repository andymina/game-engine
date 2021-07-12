//
//  Window.h
//  game-engine
//
//  Created by Andy Mina on 6/27/21.
//

#ifndef Window_h
#define Window_h

#include "pch.h"
#include "HunterCentral.h"
#include "KeyboardEvents.h"

namespace Hunter {
	class Window {
	public:
		/*
		 The following functions have been labeled as pure virtual functions so we can use OS specific code.
		 */
		virtual bool CreateWindow(unsigned int width, unsigned int height, const std::string &title) = 0;
		virtual void DeleteWindow() = 0;
		virtual void SwapBuffers() = 0;
		virtual void PollForEvent() = 0;
		virtual void ClearFrame() = 0;
		
		virtual void SetKeyPressedCallback(std::function<void(KeyPressedEvent&)> newCallback) = 0;
		virtual void SetKeyHeldCallback(std::function<void(KeyHeldEvent&)> newCallback) = 0;
		virtual void SetKeyReleasedCallback(std::function<void(KeyReleasedEvent&)> newCallback) = 0;
		
		virtual int GetWidth() const = 0;
		virtual int GetHeight() const = 0;
		virtual bool ShouldClose() const = 0;
	};
}


#endif /* Window_h */
