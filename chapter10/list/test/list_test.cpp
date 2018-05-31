#include "list.h"
#include "gtest/gtest.h"

TEST(list, normal)
{
    XY::list<int> l;
    l.insert(1);
    l.insert(2);
    l.insert(3);
    l.insert(4);
    auto it  = l.begin();
    ASSERT_EQ(static_cast<int>(l.search(4)==it), 1);
    l.delete_node(it);
    ASSERT_EQ( static_cast<int>(l.search(3)==l.begin()), 1);
}
