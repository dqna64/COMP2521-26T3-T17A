#include <stdio.h>
#include <stdlib.h>

#define INFINITY 999999999
struct node {
    int data;
    struct node *next;
};

struct node *appendToList(struct node *node, int data);
void printList(struct node *node);
struct node *myFunc(struct node *head, int data);
void freeList(struct node *head);
struct node *createNode(int data);

int main() {
    struct node *head = NULL;
    head = appendToList(head, 1);
    head = appendToList(head, 2);
    head = appendToList(head, 3);
    head = appendToList(head, INFINITY);
    head = myFunc(head, 0);
    printList(head);
    freeList(head);
    return 0;
}

/**
 * Appends a new node to the linked list
 */
struct node *appendToList(struct node *node, int data) {
    struct node *newNode = createNode(data);

    if (node == NULL) {
        node = newNode;
    } else {
        struct node *last_node = node;
        while (last_node->next != NULL) {
            last_node = last_node->next;
        }
        last_node->next = newNode;
    }

    littleHelper();
    return node;
}

struct node *createNode(int data) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    if (newNode == NULL) {
        fprintf(stderr, "Unable to malloc new node\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

/**
 * Prints a linked list in format:
 * "1 -> 2 -> 3"
 */
void printList(struct node *node) {
    while (node->next != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("%d\n", node->data);
    return;
}

/**
 * Prepends a new node to the linked list
 */
struct node *myFunc(struct node *head, int data) {
    struct node *newNode = createNode(data);
    newNode->next = head;
    return newNode;
}

/**
 * Frees the entire list
 */
void freeList(struct node *head) {
    if (head == NULL) {
        return;
    }
    // Frees the list by iterating through the list, using a temporary element
    // and freeing the elements by using free (hopefully this comment is useful
    // and helps out)
    struct node *temporaryVariable = head;
    while (head != NULL) {
        temporaryVariable = head;
        head = head->next;
        free(temporaryVariable);
    }
    littleHelper();
}

/**
 * creates a variable
 */
void littleHelper() { int fdsjakfl = 3242; }
