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
				DrawingEngine = new OpenGLImplementation;
		#else
			#only_open_gl
		#endif
	}
	
	void Renderer::Init() {
		if (!instance)
			instance = new Renderer;
	}
	
	void Renderer::Terminate() {
		if (instance)
			delete instance;
	}
	
	void Renderer::Draw(const Sprite &img, int x_pos, int y_pos, int width, int height) {
		assert(instance);
		instance->DrawingEngine->Draw(img, x_pos, y_pos, width, height);
	}
}
