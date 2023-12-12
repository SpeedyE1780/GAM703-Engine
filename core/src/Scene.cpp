#include <core/Engine.hpp>
#include <core/Scene.hpp>

namespace gam703::engine::core
{
	Scene::Scene(Engine* engine) : m_engine(engine)
	{
	}

	core_interface::ITransform* Scene::addTransform(const glm::vec3& position, const glm::vec3& rotation, const glm::vec3& scale)
	{
		auto* transform = new components::Transform(m_engine, position, rotation, scale);
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
