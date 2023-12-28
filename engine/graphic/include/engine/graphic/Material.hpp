#ifndef GAM703_ENGINE_GRAPHIC_MATERIAL_HPP
#define GAM703_ENGINE_GRAPHIC_MATERIAL_HPP

#include <engine/core-interfaces/IMaterial.hpp>

#include <engine/graphic/Config.hpp>
#include <engine/graphic/Shader.hpp>

namespace gam703::engine::graphic
{
	class ENGINE_GRAPHIC_API Material : public core_interface::IMaterial
	{
	public:
		Material();
		Material(const Shader& shader);
		Material(const Material& material);
		Material& operator=(const Material& material);

		virtual void setDiffuseTexture(int diffuseIndex, int textureIndex) const override;
		virtual void setSpecularTexture(int specularIndex, int textureIndex) const override;
		virtual void setNormalTexture(int normalIndex, int textureIndex) const override;
		virtual void setHeightTexture(int heightIndex, int textureIndex) const override;
		virtual void setColor(const glm::vec3& color) override;

		virtual core_interface::IShader* getShader() override { return &m_shader; }
		virtual const core_interface::IShader* getShader() const override { return &m_shader; }

	private:
		Shader m_shader;
		glm::vec3 m_color = glm::vec3(1, 1, 1);
	};
}

#endif // GAM703_ENGINE_GRAPHIC_MATERIAL_HPP