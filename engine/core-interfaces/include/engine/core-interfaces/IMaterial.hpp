#ifndef GAM703_ENGINE_CORE_INTERFACES_IMATERIAL_HPP
#define GAM703_ENGINE_CORE_INTERFACES_IMATERIAL_HPP

#include <engine/core-interfaces/IShader.hpp>

#include <glm/glm.hpp>

namespace gam703::engine::core_interface
{
	class IMaterial
	{
	public:
		virtual void setColor(const glm::vec3& color) = 0;
		virtual void setDiffuseTexture(int diffuseIndex, int textureIndex) = 0;
		virtual void setSpecularTexture(int specularIndex, int textureIndex) = 0;
		virtual void setNormalTexture(int normalIndex, int textureIndex) = 0;
		virtual void setHeightTexture(int heightIndex, int textureIndex) = 0;
		virtual IShader* getShader() = 0;
		virtual const IShader* getShader() const = 0;
	};
}

#endif // GAM703_ENGINE_CORE_INTERFACES_IMATERIAL_HPP
