#include <iostream>

using namespace std;

int main()
{
    float celcius;
    int ini = 0;
    int fin = 300;
    float paso = 20.0;
    float fahrenheit = ini;

    cout << "Tabla de conversion de Fahrenheit a Celcius:" << endl;
    while(fahrenheit <= fin)
    {
        celcius = (5.0/9.0)*(fahrenheit - 32.0);
        cout << fahrenheit <<"\t"<< celcius << endl;
        fahrenheit = fahrenheit + 20;
    }
    return 0;
}
