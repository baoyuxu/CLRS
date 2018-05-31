#ifndef QUEUE_H
#define QUEUE_H

#include <cstddef>
namespace XY
{
template<typename T>
class queue
{
public:
    queue()
        :_head(0), _tail(0), _capaticy(128), _elem(new T[_capaticy])
    {}
    void enqueue(T const &o)
    {
        _elem[_tail++] = o;
        if(_tail==_capaticy)
            _tail=0;
    }
    void enqueue(T &&o)
    {
        _elem[_tail++] = o;
        if(_tail==_capaticy)
            _tail=0;
    }
    T dequeue()
    {
        size_t h = _head++;
        if(_head==_capaticy)
            _head = 0;
        return _elem[h];
    }
    ~queue()
    {
        delete[] _elem;
    }
private:
    size_t _head;
    size_t _tail;
    size_t _capaticy;
    T *_elem;
};
}

#endif //QUEUE_H
