#include <engine/core/Engine.hpp>
#include <engine/core/Scene.hpp>

#include <engine/core-interfaces/Transform.hpp>

namespace gam703::engine::core
{
	Scene::Scene(Engine* engine) : IScene(engine)
	{
	}

	void Scene::updateSceneProjectionMatrix()
	{
		m_sceneRenderer.calculateProjectionMatrix(m_engine->getAspectRatio());
	}
}
