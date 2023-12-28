#ifndef GAM703_ENGINE_COMPONENTS_POINT_LIGHT_HPP
#define GAM703_ENGINE_COMPONENTS_POINT_LIGHT_HPP

#include <engine/components/Config.hpp>

#include <engine/core-interfaces/ILight.hpp>

namespace gam703::engine::components
{
	class ENGINE_COMPONENTS_API PointLight : public core_interface::ILight
	{
	public:
		PointLight(core_interface::Transform* transform, const glm::vec3& color = glm::vec3(1.0f, 1.0f, 1.0f), float range = 5.0f, float intensity = 1.0f);

		virtual core_interface::IComponent* clone(core_interface::Transform* transform) const override;

		virtual void tick(float deltaTime) override {}

		virtual void updateShaderLightInfo(const core_interface::IShader& shader) const override;

	private:
		float m_range;
	};
}

#endif // GAM703_ENGINE_COMPONENTS_POINT_LIGHT_HPP
