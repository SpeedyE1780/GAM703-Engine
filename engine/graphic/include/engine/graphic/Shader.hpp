#ifndef GAM703_ENGINE_GRAPHIC_SHADER_HPP
#define GAM703_ENGINE_GRAPHIC_SHADER_HPP

#include <engine/core-interfaces/IShader.hpp>

#include <engine/graphic/Config.hpp>

#include <glm/glm.hpp>

#include <string>

namespace gam703::engine::graphic
{
	ENGINE_GRAPHIC_API core_interface::IShader createDefaultShader();
}

#endif //GAM703_ENGINE_GRAPHIC_SHADER_HPP
