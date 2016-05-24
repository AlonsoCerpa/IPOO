#include <iostream>

using namespace std;

int main()
{
    char *oddOrEven = "Never odd or even";
    char *nthCharPtr = &oddOrEven[5]; //preg. 1
    nthCharPtr -= 2;                //preg. 2
    cout << *nthCharPtr << "\n";    //preg. 3
    char **pointerPtr = &nthCharPtr; //preg. 4
    cout << *pointerPtr << "\n";   //preg. 5
    cout << **pointerPtr << "\n";  //preg. 6
    nthCharPtr += 1;               //preg. 7
    cout << nthCharPtr - oddOrEven << endl; //preg. 8

    return 0;
}
