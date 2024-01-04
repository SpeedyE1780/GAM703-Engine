#include <engine/core/Engine.hpp>
#include <engine/core/Scene.hpp>

#include <engine/core-interfaces/Transform.hpp>

namespace gam703::engine::core
{
	Scene::Scene(Engine* engine) : IScene(engine)
	{
	}
	
	void Scene::updateScene(float deltaTime)
	{
		std::for_each(begin(m_transforms), end(m_transforms), [deltaTime](std::unique_ptr<core_interface::Transform>& transform)
			{
				transform->updateBehaviors(deltaTime);
				transform->calculateTransformMatrix();
			});

		m_sceneRenderer.render();
	}

	void Scene::updateSceneProjectionMatrix()
	{
		m_sceneRenderer.calculateProjectionMatrix(dynamic_cast<Engine*>(m_engine)->getWindow().getAspectRatio());
	}

	void Scene::setActiveCamera(core_interface::Camera* activeCamera)
	{
		m_sceneRenderer.setActiveCamera(activeCamera);
		m_sceneRenderer.calculateProjectionMatrix(dynamic_cast<Engine*>(m_engine)->getWindow().getAspectRatio());
	}
}
