/*
Reemplazamos tabs con espacios, en este caso para visualizar mejor se reemplaza con #
 */

#include <stdio.h>
#include <stdlib.h>
#define MAXLINE 1000

int getline(char input[], int lim);
void detab(char sintabs[], char input[]);

int main()
{
    int len;
    char sintabs[MAXLINE];
    char input[MAXLINE];

    while((len = getline(input, MAXLINE)) > 0){
        detab(sintabs, input);
        printf("%s", sintabs);
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

void detab(char sintabs[], char input[])
{
    int coc, tab;
    int i = 0;
    int j = 0;

    while(input[i] != '\0'){
        if(input[i] == '\t'){
            coc = (j/8) + 1;
            tab = 8 * coc;
            ++i;
            while(j<tab){
                sintabs[j] = '#';
                ++j;
            }
        }
        else{
            sintabs[j] = input[i];
            ++i;
            ++j;
        }
    }
    sintabs[j] = '\0';
}
