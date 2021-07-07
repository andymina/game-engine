//
//  Event.h
//  game-engine
//
//  Created by Andy Mina on 7/4/21.
//

#ifndef Event_h
#define Event_h

namespace Hunter {
	enum class EventType {
		KeyPressed,
		KeyReleased,
		WindowClose,
		WindowResize,
		WindowMinimize,
		WindowRestore
	};
	
	class Event {
	public:
		EventType GetEventType() const;
		
	private:
		EventType type;
	};
}

#endif /* Event_h */
