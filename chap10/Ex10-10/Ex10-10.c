#include <stdio.h>

#include <algorithm/radixsort.h>

int main(int argc, char *argv[])
{
    int data[8] = { 69, 10, 30, 2, 16, 8, 31, 22 };
    size_t i;

    RadixSort(data, NR_ELEM(data), sizeof(data[0]), 3);

    for (i = 0; i < NR_ELEM(data); i++)
        printf("%d ", data[i]);

    printf("\n");

    return 0;
}
