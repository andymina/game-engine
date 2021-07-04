//
//  OpenGLImplementation.cpp
//  game-engine
//
//  Created by Andy Mina on 7/3/21.
//

#include "pch.h"
#include "HunterApp.h"
#include "OpenGLImplementation.h"

namespace Hunter {
	OpenGLImplementation::OpenGLImplementation() {
		Init();
	}
	
	void OpenGLImplementation::Init() {
		std::string vertexPath = "assets/shaders/DefaultVertexShader.glsl";
		std::string fragmentPath = "assets/shaders/DefaultFragmentShader.glsl";
		if (!defaultShader.Load(vertexPath, fragmentPath))
			HLOG("ERROR: FAILED TO LOAD SHADERS");
		defaultShader.Use();
		
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	}
	
	/**
	 Draws a sprite on the screen.
	 
	 @param image 	the sprite to be drawn
	 @param x_pos 	the x pos of the image on the screen
	 @param y_pos 	the y pos of the image on the screen
	 @param width 	the width of the sprite
	 @param height 	the height of the sprite
	 */
	void OpenGLImplementation::Draw(const Sprite &image, int x_pos, int y_pos, int width, int height) {
		// Create vertex array
		float vertices[] = {
			(float)x_pos, 					(float)y_pos,							0.0f, 0.0f, // bottom left
			(float)x_pos, 					(float)(y_pos + height),	0.0f, 1.0f, // top left
			(float)(x_pos + width), (float)y_pos,							1.0f, 0.0f, // bottom right
			(float)(x_pos + width), (float)(y_pos + height),	1.0f, 1.0f // top right
		};
		
		
		/**
		 Declare and initialize VBO and VAO. VBO is a vertex buffer object which stores the data
		 for multiple vertices. VAO is vertex array object which stores multiple VBOs.
		 */
		unsigned int VAO; // declare VAO
		glGenVertexArrays(1, &VAO); // generate one buffer and link it to VAO
		
		glBindVertexArray(VAO); // bind the VAO
		
		unsigned int VBO; // declare VBO
		glGenBuffers(1, &VBO); // generate one buffer and link it to VBO
		glBindBuffer(GL_ARRAY_BUFFER, VBO); // bind VBO to the GL_ARRAY_BUFFER
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
		
		/**
		 OpenGL is consistently handed raw data. This function describes how it should interpret
		 the VBO.
		 
		 @param first: index of which vertex attribute we want to configure
		 @param second: how many items make up the vertex
		 @param third: what data type is in the vertex
		 @param fourth: if the vertex should be normalized (remapped to 0->1 range)
		 @param fifth: the byte size of one vertex
		 @param sixth: offset of where data begins in the buffer
		 */
		// set props for x_pos, y_pos screen vertices
		glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)0);
		glEnableVertexAttribArray(0);
		
		// set props for OpenGL normalized screen vertices
		glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)(2 * sizeof(float)));
		glEnableVertexAttribArray(1);
		
		// set the texture
		unsigned int picture;
		glGenTextures(1, &picture);
		glBindTexture(GL_TEXTURE_2D, picture);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image.GetImagePointer());
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		
		defaultShader.SetVec2Int("windowSize", HunterApp::GetWindowWidth(), HunterApp::GetWindowHeight());
		
		// draw the code
		glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
	}
	
	OpenGLImplementation::~OpenGLImplementation() {
		
	}
}
