#ifndef GAM703_GAME_COMPONENTS_MOVEMENT_CONTROLLER_HPP
#define GAM703_GAME_COMPONENTS_MOVEMENT_CONTROLLER_HPP

#include <engine/core-interfaces/ICamera.hpp>

#include <components/Config2.hpp>

namespace gam703::game::components
{
	class GAME_COMPONENTS_API MovementController : public engine::core_interface::IComponent
	{
	public:
		MovementController(engine::core_interface::ITransform* transform);

		virtual engine::core_interface::IComponent* clone(engine::core_interface::ITransform* transform) const override;

		float getYaw() const { return m_yaw; }
		float getPitch() const { return m_pitch; }
		float getMovementSpeed() const { return m_movementSpeed; }
		float getMouseSensitivity() const { return m_mouseSensitivity; }

		virtual void tick(float deltaTime) override;

	private:
		float m_yaw = -90.0f;
		float m_pitch = 0.0f;
		float m_movementSpeed = 2.5f;
		float m_mouseSensitivity = 0.1f;
	};
}

#endif // GAM703_GAME_COMPONENTS_MOVEMENT_CONTROLLER_HPP
