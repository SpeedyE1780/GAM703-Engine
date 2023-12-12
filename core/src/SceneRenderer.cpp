#include <glad/glad.h>
#include <glm/glm.hpp>
#include <core/SceneRenderer.hpp>
#include <iostream>

namespace gam703::engine::core
{

	SceneRenderer::SceneRenderer(const std::vector<core_interface::IRenderer*>& sceneObjects) : m_sceneObjects(sceneObjects)
	{
	}

	void SceneRenderer::addRenderer(core_interface::IRenderer* sceneObject)
	{
		m_sceneObjects.push_back(sceneObject);
	}

	void SceneRenderer::removeRenderer(core_interface::IRenderer* sceneObject)
	{
		auto newEnd = std::remove_if(begin(m_sceneObjects), end(m_sceneObjects), [sceneObject](core_interface::IRenderer* renderer) { return sceneObject == renderer; });
		m_sceneObjects.erase(newEnd, end(m_sceneObjects));
	}

	void SceneRenderer::setActiveCamera(components::Camera* camera)
	{
		m_activeCamera = camera;
	}

	void SceneRenderer::calculateProjectionMatrix(float aspectRatio)
	{
		if (!m_activeCamera)
		{
			return;
		}

		m_projectionMatrix = glm::perspective(glm::radians(m_activeCamera->getZoom()), aspectRatio, 0.1f, 100.0f);
	}

	void SceneRenderer::render() const
	{
		glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		for (auto* renderer : m_sceneObjects)
		{
			renderer->render(m_projectionMatrix, m_activeCamera->GetViewMatrix());
		}
	}
}

