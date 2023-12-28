#ifndef GAM703_ENGINE_CORE_INTERFACES_LIGHT_HPP
#define GAM703_ENGINE_CORE_INTERFACES_LIGHT_HPP

#include <engine/core-interfaces/Config.hpp>
#include <engine/core-interfaces/IComponent.hpp>
#include <engine/core-interfaces/IShader.hpp>

#include <glm/glm.hpp>

namespace gam703::engine::core_interface
{
	class ENGINE_CORE_INTERFACES_API ILight : public core_interface::IComponent
	{
	public:
		ILight(core_interface::Transform* transform, const glm::vec3& color, float intensity = 1.0f);
		~ILight() = default;

		const glm::vec3& getColor() const { return m_color; }
		void setColor(const glm::vec3& color) { m_color = color; }

		float getIntensity() const { return m_intensity; }
		void setIntensity(float intensity) { m_intensity = intensity; }

		virtual void updateShaderLightInfo(const IShader& shader) const = 0;

	protected:
		glm::vec3 m_color{ 1.0f, 1.0f, 1.0f };
		float m_intensity = 1.0f;
	};
}

#endif // GAM703_ENGINE_CORE_INTERFACES_LIGHT_HPP
