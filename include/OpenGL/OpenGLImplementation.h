//
//  OpenGLImplementation.h
//  game-engine
//
//  Created by Andy Mina on 7/3/21.
//

#ifndef OpenGLImplementation_h
#define OpenGLImplementation_h

#include "RendererImplementation.h"
#include "OpenGLShader.h"

namespace Hunter {
	class OpenGLImplementation: public RendererImplementation {
	public:
		OpenGLImplementation();
		virtual void Init() override;
		virtual void Draw(const Sprite &image, int x_pos, int y_pos, int width, int height) override;
		virtual ~OpenGLImplementation() override;
		
	private:
		OpenGLShader defaultShader;
	};
}

#endif /* OpenGLImplementation_h */
