#ifndef GAM703_ENGINE_GRAPHIC_MODEL_LOADER_HPP
#define GAM703_ENGINE_GRAPHIC_MODEL_LOADER_HPP

#include <core-interfaces/IResourceManager.hpp>
#include <graphic/Config.hpp>
#include <graphic/Model.hpp>

#include <filesystem>

namespace gam703::engine::graphic
{
	class GRAPHIC_API ModelLoader
	{
	public:
		ModelLoader(core_interface::IResourceManager* resourceManager);

		Model* loadModel(const std::filesystem::path& path);
		void processNode(std::vector<Mesh>& meshes, const aiNode* node, const aiScene* scene);
		Mesh processMesh(const aiMesh* mesh, const aiScene* scene);
		void loadMaterialTextures(std::vector<const core_interface::ITexture*>& textures, const aiMaterial* mat, aiTextureType type);

	private:
		core_interface::IResourceManager* m_resourceManager;
		std::filesystem::path m_currentDirectory;
	};
}

#endif // GAM703_ENGINE_GRAPHIC_MODEL_LOADER_HPP
