#include <stdio.h>
#include <stdlib.h>

main()
{
    int c, estado;
    estado = 0;

    while((c = getchar()) != EOF){
        if(c == '\t' || c == ' ')
            estado = 1;
        else{
            if(estado == 1)
                putchar('\n');
            estado = 0;
            putchar(c);
        }
    }
}
