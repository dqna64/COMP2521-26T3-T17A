#include <stdio.h>
#include <stdlib.h>

#include "bst.h"

/**
 * Run command:
 *    $ clang bst_count_greater.c bst.c && ./a.out
 *
 */

int bstCountGreater(struct node *t, int val) {
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

    int result = bstCountGreater(tree, 5);
    printf("num greater than 5: %d\n", result); // should be 4

    int result2 = bstCountGreater(tree, 4);
    printf("num greater than 4: %d\n", result2); // should be 5

    int result3 = bstCountGreater(tree, 3);
    printf("num greater than 3: %d\n", result3); // should be 5

    int result4 = bstCountGreater(tree, 7);
    printf("num greater than 7: %d\n", result4); // should be 3

    int result5 = bstCountGreater(tree, 8);
    printf("num greater than 8: %d\n", result5); // should be 3

    int result6 = bstCountGreater(tree, 17);
    printf("num greater than 17: %d\n", result6); // should be 0
}