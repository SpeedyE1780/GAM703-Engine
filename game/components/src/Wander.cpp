#include <engine/core/Engine.hpp>

#include <engine/components/Transform.hpp>

#include <engine/utility/Math.hpp>

#include <game/components/Wander.hpp>

namespace gam703::game::components
{
	namespace
	{
		glm::vec3 getPointInSquare(const glm::vec2& bounds, const glm::vec3& center)
		{
			return center + glm::vec3(engine::utility::generateRandomNumber(-bounds.x, bounds.x), 0.0f, engine::utility::generateRandomNumber(-bounds.y, bounds.y));
		}
	}

	Wander::Wander(engine::components::Transform& transform, const engine::components::TransformReference& playerTransform, const glm::vec3& origin, const glm::vec2& bounds) :
		MovementStrategy(transform),
		m_origin(origin),
		m_player(playerTransform),
		m_bounds(bounds),
		m_currentTarget(getPointInSquare(bounds, m_origin))
	{
	}

	void Wander::enter()
	{
		m_currentTarget = getPointInSquare(m_bounds, m_origin);
	}

	MovementStrategy* Wander::processMovement(float deltaTime)
	{
		m_transform.setPosition(engine::utility::moveTowards(m_transform.getPosition(), m_currentTarget, deltaTime));

		if (m_transform.getPosition() == m_currentTarget)
		{
			m_currentTarget = getPointInSquare(m_bounds, m_origin);
		}

		if (m_player && glm::length(m_transform.getPosition() - m_player->getPosition()) <= SeekDistance)
		{
			if (engine::utility::generateRandomNumber(0.0f, 1.0f) < 0.5f)
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
