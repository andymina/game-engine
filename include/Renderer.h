//
//  Renderer.h
//  game-engine
//
//  Created by Andy Mina on 7/3/21.
//

#ifndef Renderer_h
#define Renderer_h

#include "HunterCentral.h"
#include "Sprite.h"
#include "RendererImplementation.h"

namespace Hunter {
	class HUNTER_API Renderer {
	public:
		static void Init();
		static void Terminate();
		static void ClearFrame();
		static void Draw(const Sprite &img, int x_pos, int y_pos, int width, int height);
		
	private:
		Renderer();
		~Renderer();
		inline static Renderer* instance{ nullptr };
		RendererImplementation* drawingEngine{ nullptr };
	};
}

#endif /* Renderer_h */
