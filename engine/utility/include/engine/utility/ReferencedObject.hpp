#ifndef GAM703_ENGINE_UTILITY_REFERENCED_OBJECT_HPP
#define GAM703_ENGINE_UTILITY_REFERENCED_OBJECT_HPP

#include <engine/utility/ObjectReference.hpp>

#include <vector>

namespace gam703::engine::utility
{
	/// @brief ReferencedObject is used to track all class referencing the ObjectType.
	/// ReferencedObject will nullify all pointers to it to avoid undefined behavior by accessing freed memory
	/// @tparam ObjectType The type of object that is being referenced
	template<class ObjectType>
	class ReferencedObject
	{
	public:
		/// @brief Contruct the ReferencedObject and assign the ObjectType pointer
		/// @param object The object that will be referenced by other classes
		ReferencedObject(ObjectType* object) : m_object(object)
		{
		}

		/// @brief Nullify all references to this object using the observer pattern
		~ReferencedObject()
		{
			for (auto* reference : m_references)
			{
				reference->nullify();
			}
		}

		/// @brief Get a reference to object and add it to the list of references using ObjectReference's constructor
		/// @return A reference to object
		ObjectReference<ObjectType> getReference()
		{
			return ObjectReference<ObjectType>(m_object);
		}

		/// @brief Add a reference to the list of references
		/// @param ref The ObjectReference that will be added
		void addObjectReference(ObjectReference<ObjectType>* ref)
		{
			m_references.push_back(ref);
		}

		/// @brief Remove the object reference from the list of references once it's deleted
		/// @param ref The ObjectReference that is currently being deleted
		void removeObjectReference(ObjectReference<ObjectType>* ref)
		{
			auto newEnd = std::remove(begin(m_references), end(m_references), ref);
			m_references.erase(newEnd, end(m_references));
		}

	private:
		/// @brief The object that is being referenced by others
		ObjectType* m_object;
		/// @brief A list of all references to m_object
		std::vector<ObjectReference<ObjectType>*> m_references{};
	};
}

#endif // GAM703_ENGINE_UTILITY_REFERENCED_OBJECT_HPP
