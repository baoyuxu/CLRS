#include<iostream>

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



int main(int argc, char const* argv[])
{

    return 0;
}
