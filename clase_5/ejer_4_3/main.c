#include <stdio.h>
#include <stdlib.h>

#define MAXOP 100
#define NUMBER '0'

int getop(char []);
void push(double);
double pop(void);

/* Calculadora polaca de reversa, se le adiciona el operador % y se pueden operar
numeros negativos */

int main()
{
    int type;
    double op2;
    double op1;
    int coc;
    char s[MAXOP];

    while ((type = getop(s)) != EOF){
        switch(type){
        case NUMBER:
            push(atof(s));
            break;
        case '+':
            push(pop() + pop());
            break;
        case '*':
            push(pop() * pop());
            break;
        case '-':
            op2 = pop();
            push(pop() - op2);
            break;
        case '/':
            op2 = pop();
            if (op2 != 0.0)
                push(pop() / op2);
            else
                printf("error: divisor cero\n");
            break;
        case '%':         /* nuevo caso modulo */
            op2 = pop();
            op1 = pop();
            if (op2 != 0.0){
                coc = op1 / op2;
                push(op1 - (coc * op2));
            }
            else
                printf("error: divisor cero\n");
            break;
        case '\n':
            printf("\t%.8g\n", pop());
            break;
        default:
            printf("error: comando desconocido %s\n", s);
            break;
        }
    }
    return 0;
}

#define MAXVAL 100

int sp = 0;
double val[MAXVAL];

/* push: Inserta f en la posicion sp del arreglo val */
void push(double f)
{
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: arreglo lleno, no se puede insertar %g\n", f);
}

/* pop: actualiza la posicion sp y retorna el valor que este mas arriba en el arreglo */

double pop(void)
{
    if (sp > 0)
        return val[--sp];
    else {
        printf("error: arreglo vacio\n");
        return 0.0;
    }
}

#include <ctype.h>

int getch(void);
void ungetch(int);

/* getop: obtiene el siguiente operador u operando numerico */
int getop(char s[])
{
    int i, c, state;
    state = 0;

    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';
    if(c == '-' && sp != 3)  /* indica que el menos corresponde al signo de un numero y no al operador */
        state = 1;
    if (!isdigit(c) && c != '.' && !state)
        return c;
    i = 0;
    if (isdigit(c) || state)
        while(isdigit(s[++i] = c = getch()))
            ;
    if (c == '.')
        while(isdigit(s[++i] = c = getch()))
            ;
    s[i] = '\0';
    if (c != EOF)
        ungetch(c);
    return NUMBER;
}

#define BUFSIZE 100

char buf[BUFSIZE];  /* buffer para ungetch */
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






