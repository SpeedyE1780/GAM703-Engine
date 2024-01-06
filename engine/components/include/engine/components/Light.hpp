#ifndef GAM703_ENGINE_COMPONENTS_LIGHT_HPP
#define GAM703_ENGINE_COMPONENTS_LIGHT_HPP

#include <engine/components/Config.hpp>
#include <engine/components/Component.hpp>

#include <engine/graphic/Shader.hpp>

#include <glm/glm.hpp>

namespace gam703::engine::components
{
	/// @brief Light is the base class for all light sources
	class ENGINE_COMPONENTS_API Light : public Component
	{
	public:
		/// @brief Create a light that is owned by the transform and adds it to the scene renderer
		/// @param transform The Transform owning this component
		/// @param color The light color
		/// @param intensity The light intensity
		Light(Transform& transform, const glm::vec3& color, float intensity = 1.0f);

		/// @brief Remove the light source from the scene renderer
		virtual ~Light();

		/// @brief Get the light color
		/// @return The light color
		const glm::vec3& getColor() const { return m_color; }

		/// @brief Set the light color
		/// @param color The new light color
		void setColor(const glm::vec3& color) { m_color = color; }

		/// @brief Get the light intensity
		/// @return The light intensity
		float getIntensity() const { return m_intensity; }

		/// @brief Set the light intensity
		/// @param intensity The new light intensity
		void setIntensity(float intensity) { m_intensity = intensity; }

		/// @brief Update the shader corresponding lights uniforms
		/// @param shader The shader of the object being rendered
		virtual void updateShaderLightInfo(const graphic::Shader& shader) const = 0;

	protected:
		/// @brief The light color
		glm::vec3 m_color{ 1.0f, 1.0f, 1.0f };
		/// @brief The light intensity
		float m_intensity = 1.0f;
	};
}

#endif // GAM703_ENGINE_COMPONENTS_LIGHT_HPP
