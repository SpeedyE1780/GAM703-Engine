#ifndef GAM703_ENGINE_COMPONENTS_RENDERER_HPP
#define GAM703_ENGINE_COMPONENTS_RENDERER_HPP

#include <glm/mat4x4.hpp>
#include <graphic/Model.hpp>
#include <graphic/Shader.hpp>
#include <core-interfaces/IRenderer.hpp>
#include <core-interfaces/IModel.hpp>
#include <components/Config.hpp>
#include <core-interfaces/IComponent.hpp>

namespace gam703::engine::components
{
	class COMPONENTS_API Renderer : public core_interface::IRenderer
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
