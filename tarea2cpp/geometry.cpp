#include <iostream>
#include "geometry.h"

using namespace std;

Point::Point(int x1 = 0, int y1 = 0) : x(x1), y(y1) {}

int Point::getX() const
	{
		return x;
	}
int Point::getY() const
{
	return y;
}
void Point::setX(const int new_x)
{
	x = new_x;
}
void Point::setY(const int new_y)
{
	y = new_y;
}

int main()
{
	Point a(2, 4);
	cout << a.getX() << endl;
	a.setX(10);
	cout << a.getX() << endl;
	return 0;
}