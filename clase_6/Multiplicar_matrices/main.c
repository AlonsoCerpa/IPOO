#include <stdio.h>
#include <stdlib.h>
#define VAL 3

void mult_matr(int matr1[][VAL], int  matr2[][VAL], int matr_res[][VAL], int val);
void print_matr(int matr[][VAL], int val);

int main()
{
    int val = VAL;
    static int matr1[VAL][VAL] = {
        {4, 2, 4},
        {3, 8, 6},
        {4, 7, 9}
    };
    static int matr2[VAL][VAL] = {
        {5, 1, 6},
        {1, 4, 3},
        {4, 6, 7}
    };
    int matr_res[VAL][VAL] = {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}
    };

    mult_matr(matr1, matr2, matr_res, 3);
    print_matr(matr_res, val);
    return 0;
}

void mult_matr(int matr1[][VAL], int  matr2[][VAL], int matr_res[][VAL], int val)
{
    int h, i, j;

    for (h = 0; h < val; h++){
        for (i = 0; i < val; i++){
            for (j = 0; j < val; j++){
                 matr_res[h][i]+= matr1[h][j] * matr2[j][i];
            }
        }
    }
}

void print_matr(int matr[][VAL], int val)
{
    int i, j;

    for (i = 0; i < val; ++i){
        for (j = 0; j < val; ++j){
            printf("%d ", matr[i][j]);
        }
        printf("\n");
    }
}

