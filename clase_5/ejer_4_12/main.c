#include <stdio.h>
#include <stdlib.h>
#define MAXNUM 100

int itoa_r(int, char[]);

int main()
{
    int x = 248;
    char str[MAXNUM];
    int pos;

    pos = itoa_r(x, str);
    str[pos] = '\0';
    printf("%s\n", str);
    return 0;
}

int itoa_r(int num, char s[])
{
    static int i = 0;

    if (num < 0){
        s[i++] = '-';
        num = -num;
    }
    if (num / 10)
        itoa_r(num / 10, s);
    s[i++] = num % 10 + '0';
    return i;
}
