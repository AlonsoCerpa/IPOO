#include <stdio.h>
#include <stdlib.h>
#define MAXLINE 1000

void escape(char s[], char t[]);
void inv_escape(char s[], char t[]);
int getline(char cadena[], int max);

int main()
{
    char s[MAXLINE];
    char t[MAXLINE];
    int len;
    int estado = 0;

    while((len = getline(s, MAXLINE))> 0){
        if(estado){
            escape(s, t);
            printf("%s", s);
            estado = 0;
        }
        else{
            inv_escape(s, t);
            printf("%s", s);
            estado = 1;
        }
    }

    return 0;
}

int getline(char cadena[], int max){
    int c;
    int i = 0;
    while(i < max - 1 && (c = getchar()) != EOF && c != '\n'){
        cadena[i] = c;
        ++i;
    }
    if(c == '\n'){
        cadena[i] = c;
        ++i;
    }
    cadena[i] = '\0';
    return i;
}

void escape(char s[], char t[]){
    int i, j;
    i = j = 0;

    while(t[j] != '\0'){
        switch(t[j]){
        case '\n':
            s[i] = 92;
            s[++i] = 'n';
            s[++i] = '\n';
            break;
        case '\t':
            s[i] = 92;
            s[++i] = 't';
            break;
        default:
            s[i] = t[j];
            break;
        }
        ++i;
        ++j;
    }
    s[i] = '\0';
}

void inv_escape(char s[], char t[]){
    int i, j;
    i = j = 0;

    while(t[j] != '\0'){
        switch(t[j]){
        case 92:
            switch(t[j+1]){
            case 'n':
                s[i] = '\n';
                ++j;
                break;
            case 't':
                s[i] = '\t';
                ++j;
                break;
            }
        default:
            s[i] = t[j];
            break;
        }
        ++i;
        ++j;
    }
    s[i] = '\0';
}
