#include <stdio.h>
#include <stdlib.h>
#define MAXLINE 1000

int getline(char line[], int maxline);
void copy(char to[], char from[]);

int main()
{
    int len;
    char line[MAXLINE];
    char string[MAXLINE];

    while((len = getline(line, MAXLINE)) > 0){
        copy(string, line);
        printf("String: %s", string);
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
    int i, j;

    i = j = 0;
    while(from[i] != '\0'){
        if(from[i] != ' ' && from[i] != '\t'){
            to[j] = from[i];
            ++i;
            ++j;
        }
        else
            ++i;
    }
    to[j] = from[i];
}
