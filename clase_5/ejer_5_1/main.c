#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

int n;

int main()
{
    int array[SIZE], getint(int *);

    for (n = 0; n < SIZE && getint(&array[n]) != EOF; n++)
        ;
    for (n = 0; n < SIZE; n++)
        printf("%d ", array[n]);
    return 0;
}

#include <ctype.h>

int getch(void);
void ungetch(int);

int getint(int *pn)
{
    int c, sign;

    while (isspace(c = getch()))
        ;
    if (!isdigit(c) && c != EOF && c != '+' && c != '-'){
        ungetch(c);
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-'){
        c = getch();
        if (!isdigit(c) && c != EOF){       /* Detecta que el caracter siguiente al + o - no es un numero */
            n--;                               /* retrocede el indice del arreglo para que no avance de mas */
            ungetch(sign ==  1 ? '+' : '-');    /* pasa el caracter + o - al buffer */
            return 0;
        }
    }
    for (*pn = 0; isdigit(c); c = getch())
        *pn = 10 * *pn + (c - '0');
    *pn *= sign;
    if (c != EOF)
        ungetch(c);
    return c;
}

#define BUFSIZE 100

int buf[BUFSIZE];  /* buffer para ungetch */
int bufp = 0;       /* siguiente posicion libre en buf */

int getch(void)  /* obtiene un caracter (posiblemente retrasado, guardado en buf) */
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) /* inserta un caracter ya obtenido de la entrada en buf */
{
    if (bufp >= BUFSIZE)
        printf("ungetch: muchos caracteres\n");
    else
        buf[bufp++] = c;
}
