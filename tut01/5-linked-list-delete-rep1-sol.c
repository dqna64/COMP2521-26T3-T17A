#include "list-helpers.h"
#include <stdlib.h>

// 0x345   0x349
// 1 ->    2 -> 3 -> X

// free(1)

// struct node * head; // 0x345 ---- 0x349

// 0x345 ->

struct node *listDelete(struct node *headNode, int value) {
    struct node *curr = headNode;
    struct node *prev = NULL;
    while (curr != NULL) {
        if (curr->value == value) {
            if (prev == NULL) {
                struct node *new_head = curr->next;
                free(curr);
                return new_head; // 0x349
            } else {
                prev->next = curr->next;
                free(curr);
                break;
            }
        }

        prev = curr;
        curr = curr->next;
    }
    return headNode;
}

int main(void) {
    struct node *headNode = NULL;
    headNode = appendVal(NULL, 2);
    headNode = appendVal(headNode, 4);
    headNode = appendVal(headNode, 6);
    headNode = appendVal(headNode, 8);

    printList(headNode);
    // 2 -> 4 -> 6 -> 8 -> X

    headNode = listDelete(headNode, 6);
    printList(headNode);
    // 2 -> 4   ->    8 -> X

    headNode = listDelete(headNode, 8);
    printList(headNode);
    // 2 -> 4   ->         X

    headNode = listDelete(headNode, 2);
    printList(headNode);
    //      4   ->         X

    headNode = listDelete(headNode, 4);
    printList(headNode);
    //                     X
}
