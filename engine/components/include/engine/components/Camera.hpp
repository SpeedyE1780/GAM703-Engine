#ifndef GAM703_ENGINE_COMPONENTS_CAMERA_HPP
#define GAM703_ENGINE_COMPONENTS_CAMERA_HPP

#include <engine/components/Config.hpp>
#include <engine/components/Component.hpp>

#include <glm/mat4x4.hpp>

namespace gam703::engine::components
{
	/// @brief Camera is used to render the scene
	class ENGINE_COMPONENTS_API Camera : public Component
	{
	public:
		/// @brief Create a camera that is owned by the transform
		/// @param transform The Transform owning this behavior
		Camera(Transform& transform);

		/// @brief Create a camera that is owned by the transform
		/// @param transform The Transform owning this behavior
		/// @param fieldOfView The camera FOV
		Camera(Transform& transform, float fieldOfView);

		/// @brief Create a copy attached to the new transform
		/// @param transform The new transform that will own the clone
		/// @return The cloned Camera belonging to the transform
		virtual Camera* clone(Transform& transform) const override;

		/// @brief Get the view matrix used in the vertex shader
		/// @return The view matrix used in the vertex shader to render 3D objects
		glm::mat4 getViewMatrix() const;

		/// @brief Get the camera FOV
		/// @return The Camera FOV
		float getFieldOfView() const { return m_fieldOfView; }

		/// @brief Set the camera FOV
		/// @param fieldOfView The new FOV
		void setFieldOfView(float fieldOfView);

	private:
		/// @brief The camera field of view value used to calculate the projection matrix
		float m_fieldOfView = 45.0f;
	};
}

#endif // GAM703_ENGINE_COMPONENTS_CAMERA_HPP
