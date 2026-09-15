/**
 * Determine list length
 * Using representation 1 of linked list (without container struct)
 *
 *  struct node {
 *      int value;
 *      struct node *next;
 *  };
 *
 * Run:
 *   clang 4-linked-list-length-rep1-tut.c && ./a.out
 *
 */

#include "list-helpers.h"
#include <stdio.h>

int listLength(struct node *headNode) {
    // TODO
    return 0;
}

int main() {
    struct node *headNode = createList();

    printf("Length of list: %d\n", listLength(headNode));
}
