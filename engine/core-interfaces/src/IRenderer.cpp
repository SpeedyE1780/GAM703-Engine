#include <engine/core-interfaces/IRenderer.hpp>

namespace gam703::engine::core_interface
{
	IRenderer::IRenderer(Transform* transform) : Component(transform)
	{
	}
}
