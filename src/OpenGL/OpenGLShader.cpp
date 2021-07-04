//
//  OpenGLShader.cpp
//  game-engine
//
//  Created by Andy Mina on 6/28/21.
//

#include <fstream>
#include <sstream>
#include "pch.h"
#include "HunterCentral.h"
#include "OpenGL/OpenGLShader.h"

namespace Hunter {
	/**
	 Loads GLSL code.
	 @param path: the path to the GLSL file
	 @return: a string containing the code
	 */
	std::string OpenGLShader::ReadCode(const std::string &path) {
		// declare stream vars
		std::string code;
		std::ifstream CodeStream(path, std::ios::in);
		
		if (CodeStream.is_open()) {
			std::stringstream sstr;
			sstr << CodeStream.rdbuf();
			code = sstr.str();
			CodeStream.close();
			return code;
		} else {
			return "Error: Couldn't find file at " + path + "\n";
		}
	}
	
	/**
	 Given a const char* to the code, compiles it.
	 
	 @param code: a const char* to the code
	 @param type: the type of shader to compile. can be GL_VERTEX_SHADER or GL_FRAGMENT_SHADER
	 */
	unsigned int OpenGLShader::CompileShader(const char* code, const unsigned int &type) {
		// Declare shader and success flag
		unsigned int shader = glCreateShader(type);
		int success{ 0 };
		
		// Compile vertex
		glShaderSource(shader, 1, &code, nullptr);
		glCompileShader(shader);
		glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
		// Check vertex compilation was successful
		if (!success) {
			char infoLog[512];
			glGetShaderInfoLog(shader, 512, nullptr, infoLog);
			if (type == GL_VERTEX_SHADER)
				HLOG("ERROR COMPILING VERTEX SHADER");
			else
				HLOG("ERROR COMPILING FRAGMENT SHADER");
			HLOG(infoLog);
		}
		
		return shader;
	}
	
	bool OpenGLShader::Load(const std::string &vertexPath, const std::string &fragmentPath) {
		// Read vertex code from path and create shader
		std::string temp = ReadCode(vertexPath);
		if (temp.find("Error") != std::string::npos) {
			HLOG(temp);
			return false;
		}
		const char* vertexCode{ temp.c_str() };
		unsigned int vertexShader{ CompileShader(vertexCode, GL_VERTEX_SHADER) };
		if (!vertexShader) return false;
		
		// Read fragment code from path and create shader
		temp = ReadCode(fragmentPath);
		if (temp.find("Error") != std::string::npos) {
			HLOG(temp);
			return false;
		}
		const char* fragmentCode{ temp.c_str() };
		unsigned int fragmentShader{ CompileShader(fragmentCode, GL_FRAGMENT_SHADER) };
		if (!fragmentShader) return false;
		
		// Check if there was previous shader and clear it
		if (shaderProgram)
			glDeleteProgram(shaderProgram);
		
		// Attach and link shaders
		shaderProgram = glCreateProgram();
		glAttachShader(shaderProgram, vertexShader);
		glAttachShader(shaderProgram, fragmentShader);
		glLinkProgram(shaderProgram);
		
		// Check for errors
		int success{ 0 };
		glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
		if (!success) {
			char infoLog[512];
			glGetProgramInfoLog(shaderProgram, 512, nullptr, infoLog);
			HLOG("ERROR LINKING SHADER PROGRAM");
			HLOG(infoLog);
			return false;
		}
		
		// Clean up
		glDetachShader(shaderProgram, vertexShader);
		glDetachShader(shaderProgram, fragmentShader);
		glDeleteShader(vertexShader);
		glDeleteShader(fragmentShader);
		
		return true;
	}
	
	// Makes the current shader active
	void OpenGLShader::Use() {
		assert(shaderProgram);
		glUseProgram(shaderProgram);
	}
	
	void OpenGLShader::SetVec2Int(const std::string &uniformName, const int &width, const int &height){
		assert(shaderProgram);
		int uniformID{ glGetUniformLocation(shaderProgram, uniformName.c_str()) };
		glUniform2i(uniformID, width, height);
	}
	
	OpenGLShader::~OpenGLShader() {
		if (shaderProgram)
			glDeleteProgram(shaderProgram);
	}
}
