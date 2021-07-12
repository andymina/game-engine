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
	Sprite::Sprite(): img{ nullptr }, width{ -1 }, height{ -1 }, numChannels{ 0 }, spritePath{ "" } {}
	
	Sprite::Sprite(const std::string &spritePath): spritePath(spritePath) {
		stbi_set_flip_vertically_on_load(true);
		if (!Load(spritePath))
			HLOG("ERROR LOADING SPRITE");
	}
	
	// copy constructor
	Sprite::Sprite(const Sprite &other) {
		spritePath = other.GetSpritePath();
		Load(spritePath);
	}
	
	// copy assignment
	Sprite& Sprite::operator=(const Sprite &rhs) {
		if (this != &rhs) {
			spritePath = rhs.spritePath;
			Load(spritePath);
		}
		
		return *this;
	}
	
	// move constructor
	Sprite::Sprite(Sprite &&other) {
		img = other.img;
		width = other.width;
		height = other.height;
		numChannels = other.numChannels;
		spritePath = other.spritePath;
		Load(spritePath);
		
		other.img = nullptr;
		other.width = -1;
		other.height = -1;
		other.numChannels = -1;
		other.spritePath = "";
	}
	
	Sprite& Sprite::operator=(Sprite &&rhs) {
		if (img) {
			stbi_image_free(img);
		}
		
		img = nullptr;
		width = -1;
		height = -1;
		numChannels = -1;
		spritePath = "";
		
		std::swap(img, rhs.img);
		std::swap(width, rhs.width);
		std::swap(height, rhs.height);
		std::swap(numChannels, rhs.numChannels);
		std::swap(spritePath, rhs.spritePath);
		
		return *this;
	}
		
	Sprite::~Sprite() {
		if (img) {
			stbi_image_free(img);
		}
	}
	
	int Sprite::GetWidth() const {
		return width;
	}
	
	int Sprite::GetHeight()	const {
		return height;
	}
	
	std::string Sprite::GetSpritePath() const {
		return spritePath;
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
