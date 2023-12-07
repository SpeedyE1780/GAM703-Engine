#ifndef GAM703_ENGINE_COMPONENTS_CAMERA_HPP
#define GAM703_ENGINE_COMPONENTS_CAMERA_HPP

#include <components/Config.hpp>
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

	class COMPONENTS_API Camera
	{
	public:

		Camera(glm::vec3 position = glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f), float yaw = YAW, float pitch = PITCH);

		Camera(float posX, float posY, float posZ, float upX, float upY, float upZ, float yaw, float pitch);

		glm::mat4 GetViewMatrix() const;
		void ProcessKeyboard(Camera_Movement direction, float deltaTime);
		void ProcessMouseMovement(float xoffset, float yoffset, bool constrainPitch = true);
		void ProcessMouseScroll(float yoffset);

		glm::vec3 getPosition() const { return m_position; }
		glm::vec3 getFront() const { return m_front; }
		glm::vec3 getUp() const { return m_up; }
		glm::vec3 getRight() const { return m_right; }
		glm::vec3 getWorldUp() const { return m_worldUp; }
		float getYaw() const { return m_yaw; }
		float getPitch() const { return m_pitch; }
		float getMovementSpeed() const { return m_movementSpeed; }
		float getMouseSensitivity() const { return m_mouseSensitivity; }
		float getZoom() const { return m_zoom; }

	private:
		void updateCameraVectors();

		glm::vec3 m_position;
		glm::vec3 m_front;
		glm::vec3 m_up;
		glm::vec3 m_right;
		glm::vec3 m_worldUp;
		float m_yaw;
		float m_pitch;
		float m_movementSpeed;
		float m_mouseSensitivity;
		float m_zoom;
	};

} //gam703::engine::components

#endif //GAM703_ENGINE_COMPONENTS_CAMERA_HPP
