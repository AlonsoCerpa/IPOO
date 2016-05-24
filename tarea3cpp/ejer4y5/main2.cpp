#include "geometry.h"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

//Ejer 5.7:

void printAttributes(Polygon *pol){
    if (pol -> getNumSides() == 4){
        cout << "El area del rectangulo es: " << pol -> getArea() << endl;
    }
    else if (pol -> getNumSides() == 3){
        cout << "El area del triangulo es: " << pol -> getArea() << endl;
    }

    cout << "Puntos\t(x, y)" << endl;
    for (int i = 0; i < pol->getNumSides(); i++){
        cout << "Punto" << i + 1 << ":\t" << "(" << pol->getPoints()->get(i)->
        getX() << ", " << pol->getPoints()->get(i)->getY() << ")" << endl;
    }
}

int main()
{
/*
    Rectangle r{{2, 3}, {5, 8}};
    //cout << r.getNumPolygons() << endl;
    cout << r.getArea() << endl;
    Triangle t{{2, 3}, {5, 8}, {7, 4}};
    cout << t.getArea() << endl;
    printAttributes(&r);
    cout << endl;
    printAttributes(&t);
*/
    cout << "Ingrese las coordenadas de los vertices de la parte inferior-izquierda y superior-derecha de un rectangulo, en forma de 4 enteros:" << endl;

    int r1x, r1y, r2x, r2y;

    cin >> r1x >> r1y >> r2x >> r2y;
    Rectangle r{{r1x, r1y}, {r2x, r2y}};
    printAttributes(&r);

    cout << "Ingrese las coordenas de los vertices de un triangulo, en forma de 6 enteros:" << endl;

    int t1x, t1y, t2x, t2y, t3x, t3y;

    cin >> t1x >> t1y >> t2x >> t2y >> t3x >> t3y;
    Triangle t{{t1x, t1y}, {t2x, t2y}, {t3x, t3y}};
    printAttributes(&t);

    return 0;
}

/*
Ejer. 5.2:
Si usamos el destructor copia por defecto, se copian los atributos,
en este caso solo tenemos un objeto tipo PointArray, entonces se
llamaria a su constructor de copia de PointArray y se copiarian
sus atributos, es decir los objetos tipo Point al nuevo objeto tipo
Polygon.

Ejer. 5.6:
1. No se podrian crear instancias de la clase Point.

2. Se disminuye en 1 numPol y se destruye su unico atributo, el objeto
PointArray, para destruir ese objeto se llama al destructor de
PointArray, para que libere la  memoria asignada dinamicamente al
arreglo firstPoint.

3. Para que estos puedan ser accesados por las clases derivadas de
Polygon, como son Rectangle y Triangle.

4. La version de Polygon, porque la estamos llamando desde un puntero
a Polygon, para que se pueda llamar a sus versiones de clases derivadas,
se tiene que escribir "virtual" antes del tipo de retorno de la funcion,
solo es necesario en la clase base, pero tambien se puede escribe en
todas las subclases para una mejor legibilidad del codigo.
*/


