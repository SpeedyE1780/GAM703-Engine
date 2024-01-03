#ifndef GAM703_ENGINE_GRAPHIC_TEXTURE_HPP
#define GAM703_ENGINE_GRAPHIC_TEXTURE_HPP

#include <engine/graphic/Config.hpp>

#include <filesystem>

namespace gam703::engine::graphic
{
	ENGINE_GRAPHIC_API unsigned int loadTextureFromFile(const std::filesystem::path& path);
	ENGINE_GRAPHIC_API unsigned int createWhiteTexture();
}

#endif //GAM703_ENGINE_GRAPHIC_TEXTURE_HPP
