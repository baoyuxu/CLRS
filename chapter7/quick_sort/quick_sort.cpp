#include<iostream>
#include<functional>

namespace XY
{

template<typename T, typename Compare = std::less_equal<T>>
ssize_t partition(T *const p, ssize_t low, ssize_t high);
template<typename T, typename Compare = std::less_equal<T>>
void quick_sort(T *const p, ssize_t low, ssize_t high);

template<typename T, typename Compare>
void quick_sort(T *const p, ssize_t low, ssize_t high)
{
    if(low < high)
    {
        ssize_t q = partition(p, low, high);
        quick_sort(p, low, q-1);
        quick_sort(p, q+1, high);
    }
}

template<typename T, typename Compare>
ssize_t partition(T *const p, ssize_t low, ssize_t high)
{
    Compare compare;
    ssize_t slower = low;
    ssize_t faster = low;
    while(faster<high)
    {
        if( compare(p[faster], p[high])  )
        {
            std::swap(p[slower++], p[faster]);
        }
        ++faster;
    }
    std::swap(p[slower], p[high]);
    return slower;
}

} //namespace XY

int main(int argc, char const* argv[])
{
    int a[5] = {46, 8643, -46, -465, 38468};
    XY::quick_sort(a, 0, 4);
    for(int i=0; i<5; ++i)
        std::cout<<a[i]<<" ";
    std::cout<<std::endl;
    return 0;
}

