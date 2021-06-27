//
//  HunterApp.cpp
//  game-engine
//
//  Created by Andy Mina on 6/23/21.
//

#include <pch.h>
#include "HunterApp.h"

namespace Hunter {
	void HunterApp::RunGame() {
		HLOG("Starting the game");
		// Event loop
		while (true) {
			this->appWindow->SwapBuffers();
			this->appWindow->PollForEvent();
		}
	}
	
	HunterApp* HunterApp::GetApplication() {
		return instance;
	}
	
	void HunterApp::Init() {
		// Make sure this class is a singleton
		if (instance)
			instance = new HunterApp;
	}
	
	HunterApp::HunterApp() {
		// Assert this class is a singleton
		assert(!instance);
		
		this->appWindow = new WindowsOSWindow;
		this->appWindow->CreateWindow(800, 600);
	}
	
	HunterApp::~HunterApp() {
		this->appWindow->DeleteWindow();
	}
}
