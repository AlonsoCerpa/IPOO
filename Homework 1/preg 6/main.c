#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num, res, x, i;
    x = 2;
    res = 1;
    printf("Calcular 2 elevado a: ");
    scanf("%d", &num);
    for(i = 0; i<num; ++i)
        res = res * x;
    printf("%d", res);
    return 0;
}

