#include "pch.h"

#include "ZMathUtils.h"


using namespace zmath;

TEST(LessThan, 1) {
    EXPECT_TRUE(ZMathUtils::LessThan(1, 2));
}
