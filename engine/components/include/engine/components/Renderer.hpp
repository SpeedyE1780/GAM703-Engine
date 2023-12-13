#ifndef GAM703_ENGINE_COMPONENTS_RENDERER_HPP
#define GAM703_ENGINE_COMPONENTS_RENDERER_HPP

#include <engine/components/Config.hpp>

#include <engine/core-interfaces/IComponent.hpp>
#include <engine/core-interfaces/IModel.hpp>
#include <engine/core-interfaces/IRenderer.hpp>

#include <engine/graphic/Shader.hpp>

#include <glm/mat4x4.hpp>

namespace gam703::engine::components
{
	class ENGINE_COMPONENTS_API Renderer : public core_interface::IRenderer
	{
	public:
		Renderer(core_interface::ITransform* transform, const core_interface::IModel* model);
		Renderer(core_interface::ITransform* transform, const core_interface::IModel* model, const graphic::Shader& shader);
		~Renderer();

		virtual core_interface::IComponent* clone(core_interface::ITransform* transform) const override;

		void render(const glm::mat4& projectionMatrix, const glm::mat4& viewMatrix) const;
		virtual void tick(float deltaTime) override;

	private:
		const core_interface::IModel* m_model;
		graphic::Shader m_shader;
	};
}

#endif // GAM703_ENGINE_COMPONENTS_RENDERER_HPP
