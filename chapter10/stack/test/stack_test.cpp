#include "stack.h"
#include "gtest/gtest.h"


TEST(normal,test)
{
    XY::stack<int> s;
    s.push(1);
    s.push(2);
    ASSERT_EQ(2, s.pop());
    ASSERT_EQ(1, s.pop());
}
