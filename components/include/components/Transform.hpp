#ifndef GAM703_ENGINE_COMPONENTS_TRANSFORM_HPP
#define GAM703_ENGINE_COMPONENTS_TRANSFORM_HPP

#include <core-interfaces/IEngine.hpp>
#include <components/Config.hpp>
#include <components/IComponent.hpp>
#include <glm/glm.hpp>

#include <memory>
#include <vector>

namespace gam703::engine::components
{
	class COMPONENTS_API Transform
	{
	public:
		Transform(const glm::vec3& position = glm::vec3(0, 0, 0), const glm::vec3& rotation = glm::vec3(0, 0, 0), const glm::vec3& scale = glm::vec3(1, 1, 1));
		~Transform() = default;
		Transform(const Transform& transform) = delete;
		Transform& operator=(const Transform& transform) = delete;

		const glm::vec3& getPosition() const { return m_position; }
		const glm::vec3& getRotation() const { return m_rotation; }
		const glm::vec3& getScale() const { return m_scale; }
		const glm::mat4& getTransformationMatrix() const { return m_transformMatrix; }
		const glm::vec3& getFront() const { return m_front; }
		const glm::vec3& getRight() const { return m_right; }
		const glm::vec3& getUp() const { return m_up; }

		void calculateTransformMatrix();

		void setPosition(const glm::vec3& position);
		void setPosition(float x, float y, float z);
		void setRotation(const glm::vec3& eulerAngles);
		void setRotation(float x, float y, float z);
		void setScale(const glm::vec3& scale);
		void setScale(float x, float y, float z);

		void translate(const glm::vec3& offset);
		void translate(float x, float y, float z);
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

		core_interface::IEngine* getEngine() { return m_engine; }
		const core_interface::IEngine* getEngine() const { return m_engine; }

		void setEngine(core_interface::IEngine* engine) { m_engine = engine; }

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
		std::vector<std::unique_ptr<IComponent>> m_components = {};
		core_interface::IEngine* m_engine = nullptr;
	};
}

#endif // GAM703_ENGINE_COMPONENTS_TRANSFORM_HPP
