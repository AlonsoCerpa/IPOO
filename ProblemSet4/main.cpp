#include <iostream>

#include "Geometry.h"
#include "templates.h"
#include "graph.h"

#define min(x, y) (x < y) ? x : y          //Ex. 2.2

using std::cout;
using std::endl;

int main()
{
    Rectangle *rect = new Rectangle{{2, 3}, {4, 5}};
    Triangle *tri1 = reinterpret_cast<Triangle *>(rect); //Ex. 3.1
    cout << tri1->getArea() << endl;
/////////////////////////////////////////////////////////////////////////////
    Triangle *tri2 = dynamic_cast<Triangle *>(rect); //Ex. 3.2
    if (tri2 == nullptr)
        cout << "tri2 es un nullptr" << endl;
//////////////////////////////////////////////////////////////////////////
    int y = min<int>(4, 7);
    cout << y << endl << endl;

    char x = min<char>('c', 'b');
    cout << x << endl;
/////////////////////////////////////////////////////////////////////
    int a = min(4, 5);
    cout << a << endl;

    char b = min('r', 'b');
    cout << b << endl << endl;
/////////////////////////////////////////////////////////////////////
    Stack <int> j;
    j.push(3);
    j.push(4);
    j.pop();
    cout << j.top() << endl;

    Stack<int> k;
    k.push(8);
    k.push(11);

    Stack<int> l = j + k;
    cout << l.top() << endl;
//////////////////////////////////////////////////////////////
    Graph gr({4, 4, 4, 6, 7}, {1, 2, 4, 8, 12});
    cout << gr.numOutgoing(4) << endl;

    return 0;
}
