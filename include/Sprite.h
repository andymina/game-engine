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
		Sprite(); // zero param constructor
		Sprite(const std::string &spritePath);
		Sprite(const Sprite &other); // copy constructor
		Sprite(Sprite &&other); // move constructor
		Sprite& operator=(const Sprite &rhs); // copy assignment
		Sprite& operator=(Sprite &&rhs); // move assignment
		~Sprite();
		
		bool Load(const std::string &spritePath);
		int GetWidth() const;
		int GetHeight() const;
		std::string GetSpritePath() const;
		const unsigned char* GetImagePointer() const;
		
	private:
		unsigned char *img{ nullptr };
		std::string spritePath { "" };
		int width{ -1 };
		int height{ -1 };
		int numChannels{ 0 };
	};
}

#endif /* Sprite_h */
