#ifndef GAM703_GAME_COMPONENTS_MOVEMENT_CONTROLLER_HPP
#define GAM703_GAME_COMPONENTS_MOVEMENT_CONTROLLER_HPP

#include <engine/audio/AudioSource.hpp>

#include <engine/components/Behavior.hpp>

#include <game/components/Config.hpp>

namespace gam703::game::components
{
	class GAME_COMPONENTS_API MovementController : public engine::components::Behavior
	{
	public:
		MovementController(engine::components::Transform& transform);

		virtual MovementController* clone(engine::components::Transform& transform) const override;

		float getYaw() const { return m_yaw; }
		float getPitch() const { return m_pitch; }
		float getMovementSpeed() const { return m_movementSpeed; }
		float getMouseSensitivity() const { return m_mouseSensitivity; }

		virtual void tick(float deltaTime) override;

	private:
		engine::audio::AudioSource* m_bell;
		float m_yaw = 0.0f;
		float m_pitch = 0.0f;
		float m_movementSpeed = 2.5f;
		float m_mouseSensitivity = 0.1f;
	};
}

#endif // GAM703_GAME_COMPONENTS_MOVEMENT_CONTROLLER_HPP
