//
//  KeyboardEvents.h
//  game-engine
//
//  Created by Andy Mina on 7/4/21.
//

#ifndef KeyboardEvents_h
#define KeyboardEvents_h

#include "Event.h"

namespace Hunter {
	class KeyPressedEvent: public Event {
	public:
		KeyPressedEvent(int key);
		int GetKeyCode() const;
		
	private:
		int KeyCode{ -1 };
	};
	
	class KeyReleasedEvent: public Event {
	public:
		KeyReleasedEvent(int key);
		int GetKeyCode() const;
	private:
		int KeyCode{ -1 };
	};
}
#endif /* KeyboardEvents_h */
