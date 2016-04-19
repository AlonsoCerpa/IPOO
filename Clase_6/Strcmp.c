#include <stdio.h>
#include <stdlib.h>

int strcmp(char *s, char *t);

int main()
{
    int x;
    char s[20] = "Hola mundo";
    char t[20] = "Hola mund";

    x = strcmp(s, t);
    printf("%i\n", x);
    return 0;
}

int strcmp(char *s, char *t)
{
    for ( ; *s == *t; s++, t++)
        if (*s == '\0')
        return 0;
    return *s - *t;
}
