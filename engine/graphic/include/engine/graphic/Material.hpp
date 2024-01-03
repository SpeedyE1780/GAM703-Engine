#ifndef GAM703_ENGINE_GRAPHIC_MATERIAL_HPP
#define GAM703_ENGINE_GRAPHIC_MATERIAL_HPP

#include <engine/core-interfaces/IMaterial.hpp>

#include <engine/graphic/Config.hpp>
#include <engine/graphic/Shader.hpp>

namespace gam703::engine::graphic
{
	class ENGINE_GRAPHIC_API Material : public core_interface::Material
	{
	public:
		Material();
		Material(const Shader& shader);
		Material(const Material& material);
		Material& operator=(const Material& material);

		virtual core_interface::IShader* getShader() override { return &m_shader; }
		virtual const core_interface::IShader* getShader() const override { return &m_shader; }

	private:
		Shader m_shader;
	};
}

#endif // GAM703_ENGINE_GRAPHIC_MATERIAL_HPP
