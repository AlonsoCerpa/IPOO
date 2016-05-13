#include <iostream>

using namespace std;

void printArray(int *num, const int &maxnum)
{
    int i;

    for (i = 0; i < maxnum - 1; i++){
        cout << *(num + i) << ", ";
    }
    cout << *(num + i) << endl;
}

int main()
{
    int nums[4] = {2, 3, 8, 12};

    printArray(nums, 4);
    return 0;
}

