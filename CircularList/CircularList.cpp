#include "CircularList.h"
#include <iostream>
#include "Node.h"

template class CircularList<int>;

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
    CircularList &newCL = *(new CircularList);

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

template<typename T>
bool CircularList<T>::operator==(const CircularList<T> &circList)
{
    if (this == &circList)
    {
        std::cout << "Comparing the same list" << std::endl;
        return true;
    }

    else
    {
        if (this->isEmpty() && circList.isEmpty())
            return true;
        else if ((this->isEmpty() && circList.firstNode != nullptr)
                 || (circList.isEmpty() && this->firstNode != nullptr))
            return false;

        Node<T> *auxPtr1 = this->firstNode;
        Node<T> *auxPtr2 = circList.firstNode;
        while (auxPtr1->data == auxPtr2->data && auxPtr1 != this->lastNode
               && auxPtr2 != circList.lastNode)
        {
            auxPtr1 = auxPtr1->nextNode;
            auxPtr2 = auxPtr2->nextNode;
        }

        if (auxPtr1 == this->lastNode && auxPtr2 == circList.lastNode &&
            auxPtr1->data == auxPtr2->data)
            return true;
        else
            return false;
    }
}


