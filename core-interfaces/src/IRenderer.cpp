#include <core-interfaces/IRenderer.hpp>

namespace gam703::engine::core_interface
{
	IRenderer::IRenderer(ITransform* transform) :IComponent(transform)
	{
	}
}
