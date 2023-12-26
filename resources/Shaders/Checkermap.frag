#version 330 core
out vec4 FragColor;

in vec3 Position;
in vec3 Normal;

struct Material
{
    sampler2D diffuseTexture;
    vec3 color;
    float shininess;
    float specularStrength;
};

struct AmbientLight
{
    vec3 color;
    float intensity;
};

uniform vec3 secondColor = vec3(0.0, 0.0, 0.0);

uniform vec3 lightPosition;
uniform vec3 lightColor = vec3(1.0, 1.0, 1.0);

uniform vec3 cameraPosition;

uniform Material material;
uniform AmbientLight ambientLight;

void main()
{
    vec3 normal = normalize(Normal);
    vec3 lightDirection = normalize(lightPosition - Position);
    float lightImpact = max(dot(normal, lightDirection), 0);
    vec3 diffuseColor = lightImpact * lightColor;

    vec3 viewDirection = normalize(cameraPosition - Position);
    vec3 reflectDirection = reflect(-lightDirection, normal);
    float specularImpact = pow(max(dot(viewDirection, reflectDirection), 0.0), material.shininess);
    vec3 specularColor = material.specularStrength * specularImpact * lightColor;

    vec3 lightColor = (ambientLight.color * ambientLight.intensity) + diffuseColor + specularColor;

    vec3 pos = floor(Position / 10);
    float patternMask = mod(pos.x + mod(pos.y, 2) + mod(pos.z, 2), 2);
    FragColor = patternMask * vec4(material.color, 1) + (1 - patternMask) * vec4(secondColor, 1);
    FragColor *= vec4(lightColor, 1);
}
