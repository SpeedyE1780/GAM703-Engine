#version 330 core
layout (location = 0) in vec3 position;
layout (location = 1) in vec3 normal;
layout (location = 2) in vec2 textureCoordinates;

out vec2 TexCoords;
out vec3 LocalPosition;
out vec3 Position;
out vec3 Normal;

uniform mat3 normalMatrix;
uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main()
{
    TexCoords = textureCoordinates;
    LocalPosition = position;
    Position = vec3(model * vec4(position, 1.0));
    Normal = normalMatrix * normal;
    gl_Position = projection * view * model * vec4(position, 1.0);
}
