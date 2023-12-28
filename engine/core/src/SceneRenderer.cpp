#include <glad/glad.h>
#include <glm/glm.hpp>

#include <engine/core-interfaces/Transform.hpp>

#include <engine/core/SceneRenderer.hpp>

#include <glm/gtc/matrix_transform.hpp>

namespace gam703::engine::core
{

	SceneRenderer::SceneRenderer(const std::vector<core_interface::IRenderer*>& sceneObjects) : m_sceneObjects(sceneObjects)
	{
	}

	void SceneRenderer::addRenderer(core_interface::IRenderer* sceneObject)
	{
		m_sceneObjects.push_back(sceneObject);
		sceneObject->updateProjectionMatrix(m_projectionMatrix);
		sceneObject->getMaterial()->getShader()->setVec3("ambientLight.color", m_ambientLight.m_color);
		sceneObject->getMaterial()->getShader()->setFloat("ambientLight.intensity", m_ambientLight.m_intensity);

		if (m_directionalLight)
		{
			m_directionalLight->updateShaderLightInfo(*sceneObject->getMaterial()->getShader());
		}

		for (auto* lightSource : m_lightSources)
		{
			lightSource->updateShaderLightInfo(*sceneObject->getMaterial()->getShader());
		}
	}

	void SceneRenderer::removeRenderer(core_interface::IRenderer* sceneObject)
	{
		auto newEnd = std::remove_if(begin(m_sceneObjects), end(m_sceneObjects), [sceneObject](core_interface::IRenderer* renderer) { return sceneObject == renderer; });
		m_sceneObjects.erase(newEnd, end(m_sceneObjects));
	}

	void SceneRenderer::addLightSource(core_interface::ILight* light)
	{
		m_lightSources.push_back(light);

		for (auto* renderer : m_sceneObjects)
		{
			light->updateShaderLightInfo(*renderer->getMaterial()->getShader());
		}
	}

	void SceneRenderer::removeLightSource(core_interface::ILight* light)
	{
		auto newEnd = std::remove_if(begin(m_lightSources), end(m_lightSources), [light](core_interface::ILight* lightSource) { return light == lightSource; });
		m_lightSources.erase(newEnd, end(m_lightSources));
	}

	void SceneRenderer::setAmbientLight(const glm::vec3& color, float strength)
	{
		m_ambientLight.m_color = color;
		m_ambientLight.m_intensity = strength;

		for (auto* renderer : m_sceneObjects)
		{
			renderer->getMaterial()->getShader()->setVec3("ambientLight.color", m_ambientLight.m_color);
			renderer->getMaterial()->getShader()->setFloat("ambientLight.intensity", m_ambientLight.m_intensity);
		}
	}

	void SceneRenderer::setAmbientLightColor(const glm::vec3& color)
	{
		m_ambientLight.m_color = color;

		for (auto* renderer : m_sceneObjects)
		{
			renderer->getMaterial()->getShader()->setVec3("ambientLight.color", m_ambientLight.m_color);
		}
	}

	void SceneRenderer::setAmbientLightIntensity(float intensity)
	{
		m_ambientLight.m_intensity = intensity;

		for (auto* renderer : m_sceneObjects)
		{
			renderer->getMaterial()->getShader()->setFloat("ambientLight.intensity", m_ambientLight.m_intensity);
		}
	}

	void SceneRenderer::calculateProjectionMatrix(float aspectRatio)
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

	void SceneRenderer::setDirectionalLight(core_interface::ILight* light)
	{
		m_directionalLight = dynamic_cast<components::DirectionalLight*>(light);

		for (auto* renderer : m_sceneObjects)
		{
			m_directionalLight->updateShaderLightInfo(*renderer->getMaterial()->getShader());
		}
	}

	void SceneRenderer::render() const
	{
		glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		for (auto* renderer : m_sceneObjects)
		{
			for (auto* lightSource : m_lightSources)
			{
				lightSource->updateShaderLightInfo(*renderer->getMaterial()->getShader());
			}

			renderer->render(m_activeCamera->GetViewMatrix(), m_activeCamera->getTransform()->getPosition());
		}
	}
}
