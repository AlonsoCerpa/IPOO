#include <stdio.h>
#include <stdlib.h>

main()
{
    int c, i, j, cont, estado;
    int len_word[10];
    estado = cont = j = 0;

    for(i = 0; i < 10; ++i)
        len_word[i] = 0;


    while((c = getchar()) != EOF && c != '\n'){
        if(c == '\t' || c == ' ')
            estado = 1;
        else{
            if(estado == 1){
                ++cont;
                estado = 0;
            }
            ++len_word[cont];
        }
    }
    printf("Longitud de las palabras:\n");
    for(i = 0; i<10; ++i)
        printf(" %d", len_word[i]);
}
