#include <stdio.h>

#include <algorithm/mergesort.h>

static int INT_Compare(const void *_a, const void *_b)
{
    int a = *(const int *)_a;
    int b = *(const int *)_b;

    return a - b;
}

int main(int argc, char *argv[])
{
    int data[8] = { 69, 10, 30, 2, 16, 8, 31, 22 };
    void *ptr_arr[NR_ELEM(data)];
    size_t i;

    for (i = 0; i < NR_ELEM(data); i++)
        ptr_arr[i] = &data[i];

    MergeSort(ptr_arr, NR_ELEM(data), INT_Compare);

    for (i = 0; i < NR_ELEM(data); i++)
        printf("%d ", *(int *)ptr_arr[i]);

    printf("\n");

    return 0;
}
