#include <engine/utility/ObjectReference.hpp>
#include <engine/utility/ReferencedObject.hpp>

#include <gtest/gtest.h>

#include <memory>

namespace gam703::engine::utility::tests
{
	class ObjectTest : public ReferencedObject<ObjectTest>
	{
	public:
		ObjectTest() : ReferencedObject<ObjectTest>(this)
		{
		}

		int value = 0;
	};

	TEST(ObjectReferenceTest, AccessValue)
	{
		ObjectTest obj;
		auto ref = obj.getReference();

		EXPECT_TRUE(ref);
		EXPECT_EQ(obj.value, ref->value);
	}

	TEST(ObjectReferenceTest, ModifyValue)
	{
		ObjectTest obj;
		auto ref = obj.getReference();

		ASSERT_TRUE(ref);
		ASSERT_EQ(obj.value, ref->value);

		obj.value = 2;
		EXPECT_EQ(obj.value, ref->value);

		ref->value = 3;
		EXPECT_EQ(obj.value, ref->value);
	}

	TEST(ObjectReferenceTest, NullifyReference)
	{
		auto ref = std::unique_ptr<ObjectReference<ObjectTest>>();

		{
			ObjectTest obj;
			auto ref = obj.getReference();

			ASSERT_TRUE(ref);
			ASSERT_EQ(obj.value, ref->value);

			obj.value = 2;
			ASSERT_EQ(obj.value, ref->value);

			ref->value = 3;
			ASSERT_EQ(obj.value, ref->value);
		}

		EXPECT_FALSE(ref);
	}
}
