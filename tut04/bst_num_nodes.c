#include <stdio.h>
#include <stdlib.h>

#include "bst.h"

/**
 * Run command:
 *    $ clang bst_num_nodes.c bst.c && ./a.out
 *
 */

int bstNumNodes(struct node *t) {
    if (t == NULL) {
        return 0;
    }

    int nLeft = bstNumNodes(t->left);
    int nRight = bstNumNodes(t->right);
    return nLeft + nRight + 1;
}

int main(void) {
    TreeNode tree = NULL;
    tree = bstInsert(tree, 8);
    tree = bstInsert(tree, 3);
    tree = bstInsert(tree, 9);
    tree = bstInsert(tree, 1);
    tree = bstInsert(tree, 4);
    bstShow(tree);

    int numOddNodes = bstNumNodes(tree);
    printf("Number of odd nodes in BST: %d\n", numOddNodes);  // should be 3
}