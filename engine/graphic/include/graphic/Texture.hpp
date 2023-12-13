#ifndef GAM703_ENGINE_GRAPHIC_TEXTURE_HPP
#define GAM703_ENGINE_GRAPHIC_TEXTURE_HPP

#include <graphic/Config.hpp>

#include <engine/core-interfaces/ITexture.hpp>

#include <filesystem>

namespace gam703::engine::graphic
{
	class GRAPHIC_API Texture : public core_interface::ITexture
	{
	public:
		Texture(unsigned int id, TextureType type);

		virtual unsigned int getID() const override { return m_id; }
		virtual TextureType getType() const override { return m_type; }

	private:
		unsigned int m_id = 0;
		TextureType m_type = TextureType::Undefined;
	};

	GRAPHIC_API unsigned int loadTextureFromFile(const std::filesystem::path& path);
}

#endif //GAM703_ENGINE_GRAPHIC_TEXTURE_HPP
