#include <engine/core-interfaces/IRenderer.hpp>

namespace gam703::engine::core_interface
{
	IRenderer::IRenderer(Transform* transform) : Component(transform)
	{
	}

	IRenderer::IRenderer(Transform* transform, const Material& material) : Component(transform), m_material(material)
	{
	}
}
