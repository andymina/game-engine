//
//  HunterApp.h
//  game-engine
//
//  Created by Andy Mina on 6/23/21.
//

#ifndef HunterApp_h
#define HunterApp_h

#include "HunterCentral.h"
#include "Window.h"
#include "KeyboardEvents.h"

namespace Hunter {
	class HUNTER_API HunterApp {
	public: // open to everyone
		// Starts the game
		virtual void RunGame();
		// Gets the instance of the singleton
		static HunterApp* GetApplication();
		virtual void OnUpdate();
		virtual ~HunterApp();
		
		static int GetWindowWidth();
		static int GetWindowHeight();
		
		void OnKeyPressed(KeyPressedEvent &event);
		
	protected: // open to children classes only
		HunterApp();

	private: // open to noone
		// Make this class a singleton
		inline static HunterApp* instance{ nullptr };
		Hunter::Window* appWindow{ nullptr };
	};
}

#endif /* HunterApp_h */
