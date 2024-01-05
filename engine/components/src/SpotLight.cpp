#include <engine/components/Transform.hpp>
#include <engine/components/SpotLight.hpp>

namespace gam703::engine::components
{
	SpotLight::SpotLight(Transform* transform, 
		const glm::vec3& color, float innerAngle, float outerAngle, float range, float intensity)
		: Light(transform, color, intensity), m_innerAngle(innerAngle), m_outerAngle(outerAngle), m_range(range)
	{
	}

	SpotLight* SpotLight::clone(Transform* transform) const
	{
		return new SpotLight(transform, m_color, m_innerAngle, m_outerAngle, m_range, m_intensity);
	}

	void SpotLight::updateShaderLightInfo(const graphic::Shader& shader) const
	{
		shader.setVec3("spotLight.position", m_transform->getPosition());
		shader.setVec3("spotLight.direction", m_transform->getFront());
		shader.setVec3("spotLight.color", m_color);
		shader.setFloat("spotLight.intensity", m_intensity);
		shader.setFloat("spotLight.range", m_range);
		shader.setFloat("spotLight.innerAngle", glm::cos(glm::radians(m_innerAngle)));
		shader.setFloat("spotLight.outerAngle", glm::cos(glm::radians(m_outerAngle)));
	}
}
