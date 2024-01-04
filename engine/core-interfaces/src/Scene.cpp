#include <engine/core-interfaces/IEngine.hpp>
#include <engine/core-interfaces/Scene.hpp>
#include <engine/core-interfaces/Transform.hpp>

namespace gam703::engine::core_interface
{
	Scene::Scene(IEngine* engine) : m_engine(engine)
	{
	}

	Transform* Scene::addTransform(const glm::vec3& position, const glm::vec3& rotation, const glm::vec3& scale)
	{
		auto* transform = new Transform(m_engine, this, position, rotation, scale);
		m_transforms.push_back(std::unique_ptr<Transform>(transform));
		return transform;
	}

	Transform* Scene::addTransform(const Transform* transform)
	{
		if (transform)
		{
			auto* newTransform = transform->clone();
			m_transforms.push_back(std::unique_ptr<Transform>(newTransform));
			return newTransform;
		}

		return nullptr;
	}

	void Scene::setActiveCamera(Camera* activeCamera)
	{
		m_sceneRenderer.setActiveCamera(activeCamera);
		m_sceneRenderer.calculateProjectionMatrix(m_engine->getAspectRatio());
	}

	void Scene::updateScene(float deltaTime)
	{
		std::for_each(begin(m_transforms), end(m_transforms), [deltaTime](std::unique_ptr<Transform>& transform)
			{
				transform->updateBehaviors(deltaTime);
				transform->calculateTransformMatrix();
			});

		m_sceneRenderer.render();
	}

	void Scene::updateSceneProjectionMatrix()
	{
		m_sceneRenderer.calculateProjectionMatrix(m_engine->getAspectRatio());
	}
}
