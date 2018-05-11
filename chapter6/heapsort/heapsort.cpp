#include<iostream>
#include<functional>
#include<vector>

namespace XY
{

template<typename T, typename Compare = std::less<T>>
class heap
{
    private:
        template<typename U>
        class heap_vec;
    public:
        heap(std::vector<T> const &h)
            :_heap(heap_vec<T>(h)), compare(Compare())
        {}
    private:
        heap_vec<T> _heap;
        Compare compare;
        void heap_ify(size_t const i)
        {

        }



        size_t parent(size_t const i)
        {
            return i>>1;
        }
        size_t left(size_t const i)
        {
            return i<<2;
        }
        size_t right(size_t const i)
        {
            return i<<2+1;
        }

        template<typename U>
        class heap_vec
        {
            public:
                heap_vec(const std::vector<U> &v)
                    :vec(v)
                {}
                U &operator[](size_t offset)
                {
                    return vec[offset-1];
                }
            private:
                std::vector<U> vec;
        };

};

int main(int argc, char const* argv[])
{

    return 0;
}

} //namespace XY
