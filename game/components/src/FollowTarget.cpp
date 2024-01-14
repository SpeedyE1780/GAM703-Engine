#include <engine/core/Engine.hpp>

#include <engine/utility/Math.hpp>

#include <game/components/FollowTarget.hpp>

namespace gam703::game::components
{
	FollowTarget::FollowTarget(engine::components::Transform& transform, const engine::components::TransformReference& target, const glm::vec3& offset, float velocity) :
		engine::components::Behavior(transform),
		m_target(target),
		m_offset(offset),
		m_velocity(velocity)
	{
	}

	FollowTarget* FollowTarget::clone(engine::components::Transform& transform) const
	{
		return new FollowTarget(transform, m_target, m_offset);
	}

	void FollowTarget::tick(float deltaTime)
	{
		if (m_target)
		{
			glm::vec3 targetPosition = m_target->getPosition() + m_offset;
			glm::vec3 newPosition = engine::utility::moveTowards(m_transform.getPosition(), targetPosition, getEngine().getTime().getUnscaledDeltaTime() * m_velocity);

			m_transform.setPosition(newPosition);
		}
	}
}

