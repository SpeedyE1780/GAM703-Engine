#ifndef GAM703_ENGINE_COMPONENTS_CAMERA_HPP
#define GAM703_ENGINE_COMPONENTS_CAMERA_HPP

#include <components/Config.hpp>
#include <core-interfaces/IComponent.hpp>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <vector>

namespace gam703::engine::components
{

	enum COMPONENTS_API Camera_Movement
	{
		FORWARD,
		BACKWARD,
		LEFT,
		RIGHT
	};

	constexpr float YAW = -90.0f;
	constexpr float PITCH = 0.0f;
	constexpr float SPEED = 2.5f;
	constexpr float SENSITIVITY = 0.1f;
	constexpr float ZOOM = 45.0f;

	class COMPONENTS_API Camera : public core_interface::IComponent
	{
	public:
		Camera(core_interface::ITransform* transform, float yaw = YAW, float pitch = PITCH);

		virtual IComponent* clone(core_interface::ITransform* transform) const override;

		glm::mat4 GetViewMatrix() const;
		float getYaw() const { return m_yaw; }
		float getPitch() const { return m_pitch; }
		float getMovementSpeed() const { return m_movementSpeed; }
		float getMouseSensitivity() const { return m_mouseSensitivity; }
		float getZoom() const { return m_zoom; }

		void tick(float deltaTime) override;

	private:
		float m_yaw;
		float m_pitch;
		float m_movementSpeed;
		float m_mouseSensitivity;
		float m_zoom;
	};

} //gam703::engine::components

#endif //GAM703_ENGINE_COMPONENTS_CAMERA_HPP
