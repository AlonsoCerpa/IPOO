#include "Node.h"

template<typename T>
Node<T>::Node(const T &_data)
    : data{_data} {}

template class Node<int>;
