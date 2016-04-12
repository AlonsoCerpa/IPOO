#include <stdio.h>
#include <stdlib.h>
#define MAX 100

void reverse(char rev[], int ini, int fin);

int main()
{
    char rev[MAX] = {'P','e','r','u','\0'};
    char rev1[MAX] = "Abcde";
    int ini = 0;
    int fin = 4;
    int fin1 = 5;

    reverse(rev, ini, fin);
    printf("%s\n", rev);
    reverse(rev1, ini, fin1);
    printf("%s\n", rev1);
    return 0;
}

void swap(char rev[], int x, int y);

void reverse(char rev[], int ini, int fin)
{
    swap(rev, ini++, --fin);
    if(ini < fin)
        reverse(rev, ini, fin);
}

void swap(char rev[], int x, int y)
{
    int temp;

    temp = rev[x];
    rev[x] = rev[y];
    rev[y] = temp;
}
