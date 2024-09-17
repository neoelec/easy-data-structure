#include <stdio.h>

#include <algorithm/linearsearch.h>

static int INT_Compare(const void *_a, const void *_b)
{
    int a = *(const int *)_a;
    int b = *(const int *)_b;

    return a - b;
}

static void __sequentialSearch(void **ptr_arr, size_t nmemb, int key)
{
    printf("\n %d를 검색하여라! ->> ", key);

    if (LinearSearch(&key, ptr_arr, nmemb, INT_Compare))
        printf("검색 성공! \n\n");
    else
        printf("검색 실패! \n\n");
}

int main(int argc, char *argv[])
{
    int data[] = { 8, 30, 1, 9, 11, 19, 2 };
    void *ptr_arr[NR_ELEM(data)];
    size_t i;

    for (i = 0; i < NR_ELEM(data); i++)
        ptr_arr[i] = &data[i];

    __sequentialSearch(ptr_arr, NR_ELEM(data), 9);
    __sequentialSearch(ptr_arr, NR_ELEM(data), 6);

    return 0;
}
