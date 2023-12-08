#ifndef GAM703_ENGINE_COMPONENTS_TRANSFORM_HPP
#define GAM703_ENGINE_COMPONENTS_TRANSFORM_HPP

#include <components/Config.hpp>
#include <components/IComponent.hpp>
#include <glm/glm.hpp>
#include <glm/gtc/quaternion.hpp>

#include <memory>
#include <vector>

namespace gam703::engine::components
{
	class COMPONENTS_API Transform
	{
	public:
		Transform(glm::vec3 position = glm::vec3(0, 0, 0), glm::vec3 rotation = glm::vec3(0, 0, 0), glm::vec3 scale = glm::vec3(1, 1, 1));
		~Transform() = default;
		Transform(const Transform& transform) = delete;
		Transform& operator=(const Transform& transform) = delete;

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

		void translate(const glm::vec3& offset);
		void translate(float x, float y, float z);
		void rotate(const glm::quat& quaternion);
		void rotate(const glm::vec3& eulerAngles);
		void rotate(float x, float y, float z);

		template<typename Component, typename... Args>
		Component* addComponent(Args&&... args)
		{
			auto* component = new Component(this, std::forward<Args>(args)...);
			m_components.emplace_back(std::unique_ptr<Component>(component));
			return component;
		}

		template<typename Component>
		Component* getComponent()
		{
			Component* returnValue = nullptr;
			std::find_if(begin(m_components), end(m_components), [&returnValue](std::unique_ptr<IComponent>& component) { return returnValue = dynamic_cast<Component*>(component.get()); });
			return returnValue;
		}

		template<typename Component>
		void removeComponent()
		{
			auto newEnd = std::remove_if(begin(m_components), end(m_components), [](std::unique_ptr<IComponent>& component)
				{
					return dynamic_cast<Component*>(component.get());
				});

			m_components.erase(newEnd, end(m_components));
		}

		std::size_t getComponentsSize() const { return m_components.size(); }

	private:
		glm::vec3 m_position;
		glm::quat m_rotation;
		glm::vec3 m_scale;
		glm::mat4 m_transformMatrix;
		bool m_shouldCalculateTransform;
		std::vector<std::unique_ptr<IComponent>> m_components;
	};
}

#endif // GAM703_ENGINE_COMPONENTS_TRANSFORM_HPP
