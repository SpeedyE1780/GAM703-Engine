#ifndef GAM703_ENGINE_COMPONENTS_TRANSFORM_HPP
#define GAM703_ENGINE_COMPONENTS_TRANSFORM_HPP

#include <engine/components/Behavior.hpp>
#include <engine/components/Config.hpp>
#include <engine/components/Component.hpp>

#include <engine/core/Engine.fwd.hpp>
#include <engine/core/Scene.hpp>

#include <engine/utility/ObjectReference.hpp>
#include <engine/utility/ReferencedObject.hpp>

#include <glm/glm.hpp>

#include <memory>
#include <type_traits>
#include <vector>

namespace gam703::engine::components
{
	using TransformReference = utility::ObjectReference<Transform>;

	/// @brief Transform contains all the information and components of scene objects
	class ENGINE_COMPONENTS_API Transform : public utility::ReferencedObject<Transform>
	{
	public:
		/// @brief Create a new Transform
		/// @param engine The engine running the game
		/// @param position The transform position
		/// @param rotation The transform rotation
		/// @param scale The transform scale
		Transform(core::Engine& engine,
			const glm::vec3& position = glm::vec3(0.0f, 0.0f, 0.0f),
			const glm::vec3& rotation = glm::vec3(0.0f, 0.0f, 0.0f),
			const glm::vec3& scale = glm::vec3(1.0f, 1.0f, 1.0f));

		/// @brief Creates a clone based on the transform given
		/// @param transform The transform being cloned
		Transform(const Transform& transform);
		Transform& operator=(const Transform& transform) = delete;
		~Transform() = default;

		/// @brief Create a clone in with the same 3D properties and clones all the components of this transform
		/// @return A new transform identical to this one
		Transform* clone() const;

		/// @brief Get the 3D position
		/// @return The 3D position
		const glm::vec3& getPosition() const { return m_position; }

		/// @brief Get the 3D rotation euler angles
		/// @return The 3D rotation euler angles
		const glm::vec3& getRotation() const { return m_rotation; }

		/// @brief Get the 3D scale
		/// @return The 3D scale
		const glm::vec3& getScale() const { return m_scale; }

		/// @brief Get the transformation matrix used in the vertex shader
		/// @return The transformation matrix used in the vertex shader
		const glm::mat4& getTransformationMatrix() const { return m_transformMatrix; }

		/// @brief Get the normal matrix used in the vertex shader
		/// @return The normal matrix used in the vertex shader
		const glm::mat3& getNormalMatrix() const { return m_normalMatrix; }

		/// @brief Get the front facing vector
		/// @return The front facing vector
		const glm::vec3& getFront() const { return m_front; }

		/// @brief Get the right facing vector
		/// @return The right facing vector
		const glm::vec3& getRight() const { return m_right; }

		/// @brief Get the up facing vector
		/// @return The up facing vector
		const glm::vec3& getUp() const { return m_up; }

		/// @brief Calculate the transform matrix used in the vertex shader
		void calculateTransformMatrix();

		/// @brief Update all behaviors on this transform
		/// @param deltaTime Elapsed time between this frame and the last frame
		void updateBehaviors(float deltaTime);

		/// @brief Set the 3D position
		/// @param position The new 3D position
		void setPosition(const glm::vec3& position);

		/// @brief Set the 3D position
		/// @param x The x component of the new position
		/// @param y The y component of the new position
		/// @param z The z component of the new position
		void setPosition(float x, float y, float z);

		/// @brief Set the 3D rotation euler angles
		/// @param eulerAngles The 3D rotation's euler angles
		void setRotation(const glm::vec3& eulerAngles);

		/// @brief Set the 3D rotation euler angles
		/// @param x The pitch rotation
		/// @param y The yaw rotation
		/// @param z The roll rotation
		void setRotation(float x, float y, float z);

		/// @brief Set the 3D scale
		/// @param scale The new 3D scale
		void setScale(const glm::vec3& scale);

		/// @brief Set the 3D scale
		/// @param x The x component of the new scale
		/// @param y The y component of the new scale
		/// @param z The z component of the new scale
		void setScale(float x, float y, float z);

		/// @brief Translate the transform by an offset
		/// @param offset The offset added to the position
		void translate(const glm::vec3& offset);

		/// @brief Translate the transform by an offset
		/// @param x The x component of the offset added to the position
		/// @param y The y component of the offset added to the position
		/// @param z The z component of the offset added to the position
		void translate(float x, float y, float z);

		/// @brief Rotate the transform by the given euler angles
		/// @param eulerAngles The euler angles addded to the transform rotation
		void rotate(const glm::vec3& eulerAngles) ;

		/// @brief Rotate the transform by the given euler angles
		/// @param x The x pitch added to the rotation
		/// @param y The y yaw added to the rotation
		/// @param z The z roll added to the rotation
		void rotate(float x, float y, float z);

		/// @brief Get the engine running the game
		/// @return The engine running the game
		core::Engine& getEngine() { return m_engine; }

		/// @brief Get the engine running the game
		/// @return The engine running the game
		const core::Engine& getEngine() const { return m_engine; }

		/// @brief Get the game scene
		/// @return The scene containning all active objects
		core::Scene& getScene();

		/// @brief Get the game scene
		/// @return The scene containning all active objects
		const core::Scene& getScene() const;

		/// @brief Add a component to the transform
		/// @tparam ComponentType The type of the new component
		/// @tparam ...Args Expands to ComponentType constructor's argument
		/// @param ...args All the argument needed to construct the ComponentType
		/// @return The newly added component
		template<typename ComponentType, typename... Args>
		ComponentType* addComponent(Args&&... args)
		{
			static_assert(std::is_base_of_v<Behavior, ComponentType> == false, "ComponentType is a Behavior, use addBehavior instead");
			auto* component = new ComponentType(*this, std::forward<Args>(args)...);
			m_components.emplace_back(std::unique_ptr<ComponentType>(component));
			return component;
		}

		/// @brief Get a component from the transform
		/// @tparam ComponentType The component to return
		/// @return The attached component if found else nullptr
		template<typename ComponentType>
		ComponentType* getComponent()
		{
			static_assert(std::is_base_of_v<Behavior, ComponentType> == false, "ComponentType is a Behavior, use getBehavior instead");
			ComponentType* returnValue = nullptr;
			auto _ = std::find_if(begin(m_components), end(m_components), [&returnValue](std::unique_ptr<Component>& component) { return returnValue = dynamic_cast<ComponentType*>(component.get()); });
			return returnValue;
		}

		/// @brief Remove the component type from the transform if found
		/// @tparam ComponentType The component to remove
		template<typename ComponentType>
		void removeComponent()
		{
			static_assert(std::is_base_of_v<Behavior, ComponentType> == false, "ComponentType is a Behavior, use removeBehavior instead");
			auto newEnd = std::remove_if(begin(m_components), end(m_components), [](std::unique_ptr<Component>& component)
				{
					return dynamic_cast<ComponentType*>(component.get());
				});

			m_components.erase(newEnd, end(m_components));
		}

		/// @brief Add a behavior to the transform
		/// @tparam BehaviorType The type of the new behavior
		/// @tparam ...Args Expands to BehaviorType constructor's argument
		/// @param ...args All the argument needed to construct the BehaviorType
		/// @return The newly added behavior
		template<typename BehaviorType, typename... Args>
		BehaviorType* addBehavior(Args&&... args)
		{
			static_assert(std::derived_from<BehaviorType, Behavior>, "BehaviorType is a Component, use addComponent instead");
			auto* behavior = new BehaviorType(*this, std::forward<Args>(args)...);
			m_behaviors.emplace_back(std::unique_ptr<BehaviorType>(behavior));
			return behavior;
		}

		/// @brief Get a behavior from the transform
		/// @tparam BehaviorType The behavior to return
		/// @return The attached behavior if found else nullptr
		template<typename BehaviorType>
		BehaviorType* getBehavior()
		{
			static_assert(std::derived_from<BehaviorType, Behavior>, "BehaviorType is a Component, use getComponent instead");
			BehaviorType* returnValue = nullptr;
			auto _ = std::find_if(begin(m_behaviors), end(m_behaviors), [&returnValue](std::unique_ptr<Behavior>& behavior) { return returnValue = dynamic_cast<BehaviorType*>(behavior.get()); });
			return returnValue;
		}

		/// @brief Remove the behavior type from the transform if found
		/// @tparam BehaviorType The behavior to remove
		template<typename BehaviorType>
		void removeBehavior()
		{
			static_assert(std::derived_from<BehaviorType, Behavior>, "BehaviorType is a Component, use removeComponent instead");
			auto newEnd = std::remove_if(begin(m_behaviors), end(m_behaviors), [](std::unique_ptr<Behavior>& behavior)
				{
					return dynamic_cast<BehaviorType*>(behavior.get());
				});

			m_behaviors.erase(newEnd, end(m_behaviors));
		}

		/// @brief Get the number of components attached
		/// @return The number of components attached
		std::size_t getComponentsSize() const { return m_components.size(); }

		/// @brief Get the number of behaviors attached
		/// @return The number of behaviors attached
		std::size_t getBehaviorsSize() const { return m_behaviors.size(); }

	private:
		/// @brief Update the direction vectors after a rotation
		void updateDirectionVectors();

		/// @brief The engine running the game
		core::Engine& m_engine;
		/// @brief The transform position
		glm::vec3 m_position{ 0.0f, 0.0f, 0.0f };
		/// @brief The transform rotation
		glm::vec3 m_rotation{ 0.0f, 0.0f, 0.0f };
		/// @brief The transform scale
		glm::vec3 m_scale{ 1.0f, 1.0f, 1.0f };
		/// @brief The front facing vector
		glm::vec3 m_front = glm::vec3(0, 0, 0);
		/// @brief The up facing vector
		glm::vec3 m_up = glm::vec3(0, 0, 0);
		/// @brief The right facing vector
		glm::vec3 m_right = glm::vec3(0, 0, 0);
		/// @brief The transformation matrix used in the vertex shader
		glm::mat4 m_transformMatrix = glm::mat4(1);
		/// @brief The normal matrix used in the vertex shader
		glm::mat3 m_normalMatrix = glm::mat3(1);
		/// @brief Check if transformation matrix needs to be calculated again
		bool m_shouldCalculateTransform = true;
		/// @brief Check if direction vectors need to be calculated again
		bool m_shouldUpdateDirectionVectors = true;
		/// @brief List of all attached components
		std::vector<std::unique_ptr<Component>> m_components{};
		/// @brief List of all attached behaviors
		std::vector<std::unique_ptr<Behavior>> m_behaviors{};
	};
}

#endif // GAM703_ENGINE_COMPONENTS_TRANSFORM_HPP
