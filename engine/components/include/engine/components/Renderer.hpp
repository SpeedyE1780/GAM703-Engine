#ifndef GAM703_ENGINE_COMPONENTS_RENDERER_HPP
#define GAM703_ENGINE_COMPONENTS_RENDERER_HPP

#include <engine/components/Config.hpp>
#include <engine/components/Component.hpp>

#include <engine/core-interfaces/IModel.hpp>
#include <engine/core-interfaces/Material.hpp>

#include <glm/mat4x4.hpp>

namespace gam703::engine::components
{
	class ENGINE_COMPONENTS_API Renderer : public Component
	{
	public:
		Renderer(Transform* transform, const core_interface::IModel* model);
		Renderer(Transform* transform, const core_interface::IModel* model, const core_interface::Material& material);
		~Renderer();
		void render(const glm::mat4& viewMatrix, const glm::vec3& cameraPosition) const;
		core_interface::Material* getMaterial() { return &m_material; }
		const core_interface::Material* getMaterial() const { return &m_material; }
		void updateProjectionMatrix(const glm::mat4& projectionMatrix) const;

		virtual Renderer* clone(Transform* transform) const override;

	protected:
		core_interface::Material m_material{};
		const core_interface::IModel* m_model = nullptr;
	};
}

#endif // GAM703_ENGINE_COMPONENTS_RENDERER_HPP
