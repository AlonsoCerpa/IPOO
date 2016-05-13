#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

double calcPi(int n)
{
    double x, y;
    double inCirc = 0;
    int rad = 1;

    srand(time(0));
    for (int i = 0; i < n; i++){
        x = (double) rand() / RAND_MAX;
        y = (double) rand() / RAND_MAX;
        if (sqrt(pow(0 - x, 2) + pow(0 - y, 2)) <= rad){
            ++inCirc;
        }
    }
    return (4 * (inCirc / n)) / pow(rad, 2);
}

int main()
{
    double pi = calcPi(5000000);

    cout << pi << endl;
    return 0;
}
