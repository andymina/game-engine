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
#include "HunterKeys.h"

namespace Hunter {
	void HunterApp::RunGame() {
		HLOG("Starting the game");
		
		Renderer::Init();
		
		// Event loop
		while (!appWindow->ShouldClose()) {
			Renderer::ClearFrame();
			
			OnUpdate();
			
			this->appWindow->SwapBuffers();
			this->appWindow->PollForEvent();
		}
	}

	void HunterApp::OnUpdate() {
		
	}
	
	HunterApp* HunterApp::GetApplication() {
		return instance;
	}
	
	HunterApp::HunterApp() {
		// Assert this class is a singleton
		assert(!instance);
		instance = this;
		
		#ifdef _WIN32
			this->appWindow = new WindowsOSWindow;
		#elif __APPLE__
			this->appWindow = new macOSWindow;
		#endif
		
		// Assert that the window was created
		bool success{ this->appWindow->CreateWindow(800, 800) } ;
		assert(success);
		
		this->appWindow->SetKeyPressedCallback([this](KeyPressedEvent &event) {
			OnKeyPressed(event);
		});
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
	
	void HunterApp::OnKeyPressed(KeyPressedEvent &event) {
		 HLOG(event.GetKeyCode());
	}
}
