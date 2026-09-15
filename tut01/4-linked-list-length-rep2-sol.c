#include <stdio.h>
#include <stdlib.h>

/**
 * Determine list length
 * Using representation 2 of linked list (with container struct)
 *
 */
struct node {
    int value;
    struct node *next;
};

struct list {
    struct node *head;
};

/**
 * Helper function prototypes
 */
struct node *readList(int size);
struct node *createList();
void printList(struct node *l);
struct node *createNode(int val);
struct node *appendVal(struct node *head, int val);

int listLength(struct node *headNode);

int listLengthContainer(struct list *linkedList) {
    return listLength(linkedList->head);
}

int listLength(struct node *headNode) {
    int length = 0;
    struct node *curr = headNode;
    while (curr != NULL) {
        length++;
        curr = curr->next;
    }
    return length;
}

int main() {
    struct list *linkedList = malloc(sizeof(*linkedList));
    linkedList->head = createList();

    printf("Length of list: %d\n", listLengthContainer(linkedList));
}

/**
 * Helper functions
 *
 */
void printList(struct node *l) {
    if (l == NULL) {
        printf("X\n");
        return;
    }
    printf("%d -> ", l->value);
    printList(l->next);
}

struct node *readList(int size) {
    struct node *head = NULL;
    struct node *curr = head;

    for (int i = 0; i < size; i++) {
        int value;
        if (scanf("%d", &value) != 1) {
            break;
        }

        struct node *newNode = createNode(value);

        if (head == NULL) {
            head = newNode;
        } else {
            curr->next = newNode;
        }
        curr = newNode;
    }

    return head;
}

struct node *createList() {
    printf("Enter list size: ");
    int size = 0;
    if (scanf("%d", &size) == 0) {
        fprintf(stderr, "error: failed to read list size\n");
        exit(EXIT_FAILURE);
    } else if (size < 0) {
        fprintf(stderr, "error: invalid list size\n");
        exit(EXIT_FAILURE);
    }

    if (size > 0) {
        printf("Enter list values: ");
    }
    struct node *list = readList(size);

    printf("List: ");
    printList(list);
    printf("\n");

    return list;
}

struct node *createNode(int val) {
    struct node *newNode = malloc(sizeof(struct node));
    if (newNode == NULL) {
        fprintf(stderr, "ERROR while creating new node due to failed malloc");
        exit(EXIT_FAILURE);
    }
    newNode->value = val;
    newNode->next = NULL;
    return newNode;
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
