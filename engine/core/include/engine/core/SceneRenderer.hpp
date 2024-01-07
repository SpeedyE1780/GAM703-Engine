#ifndef GAM703_ENGINE_CORE_SCENE_RENDERER_HPP
#define GAM703_ENGINE_CORE_SCENE_RENDERER_HPP

#include <engine/components/Camera.hpp>
#include <engine/components/Renderer.hpp>
#include <engine/components/Light.hpp>

#include <engine/core/Config.hpp>

#include <glm/glm.hpp>

#include <vector>

namespace gam703::engine::core
{
	/// @brief SceneRenderer is used to render all scene objects
	class ENGINE_CORE_API SceneRenderer
	{
	public:
		/// @brief Add a new renderer and start rendering it
		/// @param renderer Renderer that will be rendered
		void addRenderer(components::Renderer* renderer);

		/// @brief Remove renderer and stop rendering it
		/// @param sceneObject Renderer that won't be rendered anymore
		void removeRenderer(components::Renderer* sceneObject);

		/// @brief Calculate projection matrix using new aspect ratio
		/// @param aspectRatio The new window aspect ratio
		void calculateProjectionMatrix(float aspectRatio);

		/// @brief Render all renderers in the scene
		void render() const;

		/// @brief Set ambient light color and intensity
		/// @param color Ambient light color
		/// @param intensity Ambient light intensity
		void setAmbientLight(const glm::vec3& color, float intensity);

		/// @brief Set ambient light color
		/// @param color Ambient light color
		void setAmbientLightColor(const glm::vec3& color);

		/// @brief Get ambient light color
		/// @return Ambient light color
		const glm::vec3& getAmbientLightColor() const { return m_ambientLight.m_color; }

		/// @brief Set ambient light intensity
		/// @param intensity Ambient light intensity
		void setAmbientLightIntensity(float intensity);

		/// @brief Get ambient light intensity
		/// @return Ambient light intensity
		float getAmbientLightIntensity() const { return m_ambientLight.m_intensity; }

		/// @brief Add light source that will affect renderers
		/// @param light New light source to be added
		void addLightSource(components::Light* light);

		/// @brief Remove light source that affect renderers
		/// @param light Light source to remove
		void removeLightSource(components::Light* light);

		/// @brief Set the camera rendering the scene
		/// @param camera The new camera being used to render the scene
		void setActiveCamera(components::Camera* camera) { m_activeCamera = camera; }

		/// @brief Get the camera currently used to render the scene
		/// @return The camera currently used to render the scene
		components::Camera* getActiveCamera() { return m_activeCamera; }

		/// @brief Get the camera currently used to render the scene
		/// @return The camera currently used to render the scene
		const components::Camera* getActiveCamera() const { return m_activeCamera; }

	private:
		/// @brief AmbientLight information
		struct AmbientLight
		{
			/// @brief Ambient light color
			glm::vec3 m_color = glm::vec3(1.0f, 1.0f, 1.0f);
			/// @brief Ambient light intensity
			float m_intensity = 0.1f;
		};

		/// @brief Camera being used to render the scene
		components::Camera* m_activeCamera = nullptr;
		/// @brief Check if ambient light needs to be updated
		mutable bool m_shouldUpdateAmbientLight = false;
		/// @brief Ambient light informations
		AmbientLight m_ambientLight{};
		/// @brief Current projection matrix used in vertex shader
		glm::mat4 m_projectionMatrix = glm::mat4(1);
		/// @brief All transforms that needs to be rendered
		std::vector<components::Renderer*> m_sceneObjects{};
		/// @brief All light sources in the scene
		std::vector<components::Light*> m_lightSources{};
	};
}

#endif // GAM703_ENGINE_CORE_SCENE_RENDERER_HPP
