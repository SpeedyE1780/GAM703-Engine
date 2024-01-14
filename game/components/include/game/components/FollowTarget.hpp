#ifndef GAM703_GAME_COMPONENTS_FOLLOW_TARGET_HPP
#define GAM703_GAME_COMPONENTS_FOLLOW_TARGET_HPP

#include <engine/components/Behavior.hpp>
#include <engine/components/Transform.hpp>

#include <engine/utility/ObjectReference.hpp>

#include <game/components/Config.hpp>

#include <glm/glm.hpp>

#include <memory>

namespace gam703::game::components
{
	/// @brief Follow target around
	class FollowTarget : public engine::components::Behavior
	{
	public:
		/// @brief Follow the target with the given offset
		/// @param transform The transform owning this component
		/// @param target The target the transform follows
		/// @param offset The offset to keep between the transform and target
		FollowTarget(engine::components::Transform& transform, const engine::components::TransformReference& target, const glm::vec3& offset, float velocity = 2.0f);

		/// @brief Create a copy attached to the new transform
		/// @param transform The new transform that will own the clone
		/// @return The cloned FollowTarget belonging to the transform
		virtual FollowTarget* clone(engine::components::Transform& transform) const override;

		/// @brief Move transform towards target
		/// @param deltaTime Elapsed time between this frame and the last frame
		virtual void tick(float deltaTime) override;

	private:
		/// @brief Target to follow
		engine::components::TransformReference m_target;
		/// @brief Offset between transform position and target position to keep
		glm::vec3 m_offset{};
		/// @brief The velocity traveled every second
		float m_velocity = 2.0f;
	};
}

#endif // GAM703_GAME_COMPONENTS_FOLLOW_TARGET_HPP
