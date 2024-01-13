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

		constexpr float getProgess(int power, PowerLevel low, PowerLevel high)
		{
			return 1 - getGap(high, power) / getGap(high, low);
		}

		static const glm::vec3 weakest = glm::vec3(0.168f, 0.00f, 0.00f);
		static const glm::vec3 weaker = glm::vec3(0.537f, 0.00f, 0.00f);
		static const glm::vec3 weak = glm::vec3(1.00f, 0.00f, 0.00f);
		static const glm::vec3 normal = glm::vec3(1.0f, 0.305f, 0.00f);
		static const glm::vec3 strong = glm::vec3(0.788f, 0.545, 0.00f);
		static const glm::vec3 stronger = glm::vec3(1.00f, 0.760f, 0.00f);
		static const glm::vec3 strongest = glm::vec3(1.00f, 0.988f, 0.572f);
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
			return glm::lerp(weakest, weaker, getProgess(power, PowerLevel::Weakest, PowerLevel::Weaker));
		}
		else if (power < static_cast<int>(PowerLevel::Weak))
		{
			return glm::lerp(weaker, weak, getProgess(power, PowerLevel::Weaker, PowerLevel::Weak));
		}
		else if (power < static_cast<int>(PowerLevel::Normal))
		{
			return glm::lerp(weak, normal, getProgess(power, PowerLevel::Weak, PowerLevel::Normal));
		}
		else if (power < static_cast<int>(PowerLevel::Strong))
		{
			return glm::lerp(normal, strong, getProgess(power, PowerLevel::Normal, PowerLevel::Strong));
		}
		else if (power < static_cast<int>(PowerLevel::Stronger))
		{
			return glm::lerp(strong, stronger, getProgess(power, PowerLevel::Strong, PowerLevel::Stronger));
		}
		else if (power < static_cast<int>(PowerLevel::Strongest))
		{
			return glm::lerp(stronger, strongest, getProgess(power, PowerLevel::Stronger, PowerLevel::Strongest));
		}
		else
		{
			return strongest;
		}
	}
}
