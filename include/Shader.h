//
//  Shader.h
//  game-engine
//
//  Created by Andy Mina on 6/28/21.
//

#ifndef Shader_h
#define Shader_h

#include <string>
#include "HunterCentral.h"

namespace Hunter {
	class HUNTER_API Shader {
	public:
		virtual bool Load(const std::string &vertexPath, const std::string &fragmentPath) = 0;
		virtual void Use() = 0;
		virtual void SetVec2Int(const std::string &uniformName, const int &val1, const int &val2) = 0;
		virtual ~Shader() {};
		
	};
}

#endif /* Shader_h */
