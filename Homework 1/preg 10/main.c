#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num;
    float i = 2, n_harm = 1;

    printf("Ingrese un numero natural: ");
    scanf("%d", &num);
    while(i<=num){
        n_harm=n_harm + 1/i;
        ++i;
    }
    printf("El %d-esimo numero armonico es: %.3f", num, n_harm);

    return 0;
}
