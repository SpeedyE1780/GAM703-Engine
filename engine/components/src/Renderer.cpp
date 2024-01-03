#include <engine/components/Renderer.hpp>

#include <engine/core-interfaces/IEngine.hpp>
#include <engine/core-interfaces/Transform.hpp>

namespace gam703::engine::components
{
	Renderer::Renderer(core_interface::Transform* transform, const core_interface::IModel* model) : core_interface::IRenderer(transform), m_model(model), m_material()
	{
		getScene()->getSceneRenderer()->addRenderer(this);
	}

	Renderer::Renderer(core_interface::Transform* transform, const core_interface::IModel* model, const core_interface::Material& material) : core_interface::IRenderer(transform), m_model(model), m_material(material)
	{
		getScene()->getSceneRenderer()->addRenderer(this);
	}

	Renderer::~Renderer()
	{
		getScene()->getSceneRenderer()->removeRenderer(this);
	}

	void Renderer::tick(float /*deltaTime*/)
	{
	}

	core_interface::IComponent* Renderer::clone(core_interface::Transform* transform) const
	{
		return new Renderer(transform, m_model, m_material);
	}

	void Renderer::updateProjectionMatrix(const glm::mat4& projectionMatrix) const
	{
		m_material.getShader()->setMat4("projection", projectionMatrix);
	}

	void Renderer::render(const glm::mat4& viewMatrix, const glm::vec3& cameraPosition) const
	{
		auto* shader = m_material.getShader();
		shader->use();
		shader->setMat4("view", viewMatrix);
		shader->setMat4("model", m_transform->getTransformationMatrix());
		shader->setMat3("normalMatrix", m_transform->getNormalMatrix());
		shader->setVec3("lightPosition", cameraPosition);
		shader->setVec3("cameraPosition", cameraPosition);

		m_model->draw(m_material);
	}
}
