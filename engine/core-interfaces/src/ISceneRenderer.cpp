#include <engine/core-interfaces/ISceneRenderer.hpp>

#include <glm/gtc/matrix_transform.hpp>

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

	void ISceneRenderer::calculateProjectionMatrix(float aspectRatio)
	{
		if (!m_activeCamera)
		{
			return;
		}

		m_projectionMatrix = glm::perspective(glm::radians(m_activeCamera->getFieldOfView()), aspectRatio, 0.1f, 100.0f);
	}

	void ISceneRenderer::addLightSource(ILight* light)
	{
		m_lightSources.push_back(light);
	}

	void ISceneRenderer::removeLightSource(ILight* light)
	{
		auto newEnd = std::remove_if(begin(m_lightSources), end(m_lightSources), [light](core_interface::ILight* lightSource) { return light == lightSource; });
		m_lightSources.erase(newEnd, end(m_lightSources));
	}
}
