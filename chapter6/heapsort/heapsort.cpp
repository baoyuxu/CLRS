#include<iostream>
#include<functional>
#include<vector>

#ifdef DEBUG
#define private public
#endif

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
            :_heap(heap_vec<T>(h)), _compare(Compare()), _size(_heap.size())
        {
            heap_build();
        }

        void insert(T const &o)
        {
            _heap.push_back(o);
            ++_size;
            size_t pos = _size;
            while(pos>1 && compare(_heap[pos], _heap[parent(pos)]))
            {
                std::swap(_heap[pos], _heap[parent(pos)]);
                pos = parent(pos);
            }
        }
        void insert(T &&o)
        {
            _heap.push_back(o);
            ++_size;
            size_t pos = _size;
            while(pos>1 && compare(_heap[pos], _heap[parent(pos)]))
            {
                std::swap(_heap[pos], _heap[parent(pos)]);
                pos = parent(pos);
            }
        }
        T const &maximum()
        {
            return _heap[1];
        }
        void extract_maximum()
        {
            _heap[1] = _heap[_size];
            _heap.pop_back();
            --_size;
        }
        void increase_key(size_t p, T const &k)
        {
            size_t pos = p+1;
            while(pos > 1&& compare(k, _heap[parent(pos)]) )
            {
                _heap[pos] = _heap[parent(pos)];
                pos = parent(pos);
            }
            _heap[pos] = k;
        }
        void increase_key(size_t p, T &&k)
        {
            size_t pos = p+1;
            while(pos > 1 && compare(k, _heap[parent(pos)]) )
            {
                _heap[pos] = _heap[parent(pos)];
                pos = parent(pos);
            }
            _heap[pos] = k;
        }

        std::vector<T> heap_sort()
        {
            std::vector<T> result;
            size_t s = size();
            for(size_t i=0; i<s; ++i)
            {
                result.push_back(_heap[1]);
                std::swap(_heap[1], _heap[s-i]);
                heap_ify(1, s-i-1);
            }
            return result;
        }

    private:
        heap_vec<T> _heap;
        Compare _compare;
        size_t _size;
        void heap_ify(size_t const i, size_t size)
        {
            size_t l_offset = left(i);
            size_t r_offset = right(i);
            size_t largest = i;
            if(l_offset <= size && _compare(_heap[l_offset], _heap[largest]))
                largest = l_offset;
            if(r_offset <= size && _compare(_heap[r_offset], _heap[largest]))
                largest = r_offset;
            std::swap(_heap[i], _heap[largest]);
            if(largest != i)
                heap_ify(largest, size);
        }

        void heap_build()
        {
            for(size_t i = _size/2; i>=1; --i)
                heap_ify(i, _size);
        }

        size_t size()
        {
            return _size;
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
                void push_back(T const &o)
                {
                    vec.push_back(o);
                }
                void push_back(T &&o)
                {
                    vec.push_back(o);
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


