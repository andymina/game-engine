//
//  HunterApp.h
//  game-engine
//
//  Created by Andy Mina on 6/23/21.
//

#ifndef HunterApp_h
#define HunterApp_h

#include <HunterCentral.h>

namespace Hunter {
	class DYNAMIC_LIB HunterApp {
	public:
		// Starts the game
		void RunGame();
		// Gets the instance of the singleton
		static HunterApp* GetApplication();
		// Creates the first instance of singleton
		static void Init();
		
	private:
		HunterApp();
		inline static HunterApp* instance{ nullptr };
	};
}

#endif /* HunterApp_h */
