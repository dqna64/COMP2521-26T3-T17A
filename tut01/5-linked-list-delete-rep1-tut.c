
#include "list-helpers.h"
#include <stdlib.h>

/**
 * Delete node with given value from linked list
 * Cases:
 * - delete middle
 * - delete head
 * - delete tail
 * - list with single node
 * - empty list
 *
 */

struct node *listDelete(struct node *headNode, int value) {
    // TODO
    return headNode;
}

int main(void) {
    struct node *linked_list = NULL;
    linked_list = appendVal(linked_list, 2);
    linked_list = appendVal(linked_list, 4);
    linked_list = appendVal(linked_list, 6);
    linked_list = appendVal(linked_list, 8);

    printList(linked_list);
    // 2 -> 4 -> 6 -> 8 -> X

    linked_list = listDelete(linked_list, 6);
    printList(linked_list);
    // 2 -> 4   ->    8 -> X

    linked_list = listDelete(linked_list, 8);
    printList(linked_list);
    // 2 -> 4   ->         X

    linked_list = listDelete(linked_list, 2);
    printList(linked_list);
    //      4   ->         X

    linked_list = listDelete(linked_list, 4);
    printList(linked_list);
    //                     X
}
