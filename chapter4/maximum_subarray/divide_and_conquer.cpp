#include<iostream>

template<typename T>
struct maximum_subarray;
template<typename T>
maximum_subarray<T> find_max_crossing_subarray(T *array, ssize_t low, ssize_t mid, ssize_t high);
template<typename T>
maximum_subarray<T> find_maximum_subarray(T *array, ssize_t low, ssize_t high);

template<typename T>
struct maximum_subarray
{
    ssize_t max_left;
    ssize_t max_right;
    T sum;
    maximum_subarray(ssize_t left, ssize_t right, T &s)
        :max_left(left), max_right(right), sum(s)
    {}
    maximum_subarray(ssize_t left, ssize_t right, T &&s)
        :max_left(left), max_right(right), sum(s)
    {}
    bool operator<(const maximum_subarray &o)
    {
        return sum < o.sum;
    }
    bool operator>(const maximum_subarray &o)
    {
        return sum > o.sum;
    }
    bool operator<=(const maximum_subarray &o)
    {
        return sum <= o.sum;
    }
    bool operator>=(const maximum_subarray &o)
    {
        return sum >= o.sum;
    }
};

template<typename T>
maximum_subarray<T> find_max_crossing_subarray(T *array, ssize_t low, ssize_t mid, ssize_t high)
{
    ssize_t max_left = mid;
    ssize_t max_right = mid;
    T left_sum = 0;
    T right_sum = 0;
    T sum = 0;
    for(ssize_t i = mid; i >= low; --i)
    {
        sum += array[i];
        if(sum > left_sum)
        {
            left_sum = sum;
            max_left = i;
        }
    }
    sum = 0;
    for(ssize_t i = mid+1; i<=high; ++i)
    {
        sum += array[i];
        if(sum > right_sum)
        {
            right_sum = sum;
            max_right = i;
        }
    }
    return maximum_subarray<T>(max_left, max_right, left_sum + right_sum);
}

template<typename T>
maximum_subarray<T> find_maximum_subarray(T *array, ssize_t low, ssize_t high)
{
    if( low==high )
        return maximum_subarray<T>(low, high, array[low]);
    ssize_t mid = (low+high)/2;
    maximum_subarray<T> left_max = find_maximum_subarray(array, low, mid);
    maximum_subarray<T> right_max = find_maximum_subarray(array, mid+1, high);
    maximum_subarray<T> crossing_max = find_max_crossing_subarray(array, low, mid, high);
    if(left_max >= right_max && left_max >= crossing_max)
        return left_max;
    else if(right_max >= left_max && right_max >= crossing_max)
        return right_max;
    else
        return crossing_max;
}


int main(int argc, char const* argv[])
{
    int a[5] = {10, -5, 5, -1, 846};
    auto x = find_maximum_subarray(a, 0, 4);
    std::cout<<x.max_left<<" "<<x.max_right<<" "<<x.sum<<std::endl;
    return 0;
}
