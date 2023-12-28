#include <engine/core/Engine.hpp>
#include <engine/core/Scene.hpp>

#include <engine/core-interfaces/Transform.hpp>

namespace gam703::engine::core
{
	Scene::Scene(Engine* engine) : m_engine(engine)
	{
	}
	
	void Scene::updateScene(float deltaTime)
	{
		std::for_each(begin(m_transforms), end(m_transforms), [deltaTime](std::unique_ptr<core_interface::Transform>& transform)
			{
				transform->updateComponents(deltaTime);
				transform->calculateTransformMatrix();
			});

		m_sceneRenderer.render();
	}

	void Scene::updateSceneProjectionMatrix()
	{
		m_sceneRenderer.calculateProjectionMatrix(m_engine->getWindow().getAspectRatio());
	}

	void Scene::setActiveCamera(core_interface::ICamera* activeCamera)
	{
		m_sceneRenderer.setActiveCamera(activeCamera);
		m_sceneRenderer.calculateProjectionMatrix(m_engine->getWindow().getAspectRatio());
	}

	core_interface::Transform* Scene::addTransform(const glm::vec3& position, const glm::vec3& rotation, const glm::vec3& scale)
	{
		auto* transform = new core_interface::Transform(m_engine, this, position, rotation, scale);
		m_transforms.push_back(std::unique_ptr<core_interface::Transform>(transform));
		return transform;
	}

	core_interface::Transform* Scene::addTransform(const core_interface::Transform* transform)
	{
		if (transform)
		{
			auto* newTransform = transform->clone();
			m_transforms.push_back(std::unique_ptr<core_interface::Transform>(newTransform));
			return newTransform;
		}
		
		return nullptr;
	}
}
