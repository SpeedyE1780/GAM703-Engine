#ifndef GAM703_ENGINE_CORE_RESOURCE_MANAGER_HPP
#define GAM703_ENGINE_CORE_RESOURCE_MANAGER_HPP

#include <core-interfaces/IResourceManager.hpp>
#include <graphic/ModelLoader.hpp>
#include <graphic/Texture.hpp>

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
		
		virtual const core_interface::ITexture* getTexture(const std::filesystem::path& path, graphic::Texture::TextureType type) override;
		virtual const core_interface::IModel* getModel(const std::filesystem::path& path) override;

	private:
		graphic::ModelLoader m_modelLoader;
		std::map<std::filesystem::path, std::unique_ptr<core_interface::ITexture>> m_textures{};
		std::map<std::filesystem::path, std::unique_ptr<core_interface::IModel>> m_models{};
	};
}

#endif // GAM703_ENGINE_CORE_RESOURCE_MANAGER_HPP
