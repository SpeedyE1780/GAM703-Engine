#ifndef GAM703_GAME_COMPONENTS_POWER_COLOR_HPP
#define GAM703_GAME_COMPONENTS_POWER_COLOR_HPP

#include <game/components/Config.hpp>

#include <glm/glm.hpp>

namespace gam703::game::components
{
	/// @brief Different Power Levels
	enum class PowerLevel : int
	{
		Weakest = 0,
		Weaker = 4,
		Weak = 9,
		Normal = 15,
		Strong = 20,
		Stronger = 28,
		Strongest = 40
	};

	/// @brief Get a power value between low and high
	/// @param low Lower Power
	/// @param high Higher Power
	/// @return A power value between low and high
	GAME_COMPONENTS_API int getPowerBetweenLevels(PowerLevel low, PowerLevel high);

	/// @brief Get a color between the lower and higher power level
	/// @param power The power level of the player/npc
	/// @return A color between the lower and higher power level
	GAME_COMPONENTS_API glm::vec3 getPowerColor(int power);
}

#endif // GAM703_GAME_COMPONENTS_POWER_COLOR_HPP
