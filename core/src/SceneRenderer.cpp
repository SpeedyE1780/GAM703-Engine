#include <glad/glad.h>
#include <core/SceneRenderer.hpp>

namespace gam703::engine::core
{
	SceneRenderer::SceneRenderer(const std::vector<components::Renderer*>& sceneObjects) : m_sceneObjects(sceneObjects)
	{
	}

	void SceneRenderer::render(const glm::mat4& projectionMatrix, const glm::mat4& viewMatrix) const
	{
		glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		for (auto* renderer : m_sceneObjects)
		{
			renderer->render(projectionMatrix, viewMatrix);
		}
	}
}

