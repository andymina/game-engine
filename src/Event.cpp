//
//  Event.cpp
//  game-engine
//
//  Created by Andy Mina on 7/4/21.
//

#include "pch.h"
#include "Event.h"

namespace Hunter {
	EventType Event::GetEventType() const {
		return type;
	}
}
