#ifndef GAM703_ENGINE_CORE_INTERFACES_IRESOURCE_MANAGER_HPP
#define GAM703_ENGINE_CORE_INTERFACES_IRESOURCE_MANAGER_HPP

#include <engine/core-interfaces/IModel.hpp>
#include <engine/core-interfaces/Texture.hpp>

#include <filesystem>

namespace gam703::engine::core_interface
{
	class IResourceManager
	{
	public:
		~IResourceManager() = default;
		virtual const Texture* getTexture(const std::filesystem::path& path, Texture::TextureType type) = 0;
		virtual const Texture* getWhiteTexture() = 0;
		virtual const IModel* getModel(const std::filesystem::path& path) = 0;
	};
}

#endif // GAM703_ENGINE_CORE_INTERFACES_IRESOURCE_MANAGER_HPP
