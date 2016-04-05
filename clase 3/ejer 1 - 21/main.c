/*Se reemplaza espacion con la menor cantidad de tabs y espacios (numerales)*/

#include <stdio.h>
#include <stdlib.h>
#define MAXLINE 1000

int getline(char input[], int lim);
void entab(char contabs[], char input[]);

int main()
{
    int len;
    char contabs[MAXLINE];
    char input[MAXLINE];

    while((len = getline(input, MAXLINE)) > 0){
        entab(contabs, input);
        printf("%s", contabs);
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

void entab(char contabs[], char input[])
{
    int i, j, coc, tab, h, m, cont_esp, cont_tab;
    i = j = 0;

    while(input[i] != '\0'){
        cont_esp = 0;
        cont_tab = 0;
        while(input[i] == ' '){
            coc = (i/8) + 1;
            tab = 8 * coc;
            ++i;
            if(i == tab){
                ++cont_tab;
                cont_esp = 0;
            }
            else
                ++cont_esp;
        }
        for(h = 0; h<cont_tab; ++h){
            contabs[j] = '\t';
            ++j;
        }
        for(m = 0; m<cont_esp; ++m){
            contabs[j] = '#';
            ++j;
        }
        if(input[i]!= ' '){
            contabs[j] = input[i];
            ++j;
            ++i;
        }
    }
    contabs[j] = '\0';
}
