#include <stdio.h>
#include <stdlib.h>

#include <container/cq.h>

#define CQ_SIZE 4

static void __enqueueEntry(struct CQ *queue, int data)
{
    int *entry = malloc(sizeof(*entry));

    *entry = data;
    CQ_Enqueue(queue, entry);
}

static char __dequeueEntry(struct CQ *queue)
{
    char *entry = CQ_Dequeue(queue);
    char data = *entry;

    free(entry);

    return data;
}

static char __frontEntry(struct CQ *queue) { return *(char *)CQ_Front(queue); }

static struct CQ *__createQueue(size_t nr_entries)
{
    struct CQ *queue = malloc(CQ_BYTES(nr_entries));

    CQ_Init(queue, nr_entries);

    return queue;
}

static void __destroyQueue(struct CQ *queue)
{
    while (!CQ_IsEmpty(queue))
        __dequeueEntry(queue);

    free(queue);
}

static void CHAR_PrintEntry(void *entry, void *private)
{
    printf("%3c", *(char *)entry);
}

static void __printQueue(struct CQ *queue)
{
    printf(" Circular Queue : [");
    CQ_Forward(queue, CHAR_PrintEntry, NULL);
    printf(" ]\n");
}

int main(int argc, char *argv[])
{
    struct CQ *queue = __createQueue(CQ_SIZE);
    char data;

    printf("삽입 A>>");
    __enqueueEntry(queue, 'A');
    __printQueue(queue);
    printf("삽입 B>>");
    __enqueueEntry(queue, 'B');
    __printQueue(queue);
    printf("삭제  >>");
    __dequeueEntry(queue);
    __printQueue(queue);
    printf("삽입 C>>");
    __enqueueEntry(queue, 'C');
    __printQueue(queue);
    data = __frontEntry(queue);
    printf(" peek item : %c \n", data);
    printf("삽입 D>>");
    __enqueueEntry(queue, 'D');
    __printQueue(queue);

    printf("삽입 E>>");
    __enqueueEntry(queue, 'E');
    __printQueue(queue);

    __destroyQueue(queue);

    return 0;
}
