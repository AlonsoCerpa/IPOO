#include <stdio.h>
#include <stdlib.h>
#define MAXLINE 1000

int getline(char input[], int lim);
int fold(char input[], int posic[]);

int main()
{
    int len, y, x, numpos;
    char input[MAXLINE];
    char shortline[MAXLINE];
    int posic[MAXLINE];

    while((len = getline(input, MAXLINE)) > 0){
        numpos = fold(input, posic);
        for(y = 0; y<numpos-1; y+=2){
            for(x = posic[y]; x<=posic[++y]; ++x)
                printf("%c", input[x]);
            printf("\n");
        }
    }
    return 0;
}

int getline(char input[], int lim)
{
    int c, i;

    for(i=0; i<lim-1 && (c=getchar()) != EOF && c != '\n'; ++i)
        input[i] = c;
    if (c == '\n'){
        input[i] = c;
        ++i;
    }
    input[i] = '\0';
    return i;
}

int fold(char input[], int posic[]){
    int i, j, coc, tab, pos, estado;
    i = j = estado = 0;
    while(input[i] != '\0'){
        estado = 0;
        coc = (i/8)+1;
        tab = 8 * coc;
        while(i<tab){
            if(input[i] != ' '){
                estado = 1;
                if(i == tab-8){
                    pos = i-8;
                    posic[j] = pos;
                    ++j;
                }
                else
                    pos = i;
            }
            ++i;
        }
        if(estado){
            posic[j] = pos;
            ++j;
        }
    }
    return j;
}
