#ifndef GAM703_ENGINE_COMPONENTS_SPOT_LIGHT_HPP
#define GAM703_ENGINE_COMPONENTS_SPOT_LIGHT_HPP

#include <engine/core-interfaces/ILight.hpp>

#include <engine/components/Config.hpp>

namespace gam703::engine::components
{
	class ENGINE_COMPONENTS_API SpotLight : public core_interface::ILight
	{
	public:
		SpotLight(core_interface::Transform* transform, const glm::vec3& color, float innerAngle = 25.0f, float outerAngle = 45.0f, float range = 5.0f, float intensity = 1.0f);

		virtual core_interface::IComponent* clone(core_interface::Transform* transform) const override;

		virtual void tick(float deltaTime) override {}

		virtual void updateShaderLightInfo(const core_interface::IShader& shader) const override;

	private:
		float m_innerAngle;
		float m_outerAngle;
		float m_range;
	};
}

#endif // GAM703_ENGINE_COMPONENTS_SPOT_LIGHT_HPP
