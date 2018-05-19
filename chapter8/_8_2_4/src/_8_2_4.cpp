#include "_8_2_4.h"
#include <vector>

namespace XY
{
    size_t counting(std::vector<int> const &v, size_t const k, size_t const low, size_t const high)
    {
        if(low>high)
            return 0;
        size_t cnt[k+1];
        for(size_t i=0; i<k+1; ++i)
            cnt[i]=0;
        for(auto it=v.cbegin(); it!=v.cend(); ++it)
            ++cnt[*it];
        for(size_t i=1; i<k+1; ++i)
            cnt[i] += cnt[i-1];
        if(low==0)
            return cnt[high];
        return cnt[high]-cnt[low-1];
    }
}

