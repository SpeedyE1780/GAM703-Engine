#include <gtest/gtest.h>
#include <glm/glm.hpp>
#include <components/Transform.hpp>

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
		Transform transform{};

		glm::vec3 position = glm::vec3(0, 0, 0);
		glm::vec3 scale = glm::vec3(1, 1, 1);
		glm::quat rotation = glm::quat(glm::vec3(0, 0, 0));
		glm::mat4 transformMatrix = glm::mat4(1);

		EXPECT_EQ(position, transform.getPosition());
		EXPECT_EQ(scale, transform.getScale());
		EXPECT_EQ(rotation, transform.getRotation());
		EXPECT_EQ(transformMatrix, transform.getTransformationMatrix());
	}

	TEST(TransformTests, TranslationTest)
	{
		glm::vec3 position = glm::vec3(2, 5, 2);
		Transform transform{ position };
		glm::mat4 transformMatrix = glm::translate(glm::mat4(1), position);

		EXPECT_EQ(position, transform.getPosition());
		EXPECT_EQ(transformMatrix, transform.getTransformationMatrix());
	}

	TEST(TransformTests, RotationXAxis)
	{
		glm::vec3 eulerAngles(glm::radians(90.0f), 0, 0);
		glm::quat rotation(eulerAngles);
		Transform transform{ glm::vec3(0,0,0), eulerAngles };
		glm::mat4 transformMatrix = calculateRotationMatrix(glm::mat4(1), eulerAngles);

		EXPECT_EQ(rotation, transform.getRotation());
		EXPECT_TRUE(compareMatrix(transformMatrix, transform.getTransformationMatrix()));
	}

	TEST(TransformTests, RotationYAxis)
	{
		glm::vec3 eulerAngles(0, glm::radians(90.0f), 0);
		glm::quat rotation(eulerAngles);
		Transform transform{ glm::vec3(0,0,0), eulerAngles };
		glm::mat4 transformMatrix = calculateRotationMatrix(glm::mat4(1), eulerAngles);

		EXPECT_EQ(rotation, transform.getRotation());
		EXPECT_TRUE(compareMatrix(transformMatrix, transform.getTransformationMatrix()));
	}

	TEST(TransformTests, RotationZAxis)
	{
		glm::vec3 eulerAngles(0, 0, glm::radians(90.0f));
		glm::quat rotation(eulerAngles);
		Transform transform{ glm::vec3(0,0,0), eulerAngles };
		glm::mat4 transformMatrix = calculateRotationMatrix(glm::mat4(1), eulerAngles);

		EXPECT_EQ(rotation, transform.getRotation());
		EXPECT_TRUE(compareMatrix(transformMatrix, transform.getTransformationMatrix()));
	}

	TEST(TransformTests, RotationXYAxis)
	{
		glm::vec3 eulerAngles(glm::radians(90.0f), glm::radians(90.0f), 0);
		glm::quat rotation(eulerAngles);
		Transform transform{ glm::vec3(0,0,0), eulerAngles };
		glm::mat4 transformMatrix = calculateRotationMatrix(glm::mat4(1), eulerAngles);

		EXPECT_EQ(rotation, transform.getRotation());
		EXPECT_TRUE(compareMatrix(transformMatrix, transform.getTransformationMatrix()));
	}

	TEST(TransformTests, RotationXZAxis)
	{
		glm::vec3 eulerAngles(glm::radians(90.0f), 0, glm::radians(90.0f));
		glm::quat rotation(eulerAngles);
		Transform transform{ glm::vec3(0,0,0), eulerAngles };
		glm::mat4 transformMatrix = calculateRotationMatrix(glm::mat4(1), eulerAngles);

		EXPECT_EQ(rotation, transform.getRotation());
		EXPECT_TRUE(compareMatrix(transformMatrix, transform.getTransformationMatrix()));
	}

	TEST(TransformTests, RotationYZAxis)
	{
		glm::vec3 eulerAngles(0, glm::radians(90.0f), glm::radians(90.0f));
		glm::quat rotation(eulerAngles);
		Transform transform{ glm::vec3(0,0,0), eulerAngles };
		glm::mat4 transformMatrix = calculateRotationMatrix(glm::mat4(1), eulerAngles);

		EXPECT_EQ(rotation, transform.getRotation());
		EXPECT_TRUE(compareMatrix(transformMatrix, transform.getTransformationMatrix()));
	}

	TEST(TransformTests, RotationXYZAxis)
	{
		glm::vec3 eulerAngles(glm::radians(90.0f), glm::radians(90.0f), glm::radians(90.0f));
		glm::quat rotation(eulerAngles);
		Transform transform{ glm::vec3(0,0,0), eulerAngles };
		glm::mat4 transformMatrix = calculateRotationMatrix(glm::mat4(1), eulerAngles);

		EXPECT_EQ(rotation, transform.getRotation());
		EXPECT_TRUE(compareMatrix(transformMatrix, transform.getTransformationMatrix()));
	}

	TEST(TransformTests, UniformScaleTest)
	{
		glm::vec3 scale(2, 2, 2);
		Transform transform{ glm::vec3(0,0,0), glm::vec3(0,0,0), scale };

		glm::mat4 transformMatrix = glm::scale(glm::mat4(1), scale);

		EXPECT_EQ(scale, transform.getScale());
		EXPECT_TRUE(compareMatrix(transformMatrix, transform.getTransformationMatrix()));
	}

	TEST(TransformTests, NonUniformScaleTest)
	{
		glm::vec3 scale(1, 2, 3);
		Transform transform{ glm::vec3(0,0,0), glm::vec3(0,0,0), scale };

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
		Transform transform{};
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

		EXPECT_EQ(glm::quat(eulerAngles), transform.getRotation());
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
		Transform transform{};
		const glm::mat4& transformationMatrix = transform.getTransformationMatrix();

		ASSERT_TRUE(compareMatrix(transformMatrix, transformationMatrix));

		transform.setPosition(position);

		EXPECT_EQ(position, transform.getPosition());
		EXPECT_TRUE(compareMatrix(transformMatrix, transformationMatrix));

		transform.setRotation(eulerAngles);

		EXPECT_EQ(glm::quat(eulerAngles), transform.getRotation());
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
} //gam703::engine::components::tests
