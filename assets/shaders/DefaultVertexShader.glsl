#version 330 core

layout (location = 0) in vec2 aPos;
layout (location = 1) in vec2 texData;
out vec2 texCoord;
uniform ivec2 windowSize;

void main() {
	gl_Position = vec4(aPos.x / (0.5 * windowSize.x) - 1, aPos.y / (0.5 * windowSize.y) - 1, 1.0, 1.0);
	texCoord = texData;
}
