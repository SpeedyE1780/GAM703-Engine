#ifndef GAM703_GAME_COMPONENTS_MOVEMENT_STRATEGY_HPP
#define GAM703_GAME_COMPONENTS_MOVEMENT_STRATEGY_HPP

#include <engine/components/Component.hpp>

#include <game/components/Config.hpp>

namespace gam703::game::components
{
	class GAME_COMPONENTS_API MovementStrategy : public engine::components::Component
	{
	public:
		MovementStrategy(engine::components::Transform& transform);

		virtual void enter() = 0;
		virtual MovementStrategy* processMovement(float deltaTime) = 0;
		virtual void exit() = 0;
	};
}

#endif // GAM703_GAME_COMPONENTS_MOVEMENT_STRATEGY_HPP
