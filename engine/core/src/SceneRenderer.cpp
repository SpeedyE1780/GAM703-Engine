#include <glad/glad.h>
#include <glm/glm.hpp>

#include <engine/core-interfaces/Transform.hpp>

#include <engine/core/SceneRenderer.hpp>

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

	void SceneRenderer::calculateProjectionMatrix(float aspectRatio)
	{
		core_interface::ISceneRenderer::calculateProjectionMatrix(aspectRatio);

		for (auto* renderer : m_sceneObjects)
		{
			renderer->updateProjectionMatrix(m_projectionMatrix);
		}
	}

	void SceneRenderer::render() const
	{
		glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		for (auto* renderer : m_sceneObjects)
		{
			if (m_shouldUpdateAmbientLight)
			{
				renderer->getMaterial()->getShader()->setAmbientLight(m_ambientLight.m_color, m_ambientLight.m_intensity);
			}

			for (auto* lightSource : m_lightSources)
			{
				lightSource->updateShaderLightInfo(*renderer->getMaterial()->getShader());
			}

			renderer->render(m_activeCamera->getViewMatrix(), m_activeCamera->getTransform()->getPosition());
		}

		m_shouldUpdateAmbientLight = false;
	}
}
