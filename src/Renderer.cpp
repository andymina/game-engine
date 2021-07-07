//
//  Renderer.cpp
//  game-engine
//
//  Created by Andy Mina on 7/3/21.
//

#include "pch.h"
#include "Renderer.h"
#include "OpenGLImplementation.h"

namespace Hunter {
	Renderer::Renderer() {
		#ifdef _HUNTER_OPENGL
				drawingEngine = new OpenGLImplementation;
		#else
			#only_open_gl
		#endif
	}
	
	Renderer::~Renderer() {
		delete drawingEngine;
	}
	
	void Renderer::Init() {
		if (!instance)
			instance = new Renderer;
	}
	
	void Renderer::Terminate() {
		if (instance)
			delete instance;
	}
	
	void Renderer::ClearFrame() {
		instance->drawingEngine->ClearFrame();
	}
	
	void Renderer::Draw(const Sprite &img, int x_pos, int y_pos, int width, int height) {
		assert(instance);
		instance->drawingEngine->Draw(img, x_pos, y_pos, width, height);
	}
	
}
