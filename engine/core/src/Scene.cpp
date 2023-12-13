#include <engine/core/Engine.hpp>
#include <engine/core/Scene.hpp>

#include <engine/components/Transform.hpp>

namespace gam703::engine::core
{
	Scene::Scene(Engine* engine) : m_engine(engine)
	{
	}
	
	void Scene::updateScene(float deltaTime)
	{
		std::for_each(begin(m_transforms), end(m_transforms), [deltaTime](std::unique_ptr<core_interface::ITransform>& transform)
			{
				transform->updateComponents(deltaTime);
				transform->calculateTransformMatrix();
			});

		m_sceneRenderer.render();
	}

	void Scene::setActiveCamera(core_interface::ICamera* activeCamera)
	{
		m_sceneRenderer.setActiveCamera(activeCamera);
		m_sceneRenderer.calculateProjectionMatrix(m_engine->getWindow().getAspectRatio());
	}

	core_interface::ITransform* Scene::addTransform(const glm::vec3& position, const glm::vec3& rotation, const glm::vec3& scale)
	{
		auto* transform = new components::Transform(m_engine, this, position, rotation, scale);
		m_transforms.push_back(std::unique_ptr<core_interface::ITransform>(transform));
		return transform;
	}

	core_interface::ITransform* Scene::addTransform(const core_interface::ITransform* transform)
	{
		if (transform)
		{
			auto* newTransform = transform->clone();
			m_transforms.push_back(std::unique_ptr<core_interface::ITransform>(newTransform));
			return newTransform;
		}
		
		return nullptr;
	}
}
