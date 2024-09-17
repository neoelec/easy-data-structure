#include <stdio.h>
#include <stdlib.h>

#include <container/lls.h>

struct int_entry {
    struct SLL_Node node;
    int data;
};

static void __pushEntry(struct LLS *stack, int data)
{
    struct int_entry *entry = malloc(sizeof(*entry));

    entry->data = data;
    LLS_Push(stack, &entry->node);
}

static int __popEntry(struct LLS *stack)
{
    struct SLL_Node *node = LLS_Pop(stack);
    struct int_entry *entry = CONTAINER_OF(node, struct int_entry, node);
    int data = entry->data;

    free(entry);

    return data;
}

static int __topEntry(struct LLS *stack)
{
    struct SLL_Node *node = LLS_Top(stack);
    struct int_entry *entry = CONTAINER_OF(node, struct int_entry, node);

    return entry->data;
}

static struct LLS *__createStack(void)
{
    struct LLS *stack = malloc(sizeof(*stack));

    LLS_Init(stack);

    return stack;
}

static void __destroyStack(struct LLS *stack)
{
    while (!LLS_IsEmpty(stack)) {
        struct SLL_Node *node = LLS_Pop(stack);
        free(CONTAINER_OF(node, struct int_entry, node));
    }

    free(stack);
}

static void INT_PrintEntry(struct SLL_Node *node, void *private)
{
    struct int_entry *entry = CONTAINER_OF(node, struct int_entry, node);

    printf("%d ", entry->data);
}

static void __printStack(struct LLS *stack)
{
    printf("\n STACK [ ");
    LLS_Forward(stack, INT_PrintEntry, NULL);
    printf("] ");
}

int main(int argc, char *argv[])
{
    struct LLS *stack = __createStack();
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
