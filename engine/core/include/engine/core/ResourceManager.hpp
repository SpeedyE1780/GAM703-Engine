#ifndef GAM703_ENGINE_CORE_RESOURCE_MANAGER_HPP
#define GAM703_ENGINE_CORE_RESOURCE_MANAGER_HPP

#include <engine/core-interfaces/IResourceManager.hpp>

#include <engine/graphic/ModelLoader.hpp>

#include <map>
#include <memory>

namespace gam703::engine::core
{
	class ResourceManager : public core_interface::IResourceManager
	{
	public:
		ResourceManager();
		~ResourceManager() = default;
		ResourceManager(const ResourceManager& other) = delete;
		ResourceManager& operator=(const ResourceManager& other) = delete;
		
		virtual const graphic::Texture* getTexture(const std::filesystem::path& path, graphic::Texture::TextureType type) override;
		virtual const graphic::Texture* getWhiteTexture() override;
		virtual const graphic::Model* getModel(const std::filesystem::path& path) override;

	private:
		graphic::ModelLoader m_modelLoader;
		std::map<std::filesystem::path, std::unique_ptr<graphic::Texture>> m_textures{};
		std::map<std::filesystem::path, std::unique_ptr<graphic::Model>> m_models{};
	};
}

#endif // GAM703_ENGINE_CORE_RESOURCE_MANAGER_HPP
