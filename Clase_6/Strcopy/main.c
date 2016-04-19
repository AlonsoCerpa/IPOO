#include <stdio.h>
#include <stdlib.h>

void strcpy(char *s, char *t);

int main()
{
    char t[15] = "Hello world!\n";
    char s[20];

    strcpy(s, t);
    printf("%s", s);
    return 0;
}

void strcpy(char *s, char *t)
{
    while (*s++ = *t++)
        ;
}
