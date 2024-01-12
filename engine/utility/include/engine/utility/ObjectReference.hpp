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
		/// @brief Create a reference to the object and add this reference to the list of observers
		/// @param pointer The object that is being referenced
		explicit ObjectReference(Object* pointer) : m_pointer(pointer)
		{
			if (m_pointer)
			{
				m_pointer->addObjectReference(this);
			}
		}

		/// @brief Create a reference to the object's pointer and add this reference to the list of observers 
		/// @param object The object who's pointer will be referenced
		ObjectReference(const ObjectReference& object) : m_pointer(object.m_pointer)
		{
			if (m_pointer)
			{
				m_pointer->addObjectReference(this);
			}
		}

		/// @brief Clear the old pointer and then reference object's pointer
		/// @param object The object who's pointer will be referenced
		/// @return ObjectReference referencing object's pointer
		ObjectReference& operator=(const ObjectReference& object)
		{
			if (m_pointer)
			{
				m_pointer->removeObjectReference(this);
			}

			m_pointer = object.m_pointer;
			m_pointer->addObjectReference(this);

			return *this;
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

		/// @brief Dereference ObjectReference's Object&
		/// @return The referenced Object
		Object& operator*()
		{
			return *m_pointer;
		}

		/// @brief Dereference ObjectReference's Object&
		/// @return The referenced Object
		const Object& operator*() const
		{
			return *m_pointer;
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
