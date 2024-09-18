#include <stdio.h>

#include <algorithm/quicksort.h>

static int INT_Compare(const void *_a, const void *_b)
{
    int a = *(const int *)_a;
    int b = *(const int *)_b;

    return a - b;
}

int main(int argc, char *argv[])
{
    int data[8] = { 69, 10, 30, 2, 16, 8, 31, 22 };
    size_t i;

    QuickSort(data, NR_ELEM(data), sizeof(data[0]), INT_Compare);

    for (i = 0; i < NR_ELEM(data); i++)
        printf("%d ", data[i]);

    printf("\n");

    return 0;
}
