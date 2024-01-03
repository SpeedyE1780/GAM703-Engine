#include <engine/core/ResourceManager.hpp>

#include <engine/graphic/Texture.hpp>

#include <iostream>

namespace gam703::engine::core
{
	ResourceManager::ResourceManager() : m_modelLoader(this)
	{
	}

	const core_interface::ITexture* ResourceManager::getTexture(const std::filesystem::path& path, core_interface::ITexture::TextureType type)
	{
		if (auto texture = m_textures.find(path); texture != m_textures.end())
		{
			return texture->second.get();
		}

		if (int textureID = graphic::loadTextureFromFile(path); textureID > 0)
		{
			core_interface::ITexture* texture = new core_interface::ITexture(textureID, type);
			m_textures[path] = std::unique_ptr<core_interface::ITexture>(texture);

			std::cout << "TEXTURE LOADED COUNT: " << m_textures.size() << std::endl;

			return texture;
		}

		std::cout << "ERROR LOADING TEXTURE" << std::endl;
		return 0;
	}

	const core_interface::ITexture* ResourceManager::getWhiteTexture()
	{
		if (auto texture = m_textures.find("__WhiteTexture__"); texture != m_textures.end())
		{
			return texture->second.get();
		}

		if (int textureID = graphic::createWhiteTexture(); textureID > 0)
		{
			core_interface::ITexture* texture = new core_interface::ITexture(textureID, core_interface::ITexture::TextureType::Diffuse);
			m_textures["__WhiteTexture__"] = std::unique_ptr<core_interface::ITexture>(texture);

			std::cout << "TEXTURE LOADED COUNT: " << m_textures.size() << std::endl;

			return texture;
		}

		std::cout << "ERROR LOADING TEXTURE" << std::endl;
		return 0;
	}

	const core_interface::IModel* ResourceManager::getModel(const std::filesystem::path& path)
	{
		if (auto model = m_models.find(path); model != m_models.end())
		{
			return model->second.get();
		}

		if (graphic::Model* model = m_modelLoader.loadModel(path))
		{
			m_models[path] = std::unique_ptr<graphic::Model>(model);

			std::cout << "MODEL LOADED COUNT: " << m_models.size() << std::endl;

			return model;
		}

		std::cout << "ERROR LOADING MODEL" << std::endl;
		return nullptr;
	}
}
