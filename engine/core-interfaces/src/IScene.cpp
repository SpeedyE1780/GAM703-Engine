#include <engine/core-interfaces/IEngine.hpp>
#include <engine/core-interfaces/IScene.hpp>
#include <engine/core-interfaces/Transform.hpp>

namespace gam703::engine::core_interface
{
	IScene::IScene(IEngine* engine) : m_engine(engine)
	{
	}

	Transform* IScene::addTransform(const glm::vec3& position, const glm::vec3& rotation, const glm::vec3& scale)
	{
		auto* transform = new Transform(m_engine, this, position, rotation, scale);
		m_transforms.push_back(std::unique_ptr<Transform>(transform));
		return transform;
	}

	Transform* IScene::addTransform(const Transform* transform)
	{
		if (transform)
		{
			auto* newTransform = transform->clone();
			m_transforms.push_back(std::unique_ptr<Transform>(newTransform));
			return newTransform;
		}

		return nullptr;
	}

	void IScene::setActiveCamera(Camera* activeCamera)
	{
		m_sceneRenderer.setActiveCamera(activeCamera);
		m_sceneRenderer.calculateProjectionMatrix(m_engine->getAspectRatio());
	}
}
