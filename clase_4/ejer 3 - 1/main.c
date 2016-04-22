#include <stdio.h>
#include <stdlib.h>

int binsearch(int x, int v[], int n);

int main()
{
    int res1, res2;
    int num[6] = {1, 5, 14 ,18, 24, 28};

    res1 = binsearch(17, num, 6);
    res2 = binsearch(18, num, 6);
    printf("%d\n", res1);
    printf("%d\n", res2);
    return 0;
}

int binsearch(int x, int v[], int n){
    int low, mid, high;

    low = 0;
    high = n - 1;
    while(low <= high){
        mid = (low + high) / 2;
        if(x <= v[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }
    if(x == v[mid])
        return mid;
    else
        return -1;
}
