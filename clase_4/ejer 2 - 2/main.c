#include <stdio.h>
#include <stdlib.h>

int main()
{
    int c;
    int lim = 20;
    int estado = 1;
    int i = 0;
    char s[1000];

    while(estado == 1){
        if(i<lim-1){
            if((c=getchar()) != '\n'){
                if(c == EOF)
                    estado = 0;
            }
            else
                estado = 0;
        }
        else
            estado = 0;
        if(estado == 1){
            s[i] = c;
            ++i;
        }
    }
    return 0;
}

