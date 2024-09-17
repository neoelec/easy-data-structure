#include <stdio.h>

/* 자료형의 크기 확인하기 */
int main(int argc, char *argv[])
{
    char c, c_array[100];
    int i, i_array[100];
    short s, s_array[100];
    float f, f_array[100];
    long l, l_array[100];

    printf("\n char c의 size = %zu \t: char c_array의 size = %4zu", sizeof(c),
        sizeof(c_array));
    printf("\n int i의 size = %zu \t: int i_array의 size = %4zu", sizeof(i),
        sizeof(i_array));
    printf("\n short s의 size = %zu \t: short s_array의 size = %4zu", sizeof(s),
        sizeof(s_array));
    printf("\n float f의 size = %zu \t: float f_array의 size = %4zu", sizeof(f),
        sizeof(f_array));
    printf("\n long l의 size = %zu \t: long l_array의 size = %4zu", sizeof(l),
        sizeof(l_array));

    return 0;
}
