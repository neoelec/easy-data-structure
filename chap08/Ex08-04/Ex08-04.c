#include <stdio.h>
#include <stdlib.h>

#include <container/heap.h>

#define MAX_ELEMENT (1 << 7)

static int INT_Compare(const void *_a, const void *_b)
{
    int a = *(const int *)_a;
    int b = *(const int *)_b;

    return a - b;
}

static void __insertEntry(struct Heap *heap, int data)
{
    int *entry = malloc(sizeof(*entry));

    *entry = data;

    Heap_Insert(heap, entry);
}

static int __removeHeadEntry(struct Heap *heap)
{
    int *entry = Heap_RemoveHead(heap);
    int data = *entry;

    free(entry);

    return data;
}

static void INT_PrintEntry(void *_entry, void *private)
{
    int *entry = _entry;

    printf("[%d] ", *entry);
}

int main(int argc, char *argv[])
{
    char __heap[HEAP_BYTES(MAX_ELEMENT)];
    struct Heap *heap = (void *)__heap;

    Heap_InitNrEntries(heap, MAX_ELEMENT, INT_Compare);

    __insertEntry(heap, 10);
    __insertEntry(heap, 45);
    __insertEntry(heap, 19);
    __insertEntry(heap, 11);
    __insertEntry(heap, 96);

    Heap_Forward(heap, INT_PrintEntry, NULL);

    while (heap->used)
        printf("\n delete : [%d] ", __removeHeadEntry(heap));

    return 0;
}
