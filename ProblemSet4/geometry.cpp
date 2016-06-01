#include <iostream>
#include <cmath>
#include "geometry.h"

using std::cout;
using std::endl;

//Clase Point

Point::Point(int x1, int y1) : x{x1}, y{y1} {}

int Point::getX() const{
    return x;
}

int Point::getY() const{
    return y;
}

void Point::setX(const int &new_x){
    x = new_x;
}

void Point::setY(const int &new_y){
    y = new_y;
}

//Clase PointArray

PointArray::PointArray(){
    length = 0;
    firstPoint = new Point[0];
}

PointArray::PointArray(const Point points[], const int &_size){
    length = _size;
    firstPoint = new Point[_size];
    for (int i = 0; i < _size; i++){
        firstPoint[i] = points[i];
    }
}

PointArray::PointArray(const PointArray &pv){
    length = pv.length;
    firstPoint = new Point[length];
    for (int i = 0; i < length; i++){
        firstPoint[i] = pv.firstPoint[i];
    }
}

PointArray::~PointArray(){
    delete[] firstPoint;
}

void PointArray::resize(const int &newLength){
    if (newLength >= 0 ){
        Point *aux = new Point[newLength];
        int actualLength = (newLength < length ? newLength : length);
        for (int i = 0; i < actualLength; i++){
            aux[i] = firstPoint[i];
        }
        delete[] firstPoint;
        firstPoint = aux;
        length = newLength;
    }
    else{
        cout << "Ingrese un tamaño valido" << endl;
    }
}

void PointArray::push_back(const Point &p){
    resize(length + 1);                          //Dentro de resize length aumenta en 1
    firstPoint[length - 1] = p;
}

void PointArray::insert(const int &position, const Point &p){
    resize(length + 1);
    for (int i = length - 1; i > position; i--){  //Desplazamiento en 1 a la derecha de todos los elementos
        firstPoint[i] = firstPoint[i - 1];        //que estan despues de position
    }
    firstPoint[position] = p;
}

void PointArray::remove(const int &pos){
    if (pos >= 0 && pos < length){
        for (int i = pos; i < length - 1; i++){
            firstPoint[i] = firstPoint[i + 1];
        }
        resize(length - 1);
    }
    else{
        cout << "Ingrese una posicion valida" << endl;
    }
}

const int PointArray::getSize() const{
    return length;
}

void PointArray::clear(){
    resize(0);
}

Point* PointArray::get(const int &position){
    if (position >= 0 && position < length){
        return firstPoint + position;
    }
    else{
        return NULL;
    }
}

const Point* PointArray::get(const int &position) const{
    if (position >= 0 && position < length){
        return firstPoint + position;
    }
    else{
        return NULL;
    }
}

void PointArray::showPoint(const int &pos){
    cout << "x: " << firstPoint[pos].getX() << endl;
    cout << "y: " << firstPoint[pos].getY() << endl;
}

//Clase Polygon

int Polygon::numPol = 0;

Polygon::Polygon(const Point points[], const int &len)
    : ptArr{points, len} {
    ++numPol;
}

Polygon::Polygon(const PointArray &pA)
    : ptArr{pA} {
    ++numPol;
}

Polygon::Polygon(const Polygon &pol)
    : ptArr{pol.ptArr} {
    ++numPol;
}

//Rectangle: Clase derivada de Polygon

Point constructorPoints[4];                                    //Sirve para obtener los Points resultantes
                                                               //de updateConstructorPoints()
Point *updateConstructorPoints(const Point &p1, const Point &p2,
                               const Point &p3, const Point &p4){
    constructorPoints[0] = p1;
    constructorPoints[1] = p2;
    constructorPoints[2] = p3;
    constructorPoints[3] = p4;
    return constructorPoints;
    }

Rectangle::Rectangle(const Point &p1, const Point &p2)
    : Polygon{updateConstructorPoints(p1, Point{p1.getX(), p2.getY()},
    p2, Point{p2.getX(), p1.getY()}), 4} {}

Rectangle::Rectangle(const int &p1x, const int &p1y, const int &p2x,
                     const int &p2y)
    : Polygon{updateConstructorPoints(Point{p1x, p1y}, Point{p1x, p2y},
    Point{p2x, p2y}, Point{p2x, p1y}), 4} {}

double Rectangle::getArea() const{
    int width = ptArr.get(0)->getX() - ptArr.get(2)->getX();   //Puntos diagonales del
    int length = ptArr.get(0)->getY() - ptArr.get(2)->getY();  //rectanguo
    return (double) std::abs(width * length);
}

//Triangle: Clase derivada de Polygon

Point trianglePoints[3];                                    //Sirve para obtener los Points resultantes
                                                            //de updateConstructorPoints()
Point *updateTrianglePoints(const Point &p1, const Point &p2,
                               const Point &p3){
    trianglePoints[0] = p1;
    trianglePoints[1] = p2;
    trianglePoints[2] = p3;
    return trianglePoints;
    }

Triangle::Triangle(const Point& p1, const Point& p2, const Point& p3)
    : Polygon{updateTrianglePoints(p1, p2, p3), 3} {}

double Triangle::getArea() const{
    int ax = std::abs(ptArr.get(0)->getX() - ptArr.get(1)->getX()),
        ay = std::abs(ptArr.get(0)->getY() - ptArr.get(1)->getY()),
        bx = std::abs(ptArr.get(1)->getX() - ptArr.get(2)->getX()),
        by = std::abs(ptArr.get(1)->getY() - ptArr.get(2)->getY()),
        cx = std::abs(ptArr.get(2)->getX() - ptArr.get(0)->getX()),
        cy = std::abs(ptArr.get(2)->getY() - ptArr.get(0)->getY());
    double a = std::sqrt(pow(ax, 2) + pow(ay, 2)),
           b = std::sqrt(pow(bx, 2) + pow(by, 2)),
           c = std::sqrt(pow(cx, 2) + pow(cy, 2));
    double s = (a + b + c) / 2;

    return std::sqrt(s * (s - a) * (s - b) - (s - c));
}








