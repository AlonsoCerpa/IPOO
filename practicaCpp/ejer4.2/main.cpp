/*
Porque las numeros que se van a sumar son de diferentes
tipos y las funciones de suma solo reciben sus 2 argumentos
de un mismo tipo.
*/

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
    int x = sumInt(1, 10.0);
    cout << x << "\n";
    return 0;
}

