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
		m_transforms.push_back(std::unique_ptr<components::Transform>(transform));
		return transform;
	}
}
