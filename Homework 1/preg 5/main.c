#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num, i, j, res, primo;
    j = 2;
    res = 2;
    primo = 1;

    printf("Ingrese un numero: ");
    scanf("%d", &num);
    if(num <= 2)
        printf("El resultado de la operacion es 0");
    else if(num == 3)
        printf("El resultado de la operacion es 2");
    else{
        for(i=3; i<num; ++i){
            while(j<i && primo == 1){
                if((i/j)*j == i)
                    primo = 0;
                ++j;
            }
            if(primo == 1)
                res = res + i;
            primo = 1;
            j = 2;
        }
        printf("El resultado de la operacion es: %d", res);
    }
    return 0;
}
