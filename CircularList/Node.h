#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED

#include "CircularList.h"

template<typename T> class CircularList;

template <typename T>
class Node
{
    friend class CircularList<T>;
public:
    Node(const T &_data);
private:

    Node *createNewNode();

    T data;
    Node<T> *nextNode{nullptr};
};

#endif // NODE_H_INCLUDED
