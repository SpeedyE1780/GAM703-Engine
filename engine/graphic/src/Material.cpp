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
		m_color(material.m_color)

	{
		m_shader.setColor(m_color);
	}

	Material& Material::operator=(const Material& material)
	{
		m_shader = material.m_shader;
		m_color = material.m_color;
		m_shader.setColor(m_color);
		return *this;
	}

	void Material::setDiffuseTexture(int diffuseIndex, int textureIndex) const
	{
		m_shader.setDiffuseSampler(diffuseIndex, textureIndex);
	}

	void Material::setSpecularTexture(int specularIndex, int textureIndex) const
	{
		m_shader.setSpecularSampler(specularIndex, textureIndex);
	}

	void Material::setNormalTexture(int normalIndex, int textureIndex) const
	{
		m_shader.setNormalSampler(normalIndex, textureIndex);
	}

	void Material::setHeightTexture(int heightIndex, int textureIndex) const
	{
		m_shader.setHeightSampler(heightIndex, textureIndex);
	}

	void Material::setColor(const glm::vec3& color)
	{
		m_color = color;
		m_shader.setColor(m_color);
	}
}
