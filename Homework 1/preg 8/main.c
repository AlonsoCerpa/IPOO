#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numa, numb, numc, num1, num2, num3;

    printf("Ingrese un numero: ");
    scanf("%d", &num1);
    printf("Ingrese otro numero: ");
    scanf("%d", &num2);
    printf("Ingrese un ultimo numero: ");
    scanf("%d", &num3);

    if(num1 < num2){
        if(num2 < num3)
            numa = num1;
        else
            if(num3 < num1)
                numa = num3;
            else
                numa = num1;
    }
    else{
        if(num1 < num3)
            numa = num2;
        else{
            if(num2 < num3)
                numa = num2;
            else
                numa = num3;
        }
    }

    if(numa == num1){
        if(num2 < num3)
            numb = num2;
        else
            numb = num3;
    }
    else if(numa == num2){
        if(num1 < num3)
            numb = num1;
        else
            numb == num3;
    }
    else if(numa == num3){
        if(num1 < num2)
            numb = num1;
        else
            numb = num2;
    }

    if(numa == num1){
        if(numb == num2)
            numc = num3;
        else
            numc = num2;
    }
    else if(numa == num2){
        if(numb == num1)
            numc = num3;
        else
            numc = num1;
    }
    else if(numa == num3){
        if(numb == num1)
            numc = num2;
        else
            numc = num1;
    }

    printf("Los numeros ingresados en orden creciente son: %d, %d y %d", numa, numb, numc);
    return 0;
}
