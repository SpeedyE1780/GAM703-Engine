#ifndef GAM703_ENGINE_CORE_INTERFACES_ICAMERA_HPP
#define GAM703_ENGINE_CORE_INTERFACES_ICAMERA_HPP

#include <engine/core-interfaces/Config.hpp>
#include <engine/core-interfaces/Component.hpp>

#include <glm/mat4x4.hpp>

namespace gam703::engine::core_interface
{
	class ENGINE_CORE_INTERFACES_API Camera : public Component
	{
	public:
		Camera(Transform* transform);
		Camera(Transform* transform, float fieldOfView);
		virtual ~Camera() = default;

		virtual Camera* clone(Transform* transform) const override;

		glm::mat4 getViewMatrix() const;
		float getFieldOfView() const { return m_fieldOfView; }
		void setFieldOfView(float fieldOfView);

	private:
		float m_fieldOfView = 45.0f;
	};
}

#endif // GAM703_ENGINE_CORE_INTERFACES_ICAMERA_HPP
