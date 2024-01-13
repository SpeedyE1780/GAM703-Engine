#ifndef GAM703_GAME_COMPONENTS_AI_MOVEMENT_HPP
#define GAM703_GAME_COMPONENTS_AI_MOVEMENT_HPP

#include <engine/components/Behavior.hpp>
#include <engine/components/Transform.hpp>

#include <game/components/Config.hpp>
#include <game/components/MovementStrategy.hpp>
#include <game/components/Flee.hpp>
#include <game/components/Seek.hpp>
#include <game/components/Wander.hpp>

#include <memory>

namespace gam703::game::components
{
	/// @brief AIMovement is in charge of moving NPCs
	class GAME_COMPONENTS_API AIMovement : public engine::components::Behavior
	{
	public:
		/// @brief Create an AIMovement NPC
		/// @param transform The transform owning this behavior
		/// @param player The player the npc needs to follow
		/// @param origin The origin of the npc area
		/// @param bounds The bounds of the npc area
		/// @param power The power level of the npc
		AIMovement(engine::components::Transform& transform, const engine::components::TransformReference& player, const glm::vec3& origin, const glm::vec2& bounds, int power);

		/// @brief Create a copy attached to the new transform
		/// @param transform The new transform that will own the clone
		/// @return The cloned AIMovement belonging to the transform
		virtual AIMovement* clone(engine::components::Transform& transform) const override;

		/// @brief Move the npc using its current movement strategy
		/// @param deltaTime Elapsed time between this frame and the last frame
		virtual void tick(float deltaTime) override;

	private:
		/// @brief The player the npc needs to follow
		engine::components::TransformReference m_player;
		/// @brief The origin of the npc area
		/// @param bounds The bounds of the npc area
		glm::vec3 m_origin;
		/// @brief The bounds of the npc area
		glm::vec2 m_bounds;
		/// @brief The power level of the npc
		int m_power;
		/// @brief Wander movement strategy
		Wander m_wander;
		/// @brief Flee movement strategy
		Flee m_flee;
		/// @brief Seek movement strategy
		Seek m_seek;
		/// @brief Current movement strategy one of Wander, Seek and Flee
		MovementStrategy* m_currentMovementStrategy = nullptr;
	};
}

#endif // GAM703_GAME_COMPONENTS_AI_MOVEMENT_HPP
