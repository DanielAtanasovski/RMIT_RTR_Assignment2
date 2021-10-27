#version 330 core

struct Material {
	vec3 Ambient;
	sampler2D Diffuse;
	sampler2D Specular;
	float Shininess;
};
uniform Material material;

struct PointLight {
	vec3 Ambient;
	vec3 Diffuse;
	vec3 Specular;

	vec3 Position;

	float Constant;
	float Linear;
	float Quadratic;
};
uniform PointLight light;

struct DirectionalLight {
	vec3 Ambient;
	vec3 Diffuse;
	vec3 Specular;
	vec3 Direction;
};

uniform vec3 viewPos;

in vec3 Normal;
in vec3 FragPos;
in vec2 TexCoords;

out vec4 outFragColour;

void main() 
{
	// Ambient
	vec3 ambient = light.Ambient * texture(material.Diffuse, TexCoords).rgb;

	// Diffuse
	vec3 norm = normalize(Normal);
	vec3 lightDir = normalize(light.Position - FragPos);
	float diff = max(dot(norm, lightDir), 0.0);
	vec3 diffuse = light.Diffuse * diff * texture(material.Diffuse, TexCoords).rgb;

	// Specular
	vec3 viewDir = normalize(viewPos - FragPos);
	vec3 reflectDir = reflect(-lightDir, norm);
	float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.Shininess);
	vec3 specular = light.Specular * spec * texture(material.Specular, TexCoords).rgb;

	vec3 result = ambient + diffuse + specular;
	outFragColour = vec4(result, 1.0f);
}