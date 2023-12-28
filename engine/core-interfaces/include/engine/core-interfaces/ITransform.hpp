#ifndef GAM703_ENGINE_CORE_INTERFACES_ITRANSFORM_HPP
#define GAM703_ENGINE_CORE_INTERFACES_ITRANSFORM_HPP

#include <engine/core-interfaces/Config.hpp>
#include <engine/core-interfaces/IComponent.hpp>
#include <engine/core-interfaces/IEngine.fwd.hpp>
#include <engine/core-interfaces/IScene.hpp>

#include <glm/glm.hpp>

#include <memory>
#include <vector>

namespace gam703::engine::core_interface
{
	class ENGINE_CORE_INTERFACES_API ITransform
	{
	public:
		ITransform(IEngine* engine, IScene* scene, const glm::vec3& position = glm::vec3(0.0f, 0.0f, 0.0f), const glm::vec3& rotation = glm::vec3(0.0f, 0.0f, 0.0f));
		ITransform(const ITransform& transform);
		ITransform& operator=(const ITransform& transform);
		virtual ~ITransform() = default;

		virtual ITransform* clone() const = 0;

		const glm::vec3& getPosition() const { return m_position; }
		const glm::vec3& getRotation() const { return m_rotation; }
		virtual const glm::vec3& getScale() const = 0;
		virtual const glm::mat4& getTransformationMatrix() const = 0;
		virtual const glm::mat3& getNormalMatrix() const = 0;
		virtual const glm::vec3& getFront() const = 0;
		virtual const glm::vec3& getRight() const = 0;
		virtual const glm::vec3& getUp() const = 0;

		virtual void calculateTransformMatrix() = 0;

		void updateComponents(float deltaTime);

		void setPosition(const glm::vec3& position);
		void setPosition(float x, float y, float z);
		void setRotation(const glm::vec3& eulerAngles);
		void setRotation(float x, float y, float z);
		virtual void setScale(const glm::vec3& scale) = 0;
		virtual void setScale(float x, float y, float z) = 0;

		virtual void translate(const glm::vec3& offset) = 0;
		virtual void translate(float x, float y, float z) = 0;
		virtual void rotate(const glm::vec3& eulerAngles) = 0;
		virtual void rotate(float x, float y, float z) = 0;

		IEngine* getEngine() { return m_engine; }
		const IEngine* getEngine() const { return m_engine; }

		IScene* getScene() { return m_scene; }
		const IScene* getScene() const { return m_scene; }

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
			auto _ = std::find_if(begin(m_components), end(m_components), [&returnValue](std::unique_ptr<core_interface::IComponent>& component) { return returnValue = dynamic_cast<Component*>(component.get()); });
			return returnValue;
		}

		template<typename Component>
		void removeComponent()
		{
			auto newEnd = std::remove_if(begin(m_components), end(m_components), [](std::unique_ptr<core_interface::IComponent>& component)
				{
					return dynamic_cast<Component*>(component.get());
				});

			m_components.erase(newEnd, end(m_components));
		}

		std::size_t getComponentsSize() const { return m_components.size(); }

	protected:
		glm::vec3 m_position{ 0.0f, 0.0f, 0.0f };
		glm::vec3 m_rotation{ 0.0f, 0.0f, 0.0f };
		bool m_shouldCalculateTransform = true;
		bool m_shouldUpdateDirectionVectors = true;

	private:
		std::vector<std::unique_ptr<IComponent>> m_components{};
		core_interface::IEngine* m_engine = nullptr;
		core_interface::IScene* m_scene = nullptr;
	};
}

#endif // GAM703_ENGINE_CORE_INTERFACES_ITRANSFORM_HPP
