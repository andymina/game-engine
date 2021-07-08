//
//  Sprite.cpp
//  game-engine
//
//  Created by Andy Mina on 6/28/21.
//

#include <stbi/stb_image.h>
#include "pch.h"
#include "Sprite.h"

namespace Hunter {
	Sprite::Sprite(): img{ nullptr }, width{ -1 }, height{ -1 }, numChannels{ 0 } {}
	
	Sprite::Sprite(const std::string &spritePath) {
		stbi_set_flip_vertically_on_load(true);
		if (!Load(spritePath))
			HLOG("ERROR LOADING SPRITE");
	}
	
	Sprite::~Sprite() {
		if (img)
			stbi_image_free(img);
	}
	
	int Sprite::GetWidth() const {
		return width;
	}
	
	int Sprite::GetHeight()	const {
		return height;
	}
	
	bool Sprite::Load(const std::string &spritePath) {
		img = stbi_load(spritePath.c_str(), &width, &height, &numChannels, 0);
		
		if (img) return true;
		else return false;
	}
	
	const unsigned char* Sprite::GetImagePointer() const {
		return img;
	}
}
