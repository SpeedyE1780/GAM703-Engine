#include <engine/core-interfaces/ITexture.hpp>

namespace gam703::engine::core_interface
{
	ITexture::ITexture(unsigned int id, TextureType type) : m_id(id), m_type(type)
	{
	}
}
