#include "counting_sort.h"
#include "gtest/gtest.h"

TEST(couning_sort, no_same_elem)
{
    int a[5]={4, 2, 0, 1, 3};
    int c[5]={0, 1, 2, 3, 4};
    int b[5];
    counting_sort(a, b, 5);
    for(int i = 0; i<5; ++i)
    {
        ASSERT_EQ(c[i], b[i]);
    }
}
