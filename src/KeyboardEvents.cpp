//
//  KeyboardEvents.cpp
//  game-engine
//
//  Created by Andy Mina on 7/4/21.
//

#include "pch.h"
#include "KeyboardEvents.h"

namespace Hunter {
	KeyPressedEvent::KeyPressedEvent(int key): KeyCode(key) {};
	
	int KeyPressedEvent::GetKeyCode() const {
		return KeyCode;
	}
	
	KeyReleasedEvent::KeyReleasedEvent(int key): KeyCode(key) {};
	int KeyReleasedEvent::GetKeyCode() const {
		return KeyCode;
	}
}
