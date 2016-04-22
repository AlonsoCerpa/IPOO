#include <stdio.h>
#include <stdlib.h>
#define MAXINPUT 100

int any(char s1[], char s2[]);
int get_line(char s[], int maxinput);

int main()
{
    char s1[MAXINPUT];
    char s2[MAXINPUT];
    int len1;
    int len2;
    int loc;

    while((len1=get_line(s1, MAXINPUT))>0 && (len2 = get_line(s2, MAXINPUT))>0){
        loc = any(s1, s2);
        printf("%d\n", loc);
    }
    return 0;
}

int get_line(char s[], int maxinput){
    int i, c;

    for(i=0; i<maxinput-1 && (c = getchar()) != EOF && c!= '\n'; ++i)
        s[i] = c;
    if(c == '\n'){
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}



int any(char s1[], char s2[]){
    int char1;
    int i, j;

    for(i = 0; s1[i] != '\n'; ++i){
        for(j = 0; s2[j] != '\n'; ++j){
            if(s1[i] == s2[j])
                return i;
        }
    }
    return -1;
}
