#include <iostream>

using namespace std;

const int LENGTH = 2;
const int WIDTH = 3;

void transpose(const int input[][LENGTH], int output[][WIDTH])
{
    for (int j = 0; j < LENGTH; j++){
        for (int i = 0; i < WIDTH; i++){
            output[j][i] = input[i][j];
        }
    }
}

int main()
{
    int m1[WIDTH][LENGTH] = {{4, 2},
                             {3, 7},
                             {8, 12}
                            };
    int m2[LENGTH][WIDTH];

    transpose(m1, m2);
    return 0;
}
