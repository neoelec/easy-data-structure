#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

#include <container/bst.h>

struct char_entry {
    struct BST_Node node;
    char key;
};

static int CHAR_Compare(const struct BST_Node *_a, const struct BST_Node *_b)
{
    const struct char_entry *a = CONTAINER_OF(_a, struct char_entry, node);
    const struct char_entry *b = CONTAINER_OF(_b, struct char_entry, node);

    return a->key - b->key;
}

static struct char_entry *__searchEntry(struct BST *tree, char key)
{
    struct char_entry key_entry = {
        .key = key,
    };
    struct BST_Node *x;

    x = BST_Search(tree, &key_entry.node);
    if (x == NULL)
        return NULL;

    return CONTAINER_OF(x, struct char_entry, node);
}

static int __insertEntry(struct BST *tree, char key)
{
    struct char_entry *entry = malloc(sizeof(*entry));

    if (__searchEntry(tree, key))
        return -EBUSY;

    entry->key = key;
    BST_Insert(tree, &entry->node);

    return 0;
}

static int __removeEntry(struct BST *tree, char key)
{
    struct char_entry *entry = __searchEntry(tree, key);

    if (entry == NULL)
        return -ENOENT;

    BST_Remove(tree, &entry->node);
    free(entry);

    return 0;
}

static void CHAR_PrintEntry(struct BST_Node *node, void *private)
{
    const struct char_entry *entry;

    entry = CONTAINER_OF(node, struct char_entry, node);
    printf("%c_", entry->key);
}

static struct BST *__createTree(void)
{
    struct BST *tree = malloc(sizeof(*tree));

    BST_Init(tree, CHAR_Compare);

    return tree;
}

static void __destroyTree(struct BST *tree)
{
    struct BST_Node *node;
    struct char_entry *entry;

    node = BST_Minimum(tree);
    while (node != NULL) {
        entry = CONTAINER_OF(node, struct char_entry, node);
        BST_Remove(tree, node);
        free(entry);

        node = BST_Minimum(tree);
    }

    free(tree);
}

static void __printMenu(void)
{
    printf("\n*---------------------------*");
    printf("\n\t1 : 트리 출력");
    printf("\n\t2 : 문자 삽입");
    printf("\n\t3 : 문자 삭제");
    printf("\n\t4 : 문자 검색");
    printf("\n\t5 : 종료");
    printf("\n*---------------------------*");
    printf("\n메뉴입력 >> ");
}

int main(int argc, char *argv[])
{
    struct BST *tree = __createTree();

    __insertEntry(tree, 'I');
    __insertEntry(tree, 'H');
    __insertEntry(tree, 'D');
    __insertEntry(tree, 'B');
    __insertEntry(tree, 'M');
    __insertEntry(tree, 'N');
    __insertEntry(tree, 'A');
    __insertEntry(tree, 'J');
    __insertEntry(tree, 'E');
    __insertEntry(tree, 'Q');

    while (1) {
        unsigned int cmd;
        char buf[2];
        const struct char_entry *found;
        int err;

        __printMenu();
        scanf("%u", &cmd);

        if (cmd == 5)
            break;

        switch (cmd) {
        case 1:
            printf("\t[이진트리 출력]  ");
            BST_Inorder(tree, CHAR_PrintEntry, NULL);
            printf("\n");
            break;

        case 2:
            printf("\n삽입할 문자를 입력하세요 : ");
            scanf("%s", buf);
            err = __insertEntry(tree, buf[0]);
            if (err)
                printf("\n 이미 같은 키가 있습니다!");

            break;

        case 3:
            printf("\n삭제할 문자를 입력하세요 : ");
            scanf("%s", buf);
            err = __removeEntry(tree, buf[0]);
            if (err)
                printf("\n 삭제할 키가 없습니다!!");
            break;

        case 4:
            printf("\n찾을 문자를 입력하세요 : ");
            scanf("%s", buf);
            found = __searchEntry(tree, buf[0]);
            if (found)
                printf("\n %c 를 찾았습니다! \n", found->key);
            else
                printf("\n 문자를 찾지 못했습니다. \n");
            break;

        default:
            printf("없는 메뉴입니다. 메뉴를 다시 선택하세요! \n");
            break;
        }
    }

    __destroyTree(tree);

    return 0;
}
