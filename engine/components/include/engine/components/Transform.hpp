#ifndef GAM703_ENGINE_COMPONENTS_TRANSFORM_HPP
#define GAM703_ENGINE_COMPONENTS_TRANSFORM_HPP

#include <engine/components/Config.hpp>

#include <engine/core-interfaces/IComponent.hpp>
#include <engine/core-interfaces/IEngine.hpp>
#include <engine/core-interfaces/IScene.hpp>
#include <engine/core-interfaces/ITransform.hpp>

#include <glm/glm.hpp>

#include <memory>
#include <vector>

namespace gam703::engine::components
{
	class ENGINE_COMPONENTS_API Transform : public core_interface::ITransform
	{
	public:
		Transform(core_interface::IEngine* engine, core_interface::IScene* scene, const glm::vec3& position = glm::vec3(0, 0, 0), const glm::vec3& rotation = glm::vec3(0, 0, 0), const glm::vec3& scale = glm::vec3(1, 1, 1));
		~Transform() = default;
		Transform(const Transform& transform);
		Transform& operator=(const Transform& transform);

		virtual core_interface::ITransform* clone() const override;

		virtual const glm::mat4& getTransformationMatrix() const override { return m_transformMatrix; }
		virtual const glm::mat3& getNormalMatrix() const override { return m_normalMatrix; }
		virtual const glm::vec3& getFront() const override { return m_front; }
		virtual const glm::vec3& getRight() const override { return m_right; }
		virtual const glm::vec3& getUp() const override { return m_up; }

		virtual void calculateTransformMatrix() override;

		virtual void translate(const glm::vec3& offset) override;
		virtual void translate(float x, float y, float z) override;
		virtual void rotate(const glm::vec3& eulerAngles) override;
		virtual void rotate(float x, float y, float z) override;

	private:
		void updateDirectionVectors();

		glm::mat4 m_transformMatrix = glm::mat4(1);
		glm::mat3 m_normalMatrix = glm::mat3(1);
		glm::vec3 m_front = glm::vec3(0, 0, 0);
		glm::vec3 m_up = glm::vec3(0, 0, 0);
		glm::vec3 m_right = glm::vec3(0, 0, 0);
	};
}

#endif // GAM703_ENGINE_COMPONENTS_TRANSFORM_HPP
