#include <engine/core-interfaces/ITransform.hpp>

#include <algorithm>

namespace gam703::engine::core_interface
{
	ITransform::ITransform(IEngine* engine, IScene* scene, const glm::vec3& position, const glm::vec3& rotation, const glm::vec3& scale) :
		m_engine(engine),
		m_scene(scene),
		m_position(position),
		m_rotation(rotation),
		m_scale(scale)
	{
	}

	ITransform::ITransform(const ITransform& transform) : 
		m_engine(transform.m_engine),
		m_scene(transform.m_scene),
		m_position(transform.m_position),
		m_rotation(transform.m_rotation),
		m_scale(transform.m_scale),
		m_shouldCalculateTransform(transform.m_shouldCalculateTransform),
		m_shouldUpdateDirectionVectors(transform.m_shouldUpdateDirectionVectors)
	{
		std::for_each(begin(transform.m_components), end(transform.m_components), [this](const std::unique_ptr<core_interface::IComponent>& component)
			{
				m_components.push_back(std::unique_ptr<core_interface::IComponent>(component->clone(this)));
			});
	}

	ITransform& ITransform::operator=(const ITransform& transform)
	{
		m_position = transform.m_position;
		m_rotation = transform.m_rotation;
		m_scale = transform.m_scale;
		m_engine = transform.m_engine;
		m_scene = transform.m_scene;
		m_components = std::vector<std::unique_ptr<IComponent>>{};
		m_shouldCalculateTransform = transform.m_shouldCalculateTransform;
		m_shouldUpdateDirectionVectors = transform.m_shouldUpdateDirectionVectors;

		std::for_each(begin(transform.m_components), end(transform.m_components), [this](const std::unique_ptr<core_interface::IComponent>& component)
			{
				m_components.push_back(std::unique_ptr<core_interface::IComponent>(component->clone(this)));
			});

		return *this;
	}

	void ITransform::setPosition(const glm::vec3& position)
	{
		if (m_position != position)
		{
			m_position = position;
			m_shouldCalculateTransform = true;
		}
	}

	void ITransform::setPosition(float x, float y, float z)
	{
		setPosition(glm::vec3(x, y, z));
	}

	void ITransform::setRotation(const glm::vec3& eulerAngles)
	{
		if (m_rotation != eulerAngles)
		{
			m_rotation = eulerAngles;
			m_shouldCalculateTransform = true;
			m_shouldUpdateDirectionVectors = true;
		}
	}

	void ITransform::setRotation(float x, float y, float z)
	{
		setRotation(glm::vec3(x, y, z));
	}

	void ITransform::setScale(const glm::vec3& scale)
	{
		if (m_scale != scale)
		{
			m_scale = scale;
			m_shouldCalculateTransform = true;
		}
	}

	void ITransform::setScale(float x, float y, float z)
	{
		setScale(glm::vec3(x, y, z));
	}

	void ITransform::updateComponents(float deltaTime)
	{
		std::for_each(begin(m_components), end(m_components), [deltaTime](std::unique_ptr<core_interface::IComponent>& component) { component->tick(deltaTime); });
	}
}
