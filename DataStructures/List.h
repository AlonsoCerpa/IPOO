#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

#include <iostream>
using std::cout;
using std::endl;

#include "NodeList.h"

template<typename NODETYPE>
class List
{
public:
    List();
    ~List();
    void insertBeginning(const NODETYPE &);
    void insertEnd(const NODETYPE &);
    bool deleteBeginning(NODETYPE &);
    bool deleteEnd(NODETYPE &);
    bool isEmpty() const;
    void printList() const;
private:
    NodeList<NODETYPE> *firstPtr;
    NodeList<NODETYPE> *lastPtr;

    NodeList<NODETYPE> *getNewNode(const NODETYPE &);
};

/////////////////////////////////////////////////////////


template<typename NODETYPE>
List<NODETYPE>::List()
    : firstPtr{nullptr}, lastPtr{nullptr} {}

template<typename NODETYPE>
List<NODETYPE>::~List(){
    if (!isEmpty()){
        NodeList<NODETYPE> *currentPtr = firstPtr;
        NodeList<NODETYPE> *tempPtr;
        while (currentPtr != nullptr){
            tempPtr = currentPtr;
            currentPtr = currentPtr -> nextPtr;
            delete tempPtr;
        }
    }
}

template<typename NODETYPE>
void List<NODETYPE>::insertBeginning(const NODETYPE &data){
    NodeList<NODETYPE> *newPtr = getNewNode(data);
    if (isEmpty()){
        firstPtr = lastPtr = newPtr;
    }
    else{
        newPtr -> nextPtr = firstPtr;
        firstPtr = newPtr;
    }
}

template<typename NODETYPE>
void List<NODETYPE>::insertEnd(const NODETYPE &data){
    NodeList<NODETYPE> *newPtr = getNewNode(data);
    if (isEmpty()){
        firstPtr = lastPtr = newPtr;
    }
    else{
        lastPtr -> nextPtr = newPtr;
        lastPtr = newPtr;
    }
}

template<typename NODETYPE>
bool List<NODETYPE>::deleteBeginning(NODETYPE &value){
    if (isEmpty()){
        return false;
    }
    else{
        NodeList<NODETYPE> *tempPtr = firstPtr;
        if (firstPtr == lastPtr){
            firstPtr = lastPtr = nullptr;
        }
        else{
            firstPtr = firstPtr -> nextPtr;
        }
        value = tempPtr -> data;
        delete tempPtr;
        return true;
    }
}

template<typename NODETYPE>
bool List<NODETYPE>::deleteEnd(NODETYPE &value){
    if (isEmpty()){
        return false;
    }
    else{
        NodeList<NODETYPE> *tempPtr = lastPtr;
        if (firstPtr == lastPtr){
            firstPtr = lastPtr = nullptr;
        }
        else{
            NodeList<NODETYPE> *currentPtr = firstPtr;
            while (currentPtr -> nextPtr != lastPtr){
                currentPtr = currentPtr -> nextPtr;
            }
            lastPtr = currentPtr;
            currentPtr -> nextPtr = nullptr;
        }
        value = tempPtr -> data;
        delete tempPtr;
        return true;
    }
}

template<typename NODETYPE>
bool List<NODETYPE>::isEmpty() const {
    return firstPtr == nullptr;
}

template<typename NODETYPE>
NodeList<NODETYPE> *List<NODETYPE>::getNewNode(const NODETYPE &value){
    return new NodeList<NODETYPE>{value};
}

template<typename NODETYPE>
void List<NODETYPE>::printList() const {
    if (isEmpty()){
        cout << "The list is empty" << endl;
        return;
    }
    NodeList<NODETYPE> *currentPtr = firstPtr;
    cout << "The list is: ";
    while (currentPtr != nullptr){
        cout << currentPtr -> data << ' ';
        currentPtr = currentPtr -> nextPtr;
    }
    cout << endl;
}

#endif // LIST_H_INCLUDED
