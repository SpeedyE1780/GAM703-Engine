#ifndef GAM703_ENGINE_CORE_SCENE_HPP
#define GAM703_ENGINE_CORE_SCENE_HPP

#include <engine/core/Config.hpp>
#include <engine/core/Engine.fwd.hpp>

#include <engine/core-interfaces/IScene.hpp>
#include <engine/core-interfaces/Transform.hpp>

#include <vector>

namespace gam703::engine::core
{

	class ENGINE_CORE_API Scene : public core_interface::IScene
	{
	public:
		Scene(Engine* engine);
		Scene(const Scene&) = delete;
		Scene& operator=(const Scene&) = delete;
	};
}

#endif // GAM703_ENGINE_CORE_SCENE_HPP
