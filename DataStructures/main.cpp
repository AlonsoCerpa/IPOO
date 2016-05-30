#include "Stack.h"
#include "Queue.h"

int main()
{
    List<int> a;
    a.insertBeginning(4);
    a.insertBeginning(2);
    a.insertBeginning(5);
    a.printList();
    int var1;
    if(a.deleteEnd(var1))
        cout << "The last element with value " << var1 << " was deleted." << endl;
    a.printList();
    cout << endl;
/////////////////////////////////////////////////////////////////////////
    List<double> b;
    b.insertEnd(2.5);
    b.insertEnd(8.9);
    b.insertEnd(3.1);
    b.printList();
    double var2;
    if(b.deleteBeginning(var2))
        cout << "The first element with value " << var2 << " was deleted." << endl;
    b.printList();
    cout << endl;
/////////////////////////////////////////////////////////////////////////
    Stack<float> c;
    c.push(0.054);
    c.push(65.4);
    c.push(0.0001);
    c.printStack();

    float var3;
    c.pop(var3);
    cout << var3 << endl;
    c.printStack();
/////////////////////////////////////////////////////////////////////////
    Queue<long> d;
    d.enqueue(4589);
    d.enqueue(4589);
    d.enqueue(4589);
    d.printQueue();

    long var4;
    d.dequeue(var4);
    cout << var4 << endl;
    d.printQueue();

    return 0;
}
