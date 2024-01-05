#ifndef GAM703_ENGINE_COMPONENTS_SPOT_LIGHT_HPP
#define GAM703_ENGINE_COMPONENTS_SPOT_LIGHT_HPP

#include <engine/components/Light.hpp>

#include <engine/components/Config.hpp>

namespace gam703::engine::components
{
	class ENGINE_COMPONENTS_API SpotLight : public Light
	{
	public:
		SpotLight(Transform* transform, const glm::vec3& color, float innerAngle = 25.0f, float outerAngle = 45.0f, float range = 5.0f, float intensity = 1.0f);

		virtual SpotLight* clone(Transform* transform) const override;

		virtual void updateShaderLightInfo(const graphic::Shader& shader) const override;

	private:
		float m_innerAngle;
		float m_outerAngle;
		float m_range;
	};
}

#endif // GAM703_ENGINE_COMPONENTS_SPOT_LIGHT_HPP
