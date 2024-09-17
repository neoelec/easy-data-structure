#include <stdio.h>
#include <stdlib.h>

#include <container/lls.h>

struct calc_entry {
    struct SLL_Node node;
    int data;
};

static void __pushEntry(struct LLS *stack, int data)
{
    struct calc_entry *entry = malloc(sizeof(*entry));

    entry->data = data;
    LLS_Push(stack, &entry->node);
}

static int __popEntry(struct LLS *stack)
{
    struct SLL_Node *node = LLS_Pop(stack);
    struct calc_entry *entry = CONTAINER_OF(node, struct calc_entry, node);
    int data = entry->data;

    free(entry);

    return data;
}

static struct LLS *__createStack(void)
{
    struct LLS *stack = malloc(sizeof(*stack));

    LLS_Init(stack);

    return stack;
}

static void __destroyStack(struct LLS *stack)
{
    while (!LLS_IsEmpty(stack))
        free(LLS_Pop(stack));

    free(stack);
}

static int __evalPostfix(const char *exp) // 후위 표기식을 계산하는 연산
{
    struct LLS *stack = __createStack();
    int ret;

    while (*exp) {
        char symbol = *exp++;

        if (symbol != '+' && symbol != '-' && symbol != '*' && symbol != '/') {
            __pushEntry(stack, symbol - '0');
        } else {
            int opr2 = __popEntry(stack);
            int opr1 = __popEntry(stack);

            switch (symbol) {
            case '+':
                __pushEntry(stack, opr1 + opr2);
                break;
            case '-':
                __pushEntry(stack, opr1 - opr2);
                break;
            case '*':
                __pushEntry(stack, opr1 * opr2);
                break;
            case '/':
                __pushEntry(stack, opr1 / opr2);
                break;
            }
        }
    }

    ret = __popEntry(stack);
    __destroyStack(stack);

    return ret;
}

int main(int argc, char *argv[])
{
    int result;
    char *express = "35*62/-";

    printf("후위표기식 : %s", express);

    result = __evalPostfix(express);
    printf("\n\n 연산결과 => %d", result);

    return 0;
}
