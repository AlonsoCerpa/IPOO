#include <iostream>

using namespace std;

int sum(const int &num1, const int &num2, const int &num3 = 0, const int &num4 = 0)
{
    return num1 + num2 + num3 + num4;
}

int main()
{
    int y = sum(3, 5, 7);
    cout << y << endl;
    return 0;
}
