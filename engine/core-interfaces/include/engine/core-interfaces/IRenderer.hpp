#ifndef GAM703_ENGINE_CORE_INTERFACES_IRENDERER_HPP
#define GAM703_ENGINE_CORE_INTERFACES_IRENDERER_HPP

#include <engine/core-interfaces/Config.hpp>
#include <engine/core-interfaces/Component.hpp>
#include <engine/core-interfaces/Material.hpp>

#include <glm/mat4x4.hpp>

namespace gam703::engine::core_interface
{
	class ENGINE_CORE_INTERFACES_API IRenderer : public Component
	{
	public:
		IRenderer(Transform* transform);
		IRenderer(Transform* transform, const Material& material);
		virtual ~IRenderer() = default;
		virtual void render(const glm::mat4& viewMatrix, const glm::vec3& cameraPosition) const = 0;
		Material* getMaterial() { return &m_material; }
		const Material* getMaterial() const { return &m_material; }
		virtual void updateProjectionMatrix(const glm::mat4& projectionMatrix) const = 0;

	protected:
		Material m_material{};
	};
}

#endif // GAM703_ENGINE_CORE_INTERFACES_IRENDERER_HPP
