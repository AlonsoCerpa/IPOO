#include <stdio.h>
#include <stdlib.h>
#define MAXLINE 1000

int getline(char input[], int lim);
int htoi(char s[]);

int main()
{
    int n, len;
    char s[MAXLINE];
    while((len = getline(s, MAXLINE)) > 0){
        n = htoi(s);
        printf("%d\n", n);
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

int htoi(char s[]){
    int i, n;
    n = 0;

    while(s[i] != '\n'){
        if(s[i] >= '0' && s[i] <= '9')
            n = 16 * n + (s[i] - '0');
        else if(s[i] >= 'a' && s[i] <= 'f')
            n = 16 * n + (s[i] - 'a' + 10);
        else if(s[i] >= 'A' && s[i] <= 'F')
            n = 16 * n + (s[i] - 'A' + 10);
        ++i;
    }
    return n;

}
