#include "counting_sort.h"

void counting_sort(int *src, int *des, ssize_t k)
{
    int cnt[k];
    for(ssize_t i=0; i<k; ++i)
        cnt[i]=0;
    for(ssize_t i=0; i<k; ++i)
        ++cnt[src[i]];
    for(ssize_t i=1; i<k; ++i)
        cnt[i]+=cnt[i-1];
    for(ssize_t i=k-1; i>=0; --i)
    {
        des[cnt[src[i]]---1] = src[i];
    }
}

