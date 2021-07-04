#version 330 core
in vec2 texCoord;
out vec4 FragColor;

uniform sampler2D ourTexture;

void main() {
//	FragColor = vec4(1.0, 0.0, 0.0, 1.0);
	FragColor = texture(ourTexture, texCoord);
}
