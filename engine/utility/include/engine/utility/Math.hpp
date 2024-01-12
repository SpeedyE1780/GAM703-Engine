#ifndef GAM703_ENGINE_UTILITY_MATH_HPP
#define GAM703_ENGINE_UTILITY_MATH_HPP

#include <engine/utility/Config.hpp>

#include <glm/glm.hpp>

namespace gam703::engine::utility
{
	/// @brief Represent PI
	constexpr float PI = 3.14f;

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

	/// @brief Generate a random value between a minimum and maximum value
	/// @param minimum Minimum Value
	/// @param maximum Maximum Value
	/// @return Random value in range [minimum, maximum[
	ENGINE_UTILITY_API float generateRandomNumber(float minimum, float maximum);

	/// @brief Return a point in the rectangle
	/// @param center Center of the rectangle
	/// @param bounds Extents of the rectangle
	/// @return Point within rectangle bounds
	ENGINE_UTILITY_API glm::vec3 getPointInRectangle(const glm::vec3& center, const glm::vec2& bounds);

	/// @brief Check if point is inside bounding box on xz plane
	/// @param point The point to be checked
	/// @param origin The center of the xz bounding box
	/// @param bounds The extent of the xz bounding box
	/// @return True if point is inside bounding box
	ENGINE_UTILITY_API bool isWithinBounds(const glm::vec3& point, const glm::vec3& origin, const glm::vec2& bounds);

	/// @brief Return a point in a circle
	/// @param radius The circle radius
	/// @param center The center of the circle
	/// @param offset The minimum distance from the center
	/// @return Point in a circle
	ENGINE_UTILITY_API glm::vec3 getPointInCircle(float radius, const glm::vec3& center = glm::vec3(0.0f, 0.0f, 0.0f), float offset = 0.0f);
}

#endif // GAM703_ENGINE_UTILITY_MATH_HPP
