#ifndef GAM703_GAME_COMPONENTS_MOVEMENT_CONTROLLER_HPP
#define GAM703_GAME_COMPONENTS_MOVEMENT_CONTROLLER_HPP

#include <engine/components/AudioPlayer.hpp>
#include <engine/components/Behavior.hpp>

#include <game/components/Config.hpp>

namespace gam703::game::components
{
	class GAME_COMPONENTS_API MovementController : public engine::components::Behavior
	{
	public:
		MovementController(engine::components::Transform& transform);

		virtual MovementController* clone(engine::components::Transform& transform) const override;

		virtual void tick(float deltaTime) override;

	private:
		engine::components::AudioPlayer* m_bell;
		float m_movementSpeed = 2.5f;
	};
}

#endif // GAM703_GAME_COMPONENTS_MOVEMENT_CONTROLLER_HPP
