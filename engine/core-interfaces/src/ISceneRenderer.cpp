#include <engine/core-interfaces/ISceneRenderer.hpp>

namespace gam703::engine::core_interface
{
	void ISceneRenderer::setAmbientLight(const glm::vec3& color, float strength)
	{
		m_ambientLight.m_color = color;
		m_ambientLight.m_intensity = strength;
		m_shouldUpdateAmbientLight = true;
	}

	void ISceneRenderer::setAmbientLightColor(const glm::vec3& color)
	{
		m_ambientLight.m_color = color;
		m_shouldUpdateAmbientLight = true;
	}

	void ISceneRenderer::setAmbientLightIntensity(float intensity)
	{
		m_ambientLight.m_intensity = intensity;
		m_shouldUpdateAmbientLight = true;
	}
}
