#ifndef GAM703_ENGINE_COMPONENTS_POINT_LIGHT_HPP
#define GAM703_ENGINE_COMPONENTS_POINT_LIGHT_HPP

#include <engine/components/Config.hpp>

#include <engine/components/Light.hpp>

namespace gam703::engine::components
{
	class ENGINE_COMPONENTS_API PointLight : public Light
	{
	public:
		PointLight(Transform& transform, const glm::vec3& color = glm::vec3(1.0f, 1.0f, 1.0f), float range = 5.0f, float intensity = 1.0f);

		virtual PointLight* clone(Transform& transform) const override;

		virtual void updateShaderLightInfo(const graphic::Shader& shader) const override;

	private:
		float m_range;
	};
}

#endif // GAM703_ENGINE_COMPONENTS_POINT_LIGHT_HPP
