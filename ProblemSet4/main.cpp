#include <iostream>
#include "Geometry.h"
#define min(x, y) (x < y) ? x : y          //Ex. 2.2

using std::cout;
using std::endl;
/*
template<typename T>                        //Ex. 2.1
T min(const T &val1, const T &val2)
{
    return (val1 < val2) ? val1 : val2;
}

template <>
char min<char>(const char &val1, const char &val2)
{
    cout << "Imprime segun la tabla ASCII" << endl;
    return (val1 < val2) ? val1 : val2;
}
*/


int main()
{
    Rectangle *rect = new Rectangle{{2, 3}, {4, 5}};
    Triangle *tri1 = reinterpret_cast<Triangle *>(rect); //Ex. 3.1
    cout << tri1->getArea() << endl;


    Triangle *tri2 = dynamic_cast<Triangle *>(rect); //Ex. 3.2
    if (tri2 == nullptr)
        cout << "tri2 es un nullptr" << endl;
    /*
    int y = min<int>(4, 7);
    cout << y << endl << endl;

    char x = min<char>('c', 'b');
    cout << x << endl;
*/
    int a = min(4, 5);
    cout << a << endl;

    char b = min('r', 'b');
    cout << b << endl;

    return 0;
}
