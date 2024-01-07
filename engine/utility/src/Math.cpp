#include <engine/utility/Math.hpp>

#include <random>

namespace gam703::engine::utility
{
	glm::vec3 moveTowards(const glm::vec3& current, const glm::vec3& target, float maxDistance)
	{
		glm::vec3 direction = target - current;

		if (glm::length(direction) > maxDistance)
		{
			return current + glm::normalize(direction) * maxDistance;
		}

		return current + direction;
	}

	float clamp(float value, float min, float max)
	{
		return glm::clamp(value, min, max);
	}

	float generateRandomNumber(float minimum, float maximum)
	{
		static std::default_random_engine engine;
		static std::uniform_real_distribution<> dis(0, 1);
		return dis(engine) * (maximum - minimum) + minimum;
	}
}
