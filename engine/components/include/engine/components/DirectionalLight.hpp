#ifndef GAM703_ENGINE_COMPONENTS_DIRECTIONAL_LIGHTS_HPP
#define GAM703_ENGINE_COMPONENTS_DIRECTIONAL_LIGHTS_HPP

#include <engine/components/Config.hpp>
#include <engine/components/Light.hpp>

namespace gam703::engine::components
{
	class ENGINE_COMPONENTS_API DirectionalLight : public Light
	{
	public:
		DirectionalLight(Transform& transform, const glm::vec3& color, float intensity = 1.0f);

		virtual DirectionalLight* clone(Transform& transform) const override;

		virtual void updateShaderLightInfo(const graphic::Shader& shader) const override;
	};
}

#endif // GAM703_ENGINE_COMPONENTS_DIRECTIONAL_LIGHTS_HPP
