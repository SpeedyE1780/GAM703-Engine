#include <engine/core-interfaces/ILight.hpp>
#include <engine/core-interfaces/IScene.hpp>

namespace gam703::engine::core_interface
{
	ILight::ILight(Transform* transform, const glm::vec3& color, float intensity) : IComponent(transform), m_color(color), m_intensity(intensity)
	{
		getScene()->getSceneRenderer()->addLightSource(this);
	}

	ILight::~ILight()
	{
		getScene()->getSceneRenderer()->removeLightSource(this);
	}
}
