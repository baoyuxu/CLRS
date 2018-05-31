#ifndef HEADER_H
#define HEADER_H

#include<iostream>

namespace XY
{
template<typename T>
struct node;
template<typename T>
class list;

template<typename T>
struct node
{
    node(node *p,node *n, T const &vl)
        :prev(p), next(n), v(vl)
    {}
    node(node *p, node *n, T &&vl)
        :prev(p), next(n), v(vl)
    {}
    node *prev;
    node *next;
    T v;
};

template<typename T>
class list
{
public:
    class iterator;
    list();
    iterator begin();
    iterator end();
    iterator search(T &&o);
    iterator search(T const &o);
    void delete_node(iterator &iter);
    void insert(T const &o);
    void insert(T &&o);
    ~list();
private:
    node<T> *_head;
    node<T> *_tail;
    iterator _end;
};
template<typename T>
class list<T>::iterator
{
public:
    iterator()
        :_v{nullptr}
    {}
    iterator(node<T> *v)
        :_v{v}
    {}
    iterator operator++(int)
    {
        auto ret = *this;
        _v = _v->next;
        return ret;
    }
    iterator &operator++()
    {
        _v = _v->next;
        return *this;
    }
    iterator operator--(int)
    {
        auto ret = *this;
        _v = _v->prev;
        return ret;
    }
    iterator &operator--()
    {
        _v = _v->prev;
        return *this;
    }
    node<T> &operator*()
    {
        return *_v;
    }
    node<T>* operator->()
    {
        return _v;
    }
    bool operator!=(list<T>::iterator const &o)
    {
        return _v != o._v;
    }
    bool operator==(list<T>::iterator const &o)
    {
        return _v == o._v;
    }
private:
    node<T> *_v;
};

template<typename T>
list<T>::list()
    :_head{new node<T>(nullptr, nullptr, 0)}, _tail{new node<T>(_head, nullptr, 0)}, _end{_tail}
{
    _head->next = _tail;
}

template<typename T>
void list<T>::insert(T const &o)
{
    node<T> *n = new node(_head, _head->next, o);
    _head->next = n;
    n->next->prev = n;
}
template<typename T>
void list<T>::insert(T &&o)
{
    node<T> *n = new node(_head, _head->next, o);
    _head->next = n;
    n->next->prev = n;
}

template<typename T>
typename list<T>::iterator list<T>::begin()
{
    return list<T>::iterator(_head->next);
}
template<typename T>
typename list<T>::iterator list<T>::end()
{
    return _end;
}

template<typename T>
typename list<T>::iterator list<T>::search(T &&o)
{
    auto it = list<T>::begin();
    while(it != list<T>::end())
    {
        if((it++)->v == o)
            break;
    }
    return --it;
}
template<typename T>
typename list<T>::iterator list<T>::search(T const &o)
{
    auto it = list<T>::begin();
    while(it != list<T>::end())
    {
        if(*it++->v == o)
            break;
    }
    return it;
}

template<typename T>
void list<T>::delete_node(typename list<T>::iterator &iter)
{
    iter->prev->next = iter->next;
    iter->next->prev = iter->prev;
    delete &*iter;
}

template<typename T>
list<T>::~list()
{
    while(_head)
    {
        auto d = _head;
        _head = _head->next;
        delete d;
    }
}

}// namespace XY
#endif
