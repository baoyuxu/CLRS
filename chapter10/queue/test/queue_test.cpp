#include "queue.h"
#include "gtest/gtest.h"

TEST(normal, test)
{
    XY::queue<int> q;
    q.enqueue(1);
    q.enqueue(2);
    ASSERT_EQ(1, q.dequeue());
    ASSERT_EQ(2, q.dequeue());
}
