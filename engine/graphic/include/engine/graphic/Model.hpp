#ifndef GAM703_ENGINE_GRAPHIC_MODEL_HPP
#define GAM703_ENGINE_GRAPHIC_MODEL_HPP

#include <engine/core-interfaces/IMaterial.hpp>
#include <engine/core-interfaces/IModel.hpp>

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
	class ENGINE_GRAPHIC_API Model : public core_interface::IModel
	{
	public:
		Model(const std::vector<Mesh>& meshes);
		virtual void draw(const core_interface::IMaterial& material) const override;

	private:
		std::vector<Mesh> m_meshes;
	};
}

#endif // GAM703_ENGINE_GRAPHIC_MODEL_HPP