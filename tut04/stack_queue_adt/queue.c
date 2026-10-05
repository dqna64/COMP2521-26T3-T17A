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
    StackPush(q->s1, item);
}

/**
 * Dequeue: Remove the front item and return.
 *
 */
int QueueDequeue(Queue q) {
    if (StackIsEmpty(q->s2)) {
        while (!StackIsEmpty(q->s1)) {
            int fromS1 = StackPop(q->s1);
            StackPush(q->s2, fromS1);
        }
    }

    if (StackIsEmpty(q->s2)) {
        fprintf(stderr, "Queue is empty, cannot dequeue.\n");
        exit(1);
    }

    return StackPop(q->s2);
}

void QueueFree(Queue q) {
    StackFree(q->s1);
    StackFree(q->s2);
    free(q);
}