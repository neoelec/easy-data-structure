#include <stdio.h>

/* 3차원 배열 예제 */
int main(int argc, char *argv[])
{
    int array[2][3][4];
    size_t i, j, k, value = 1;

    for (i = 0; i < 2; i++) {
        for (j = 0; j < 3; j++) {
            for (k = 0; k < 4; k++) {
                array[i][j][k] = value;
                printf("\n array[%zu][%zu][%zu] = %d", i, j, k, array[i][j][k]);
                value++;
            }
        }
    }

    return 0;
}
