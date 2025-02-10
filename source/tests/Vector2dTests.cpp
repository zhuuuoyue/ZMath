#include "gtest/gtest.h"

#include "Vector2d.h"
#include "ZMathUtils.h"
#include "Vector2dUtils.h"


using namespace zmath;

TEST(Vector2dTest, Assignment)
{
    Vector2d v1{ 3, 4 };
    Vector2d v2;
    v2 = v1;

    EXPECT_TRUE(ZMathUtils::EqualTo(v2.X(), 3));
    EXPECT_TRUE(ZMathUtils::EqualTo(v2.Y(), 4));
}

TEST(Vector2dTest, Add)
{
    Vector2d v1{ 3, 4 };
    Vector2d v2{ 4, 6 };
    Vector2d result = v1 + v2;
    Vector2d expect{ 7, 10 };
    EXPECT_TRUE(Vector2dEqualToPredictor{}(result, expect));
}

TEST(Vector2dTest, AddAndAssign)
{
    Vector2d v1{ 3, 4 };
    Vector2d v2{ 4, 6 };
    v2 += v1;
    Vector2d expect{ 7, 10 };
    EXPECT_TRUE(Vector2dEqualToPredictor{}(v2, expect));
}

TEST(Vector2dTest, Minus)
{
    Vector2d v1{ 3, 4 };
    Vector2d v2{ 4, 6 };
    Vector2d result = v1 - v2;
    Vector2d expect{ -1, -2 };
    EXPECT_TRUE(Vector2dEqualToPredictor{}(result, expect));
}

TEST(Vector2dTest, MinusAndAssign)
{
    Vector2d v1{ 3, 4 };
    Vector2d v2{ 4, 6 };
    v2 -= v1;
    Vector2d expect{ 1, 2 };
    EXPECT_TRUE(Vector2dEqualToPredictor{}(v2, expect));
}

TEST(Vector2dTest, VecXK)
{
    Vector2d vec{ 3, 4 };
    Vector2d result = vec * 2;
    Vector2d expect{ 6, 8 };
    EXPECT_TRUE(Vector2dEqualToPredictor{}(result, expect));
}

TEST(Vector2dTest, KXVec)
{
    Vector2d vec{ 3, 4 };
    Vector2d result = 2 * vec;
    Vector2d expect{ 6, 8 };
    EXPECT_TRUE(Vector2dEqualToPredictor{}(result, expect));
}

TEST(Vector2dTest, TimeAndAssign)
{
    Vector2d vec{ 3, 4 };
    vec *= 2;
    Vector2d expect{ 6, 8 };
    EXPECT_TRUE(Vector2dEqualToPredictor{}(vec, expect));
}

TEST(Vector2dTest, Divide)
{
    Vector2d vec{ 3, 4 };
    Vector2d result = vec / 2;
    Vector2d expect{ 1.5, 2 };
    EXPECT_TRUE(Vector2dEqualToPredictor{}(result, expect));
}

TEST(Vector2dTest, DivideByZero)
{
    Vector2d vec{ 3, 4 };
    vec = vec / 0;
    EXPECT_TRUE(std::isinf(vec.X()));
    EXPECT_TRUE(std::isinf(vec.Y()));
}

TEST(Vector2dTest, DivideAndAssign)
{
    Vector2d vec{ 3, 4 };
    vec /= 2;
    Vector2d expect{ 1.5, 2 };
    EXPECT_TRUE(Vector2dEqualToPredictor{}(vec, expect));
}
