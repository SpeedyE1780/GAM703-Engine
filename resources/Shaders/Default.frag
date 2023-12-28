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

struct SpotLight
{
    vec3 position;
    vec3 direction;
    vec3 color;
    float intensity;
    float range;
    float innerAngle;
    float outerAngle;
};

uniform vec3 cameraPosition;

uniform Material material;
uniform AmbientLight ambientLight;
uniform DirectionalLight directionalLight;
uniform PointLight pointLight;
uniform SpotLight spotLight;

vec3 calculateAmbientLight()
{
    return (ambientLight.color * ambientLight.intensity) * texture(material.diffuseTexture, TexCoords).rgb;
}

vec3 calculateDirectionalLight(vec3 normal, vec3 viewDirection)
{
    vec3 lightDirection = normalize(-directionalLight.direction);
    float lightImpact = max(dot(normal, lightDirection), 0) * directionalLight.intensity;
    vec3 diffuseColor = lightImpact * directionalLight.color * texture(material.diffuseTexture, TexCoords).rgb;

    vec3 reflectDirection = reflect(-lightDirection, normal);

    float specularImpact = pow(max(dot(viewDirection, reflectDirection), 0.0), material.shininess) * directionalLight.intensity;
    vec3 specularColor = material.specularStrength * specularImpact * directionalLight.color * texture(material.specularTexture, TexCoords).rgb;

    return diffuseColor + specularColor;
}

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

vec3 calculateSpotLight(vec3 normal, vec3 viewDirection)
{
    float constant = 1.0f;
    float linear = 0.09f;
    float quadratic = 0.032f;

    vec3 lightDirection = normalize(spotLight.position - Position);
    float lightImpact = max(dot(normal, lightDirection), 0.0) * spotLight.intensity;
    vec3 diffuseColor = lightImpact * spotLight.color * texture(material.diffuseTexture, TexCoords).rgb;

    vec3 reflectDirection = reflect(-lightDirection, normal);
    float specularImpact = pow(max(dot(viewDirection, reflectDirection), 0.0), material.shininess);
    vec3 specularColor = material.specularStrength * specularImpact * spotLight.color * texture(material.specularTexture, TexCoords).rgb;

    float theta = dot(lightDirection, normalize(-spotLight.direction));
    float epsilon = (spotLight.innerAngle - spotLight.outerAngle);
    float intensity = clamp((theta - spotLight.outerAngle) / epsilon, 0.0, 1.0);

    // attenuation
    float attenuationDistance = max(length(spotLight.position - Position) - spotLight.range, 0);
    float attenuation = 1.0 / (constant + linear * attenuationDistance + quadratic * (attenuationDistance * attenuationDistance));

    diffuseColor  *= intensity * attenuation;
    specularColor *= intensity * attenuation;

    return diffuseColor + specularColor;
}

void main()
{
    vec3 normal = normalize(Normal);
    vec3 viewDirection = normalize(cameraPosition - Position);

    vec3 outputColor = (calculateAmbientLight() + calculateDirectionalLight(normal, viewDirection) + calculatePointLight(normal, viewDirection) + calculateSpotLight(normal, viewDirection)) * material.color;
    FragColor = vec4(outputColor, 1);
}
