#include <engine/core/ResourceManager.hpp>

#include <engine/graphic/Texture.hpp>

#include <engine/utility/File.hpp>

#include <glad/glad.h>

#include <iostream>

namespace gam703::engine::core
{
	ResourceManager::ResourceManager() : m_modelLoader(*this)
	{
	}

	const graphic::Texture* ResourceManager::getTexture(const std::filesystem::path& path, graphic::Texture::TextureType type)
	{
		if (auto texture = m_textures.find(path); texture != m_textures.end())
		{
			return texture->second.get();
		}

		if (int textureID = graphic::loadTextureFromFile(path); textureID > 0)
		{
			graphic::Texture* texture = new graphic::Texture(textureID, type);
			m_textures[path] = std::unique_ptr<graphic::Texture>(texture);

			std::cout << "TEXTURE LOADED COUNT: " << m_textures.size() << std::endl;

			return texture;
		}

		std::cout << "ERROR LOADING TEXTURE" << std::endl;
		return nullptr;
	}

	const graphic::Texture* ResourceManager::getWhiteTexture()
	{
		if (auto texture = m_textures.find("__WhiteTexture__"); texture != m_textures.end())
		{
			return texture->second.get();
		}

		if (int textureID = graphic::createWhiteTexture(); textureID > 0)
		{
			graphic::Texture* texture = new graphic::Texture(textureID, graphic::Texture::TextureType::Diffuse);
			m_textures["__WhiteTexture__"] = std::unique_ptr<graphic::Texture>(texture);

			std::cout << "TEXTURE LOADED COUNT: " << m_textures.size() << std::endl;

			return texture;
		}

		std::cout << "ERROR LOADING TEXTURE" << std::endl;
		return nullptr;
	}

	const graphic::Model* ResourceManager::getModel(const std::filesystem::path& path)
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

	graphic::Shader* ResourceManager::getShader(const std::filesystem::path& vertexSource, const std::filesystem::path& fragmentSource)
	{
		std::string key = vertexSource.string() + fragmentSource.string();

		if (auto shader = m_shaders.find(key); shader != m_shaders.end())
		{
			return shader->second.get();
		}

		auto* shader = new graphic::Shader(getShaderSource(vertexSource, GL_VERTEX_SHADER), getShaderSource(fragmentSource, GL_FRAGMENT_SHADER));
		m_shaders[key] = std::unique_ptr<graphic::Shader>(shader);
		return shader;
	}

	graphic::Shader* ResourceManager::getDefaultShader()
	{
		return getShader("resources/Shaders/Default.vert", "resources/Shaders/Default.frag");
	}

	graphic::ShaderSource* ResourceManager::getShaderSource(const std::filesystem::path& shaderSourcePath, int shaderType)
	{
		if (auto shaderSource = m_shaderSources.find(shaderSourcePath); shaderSource != m_shaderSources.end())
		{
			return shaderSource->second.get();
		}

		graphic::ShaderSource* shaderSource = new graphic::ShaderSource(utility::readFile(shaderSourcePath), shaderType);
		m_shaderSources[shaderSourcePath] = std::unique_ptr<graphic::ShaderSource>(shaderSource);
		std::cout << "SHADER SOURCE LOADED COUNT: " << m_shaderSources.size() << std::endl;

		return shaderSource;
	}
}
