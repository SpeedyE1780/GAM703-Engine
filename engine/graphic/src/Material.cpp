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
		core_interface::Material(material),
		m_shader(material.m_shader)

	{
		m_shader.setColor(getColor());
	}

	Material& Material::operator=(const Material& material)
	{
		core_interface::Material::operator=(material);
		m_shader = material.m_shader;
		m_shader.setColor(getColor());
		return *this;
	}
}
