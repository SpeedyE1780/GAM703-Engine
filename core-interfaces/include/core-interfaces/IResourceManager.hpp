#ifndef GAM703_ENGINE_CORE_INTERFACES_IRESOURCE_MANAGER_HPP
#define GAM703_ENGINE_CORE_INTERFACES_IRESOURCE_MANAGER_HPP

#include <core-interfaces/ITexture.hpp>

#include <filesystem>

namespace gam703::engine::core_interface
{
	class IResourceManager
	{
	public:
		~IResourceManager() = default;
		virtual const ITexture* getTexture(const std::filesystem::path& path, ITexture::TextureType type) = 0;
	};
}

#endif // GAM703_ENGINE_CORE_INTERFACES_IRESOURCE_MANAGER_HPP
