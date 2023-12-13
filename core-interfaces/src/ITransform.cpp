#include <core-interfaces/ITransform.hpp>
#include <algorithm>

namespace gam703::engine::core_interface
{
	ITransform::ITransform(IEngine* engine, IScene* scene) : m_engine(engine), m_scene(scene)
	{
	}

	ITransform::ITransform(const ITransform& transform) : m_engine(transform.m_engine), m_scene(transform.m_scene)
	{
		std::for_each(begin(transform.m_components), end(transform.m_components), [this](const std::unique_ptr<core_interface::IComponent>& component)
			{
				m_components.push_back(std::unique_ptr<core_interface::IComponent>(component->clone(this)));
			});
	}

	ITransform& ITransform::operator=(const ITransform& transform)
	{
		m_engine = transform.m_engine;
		m_scene = transform.m_scene;
		m_components = std::vector<std::unique_ptr<IComponent>>{};

		std::for_each(begin(transform.m_components), end(transform.m_components), [this](const std::unique_ptr<core_interface::IComponent>& component)
			{
				m_components.push_back(std::unique_ptr<core_interface::IComponent>(component->clone(this)));
			});

		return *this;
	}

	void ITransform::updateComponents(float deltaTime)
	{
		std::for_each(begin(m_components), end(m_components), [deltaTime](std::unique_ptr<core_interface::IComponent>& component) {component->tick(deltaTime); });
	}
}
