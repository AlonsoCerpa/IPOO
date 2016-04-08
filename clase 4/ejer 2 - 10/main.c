#include <stdio.h>
#include <stdlib.h>

int lower(int c);

int main()
{
    int carac;

    printf("Ingrese un caracter: ");
    scanf("%c", &carac);
    carac = lower(carac);
    printf("%c", carac);
    return 0;
}

int lower(int c)
{
    int res;
    return res = (c >= 'A' && c <= 'Z') ? c + 'a' - 'A' : c;
}
