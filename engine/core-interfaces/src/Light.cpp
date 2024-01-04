#include <engine/core-interfaces/Light.hpp>
#include <engine/core-interfaces/Scene.hpp>

namespace gam703::engine::core_interface
{
	Light::Light(Transform* transform, const glm::vec3& color, float intensity) : Component(transform), m_color(color), m_intensity(intensity)
	{
		getScene()->getSceneRenderer()->addLightSource(this);
	}

	Light::~Light()
	{
		getScene()->getSceneRenderer()->removeLightSource(this);
	}
}
