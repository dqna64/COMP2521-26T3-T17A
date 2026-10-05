#include <stdio.h>
#include <stdlib.h>

#include "bst.h"

/**
 * Run command:
 *    $ clang bst_count_internal_tut.c bst.c && ./a.out
 *
 */

int bstCountInternal(struct node *t) {
    // TODO

    return 0;
}

int main(void) {
    struct node *tree = NULL;
    tree = bstInsert(tree, 7);
    tree = bstInsert(tree, 2);
    tree = bstInsert(tree, 9);
    tree = bstInsert(tree, 1);
    tree = bstInsert(tree, 5);
    tree = bstInsert(tree, 8);
    tree = bstInsert(tree, 10);
    tree = bstInsert(tree, 4);
    bstShow(tree);

    int result = bstCountInternal(tree);
    printf("number of internal nodes: %d\n", result); // should be 4
}