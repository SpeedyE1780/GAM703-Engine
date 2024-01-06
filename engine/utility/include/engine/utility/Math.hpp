#ifndef GAM703_ENGINE_UTILITY_MATH_HPP
#define GAM703_ENGINE_UTILITY_MATH_HPP

#include <engine/utility/Config.hpp>

#include <glm/glm.hpp>

namespace gam703::engine::utility
{
	ENGINE_UTILITY_API glm::vec3 moveTowards(const glm::vec3& current, const glm::vec3& target, float maxDistance);
	ENGINE_UTILITY_API float clamp(float value, float min, float max);
}

#endif // GAM703_ENGINE_UTILITY_MATH_HPP
