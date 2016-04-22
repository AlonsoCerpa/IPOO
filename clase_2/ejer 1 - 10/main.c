#include <stdio.h>
#include <stdlib.h>

main()
{
    int c, cont;

    while((c = getchar()) != EOF ){
        if(c == 9){
            putchar(92);
            putchar('t');
        }
        else if(c == 8){
            putchar(92);
            putchar('b');
        }
        else if(c == 92){
            putchar(92);
            putchar(92);
        }
        else
            putchar(c);
    }
}
