//
//  Sprite.h
//  game-engine
//
//  Created by Andy Mina on 6/28/21.
//

#ifndef Sprite_h
#define Sprite_h

#include "HunterCentral.h"
#include "pch.h"

namespace Hunter {
	class HUNTER_API Sprite {
	public:
		Sprite(const std::string &spritePath);
		bool Load(const std::string &spritePath);
		int GetWidth() const;
		int GetHeight() const;
		~Sprite();
		
	private:
		unsigned char* img{ nullptr };
		int width;
		int height;
		int numChannels{ 0 };
	};
}

#endif /* Sprite_h */
