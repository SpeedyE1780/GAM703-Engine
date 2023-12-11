#include <glad/glad.h>
#include <glm/glm.hpp>
#include <core/SceneRenderer.hpp>
#include <iostream>

namespace gam703::engine::core
{
	SceneRenderer::SceneRenderer(gui::Window* window) : m_window(window)
	{
	}

	SceneRenderer::SceneRenderer(gui::Window* window, const std::vector<core_interface::IRenderer*>& sceneObjects) : m_window(window), m_sceneObjects(sceneObjects)
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

	void SceneRenderer::setMainCamera(components::Camera* camera)
	{
		m_mainCamera = camera;
		calculateProjectionMatrix();
	}

	void SceneRenderer::calculateProjectionMatrix()
	{
		if (!m_mainCamera)
		{
			return;
		}

		m_projectionMatrix = glm::perspective(glm::radians(m_mainCamera->getZoom()), m_window->getAspectRatio(), 0.1f, 100.0f);
	}

	void SceneRenderer::render() const
	{
		glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		for (auto* renderer : m_sceneObjects)
		{
			renderer->render(m_projectionMatrix, m_mainCamera->GetViewMatrix());
		}
	}
}

