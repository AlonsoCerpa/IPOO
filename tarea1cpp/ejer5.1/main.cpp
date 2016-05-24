#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    double x, y;

    srand(time(0));
    x = (double) rand() / RAND_MAX;
    y = (double) rand() / RAND_MAX;
    cout << x << "\n" << y << endl;
    return 0;
}
