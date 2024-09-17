#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <container/bst.h>

#define MAX_WORD_LENGTH 20
#define MAX_MEAN_LENGTH 200

struct dict_entry {
    struct BST_Node node;
    // 영어사전 항목의 구조 정의
    char word[MAX_WORD_LENGTH];
    char mean[MAX_MEAN_LENGTH];
};

static int DICT_Compare(const struct BST_Node *_a, const struct BST_Node *_b)
{
    const struct dict_entry *a = CONTAINER_OF(_a, struct dict_entry, node);
    const struct dict_entry *b = CONTAINER_OF(_b, struct dict_entry, node);

    return strncmp(a->word, b->word, sizeof(a->word));
}

static struct dict_entry *__searchEntry(
    struct BST *tree, const struct dict_entry *key_entry)
{
    struct BST_Node *x;

    x = BST_Search(tree, &key_entry->node);
    if (x == NULL)
        return NULL;

    return CONTAINER_OF(x, struct dict_entry, node);
}

static int __insertEntry(struct BST *tree, const struct dict_entry *new_entry)
{
    struct dict_entry *entry;

    if (__searchEntry(tree, new_entry))
        return -EBUSY;

    entry = malloc(sizeof(*entry));
    memcpy(entry, new_entry, sizeof(*entry));

    BST_Insert(tree, &entry->node);

    return 0;
}

static int __insertWordMean(
    struct BST *tree, const char *word, const char *mean)
{
    struct dict_entry entry;

    strncpy(entry.word, word, sizeof(entry.word));
    strncpy(entry.mean, mean, sizeof(entry.mean));

    return __insertEntry(tree, &entry);
}

static int __removeEntry(struct BST *tree, const struct dict_entry *del_entry)
{
    struct dict_entry *entry = __searchEntry(tree, del_entry);

    if (entry == NULL)
        return -ENOENT;

    BST_Remove(tree, &entry->node);
    free(entry);

    return 0;
}

static void DICT_PrintEntry(struct BST_Node *node, void *private)
{
    const struct dict_entry *entry;

    entry = CONTAINER_OF(node, struct dict_entry, node);
    printf("\n%s : %s", entry->word, entry->mean);
}

static struct BST *__createTree(void)
{
    struct BST *tree = malloc(sizeof(*tree));

    BST_Init(tree, DICT_Compare);

    return tree;
}

static void __destroyTree(struct BST *tree)
{
    struct BST_Node *node;
    struct dict_entry *entry;

    node = BST_Minimum(tree);
    while (node != NULL) {
        entry = CONTAINER_OF(node, struct dict_entry, node);
        BST_Remove(tree, node);
        free(entry);

        node = BST_Minimum(tree);
    }

    free(tree);
}

static void __printMenu(void)
{
    printf("\n\n*---------------------------*");
    printf("\n\t1 : 출력");
    printf("\n\t2 : 입력");
    printf("\n\t3 : 삭제");
    printf("\n\t4 : 검색");
    printf("\n\t5 : 종료");
    printf("\n*---------------------------*");
    printf("\n메뉴입력 >> ");
}

int main(int argc, char *argv[])
{
    struct BST *tree = __createTree();

    __insertWordMean(tree, "come", "오다.나오다.도착하다.");
    __insertWordMean(tree, "active", "활동적인.의용적인.");
    __insertWordMean(tree, "boy", "젊은이.소년.");
    __insertWordMean(tree, "passion", "열정.정렬.");

    while (1) {
        unsigned int cmd;
        struct dict_entry entry;
        const struct dict_entry *found;
        int err;

        __printMenu();
        scanf("%u", &cmd);

        if (cmd == 5)
            break;

        switch (cmd) {
        case 1:
            printf("\t[사전 출력]");
            BST_Inorder(tree, DICT_PrintEntry, NULL);
            printf("\n\t[사전 끝]");
            break;

        case 2:
            printf("\n[단어 입력] 단어를 입력하세요 : ");
            scanf("%s", entry.word);
            printf("\n[단어입력] 단어 뜻을 입력하세요 : ");
            scanf("%s", entry.mean);
            err = __insertEntry(tree, &entry);
            if (err)
                printf("\n 이미 같은 단어가 있습니다!");

            break;

        case 3:
            printf("\n[단어 삭제] 삭제할 단어 : ");
            scanf("%s", entry.word);
            err = __removeEntry(tree, &entry);
            if (err)
                printf("\n 삭제할 단어가 사전에 없습니다!!");

            break;

        case 4:
            printf("\n[단어 검색] 검색할 단어 : ");
            scanf("%s", entry.word);
            found = __searchEntry(tree, &entry);
            if (found)
                printf("\n 단어 뜻 : %s", found->mean);
            else
                printf("\n 사전에 없는 단어입니다.");

            break;

        default:
            printf("없는 메뉴입니다. 메뉴를 다시 선택하세요! \n");
            break;
        }
    }

    __destroyTree(tree);

    return 0;
}
