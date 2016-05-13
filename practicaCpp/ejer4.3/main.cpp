#include <iostream>

using namespace std;

int sum(const int &num1, const int &num2, const int &num3 = 0, const int &num4 = 0)
{
    return num1 + num2 + num3 + num4;
}

int main()
{
    int x = sum(2, 4);
    int y = sum(3, 5, 7);
    int z = sum(1, 2, 4, 8);
    cout << x << " " << y << " " << z << "\n";
    return 0;
}
