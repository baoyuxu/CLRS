#include "_8_2_4.h"
#include <vector>
#include "gtest/gtest.h"

TEST(_8_2_4_test, normal)
{
    std::vector<int> v{1, 1, 2, 3, 4};
    ASSERT_EQ(3, XY::counting(v, 4, 1, 2));
    ASSERT_EQ(XY::counting(v, 4, 1, 4), 5);
}

TEST(_8_2_4_test, zero)
{
    std::vector<int> v{1, 1, 2, 3, 4};
    ASSERT_EQ(XY::counting(v, 4, 0, 2), 3);
    ASSERT_EQ(XY::counting(v, 4, 0, 4), 5);
}
