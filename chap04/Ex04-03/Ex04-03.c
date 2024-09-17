#include <stdio.h>

int main(int argc, char *argv[])
{
    size_t i;
    int *ptr;
    int sale[2][2][4] = { { { 63, 84, 140, 130 }, // 3차원 배열의 초기화
                              { 157, 209, 251, 312 } },
        { { 59, 80, 130, 135 }, { 149, 187, 239, 310 } } };

    ptr = &sale[0][0][0];
    for (i = 0; i < 16; i++) {
        printf("\n address: %p sale %2zu = %3d", ptr, i, *ptr);
        ptr++;
    }

    return 0;
}
