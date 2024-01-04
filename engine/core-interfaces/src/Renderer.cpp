#include <engine/core-interfaces/Renderer.hpp>
#include <engine/core-interfaces/Transform.hpp>

namespace gam703::engine::core_interface
{
	Renderer::Renderer(Transform* transform, const core_interface::IModel* model) : Component(transform), m_model(model)
	{
		getScene()->getSceneRenderer()->addRenderer(this);
	}

	Renderer::Renderer(Transform* transform, const core_interface::IModel* model, const Material& material) : Component(transform), m_model(model), m_material(material)
	{
		getScene()->getSceneRenderer()->addRenderer(this);
	}

	Renderer::~Renderer()
	{
		getScene()->getSceneRenderer()->removeRenderer(this);
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

	Renderer* Renderer::clone(core_interface::Transform* transform) const
	{
		return new Renderer(transform, m_model, m_material);
	}
}
