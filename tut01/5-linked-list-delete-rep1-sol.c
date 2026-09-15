#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node *next;
};

/**
 * Helper function prototypes
 */
struct node *appendNode(struct node *head, int num);
void printList(struct node *head);

// 0x345   0x349
// 1 ->    2 -> 3 -> X

// free(1)

// struct node * head; // 0x345 ---- 0x349

// 0x345 ->

struct node *listDelete(struct node *list, int value) {
    struct node *curr = list;
    struct node *prev = NULL;
    while (curr != NULL) {
        if (curr->value == value) {
            if (prev == NULL) {
                struct node *new_head = curr->next;
                free(curr);
                return new_head;  // 0x349
            } else {
                prev->next = curr->next;
                free(curr);
                break;
            }
        }

        prev = curr;
        curr = curr->next;
    }
    return list;
}

int main(void) {
    struct node *headNode = NULL;
    headNode = appendNode(NULL, 2);
    headNode = appendNode(headNode, 4);
    headNode = appendNode(headNode, 6);
    headNode = appendNode(headNode, 8);

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