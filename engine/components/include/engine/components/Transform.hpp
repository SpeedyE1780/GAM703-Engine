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

		virtual const glm::vec3& getPosition() const override { return m_position; }
		virtual const glm::vec3& getRotation() const override { return m_rotation; }
		virtual const glm::vec3& getScale() const override { return m_scale; }
		virtual const glm::mat4& getTransformationMatrix() const override { return m_transformMatrix; }
		virtual const glm::vec3& getFront() const override { return m_front; }
		virtual const glm::vec3& getRight() const override { return m_right; }
		virtual const glm::vec3& getUp() const override { return m_up; }

		virtual void calculateTransformMatrix() override;

		virtual void setPosition(const glm::vec3& position) override;
		virtual void setPosition(float x, float y, float z) override;
		virtual void setRotation(const glm::vec3& eulerAngles) override;
		virtual void setRotation(float x, float y, float z) override;
		virtual void setScale(const glm::vec3& scale) override;
		virtual void setScale(float x, float y, float z) override;

		virtual void translate(const glm::vec3& offset) override;
		virtual void translate(float x, float y, float z) override;
		virtual void rotate(const glm::vec3& eulerAngles) override;
		virtual void rotate(float x, float y, float z) override;

	private:
		void updateDirectionVectors();

		glm::vec3 m_position;
		glm::vec3 m_rotation;
		glm::vec3 m_scale;
		glm::mat4 m_transformMatrix;
		glm::vec3 m_front = glm::vec3(0, 0, 0);
		glm::vec3 m_up = glm::vec3(0, 0, 0);
		glm::vec3 m_right = glm::vec3(0, 0, 0);
		bool m_shouldCalculateTransform;
		bool m_shouldUpdateDirectionVectors;
	};
}

#endif // GAM703_ENGINE_COMPONENTS_TRANSFORM_HPP
