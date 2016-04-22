#include <stdio.h>
#include <stdlib.h>

void mult_matr(int matr1[][2], int  matr2[]{2], int matr_res[][2], int row, int col);
void print_matr(int ma)

int main()
{
    static int matr1[2][2] = {
        {4, 2},
        {3, 8}
    };
    static int matr2[2][2] = {
        {5, 1},
        {1, 4}
    };
    int matr_res[2][2];

    mult_matr(matr1, matr2, matr_res, 2, 2);
    print_matr(matr_res);
    return 0;
}

void mult_matr(int matr1[][2], int  matr2[][2], int matr_res[][2], int row, int col)
{
    int i, j, k;
    int sum = 0;
    k = 0;

    for (j = 0; j < row; j++){
        for (k = 0; )
            for (i = 0; i < row; i++){
                sum += matr1[i][k] * matr2[k][i];
            }
            matr_res[j][k++] = sum;
    }
}
