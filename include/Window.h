//
//  Window.h
//  game-engine
//
//  Created by Andy Mina on 6/27/21.
//

#ifndef Window_h
#define Window_h

#include "HunterCentral.h"

namespace Hunter {
	class Window {
	public:
		/*
		 The following functions have been labeled as pure virtual functions so we can use OS specific code.
		 */
		virtual bool CreateWindow(unsigned int width, unsigned int height) = 0;
		virtual void DeleteWindow() = 0;
		virtual void SwapBuffers() = 0;
		virtual void PollForEvent() = 0;
	};
}


#endif /* Window_h */
