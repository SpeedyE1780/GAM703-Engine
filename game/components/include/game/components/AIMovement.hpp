#ifndef GAM703_GAME_COMPONENTS_AI_MOVEMENT_HPP
#define GAM703_GAME_COMPONENTS_AI_MOVEMENT_HPP

#include <engine/components/Behavior.hpp>

#include <game/components/Config.hpp>
#include <game/components/MovementStrategy.hpp>
#include <game/components/Flee.hpp>
#include <game/components/Seek.hpp>
#include <game/components/Wander.hpp>

namespace gam703::game::components
{
	class GAME_COMPONENTS_API AIMovement : public engine::components::Behavior
	{
	public:
		AIMovement(engine::components::Transform& transform, engine::components::Transform* player, const glm::vec3& origin, const glm::vec2& bounds);

		virtual AIMovement* clone(engine::components::Transform& transform) const override;
		virtual void tick(float deltaTime) override;

	private:
		engine::components::Transform* m_player;
		glm::vec3 m_origin;
		glm::vec2 m_bounds;
		Wander m_wander;
		Flee m_flee;
		Seek m_seek;
		MovementStrategy* m_currentMovementStrategy = nullptr;
	};
}

#endif // GAM703_GAME_COMPONENTS_AI_MOVEMENT_HPP
