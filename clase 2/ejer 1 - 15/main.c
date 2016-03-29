#include <stdio.h>
#include <stdlib.h>

int fahr_to_celc(int fahr);

int main()
{
    int fahr;
    for(fahr=0; fahr<=300; fahr+=20){
        printf("%d\t%d\n", fahr, fahr_to_celc(fahr));
    }
    return 0;
}

int fahr_to_celc(int fahr)
{
    int celc;
    celc = (5*(fahr - 32))/9;
    return celc;
}
