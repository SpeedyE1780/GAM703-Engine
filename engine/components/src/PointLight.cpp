#include <engine/components/PointLight.hpp>
#include <engine/components/Transform.hpp>

namespace gam703::engine::components
{
	PointLight::PointLight(core_interface::ITransform* transform, const glm::vec3& color, float range, float intensity) :
		core_interface::ILight(transform, color, intensity), m_range(range)
	{
	}

	core_interface::IComponent* PointLight::clone(core_interface::ITransform* transform) const
	{
		return new PointLight(m_transform, m_color, m_range, m_intensity);
	}

	void PointLight::updateShaderLightInfo(const core_interface::IShader& shader) const
	{
		shader.setVec3("pointLight.position", m_transform->getPosition());
		shader.setVec3("pointLight.color", m_color);
		shader.setFloat("pointLight.intensity", m_intensity);
		shader.setFloat("pointLight.range", m_range);
	}
}
