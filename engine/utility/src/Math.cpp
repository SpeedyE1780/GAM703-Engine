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

	glm::vec3 getPointInRectangle(const glm::vec3& center, const glm::vec2& bounds)
	{
		return center + glm::vec3(generateRandomNumber(-bounds.x, bounds.x), 0.0f, generateRandomNumber(-bounds.y, bounds.y));
	}

	bool isWithinBounds(const glm::vec3& point, const glm::vec3& origin, const glm::vec2& bounds)
	{
		bool withinLeft = point.x > origin.x - bounds.x;
		bool withinRight = point.x < origin.x + bounds.x;
		bool withinTop = point.z < origin.z + bounds.y;
		bool withinBottom = point.z > origin.z - bounds.y;

		return withinLeft && withinRight && withinTop && withinBottom;
	}
}
