#include <engine/utility/Math.hpp>

#include <game/components/FollowTarget.hpp>

namespace gam703::game::components
{
	FollowTarget::FollowTarget(engine::components::Transform& transform, engine::components::Transform* target, const glm::vec3& offset) :
		engine::components::Behavior(transform),
		m_target(target->getReference()),
		m_offset(offset)
	{
	}

	FollowTarget* FollowTarget::clone(engine::components::Transform& transform) const
	{
		return new FollowTarget(transform, m_target->getObject(), m_offset);
	}

	void FollowTarget::tick(float deltaTime)
	{
		if (*m_target)
		{
			glm::vec3 targetPosition = (*m_target)->getPosition() + m_offset;
			glm::vec3 newPosition = engine::utility::moveTowards(m_transform.getPosition(), targetPosition, deltaTime * 2.0f);

			m_transform.setPosition(newPosition);
		}
	}
}

