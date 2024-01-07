#ifndef GAM703_ENGINE_COMPONENTS_SPOT_LIGHT_HPP
#define GAM703_ENGINE_COMPONENTS_SPOT_LIGHT_HPP

#include <engine/components/Light.hpp>

#include <engine/components/Config.hpp>

namespace gam703::engine::components
{
	/// @brief SpotLight acts like a spot light and lights up all objects in the light cone
	class ENGINE_COMPONENTS_API SpotLight : public Light
	{
	public:
		/// @brief Create a directional light that is owned by the transform
		/// @param transform The Transform owning this component
		/// @param color The light color
		/// @param innerAngle The inner cone angle that gets full intensity
		/// @param outerAngle The outer cone angle where the intensity reaches zero
		/// @param range The cone base distance from the spot light
		/// @param intensity The light intensity
		SpotLight(Transform& transform, const glm::vec3& color, float innerAngle = 25.0f, float outerAngle = 45.0f, float range = 5.0f, float intensity = 1.0f);

		/// @brief Create a copy attached to the new transform
		/// @param transform The new transform that will own the clone
		/// @return The cloned SpotLight belonging to the transform
		virtual SpotLight* clone(Transform& transform) const override;

		/// @brief Update the shader SpotLight uniforms
		/// @param shader The shader of the object being rendered
		virtual void updateShaderLightInfo(const graphic::Shader& shader) const override;

	private:
		/// @brief The inner cone angle that gets full intensity
		float m_innerAngle;
		/// @brief The outer cone angle where the intensity reaches zero
		float m_outerAngle;
		/// @brief The cone base distance from the spot light
		float m_range;
	};
}

#endif // GAM703_ENGINE_COMPONENTS_SPOT_LIGHT_HPP
