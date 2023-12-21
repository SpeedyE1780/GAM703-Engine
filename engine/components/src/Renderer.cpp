#include <engine/components/Renderer.hpp>

#include <engine/core-interfaces/IEngine.hpp>
#include <engine/core-interfaces/ITransform.hpp>

namespace gam703::engine::components
{
	Renderer::Renderer(core_interface::ITransform* transform, const core_interface::IModel* model) : core_interface::IRenderer(transform), m_model(model), m_material()
	{
		getScene()->getSceneRenderer()->addRenderer(this);
	}

	Renderer::Renderer(core_interface::ITransform* transform, const core_interface::IModel* model, const graphic::Material& material) : core_interface::IRenderer(transform), m_model(model), m_material(material)
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

	core_interface::IComponent* Renderer::clone(core_interface::ITransform* transform) const
	{
		return new Renderer(transform, m_model, m_material);
	}

	void Renderer::render(const glm::mat4& projectionMatrix, const glm::mat4& viewMatrix) const
	{
		auto* shader = m_material.getShader();
		shader->use();
		shader->setMat4("projection", projectionMatrix);
		shader->setMat4("view", viewMatrix);
		shader->setMat4("model", m_transform->getTransformationMatrix());

		m_model->draw(m_material);
	}
}
