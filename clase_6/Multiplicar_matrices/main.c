#include <stdio.h>
#include <stdlib.h>

void mult_matr(int matr1[][2], int  matr2[][2], int matr_res[][2], int val);
void print_matr(int matr, int val);

int main()
{
    int val = 2;
    static int matr1[2][2] = {
        {4, 2},
        {3, 8}
    };
    static int matr2[2][2] = {
        {5, 1},
        {1, 4}
    };
    int matr_res[2][2];

    mult_matr(matr1, matr2, matr_res, 2);
    print_matr(matr_res, val);
    return 0;
}

void mult_matr(int matr1[][2], int  matr2[][2], int matr_res[][2], int val)
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

void print_matr(int matr[][2], int val)
{
    int i, j;

    for (i = 0; i < val; ++i){
        for (j = 0; j < val; ++j){
            printf("%d\t", matriz[i][j]);
        }
        printf("\n");
    }
}
