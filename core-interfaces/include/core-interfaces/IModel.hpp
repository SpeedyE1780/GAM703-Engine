#ifndef GAM703_ENGINE_CORE_INTERFACES_MODEL_HPP
#define GAM703_ENGINE_CORE_INTERFACES_MODEL_HPP

#include <core-interfaces/IShader.hpp>

namespace gam703::engine::core_interface
{
	class IModel
	{
	public:
		~IModel() = default;
		virtual void draw(const IShader& shader) const = 0;

	};
}

#endif // GAM703_ENGINE_CORE_INTERFACES_MODEL_HPP
