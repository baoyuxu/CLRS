#ifndef LINEAR_H
#define LINEAR_H
#include <sys/types.h>

namespace XY
{

template<typename T>
struct maximum_subarray
{
    ssize_t low;
    ssize_t high;
    T sum;
    maximum_subarray(ssize_t l, ssize_t h, T &s)
        :low(l), high(h), sum(s)
    {}
    maximum_subarray(ssize_t l, ssize_t h, T &&s)
        :low(l), high(h), sum(s)
    {}
};

template<typename T>
maximum_subarray<T> find_maximum_subarray(T *const ptr, ssize_t low, ssize_t high)
{
    maximum_subarray<T> current_maximum(low, low, ptr[low]);
    maximum_subarray<T> current(current_maximum);
    for(ssize_t i = low+1 ; i < high+1; ++i)
    {
        current.sum += ptr[i];
        if(current.sum <= 0)
        {
            current.low = i+1;
            current.sum = 0;
        }
        else
        {
            current.high = i;
        }
        if(current.sum >= current_maximum.sum)
        {
            current_maximum = current;
        }
    }
    return current_maximum;
}

}//namespace XY
#endif
