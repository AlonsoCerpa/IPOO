#include "Node.h"

template class Node<int>;

template<typename T>
Node<T>::Node(const T &_data)
    : data{_data} {}


