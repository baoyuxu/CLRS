#ifndef RANDOMIZED_SELECT_H
#define RANDOMIZED_SELECT_H
#include <vector>
#include <sys/types.h>
#include <functional>
#include <random>
#include <ctime>
namespace XY
{
    template<typename T, typename Compare>
    ssize_t randomized_partition(std::vector<T> &v, ssize_t const low, ssize_t const high)
    {
        static Compare compare;
        static std::default_random_engine random(time(NULL));
        std::uniform_int_distribution<ssize_t> u_dis(low, high);

        std::swap(v[high], v[u_dis(random)]);
        ssize_t lower_next = low;
        ssize_t curr = low;
        while(curr<high)
        {
            if(compare(v[curr], v[high]))
            {
                std::swap(v[lower_next++], v[curr]);
            }
            ++curr;
        }
        std::swap(v[lower_next], v[high]);
        return lower_next;
    }

    template<typename T, typename Compare=std::less<T>>
    T &randomized_select(std::vector<T> &v, ssize_t const low, ssize_t const high, ssize_t const target)
    {
        if(low == high)
            return v[low];
        ssize_t pivot = randomized_partition<T, Compare>(v, low, high);
        ssize_t offset = pivot - low;
        if(target == offset)
            return v[target];
        else if (target<offset)
            return randomized_select(v, low, pivot-1, target);
        else
            return randomized_select(v, pivot+1, high, target-offset-1);
    }
}
#endif
