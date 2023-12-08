#ifndef GAM703_ENGINE_COMPONENTS_TRANSFORM_HPP
#define GAM703_ENGINE_COMPONENTS_TRANSFORM_HPP

#include <components/Config.hpp>
#include <glm/glm.hpp>
#include <glm/gtc/quaternion.hpp>

namespace gam703::engine::components
{
	class COMPONENTS_API Transform
	{
	public:
		Transform(glm::vec3 position = glm::vec3(0, 0, 0), glm::vec3 rotation = glm::vec3(0, 0, 0), glm::vec3 scale = glm::vec3(1, 1, 1));

		glm::vec3 getPosition() const { return m_position; }
		glm::quat getRotation() const { return m_rotation; }
		glm::vec3 getScale() const { return m_scale; }

	private:
		glm::vec3 m_position;
		glm::quat m_rotation;
		glm::vec3 m_scale;
	};
}

#endif // GAM703_ENGINE_COMPONENTS_TRANSFORM_HPP
