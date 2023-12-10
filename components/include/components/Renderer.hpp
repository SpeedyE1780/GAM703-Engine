#ifndef GAM703_ENGINE_COMPONENTS_RENDERER_HPP
#define GAM703_ENGINE_COMPONENTS_RENDERER_HPP

#include <graphic/Model.hpp>
#include <graphic/Shader.hpp>
#include <components/IComponent.hpp>

namespace gam703::engine::components
{
	class Renderer
	{
	public:
		Renderer(const graphic::Model& model);
		Renderer(const graphic::Model& model, const graphic::Shader& shader);

	private:
		graphic::Model m_model;
		graphic::Shader m_shader;
	};
}

#endif // GAM703_ENGINE_COMPONENTS_RENDERER_HPP
