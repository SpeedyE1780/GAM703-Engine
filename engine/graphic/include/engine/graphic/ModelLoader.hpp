#ifndef GAM703_ENGINE_GRAPHIC_MODEL_LOADER_HPP
#define GAM703_ENGINE_GRAPHIC_MODEL_LOADER_HPP

#include <engine/core/ResourceManager.fwd.hpp>
#include <engine/graphic/Texture.hpp>

#include <engine/graphic/Config.hpp>
#include <engine/graphic/Model.hpp>

#include <filesystem>

namespace gam703::engine::graphic
{
	/// @brief ModelLoader loads model from file and adds them to resource manager
	class ENGINE_GRAPHIC_API ModelLoader
	{
	public:
		/// @brief Create a model loader
		/// @param resourceManager ResourceManager where models needs to be added
		ModelLoader(core::ResourceManager& resourceManager);

		/// @brief Load model from file path
		/// @param path File path where model is located
		/// @return Loaded model pointer
		Model* loadModel(const std::filesystem::path& path);

		/// @brief Process aiNode and children and push back meshes
		/// @param meshes Meshes where new mesh are pushed
		/// @param node Contains mehses info and subnodes
		/// @param scene Contains all meshes
		void processNode(std::vector<Mesh>& meshes, const aiNode* node, const aiScene* scene);

		/// @brief Load mesh from aiMesh and return it
		/// @param mesh Contains vertices, faces and material information
		/// @param scene Contains material information
		/// @return New Mesh constructed from aiMesh
		Mesh processMesh(const aiMesh* mesh, const aiScene* scene);

		/// @brief Load texture from material
		/// @param textures textures vector where loaded texture is added
		/// @param mat Material containing the textures
		/// @param type Texture Type (eg: Diffuse, Specular, Height, Normal)
		void loadMaterialTextures(std::vector<const Texture*>& textures, const aiMaterial* mat, aiTextureType type);

	private:
		/// @brief ResourceManager where models are added
		core::ResourceManager& m_resourceManager;
		/// @brief Current model directory to look for textures
		std::filesystem::path m_currentDirectory;
	};
}

#endif // GAM703_ENGINE_GRAPHIC_MODEL_LOADER_HPP
