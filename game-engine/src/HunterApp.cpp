//
//  HunterApp.cpp
//  game-engine
//
//  Created by Andy Mina on 6/23/21.
//

#include <cassert>
#include <iostream>
#include "HunterApp.h"

namespace Hunter {
	void HunterApp::RunGame() {
		HLOG("Starting the game");
		// Event loop
		while (true) {
			
		}
	}
	
	HunterApp* HunterApp::GetApplication() {
		return instance;
	}
	
	void HunterApp::Init() {
		if (instance)
			instance = new HunterApp;
	}
	
	HunterApp::HunterApp() {
		assert(!instance);
	}
}
