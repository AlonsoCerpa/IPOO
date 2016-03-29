#include <stdio.h>
#include <stdlib.h>

int mcd(int a, int b);

int main()
{
    int i, j, res, est, n;
    int num[4];
    est = i = j = 0;

    for(i=0; i<4; ++i){
        printf("Ingrese un numero: ");
        scanf("%d", &n);
        num[i] = n;
    }

    while(j<4){
        if(est == 0){
            res = mcd(num[j],num[++j]);
            est = 1;
        }
        else
            res = mcd(num[j], res);
        ++j;
    }

    printf("El maximo comun divisor de los numeros ingresados es: %d", res);

    return 0;
}

int mcd(int a, int b){
    if(b == 0)
        return a;
    else
        return mcd(b, a%b);
}
