#ifndef GAM703_ENGINE_GRAPHIC_TEXTURE_HPP
#define GAM703_ENGINE_GRAPHIC_TEXTURE_HPP

#include <filesystem>

namespace gam703::engine::graphic
{
	unsigned int loadTextureFromFile(const std::filesystem::path& path);
}

#endif //GAM703_ENGINE_GRAPHIC_TEXTURE_HPP
