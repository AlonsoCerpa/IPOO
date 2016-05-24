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

void reverse(int nums[], const int &len)
{
    int aux;
    int lenVar = len;

    for (int i = 0; i < len / 2; i++){
        lenVar--;
        aux = nums[i];
        nums[i] = nums[lenVar];
        nums[lenVar] = aux;
    }
}

int main()
{
    int nums1[5] = {2, 1, 8, 14, 7};
    int nums2[4] = {3, 11, 27, 6};

    reverse(nums1, 5);
    reverse(nums2, 4);
    printArray(nums1, 5);
    printArray(nums2, 4);
    return 0;
}
