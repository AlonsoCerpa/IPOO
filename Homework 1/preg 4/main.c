#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, res, i;
    res = 0;
    printf("Ingrese un numero: ");
    scanf("%d", &n);
    for(i=1; i<=n; ++i)
        res = res + i;
    printf("El resultado de la operacion es: %d", res);
    return 0;
}
