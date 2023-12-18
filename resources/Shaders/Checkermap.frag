#version 330 core
out vec4 FragColor;

in vec3 Position;

uniform vec3 color = vec3(1.0, 1.0, 1.0);
uniform vec3 secondColor = vec3(0.0, 0.0, 0.0);

void main()
{
    vec3 pos = floor(Position / 10);
    float patternMask = mod(pos.x + mod(pos.y, 2) + mod(pos.z, 2), 2);
    FragColor = patternMask * vec4(color, 1) + (1 - patternMask) * vec4(secondColor, 1);
}
