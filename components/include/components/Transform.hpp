#ifndef GAM703_ENGINE_COMPONENTS_TRANSFORM_HPP
#define GAM703_ENGINE_COMPONENTS_TRANSFORM_HPP

#include <core-interfaces/IEngine.hpp>
#include <core-interfaces/IScene.hpp>
#include <core-interfaces/ITransform.hpp>

#include <components/Config.hpp>
#include <components/IComponent.hpp>

#include <glm/glm.hpp>

#include <memory>
#include <vector>

namespace gam703::engine::components
{
	class COMPONENTS_API Transform : public core_interface::ITransform
	{
	public:
		Transform(core_interface::IEngine* engine, const glm::vec3& position = glm::vec3(0, 0, 0), const glm::vec3& rotation = glm::vec3(0, 0, 0), const glm::vec3& scale = glm::vec3(1, 1, 1));
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
			auto _ = std::find_if(begin(m_components), end(m_components), [&returnValue](std::unique_ptr<IComponent>& component) { return returnValue = dynamic_cast<Component*>(component.get()); });
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

		void updateComponents(float deltaTime);

		virtual core_interface::IEngine* getEngine() override { return m_engine; }
		virtual const core_interface::IEngine* getEngine() const override { return m_engine; }

		virtual core_interface::IScene* getScene() override { return m_scene; }
		virtual const core_interface::IScene* getScene() const override { return m_scene; }

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
		core_interface::IScene* m_scene = nullptr;
	};
}

#endif // GAM703_ENGINE_COMPONENTS_TRANSFORM_HPP
