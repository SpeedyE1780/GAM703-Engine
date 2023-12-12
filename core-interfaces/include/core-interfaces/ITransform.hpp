#ifndef GAM703_ENGINE_CORE_INTERFACES_ITRANSFORM_HPP
#define GAM703_ENGINE_CORE_INTERFACES_ITRANSFORM_HPP

#include <core-interfaces/IScene.hpp>

#include <glm/glm.hpp>

namespace gam703::engine::core_interface
{
	class ITransform
	{
	public:
		virtual ~ITransform() = default;

		virtual ITransform* clone() const = 0;

		virtual const glm::vec3& getPosition() const = 0;
		virtual const glm::vec3& getRotation() const = 0;
		virtual const glm::vec3& getScale() const = 0;
		virtual const glm::mat4& getTransformationMatrix() const = 0;
		virtual const glm::vec3& getFront() const = 0;
		virtual const glm::vec3& getRight() const = 0;
		virtual const glm::vec3& getUp() const = 0;

		virtual void calculateTransformMatrix() = 0;

		virtual void setPosition(const glm::vec3& position) = 0;
		virtual void setPosition(float x, float y, float z) = 0;
		virtual void setRotation(const glm::vec3& eulerAngles) = 0;
		virtual void setRotation(float x, float y, float z) = 0;
		virtual void setScale(const glm::vec3& scale) = 0;
		virtual void setScale(float x, float y, float z) = 0;

		virtual void translate(const glm::vec3& offset) = 0;
		virtual void translate(float x, float y, float z) = 0;
		virtual void rotate(const glm::vec3& eulerAngles) = 0;
		virtual void rotate(float x, float y, float z) = 0;

		virtual IEngine* getEngine() = 0;
		virtual const IEngine* getEngine() const = 0;

		virtual IScene* getScene() = 0;
		virtual const IScene* getScene() const = 0;
	};
}

#endif // GAM703_ENGINE_CORE_INTERFACES_ITRANSFORM_HPP
