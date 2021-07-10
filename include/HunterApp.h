//
//  HunterApp.h
//  game-engine
//
//  Created by Andy Mina on 6/23/21.
//

#ifndef HunterApp_h
#define HunterApp_h

#include "pch.h"
#include "HunterCentral.h"
#include "Window.h"
#include "KeyboardEvents.h"

namespace Hunter {
	class HUNTER_API HunterApp {
	typedef std::chrono::steady_clock clock;
		
	public: // open to everyone
		// Starts the game
		virtual void RunGame();
		// Gets the instance of the singleton
		static HunterApp* GetApplication();
		virtual void OnUpdate();
		virtual ~HunterApp();
		
		static int GetWindowWidth();
		static int GetWindowHeight();
		
		// Key events
		virtual void OnKeyPressed(KeyPressedEvent &event);
		virtual void OnKeyHeld(KeyHeldEvent &event);
		virtual void OnKeyReleased(KeyReleasedEvent &event);
		
	protected: // open to children classes only
		HunterApp();

	private: // open to noone
		// Make this class a singleton
		inline static HunterApp* instance{ nullptr };
		Hunter::Window* appWindow{ nullptr };
		clock::time_point nextFrameTime;
		std::chrono::milliseconds frameDuration{ 32 }; // default to 60 FPS
	};
}

#endif /* HunterApp_h */
