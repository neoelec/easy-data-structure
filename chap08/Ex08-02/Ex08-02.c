#include <stdio.h>
#include <stdlib.h>

#include <container/sbt.h>

struct directory_entry {
    struct SBT_Node node;
    size_t size;
};

static struct directory_entry *__createEntry(
    size_t size, struct directory_entry *left, struct directory_entry *right)
{
    struct directory_entry *entry = malloc(sizeof(*entry));

    entry->size = size;
    entry->node.left = left ? &left->node : NULL;
    entry->node.right = right ? &right->node : NULL;

    return entry;
}

static void __destroyEntry(struct SBT_Node *node)
{
    struct directory_entry *entry;

    if (node == NULL)
        return;

    entry = CONTAINER_OF(node, struct directory_entry, node);

    __destroyEntry(node->left);
    __destroyEntry(node->right);

    free(entry);
}

static void DIR_AccumulateSize(struct SBT_Node *node, void *__total)
{
    size_t *total = __total;
    struct directory_entry *entry
        = CONTAINER_OF(node, struct directory_entry, node);

    *total += entry->size;
}

static size_t __totalUsage(struct directory_entry *entry)
{
    struct SBT tree = {
        .root = &entry->node,
    };
    size_t total = 0;

    SBT_Postorder(&tree, DIR_AccumulateSize, &total);

    return total;
}

static struct SBT *__createTree(void)
{
    struct SBT *tree = malloc(sizeof(*tree));

    SBT_Init(tree);

    return tree;
}

static void __destroyTree(struct SBT *tree)
{
    __destroyEntry(tree->root);
    free(tree);
}

int main(int argc, char *argv[])
{
    struct SBT *tree = __createTree();

    struct directory_entry *F11 = __createEntry(120, NULL, NULL);
    struct directory_entry *F10 = __createEntry(55, NULL, NULL);
    struct directory_entry *F9 = __createEntry(100, NULL, NULL);
    struct directory_entry *F8 = __createEntry(200, NULL, NULL);
    struct directory_entry *F7 = __createEntry(68, F10, F11);

    struct directory_entry *F6 = __createEntry(40, NULL, NULL);
    struct directory_entry *F5 = __createEntry(15, NULL, NULL);
    struct directory_entry *F4 = __createEntry(2, F8, F9);
    struct directory_entry *F3 = __createEntry(10, F6, F7);
    struct directory_entry *F2 = __createEntry(0, F4, F5);
    struct directory_entry *F1 = __createEntry(0, F2, F3);

    tree->root = &F1->node;

    printf("\n\n C:\\의 용량 : %zu M \n", __totalUsage(F2));
    printf("\n D:\\의 용량 : %zu M \n", __totalUsage(F3));
    printf("\n 내 컴퓨터의 전체 용량 : %zu M \n", __totalUsage(F1));

    __destroyTree(tree);

    return 0;
}
