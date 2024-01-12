#include <engine/utility/Math.hpp>

#include <game/components/PowerLevel.hpp>

#include <glm/gtx/compatibility.hpp>

namespace gam703::game::components
{
	namespace
	{
		constexpr float getGap(PowerLevel high, int low)
		{
			return static_cast<int>(high) - low;
		}

		constexpr float getGap(PowerLevel high, PowerLevel low)
		{
			return static_cast<int>(high) - static_cast<int>(low);
		}

		static const glm::vec3 weakest = glm::vec3(0.6f, 0.443f, 0.321f);
		static const glm::vec3 weaker = glm::vec3(0.203f, 0.662f, 0.349f);
		static const glm::vec3 weak = glm::vec3(0.968f, 0.674f, 0.364f);
		static const glm::vec3 normal = glm::vec3(1.0f, 0.905f, 0.580f);
		static const glm::vec3 strong = glm::vec3(0.172f, 0.725f, 0.776f);
		static const glm::vec3 stronger = glm::vec3(0.113f, 0.411f, 0.878f);
		static const glm::vec3 strongest = glm::vec3(0.968f, 0.372f, 0.364f);
	}

	int getPowerBetweenLevels(PowerLevel low, PowerLevel high)
	{
		return engine::utility::generateRandomNumber(static_cast<int>(low), static_cast<int>(high));
	}

	glm::vec3 getPowerColor(int power)
	{
		if (power < static_cast<int>(PowerLevel::Weakest))
		{
			return weakest;
		}
		else if (power < static_cast<int>(PowerLevel::Weaker))
		{
			return glm::lerp(weakest, weaker, getGap(PowerLevel::Weaker, power) / getGap(PowerLevel::Weaker, PowerLevel::Weakest));
		}
		else if (power < static_cast<int>(PowerLevel::Weak))
		{
			return glm::lerp(weaker, weak, getGap(PowerLevel::Weak, power) / getGap(PowerLevel::Weak, PowerLevel::Weaker));
		}
		else if (power < static_cast<int>(PowerLevel::Normal))
		{
			return glm::lerp(weak, normal, getGap(PowerLevel::Normal, power) / getGap(PowerLevel::Normal, PowerLevel::Weak));
		}
		else if (power < static_cast<int>(PowerLevel::Strong))
		{
			return glm::lerp(normal, strong, getGap(PowerLevel::Strong, power) / getGap(PowerLevel::Strong, PowerLevel::Normal));
		}
		else if (power < static_cast<int>(PowerLevel::Stronger))
		{
			return glm::lerp(strong, stronger, getGap(PowerLevel::Stronger, power) / getGap(PowerLevel::Stronger, PowerLevel::Strong));
		}
		else if (power < static_cast<int>(PowerLevel::Strongest))
		{
			return glm::lerp(stronger, strongest, getGap(PowerLevel::Strongest, power) / getGap(PowerLevel::Strongest, PowerLevel::Stronger));
		}
		else
		{
			return strongest;
		}
	}
}
