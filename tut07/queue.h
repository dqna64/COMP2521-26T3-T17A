#include <stdbool.h>

typedef int Item;

typedef struct node {
    Item item;
    struct node* next;
} Node;

typedef struct queue {
    Node *head;
    Node *tail;
} *Queue;

Queue QueueNew();
void QueueFree(Queue q);
void QueueEnqueue(Queue q, Item item);
Item QueueDequeue(Queue q);
bool QueueIsEmpty(Queue q);