#ifndef GAM703_GAME_COMPONENTS_WANDER_HPP
#define GAM703_GAME_COMPONENTS_WANDER_HPP

#include <engine/components/AudioPlayer.hpp>

#include <game/components/Flee.hpp>
#include <game/components/MovementStrategy.hpp>
#include <game/components/Seek.hpp>

#include <game/components/Config.hpp>

#include <glm/glm.hpp>

namespace gam703::game::components
{
	/// @brief Wander npc will move towards random point in area
	class GAME_COMPONENTS_API Wander : public MovementStrategy
	{
	public:
		/// @brief 
		/// @param transform The transform owning this component
		/// @param playerTransform The player the npc needs to follow
		/// @param origin The origin of the npc area
		/// @param bounds The bounds of the npc area
		/// @param aiPower The power level of the npc
		Wander(engine::components::Transform& transform, const engine::components::TransformReference& playerTransform, const glm::vec3& origin, const glm::vec2& bounds, int& aiPower);

		/// @brief Set the seek strategy
		/// @param seek The seek strategy
		void setSeek(Seek* seek) { m_seek = seek; }

		/// @brief Set the flee strategy
		/// @param flee The flee strategy
		void setFlee(Flee* flee) { m_flee = flee; }

		/// @brief Setup strategy
		virtual void enter() override;

		/// @brief Move npc using current strategy
		/// @param deltaTime Elapsed time between this frame and the last frame
		/// @return The next strategy to npc needs to use
		virtual MovementStrategy* processMovement(float deltaTime) override;

		/// @brief Clean up strategy
		virtual void exit() override;

	private:
		/// @brief Current position npc is moving towards
		glm::vec3 m_currentTarget;
		/// @brief Seek strategy wander exits to
		Seek* m_seek = nullptr;
		/// @brief Flee strategy wander exits to
		Flee* m_flee = nullptr;
	};
}

#endif // GAM703_GAME_COMPONENTS_WANDER_HPP
