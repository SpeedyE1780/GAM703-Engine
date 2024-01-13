#ifndef GAM703_GAME_COMPONENTS_SEEK_HPP
#define GAM703_GAME_COMPONENTS_SEEK_HPP

#include <engine/components/AudioPlayer.hpp>

#include <game/components/Config.hpp>
#include <game/components/MovementStrategy.hpp>

namespace gam703::game::components
{
	class Wander;

	/// @brief Seek npc will move towards from player
	class GAME_COMPONENTS_API Seek : public MovementStrategy
	{
	public:
		/// @brief Create a Seek strategy to move towards player
		/// @param transform The transform owning this component
		/// @param player The player the npc needs to follow
		/// @param wander The wander strategy the npc exits too
		/// @param origin The origin of the npc area
		/// @param bounds The bounds of the npc area
		/// @param aiPower The power level of the npc
		Seek(engine::components::Transform& transform, const engine::components::TransformReference& player, Wander* wander, const glm::vec3& origin, const glm::vec2& bounds, int& aiPower);

		/// @brief Setup strategy
		virtual void enter() override;

		/// @brief Move npc using current strategy
		/// @param deltaTime Elapsed time between this frame and the last frame
		/// @return The next strategy to npc needs to use
		virtual MovementStrategy* processMovement(float deltaTime) override;

		/// @brief Clean up strategy
		virtual void exit() override;

	private:
		/// @brief The behavior Seek escapes too
		Wander* m_wander = nullptr;
		/// @brief The audio to play once the npc starts seeking
		engine::components::AudioPlayer* m_alert = nullptr;
		/// @brief The audio to play once the npc stops seeking
		engine::components::AudioPlayer* m_deactivate = nullptr;
	};
}

#endif // GAM703_GAME_COMPONENTS_SEEK_HPP
