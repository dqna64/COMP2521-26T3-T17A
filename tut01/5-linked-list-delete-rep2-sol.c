#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node *next;
    int length;
    int sum;
    int biggest;
    char *metadata;
};

struct list {
    struct node *head;  // NULL
    int length;
    char *metadata;
};

/**
 * Helper function prototypes
 */
struct node *appendVal(struct node *head, int val);
void appendValContainer(struct list *linkedList, int val);
void printList(struct node *head);
void printListContainer(struct list *linkedList);
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

/**
 * Below are helper functions for linked list
 */
struct node *createNode(int num) {
    struct node *newNode = malloc(sizeof(struct node));
    newNode->value = num;
    newNode->next = NULL;
    return newNode;
}

// linkedLIst must not be NULL
void appendValContainer(struct list *linkedList, int val) {
    linkedList->head = appendVal(linkedList->head, val);
}

struct node *appendVal(struct node *head, int val) {
    struct node *newNode = createNode(val);

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

void printListContainer(struct list *linkedList) {
    printList(linkedList->head);
}

void printList(struct node *head) {
    for (struct node *curr = head; curr != NULL; curr = curr->next) {
        printf("%d -> ", curr->value);
    }
    printf("X\n");
}