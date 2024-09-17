#include <stdio.h>
#include <stdlib.h>

#include <container/sll.h>

struct poly_entry {
    struct SLL_Node node;
    float coef;
    int expo;
};

static struct poly_entry *__insertEntry(
    struct SLL_Node *head, float coef, int expo)
{
    struct poly_entry *entry = malloc(sizeof(*entry));

    entry->coef = coef;
    entry->expo = expo;
    SLL_Init(&entry->node);
    SLL_InsertTail(head, &entry->node);

    return entry;
}

static void __addPoly(
    const struct SLL_Node *A, const struct SLL_Node *B, struct SLL_Node *C)

{ // 두 다항식의 합을 구하는 연산
    struct SLL_Node *a = A->next;
    struct SLL_Node *b = B->next;

    while (a && b) { // 두 다항식에 노드가 있는 동안 반복 수행
        struct poly_entry *p_a = CONTAINER_OF(a, struct poly_entry, node);
        struct poly_entry *p_b = CONTAINER_OF(b, struct poly_entry, node);
        if (p_a->expo == p_b->expo) {
            // 다항식 A의 지수가 다항식 B의 지수와 같은 경우
            __insertEntry(C, p_a->coef + p_b->coef, p_a->expo);
            a = a->next;
            b = b->next;
        } else if (p_a->expo > p_b->expo) {
            // 다항식 A의 지수가 다항식 B의 지수보다 큰 경우
            __insertEntry(C, p_a->coef, p_a->expo);
            a = a->next;
        } else {
            // 다항식 A의 지수가 다항식 B의 지수보다 작은 경우
            __insertEntry(C, p_b->coef, p_b->expo);
            b = b->next;
        }
    }

    for (; a != NULL; a = a->next) {
        struct poly_entry *p_a = CONTAINER_OF(a, struct poly_entry, node);
        __insertEntry(C, p_a->coef, p_a->expo);
    }

    for (; b != NULL; b = b->next) {
        struct poly_entry *p_b = CONTAINER_OF(b, struct poly_entry, node);
        __insertEntry(C, p_b->coef, p_b->expo);
    }
}

static void POLY_PrintEntry(struct SLL_Node *node, void *private)
{
    struct poly_entry *entry = CONTAINER_OF(node, struct poly_entry, node);

    printf("%3.0fx^%d", entry->coef, entry->expo);
}

static void __printPoly(struct SLL_Node *head)
{
    SLL_Forward(head, POLY_PrintEntry, NULL);
}

static struct SLL_Node *__createList(void)
{
    struct SLL_Node *head = malloc(sizeof(*head));

    SLL_Init(head);

    return head;
}

static void __destroyList(struct SLL_Node *head)
{
    while (head->next) {
        struct SLL_Node *node = head->next;
        SLL_Remove(head, node);
        free(CONTAINER_OF(node, struct poly_entry, node));
    }

    free(head);
}

int main(int argc, char *argv[])
{
    struct SLL_Node *A = __createList(); // 공백 다항식 리스트 A, B, C 생성하기
    struct SLL_Node *B = __createList();
    struct SLL_Node *C = __createList();

    __insertEntry(A, 4, 3); // 다항식 리스트 A에 4x3 노드 추가
    __insertEntry(A, 3, 2); // 다항식 리스트 A에 3x2 노드 추가
    __insertEntry(A, 5, 1); // 다항식 리스트 A에 5x1 노드 추가
    printf("\n A(x)=");

    __printPoly(A); // 다항식 리스트 A 출력하기

    __insertEntry(B, 3, 4); // 다항식 리스트 B에 3x4 노드 추가
    __insertEntry(B, 1, 3); // 다항식 리스트 B에 1x3 노드 추가
    __insertEntry(B, 2, 1); // 다항식 리스트 B에 2x1 노드 추가
    __insertEntry(B, 1, 0); // 다항식 리스트 B에 1x0 노드 추가
    printf("\n B(x)=");

    __printPoly(B); // 다항식 리스트 B 출력하기

    __addPoly(A, B, C); // 다항식의 덧셈연산 수행
    printf("\n C(x)=");
    __printPoly(C); // 다항식 리스트 C 출력하기

    __destroyList(A);
    __destroyList(B);
    __destroyList(C);

    return 0;
}
