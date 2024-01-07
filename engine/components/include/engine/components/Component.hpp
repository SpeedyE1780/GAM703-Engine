#ifndef GAM703_ENGINE_COMPONENTS_COMPONENT_HPP
#define GAM703_ENGINE_COMPONENTS_COMPONENT_HPP

#include <engine/components/Config.hpp>
#include <engine/components/Transform.fwd.hpp>

#include <engine/core/Engine.fwd.hpp>

#include <engine/core/Scene.fwd.hpp>

namespace gam703::engine::components
{
	/// @brief Component is the base class of all components that can be attached to scene objects
	class ENGINE_COMPONENTS_API Component
	{
	public:
		/// @brief Create a component that is owned by the transform
		/// @param transform The Transform owning this component
		Component(Transform& transform);
		virtual ~Component() = default;

		/// @brief Create a copy attached to the new transform
		/// @param transform The new transform that will own the clone
		/// @return The cloned Component belonging to the transform
		virtual Component* clone(Transform& transform) const = 0;

		/// @brief Get the component transform
		/// @return The Transform owning this component
		Transform& getTransform() { return m_transform; }

		/// @brief Get the component transform
		/// @return The Transform owning this component
		const Transform& getTransform() const { return m_transform; }

		/// @brief Get the engine running the game
		/// @return The engine running the game
		core::Engine& getEngine();

		/// @brief Get the engine running the game
		/// @return The engine running the game
		const core::Engine& getEngine() const;

		/// @brief Get the game scene
		/// @return The scene containning all active objects
		core::Scene& getScene();

		/// @brief Get the game scene
		/// @return The scene containning all active objects
		const core::Scene& getScene() const;

	protected:
		/// @brief The transform that owns this component
		Transform& m_transform;
	};
}

#endif // GAM703_ENGINE_COMPONENTS_COMPONENT_HPP
