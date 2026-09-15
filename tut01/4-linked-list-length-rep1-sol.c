/**
 * Determine list length
 * Using representation 1 of linked list (without container struct)
 *
 * struct node {
 *     int value;
 *     struct node *next;
 * }
 */

#include "list-helpers.h"
#include <stdio.h>

int listLength(struct node *headNode) {
    // 0x74    0x78            curr
    // 1 ->    2 ->      3 -> NULL
    int length = 0;
    struct node *curr = headNode;
    while (curr != NULL) {
        length++;
        curr = curr->next;
    }

    // for (struct node *curr = headNode; curr != NULL; curr = curr->next) {
    //     ++length;
    // }

    return length;
}

int main() {
    struct node *headNode = createList();

    printf("Length of list: %d\n", listLength(headNode));
}
