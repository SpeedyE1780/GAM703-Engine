#version 330 core
out vec4 FragColor;

in vec2 TexCoords;
in vec3 Position;
in vec3 Normal;

uniform sampler2D diffuse;
uniform vec3 color = vec3(1.0, 1.0, 1.0);

uniform vec3 ambientLight = vec3(1.0, 1.0, 1.0);
uniform vec3 lightPosition;
uniform vec3 lightColor = vec3(1.0, 1.0, 1.0);

void main()
{
    vec3 normal = normalize(Normal);
    vec3 lightDirection = normalize(lightPosition - Position);
    float lightImpact = max(dot(normal, lightDirection), 0);
    vec3 diffuseColor = lightImpact * lightColor;
    vec3 outputColor = (ambientLight + diffuseColor) * color;
    FragColor = texture(diffuse, TexCoords) * vec4(outputColor, 1);
}
