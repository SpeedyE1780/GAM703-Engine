#include <engine/core-interfaces/ITransform.hpp>

#include <game/components/Wonder.hpp>

namespace gam703::game::components
{
	Wonder::Wonder(engine::core_interface::ITransform* transform, engine::core_interface::ITransform* playerTransform) : engine::core_interface::IComponent(transform), m_origin(transform->getPosition()), m_player(playerTransform)
	{
	}

	engine::core_interface::IComponent* Wonder::clone(engine::core_interface::ITransform* transform) const
	{
		return new Wonder(transform, m_player);
	}

	void Wonder::tick(float deltaTime)
	{
		if (glm::distance(m_origin, m_player->getPosition()) > m_radius)
		{
			m_angle += deltaTime;
			m_transform->setPosition(m_origin + glm::vec3(glm::cos(m_angle), 0.0f, glm::sin(m_angle)) * m_radius);
			m_transform->setRotation(0.0f, m_angle, 0.0f);
		}
		else
		{
			m_transform->setPosition(m_player->getPosition());
		}
	}
}
