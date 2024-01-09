#include <engine/graphic/Material.hpp>
#include <engine/graphic/Shader.hpp>

namespace gam703::engine::graphic
{
	Material::Material(Shader& shader) : m_shader(shader)
	{
	}

	Material::Material(const Material& material) :
		m_color(material.m_color),
		m_shader(material.m_shader)
	{
	}

	Material& Material::operator=(const Material& material)
	{
		m_color = material.m_color;
		m_shader = material.m_shader;
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

	void Material::updateShaderUniforms() const
	{
		m_shader.setColor(m_color);
		m_shader.setVec3("secondColor", m_secondColor);
	}
}
