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

	Wander::Wander(engine::components::Transform& transform, engine::components::Transform* playerTransform, const glm::vec3& origin, const glm::vec2& bounds) :
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

		if (glm::length(m_transform.getPosition() - m_player->getPosition()) <= SeekDistance)
		{
			exit();

			if (engine::utility::generateRandomNumber(0.0f, 1.0f) < 0.5f)
			{
				m_seek->enter();
				return m_seek;
			}
			else
			{
				m_flee->enter();
				return m_flee;
			}
		}

		return this;
	}

	void Wander::exit()
	{

	}
}
