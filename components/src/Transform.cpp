#include <components/Transform.hpp>

namespace gam703::engine::components
{
	Transform::Transform(glm::vec3 position, glm::vec3 rotation, glm::vec3 scale) : m_position(position), m_rotation(rotation), m_scale(scale)
	{
	}
}
