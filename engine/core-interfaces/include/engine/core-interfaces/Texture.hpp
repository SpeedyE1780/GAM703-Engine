#ifndef GAM703_ENGINE_CORE_INTERFACES_TEXTURE_HPP
#define GAM703_ENGINE_CORE_INTERFACES_TEXTURE_HPP

#include <engine/core-interfaces/Config.hpp>

namespace gam703::engine::core_interface
{
	class ENGINE_CORE_INTERFACES_API Texture
	{
	public:

		enum class TextureType
		{
			Undefined,
			Diffuse,
			Specular,
			Normal,
			Height
		};

		Texture(unsigned int id, TextureType type);
		unsigned int getID() const { return m_id; }
		TextureType getType() const { return m_type; }

	private:
		unsigned int m_id = 0;
		TextureType m_type = TextureType::Undefined;
	};
}

#endif // GAM703_ENGINE_CORE_INTERFACES_TEXTURE_HPP
