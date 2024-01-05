#ifndef GAM703_ENGINE_COMPONENTS_CAMERA_HPP
#define GAM703_ENGINE_COMPONENTS_CAMERA_HPP

#include <engine/components/Config.hpp>
#include <engine/components/Component.hpp>

#include <glm/mat4x4.hpp>

namespace gam703::engine::components
{
	class ENGINE_COMPONENTS_API Camera : public Component
	{
	public:
		Camera(Transform& transform);
		Camera(Transform& transform, float fieldOfView);

		virtual Camera* clone(Transform& transform) const override;

		glm::mat4 getViewMatrix() const;
		float getFieldOfView() const { return m_fieldOfView; }
		void setFieldOfView(float fieldOfView);

	private:
		float m_fieldOfView = 45.0f;
	};
}

#endif // GAM703_ENGINE_COMPONENTS_CAMERA_HPP
