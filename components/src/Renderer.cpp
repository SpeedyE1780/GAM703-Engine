#include <components/Renderer.hpp>
#include <components/Transform.hpp>

namespace gam703::engine::components
{
	Renderer::Renderer(Transform* transform, const graphic::Model& model) : IComponent(transform), m_model(model), m_shader(graphic::createDefaultShader())
	{
	}

	Renderer::Renderer(Transform* transform, const graphic::Model& model, const graphic::Shader& shader) : IComponent(transform), m_model(model), m_shader(shader)
	{
	}

	void Renderer::render(const glm::mat4& projectionMatrix, const glm::mat4& viewMatrix) const
	{
		m_shader.use();

		m_shader.setMat4("projection", projectionMatrix);
		m_shader.setMat4("view", viewMatrix);
		m_shader.setMat4("model", m_transform->getTransformationMatrix());

		m_model.draw(m_shader);
	}
}
