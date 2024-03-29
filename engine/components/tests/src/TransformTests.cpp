#include <engine/components/Transform.hpp>

#include <engine/core/Engine.hpp>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <gtest/gtest.h>

#include <cmath>

namespace gam703::engine::components::tests
{
	static bool compareMatrix(const glm::mat4& lhs, const glm::mat4& rhs)
	{
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				if (abs(lhs[i][j] - rhs[i][j]) > pow(10, -6))
				{
					return false;
				}
			}
		}

		return true;
	}

	static glm::mat4 calculateRotationMatrix(const glm::mat4& base, const glm::vec3& eulerAngles)
	{
		glm::mat4 output = glm::rotate(base, eulerAngles.z, glm::vec3(0, 0, 1));
		output = glm::rotate(output, eulerAngles.y, glm::vec3(0, 1, 0));
		output = glm::rotate(output, eulerAngles.x, glm::vec3(1, 0, 0));
		return output;
	}

	TEST(TransformTests, TransformConstructor)
	{
		core::Engine engine{ "TEST", 1280, 720 };
		Transform transform{ engine };

		glm::vec3 position = glm::vec3(0, 0, 0);
		glm::vec3 scale = glm::vec3(1, 1, 1);
		glm::vec3 rotation = glm::vec3(0, 0, 0);
		glm::mat4 transformMatrix = glm::mat4(1);

		EXPECT_EQ(position, transform.getPosition());
		EXPECT_EQ(scale, transform.getScale());
		EXPECT_EQ(rotation, transform.getRotation());
		EXPECT_EQ(transformMatrix, transform.getTransformationMatrix());
	}

	TEST(TransformTests, TranslationTest)
	{
		glm::vec3 position = glm::vec3(2, 5, 2);
		core::Engine engine{ "TEST", 1280, 720 };
		Transform transform{ engine, position };
		glm::mat4 transformMatrix = glm::translate(glm::mat4(1), position);

		EXPECT_EQ(position, transform.getPosition());
		EXPECT_EQ(transformMatrix, transform.getTransformationMatrix());
	}

	TEST(TransformTests, RotationXAxis)
	{
		glm::vec3 eulerAngles(glm::radians(90.0f), 0, 0);
		core::Engine engine{ "TEST", 1280, 720 };
		Transform transform{ engine, glm::vec3(0,0,0), eulerAngles };
		glm::mat4 transformMatrix = calculateRotationMatrix(glm::mat4(1), eulerAngles);

		EXPECT_EQ(eulerAngles, transform.getRotation());
		EXPECT_TRUE(compareMatrix(transformMatrix, transform.getTransformationMatrix()));
	}

	TEST(TransformTests, RotationYAxis)
	{
		glm::vec3 eulerAngles(0, glm::radians(90.0f), 0);
		core::Engine engine{ "TEST", 1280, 720 };
		Transform transform{ engine, glm::vec3(0,0,0), eulerAngles };
		glm::mat4 transformMatrix = calculateRotationMatrix(glm::mat4(1), eulerAngles);

		EXPECT_EQ(eulerAngles, transform.getRotation());
		EXPECT_TRUE(compareMatrix(transformMatrix, transform.getTransformationMatrix()));
	}

	TEST(TransformTests, RotationZAxis)
	{
		glm::vec3 eulerAngles(0, 0, glm::radians(90.0f));
		core::Engine engine{ "TEST", 1280, 720 };
		Transform transform{ engine, glm::vec3(0,0,0), eulerAngles };
		glm::mat4 transformMatrix = calculateRotationMatrix(glm::mat4(1), eulerAngles);

		EXPECT_EQ(eulerAngles, transform.getRotation());
		EXPECT_TRUE(compareMatrix(transformMatrix, transform.getTransformationMatrix()));
	}

	TEST(TransformTests, RotationXYAxis)
	{
		glm::vec3 eulerAngles(glm::radians(90.0f), glm::radians(90.0f), 0);
		core::Engine engine{ "TEST", 1280, 720 };
		Transform transform{ engine, glm::vec3(0,0,0), eulerAngles };
		glm::mat4 transformMatrix = calculateRotationMatrix(glm::mat4(1), eulerAngles);

		EXPECT_EQ(eulerAngles, transform.getRotation());
		EXPECT_TRUE(compareMatrix(transformMatrix, transform.getTransformationMatrix()));
	}

	TEST(TransformTests, RotationXZAxis)
	{
		glm::vec3 eulerAngles(glm::radians(90.0f), 0, glm::radians(90.0f));
		core::Engine engine{ "TEST", 1280, 720 };
		Transform transform{ engine, glm::vec3(0,0,0), eulerAngles };
		glm::mat4 transformMatrix = calculateRotationMatrix(glm::mat4(1), eulerAngles);

		EXPECT_EQ(eulerAngles, transform.getRotation());
		EXPECT_TRUE(compareMatrix(transformMatrix, transform.getTransformationMatrix()));
	}

	TEST(TransformTests, RotationYZAxis)
	{
		glm::vec3 eulerAngles(0, glm::radians(90.0f), glm::radians(90.0f));
		core::Engine engine{ "TEST", 1280, 720 };
		Transform transform{ engine, glm::vec3(0,0,0), eulerAngles };
		glm::mat4 transformMatrix = calculateRotationMatrix(glm::mat4(1), eulerAngles);

		EXPECT_EQ(eulerAngles, transform.getRotation());
		EXPECT_TRUE(compareMatrix(transformMatrix, transform.getTransformationMatrix()));
	}

	TEST(TransformTests, RotationXYZAxis)
	{
		glm::vec3 eulerAngles(glm::radians(90.0f), glm::radians(90.0f), glm::radians(90.0f));
		core::Engine engine{ "TEST", 1280, 720 };
		Transform transform{ engine, glm::vec3(0,0,0), eulerAngles };
		glm::mat4 transformMatrix = calculateRotationMatrix(glm::mat4(1), eulerAngles);

		EXPECT_EQ(eulerAngles, transform.getRotation());
		EXPECT_TRUE(compareMatrix(transformMatrix, transform.getTransformationMatrix()));
	}

	TEST(TransformTests, UniformScaleTest)
	{
		glm::vec3 scale(2, 2, 2);
		core::Engine engine{ "TEST", 1280, 720 };
		Transform transform{ engine, glm::vec3(0,0,0), glm::vec3(0,0,0), scale };

		glm::mat4 transformMatrix = glm::scale(glm::mat4(1), scale);

		EXPECT_EQ(scale, transform.getScale());
		EXPECT_TRUE(compareMatrix(transformMatrix, transform.getTransformationMatrix()));
	}

	TEST(TransformTests, NonUniformScaleTest)
	{
		glm::vec3 scale(1, 2, 3);
		core::Engine engine{ "TEST", 1280, 720 };
		Transform transform{ engine, glm::vec3(0,0,0), glm::vec3(0,0,0), scale };

		glm::mat4 transformMatrix = glm::scale(glm::mat4(1), scale);

		EXPECT_EQ(scale, transform.getScale());
		EXPECT_TRUE(compareMatrix(transformMatrix, transform.getTransformationMatrix()));
	}

	TEST(TransformTests, MultipleTransformationWithMultipleCalculations)
	{
		glm::vec3 position(5, 3, 2);
		glm::vec3 eulerAngles(glm::radians(25.0f), glm::radians(35.0f), glm::radians(45.0f));
		glm::vec3 scale(1, 2, 3);
		glm::mat4 transformMatrix = glm::mat4(1);
		core::Engine engine{ "TEST", 1280, 720 };
		Transform transform{ engine };
		const glm::mat4& transformationMatrix = transform.getTransformationMatrix();

		ASSERT_TRUE(compareMatrix(transformMatrix, transformationMatrix));

		transform.setPosition(position);
		transform.calculateTransformMatrix();
		transformMatrix = glm::translate(transformMatrix, position);

		EXPECT_EQ(position, transform.getPosition());
		EXPECT_TRUE(compareMatrix(transformMatrix, transformationMatrix));

		transform.setRotation(eulerAngles);
		transform.calculateTransformMatrix();
		transformMatrix = calculateRotationMatrix(transformMatrix, eulerAngles);

		EXPECT_EQ(eulerAngles, transform.getRotation());
		EXPECT_TRUE(compareMatrix(transformMatrix, transformationMatrix));

		transform.setScale(scale);
		transform.calculateTransformMatrix();
		transformMatrix = glm::scale(transformMatrix, scale);

		EXPECT_EQ(scale, transform.getScale());
		EXPECT_TRUE(compareMatrix(transformMatrix, transformationMatrix));
	}

	TEST(TransformTests, MultipleTransformationWithOneCalculation)
	{
		glm::vec3 position(5, 3, 2);
		glm::vec3 eulerAngles(glm::radians(25.0f), glm::radians(35.0f), glm::radians(45.0f));
		glm::vec3 scale(1, 2, 3);
		glm::mat4 transformMatrix = glm::mat4(1);
		core::Engine engine{ "TEST", 1280, 720 };
		Transform transform{ engine };
		const glm::mat4& transformationMatrix = transform.getTransformationMatrix();

		ASSERT_TRUE(compareMatrix(transformMatrix, transformationMatrix));

		transform.setPosition(position);

		EXPECT_EQ(position, transform.getPosition());
		EXPECT_TRUE(compareMatrix(transformMatrix, transformationMatrix));

		transform.setRotation(eulerAngles);

		EXPECT_EQ(eulerAngles, transform.getRotation());
		EXPECT_TRUE(compareMatrix(transformMatrix, transformationMatrix));

		transform.setScale(scale);
		EXPECT_EQ(scale, transform.getScale());
		EXPECT_TRUE(compareMatrix(transformMatrix, transformationMatrix));

		transform.calculateTransformMatrix();
		transformMatrix = glm::translate(transformMatrix, position);
		transformMatrix = calculateRotationMatrix(transformMatrix, eulerAngles);
		transformMatrix = glm::scale(transformMatrix, scale);

		EXPECT_TRUE(compareMatrix(transformMatrix, transformationMatrix));
	}

	TEST(TransformTests, TranslateTest)
	{
		glm::vec3 position(1, 2, 3);
		core::Engine engine{ "TEST", 1280, 720 };
		Transform transform(engine, position);
		glm::mat4 transformMatrix = glm::translate(glm::mat4(1), position);

		ASSERT_TRUE(compareMatrix(transformMatrix, transform.getTransformationMatrix()));

		glm::vec3 offset(5, 6, 7);
		transform.translate(offset);
		transform.calculateTransformMatrix();
		transformMatrix = glm::translate(transformMatrix, offset);

		EXPECT_TRUE(compareMatrix(transformMatrix, transform.getTransformationMatrix()));
	}

	TEST(TransformTests, RotationTest)
	{
		glm::vec3 eulerAngles(20, 0, 0);
		core::Engine engine{ "TEST", 1280, 720 };
		Transform transform(engine, glm::vec3(0, 0, 0), eulerAngles);
		glm::mat4 transformMatrix = glm::rotate(glm::mat4(1), 20.0f, glm::vec3(1, 0, 0));

		ASSERT_TRUE(compareMatrix(transformMatrix, transform.getTransformationMatrix()));

		transform.rotate(eulerAngles);
		transform.calculateTransformMatrix();
		transformMatrix = glm::rotate(transformMatrix, 20.0f, glm::vec3(1, 0, 0));

		EXPECT_TRUE(compareMatrix(transformMatrix, transform.getTransformationMatrix()));
	}

	TEST(TransformTests, CloningTests)
	{
		glm::vec3 position(5, 3, 2);
		glm::vec3 eulerAngles(glm::radians(25.0f), glm::radians(35.0f), glm::radians(45.0f));
		glm::vec3 scale(1, 2, 3);
		glm::mat4 transformMatrix = glm::mat4(1);
		core::Engine engine{ "TEST", 1280, 720 };
		Transform transform{ engine };
		const glm::mat4& transformationMatrix = transform.getTransformationMatrix();

		ASSERT_TRUE(compareMatrix(transformMatrix, transformationMatrix));

		transform.setPosition(position);

		ASSERT_EQ(position, transform.getPosition());
		ASSERT_TRUE(compareMatrix(transformMatrix, transformationMatrix));

		transform.setRotation(eulerAngles);

		ASSERT_EQ(eulerAngles, transform.getRotation());
		ASSERT_TRUE(compareMatrix(transformMatrix, transformationMatrix));

		transform.setScale(scale);
		ASSERT_EQ(scale, transform.getScale());
		ASSERT_TRUE(compareMatrix(transformMatrix, transformationMatrix));

		transform.calculateTransformMatrix();
		transformMatrix = glm::translate(transformMatrix, position);
		transformMatrix = calculateRotationMatrix(transformMatrix, eulerAngles);
		transformMatrix = glm::scale(transformMatrix, scale);

		ASSERT_TRUE(compareMatrix(transformMatrix, transformationMatrix));

		Transform copyConstructor{ transform };
		Transform copyAssignment{ transform };
		Transform* clone = transform.clone();

		EXPECT_TRUE(compareMatrix(transformMatrix, copyConstructor.getTransformationMatrix()));
		EXPECT_TRUE(compareMatrix(transformMatrix, copyAssignment.getTransformationMatrix()));
		EXPECT_TRUE(compareMatrix(transformMatrix, clone->getTransformationMatrix()));

		delete clone;
	}

} //gam703::engine::components::tests
