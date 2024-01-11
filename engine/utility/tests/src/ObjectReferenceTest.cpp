#include <engine/utility/ObjectReference.hpp>
#include <engine/utility/ReferencedObject.hpp>

#include <gtest/gtest.h>

#include <memory>

namespace gam703::engine::utility::tests
{
	class ObjectTest : public ReferencedObject<ObjectTest>
	{
	public:
		ObjectTest(int v = 0) : ReferencedObject<ObjectTest>(this), value(v)
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
		auto ref = ObjectReference<ObjectTest>(nullptr);

		{
			ObjectTest obj;
			ref = obj.getReference();

			ASSERT_TRUE(ref);
			ASSERT_EQ(obj.value, ref->value);

			obj.value = 2;
			ASSERT_EQ(obj.value, ref->value);

			ref->value = 3;
			ASSERT_EQ(obj.value, ref->value);
		}

		EXPECT_FALSE(ref);
	}

	TEST(ObjectReferenceTest, ObjectReferenceCopyConstructor)
	{
		ObjectTest obj{ 3 };
		auto ref = obj.getReference();

		ASSERT_EQ(obj.value, ref->value);

		auto ref2{ ref };

		EXPECT_EQ(obj.value, ref2->value);
		EXPECT_EQ(ref->value, ref2->value);

		ref2->value = 5;

		EXPECT_EQ(obj.value, ref2->value);
		EXPECT_EQ(ref->value, ref2->value);
		EXPECT_EQ(obj.value, 5);
	}

	TEST(ObjectReferenceTest, ObjectReferenceCopyAssignment)
	{
		ObjectTest obj{ 1 };
		auto ref = obj.getReference();

		ASSERT_EQ(obj.value, ref->value);

		ObjectTest obj2{ 10 };
		ref = obj2.getReference();

		EXPECT_EQ(ref->value, obj2.value);
	}


	TEST(ObjectReferenceTest, MultipleObjectAndReferences)
	{
		ObjectTest obj{ 1 };
		auto ref = obj.getReference();
		ObjectTest obj2{ 2 };
		auto ref2 = obj2.getReference();

		ASSERT_EQ(obj.value, ref->value);
		ASSERT_EQ(obj2.value, ref2->value);

		{
			ObjectTest obj3{ 3 };
			ref = obj3.getReference();

			EXPECT_EQ(obj3.value, ref->value);

			ref->value = 4;
			EXPECT_EQ(ref->value, obj3.value);
			EXPECT_EQ(obj3.value, 4);
			EXPECT_EQ(obj.value, 1);

			ref2 = obj.getReference();
			ref2->value = 5;

			EXPECT_EQ(obj.value, 5);
			EXPECT_EQ(obj.value, ref2->value);
		}

		EXPECT_FALSE(ref);
		EXPECT_EQ(obj2.value, 2);
	}
}
