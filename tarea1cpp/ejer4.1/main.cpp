#include <iostream>

using namespace std;

int sumInt(const int &num1, const int &num2)
{
    return num1 + num2;
}

double sumDoub(const double &num1, const double &num2)
{
    return num1 + num2;
}

int main()
{
    int x = sumInt(4, 7);
    double y = sumDoub(4.2, 3.1);
    cout << x << " " << y << "\n";
    return 0;
}
