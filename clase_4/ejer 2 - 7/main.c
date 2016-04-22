#include <stdio.h>
#include <stdlib.h>

unsigned invert(unsigned x, int p, int n);

int main()
{
    unsigned num;
    unsigned res;

    printf("Ingrese un entero sin signo: ");
    scanf("%u", &num);
    res = invert(num, 5, 3);
    printf("El resultado de la funcion es: %u", res);
    return 0;
}

unsigned invert(unsigned x, int p, int n){
    return ((x >> (p+1-n)) & ~(~0 << n)) ^ ~(~0 << n);
}
