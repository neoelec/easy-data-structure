#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include <container/lls.h>

struct symbol_entry {
    struct SLL_Node node;
    char data;
};

static void __pushEntry(struct LLS *stack, char data)
{
    struct symbol_entry *entry = malloc(sizeof(*entry));

    entry->data = data;
    LLS_Push(stack, &entry->node);
}

static char __popEntry(struct LLS *stack)
{
    struct SLL_Node *node = LLS_Pop(stack);
    struct symbol_entry *entry = CONTAINER_OF(node, struct symbol_entry, node);
    char data = entry->data;

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
    while (!LLS_IsEmpty(stack)) {
        struct SLL_Node *node = LLS_Pop(stack);
        free(CONTAINER_OF(node, struct symbol_entry, node));
    }

    free(stack);
}

static bool __testPair(const char *exp) // 수식의 괄호를 검사하는 연산
{
    struct LLS *stack = __createStack();
    bool ret;

    while (1) {
        char symbol = *exp++;
        char open_pair;

        if (!symbol)
            break;

        switch (symbol) {
        case '(':
        case '[':
        case '{':
            __pushEntry(stack, symbol);
            break;
        case ')':
        case ']':
        case '}':
            if (LLS_IsEmpty(stack)) {
                ret = false;
                goto err_exit;
            }

            open_pair = __popEntry(stack);
            if ((open_pair == '(' && symbol != ')')
                || (open_pair == '[' && symbol != ']')
                || (open_pair == '{' && symbol != '}')) {
                ret = false;
                goto err_exit;
            }

            break;
        }
    }

    ret = LLS_IsEmpty(stack);

err_exit:
    __destroyStack(stack);
    return ret;
}

int main(int argc, char *argv[])
{
    char *express = "{(A+B)-3}*5+[{cos(x+y)+7}-1]*4";

    printf("%s", express);
    if (__testPair(express))
        printf("\n\n 수식의 괄호가 맞게 사용되었습니다!");
    else
        printf("\n\n 수식의 괄호가 틀렸습니다!");

    return 0;
}
