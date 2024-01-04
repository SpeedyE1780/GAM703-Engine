#ifndef GAM703_ENGINE_COMPONENTS_RENDERER_HPP
#define GAM703_ENGINE_COMPONENTS_RENDERER_HPP

#include <engine/components/Config.hpp>

#include <engine/core-interfaces/Component.hpp>
#include <engine/core-interfaces/IModel.hpp>
#include <engine/core-interfaces/IRenderer.hpp>

#include <glm/mat4x4.hpp>

namespace gam703::engine::components
{
	class ENGINE_COMPONENTS_API Renderer : public core_interface::IRenderer
	{
	public:
		Renderer(core_interface::Transform* transform, const core_interface::IModel* model);
		Renderer(core_interface::Transform* transform, const core_interface::IModel* model, const core_interface::Material& material);
		~Renderer();

		virtual core_interface::Component* clone(core_interface::Transform* transform) const override;

		virtual void render(const glm::mat4& viewMatrix, const glm::vec3& cameraPosition) const override;
		virtual void tick(float deltaTime) override;

		virtual core_interface::Material* getMaterial() override { return &m_material; }
		virtual const core_interface::Material* getMaterial() const override { return &m_material; }

		virtual void updateProjectionMatrix(const glm::mat4& projectionMatrix) const override;

	private:
		const core_interface::IModel* m_model;
		core_interface::Material m_material;
	};
}

#endif // GAM703_ENGINE_COMPONENTS_RENDERER_HPP
