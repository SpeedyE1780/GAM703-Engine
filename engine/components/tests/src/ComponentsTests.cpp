#include <engine/core-interfaces/Transform.hpp>
#include <gtest/gtest.h>

#include <string>

namespace gam703::engine::components::tests
{
	class MockComponent1 : public core_interface::Component
	{
	public:
		MockComponent1(core_interface::Transform* transform) : core_interface::Component(transform)
		{
		}

		virtual void tick(float deltaTime) override
		{
		}

		virtual core_interface::Component* clone(core_interface::Transform*) const override
		{
			return nullptr;
		}
	};

	class MockComponent2 : public core_interface::Component
	{
	public:
		MockComponent2(core_interface::Transform* transform) : core_interface::Component(transform)
		{
		}
		
		virtual void tick(float deltaTime) override
		{
		}

		virtual core_interface::Component* clone(core_interface::Transform*) const override
		{
			return nullptr;
		}
	};

	class MockComponentWithArgs : public core_interface::Component
	{
	public:
		MockComponentWithArgs(core_interface::Transform* transform) : core_interface::Component(transform)
		{
		}

		MockComponentWithArgs(core_interface::Transform* transform, const std::string& name, int id, float speed, double precision) : core_interface::Component(transform), m_name(name), m_id(id), m_speed(speed), m_precision(precision)
		{

		}

		virtual void tick(float deltaTime) override
		{
		}

		virtual core_interface::Component* clone(core_interface::Transform*) const override
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
		core_interface::Transform transform{ nullptr, nullptr };

		ASSERT_EQ(0, transform.getComponentsSize());

		auto* component = transform.addComponent<MockComponent1>();

		EXPECT_TRUE(component != nullptr);
		EXPECT_EQ(1, transform.getComponentsSize());
		EXPECT_EQ(&transform, component->getTransform());
	}

	TEST(ComponentsTest, AddComponentWithArgs)
	{
		core_interface::Transform transform{ nullptr, nullptr };
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
		core_interface::Transform transform{ nullptr, nullptr };

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
		core_interface::Transform transform{ nullptr, nullptr };
		transform.addComponent<MockComponent1>();
		ASSERT_EQ(1, transform.getComponentsSize());

		transform.removeComponent<MockComponent1>();

		EXPECT_EQ(0, transform.getComponentsSize());
	}

	TEST(ComponentsTest, MultipleComponents)
	{
		core_interface::Transform transform{ nullptr, nullptr };
		ASSERT_EQ(0, transform.getComponentsSize());

		auto* mock1 = transform.addComponent<MockComponent1>();

		EXPECT_EQ(1, transform.getComponentsSize());
		EXPECT_EQ(&transform, mock1->getTransform());

		auto* mock2 = transform.addComponent<MockComponent2>();

		EXPECT_EQ(2, transform.getComponentsSize());
		EXPECT_EQ(&transform, mock2->getTransform());

		transform.removeComponent<MockComponent1>();
		EXPECT_EQ(1, transform.getComponentsSize());

		transform.removeComponent<MockComponent2>();
		EXPECT_EQ(0, transform.getComponentsSize());
	}
} //gam703::engine::components::tests
