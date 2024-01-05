#ifndef GAM703_ENGINE_COMPONENTS_LIGHT_HPP
#define GAM703_ENGINE_COMPONENTS_LIGHT_HPP

#include <engine/components/Config.hpp>
#include <engine/components/Component.hpp>

#include <engine/core-interfaces/Shader.hpp>

#include <glm/glm.hpp>

namespace gam703::engine::components
{
	class ENGINE_COMPONENTS_API Light : public Component
	{
	public:
		Light(Transform* transform, const glm::vec3& color, float intensity = 1.0f);
		virtual ~Light();

		const glm::vec3& getColor() const { return m_color; }
		void setColor(const glm::vec3& color) { m_color = color; }

		float getIntensity() const { return m_intensity; }
		void setIntensity(float intensity) { m_intensity = intensity; }

		virtual void updateShaderLightInfo(const core_interface::Shader& shader) const = 0;

	protected:
		glm::vec3 m_color{ 1.0f, 1.0f, 1.0f };
		float m_intensity = 1.0f;
	};
}

#endif // GAM703_ENGINE_COMPONENTS_LIGHT_HPP
