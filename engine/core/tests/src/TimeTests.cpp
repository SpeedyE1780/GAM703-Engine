#include <engine/core/Time.hpp>

#include <gtest/gtest.h>

namespace gam703::engine::core::tests
{
	TEST(TimeTests, SetTime)
	{
		const double expected = 20;
		Time time(expected);

		EXPECT_EQ(expected, time.getTime());
	}

	TEST(TimeTests, UpdateDeltaTime)
	{
		const double initialTime = 20;
		Time time(initialTime);

		ASSERT_EQ(initialTime, time.getTime());

		const double timeStep = 5;
		const double newTime = initialTime + timeStep;
		time.processTime(newTime);

		EXPECT_EQ(newTime, time.getTime());
		EXPECT_EQ(timeStep, time.getDeltaTime());
	}

	TEST(TimeTests, SetTimeScale)
	{
		const double initialTime = 20;
		const double timeScale = 2;
		Time time(initialTime, timeScale);

		ASSERT_EQ(initialTime, time.getTime());
		EXPECT_EQ(timeScale, time.getTimeScale());
	}

	TEST(TimeTests, UpdateScaledDeltaTime)
	{
		const double initialTime = 20;
		const double timeScale = 2;
		Time time(initialTime, timeScale);

		ASSERT_EQ(initialTime, time.getTime());
		ASSERT_EQ(timeScale, time.getTimeScale());

		const double timeStep = 5;
		const double newTime = initialTime + timeStep;
		time.processTime(newTime);

		ASSERT_EQ(newTime, time.getTime());

		const double scaledTimeStep = timeStep * timeScale;
		EXPECT_EQ(scaledTimeStep, time.getDeltaTime());
		EXPECT_EQ(timeStep, time.getUnscaledDeltaTime());
	}

	TEST(TimeTests, UpdateTimeScaleThenRevert)
	{
		const double initialTime = 20;
		const double timeScale = 2;
		Time time(initialTime, timeScale);

		ASSERT_EQ(initialTime, time.getTime());
		ASSERT_EQ(timeScale, time.getTimeScale());

		const double timeStep = 5;
		double newTime = initialTime + timeStep;
		time.processTime(newTime);

		ASSERT_EQ(newTime, time.getTime());

		const double scaledTimeStep = timeStep * timeScale;
		EXPECT_EQ(scaledTimeStep, time.getDeltaTime());
		EXPECT_EQ(timeStep, time.getUnscaledDeltaTime());

		time.setTimeScale(1);
		newTime += timeStep;
		time.processTime(newTime);

		EXPECT_EQ(newTime, time.getTime());
		EXPECT_EQ(timeStep, time.getDeltaTime());
		EXPECT_EQ(timeStep, time.getUnscaledDeltaTime());
	}
}
