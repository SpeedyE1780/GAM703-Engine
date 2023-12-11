#ifndef GAM703_ENGINE_CORE_INTERFACES_IRENDERER_HPP
#define GAM703_ENGINE_CORE_INTERFACES_IRENDERER_HPP

#include <glm/mat4x4.hpp>

namespace gam703::engine::core_interface
{
	class IRenderer
	{
	public:
		virtual ~IRenderer() = default;
		virtual void render(const glm::mat4& projectionMatrix, const glm::mat4& viewMatrix) const = 0;
	};
}

#endif // GAM703_ENGINE_CORE_INTERFACES_IRENDERER_HPP
