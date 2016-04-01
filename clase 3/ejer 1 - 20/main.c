#include <stdio.h>
#include <stdlib.h>
#define MAXLINE 1000

/*
Respuesta a la pregunta del libro:
n es una variable que cambia segun cuantos tabs hay en cada linea
 */

int main()
{
    int len;
    char to[MAXLINE];
    char s[MAXLINE];

    while((len = getline(s, MAXLINE)) > 0){
        detab(to, s, len);
        printf("String: %s", to);
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

void detab(char to[], char from[])
{
    int h;
    int i = 0;
    int j = 0;

    while(from[i] != '\0'){
        if(from[i] == '\t'){
            i+=4;
            h = j+4;
            while(j<=h){
                to[j] = ' ';
                ++j;
            }
        }
        else{
            to[j] = from[i];
            ++j;
            ++i;
        }
    }
}
