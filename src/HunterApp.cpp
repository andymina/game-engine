//
//  HunterApp.cpp
//  game-engine
//
//  Created by Andy Mina on 6/23/21.
//

#include "pch.h"
#include "HunterApp.h"
#include PLATFORM_WINDOW_FILE
#include "Renderer.h"
#include "Sprite.h"

namespace Hunter {
	void HunterApp::RunGame() {
		HLOG("Starting the game");
		
		Renderer::Init();
		Sprite test1{ "assets/sprites/mario.png" };
		
		// Event loop
		while (!appWindow->ShouldClose()) {
			this->appWindow->ClearScreen();
			
			Renderer::Draw(test1, 100, 100, test1.GetWidth(), test1.GetHeight());
			
			this->appWindow->SwapBuffers();
			this->appWindow->PollForEvent();
		}
	}
	
	HunterApp* HunterApp::GetApplication() {
		return instance;
	}
	
	void HunterApp::Init() {
		// Make sure this class is a singleton
		if (!instance)
			instance = new HunterApp;
	}
	
	HunterApp::HunterApp() {
		// Assert this class is a singleton
		assert(!instance);
		
		#ifdef _WIN32
			this->appWindow = new WindowsOSWindow;
		#elif __APPLE__
			this->appWindow = new macOSWindow;
		#endif
		
		// Assert that the window was created
		bool success{ this->appWindow->CreateWindow(800, 600) } ;
		assert(success);
	}
	
	int HunterApp::GetWindowWidth() {
		return instance->appWindow->GetWidth();
	}
	
	int HunterApp::GetWindowHeight() {
		return instance->appWindow->GetHeight();
	}
	
	HunterApp::~HunterApp() {
		this->appWindow->DeleteWindow();
	}
}
