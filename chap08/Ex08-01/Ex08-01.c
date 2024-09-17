#include <stdio.h>
#include <stdlib.h>

#include <container/sbt.h>

struct calc_entry {
    struct SBT_Node node;
    char data;
};

static struct calc_entry *__createEntry(
    char data, struct calc_entry *left, struct calc_entry *right)
{
    struct calc_entry *entry = malloc(sizeof(*entry));

    entry->data = data;
    entry->node.left = left ? &left->node : NULL;
    entry->node.right = right ? &right->node : NULL;

    return entry;
}

static void __destroyEntry(struct SBT_Node *node)
{
    struct calc_entry *entry;

    if (node == NULL)
        return;

    entry = CONTAINER_OF(node, struct calc_entry, node);

    __destroyEntry(node->left);
    __destroyEntry(node->right);

    free(entry);
}

static void CALC_PrintEntry(struct SBT_Node *node, void *private)
{
    struct calc_entry *entry = CONTAINER_OF(node, struct calc_entry, node);

    printf(" %c", entry->data);
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

    struct calc_entry *n7 = __createEntry('D', NULL, NULL);
    struct calc_entry *n6 = __createEntry('C', NULL, NULL);
    struct calc_entry *n5 = __createEntry('B', NULL, NULL);
    struct calc_entry *n4 = __createEntry('A', NULL, NULL);

    struct calc_entry *n3 = __createEntry('/', n6, n7);
    struct calc_entry *n2 = __createEntry('*', n4, n5);
    struct calc_entry *n1 = __createEntry('-', n2, n3);

    tree->root = &n1->node;

    printf("\n preorder : ");
    SBT_Preorder(tree, CALC_PrintEntry, NULL);

    printf("\n inorder : ");
    SBT_Inorder(tree, CALC_PrintEntry, NULL);

    printf("\n postorder : ");
    SBT_Postorder(tree, CALC_PrintEntry, NULL);

    __destroyTree(tree);

    return 0;
}
