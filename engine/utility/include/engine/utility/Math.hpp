#ifndef GAM703_ENGINE_UTILITY_MATH_HPP
#define GAM703_ENGINE_UTILITY_MATH_HPP

#include <engine/utility/Config.hpp>

#include <glm/glm.hpp>

namespace gam703::engine::utility
{
	/// @brief Get a vector move towards the target by a maximum distance
	/// @param current The current vector that's being moved
	/// @param target The target vector we want to reach
	/// @param maxDistance The maximum distance that can be moved
	/// @return The current vector moved by max distance or target if distance < maxDistance
	ENGINE_UTILITY_API glm::vec3 moveTowards(const glm::vec3& current, const glm::vec3& target, float maxDistance);

	/// @brief Clamps a value between a minimum and maximum value
	/// @param value Current value
	/// @param min Minimum Value
	/// @param max Maximum Value
	/// @return Clamped value
	ENGINE_UTILITY_API float clamp(float value, float min, float max);
}

#endif // GAM703_ENGINE_UTILITY_MATH_HPP
