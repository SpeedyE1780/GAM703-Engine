#include <components/Renderer.hpp>

namespace gam703::engine::components
{
	Renderer::Renderer(const graphic::Model& model) : m_model(model), m_shader(graphic::createDefaultShader())
	{
	}

	Renderer::Renderer(const graphic::Model& model, const graphic::Shader& shader) : m_model(model), m_shader(shader)
	{
	}
}
