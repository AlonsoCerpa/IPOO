#include <iostream>
#define MAXNUM 7

using namespace std;

int sum(int *nums, const int &maxnum, int contNum = 0)
{
    if (contNum  < maxnum){
        ++contNum;
        return *nums + sum(nums + 1, maxnum, contNum);
    }
    return 0;
}

int main()
{
    int a[MAXNUM] = {4,6,8,2,14,2,-3};
    int b[4] = {4,1,2,8};
    int res1 = sum(a, MAXNUM);
    int res2 = sum(b, 4);
    cout << res1 << "\n" << res2 << "\n";
    return 0;
}
