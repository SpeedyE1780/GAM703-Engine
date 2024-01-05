#include <engine/components/DirectionalLight.hpp>
#include <engine/components/Transform.hpp>

namespace gam703::engine::components
{
	DirectionalLight::DirectionalLight(Transform* transform, const glm::vec3& color, float intensity) : Light(transform, color, intensity)
	{
	}

	DirectionalLight* DirectionalLight::clone(Transform* transform) const
	{
		return new DirectionalLight(transform, m_color, m_intensity);
	}

	void DirectionalLight::updateShaderLightInfo(const core_interface::Shader& shader) const
	{
		shader.setVec3("directionalLight.color", m_color);
		shader.setFloat("directionalLight.intensity", m_intensity);
		shader.setVec3("directionalLight.direction", m_transform->getFront());
	}
}
