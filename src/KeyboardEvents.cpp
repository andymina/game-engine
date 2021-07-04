//
//  KeyboardEvents.cpp
//  game-engine
//
//  Created by Andy Mina on 7/4/21.
//

#include "pch.h"
#include "KeyboardEvents.h"

namespace Hunter {
	int KeyPressedEvent::GetKeyCode() const {
		return KeyCode;
	}
	
	int KeyReleasedEvent::GetKeyCode() const {
		return KeyCode;
	}
}
