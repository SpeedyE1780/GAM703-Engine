#include <glad/glad.h>

#include <engine/components/Transform.hpp>

#include <engine/core/SceneRenderer.hpp>

#include <glm/gtc/matrix_transform.hpp>

namespace gam703::engine::core
{
	void SceneRenderer::setAmbientLight(const glm::vec3& color, float intensity)
	{
		m_ambientLight.m_color = color;
		m_ambientLight.m_intensity = intensity;
		m_shouldUpdateAmbientLight = true;
	}

	void SceneRenderer::setAmbientLightColor(const glm::vec3& color)
	{
		m_ambientLight.m_color = color;
		m_shouldUpdateAmbientLight = true;
	}

	void SceneRenderer::setAmbientLightIntensity(float intensity)
	{
		m_ambientLight.m_intensity = intensity;
		m_shouldUpdateAmbientLight = true;
	}

	void SceneRenderer::calculateProjectionMatrix(float aspectRatio)
	{
		if (!m_activeCamera || std::isnan(aspectRatio))
		{
			return;
		}

		m_projectionMatrix = glm::perspective(glm::radians(m_activeCamera->getFieldOfView()), aspectRatio, 0.1f, 100.0f);

		for (auto* renderer : m_sceneObjects)
		{
			renderer->updateProjectionMatrix(m_projectionMatrix);
		}
	}

	void SceneRenderer::addRenderer(components::Renderer* sceneObject)
	{
		m_sceneObjects.push_back(sceneObject);
		sceneObject->updateProjectionMatrix(m_projectionMatrix);
		sceneObject->getMaterial().getShader().setVec3("ambientLight.color", m_ambientLight.m_color);
		sceneObject->getMaterial().getShader().setFloat("ambientLight.intensity", m_ambientLight.m_intensity);
	}

	void SceneRenderer::removeRenderer(components::Renderer* sceneObject)
	{
		auto newEnd = std::remove_if(begin(m_sceneObjects), end(m_sceneObjects), [sceneObject](components::Renderer* renderer) { return sceneObject == renderer; });
		m_sceneObjects.erase(newEnd, end(m_sceneObjects));
	}

	void SceneRenderer::addLightSource(components::Light* light)
	{
		m_lightSources.push_back(light);
	}

	void SceneRenderer::removeLightSource(components::Light* light)
	{
		auto newEnd = std::remove_if(begin(m_lightSources), end(m_lightSources), [light](components::Light* lightSource) { return light == lightSource; });
		m_lightSources.erase(newEnd, end(m_lightSources));
	}

	void SceneRenderer::render() const
	{
		glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		for (auto* renderer : m_sceneObjects)
		{
			if (m_shouldUpdateAmbientLight)
			{
				renderer->getMaterial().getShader().setAmbientLight(m_ambientLight.m_color, m_ambientLight.m_intensity);
			}

			for (auto* lightSource : m_lightSources)
			{
				lightSource->updateShaderLightInfo(renderer->getMaterial().getShader());
			}

			renderer->render(m_activeCamera->getViewMatrix(), m_activeCamera->getTransform().getPosition());
		}

		m_shouldUpdateAmbientLight = false;
	}
}
