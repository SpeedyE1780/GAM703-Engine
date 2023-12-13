#ifndef GAM703_ENGINE_CORE_INTERFACES_ITRANSFORM_HPP
#define GAM703_ENGINE_CORE_INTERFACES_ITRANSFORM_HPP

#include <core-interfaces/Config.hpp>
#include <core-interfaces/IScene.hpp>
#include <core-interfaces/IComponent.hpp>

#include <glm/glm.hpp>

#include <vector>
#include <memory>

namespace gam703::engine::core_interface
{
	class CORE_INTERFACES_API ITransform
	{
	public:
		ITransform(IEngine* engine, IScene* scene);
		ITransform(const ITransform& transform);
		ITransform& operator=(const ITransform& transform);
		virtual ~ITransform() = default;

		virtual ITransform* clone() const = 0;

		virtual const glm::vec3& getPosition() const = 0;
		virtual const glm::vec3& getRotation() const = 0;
		virtual const glm::vec3& getScale() const = 0;
		virtual const glm::mat4& getTransformationMatrix() const = 0;
		virtual const glm::vec3& getFront() const = 0;
		virtual const glm::vec3& getRight() const = 0;
		virtual const glm::vec3& getUp() const = 0;

		virtual void calculateTransformMatrix() = 0;

		void updateComponents(float deltaTime);

		virtual void setPosition(const glm::vec3& position) = 0;
		virtual void setPosition(float x, float y, float z) = 0;
		virtual void setRotation(const glm::vec3& eulerAngles) = 0;
		virtual void setRotation(float x, float y, float z) = 0;
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

	private:
		std::vector<std::unique_ptr<IComponent>> m_components = {};
		core_interface::IEngine* m_engine = nullptr;
		core_interface::IScene* m_scene = nullptr;
	};
}

#endif // GAM703_ENGINE_CORE_INTERFACES_ITRANSFORM_HPP
