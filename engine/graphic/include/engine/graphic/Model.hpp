#ifndef GAM703_ENGINE_GRAPHIC_MODEL_HPP
#define GAM703_ENGINE_GRAPHIC_MODEL_HPP

#include <engine/graphic/Config.hpp>
#include <engine/graphic/Mesh.hpp>

#include <string>
#include <vector>
#include <filesystem>

struct aiNode;
struct aiMesh;
struct aiScene;
struct aiMaterial;
enum aiTextureType;

namespace gam703::engine::graphic
{
	/// @brief Model contains Meshes to create 3D object
	class ENGINE_GRAPHIC_API Model
	{
	public:
		/// @brief Create Model using Mesh vector
		/// @param meshes Meshes creating Model
		Model(const std::vector<Mesh>& meshes);

		/// @brief Draw model on screen
		/// @param material Material used to set texture indices
		void draw(const Material& material) const;

	private:
		/// @brief Meshes creating model
		std::vector<Mesh> m_meshes;
	};
}

#endif // GAM703_ENGINE_GRAPHIC_MODEL_HPP
