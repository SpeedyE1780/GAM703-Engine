#ifndef GAM703_ENGINE_CORE_INTERFACES_ITEXTURE_HPP
#define GAM703_ENGINE_CORE_INTERFACES_ITEXTURE_HPP

namespace gam703::engine::core_interface
{
	class ITexture
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

		virtual ~ITexture() = default;
		virtual unsigned int getID() const = 0;
		virtual TextureType getType() const = 0;
	};
}

#endif // GAM703_ENGINE_CORE_INTERFACES_ITEXTURE_HPP
