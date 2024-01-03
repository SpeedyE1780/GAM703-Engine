#include <engine/core-interfaces/IMaterial.hpp>

namespace gam703::engine::core_interface
{
	Material::Material(const Material& material) :
		m_color(material.m_color)

	{
	}

	Material& Material::operator=(const Material& material)
	{
		m_color = material.m_color;
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
