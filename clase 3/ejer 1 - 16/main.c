#include <stdio.h>
#include <stdlib.h>

int getline(char line[], int maxline);
void copy(char to[], char from[]);

int main()
{
    int maxline;
    int len;
    int max;

    printf("Cuantos caracteres desea ingresar como maximo?");
    scanf("%d", &maxline);

    char line[maxline];
    char longest[maxline];

    max = 0;
    while((len = getline(line, maxline)) > 0){
        if(len > max){
            max = len;
            copy(longest, line);
        }
    }
    if(max > 0)
        printf("Linea mas larga: %sString de %d caracteres", longest, max+1);
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
