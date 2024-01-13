#ifndef GAM703_GAME_COMPONENTS_SPAWNER_HPP
#define GAM703_GAME_COMPONENTS_SPAWNER_HPP

#include <engine/components/Component.hpp>

#include <game/components/Config.hpp>
#include <game/components/PowerLevel.hpp>

namespace gam703::game::components
{
	/// @brief Spawner spawns npc in an area
	class GAME_COMPONENTS_API Spawner : public engine::components::Component
	{
	public:
		/// @brief Creates a Spawner to spawn npc
		/// @param transform The transform owning this component
		/// @param player The player the npc needs to follow
		/// @param count The count of npc to spawn
		/// @param radius The max distance from the transform position to spawn enemy
		/// @param low Lowest npc power level
		/// @param high Highest npc power level
		Spawner(engine::components::Transform& transform, engine::components::Transform* player, int count, float radius, PowerLevel low, PowerLevel high);

		/// @brief Create a copy attached to the new transform
		/// @param transform The new transform that will own the clone
		/// @return The cloned Spawner belonging to the transform
		virtual Spawner* clone(engine::components::Transform& transform) const override;

	private:
		/// @brief The player the npc needs to follow
		engine::components::Transform* m_player;
		/// @brief The count of npc to spawn
		const int m_count;
		/// @brief The max distance from the transform position to spawn enemy
		const float m_radius;
		/// @brief Lowest npc power level
		const PowerLevel m_lowPowerLevel;
		/// @brief Highest npc power level
		const PowerLevel m_highPowerLevel;
	};
}

#endif // GAM703_GAME_COMPONENTS_SPAWNER_HPP
