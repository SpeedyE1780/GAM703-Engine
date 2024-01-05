#include <engine/components/Light.hpp>
#include <engine/core/Scene.hpp>

namespace gam703::engine::components
{
	Light::Light(Transform& transform, const glm::vec3& color, float intensity) : Component(transform), m_color(color), m_intensity(intensity)
	{
		getScene().getSceneRenderer().addLightSource(this);
	}

	Light::~Light()
	{
		getScene().getSceneRenderer().removeLightSource(this);
	}
}
