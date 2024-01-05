#include <engine/components/PointLight.hpp>
#include <engine/components/Transform.hpp>

namespace gam703::engine::components
{
	PointLight::PointLight(Transform& transform, const glm::vec3& color, float range, float intensity) :
		Light(transform, color, intensity), m_range(range)
	{
	}

	PointLight* PointLight::clone(Transform& transform) const
	{
		return new PointLight(m_transform, m_color, m_range, m_intensity);
	}

	void PointLight::updateShaderLightInfo(const graphic::Shader& shader) const
	{
		shader.setVec3("pointLight.position", m_transform.getPosition());
		shader.setVec3("pointLight.color", m_color);
		shader.setFloat("pointLight.intensity", m_intensity);
		shader.setFloat("pointLight.range", m_range);
	}
}
