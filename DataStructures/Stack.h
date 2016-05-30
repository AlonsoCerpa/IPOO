#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include "List.h"

template<typename STACKTYPE>
class Stack : private List<STACKTYPE>
{
public:
    void push(const STACKTYPE &value)
    {
        insertBeginning(value);
    }
    bool pop(STACKTYPE &value)
    {
        return deleteBeginning(value);
    }
    bool isEmptyStack() const
    {
        return isEmpty();
    }
    void printStack() const
    {
        printList();
    }
};

#endif // STACK_H_INCLUDED
