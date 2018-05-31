#ifndef STACK_H
#define STACK_H
#include <cstddef>

namespace XY
{

template<typename T>
class stack
{
    public:
        stack()
            :_top(0), _capacity(128), _elem(new T [_capacity])
        {}
        bool empty()
        {
            return _top==0;
        }
        void push(T const &o)
        {
            _elem[_top++] = o;
        }
        void push(T &&o)
        {
            _elem[_top++] = o;
        }
        T const pop()
        {
            return _elem[--_top];
        }
        ~stack()
        {
            delete[] _elem;
        }
    private:
        size_t _top;
        size_t _capacity;
        T *_elem;
};

}//namespace XY


#endif //STACK_H
