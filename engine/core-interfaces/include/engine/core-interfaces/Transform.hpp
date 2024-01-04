#ifndef GAM703_ENGINE_CORE_INTERFACES_TRANSFORM_HPP
#define GAM703_ENGINE_CORE_INTERFACES_TRANSFORM_HPP

#include <engine/core-interfaces/Config.hpp>
#include <engine/core-interfaces/Component.hpp>
#include <engine/core-interfaces/IEngine.fwd.hpp>
#include <engine/core-interfaces/IScene.hpp>

#include <glm/glm.hpp>

#include <memory>
#include <vector>

namespace gam703::engine::core_interface
{
	class ENGINE_CORE_INTERFACES_API Transform
	{
	public:
		Transform(IEngine* engine, IScene* scene,
			const glm::vec3& position = glm::vec3(0.0f, 0.0f, 0.0f),
			const glm::vec3& rotation = glm::vec3(0.0f, 0.0f, 0.0f),
			const glm::vec3& scale = glm::vec3(1.0f, 1.0f, 1.0f));

		Transform(const Transform& transform);
		Transform& operator=(const Transform& transform);
		virtual ~Transform() = default;

		Transform* clone() const;

		const glm::vec3& getPosition() const { return m_position; }
		const glm::vec3& getRotation() const { return m_rotation; }
		const glm::vec3& getScale() const { return m_scale; }
		const glm::mat4& getTransformationMatrix() const { return m_transformMatrix; }
		const glm::mat3& getNormalMatrix() const { return m_normalMatrix; }
		const glm::vec3& getFront() const { return m_front; }
		const glm::vec3& getRight() const { return m_right; }
		const glm::vec3& getUp() const { return m_up; }

		void calculateTransformMatrix();

		void updateComponents(float deltaTime);

		void setPosition(const glm::vec3& position);
		void setPosition(float x, float y, float z);
		void setRotation(const glm::vec3& eulerAngles);
		void setRotation(float x, float y, float z);
		void setScale(const glm::vec3& scale);
		void setScale(float x, float y, float z);

		void translate(const glm::vec3& offset);
		void translate(float x, float y, float z);
		void rotate(const glm::vec3& eulerAngles) ;
		void rotate(float x, float y, float z);

		IEngine* getEngine() { return m_engine; }
		const IEngine* getEngine() const { return m_engine; }

		IScene* getScene() { return m_scene; }
		const IScene* getScene() const { return m_scene; }

		template<typename ComponentType, typename... Args>
		ComponentType* addComponent(Args&&... args)
		{
			auto* component = new ComponentType(this, std::forward<Args>(args)...);
			m_components.emplace_back(std::unique_ptr<ComponentType>(component));
			return component;
		}

		template<typename ComponentType>
		ComponentType* getComponent()
		{
			ComponentType* returnValue = nullptr;
			auto _ = std::find_if(begin(m_components), end(m_components), [&returnValue](std::unique_ptr<Component>& component) { return returnValue = dynamic_cast<ComponentType*>(component.get()); });
			return returnValue;
		}

		template<typename ComponentType>
		void removeComponent()
		{
			auto newEnd = std::remove_if(begin(m_components), end(m_components), [](std::unique_ptr<Component>& component)
				{
					return dynamic_cast<ComponentType*>(component.get());
				});

			m_components.erase(newEnd, end(m_components));
		}

		std::size_t getComponentsSize() const { return m_components.size(); }

	private:
		void updateDirectionVectors();

		IEngine* m_engine = nullptr;
		IScene* m_scene = nullptr;
		glm::vec3 m_position{ 0.0f, 0.0f, 0.0f };
		glm::vec3 m_rotation{ 0.0f, 0.0f, 0.0f };
		glm::vec3 m_scale{ 1.0f, 1.0f, 1.0f };
		glm::vec3 m_front = glm::vec3(0, 0, 0);
		glm::vec3 m_up = glm::vec3(0, 0, 0);
		glm::vec3 m_right = glm::vec3(0, 0, 0);
		glm::mat4 m_transformMatrix = glm::mat4(1);
		glm::mat3 m_normalMatrix = glm::mat3(1);
		bool m_shouldCalculateTransform = true;
		bool m_shouldUpdateDirectionVectors = true;
		std::vector<std::unique_ptr<Component>> m_components{};
	};
}

#endif // GAM703_ENGINE_CORE_INTERFACES_TRANSFORM_HPP
