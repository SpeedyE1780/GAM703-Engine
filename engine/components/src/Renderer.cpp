#include <engine/components/Renderer.hpp>
#include <engine/components/Transform.hpp>

#include <engine/core/Engine.hpp>

namespace gam703::engine::components
{
	Renderer::Renderer(Transform& transform, const graphic::Model* model) : Component(transform), m_model(model), m_material(getEngine().getResourceManager().getDefaultShader())
	{
		getScene().getSceneRenderer().addRenderer(this);
	}

	Renderer::Renderer(Transform& transform, const graphic::Model* model, const graphic::Material& material) : Component(transform), m_model(model), m_material(material)
	{
		getScene().getSceneRenderer().addRenderer(this);
	}

	Renderer::~Renderer()
	{
		getScene().getSceneRenderer().removeRenderer(this);
	}

	void Renderer::updateProjectionMatrix(const glm::mat4& projectionMatrix) const
	{
		m_material.getShader().setMat4("projection", projectionMatrix);
	}

	void Renderer::render(const glm::mat4& viewMatrix, const glm::vec3& cameraPosition) const
	{
		auto& shader = m_material.getShader();
		shader.use();
		shader.setMat4("view", viewMatrix);
		shader.setMat4("model", m_transform.getTransformationMatrix());
		shader.setMat3("normalMatrix", m_transform.getNormalMatrix());
		shader.setVec3("cameraPosition", cameraPosition);

		m_model->draw(m_material);
	}

	Renderer* Renderer::clone(Transform& transform) const
	{
		return new Renderer(transform, m_model, m_material);
	}
}
