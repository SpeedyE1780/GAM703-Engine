#include <engine/graphic/Shader.hpp>

namespace gam703::engine::graphic
{
	core_interface::Shader createDefaultShader()
	{
		return core_interface::Shader("resources/Shaders/Default.vert", "resources/Shaders/Default.frag");
	}
}
