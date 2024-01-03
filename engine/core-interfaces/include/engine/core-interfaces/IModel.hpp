#ifndef GAM703_ENGINE_CORE_INTERFACES_IMODEL_HPP
#define GAM703_ENGINE_CORE_INTERFACES_IMODEL_HPP

#include <engine/core-interfaces/Material.hpp>

namespace gam703::engine::core_interface
{
	class IModel
	{
	public:
		~IModel() = default;
		virtual void draw(const Material& material) const = 0;

	};
}

#endif // GAM703_ENGINE_CORE_INTERFACES_IMODEL_HPP
