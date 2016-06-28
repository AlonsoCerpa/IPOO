#include "CircularList.h"
#include <iostream>
#include "Node.h"

template<typename T>
CircularList<T>::~CircularList()
{
    Node<T> *auxPtr = firstNode;
    Node<T> *tempPtr;
    while (auxPtr != lastNode)
    {
        tempPtr = auxPtr->nextNode;
        delete auxPtr;
        auxPtr = tempPtr;
    }
    delete auxPtr;
}

template<typename T>
bool CircularList<T>::isEmpty() const
{
    if (firstNode == nullptr)
        return true;
    else
        return false;
}

template<typename T>
void CircularList<T>::pushBack(const T &_data)
{
    Node<T> *newNode = new Node<T>(_data);
    if (isEmpty())
    {
        firstNode = lastNode = newNode;
        firstNode -> nextNode = newNode;
    }
    else
    {
        lastNode -> nextNode = newNode;
        lastNode = newNode;
        newNode -> nextNode = firstNode;
    }
}

template<typename T>
T CircularList<T>::popBack()
{
    if(isEmpty())
    {
        return 0;
        std::cout << "Circular list is empty" << std::endl;
    }
    else
    {
        T dataReturned;

        if (firstNode == lastNode)
        {
            dataReturned = firstNode -> data;
            delete firstNode;
            firstNode = lastNode = nullptr;
        }

        else
        {
            Node<T> *auxPtr = firstNode;
            Node<T> *tempPtr;
            while (auxPtr != lastNode)
            {
                tempPtr = auxPtr;
                auxPtr = auxPtr -> nextNode;
            }
            dataReturned = lastNode -> data;
            delete lastNode;
            lastNode = tempPtr;
            lastNode -> nextNode = firstNode;
        }

        return dataReturned;
    }
}

template<typename T>
void CircularList<T>::print()
{
    if (isEmpty())
    {
        std::cout << "The circular list is empty" << std::endl;
    }
    else
    {
        if (firstNode == lastNode)
        {
            std::cout << firstNode -> data << std::endl;
        }
        else
        {
            std::cout << firstNode -> data << " -> ";
            Node<T> *auxPtr = firstNode -> nextNode;
            while (auxPtr != firstNode)
            {
                std::cout << auxPtr -> data << " -> ";
                auxPtr = auxPtr -> nextNode;
            }
            std::cout << std::endl;
        }
    }
}

template<typename T>
CircularList<T> &CircularList<T>::operator+(const CircularList<T> &circList)
{
    CircularList newCL = *(new CircularList);

    Node<T> *auxPtr = this->firstNode;
    while (auxPtr != this->lastNode)
    {
        newCL.pushBack(auxPtr->data);
        auxPtr = auxPtr -> nextNode;
    }
    newCL.pushBack(auxPtr->data);

    auxPtr = circList.firstNode;
    while (auxPtr != circList.lastNode)
    {
        newCL.pushBack(auxPtr->data);
        auxPtr = auxPtr -> nextNode;
    }
    newCL.pushBack(auxPtr->data);

    return newCL;
}

template class CircularList<int>;

