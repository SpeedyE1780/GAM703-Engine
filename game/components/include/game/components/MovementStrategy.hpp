#ifndef GAM703_GAME_COMPONENTS_MOVEMENT_STRATEGY_HPP
#define GAM703_GAME_COMPONENTS_MOVEMENT_STRATEGY_HPP

#include <engine/components/AudioPlayer.hpp>
#include <engine/components/Transform.hpp>

#include <game/components/Config.hpp>

namespace gam703::game::components
{
	/// @brief MovementStrategy is a strategy pattern to move NPC
	class GAME_COMPONENTS_API MovementStrategy
	{
	public:
		/// @brief Create a movement strategy to move NPC
		/// @param transform The transform owning this behavior
		/// @param player The player the npc needs to follow
		/// @param origin The origin of the npc area
		/// @param bounds The bounds of the npc area
		/// @param aiPower The power level of the npc
		MovementStrategy(engine::components::Transform& transform, engine::components::TransformReference player, const glm::vec3& origin, const glm::vec2& bounds, int& aiPower);

		/// @brief Setup strategy
		virtual void enter() = 0;

		/// @brief Move npc using current strategy
		/// @param deltaTime Elapsed time between this frame and the last frame
		/// @return The next strategy to npc needs to use
		virtual MovementStrategy* processMovement(float deltaTime) = 0;

		/// @brief Clean up strategy
		virtual void exit() = 0;

		/// @brief Set battle start audio
		/// @param battleStart Battle start audio
		void setBattleStart(engine::components::AudioPlayer* battleStart) { m_battleStart = battleStart; }

	protected:
		/// @brief The distance where NPC stop Seeking/Fleeing
		static constexpr float SeekDistance = 3.0f;
		/// @brief The distance where the battle starts
		static constexpr float BattleDistance = 0.25f;

		/// @brief The transform that owns this component
		engine::components::Transform& m_transform;
		/// @brief The player the npc needs to follow
		engine::components::TransformReference m_player;
		/// @brief The origin of the npc area
		const glm::vec3& m_origin;
		/// @brief The bounds of the npc area
		const glm::vec2& m_bounds;
		/// @brief The power level of the npc
		const int& m_aiPower;
		/// @brief The audio to play once a battle starts
		engine::components::AudioPlayer* m_battleStart = nullptr;
	};
}

#endif // GAM703_GAME_COMPONENTS_MOVEMENT_STRATEGY_HPP
