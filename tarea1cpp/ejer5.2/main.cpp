#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

int main()
{
    double x, y;
    int inCirc = 0, rad = 1, n = 5;

    srand(time(0));
    for (int i = 0; i < n; i++){
        x = (double) rand() / RAND_MAX;
        y = (double) rand() / RAND_MAX;
        cout << x << "\n" << y << "\n\n";
        if (sqrt(pow(0 - x, 2) + pow(0 - y, 2)) <= 1){
            ++inCirc;
        }
    }
    cout << inCirc << endl;
    return 0;
}
