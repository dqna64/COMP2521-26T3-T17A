#include "queue.h"
#include "stack.h"
#include <stdio.h>

struct queue {
    Stack s1;
    Stack s2;
};

Queue QueueNew(void) {
    Queue q = malloc(sizeof(struct queue));
    q->s1 = StackNew();
    q->s2 = StackNew();
    return q;
}

/**
 * Enqueue: Insert a new item at the back of the queue.
 *
 * @param q
 * @param item
 */
void QueueEnqueue(Queue q, int item) {
    // TODO
}

/**
 * Dequeue: Remove the front item and return.
 */
int QueueDequeue(Queue q) {
    // TODO

    return 0;
}

void QueueFree(Queue q) {
    StackFree(q->s1);
    StackFree(q->s2);
    free(q);
}