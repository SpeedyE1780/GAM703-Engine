#ifndef GAM703_ENGINE_COMPONENTS_BEHAVIOR_HPP
#define GAM703_ENGINE_COMPONENTS_BEHAVIOR_HPP

#include <engine/components/Config.hpp>
#include <engine/components/Component.hpp>

namespace gam703::engine::components
{
	class ENGINE_COMPONENTS_API Behavior : public Component
	{
	public:
		Behavior(Transform* transform);

		virtual void tick(float deltaTime) = 0;
		virtual Behavior* clone(Transform* transform) const override = 0;
	};
}

#endif // GAM703_ENGINE_COMPONENTS_BEHAVIOR_HPP
