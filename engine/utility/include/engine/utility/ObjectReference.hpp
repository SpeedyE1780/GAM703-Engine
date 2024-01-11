#ifndef GAM703_ENGINE_UTILITY_OBJECT_REFERENCE_HPP
#define GAM703_ENGINE_UTILITY_OBJECT_REFERENCE_HPP

namespace gam703::engine::utility
{
	/// @brief ObjectReference is used to track an Object reference and will be nullified once the object is destroyed using the observer pattern
	/// @tparam Object The type of object that is being referenced
	template<class Object>
	class ObjectReference
	{
	public:
		/// @brief Assign the object that is being referenced
		/// @param pointer The object that is being referenced
		ObjectReference(Object* pointer) : m_pointer(pointer)
		{
		}

		/// @brief Remove the object reference from the list of observers
		~ObjectReference()
		{
			if (m_pointer)
			{
				m_pointer->removeObjectReference(this);
			}
		}

		/// @brief Nullify the pointer since it has been destroyed
		void nullify()
		{
			m_pointer = nullptr;
		}

		/// @brief Allow access to the Object methods
		/// @return The Object
		Object* operator->()
		{
			return m_pointer;
		}

		/// @brief Allow access to the Object methods
		/// @return The Object
		const Object* operator->() const
		{
			return m_pointer;
		}

		/// @brief Check if m_pointer still points to a valid address
		explicit operator bool() const
		{
			return m_pointer;
		}

	private:
		/// @brief The object that is being tracked by this class
		Object* m_pointer;
	};
}

#endif // GAM703_ENGINE_UTILITY_OBJECT_REFERENCE_HPP
