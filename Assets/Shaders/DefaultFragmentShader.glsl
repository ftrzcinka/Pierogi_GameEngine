#version 330 core
			
in vec2 TexCoord;
uniform sampler20 picture;

out vec4 FreagColor;
			
void main()
{
	FragColor = texture(picture, TexCoord);
}