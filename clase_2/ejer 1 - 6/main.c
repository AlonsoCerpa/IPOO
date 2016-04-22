#include <stdio.h>
#include <stdlib.h>

int main()
{
    /*Probar con control + z en Windows para que resulte 0 y control + d en Linux, y con cualquier caracter para que resulte 1*/
    int a = (getchar() != EOF);
    printf("%d", a);
    return 0;
}
