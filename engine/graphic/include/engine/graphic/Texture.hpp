#ifndef GAM703_ENGINE_GRAPHIC_TEXTURE_HPP
#define GAM703_ENGINE_GRAPHIC_TEXTURE_HPP

#include <engine/core-interfaces/ITexture.hpp>

#include <engine/graphic/Config.hpp>

#include <filesystem>

namespace gam703::engine::graphic
{
	class ENGINE_GRAPHIC_API Texture : public core_interface::ITexture
	{
	public:
		Texture(unsigned int id, TextureType type);

		virtual unsigned int getID() const override { return m_id; }
		virtual TextureType getType() const override { return m_type; }

	private:
		unsigned int m_id = 0;
		TextureType m_type = TextureType::Undefined;
	};

	ENGINE_GRAPHIC_API unsigned int loadTextureFromFile(const std::filesystem::path& path);
	ENGINE_GRAPHIC_API unsigned int createWhiteTexture();
}

#endif //GAM703_ENGINE_GRAPHIC_TEXTURE_HPP
