#ifndef GAM703_ENGINE_CORE_INTERFACES_BEHAVIOR_HPP
#define GAM703_ENGINE_CORE_INTERFACES_BEHAVIOR_HPP

#include <engine/core-interfaces/Config.hpp>
#include <engine/core-interfaces/Component.hpp>

namespace gam703::engine::core_interface
{
	class ENGINE_CORE_INTERFACES_API Behavior : public Component
	{
	public:
		Behavior(Transform* transform);

		virtual void tick(float deltaTime) = 0;
		virtual Behavior* clone(Transform* transform) const override = 0;
	};
}

#endif // GAM703_ENGINE_CORE_INTERFACES_BEHAVIOR_HPP
