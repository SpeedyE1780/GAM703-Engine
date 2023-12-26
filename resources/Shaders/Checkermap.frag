#version 330 core
out vec4 FragColor;

in vec2 TexCoords;
in vec3 Position;
in vec3 Normal;

struct Material
{
    sampler2D diffuseTexture;
    sampler2D specularTexture;
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

struct DirectionalLight
{
    vec3 direction;
    vec3 color;
    float intensity;
};

uniform vec3 cameraPosition;

uniform Material material;
uniform AmbientLight ambientLight;
uniform DirectionalLight directionalLight;

void main()
{
    vec3 ambientColor = (ambientLight.color * ambientLight.intensity) * texture(material.diffuseTexture, TexCoords).rgb;

    vec3 normal = normalize(Normal);
    vec3 lightDirection = normalize(-directionalLight.direction);
    float lightImpact = max(dot(normal, lightDirection), 0) * directionalLight.intensity;
    vec3 diffuseColor = lightImpact * directionalLight.color * texture(material.diffuseTexture, TexCoords).rgb;

    vec3 viewDirection = normalize(cameraPosition - Position);
    vec3 reflectDirection = reflect(-lightDirection, normal);

    float specularImpact = pow(max(dot(viewDirection, reflectDirection), 0.0), material.shininess) * directionalLight.intensity;
    vec3 specularColor = material.specularStrength * specularImpact * directionalLight.color * texture(material.specularTexture, TexCoords).rgb;

    vec3 outputColor = ambientColor + diffuseColor + specularColor;

    vec3 pos = floor(Position / 10);
    float patternMask = mod(pos.x + mod(pos.y, 2) + mod(pos.z, 2), 2);
    FragColor = patternMask * vec4(material.color, 1) + (1 - patternMask) * vec4(secondColor, 1);
    FragColor *= vec4(outputColor, 1);
}
