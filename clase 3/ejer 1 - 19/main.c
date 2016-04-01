#include <stdio.h>
#include <stdlib.h>
#define MAXLINE 1000

int getline(char line[], int maxline);
void reverse(char to[], char from[], int len);

int main()
{
    int len;
    char to[MAXLINE];
    char s[MAXLINE];

    while((len = getline(s, MAXLINE)) > 0){
        reverse(to, s, len);
        printf("String invertido: %s", to);
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

void reverse(char to[], char from[], int len)
{
    int i, j;
    for(i = 0, j = len-2-i; i<=len-2; j = len-2-++i)
        to[i] = from[j];
    to[i++] = '\n';
    to[i] = '\0';
}

