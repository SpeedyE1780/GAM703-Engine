#include <glad/glad.h>
#include <glm/glm.hpp>

#include <engine/core-interfaces/Transform.hpp>

#include <engine/core/SceneRenderer.hpp>

namespace gam703::engine::core
{
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
