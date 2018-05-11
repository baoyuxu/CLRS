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
        {
            heap_build();
        }

        std::vector<T> heap_sort()
        {
            std::vector<T> result;
            size_t s = size();
            for(size_t i=0; i<s; ++i)
            {
                result.push_back(_heap[1]);
                _heap[1] = _heap[s-i];
                _heap.pop_back();
                heap_ify(1);
            }
            return result;
        }

    private:
        heap_vec<T> _heap;
        Compare compare;
        void heap_ify(size_t const i)
        {
            size_t l_offset = left(i);
            size_t r_offset = right(i);
            size_t largest = i;
            if(l_offset <= size() && compare(_heap[l_offset], _heap[largest]))
                largest = l_offset;
            if(r_offset <= size() && compare(_heap[r_offset], _heap[largest]))
                largest = r_offset;
            std::swap(_heap[i], _heap[largest]);
            if(largest != i)
                heap_ify(largest);
        }

        void heap_build()
        {
            size_t s = size();
            for(size_t i = s/2; i>=1; --i)
                heap_ify(i);
        }

        size_t size()
        {
            return _heap.size();
        }

        size_t parent(size_t const i)
        {
            return i>>1;
        }
        size_t left(size_t const i)
        {
            return i<<1;
        }
        size_t right(size_t const i)
        {
            return (i<<1)+1;
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
                size_t size()
                {
                    return vec.size();
                }
                void pop_back()
                {
                    vec.pop_back();
                }
            private:
                std::vector<U> vec;
        };

};

} // namespace XY

int main(int argc, char const* argv[])
{
    std::vector<int> v = {465, 12, 684, 9, -5};
    XY::heap<int> heap(v);
    std::vector<int> r(heap.heap_sort());
    for(int i = 0; i < r.size(); ++i)
        std::cout<<r[i]<<" ";
    std::cout<<std::endl;
    return 0;
}


