#ifndef RANDOMIZED_QUICK_SORT_H
#define RANDOMIZED_QUICK_SORT_H

#include<functional>

namespace XY
{

struct pivot
{
    ssize_t lower;
    ssize_t upper;
    pivot(ssize_t l, ssize_t h)
        :lower(l), upper(h)
    {}
};

template<typename T, typename Compare = std::less_equal<T>>
pivot partition(T *const p, ssize_t low, ssize_t high);
template<typename T, typename Compare = std::less_equal<T>>
void quick_sort(T *const p, ssize_t low, ssize_t high);

template<typename T, typename Compare>
void quick_sort(T *const p, ssize_t const low, ssize_t const high)
{
    if(low < high)
    {
        pivot q = partition<T, Compare>(p, low, high);
        quick_sort(p, low, q.lower);
        quick_sort(p, q.upper, high);
    }
}

template<typename T, typename Compare>
pivot partition(T *const p, ssize_t const low, ssize_t const high)
{
    Compare compare;
    ssize_t lower = low;
    ssize_t upper = low;
    ssize_t curr = low;
    while(curr<high)
    {
        if( compare(p[curr], p[high]) )
        {
            std::swap(p[upper], p[curr]);
            if( !(p[upper] == p[high]) )
            {
                std::swap(p[lower], p[upper]);
                ++lower;
            }
            ++upper;
        }
        ++curr;
    }
    std::swap(p[upper], p[high]);

    return pivot(lower-1, upper+1);
}

} //namespace XY
#endif
