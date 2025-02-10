#include "gtest/gtest.h"

#include "ZMathUtils.h"


using namespace zmath;


class TestComparison : public testing::Test
{
public:


protected:

    LessThanPredictor predictor;
};


TEST_F(TestComparison, LessThan1)
{
    EXPECT_TRUE(predictor(2.718, 3.14));
}

TEST_F(TestComparison, LessThan2)
{
    EXPECT_FALSE(predictor(3.14, 3.14));
}

TEST_F(TestComparison, LessThan3)
{
    EXPECT_FALSE(predictor(3.14, 2.718));
}

TEST_F(TestComparison, LessThan4)
{
    EXPECT_TRUE(predictor(3.141592, 3.1415931));
}

TEST_F(TestComparison, LessThan5)
{
    EXPECT_FALSE(predictor(3.1415926, 3.1415927));
}
