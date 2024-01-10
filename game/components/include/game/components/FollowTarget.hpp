#ifndef GAM703_GAME_COMPONENTS_FOLLOW_TARGET_HPP
#define GAM703_GAME_COMPONENTS_FOLLOW_TARGET_HPP

#include <engine/components/Behavior.hpp>

#include <game/components/Config.hpp>

#include <glm/glm.hpp>

namespace gam703::game::components
{
	class FollowTarget : public engine::components::Behavior
	{
	public:
		FollowTarget(engine::components::Transform& transform, engine::components::Transform* target, const glm::vec3& offset);

		virtual FollowTarget* clone(engine::components::Transform& transform) const override;

		virtual void tick(float deltaTime) override;

	private:
		engine::components::Transform* m_target = nullptr;
		glm::vec3 m_offset{};
	};
}

#endif // GAM703_GAME_COMPONENTS_FOLLOW_TARGET_HPP
