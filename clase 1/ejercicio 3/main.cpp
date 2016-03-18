#include <iostream>

using namespace std;

int main()
{
    float fahrenheit;
    int ini = 0;
    int fin = 300;
    float paso = 20.0;
    float celcius = ini;

    cout << "Tabla de conversion de Celcius a Fahrenheit:" << endl;
        while(celcius <= fin)
        {
        fahrenheit = (9.0 * celcius)/5.0 + 32.0;
        cout << celcius << "\t" << fahrenheit << endl;
        celcius = celcius + 20;
        }
    return 0;
}
