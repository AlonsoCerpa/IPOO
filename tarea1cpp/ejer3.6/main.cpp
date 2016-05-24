#include <iostream>
const int ARRAY_LEN = 10;

using namespace std;

int main()
{
    int arr[ARRAY_LEN] = {10};
    int *xPtr = arr, *yPtr = arr + ARRAY_LEN - 1;
    std::cout << *xPtr << ' ' << *yPtr << "\n";
    return 0;
}
