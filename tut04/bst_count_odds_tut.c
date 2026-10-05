#include <stdio.h>
#include <stdlib.h>

#include "bst.h"

/**
 * Run command:
 *    $ clang bst_count_odds_tut.c bst.c && ./a.out
 *
 */

int bstCountOdds(struct node *t) {
    // TODO
}

int main(void) {
    TreeNode tree = NULL;
    tree = bstInsert(tree, 8);
    tree = bstInsert(tree, 3);
    tree = bstInsert(tree, 9);
    tree = bstInsert(tree, 1);
    tree = bstInsert(tree, 4);
    bstShow(tree);

    int numOddNodes = bstCountOdds(tree);
    printf("Number of odd nodes in BST: %d\n", numOddNodes);  // should be 3
}