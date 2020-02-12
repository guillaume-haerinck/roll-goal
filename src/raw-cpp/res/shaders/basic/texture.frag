#version 300 es

out highp vec4 FragColor;

in highp vec2 TexCoord;

uniform sampler2D ourTexture;

void main() {
	FragColor = texture(ourTexture, TexCoord);
}
