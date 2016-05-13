#include <iostream>
#define MAXNUM 7

using namespace std;

int sum(int nums[], int maxnum)
{
    int res = 0;

    for (int i = 0; i < maxnum; i++){
        res += nums[i];
    }
    return res;
}

int main()
{
    int a[MAXNUM] = {4,6,8,2,14,2,-3};
    int num = sum(a, MAXNUM);
    cout << num << "\n";
    return 0;
}
