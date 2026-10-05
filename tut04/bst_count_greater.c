#include <stdio.h>
#include <stdlib.h>

#include "bst.h"

/**
 * Run command:
 *    $ clang bst_count_greater.c bst.c && ./a.out
 *
 */

int bstCountGreater(struct node *t, int val) {
    if (t == NULL) {
        return 0;
    }

    if (t->value <= val) {
        return bstCountGreater(t->right, val);
    } else {
        return 1 + bstCountGreater(t->left, val) + bstCountGreater(t->right, val);
    }
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

    printf("num greater than 2: %d\n", bstCountGreater(tree, 2));    // should be 6
    printf("num greater than 3: %d\n", bstCountGreater(tree, 3));    // should be 6
    printf("num greater than 4: %d\n", bstCountGreater(tree, 4));    // should be 5
    printf("num greater than 5: %d\n", bstCountGreater(tree, 5));    // should be 4
    printf("num greater than 6: %d\n", bstCountGreater(tree, 6));    // should be 4
    printf("num greater than 7: %d\n", bstCountGreater(tree, 7));    // should be 3
    printf("num greater than 8: %d\n", bstCountGreater(tree, 8));    // should be 2
    printf("num greater than 10: %d\n", bstCountGreater(tree, 17));  // should be 0
    printf("num greater than 11: %d\n", bstCountGreater(tree, 17));  // should be 0
}