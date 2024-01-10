#ifndef GAM703_GAME_COMPONENTS_AI_MOVEMENT_HPP
#define GAM703_GAME_COMPONENTS_AI_MOVEMENT_HPP

#include <engine/components/Behavior.hpp>

#include <game/components/Config.hpp>
#include <game/components/MovementStrategy.hpp>

namespace gam703::game::components
{
	class GAME_COMPONENTS_API AIMovement : public engine::components::Behavior
	{
	public:
		AIMovement(engine::components::Transform& transform);
		AIMovement(engine::components::Transform& transform, engine::components::Transform* player, const glm::vec3& origin, const glm::vec2& bounds);

		virtual AIMovement* clone(engine::components::Transform& transform) const override;
		virtual void tick(float deltaTime) override;

	private:
		MovementStrategy* m_currentMovementStrategy = nullptr;
	};
}

#endif // GAM703_GAME_COMPONENTS_AI_MOVEMENT_HPP
