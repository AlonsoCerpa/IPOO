#include <stdio.h>
#include <stdlib.h>

int main()
{
    int c, esp, tab, sl;
    esp = tab = sl = 0;
    while((c=getchar()) != EOF){
        if(c == ' ')
            ++esp;
        else if(c =='\t')
            ++tab;
        else if(c == '\n')
            ++sl;
    }
    //Presionar el comando EOF respectivo para visualizar los resultados.
    printf("%d espacios, %d tabs y %d saltos de linea\n", esp, tab, sl);
    return 0;
}
