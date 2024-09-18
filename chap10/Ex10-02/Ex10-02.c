#include <stdio.h>

#include <algorithm/selectionsort.h>

static int INT_Compare(const void *_a, const void *_b)
{
    int a = *(const int *)_a;
    int b = *(const int *)_b;

    return a - b;
}

int main(int argc, char *argv[])
{
    int data[8] = { 69, 10, 30, 2, 16, 8, 31, 22 }; // 정렬할 초기 원소 배열
    size_t i;

    SelectionSort(data, NR_ELEM(data), sizeof(data[0]),
        INT_Compare); // 선택 정렬 연산 호출

    for (i = 0; i < NR_ELEM(data); i++)
        printf("%d ", data[i]);

    printf("\n");

    return 0;
}
