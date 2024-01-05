#ifndef GAM703_ENGINE_COMPONENTS_RENDERER_HPP
#define GAM703_ENGINE_COMPONENTS_RENDERER_HPP

#include <engine/components/Config.hpp>
#include <engine/components/Component.hpp>

#include <engine/graphic/Material.hpp>
#include <engine/graphic/Model.hpp>

#include <glm/mat4x4.hpp>

namespace gam703::engine::components
{
	class ENGINE_COMPONENTS_API Renderer : public Component
	{
	public:
		Renderer(Transform* transform, const graphic::Model* model);
		Renderer(Transform* transform, const graphic::Model* model, const graphic::Material& material);
		~Renderer();
		void render(const glm::mat4& viewMatrix, const glm::vec3& cameraPosition) const;
		graphic::Material* getMaterial() { return &m_material; }
		const graphic::Material* getMaterial() const { return &m_material; }
		void updateProjectionMatrix(const glm::mat4& projectionMatrix) const;

		virtual Renderer* clone(Transform* transform) const override;

	protected:
		graphic::Material m_material{};
		const graphic::Model* m_model = nullptr;
	};
}

#endif // GAM703_ENGINE_COMPONENTS_RENDERER_HPP
