#include <engine/graphic/Material.hpp>

namespace gam703::engine::graphic
{
	Material::Material() : m_shader(createDefaultShader())
	{
	}

	Material::Material(const Shader& shader) : m_shader(shader)
	{
	}

	Material::Material(const Material& material) :
		m_shader(material.m_shader),
		m_diffuseTextureIndex(material.m_diffuseTextureIndex),
		m_specularTextureIndex(material.m_specularTextureIndex),
		m_normalTextureIndex(material.m_normalTextureIndex),
		m_heightTextureIndex(material.m_heightTextureIndex),
		m_color(material.m_color)

	{
		m_shader.setDiffuseSampler(0, m_diffuseTextureIndex);
		m_shader.setSpecularSampler(0, m_specularTextureIndex);
		m_shader.setNormalSampler(0, m_normalTextureIndex);
		m_shader.setHeightSampler(0, m_heightTextureIndex);
		m_shader.setColor(m_color);
	}

	Material& Material::operator=(const Material& material)
	{
		m_shader = material.m_shader;
		m_diffuseTextureIndex = material.m_diffuseTextureIndex;
		m_specularTextureIndex = material.m_specularTextureIndex;
		m_normalTextureIndex = material.m_normalTextureIndex;
		m_heightTextureIndex = material.m_heightTextureIndex;
		m_color = material.m_color;

		m_shader.setDiffuseSampler(0, m_diffuseTextureIndex);
		m_shader.setSpecularSampler(0, m_specularTextureIndex);
		m_shader.setNormalSampler(0, m_normalTextureIndex);
		m_shader.setHeightSampler(0, m_heightTextureIndex);
		m_shader.setColor(m_color);

		return *this;
	}

	void Material::setDiffuseTexture(int diffuseIndex, int textureIndex)
	{
		m_diffuseTextureIndex = textureIndex;
		m_shader.setDiffuseSampler(diffuseIndex, m_diffuseTextureIndex);
	}

	void Material::setSpecularTexture(int specularIndex, int textureIndex)
	{
		m_specularTextureIndex = textureIndex;
		m_shader.setSpecularSampler(specularIndex, m_specularTextureIndex);
	}

	void Material::setNormalTexture(int normalIndex, int textureIndex)
	{
		m_normalTextureIndex = textureIndex;
		m_shader.setNormalSampler(normalIndex, m_normalTextureIndex);
	}

	void Material::setHeightTexture(int heightIndex, int textureIndex)
	{
		m_heightTextureIndex = textureIndex;
		m_shader.setHeightSampler(heightIndex, m_heightTextureIndex);
	}

	void Material::setColor(const glm::vec3& color)
	{
		m_color = color;
		m_shader.setColor(m_color);
	}
}
