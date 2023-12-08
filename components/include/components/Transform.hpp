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

		const glm::vec3& getPosition() const { return m_position; }
		const glm::quat& getRotation() const { return m_rotation; }
		const glm::vec3& getScale() const { return m_scale; }
		const glm::mat4& getTransformationMatrix() const { return m_transformMatrix; }

		void calculateTransformMatrix();

		void setPosition(const glm::vec3& position);
		void setPosition(float x, float y, float z);
		void setRotation(const glm::quat& rotation);
		void setRotation(const glm::vec3& eulerAngles);
		void setRotation(float x, float y, float z);
		void setScale(const glm::vec3& scale);
		void setScale(float x, float y, float z);

	private:
		glm::vec3 m_position;
		glm::quat m_rotation;
		glm::vec3 m_scale;
		glm::mat4 m_transformMatrix;
		bool m_shouldCalculateTransform;
	};
}

#endif // GAM703_ENGINE_COMPONENTS_TRANSFORM_HPP
