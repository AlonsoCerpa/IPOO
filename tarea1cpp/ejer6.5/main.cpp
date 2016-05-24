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

void reverse(int *nums, const int &len)
{
    int lenVar = len - 1;
    int aux;

    for (int i = 0; i < len/2; i++, lenVar--){
        aux = *(nums + i);
        *(nums + i) = *(nums + lenVar);
        *(nums + lenVar) = aux;
    }
}

int main()
{
    int nums1[4] = {4, 6, 7, 2};
    int nums2[5] = {3, 12, 0, 5, 1};

    reverse(nums1, 4);
    reverse(nums2, 5);

    printArray(nums1, 4);
    printArray(nums2, 5);
    return 0;
}
