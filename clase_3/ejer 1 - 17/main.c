#include <stdio.h>
#include <stdlib.h>
#define MAXLINE 1000

int getline(char line[], int maxline);
void copy(char to[], char from[]);

int main()
{
    int len;
    char line[MAXLINE];
    char mas_de_80[MAXLINE];

    while((len = getline(line, MAXLINE)) > 0){
        if(len+1 > 80){
            copy(mas_de_80, line);
            printf("String de mas de 80 caracteres:\n%s", mas_de_80);
        }
    }
    return 0;
}

int getline(char s[], int lim)
{
    int c, i;

    for(i=0; i<lim-1 && (c=getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if (c == '\n'){
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

void copy(char to[], char from[])
{
    int i;

    i = 0;
    while((to[i] = from[i]) != '\0')
        ++i;
}
