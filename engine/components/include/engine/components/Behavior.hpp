#ifndef GAM703_ENGINE_COMPONENTS_BEHAVIOR_HPP
#define GAM703_ENGINE_COMPONENTS_BEHAVIOR_HPP

#include <engine/components/Config.hpp>
#include <engine/components/Component.hpp>

namespace gam703::engine::components
{
	/// @brief Behavior is the Parent class of components that will be updated every frame
	class ENGINE_COMPONENTS_API Behavior : public Component
	{
	public:
		/// @brief Create a behavior that is owned by the transform
		/// @param transform The Transform owning this behavior
		Behavior(Transform& transform);
		virtual ~Behavior() = default;

		/// @brief Update the behavior every frame
		/// @param deltaTime Elapsed time between this frame and the last frame
		virtual void tick(float deltaTime) = 0;

		/// @brief Create a copy attached to the new transform
		/// @param transform The new transform that will own the clone
		/// @return The cloned Behavior belonging to the transform
		virtual Behavior* clone(Transform& transform) const override = 0;
	};
}

#endif // GAM703_ENGINE_COMPONENTS_BEHAVIOR_HPP
