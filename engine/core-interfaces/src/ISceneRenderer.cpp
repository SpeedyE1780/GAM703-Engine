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

		for (auto* renderer : m_sceneObjects)
		{
			renderer->updateProjectionMatrix(m_projectionMatrix);
		}
	}

	void ISceneRenderer::addRenderer(core_interface::IRenderer* sceneObject)
	{
		m_sceneObjects.push_back(sceneObject);
		sceneObject->updateProjectionMatrix(m_projectionMatrix);
		sceneObject->getMaterial()->getShader()->setVec3("ambientLight.color", m_ambientLight.m_color);
		sceneObject->getMaterial()->getShader()->setFloat("ambientLight.intensity", m_ambientLight.m_intensity);
	}

	void ISceneRenderer::removeRenderer(core_interface::IRenderer* sceneObject)
	{
		auto newEnd = std::remove_if(begin(m_sceneObjects), end(m_sceneObjects), [sceneObject](core_interface::IRenderer* renderer) { return sceneObject == renderer; });
		m_sceneObjects.erase(newEnd, end(m_sceneObjects));
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
