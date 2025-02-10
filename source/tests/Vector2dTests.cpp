#include "gtest/gtest.h"

#include "Vector2d.h"
#include "ZMathUtils.h"


using namespace zmath;

TEST(Vector2dTest, Assignment)
{
    Vector2d v1{ 3, 4 };
    Vector2d v2;
    v2 = v1;

    EXPECT_TRUE(ZMathUtils::EqualTo(v2.X(), 3));
    EXPECT_TRUE(ZMathUtils::EqualTo(v2.Y(), 4));
}
