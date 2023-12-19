#include <engine/core-interfaces/ITransform.hpp>

#include <game/components/Wonder.hpp>

namespace gam703::game::components
{
	Wonder::Wonder(engine::core_interface::ITransform* transform) : engine::core_interface::IComponent(transform), m_origin(transform->getPosition())
	{
	}

	engine::core_interface::IComponent* Wonder::clone(engine::core_interface::ITransform* transform) const
	{
		return new Wonder(transform);
	}

	void Wonder::tick(float deltaTime)
	{
		m_angle += deltaTime;
		m_transform->setPosition(m_origin + glm::vec3(glm::cos(m_angle), 0.0f, glm::sin(m_angle)) * m_radius);
		m_transform->setRotation(0.0f, m_angle, 0.0f);
	}
}
