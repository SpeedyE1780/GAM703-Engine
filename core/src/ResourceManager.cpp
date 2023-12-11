#include <core/ResourceManager.hpp>
#include <graphic/Texture.hpp>

#include <iostream>

namespace gam703::engine::core
{
	const core_interface::ITexture* ResourceManager::getTexture(const std::filesystem::path& path, graphic::Texture::TextureType type)
	{
		if (auto texture = m_textures.find(path); texture != m_textures.end())
		{
			return texture->second.get();
		}

		int textureID = graphic::loadTextureFromFile(path);
		graphic::Texture* texture = new graphic::Texture(textureID, type);
		m_textures[path] = std::unique_ptr<graphic::Texture>(texture);

		std::cout << "TEXTURE LOADED COUNT: " << m_textures.size() << std::endl;

		return texture;
	}
}
