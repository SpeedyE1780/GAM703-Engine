#include <engine/core/Scene.hpp>

#include <engine/core/Engine.hpp>

#include <engine/components/Transform.hpp>

namespace gam703::engine::core
{
	Scene::Scene(Engine& engine) : m_engine(engine)
	{
	}

	components::Transform* Scene::addTransform(const glm::vec3& position, const glm::vec3& rotation, const glm::vec3& scale)
	{
		auto* transform = new components::Transform(m_engine, position, rotation, scale);
		m_transforms.push_back(std::unique_ptr<components::Transform>(transform));
		return transform;
	}

	components::Transform* Scene::addTransform(const components::Transform& transform)
	{
		auto* newTransform = transform.clone();
		m_transforms.push_back(std::unique_ptr<components::Transform>(newTransform));
		return newTransform;
	}

	void Scene::removeTransform(const components::Transform& transform)
	{
		auto newEnd = std::remove_if(begin(m_transforms), end(m_transforms), [&transform, this](std::unique_ptr<components::Transform>& sceneTransform)
			{
				if (&transform == sceneTransform.get())
				{
					m_deletedTransforms.emplace_back(std::move(sceneTransform));
					return true;
				}

				return false;
			});

		m_transforms.erase(newEnd, end(m_transforms));
	}

	void Scene::setActiveCamera(components::Camera* activeCamera)
	{
		m_sceneRenderer.setActiveCamera(activeCamera);
		m_sceneRenderer.calculateProjectionMatrix(m_engine.getWindow().getAspectRatio());
	}

	void Scene::updateScene(float deltaTime)
	{
		std::for_each(rbegin(m_transforms), rend(m_transforms), [deltaTime](std::unique_ptr<components::Transform>& transform)
			{
				transform->updateBehaviors(deltaTime);
				transform->calculateTransformMatrix();
			});

		m_sceneRenderer.render();

		if (m_deletedTransforms.size() > 0)
		{
			m_deletedTransforms.clear();
		}
	}

	void Scene::updateSceneProjectionMatrix()
	{
		m_sceneRenderer.calculateProjectionMatrix(m_engine.getWindow().getAspectRatio());
	}
}
