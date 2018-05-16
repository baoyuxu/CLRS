#include<iostream>
#include<functional>
#include<random>

namespace XY
{

template<typename T, typename Compare = std::less_equal<T>>
ssize_t randomized_partition(T *const p, ssize_t low, ssize_t high);
template<typename T, typename Compare = std::less_equal<T>>
void randomized_quick_sort(T *const p, ssize_t low, ssize_t high);

template<typename T, typename Compare>
void randomized_quick_sort(T *const p, ssize_t low, ssize_t high)
{
    if(low < high)
    {
        ssize_t q = randomized_partition<T, Compare>(p, low, high);
        randomized_quick_sort(p, low, q-1);
        randomized_quick_sort(p, q+1, high);
    }
}

template<typename T, typename Compare>
ssize_t randomized_partition(T *const p, ssize_t low, ssize_t high)
{
    Compare compare;
    std::random_device rd;
    unsigned int rd_mid = low+rd()%(high-low+1);
    std::swap(p[rd_mid], p[high]);
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
    XY::randomized_quick_sort(a, 0, 4);
    for(int i=0; i<5; ++i)
        std::cout<<a[i]<<" ";
    std::cout<<std::endl;
    return 0;
}

