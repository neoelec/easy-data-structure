#include <stdio.h>
#include <stdlib.h>

#include <container/as.h>

#define STACK_SIZE 100

static void __pushEntry(struct AS *stack, int data)
{
    int *entry = malloc(sizeof(*entry));

    *entry = data;
    AS_Push(stack, entry);
}

static int __popEntry(struct AS *stack)
{
    int *entry = AS_Pop(stack);
    int data = *entry;

    free(entry);

    return data;
}

static int __topEntry(struct AS *stack) { return *(int *)AS_Top(stack); }

static struct AS *__createStack(size_t nr_entries)
{
    struct AS *stack = malloc(AS_BYTES(nr_entries));

    AS_Init(stack, nr_entries);

    return stack;
}

static void __destroyStack(struct AS *stack)
{
    while (!AS_IsEmpty(stack))
        __popEntry(stack);

    free(stack);
}

static void INT_PrintEntry(void *entry, void *private)
{
    printf("%d ", *(int *)entry);
}

static void __printStack(struct AS *stack)
{
    printf("\n STACK [ ");
    AS_Forward(stack, INT_PrintEntry, NULL);
    printf("] ");
}

int main(int argc, char *argv[])
{
    struct AS *stack = __createStack(STACK_SIZE);
    int item;

    __printStack(stack);
    __pushEntry(stack, 1);
    __printStack(stack);
    __pushEntry(stack, 2);
    __printStack(stack);
    __pushEntry(stack, 3);
    __printStack(stack);

    item = __topEntry(stack);
    __printStack(stack);
    printf("peek top => %d", item);

    __popEntry(stack);
    __printStack(stack);

    item = __popEntry(stack);
    __printStack(stack);
    printf("\t pop top => %d", item);

    item = __popEntry(stack);
    __printStack(stack);
    printf("\t pop top => %d", item);

    __destroyStack(stack);

    return 0;
}
