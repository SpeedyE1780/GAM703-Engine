#include <engine/core-interfaces/Material.hpp>
#include <engine/core-interfaces/Shader.hpp>

namespace gam703::engine::core_interface
{
	Material::Material() : m_shader(createDefaultShader())
	{
	}

	Material::Material(const core_interface::Shader& shader) : m_shader(shader)
	{
	}

	Material::Material(const Material& material) :
		m_color(material.m_color),
		m_shader(material.m_shader)

	{
		m_shader.setColor(m_color);
	}

	Material& Material::operator=(const Material& material)
	{
		m_color = material.m_color;
		m_shader = material.m_shader;
		m_shader.setColor(m_color);
		return *this;
		return *this;
	}

	void Material::setDiffuseTexture(int diffuseIndex, int textureIndex) const
	{
		getShader()->setDiffuseSampler(diffuseIndex, textureIndex);
	}

	void Material::setSpecularTexture(int specularIndex, int textureIndex) const
	{
		getShader()->setSpecularSampler(specularIndex, textureIndex);
	}

	void Material::setNormalTexture(int normalIndex, int textureIndex) const
	{
		getShader()->setNormalSampler(normalIndex, textureIndex);
	}

	void Material::setHeightTexture(int heightIndex, int textureIndex) const
	{
		getShader()->setHeightSampler(heightIndex, textureIndex);
	}

	void Material::setColor(const glm::vec3& color)
	{
		m_color = color;
		getShader()->setColor(m_color);
	}
}
