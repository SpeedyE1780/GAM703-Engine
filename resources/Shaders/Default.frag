#version 330 core
out vec4 FragColor;

in vec2 TexCoords;

uniform sampler2D diffuse;
uniform vec3 color = vec3(1.0, 1.0, 1.0);

uniform vec3 ambientLight = vec3(1.0, 1.0, 1.0);

void main()
{
    FragColor = texture(diffuse, TexCoords) * vec4(color, 1) * vec4(ambientLight, 1);
}
