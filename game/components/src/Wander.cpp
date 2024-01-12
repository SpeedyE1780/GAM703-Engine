#include <engine/core/Engine.hpp>

#include <engine/components/Transform.hpp>

#include <engine/utility/Math.hpp>

#include <game/components/MovementController.hpp>
#include <game/components/Wander.hpp>

namespace gam703::game::components
{
	Wander::Wander(engine::components::Transform& transform, const engine::components::TransformReference& playerTransform, const glm::vec3& origin, const glm::vec2& bounds, int& aiPower) :
		MovementStrategy(transform),
		m_player(playerTransform),
		m_origin(origin),
		m_bounds(bounds),
		m_aiPower(aiPower),
		m_currentTarget(engine::utility::getPointInRectangle(m_origin, m_bounds))
	{
	}

	void Wander::enter()
	{
		m_currentTarget = engine::utility::getPointInRectangle(m_origin, m_bounds);
	}

	MovementStrategy* Wander::processMovement(float deltaTime)
	{
		m_transform.setPosition(engine::utility::moveTowards(m_transform.getPosition(), m_currentTarget, deltaTime));

		if (m_transform.getPosition() == m_currentTarget)
		{
			m_currentTarget = engine::utility::getPointInRectangle(m_origin, m_bounds);
		}

		if (m_player && glm::length(m_transform.getPosition() - m_player->getPosition()) <= SeekDistance)
		{
			auto* playerMovement = m_player->getBehavior<MovementController>();

			if (playerMovement->getPower() <= m_aiPower)
			{
				return m_seek;
			}
			else
			{
				return m_flee;
			}
		}

		return this;
	}

	void Wander::exit()
	{

	}
}
