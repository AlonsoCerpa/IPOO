#include <stdio.h>
#include <stdlib.h>

/* Porque al restarle 1 a x, todos los bits cambian su valor hasta encontrar
un 1-bit, despues al aplicar el & con el x, el resultado es que cambia el 1-bit
que esta mas hacia la derecha.
 */

int bitcount(unsigned num);

int main()
{
    unsigned num;
    int n_bit1;

    printf("Ingrese un numero sin signo: ");
    scanf("%u", &num);
    n_bit1 = bitcount(num);
    printf("Hay %d bit(s) de valor 1 en el numero ingresado.", n_bit1);
    return 0;
}

int bitcount(unsigned num){
    int x = num;
    int cont;

    while(x != 0){
        if(num != (x &= (x - 1)))
            ++cont;
    }
    return cont;
}
