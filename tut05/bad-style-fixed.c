#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *appendToList(struct node *head, int data);
struct node *prependToList(struct node *head, int data);
static struct node *createNode(int data);
void printList(struct node *head);
void freeList(struct node *head);

int main(void) {
    struct node *head = NULL;
    head = appendToList(head, 1);
    head = appendToList(head, 2);
    head = appendToList(head, 3);
    head = appendToList(head, INT_MAX);
    head = prependToList(head, 0);
    printList(head);
    freeList(head);
    return 0;
}

/**
 * Appends a new node containing the given data to the end of the list,
 * and returns the head of the list
 */
struct node *appendToList(struct node *head, int data) {
    struct node *newNode = createNode(data);
    if (head == NULL) {
        return newNode;
    }

    // Find the last node of the list
    struct node *lastNode = head;
    while (lastNode->next != NULL) {
        lastNode = lastNode->next;
    }
    lastNode->next = newNode;
    return head;
}

/**
 * Prepends a new node containing the given data to the start of the list,
 * and returns the new head of the list
 */
struct node *prependToList(struct node *head, int data) {
    struct node *newNode = createNode(data);
    newNode->next = head;
    return newNode;
}

/**
 * Creates a new node containing the given data, exiting if malloc fails
 */
static struct node *createNode(int data) {
    struct node *newNode = malloc(sizeof(struct node));
    if (newNode == NULL) {
        fprintf(stderr, "Unable to malloc new node\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

/**
 * Prints each node in the list in order, e.g. 1 -> 2 -> 3
 */
void printList(struct node *head) {
    struct node *curr = head;
    while (curr->next != NULL) {
        printf("%d -> ", curr->data);
        curr = curr->next;
    }
    printf("%d\n", curr->data);
}

/**
 * Frees every node in the list
 */
void freeList(struct node *head) {
    while (head != NULL) {
        struct node *temp = head;
        head = head->next;
        free(temp);
    }
}
