#include <stdio.h>
#include <stdlib.h>

#include <container/llq.h>

struct char_entry {
    struct DLL_Node node;
    char data;
};

static void __insertFrontEntry(struct LLQ *queue, int data)
{
    struct char_entry *entry = malloc(sizeof(*entry));

    entry->data = data;
    LLQ_InsertFront(queue, &entry->node);
}

static void __insertRearEntry(struct LLQ *queue, int data)
{
    struct char_entry *entry = malloc(sizeof(*entry));

    entry->data = data;
    LLQ_InsertRear(queue, &entry->node);
}

static char __removeFrontEntry(struct LLQ *queue)
{
    struct DLL_Node *node = LLQ_RemoveFront(queue);
    struct char_entry *entry = CONTAINER_OF(node, struct char_entry, node);
    char data = entry->data;

    free(entry);

    return data;
}

static char __removeRearEntry(struct LLQ *queue)
{
    struct DLL_Node *node = LLQ_RemoveRear(queue);
    struct char_entry *entry = CONTAINER_OF(node, struct char_entry, node);
    char data = entry->data;

    free(entry);

    return data;
}

static char __frontEntry(struct LLQ *queue)
{
    struct DLL_Node *node = LLQ_Front(queue);
    struct char_entry *entry = CONTAINER_OF(node, struct char_entry, node);

    return entry->data;
}

static char __rearEntry(struct LLQ *queue)
{
    struct DLL_Node *node = LLQ_Rear(queue);
    struct char_entry *entry = CONTAINER_OF(node, struct char_entry, node);

    return entry->data;
}

static struct LLQ *__createQueue()
{
    struct LLQ *queue = malloc(sizeof(*queue));

    LLQ_Init(queue);

    return queue;
}

static void __destroyQueue(struct LLQ *queue)
{
    while (!LLQ_IsEmpty(queue))
        __removeFrontEntry(queue);

    free(queue);
}

static void CHAR_PrintEntry(struct DLL_Node *node, void *private)
{
    struct char_entry *entry = CONTAINER_OF(node, struct char_entry, node);

    printf("%3c", entry->data);
}

static void __printQueue(struct LLQ *queue)
{
    printf("DeQue : [");
    LLQ_Forward(queue, CHAR_PrintEntry, NULL);
    printf(" ]\n");
}

int main(int argc, char *argv[])
{
    struct LLQ *queue = __createQueue();
    char data;

    printf("front 삽입 A>> ");
    __insertFrontEntry(queue, 'A');
    __printQueue(queue);
    printf("front 삽입 B>> ");
    __insertFrontEntry(queue, 'B');
    __printQueue(queue);
    printf("rear  삽입 C>> ");
    __insertRearEntry(queue, 'C');
    __printQueue(queue);
    printf("front 삭제  >> ");
    __removeFrontEntry(queue);
    __printQueue(queue);
    printf("rear  삭제  >> ");
    __removeRearEntry(queue);
    __printQueue(queue);
    printf("rear  삽입 D>> ");
    __insertRearEntry(queue, 'D');
    __printQueue(queue);
    printf("front 삽입 E>> ");
    __insertFrontEntry(queue, 'E');
    __printQueue(queue);
    printf("front 삽입 F>> ");
    __insertFrontEntry(queue, 'F');
    __printQueue(queue);

    data = __frontEntry(queue);
    printf("peek Front item : %c \n", data);
    data = __rearEntry(queue);
    printf("peek Rear item : %c \n", data);

    __destroyQueue(queue);

    return 0;
}
