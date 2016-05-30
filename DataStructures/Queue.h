#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

#include "List.h"

template<typename QUEUETYPE>
class Queue : private List<QUEUETYPE>
{
public:
    void enqueue(const QUEUETYPE &value)
    {
        insertEnd(value);
    }
    bool dequeue(QUEUETYPE &value)
    {
        return deleteEnd(value);
    }
    bool isEmptyQueue()
    {
        return isEmpty();
    }
    void printQueue()
    {
        printList();
    }
};

#endif // QUEUE_H_INCLUDED
