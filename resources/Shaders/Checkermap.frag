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

struct PointLight
{
    vec3 position;
    vec3 color;
    float intensity;
    float range;
};

uniform vec3 cameraPosition;

uniform Material material;
uniform AmbientLight ambientLight;
uniform DirectionalLight directionalLight;
uniform PointLight pointLight;

vec3 calculatePointLight(vec3 normal, vec3 viewDirection)
{
    float constant = 1.0f;
    float linear = 0.09f;
    float quadratic = 0.032f;

    // diffuse shading
    vec3 lightDirection = normalize(pointLight.position - Position);
    float lightImpact = max(dot(normal, lightDirection), 0.0) * pointLight.intensity;
    vec3 diffuseColor = lightImpact * pointLight.color * texture(material.diffuseTexture, TexCoords).rgb;

    // specular shading
    vec3 reflectDirection = reflect(-lightDirection, normal);
    float specularImpact = pow(max(dot(viewDirection, reflectDirection), 0.0), material.shininess);
    vec3 specularColor = material.specularStrength * specularImpact * pointLight.color * texture(material.specularTexture, TexCoords).rgb;

    // attenuation
    float attenuationDistance = max(length(pointLight.position - Position) - pointLight.range, 0);
    float attenuation = 1.0 / (constant + linear * attenuationDistance + quadratic * (attenuationDistance * attenuationDistance));

    diffuseColor *= attenuation;
    specularColor *= attenuation;

    return diffuseColor + specularColor;
}

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

    vec3 outputColor = ambientColor + diffuseColor + specularColor + calculatePointLight(normal, viewDirection);

    vec3 pos = floor(Position / 10);
    float patternMask = mod(pos.x + mod(pos.y, 2) + mod(pos.z, 2), 2);
    FragColor = patternMask * vec4(material.color, 1) + (1 - patternMask) * vec4(secondColor, 1);
    FragColor *= vec4(outputColor, 1);
}
