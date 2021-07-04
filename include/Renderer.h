//
//  Renderer.h
//  game-engine
//
//  Created by Andy Mina on 7/3/21.
//

#ifndef Renderer_h
#define Renderer_h

#include "Sprite.h"
#include "RendererImplementation.h"

namespace Hunter {
	class Renderer {
	public:
		static void Init();
		static void Terminate();
		static void Draw(const Sprite &img, int x_pos, int y_pos, int width, int height);
		
	private:
		Renderer();
		inline static Renderer* instance{ nullptr };
		RendererImplementation* DrawingEngine{ nullptr };
	};
}

#endif /* Renderer_h */
