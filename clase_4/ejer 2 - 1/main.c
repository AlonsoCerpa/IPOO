#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    long a = 2;
    long ini = 0;
    long ran_char = pow(a,8);
    short int ran_shint = pow(a, 16);
    unsigned long int ran1_lnint = pow(a, 32);
    long int ran_lnint = pow(a, 32);

    printf("Unsigned Char: %d a %d\n", ini, ran_char - 1);
    printf("Signed Char: %d a %d\n", 0-(ran_char/2), ran_char/2 - 1);
    printf("Unsigned Short Int: %d a %hi\n", ini, ran_shint - 1);
    printf("Signed Short Int: %hi a %hi\n", 0-(ran_shint/2), ran_shint/2 - 1);
    printf("Unsigned Long Int: %d a %lu\n", ini, ran1_lnint - 1);
    printf("Signed Long Int: %li a %li\n", (0-(ran_lnint/2))*-1, (ran_lnint/2 - 1)*-1);
    return 0;
}
