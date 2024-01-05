#include <engine/components/Transform.hpp>
#include <engine/core/Engine.hpp>
#include <gtest/gtest.h>

#include <string>

namespace gam703::engine::components::tests
{
	class MockComponent1 : public Component
	{
	public:
		MockComponent1(Transform& transform) : Component(transform)
		{
		}

		virtual Component* clone(Transform&) const override
		{
			return nullptr;
		}
	};

	class MockComponent2 : public Component
	{
	public:
		MockComponent2(Transform& transform) : Component(transform)
		{
		}

		virtual Component* clone(Transform&) const override
		{
			return nullptr;
		}
	};

	class MockComponentWithArgs : public Component
	{
	public:
		MockComponentWithArgs(Transform& transform) : Component(transform)
		{
		}

		MockComponentWithArgs(Transform& transform, const std::string& name, int id, float speed, double precision) : Component(transform), m_name(name), m_id(id), m_speed(speed), m_precision(precision)
		{

		}

		virtual Component* clone(Transform&) const override
		{
			return nullptr;
		}

		std::string m_name = "DEFAULT";
		int m_id = 0;
		float m_speed = 0;
		double m_precision = 0;
	};

	TEST(ComponentsTest, AddComponent)
	{
		core::Engine engine{ "TEST", 1280, 720 };
		Transform transform{ engine };

		ASSERT_EQ(0, transform.getComponentsSize());
		ASSERT_EQ(0, transform.getBehaviorsSize());

		auto* component = transform.addComponent<MockComponent1>();

		EXPECT_TRUE(component != nullptr);
		EXPECT_EQ(1, transform.getComponentsSize());
		EXPECT_EQ(&transform, &component->getTransform());
	}

	TEST(ComponentsTest, AddComponentWithArgs)
	{
		core::Engine engine{ "TEST", 1280, 720 };
		Transform transform{ engine };
		std::string name = "Hello World!";
		int id = 20;
		float speed = 32.23f;
		double precision = 34.7;

		ASSERT_EQ(0, transform.getComponentsSize());
		ASSERT_EQ(nullptr, transform.getComponent<MockComponentWithArgs>());

		auto* component = transform.addComponent<MockComponentWithArgs>();

		ASSERT_TRUE(component != nullptr);
		ASSERT_EQ(1, transform.getComponentsSize());

		EXPECT_EQ("DEFAULT", component->m_name);
		EXPECT_EQ(0, component->m_id);
		EXPECT_EQ(0, component->m_speed);
		EXPECT_EQ(0, component->m_precision);

		transform.removeComponent<MockComponentWithArgs>();
		component = nullptr;

		ASSERT_EQ(0, transform.getComponentsSize());

		component = transform.addComponent<MockComponentWithArgs>(name, id, speed, precision);

		ASSERT_EQ(1, transform.getComponentsSize());
		EXPECT_EQ(name, component->m_name);
		EXPECT_EQ(id, component->m_id);
		EXPECT_EQ(speed, component->m_speed);
		EXPECT_EQ(precision, component->m_precision);
	}

	TEST(ComponentsTest, GetComponent)
	{
		core::Engine engine{ "TEST", 1280, 720 };
		Transform transform{ engine };

		ASSERT_EQ(0, transform.getComponentsSize());
		ASSERT_EQ(nullptr, transform.getComponent<MockComponent1>());

		auto* component = transform.addComponent<MockComponent1>();

		ASSERT_TRUE(component != nullptr);
		ASSERT_EQ(1, transform.getComponentsSize());

		auto* componentFromTransform = transform.getComponent<MockComponent1>();
		EXPECT_EQ(component, componentFromTransform);
	}

	TEST(ComponentsTest, RemoveComponent)
	{
		core::Engine engine{ "TEST", 1280, 720 };
		Transform transform{ engine };
		transform.addComponent<MockComponent1>();
		ASSERT_EQ(1, transform.getComponentsSize());

		transform.removeComponent<MockComponent1>();

		EXPECT_EQ(0, transform.getComponentsSize());
	}

	TEST(ComponentsTest, MultipleComponents)
	{
		core::Engine engine{ "TEST", 1280, 720 };
		Transform transform{ engine };
		ASSERT_EQ(0, transform.getComponentsSize());

		auto* mock1 = transform.addComponent<MockComponent1>();

		EXPECT_EQ(1, transform.getComponentsSize());
		EXPECT_EQ(&transform, &mock1->getTransform());

		auto* mock2 = transform.addComponent<MockComponent2>();

		EXPECT_EQ(2, transform.getComponentsSize());
		EXPECT_EQ(&transform, &mock2->getTransform());

		transform.removeComponent<MockComponent1>();
		EXPECT_EQ(1, transform.getComponentsSize());

		transform.removeComponent<MockComponent2>();
		EXPECT_EQ(0, transform.getComponentsSize());
	}
} //gam703::engine::components::tests
