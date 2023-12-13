#ifndef GAM703_ENGINE_COMPONENTS_CAMERA_HPP
#define GAM703_ENGINE_COMPONENTS_CAMERA_HPP

#include <engine/components/Config.hpp>

#include <engine/core-interfaces/ICamera.hpp>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <vector>

namespace gam703::engine::components
{

	class ENGINE_COMPONENTS_API Camera : public core_interface::ICamera
	{
	public:
		Camera(core_interface::ITransform* transform);

		virtual core_interface::IComponent* clone(core_interface::ITransform* transform) const override;

		virtual glm::mat4 GetViewMatrix() const override;
		virtual float getFieldOfView() const override { return m_fieldOfView; }

		void tick(float deltaTime) override;

	private:
		float m_fieldOfView = 45.0f;
	};

} //gam703::engine::components

#endif //GAM703_ENGINE_COMPONENTS_CAMERA_HPP
