#ifndef GAM703_ENGINE_COMPONENTS_RENDERER_HPP
#define GAM703_ENGINE_COMPONENTS_RENDERER_HPP

#include <engine/components/Config.hpp>
#include <engine/components/Component.hpp>

#include <engine/graphic/Material.hpp>
#include <engine/graphic/Model.hpp>

#include <glm/mat4x4.hpp>

namespace gam703::engine::components
{
	/// @brief Renderer is used to Render the scene object 3D model
	class ENGINE_COMPONENTS_API Renderer : public Component
	{
	public:
		/// @brief Create a renderer that is owned by the transform and add it to the SceneRenderer
		/// @param transform The Transform owning this component
		/// @param model The model that will be rendered
		Renderer(Transform& transform, const graphic::Model* model);

		/// @brief Create a renderer that is owned by the transform and add it to the SceneRenderer
		/// @param transform The Transform owning this component
		/// @param model The model that will be rendered
		/// @param material The material that will be used to render
		Renderer(Transform& transform, const graphic::Model* model, const graphic::Material& material);

		/// @brief Remove Renderer from SceneRenderer
		~Renderer();

		/// @brief Render the 3D model to the screen
		/// @param viewMatrix The view matrix used in the vertex shader
		/// @param cameraPosition The view position used for light reflection calculations
		void render(const glm::mat4& viewMatrix, const glm::vec3& cameraPosition) const;

		/// @brief Get the material used
		/// @return The material used
		graphic::Material& getMaterial() { return m_material; }

		/// @brief Get the material used
		/// @return The material used
		const graphic::Material& getMaterial() const { return m_material; }

		/// @brief Update the projection matrix after a changed in active camera or Window size
		/// @param projectionMatrix The new projection matrix
		void updateProjectionMatrix(const glm::mat4& projectionMatrix) const;

		/// @brief Create a copy attached to the new transform
		/// @param transform The new transform that will own the clone
		/// @return The cloned Renderer belonging to the transform
		virtual Renderer* clone(Transform& transform) const override;

	protected:
		/// @brief The material used to set the model properties (eg: Color, Diffuse, Specular...)
		graphic::Material m_material;
		/// @brief The 3D model being currently rendered
		const graphic::Model* m_model = nullptr;
	};
}

#endif // GAM703_ENGINE_COMPONENTS_RENDERER_HPP
