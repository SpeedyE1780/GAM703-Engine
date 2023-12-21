#ifndef GAM703_ENGINE_CORE_INTERFACES_IRENDERER_HPP
#define GAM703_ENGINE_CORE_INTERFACES_IRENDERER_HPP

#include <engine/core-interfaces/Config.hpp>
#include <engine/core-interfaces/IComponent.hpp>
#include <engine/core-interfaces/IMaterial.hpp>

#include <glm/mat4x4.hpp>

namespace gam703::engine::core_interface
{
	class ENGINE_CORE_INTERFACES_API IRenderer : public IComponent
	{
	public:
		IRenderer(ITransform* transform);
		virtual ~IRenderer() = default;
		virtual void render(const glm::mat4& projectionMatrix, const glm::mat4& viewMatrix) const = 0;
		virtual  IMaterial* getMaterial() = 0;
		virtual const IMaterial* getMaterial() const = 0;
	};
}

#endif // GAM703_ENGINE_CORE_INTERFACES_IRENDERER_HPP
