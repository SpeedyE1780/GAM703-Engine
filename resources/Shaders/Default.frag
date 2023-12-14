#version 330 core
out vec4 FragColor;

in vec2 TexCoords;

uniform sampler2D diffuse;
uniform vec3 color;

void main()
{
    FragColor = texture(diffuse, TexCoords) + vec4(color, 1);
}
