#ifndef GAM703_ENGINE_CORE_INTERFACES_RENDERER_HPP
#define GAM703_ENGINE_CORE_INTERFACES_RENDERER_HPP

#include <engine/core-interfaces/Config.hpp>
#include <engine/core-interfaces/Component.hpp>
#include <engine/core-interfaces/IModel.hpp>
#include <engine/core-interfaces/Material.hpp>

#include <glm/mat4x4.hpp>

namespace gam703::engine::core_interface
{
	class ENGINE_CORE_INTERFACES_API Renderer : public Component
	{
	public:
		Renderer(Transform* transform, const core_interface::IModel* model);
		Renderer(Transform* transform, const core_interface::IModel* model, const Material& material);
		~Renderer();
		void render(const glm::mat4& viewMatrix, const glm::vec3& cameraPosition) const;
		Material* getMaterial() { return &m_material; }
		const Material* getMaterial() const { return &m_material; }
		void updateProjectionMatrix(const glm::mat4& projectionMatrix) const;

		virtual Renderer* clone(core_interface::Transform* transform) const override;

	protected:
		Material m_material{};
		const IModel* m_model = nullptr;
	};
}

#endif // GAM703_ENGINE_CORE_INTERFACES_RENDERER_HPP
