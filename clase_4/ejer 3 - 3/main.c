#include <stdio.h>
#include <stdlib.h>
#define MAXLINE 100

void expand(char s1[], char s2[], int pos[]);
int getline(char cadena[], int max);

int main()
{
    char s[4] = {-,a,-,m};
    char t[MAXLINE];
    int x[10];

    expand(s, t, x);
    printf("%s", t);
    return 0;
}

void expand(char s1[], char s2[], int pos[]){
    int i, j, h, m, k, l;
    i = j = m = h= k = l =0;
    int estado = 1;
    int sta = 1;
    int ini, fin;

    while(s1[i] >= 'a' && s1[i] <= 'z') || (s1[i] >= 'A' && s1[i] <= 'Z') || s1[i] == '-' || (s1[i] >= '0' && s1[i] <= '9')){
        if(s1[i] >= 'a' && s1[i] <= 'z' && (estado == 1 || estado == 3) || (s1[i] >= 'A' && s1[i] <= 'Z') || (s1[i] >= '0' && s1[i] <= '9')){
            if(estado){
                if(s1[i] >= 'a' && s1[i] <= 'z'){
                    if(sta == 1)
                        pos[j-1] = s1[i];
                    else
                        sta = 1;
                }
                else if(s1[i] >= 'A' && s1[i] <= 'Z'){
                    if(sta == 2)
                        pos[j-1] = s1[i];
                    else
                        sta = 2;
                }
                else if(s1[i] >= '0' && s1[i] <= '9'){
                    if(sta == 3)
                        pos[j-1] = s1[i];
                    else
                        sta = 3;
                }
                else{
                    pos[j] = s1[i];
                    ++i;
                    ++j;
                    estado = 2;
                }
            }
            else if(estado == 3){
                pos[j] = s1[i];
                ++i;
                ++j;
                estado = 1;
            }
        }
        else if(s1[i] == '-'){
            if(estado == 2)
                estado = 3;
            ++i;
        }
    }
    while(h < j)
        for(k = pos[h]; k < pos[h+1]; ++k){
            s2[l] = pos[m];
            ++m;
            ++l;
        }
        h+=2;
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
