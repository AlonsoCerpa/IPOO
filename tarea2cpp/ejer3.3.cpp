#include <iostream>

using namespace std;

class Point
{
private:
	int x, y;
public:
	Point(int x1 = 0, int y1 = 0) : x(x1), y(y1) {}
	int getX() const
	{
		return x;
	}
	int getY() const
	{
		return y;
	}
	void setX(const int new_x)
	{
		x = new_x;
	}
	void setY(const int new_y)
	{
		y = new_y;
	}
};

int main()
{
	Point a(2, 4);
	cout << a.getX() << endl;
	a.setX(10);
	cout << a.getX() << endl;
	return 0;
}