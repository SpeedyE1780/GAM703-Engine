#ifndef GAM703_ENGINE_GRAPHIC_TEXTURE_HPP
#define GAM703_ENGINE_GRAPHIC_TEXTURE_HPP

#include <engine/graphic/Config.hpp>

#include <filesystem>

namespace gam703::engine::graphic
{
	class ENGINE_GRAPHIC_API Texture
	{
	public:

		enum class TextureType
		{
			Undefined,
			Diffuse,
			Specular,
			Normal,
			Height
		};

		Texture(unsigned int id, TextureType type);
		unsigned int getID() const { return m_id; }
		TextureType getType() const { return m_type; }

	private:
		unsigned int m_id = 0;
		TextureType m_type = TextureType::Undefined;
	};

	ENGINE_GRAPHIC_API unsigned int loadTextureFromFile(const std::filesystem::path& path);
	ENGINE_GRAPHIC_API unsigned int createWhiteTexture();
}

#endif //GAM703_ENGINE_GRAPHIC_TEXTURE_HPP
