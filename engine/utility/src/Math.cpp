#include <engine/utility/Math.hpp>

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
}
