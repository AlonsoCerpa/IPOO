#include <stdio.h>
#include <stdlib.h>

main()
{
    int c, cont;
    cont = 0;

    while((c=getchar()) != EOF){
        if(c == ' '){
            ++cont;
            if(cont == 1)
                putchar(c);
        }
        if(c != ' ' && cont > 0)
            cont = 0;
        if(cont == 0)
            putchar(c);
    }
}
