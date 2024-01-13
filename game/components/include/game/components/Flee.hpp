#ifndef GAM703_GAME_COMPONENTS_FLEE_HPP
#define GAM703_GAME_COMPONENTS_FLEE_HPP

#include <game/components/Config.hpp>
#include <game/components/MovementStrategy.hpp>

namespace gam703::game::components
{
	class Wander;

	/// @brief Flee npc will move away from player
	class GAME_COMPONENTS_API Flee : public MovementStrategy
	{
	public:
		/// @brief Create a Flee strategy to escape from player
		/// @param transform The transform owning this component
		/// @param player The player the npc needs to follow
		/// @param wander The wander strategy the npc exits too
		/// @param origin The origin of the npc area
		/// @param bounds The bounds of the npc area
		/// @param aiPower The power level of the npc
		Flee(engine::components::Transform& transform, const engine::components::TransformReference& player, Wander* wander, const glm::vec3& origin, const glm::vec2& bounds, int& aiPower);

		/// @brief Setup strategy
		virtual void enter() override;

		/// @brief Move npc using current strategy
		/// @param deltaTime Elapsed time between this frame and the last frame
		/// @return The next strategy to npc needs to use
		virtual MovementStrategy* processMovement(float deltaTime) override;

		/// @brief Clean up strategy
		virtual void exit() override;

	private:
		/// @brief The behavior Flee escapes too
		Wander* m_wander = nullptr;
		/// @brief The audio to play once the npc starts fleeing
		engine::components::AudioPlayer* m_fleeStart = nullptr;
		/// @brief The audio to play once the npc stops fleeing
		engine::components::AudioPlayer* m_fleeEnd = nullptr;
	};
}

#endif // GAM703_GAME_COMPONENTS_FLEE_HPP
