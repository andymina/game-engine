//
//  HunterApp.h
//  game-engine
//
//  Created by Andy Mina on 6/23/21.
//

#ifndef HunterApp_h
#define HunterApp_h

#include "HunterCentral.h"
#include "WindowsOS/WindowsOSWindow.h"

namespace Hunter {
	class HUNTER_API HunterApp {
	public:
		// Starts the game
		void RunGame();
		// Gets the instance of the singleton
		static HunterApp* GetApplication();
		// Creates the first instance of singleton
		static void Init();
		
	private:
		HunterApp();
		virtual ~HunterApp();
		// Make this class a singleton
		inline static HunterApp* instance{ nullptr };
		Hunter::Window* appWindow{ nullptr };
	};
}

#endif /* HunterApp_h */
