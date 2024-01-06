#ifndef GAM703_ENGINE_COMPONENTS_POINT_LIGHT_HPP
#define GAM703_ENGINE_COMPONENTS_POINT_LIGHT_HPP

#include <engine/components/Config.hpp>

#include <engine/components/Light.hpp>

namespace gam703::engine::components
{
	/// @brief PointLight acts like a light bulb and lights up all objects in range
	class ENGINE_COMPONENTS_API PointLight : public Light
	{
	public:
		/// @brief Create a light that is owned by the transform
		/// @param transform The Transform owning this component
		/// @param color The light color
		/// @param range The light range
		/// @param intensity The light intensity
		PointLight(Transform& transform, const glm::vec3& color = glm::vec3(1.0f, 1.0f, 1.0f), float range = 5.0f, float intensity = 1.0f);

		/// @brief Create a copy attached to the new transform
		/// @param transform The new transform that will own the clone
		/// @return The cloned PointLight belonging to the transform
		virtual PointLight* clone(Transform& transform) const override;

		/// @brief Update the shader PointLight uniforms
		/// @param shader The shader of the object being rendered
		virtual void updateShaderLightInfo(const graphic::Shader& shader) const override;

	private:
		/// @brief The light range
		float m_range;
	};
}

#endif // GAM703_ENGINE_COMPONENTS_POINT_LIGHT_HPP
