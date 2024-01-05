#ifndef GAM703_ENGINE_CORE_INTERFACES_IRESOURCE_MANAGER_HPP
#define GAM703_ENGINE_CORE_INTERFACES_IRESOURCE_MANAGER_HPP

#include <engine/graphic/Model.hpp>
#include <engine/graphic/Texture.hpp>

#include <filesystem>

namespace gam703::engine::core_interface
{
	class IResourceManager
	{
	public:
		~IResourceManager() = default;
		virtual const graphic::Texture* getTexture(const std::filesystem::path& path, graphic::Texture::TextureType type) = 0;
		virtual const graphic::Texture* getWhiteTexture() = 0;
		virtual const graphic::Model* getModel(const std::filesystem::path& path) = 0;
	};
}

#endif // GAM703_ENGINE_CORE_INTERFACES_IRESOURCE_MANAGER_HPP
