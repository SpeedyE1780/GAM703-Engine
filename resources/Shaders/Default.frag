#version 330 core
out vec4 FragColor;

in vec2 TexCoords;
in vec3 Position;
in vec3 Normal;

struct Material
{
    sampler2D diffuseTexture;
    vec3 color;
    float shininess;
    float specularStrength;
};


uniform vec3 ambientLight = vec3(1.0, 1.0, 1.0);
uniform vec3 lightPosition;
uniform vec3 lightColor = vec3(1.0, 1.0, 1.0);

uniform vec3 cameraPosition;

uniform Material material;

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

    vec3 outputColor = (ambientLight + diffuseColor + specularColor) * material.color;
    FragColor = texture(material.diffuseTexture, TexCoords) * vec4(outputColor, 1);
}
