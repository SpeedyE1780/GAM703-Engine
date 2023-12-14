#include <engine/graphic/Material.hpp>

namespace gam703::engine::graphic
{
	Material::Material() : m_shader(createDefaultShader())
	{
	}

	Material::Material(const Shader& shader) : m_shader(shader)
	{
	}

	void Material::setDiffuseTexture(int diffuseIndex, int textureIndex)
	{
		m_diffuseTextureIndex = textureIndex;
		m_shader.setDiffuseSampler(diffuseIndex, textureIndex);
	}

	void Material::setSpecularTexture(int specularIndex, int textureIndex)
	{
		m_specularTextureIndex = textureIndex;
		m_shader.setSpecularSampler(specularIndex, textureIndex);
	}

	void Material::setNormalTexture(int normalIndex, int textureIndex)
	{
		m_normalTextureIndex = textureIndex;
		m_shader.setNormalSampler(normalIndex, textureIndex);
	}

	void Material::setHeightTexture(int heightIndex, int textureIndex)
	{
		m_heightTextureIndex = textureIndex;
		m_shader.setHeightSampler(heightIndex, textureIndex);
	}

	void Material::setColor(const glm::vec3& color)
	{
		m_color = color;
		m_shader.setColor(m_color);
	}
}
