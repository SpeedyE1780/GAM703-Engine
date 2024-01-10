#ifndef GAM703_GAME_COMPONENTS_MOVEMENT_STRATEGY_HPP
#define GAM703_GAME_COMPONENTS_MOVEMENT_STRATEGY_HPP

#include <engine/components/Transform.hpp>

#include <game/components/Config.hpp>

namespace gam703::game::components
{
	class GAME_COMPONENTS_API MovementStrategy
	{
	public:
		MovementStrategy(engine::components::Transform& transform);

		virtual void enter() = 0;
		virtual MovementStrategy* processMovement(float deltaTime) = 0;
		virtual void exit() = 0;

	protected:
		static constexpr float SeekDistance = 3.0f;
		static constexpr float BattleDistance = 0.25f;

		engine::components::Transform& m_transform;
	};
}

#endif // GAM703_GAME_COMPONENTS_MOVEMENT_STRATEGY_HPP
