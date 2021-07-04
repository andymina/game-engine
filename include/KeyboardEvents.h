//
//  KeyboardEvents.h
//  game-engine
//
//  Created by Andy Mina on 7/4/21.
//

#ifndef KeyboardEvents_h
#define KeyboardEvents_h

namespace Hunter {
	class KeyPressedEvent: public Event {
	public:
		int GetKeyCode() const;
	private:
		int KeyCode{ -1 };
	};
	
	class KeyReleasedm Event: public Event {
	public:
		int GetKeyCode() const;
	private:
		int KeyCode{ -1 };
	};
}
#endif /* KeyboardEvents_h */
