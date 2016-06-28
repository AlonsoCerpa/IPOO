#ifndef CIRCULARLIST_H_INCLUDED
#define CIRCULARLIST_H_INCLUDED

#include "Node.h"

template<typename T> class Node;

template<typename T>
class CircularList
{
public:
    ~CircularList();
    void pushBack(const T &_data);
    T popBack();
    void print();
    CircularList<T> &operator+(const CircularList<T> &circList);
private:
    bool isEmpty() const;

    Node<T> *firstNode{nullptr};
    Node<T> *lastNode{nullptr};
};

#endif // CIRCULARLIST_H_INCLUDED
