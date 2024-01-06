#ifndef GAM703_ENGINE_COMPONENTS_DIRECTIONAL_LIGHTS_HPP
#define GAM703_ENGINE_COMPONENTS_DIRECTIONAL_LIGHTS_HPP

#include <engine/components/Config.hpp>
#include <engine/components/Light.hpp>

namespace gam703::engine::components
{
	/// @brief DirectionalLight acts like a sun and lights up all object in the scene
	class ENGINE_COMPONENTS_API DirectionalLight : public Light
	{
	public:
		/// @brief Create a directional light that is owned by the transform
		/// @param transform The Transform owning this component
		/// @param color The light color
		/// @param intensity The light intensity
		DirectionalLight(Transform& transform, const glm::vec3& color, float intensity = 1.0f);

		/// @brief Create a copy attached to the new transform
		/// @param transform transform The new transform that will own the clone
		/// @return The cloned DirectionalLight belonging to the transform
		virtual DirectionalLight* clone(Transform& transform) const override;

		/// @brief Update the shader DirectionalLight uniforms
		/// @param shader The shader of the object being rendered
		virtual void updateShaderLightInfo(const graphic::Shader& shader) const override;
	};
}

#endif // GAM703_ENGINE_COMPONENTS_DIRECTIONAL_LIGHTS_HPP
