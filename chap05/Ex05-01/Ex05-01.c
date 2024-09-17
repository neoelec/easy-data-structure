#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <container/sll.h>

struct wday_entry {
    struct SLL_Node node;
    char data[20];
};

static struct wday_entry *__insertEntry(struct SLL_Node *head, const char *data)
{
    struct wday_entry *entry = malloc(sizeof(*entry));

    strcpy(entry->data, data);
    SLL_Init(&entry->node);
    SLL_InsertTail(head, &entry->node);

    return entry;
}

static void WDAY_PrintEntry(struct SLL_Node *node, void *private)
{
    struct wday_entry *entry = CONTAINER_OF(node, struct wday_entry, node);

    printf("%s", entry->data);

    if (node->next)
        printf(", ");
}

static void __printList(struct SLL_Node *head)
{
    printf("L = (");
    SLL_Forward(head, WDAY_PrintEntry, NULL);
    printf(")\n");
}

int main(int argc, char *argv[])
{
    struct SLL_Node __head;
    struct SLL_Node *head = &__head;
    struct SLL_Node *node;

    printf("(1) 공백 리스트 생성하기! \n");
    SLL_Init(head);
    __printList(head);

    printf("(2) 리스트에 3개의 노드 추가하기! \n");
    __insertEntry(head, "월");
    __insertEntry(head, "수");
    __insertEntry(head, "금");
    __printList(head);

    printf("(3) 리스트 마지막에 노드 한개 추가하기! \n");
    __insertEntry(head, "일");
    __printList(head);

    printf("(4) 마지막 노드 삭제하기! \n");
    node = SLL_GetNode(head, SLL_Count(head) - 1);
    SLL_Remove(head, node);
    free(CONTAINER_OF(node, struct wday_entry, node));
    __printList(head);

    printf("(5) 리스트 원소를 역순으로 변환하기! \n");
    SLL_Reverse(head);
    __printList(head);

    printf("(6) 리스트 공간을 해제하여, 공백 리스트 상태로 만들기! \n");
    while (head->next) {
        node = head->next;
        SLL_Remove(head, node);
        free(CONTAINER_OF(node, struct wday_entry, node));
    }

    return 0;
}
