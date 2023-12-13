#ifndef GAM703_ENGINE_GRAPHIC_MODEL_HPP
#define GAM703_ENGINE_GRAPHIC_MODEL_HPP

#include <engine/core-interfaces/IModel.hpp>
#include <engine/core-interfaces/IShader.hpp>

#include <graphic/Config.hpp>
#include <graphic/Mesh.hpp>
#include <graphic/Shader.fwd.hpp>

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
	class GRAPHIC_API Model : public core_interface::IModel
	{
	public:
		Model(const std::vector<Mesh>& meshes);
		virtual void draw(const core_interface::IShader& shader) const override;

	private:
		std::vector<Mesh> m_meshes;
	};
}

#endif // GAM703_ENGINE_GRAPHIC_MODEL_HPP
