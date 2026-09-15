#include "list-helpers.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * Determine list length
 * Using representation 2 of linked list (with container struct)
 *
 * Run:
 *   clang 4-linked-list-length-rep2-tut.c && ./a.out
 *
 * struct node {
 *     int value;
 *     struct node *next;
 * };
 *
 * struct list {
 *     struct node *head; // 0x642
 *     int length;
 *     struct node *tail;
 *     //...
 * };
 */

int listLengthContainer(struct list *linkedList) {
    // TODO
    return 0;
}

int listLength(struct node *headNode) {
    // 1 -> 2 -> 3 -> X
    // TODO
    return 0;
}

int main() {
    struct list *linkedList = malloc(sizeof(*linkedList));
    linkedList->head = createList();

    printf("Length of list: %d\n", listLengthContainer(linkedList));
}
