#include <stdio.h>
#include <stdlib.h>
#define MAXTXT 500

int getline(char *v, int max);
int palindrome(char *texto, int len);
int len(char *txt);

int main()
{
    int len, x, txt[MAXTXT];

    while ((len = getline(txt, MAXTXT)) > 0){
        printf("%s\n", txt);
        x = palindrome(txt, len - 1);
        if(x)
            printf("Si es palindrome\n\n");
        else
            printf("No es palindrome\n\n");
    }
    return 0;
}

int getline(char *v, int max)
{
    int c, i;

    for (i = 0 ; i < max && (c = getchar()) != EOF && c != '\n'; *(v+i) = c, i++)
        ;
    if (c == '\n'){
        *(v + i) = c;
        ++i;
    }
    *(v + i) = '\0';
    return i;
}

int palindrome(char *txt, int len)
{
    int i, j;

    for (i = 0, j = len - 1; *(txt + i) == *(txt + j); --j, ++i){
        if (i == (len - 1)/ 2 && len%2 == 1)
            return 1;
        if (i == len/2 && len%2 == 0)
            return 1;
    }
    return 0;
}
