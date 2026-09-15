#include <stdio.h>
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

struct node {
    int value;
    struct node *next;
};

/**
 * Helper function prototypes
 */
struct node *appendNode(struct node *head, int num);
void printList(struct node *head);

struct node *listDelete(struct node *list, int value) {
    // TODO
    return NULL;
}

int main(void) {
    struct node *linked_list = NULL;
    linked_list = appendNode(linked_list, 2);
    linked_list = appendNode(linked_list, 4);
    linked_list = appendNode(linked_list, 6);
    linked_list = appendNode(linked_list, 8);

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

/**
 * Below are helper functions for linked list
 */
struct node *createNode(int num) {
    struct node *newNode = malloc(sizeof(struct node));
    newNode->value = num;
    newNode->next = NULL;
    return newNode;
}

struct node *appendNode(struct node *head, int num) {
    struct node *newNode = createNode(num);

    if (head == NULL) {
        return newNode;
    }

    struct node *curr = head;
    while (curr->next != NULL) {
        curr = curr->next;
    }
    curr->next = newNode;
    return head;
}

void printList(struct node *head) {
    for (struct node *curr = head; curr != NULL; curr = curr->next) {
        printf("%d -> ", curr->value);
    }
    printf("X\n");
}