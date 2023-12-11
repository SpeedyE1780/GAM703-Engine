#ifndef GAM703_ENGINE_CORE_RESOURCE_MANAGER_HPP
#define GAM703_ENGINE_CORE_RESOURCE_MANAGER_HPP

#include <core-interfaces/IResourceManager.hpp>
#include <graphic/Texture.hpp>

#include <map>
#include <memory>

namespace gam703::engine::core
{
	class ResourceManager : public core_interface::IResourceManager
	{
	public:
		ResourceManager() = default;
		~ResourceManager() = default;
		ResourceManager(const ResourceManager& other) = delete;
		ResourceManager& operator=(const ResourceManager& other) = delete;
		
		virtual const core_interface::ITexture* getTexture(const std::filesystem::path& path, graphic::Texture::TextureType type) override;

	private:
		std::map<std::filesystem::path, std::unique_ptr<core_interface::ITexture>> m_textures;
	};
}

#endif // GAM703_ENGINE_CORE_RESOURCE_MANAGER_HPP
