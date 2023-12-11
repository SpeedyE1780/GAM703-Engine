#ifndef GAM703_ENGINE_COMPONENTS_RENDERER_HPP
#define GAM703_ENGINE_COMPONENTS_RENDERER_HPP

#include <glm/mat4x4.hpp>
#include <graphic/Model.hpp>
#include <graphic/Shader.hpp>
#include <core-interfaces/IRenderer.hpp>
#include <core-interfaces/IModel.hpp>
#include <components/Config.hpp>
#include <components/IComponent.hpp>

namespace gam703::engine::components
{
	class COMPONENTS_API Renderer : public IComponent, public core_interface::IRenderer
	{
	public:
		Renderer(Transform* transform, const core_interface::IModel* model);
		Renderer(Transform* transform, const core_interface::IModel* model, const graphic::Shader& shader);

		void render(const glm::mat4& projectionMatrix, const glm::mat4& viewMatrix) const;
		void tick(float deltaTime) override {}

	private:
		const core_interface::IModel* m_model;
		graphic::Shader m_shader;
	};
}

#endif // GAM703_ENGINE_COMPONENTS_RENDERER_HPP
