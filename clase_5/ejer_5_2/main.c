#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

int n;

int main()
{
    float array[SIZE];
    int getfloat(float *);

    for (n = 0; n < SIZE && getfloat(&array[n]) != EOF; n++)
        ;
    for (n = 0; n < SIZE; n++)
        printf("%f ", array[n]);
    return 0;
}

#include <ctype.h>

int getch(void);
void ungetch(int);

int getfloat(float *pn)
{
    int c, sign;
    float power;

    while (isspace(c = getch()))
        ;
    if (!isdigit(c) && c != EOF && c != '+' && c != '-' && c != '.'){
        ungetch(c);{}
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
    for (*pn = 0.0; isdigit(c); c = getch())
        *pn = 10.0 * *pn + (c - '0');
    if(c == '.')
        c = getch();
    for (power = 1.0; isdigit(c); c = getch()){
        *pn = 10.0 * *pn + (c - '0');
        power *= 10.0;
    }
    *pn *= sign / power;
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
