#include <engine/graphic/Shader.hpp>

#include <glad/glad.h>

#include <glm/gtc/type_ptr.hpp>

#include <engine/utility/File.hpp>

#include <iostream>

namespace gam703::engine::graphic
{
	core_interface::IShader createDefaultShader()
	{
		return core_interface::IShader("resources/Shaders/Default.vert", "resources/Shaders/Default.frag");
	}
}
