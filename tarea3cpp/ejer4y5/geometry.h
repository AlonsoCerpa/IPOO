//Clase Point

class Point
{
public:
    Point(int x1 = 0, int y1 = 0);
    int getX() const;
    int getY() const;
    void setX(const int &new_x);
    void setY(const int &new_y);
protected:
    int x, y;
};

//Clase PointArray

class PointArray
{
public:
    PointArray();
    PointArray(const Point points[], const int &_size);
    PointArray(const PointArray &pv);
    ~PointArray();
    void showPoint(const int &pos);
    void push_back(const Point &p);
    void insert(const int &position, const Point &p);
    void remove(const int &pos);
    const int getSize() const;
    void clear();
    Point* get(const int &position);                //Permite modificar al PointArray, ya que nos devuelve un puntero a Point.
    const Point* get(const int &position) const;    //Solo para leer la informacion del Point, pero no para cambiarla.
private:
    void resize(const int &newLength);

    Point* firstPoint;
    int length;
};

//Clase abstracta Polygon

class Polygon
{
public:
    Polygon(const Point points[], const int &len);
    Polygon(const PointArray &pA);
    Polygon(const Polygon &pol);
    ~Polygon() {--numPol;}
    virtual double getArea() const = 0;             //La hace una clase abstracta
    int getNumPolygons() const {return numPol;}
    int getNumSides() const {return ptArr.getSize();}
    const PointArray *getPoints() const {return &ptArr;}
protected:
    PointArray ptArr;                               //Creo el objeto PointArray, de otra clase
    static int numPol;
};

//Subclase Rectangle de la clase base Polygon

class Rectangle : public Polygon                    //Hereda ptArr, mas no numPol
{
public:
    Rectangle(const Point &p1, const Point &p2);
    Rectangle(const int &n1, const int &n2, const int &n3, const int &n4);
    virtual double getArea() const;
};

//Subclase Triangle de la clase base Polygon

class Triangle : public Polygon
{
public:
    Triangle(const Point& p1, const Point& p2, const Point& p3);
    virtual double getArea() const;
};






