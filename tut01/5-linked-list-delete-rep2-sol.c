#include "list-helpers.h"
#include <stdlib.h>

struct node *listDelete(struct node *headNode, int value);

void listContainerDelete(struct list *list, int value) {
    list->head = listDelete(list->head, value);
}

struct node *listDelete(struct node *headNode, int value) {
    struct node *curr = headNode;
    struct node *prev = NULL;
    while (curr != NULL) {
        if (curr->value == value) {
            if (prev == NULL) {
                struct node *newHead = curr->next;
                free(curr);
                return newHead;
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
    struct list *linkedList = malloc(sizeof(*linkedList));
    appendValContainer(linkedList, 2);
    appendValContainer(linkedList, 4);
    appendValContainer(linkedList, 6);
    appendValContainer(linkedList, 8);

    printListContainer(linkedList);
    // 2 -> 4 -> 6 -> 8 -> X

    listContainerDelete(linkedList, 6);
    printListContainer(linkedList);
    // 2 -> 4   ->    8 -> X

    listContainerDelete(linkedList, 8);
    printListContainer(linkedList);
    // 2 -> 4   ->         X

    listContainerDelete(linkedList, 2);
    printListContainer(linkedList);
    //      4   ->         X

    listContainerDelete(linkedList, 4);
    printListContainer(linkedList);
    //                     X
}
