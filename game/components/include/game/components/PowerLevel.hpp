#ifndef GAM703_GAME_COMPONENTS_POWER_COLOR_HPP
#define GAM703_GAME_COMPONENTS_POWER_COLOR_HPP

#include <game/components/Config.hpp>

#include <glm/glm.hpp>

namespace gam703::game::components
{
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

	GAME_COMPONENTS_API int getPowerBetweenLevels(PowerLevel low, PowerLevel high);

	GAME_COMPONENTS_API glm::vec3 getPowerColor(int power);
}

#endif // GAM703_GAME_COMPONENTS_POWER_COLOR_HPP
