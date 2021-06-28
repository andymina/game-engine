//
//  OpenGLShader.h
//  game-engine
//
//  Created by Andy Mina on 6/28/21.
//

#ifndef OpenGLShader_h
#define OpenGLShader_h
#define GLFW_INCLUDE_NONE

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "HunterCentral.h"
#include "Shader.h"

namespace Hunter {
	class HUNTER_API OpenGLShader: public Shader {
	public:
		virtual bool Load(const std::string &vertexPath, const std::string &fragmentPath) override;
		virtual void Use() override;
		virtual void SetVec2Int(const std::string &uniformName, const int &width, const int &height) override;
		virtual ~OpenGLShader() override;
		
	private:
		unsigned int shaderProgram{ 0 };
		
		std::string ReadCode(const std::string &path);
		unsigned int CompileShader(const char* code, const unsigned int &type);
	};
}

#endif /* OpenGLShader_h */
