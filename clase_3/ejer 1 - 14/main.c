#include <stdio.h>
#include <stdlib.h>

main()
{
    int c, i;
    int n_char_x[3];

    for(i = 0; i < 3; ++i)
        n_char_x[i] = 0;

    while((c = getchar()) != EOF && c != '\n'){
        if(c == 'a')
            ++n_char_x[0];
        else if(c == 'b')
            ++n_char_x[1];
        else if(c == 'c')
            ++n_char_x[2];
    }
    printf("Los caracteres a, b y c estan respectivamente presentes:");
    for(i = 0; i < 3; ++i)
        printf(" %d", n_char_x[i]);
    printf(" veces.");
}
