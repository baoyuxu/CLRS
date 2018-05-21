#include "randomized_select.h"
#include "gtest/gtest.h"

TEST(randomized_select_test, normal)
{
    std::vector<int> a={5, 4, 8, 3};
    std::vector<int> b(a);
    ASSERT_EQ(XY::randomized_select(b, 0, 3, 2), 5);
    b = a;
    ASSERT_EQ(XY::randomized_select(b, 0, 4, 3), 8);
}

TEST(randomized_select_test, zero)
{
    std::vector<int> a={5, 4, 8, 3};
    std::vector<int> b(a);
    ASSERT_EQ(XY::randomized_select(b, 0, 3, 0), 3);
}
