#include <engine/components/Transform.hpp>

#include <game/components/AIMovement.hpp>
#include <game/components/Wander.hpp>

namespace gam703::game::components
{
	AIMovement::AIMovement(engine::components::Transform& transform) : engine::components::Behavior(transform)
	{
	}

	AIMovement::AIMovement(engine::components::Transform& transform, engine::components::Transform* player, const glm::vec3& origin, const glm::vec2& bounds) : AIMovement(transform)
	{
		m_currentMovementStrategy = m_transform.addComponent<Wander>(player, origin, bounds);
	}

	AIMovement* AIMovement::clone(engine::components::Transform& transform) const
	{
		return new AIMovement(transform);
	}

	void AIMovement::tick(float deltaTime)
	{
		m_currentMovementStrategy = m_currentMovementStrategy->processMovement(deltaTime);
	}
}
