#include <engine/core-interfaces/ILight.hpp>

namespace gam703::engine::core_interface
{
	ILight::ILight(Transform* transform, const glm::vec3& color, float intensity) : IComponent(transform), m_color(color), m_intensity(intensity)
	{
	}
}
