#ifndef GAM703_ENGINE_COMPONENTS_DIRECTIONAL_LIGHTS_HPP
#define GAM703_ENGINE_COMPONENTS_DIRECTIONAL_LIGHTS_HPP

#include <engine/components/Config.hpp>
#include <engine/core-interfaces/ILight.hpp>

namespace gam703::engine::components
{
	class ENGINE_COMPONENTS_API DirectionalLight : public core_interface::ILight
	{
	public:
		DirectionalLight(core_interface::ITransform* transform, const glm::vec3& color, float intensity = 1.0f);

		virtual core_interface::IComponent* clone(core_interface::ITransform* transform) const override;

		virtual void tick(float deltaTime) override {}

		virtual void updateShaderLightInfo(const core_interface::IShader& shader) const override;
	};
}

#endif // GAM703_ENGINE_COMPONENTS_DIRECTIONAL_LIGHTS_HPP
