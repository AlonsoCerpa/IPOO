#include <iostream>
#include "geometry.h"

using std::cout;
using std::endl;

int main()
{
    Point arrPoints[3];              //arreglo de Points
    arrPoints[2] = {4, 2};

    PointArray pA1{arrPoints, 3};    //objeto tipo PointArray
    PointArray pA2{pA1};             //Copio pA1 a pA2

    Point nuevo1{14, 25};
    pA2.push_back(nuevo1);           //insertar al final del arreglo

    Point nuevo2{5, 6};
    pA2.insert(1, nuevo2);
    pA2.showPoint(1);
    pA2.showPoint(4);                //Point nuevo1 en pos. 4
    cout << pA2.getSize() << endl;

    pA2.remove(3);
    pA2.showPoint(3);                //Ahora Point pos. 4 pasa a pos. 3
    cout << pA2.getSize() << endl;

    Point *ptrP = pA2.get(3);
    cout << ptrP->getX() << endl;
    cout << ptrP->getY() << endl;

    pA2.clear();
    cout << pA2.getSize() << endl;

/*
Ejer- 4.5.1:
Se necesita una version const para que al llamar a la funcion desde un const ArrayPoint,
se puedan devolver punteros a const Point, de esta manera si se acceden a los valores de los
puntos, no van a poder modificarse, solo leerse; pero ademas se necesita uno sin const para que se retorne
un puntero a Point, donde los atributos del objeto Point si pueden ser cambiados y tambien leidos.
*/

    return 0;
}
