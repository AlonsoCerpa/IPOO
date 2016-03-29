#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num, i, res;
    res = 1;

    printf("Calcular el factorial de: ");
    scanf("%d", &num);

    if (num==0)
        res = 1;
    else{
        for(i=1; i<=num; ++i){
            res = res * i;
        }
    }
    printf("%d", res);
    return 0;
}
